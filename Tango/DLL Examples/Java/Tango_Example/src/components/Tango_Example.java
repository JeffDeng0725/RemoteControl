/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package components;

import com.sun.jna.Memory;
import com.sun.jna.Native;
import com.sun.jna.Pointer;
import com.sun.jna.ptr.DoubleByReference;
import com.sun.jna.ptr.IntByReference;
import java.awt.*;
import java.awt.Frame;
import java.awt.Rectangle;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.awt.event.MouseWheelEvent;
import java.awt.event.MouseWheelListener;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.Properties;
import javax.swing.JOptionPane;
import jssc.SerialPortList;

/**
 *
 * @author Falk Dettmar
 */
public class Tango_Example extends javax.swing.JFrame {
    /** This will end up in the current directory
    A more sensible location is a sub-directory of user.home.
    (left as an exercise for the reader) */
    private static TANGODLL TANGOINST;
    
    private static String TANGOOPTIONS = "tangooptions.prop"; //TangoOptions
    private String iniPath = System.getProperty("user.dir")+"\\TANGO_API.ini";
    private String COMPort;
    
    private String tangoport;
    
    private boolean connected       = false;
    private boolean ETS_Present     = false;
    
    private boolean init            = false;
    private boolean GeberZ          = false;
    private boolean JoyStkMode      = false;
    private boolean runDataPoll     = true;
    private boolean DataPollStopped = false;
    private boolean flushRxBuffer   = false;
    private boolean enablePoll      = true;
    
    private int     lLSID;
    private Pointer pcRet = null;
    private TangoDataPollThread DataPollThread = null;
    private double xMaxPos, yMaxPos;
    private double xMinPos, yMinPos;
    private double z_offset = 0.0;
    
    private DecimalFormat TwoN   = new DecimalFormat("#0.00");
    private DecimalFormat FourN  = new DecimalFormat("#0.0000");
    
    private MouseMoveStage mousemovestage;

    private Thread t = null;


    /** Store location & size of UI
     * @param f
     * @throws java.lang.Exception */
    public static void storeOptions(Frame f) throws Exception {
        File file = new File(TANGOOPTIONS);
        Properties p = new Properties();
        // restore the frame from 'full screen' first!
        f.setExtendedState(Frame.NORMAL);
        Rectangle r = f.getBounds();
        int x = (int)r.getX();
        int y = (int)r.getY();
        int w = (int)r.getWidth();
        int h = (int)r.getHeight();

        p.setProperty("x", "" + x);
        p.setProperty("y", "" + y);
        p.setProperty("w", "" + w);
        p.setProperty("h", "" + h);

        BufferedWriter br = new BufferedWriter(new FileWriter(file));
        p.store(br, "Properties of the user frame");
    }

    
    
    /** Restore location & size of UI
     * @param f
     * @throws java.io.IOException */
    public static void restoreOptions(Frame f) throws IOException {
        File file = new File(TANGOOPTIONS);
        Properties p = new Properties();
        BufferedReader br = new BufferedReader(new FileReader(file));
        p.load(br);

        int x = Integer.parseInt(p.getProperty("x"));
        int y = Integer.parseInt(p.getProperty("y"));
        int w = Integer.parseInt(p.getProperty("w"));
        int h = Integer.parseInt(p.getProperty("h"));

        //if 2nd monitor is unplugged
        int totw = 0;
        int toth = 0;
        GraphicsEnvironment    ge = GraphicsEnvironment.getLocalGraphicsEnvironment();
        GraphicsDevice[] monitors = GraphicsEnvironment.getLocalGraphicsEnvironment().getScreenDevices();
        for (GraphicsDevice curGs : monitors)
        {
            DisplayMode mode = curGs.getDisplayMode();
            totw += mode.getWidth();
            toth  = mode.getHeight();
        }
        totw = totw - 100;
        toth = toth - 100;
        if (x > totw) x = totw;
        if (y > toth) y = toth;

        Rectangle r = new Rectangle(x,y,w,h);

        f.setBounds(r);
    }

    
    
    public class MouseMoveStage implements MouseListener, MouseWheelListener, MouseMotionListener {
        private int videoX0;
        private int videoY0;
        private int mms_error;
        private double scalerX;
        private double scalerY;
        double stageX0;
        double stageY0;
        public double pixelfactor;

        public MouseMoveStage() {
            this.videoY0 = 0;
            this.videoX0 = 0;
            this.mms_error = -1;
            this.scalerX = 1.0;
            this.scalerY = 1.0;
            this.pixelfactor = 1.0;
        }
        
        @Override
        public void mousePressed(MouseEvent evt) {
            enableGUI(false);
            jLabel4.setText("mm");
            jLabel5.setText("mm");

            videoX0 = evt.getX();
            videoY0 = evt.getY();
            DoubleByReference xx = new DoubleByReference();
            DoubleByReference yy = new DoubleByReference();
            
            mms_error = GetPos(xx,yy);
            if (mms_error == 0) {
                stageX0 = xx.getValue();
                stageY0 = yy.getValue();
            }
            else {
                stageX0 = 0;
                stageY0 = 0;
            }

            scalerX = pixelfactor/1000.0;
            scalerY = pixelfactor/1000.0;
            System.out.println("mouse pressed: "+videoX0+" "+videoY0);
        }

        @Override
        public void mouseDragged(MouseEvent evt){
            int xr = evt.getX()-videoX0;
            int yr = evt.getY()-videoY0;
            System.out.println("mouse dragged: "+xr+" "+yr);

            if (mms_error == 0) {
                double xx = stageX0 + xr*scalerX;
                double yy = stageY0 + yr*scalerY;
                mms_error = GoAbs(xx,yy);
            }
        }
        

        @Override
        public void mouseClicked(MouseEvent evt) {
        }

        @Override
        public void mouseReleased(MouseEvent evt) {
            jLabel4.setText("µm");
            jLabel5.setText("µm");
            enableGUI(true);
        }

        @Override
        public void mouseEntered(MouseEvent me) {
        }

        @Override
        public void mouseExited(MouseEvent me) {
        }

        @Override
        public void mouseWheelMoved(MouseWheelEvent mwe) {
        }

        @Override
        public void mouseMoved(MouseEvent me) {
        }
    }


    class TangoDataPollThread implements Runnable
    {
        protected volatile boolean runnable = false;
        Point pnt;

        TangoDataPollThread() {
            this.pnt = new Point();
        }

        @Override
        public  void run()
        {
            synchronized(this)
            {
                if(init)
                {
                    DoubleByReference drxPos = new DoubleByReference(0.0);
                    DoubleByReference dryPos = new DoubleByReference(0.0);
                    DoubleByReference drzPos = new DoubleByReference(0.0);
                    DoubleByReference draPos = new DoubleByReference(0.0);
                    while(runnable)
                    {
                        try{
                            while(runDataPoll && enablePoll)
                            {
                                DataPollStopped = false;
                                
                                if (flushRxBuffer) {
                                    TANGOINST.LSX_FlushBuffer(lLSID,0);
                                    flushRxBuffer = false;
                                }
                                
                                if((TANGOINST.LSX_GetPosEx(lLSID, drxPos, dryPos, drzPos, draPos,true)) == 0) {
                                    jTextFieldXPos.setText(TwoN.format(drxPos.getValue() * 1000));
                                    jTextFieldYPos.setText(TwoN.format(dryPos.getValue() * 1000));
                                    jTextFieldZPos.setText(TwoN.format((drzPos.getValue() * 1000) - z_offset));
                                }
                                                                                              
                                Thread.sleep(100);
                                
                                Point p = simpleJoystick1.getDeflection();
                                if ((p.x != pnt.x) || (p.y != pnt.y)) {
                                    pnt.x = p.x;
                                    pnt.y = p.y;
                                    double dx = p.x/100.0;
                                    double dy = p.y/100.0;
                                    dx = dx*dx*dx;
                                    dy = dy*dy*dy * (-1.0);
                                    String speed = "!speed "+ FourN.format(dx*10.0) + " " + FourN.format(dy*10.0) + "\r"; //up to 10mm/s
                                    int err = SendString(speed,false,0);
                                    Thread.sleep(100);
                                }
                            }
                            
                            Thread.sleep(100);
                            DataPollStopped = true;
                            
                            if(runnable == false) {
                                System.out.println("Tango API going to wait()");
                                this.wait();
                            }
                        } catch(Exception e) {
                        //    JOptionPane.showMessageDialog(Tango_Example.this, e.getMessage(), "Fehler", JOptionPane.ERROR_MESSAGE);
                        }
                    }
                }
            }
        }
    }





    
    public void enableGUI(boolean enable) {
        if (enable) {
            flushRxBuffer = true;
            enablePoll    = true;
        }
        else enablePoll   = false;
    }
    
    
    
    
    
    /**
     * Creates new form
     */
    public Tango_Example() {
        initComponents();
        
        String smodel = System.getProperty( "sun.arch.data.model");
        
        this.setTitle("TANGO example on Java version " + System.getProperty("java.version") + " (" + smodel + " bit)");
        
        mousemovestage = new MouseMoveStage();
        
        simpleJoystick1.setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));
        
        jPanel2.addMouseListener(mousemovestage);
        jPanel2.addMouseMotionListener(mousemovestage);
        
        pcRet = new Memory(256);
        
        String[] COMPorts = getComPorts();
        
        for(int i = 0; i < COMPorts.length; i++)
        {
            jComboBoxComPort.insertItemAt(COMPorts[i], i);
        }
        jComboBoxComPort.setSelectedIndex(0);

        //Locked = false;
        //ImageIcon image = new ImageIcon(System.getProperty("user.dir") + "\\Logo.png");
        //JLabel label = new JLabel("", image, JLabel.NORTH_EAST);
        //JPanel panel = new JPanel(new BorderLayout());
        //panel.add( label, BorderLayout.NORTH );
        
        String DLLPath = System.getProperty("user.dir");
        String DLLPathAndName;
        int model = Integer.parseInt(smodel);
        switch (model) {
            case 32: DLLPathAndName = DLLPath + "\\Tango_DLL_32.dll"; break;
            case 64: DLLPathAndName = DLLPath + "\\Tango_DLL_64.dll"; break;
            default: JOptionPane.showMessageDialog(null, "OS unsupported ("+model+" bit)", "Error", JOptionPane.ERROR_MESSAGE);
                     return;
        }
        File f = new File(DLLPathAndName);
        if(!f.isFile()) {
            JOptionPane.showMessageDialog(null, "missing File: "+DLLPathAndName, "Error", JOptionPane.ERROR_MESSAGE);
            return;
        }
        
        TANGOINST = (TANGODLL) Native.loadLibrary(DLLPathAndName, TANGODLL.class);
        
        try{
            JiniFile jini = new JiniFile(iniPath);
            
            if (tangoport != null) COMPort = tangoport;
            else                   COMPort = jini.ReadString("Variablen", "COM", "");
            
            int i;
            for(i = 0; i < jComboBoxComPort.getItemCount(); i++)
            {
                if(jComboBoxComPort.getItemAt(i).equals(COMPort))
                    break;
            }
            if(i < jComboBoxComPort.getItemCount())
                jComboBoxComPort.setSelectedIndex(i);
            
        }catch(SecurityException e){
            JOptionPane.showMessageDialog(null, e.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel6 = new javax.swing.JLabel();
        jLabel7 = new javax.swing.JLabel();
        jScrollPane1 = new javax.swing.JScrollPane();
        jTextAreaLog = new javax.swing.JTextArea();
        jTextFieldSendStr = new javax.swing.JTextField();
        jTextFieldYPos = new javax.swing.JTextField();
        jTextFieldXPos = new javax.swing.JTextField();
        jTextFieldZPos = new javax.swing.JTextField();
        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        jLabelVersion = new javax.swing.JLabel();
        jPanel1 = new javax.swing.JPanel();
        simpleJoystick1 = new components.SimpleJoystick();
        jComboBoxComPort = new javax.swing.JComboBox<>();
        jButtonSeachIni = new javax.swing.JButton();
        jPanel2 = new javax.swing.JPanel();
        jLabel8 = new javax.swing.JLabel();
        jLabel9 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setModalExclusionType(java.awt.Dialog.ModalExclusionType.APPLICATION_EXCLUDE);
        addWindowListener(new java.awt.event.WindowAdapter() {
            public void windowClosed(java.awt.event.WindowEvent evt) {
                formWindowClosed(evt);
            }
            public void windowClosing(java.awt.event.WindowEvent evt) {
                formWindowClosing(evt);
            }
        });

        jLabel6.setFont(new java.awt.Font("Tahoma", 1, 18)); // NOI18N
        jLabel6.setText("µm");

        jLabel7.setFont(new java.awt.Font("Tahoma", 1, 12)); // NOI18N
        jLabel7.setText("Position");

        jTextAreaLog.setEditable(false);
        jTextAreaLog.setColumns(20);
        jTextAreaLog.setRows(5);
        jScrollPane1.setViewportView(jTextAreaLog);

        jTextFieldSendStr.setHorizontalAlignment(javax.swing.JTextField.LEFT);
        jTextFieldSendStr.setToolTipText("");
        jTextFieldSendStr.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jTextFieldSendStrActionPerformed(evt);
            }
        });

        jTextFieldYPos.setEditable(false);
        jTextFieldYPos.setBackground(new java.awt.Color(255, 255, 204));
        jTextFieldYPos.setFont(new java.awt.Font("Tahoma", 0, 18)); // NOI18N
        jTextFieldYPos.setHorizontalAlignment(javax.swing.JTextField.RIGHT);

        jTextFieldXPos.setEditable(false);
        jTextFieldXPos.setBackground(new java.awt.Color(255, 255, 204));
        jTextFieldXPos.setFont(new java.awt.Font("Tahoma", 0, 18)); // NOI18N
        jTextFieldXPos.setHorizontalAlignment(javax.swing.JTextField.RIGHT);

        jTextFieldZPos.setEditable(false);
        jTextFieldZPos.setBackground(new java.awt.Color(255, 255, 204));
        jTextFieldZPos.setFont(new java.awt.Font("Tahoma", 0, 18)); // NOI18N
        jTextFieldZPos.setHorizontalAlignment(javax.swing.JTextField.RIGHT);

        jLabel1.setFont(new java.awt.Font("Tahoma", 1, 18)); // NOI18N
        jLabel1.setText("X");

        jLabel2.setFont(new java.awt.Font("Tahoma", 1, 18)); // NOI18N
        jLabel2.setText("Y");

        jLabel3.setFont(new java.awt.Font("Tahoma", 1, 18)); // NOI18N
        jLabel3.setText("Z");

        jLabel4.setFont(new java.awt.Font("Tahoma", 1, 18)); // NOI18N
        jLabel4.setText("µm");

        jLabel5.setFont(new java.awt.Font("Tahoma", 1, 18)); // NOI18N
        jLabel5.setText("µm");

        jLabelVersion.setBorder(javax.swing.BorderFactory.createEtchedBorder());

        jPanel1.setBorder(javax.swing.BorderFactory.createTitledBorder("Joystick"));

        simpleJoystick1.setBorder(javax.swing.BorderFactory.createEtchedBorder());
        simpleJoystick1.setToolTipText("speed = f(deflection)");

        javax.swing.GroupLayout simpleJoystick1Layout = new javax.swing.GroupLayout(simpleJoystick1);
        simpleJoystick1.setLayout(simpleJoystick1Layout);
        simpleJoystick1Layout.setHorizontalGroup(
            simpleJoystick1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 116, Short.MAX_VALUE)
        );
        simpleJoystick1Layout.setVerticalGroup(
            simpleJoystick1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 116, Short.MAX_VALUE)
        );

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(simpleJoystick1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addComponent(simpleJoystick1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(0, 8, Short.MAX_VALUE))
        );

        jComboBoxComPort.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "availabe COM ports" }));
        jComboBoxComPort.setToolTipText("select Tango Port");
        jComboBoxComPort.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jComboBoxComPortActionPerformed(evt);
            }
        });

        jButtonSeachIni.setText("connect");
        jButtonSeachIni.setToolTipText("establish connection to selected Tango port");
        jButtonSeachIni.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButtonSeachIniActionPerformed(evt);
            }
        });

        jPanel2.setBorder(javax.swing.BorderFactory.createTitledBorder("mouse drag stage pad"));
        jPanel2.setToolTipText("Stage will follow all mouse move events\n");
        jPanel2.setCursor(new java.awt.Cursor(java.awt.Cursor.CROSSHAIR_CURSOR));

        javax.swing.GroupLayout jPanel2Layout = new javax.swing.GroupLayout(jPanel2);
        jPanel2.setLayout(jPanel2Layout);
        jPanel2Layout.setHorizontalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 0, Short.MAX_VALUE)
        );
        jPanel2Layout.setVerticalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 100, Short.MAX_VALUE)
        );

        jLabel8.setText("Command Line");
        jLabel8.setToolTipText("");

        jLabel9.setText("Response");
        jLabel9.setToolTipText("");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(jLabelVersion, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(0, 38, Short.MAX_VALUE)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(jLabel9, javax.swing.GroupLayout.PREFERRED_SIZE, 69, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(18, 18, 18)
                                .addComponent(jScrollPane1))
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(jLabel8)
                                .addGap(18, 18, 18)
                                .addComponent(jTextFieldSendStr, javax.swing.GroupLayout.PREFERRED_SIZE, 301, javax.swing.GroupLayout.PREFERRED_SIZE))))
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addGap(72, 72, 72)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                                    .addComponent(jButtonSeachIni, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                    .addComponent(jComboBoxComPort, javax.swing.GroupLayout.Alignment.LEADING, 0, 127, Short.MAX_VALUE)))
                            .addGroup(layout.createSequentialGroup()
                                .addGap(16, 16, 16)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                                    .addComponent(jLabel1)
                                    .addComponent(jLabel2)
                                    .addComponent(jLabel3))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(jLabel7)
                                    .addGroup(layout.createSequentialGroup()
                                        .addComponent(jTextFieldXPos, javax.swing.GroupLayout.PREFERRED_SIZE, 127, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                        .addComponent(jLabel4))
                                    .addGroup(layout.createSequentialGroup()
                                        .addComponent(jTextFieldYPos, javax.swing.GroupLayout.PREFERRED_SIZE, 127, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                        .addComponent(jLabel5))
                                    .addGroup(layout.createSequentialGroup()
                                        .addComponent(jTextFieldZPos, javax.swing.GroupLayout.PREFERRED_SIZE, 127, javax.swing.GroupLayout.PREFERRED_SIZE)
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                        .addComponent(jLabel6)))))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(jPanel2, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))))
                .addGap(106, 106, 106))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jComboBoxComPort, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addComponent(jButtonSeachIni))
                    .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(jLabel7)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(jTextFieldXPos, javax.swing.GroupLayout.PREFERRED_SIZE, 32, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jLabel1)
                            .addComponent(jLabel4))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(jTextFieldYPos, javax.swing.GroupLayout.PREFERRED_SIZE, 32, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jLabel2)
                            .addComponent(jLabel5))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(jTextFieldZPos, javax.swing.GroupLayout.PREFERRED_SIZE, 32, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jLabel3)
                            .addComponent(jLabel6)))
                    .addComponent(jPanel2, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jTextFieldSendStr, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel8))
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(18, 18, 18)
                        .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 120, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(66, 66, 66)
                        .addComponent(jLabel9)))
                .addGap(22, 22, 22)
                .addComponent(jLabelVersion, javax.swing.GroupLayout.PREFERRED_SIZE, 20, javax.swing.GroupLayout.PREFERRED_SIZE))
        );

        jPanel1.getAccessibleContext().setAccessibleName("move XY stage");

        pack();
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

    private void jTextFieldSendStrActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jTextFieldSendStrActionPerformed
        if(connected)
        {
            String sendstr = jTextFieldSendStr.getText();
            jTextFieldSendStr.setText("");
            int returnfunction;
            String errorString;
            if(!sendstr.isEmpty())
            {
                StopDataPollThread();
                sendstr = sendstr + "\r";
                jTextAreaLog.append(sendstr + "\n");
                try{
                    if(sendstr.equals("reset\r") || sendstr.equals("!reset\r"))
                    {
                        if((returnfunction = SendString(sendstr, false, 0)) != 0) {
                            throw new Exception("Senden von " + sendstr + "fehlgeschlagen!\nMeldung: " + getTANGODLLError(returnfunction));
                        }

                        sendstr = "?err";
                        long timeout = System.currentTimeMillis();
                        String returnstring;
                        int counter = 0;
                        do
                        {
                            if((SendString(sendstr, true, 200)) != 0)
                            {
                                counter++;
                            }
                            returnstring = pcRet.getString(0);
                        }while((!returnstring.equals("0")) && ((System.currentTimeMillis() - timeout) <= 10000) && counter < 20);

                        if((returnfunction = SendString(sendstr, true, 2000)) != 0) {
                            throw new Exception("Senden von " + sendstr + "fehlgeschlagen!\nMeldung: " + getTANGODLLError(returnfunction));
                        }
                        int response = Integer.parseInt(pcRet.getString(0));
                        if(response != 0)
                        {
                            errorString = getTANGODLLError(response);
                            jTextAreaLog.append("err: " + pcRet.getString(0) + " -> " + errorString + "\n");
                        }
                    }
                    else
                    {
                        if(sendstr.substring(0, 1).equals("!"))
                        {
                            if((SendString(sendstr, false, 0)) == 0)
                            {
                                sendstr = "?err\r";
                                if((returnfunction = SendString(sendstr, true, 2000)) != 0)
                                throw new Exception("Senden von " + sendstr + "fehlgeschlagen!\nMeldung: " + getTANGODLLError(returnfunction));
                                if(!pcRet.getString(0).equals("0"))
                                {
                                    errorString = getTANGODLLError(Integer.parseInt(pcRet.getString(0)));
                                    jTextAreaLog.append("err: " + pcRet.getString(0) + " -> " + errorString + "\n");
                                }
                            }
                        }
                        else
                        {
                            if((SendString(sendstr, true, 2000)) == 0)
                            {
                                jTextAreaLog.append(pcRet.getString(0) + "\n");
                            }
                            sendstr = "?err\r";
                            if((returnfunction = SendString(sendstr, true, 2000)) != 0)
                            throw new Exception("Senden von " + sendstr + "fehlgeschlagen!\nMeldung: " + getTANGODLLError(returnfunction));

                            if (!pcRet.getString(0).equals("0"))
                            {
                                errorString = getTANGODLLError(Integer.parseInt(pcRet.getString(0)));
                                jTextAreaLog.append("err: " + pcRet.getString(0) + " -> " + errorString + "\n");
                            }
                        }
                    }
                }catch(Exception e){
                    JOptionPane.showMessageDialog(this, e.getMessage(), "Fehler", JOptionPane.ERROR_MESSAGE);
                }
                StartDataPollThread();
            }
        }
    }//GEN-LAST:event_jTextFieldSendStrActionPerformed

    private void jComboBoxComPortActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jComboBoxComPortActionPerformed
        String[] Ports;
        if(jComboBoxComPort.getSelectedItem().equals((String) "Aktualisieren"))
        {
            jComboBoxComPort.removeAllItems();
            
            Ports = SerialPortList.getPortNames();
            for(int i = 0; i < Ports.length; i++)
            {
                jComboBoxComPort.insertItemAt(Ports[i], i);
            }
            
            jComboBoxComPort.addItem("Aktualisieren");
        }
    }//GEN-LAST:event_jComboBoxComPortActionPerformed

    private void jButtonSeachIniActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonSeachIniActionPerformed
        if(connect(jComboBoxComPort.getSelectedItem().toString())) {
            Initialize(false);
        }
    }//GEN-LAST:event_jButtonSeachIniActionPerformed

    private void formWindowClosed(java.awt.event.WindowEvent evt) {//GEN-FIRST:event_formWindowClosed

    }//GEN-LAST:event_formWindowClosed

    private void formWindowClosing(java.awt.event.WindowEvent evt) {//GEN-FIRST:event_formWindowClosing
        StopDataPollThread();
    }//GEN-LAST:event_formWindowClosing


    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        /*try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(Tango_Example.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Tango_Example.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Tango_Example.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Tango_Example.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            @Override
            public void run() {
                new Tango_Example().setVisible(true);
            }
        });
    }
    
    
    private String[] getComPorts()
    {
        String[] COMPorts = SerialPortList.getPortNames();
        return COMPorts;
    }
    
    /**
     *
     */
    public final void Disconnect()
    {
        int returnfunction = 0;
        try{
            if (DataPollThread != null) {
                if (DataPollThread.runnable)
                {
                    StopDataPollThread();
                }
            }
            
            SendString("!pa 0", false, 0); //Funken beim Lösen der Motorkabel vermeiden
            
            Thread.sleep(200);
            connected = false;
            init = false;
            if((returnfunction = TANGOINST.LSX_Disconnect(lLSID)) != 0)
                throw new Exception("Verbindungsabbau fehlgeschlagen!\nMeldung: " + getTANGODLLError(returnfunction));
            if((returnfunction = TANGOINST.LSX_FreeLSID(lLSID)) != 0)
                throw new Exception("LSID freigeben fehlgeschlagen\nMeldung: " + getTANGODLLError(returnfunction));
        }catch(Exception e)
        {
            JOptionPane.showMessageDialog(this, e.getMessage(), "Verbindungsabbau fehlgeschlagen!\nMessage: " + getTANGODLLError(returnfunction), 0);
        }
        
        StopDataPollThread();
    }


    
    private boolean connect(String Port)
    {
        int returnfunction;
        IntByReference plLSID = new IntByReference();
        init = false;
        try{
            if((returnfunction = TANGOINST.LSX_CreateLSID(plLSID)) != 0) 
                throw new Exception("LSID erzeugen fehlgeschlagen!\nMeldung: " + getTANGODLLError(returnfunction));
            lLSID = plLSID.getValue();
            if((returnfunction = TANGOINST.LSX_ConnectSimple(lLSID, 1, Port, 57600, false)) != 0)
                throw new Exception("ConnectSimple fehlgeschlagen!\nMeldung: " + getTANGODLLError(returnfunction));
            connected = true;
            JiniFile jini = new JiniFile(iniPath);
            jini.WriteString ("Variablen", "COM", jComboBoxComPort.getSelectedItem().toString());
            boolean sucess = jini.UpdateFile();
            if (!sucess) JOptionPane.showMessageDialog(null, "Der gewählte COM Port konnte nicht in der ini Datei gespeichert werden.", "Fehler", JOptionPane.ERROR_MESSAGE);
            return true;
        }
        catch(Exception e)
        {
             JOptionPane.showMessageDialog(this, e.getMessage(), "Fehler", JOptionPane.ERROR_MESSAGE);
        }
        return false;
    }


    
    private void Initialize(boolean calibrateXY)
    {
        int returnfunction;
        
        String sendString;
        DoubleByReference drxPos = new DoubleByReference();
        DoubleByReference dryPos = new DoubleByReference();
        DoubleByReference drzPos = new DoubleByReference();
        DoubleByReference draPos = new DoubleByReference();
     
        try{
            sendString = "?version\r";
            if((returnfunction = SendString(sendString, true, 2000)) != 0)
                throw new Exception("Senden von Kommando: " + sendString + " fehlgeschlagen!\nFehler: " + getTANGODLLError(returnfunction));
            jLabelVersion.setText(pcRet.getString(0));
            if(pcRet.getString(0).contains("TANGO"))
            {
                connected = true;
                StartDataPollThread();
            }
            else connected = false;
            
            if (connected) {
                String StageSN = GetStageSerialNumber();
                jLabelVersion.setText (jLabelVersion.getText() + " StageSN = " + StageSN);
            }
            
            
            //like to use mm for positions and mm/s for speed
            if((returnfunction = TANGOINST.LSX_SetDimensions(lLSID, 9, 9, 9, 9)) != 0)
                throw new Exception("SetDimensions fehlgeschlagen!\nMeldung: " + getTANGODLLError(returnfunction));   

            if (calibrateXY)
            {
                if((returnfunction = TANGOINST.LSX_CalibrateEx(lLSID, 3)) != 0)
                    throw new Exception("Kalibrieren fehlgeschlagen!\nMeldung: " + getTANGODLLError(returnfunction));
                Thread.sleep(10);

                if((returnfunction = TANGOINST.LSX_RMeasureEx(lLSID, 3)) != 0)
                    throw new Exception("Range Measure fehlgeschlagen!\nMeldung: " + getTANGODLLError(returnfunction));
                Thread.sleep(10);
            }
            
            if((returnfunction = TANGOINST.LSX_GetPos(lLSID, drxPos, dryPos, drzPos, draPos)) != 0)
                throw new Exception("Get Pos fehlgeschlagen!\nMeldung: " + getTANGODLLError(returnfunction));

            xMaxPos = drxPos.getValue();
            yMaxPos = dryPos.getValue();

            if((returnfunction = SendString("!pa 1", false, 0)) != 0) {
                //Motoren einschalten
                throw new Exception("Motoren einschalten fehlgeschlagen!\nMeldung: " + getTANGODLLError(returnfunction));
            }

            if (calibrateXY) {
                //xy mittig
                if((returnfunction = TANGOINST.LSX_MoveAbs(lLSID, (drxPos.getValue()/2), (dryPos.getValue()/2), drzPos.getValue(), draPos.getValue(), true)) != 0)
                    throw new Exception("Move Abs fehlgeschlagen!\nMeldung: " + getTANGODLLError(returnfunction));
            }
            
            DataPollThread = new TangoDataPollThread();
            DataPollThread.runnable = true;

            t = new Thread(DataPollThread); //global
//            int p = t.getPriority();
//            t.setPriority(Thread.MIN_PRIORITY); //Thread.MAX_PRIORITY
//            t.setDaemon(true);
            t.start();

            init = true;

            
        }catch(Exception e)
        {
            JOptionPane.showMessageDialog(this, e.getMessage(), "Fehler", JOptionPane.ERROR_MESSAGE);
        }
    }


    
    private void StartDataPollThread()
    {
        if(init)
        {
            /*
            DataPollThread = new TangoDataPollThread();
            DataPollThread.runnable = true;
            Thread t = new Thread(DataPollThread);
            t.setDaemon(true);
            t.start();
            try {
                 Thread.sleep(200);
            } catch (InterruptedException ex) {
                Logger.getLogger(Tango_Example.class.getName()).log(Level.SEVERE, null, ex);
            }
            */
            runDataPoll = true;
        }
    }


    
    private void StopDataPollThread()
    {
        if(init)
        {
            //if(DataPollThread.runnable == true)
            //    DataPollThread.runnable = false;
            runDataPoll = false;
            try{
                int counter = 0;
                while(!DataPollStopped)
                {
                    Thread.sleep(200);
                    counter++;
                    if(counter == 10)   break;
                }
            }catch(Exception e){}
        }
    }


    
    /**
     *
     * @param sendStr
     * @param wait
     * @param timeout
     * @return
     */
//    @Override
    private int SendString(String sendStr, boolean wait, int timeout) {
        pcRet.setString(0, "");
        Pointer pcStr;
        String sendString = sendStr;
        sendString = sendString.replaceAll(",", ".");
        if (!sendString.endsWith("\r")) sendString = sendString + "\r"; //Tango requires delimiter !!!
        pcStr = new Memory(sendString.length() + 1);
        pcStr.setString(0, sendString);
        return TANGOINST.LSX_SendString(lLSID, pcStr, pcRet, 256, wait, timeout); 
    }


    public int SoftwareReset() {
        StopDataPollThread();
//        int retval = TANGOINST.LSX_SoftwareReset(lLSID);
        
        int retval = SendString("reset\r", false, 0);

        String sendstr = "?err\r";
        long timeout = System.currentTimeMillis();
        String returnstring;
        int counter = 0;
        do
        {
            if((SendString(sendstr, true, 200)) != 0)
            {
                counter++;
            }
            returnstring = pcRet.getString(0);
        }while((!returnstring.equals("0")) && ((System.currentTimeMillis() - timeout) <= 10000) && counter < 20);
        
        StartDataPollThread();
        return retval;
    }
    
    /**
     *
     * @param flags
     * @return
     */
    public int Calibrate(int flags)
    {
        StopDataPollThread();
        int retval = TANGOINST.LSX_CalibrateEx(lLSID, flags);
        StartDataPollThread();
        return retval;
    }

    
    
    /**
     *
     * @param flags
     * @return
     */
    public int RangeMeasure(int flags)
    {
        StopDataPollThread();
        
        int retval = TANGOINST.LSX_RMeasureEx(lLSID, flags);
        
        if (retval == 0) {
            DoubleByReference drxPos = new DoubleByReference();
            DoubleByReference dryPos = new DoubleByReference();
            DoubleByReference drzPos = new DoubleByReference();
            DoubleByReference draPos = new DoubleByReference();
            if(TANGOINST.LSX_GetPos(lLSID, drxPos, dryPos, drzPos, draPos) == 0)
            {
                xMaxPos = drxPos.getValue();
                yMaxPos = dryPos.getValue();
            }
        }
        StartDataPollThread();
        return retval;    
    }


    
    /**
     *
     * @return
     */
    public int JoyStickOff()
    {
        if (!connected) return -1;
        if (!JoyStkMode) return 0; //nothing to do
        
        StopDataPollThread();
        
        int retval = TANGOINST.LSX_SetJoystickOff(lLSID);
        
        StartDataPollThread();
        
        if (retval == 0) {
            JoyStkMode = false;
        }    
        return retval;
    }


    
    /**
     *
     * @return
     */
    public int JoyStickOn()
    {
        if (!connected) return -1;
        if (JoyStkMode) return 0; //nothing to do
   
        StopDataPollThread();
        
        int retval = TANGOINST.LSX_SetJoystickOn(lLSID, true, true);

        StartDataPollThread();

        if (retval == 0) {
            JoyStkMode = true;
        }
        return retval;
    }


    
    /**
     *
     * @return
     */
    public boolean GetInit()
    {
        return init;
    }


    
    /**
     *
     * @return
     */
    public int WaitForReady()
    {
        StopDataPollThread();
        String antwort;
        int returnfunction;
        String sendString = "?err\r";     
        pcRet.setString(0, "");
        Pointer pcStr;
        pcStr = new Memory(sendString.length() + 1);
        pcStr.setString(0, sendString);
        
        TANGOINST.LSX_FlushBuffer(lLSID, 0);
        if((returnfunction = TANGOINST.LSX_SendString(lLSID, pcStr, pcRet, 256, true, 20000)) == 0)
        {
            antwort = pcRet.getString(0);
            try {
                returnfunction = Integer.parseInt(antwort);
            } catch (NumberFormatException ex) {
                returnfunction = -2;
            }
        }
        
        StartDataPollThread();
        return returnfunction;
    }

    /**
     *
     * @param x
     * @param y
     * @param z
     * @param a
     * @return
     */
    public int GetPitch(DoubleByReference x, DoubleByReference y, DoubleByReference z, DoubleByReference a)
    {
        StopDataPollThread();
        x.setValue(1.0);
        y.setValue(1.0);
        z.setValue(1.0);
        a.setValue(1.0);
        int returnfunction = -1;
        if(connected)
        {
            if((returnfunction = TANGOINST.LSX_GetPitch(lLSID, x, y, z, a)) != 0)
            {
                x.setValue(1.0);
                y.setValue(1.0);
                z.setValue(1.0);
                a.setValue(1.0);
            }  
        }
        StartDataPollThread();
        return returnfunction;
    }

    
    
    /**
     *
     * @param x
     * @param y
     * @param z
     * @param a
     * @return
     */
    public int GetGear(DoubleByReference x, DoubleByReference y, DoubleByReference z, DoubleByReference a)
    {
        StopDataPollThread();
        x.setValue(1.0);
        y.setValue(1.0);
        z.setValue(1.0);
        a.setValue(1.0);
        int returnfunction = -1;
        if(connected)
        {
            if((returnfunction = TANGOINST.LSX_GetGear(lLSID, x, y, z, a)) != 0)
            {
                x.setValue(1.0);
                y.setValue(1.0);
                z.setValue(1.0);
                a.setValue(1.0);
            }  
        }
        StartDataPollThread();
        return returnfunction;
    }


    
    /**
     *
     * @param x
     * @param y
     * @return
     */
    public int GetMotCur(DoubleByReference x, DoubleByReference y)
    {
        StopDataPollThread();
        x.setValue(0.0);
        y.setValue(0.0);
        DoubleByReference z = new DoubleByReference();
        DoubleByReference a = new DoubleByReference();

        int returnfunction = -1;
        if(connected)
        {
            if((returnfunction = TANGOINST.LSX_GetMotorCurrent(lLSID, x, y, z, a)) != 0)
            {
                x.setValue(0.0);
                y.setValue(0.0);
                z.setValue(0.0);
                a.setValue(0.0);
            }  
        }
        StartDataPollThread();
        return returnfunction;
    }


    
    /**
     *
     * @param x
     * @param y
     * @return
     */
    public int GetPos(DoubleByReference x, DoubleByReference y)
    {
        StopDataPollThread();
        x.setValue(0.0);
        y.setValue(0.0);
        DoubleByReference z = new DoubleByReference();
        DoubleByReference a = new DoubleByReference();

        int returnfunction = -1;
        if(connected)
        {
            if((returnfunction = TANGOINST.LSX_GetPos(lLSID, x, y, z, a)) != 0)
            {
                x.setValue(0.0);
                y.setValue(0.0);
            } 
/*
            else
            {
                x.setValue(x.getValue());
                y.setValue(y.getValue());
            }
*/
            jTextFieldXPos.setText(TwoN.format(x.getValue()*1000.0));
            jTextFieldYPos.setText(TwoN.format(y.getValue()*1000.0));
        }
        StartDataPollThread();
        return returnfunction;
    }


    
    /**
     *
     * @param x returns x encoder position if encoder=true and x motor position if encoder=false
     * @param y
     * @param z
     * @param a
     * @param encoder 
     * @return
     */
    public int GetPosEx(DoubleByReference x, DoubleByReference y, DoubleByReference z, DoubleByReference a, boolean encoder)
    {
        StopDataPollThread();
        x.setValue(0.0);
        y.setValue(0.0);
        z.setValue(0.0);
        a.setValue(0.0);

        int returnfunction = -1;
        if(connected)
        {
            if((returnfunction = TANGOINST.LSX_GetPosEx(lLSID, x, y, z, a, encoder)) != 0)
            {
                x.setValue(0.0);
                y.setValue(0.0);
                z.setValue(0.0);
                a.setValue(0.0);
            }
            /*
            else
            {
                x.setValue(x.getValue());
                y.setValue(y.getValue());
                z.setValue(z.getValue());
                a.setValue(a.getValue());
            }
            */
        }
        StartDataPollThread();
        return returnfunction;
    }


    
    /**
     *
     * @param x
     * @param y
     * @return
     */
    public int SetPos(double x, double y)
    {
        StopDataPollThread();
        int returnfunction = -1;
        DoubleByReference drx = new DoubleByReference();
        DoubleByReference dry = new DoubleByReference();
        DoubleByReference drz = new DoubleByReference();
        DoubleByReference dra = new DoubleByReference();
        
        if(connected)
        {
            if((returnfunction = TANGOINST.LSX_GetPos(lLSID, drx, dry, drz, dra)) == 0)
            {
                if((returnfunction = TANGOINST.LSX_SetPos(lLSID, x, y, drz.getValue(), dra.getValue())) == 0)
                {
                    returnfunction = WaitForReady();
                }
            }
        }
        StartDataPollThread();
        return returnfunction;
    }


    
    /**
     *
     * @param x
     * @param y
     * @return
     */
    public int GetMaxPos(DoubleByReference x, DoubleByReference y)
    {
        int returnfunction = -1;
        if(connected)
        {
            x.setValue(xMaxPos);
            y.setValue(yMaxPos);
            returnfunction = 0;
        }
        return returnfunction;
    }


    
    /**
     *
     * @param x
     * @param y
     * @return
     */
    public int SetMaxPos(double x, double y)
    {
        StopDataPollThread();
        int returnfunction = -1;
        DoubleByReference drXmin = new DoubleByReference();
        DoubleByReference drYmin = new DoubleByReference();
        DoubleByReference drXmax = new DoubleByReference();
        DoubleByReference drYmax = new DoubleByReference();
        
        if(connected)
        {
            if((returnfunction = TANGOINST.LSX_GetLimit(lLSID, 1, drXmin, drXmax)) == 0)
            {
                if((returnfunction = TANGOINST.LSX_GetLimit(lLSID, 2, drYmin, drYmax)) == 0)
                {
                    xMaxPos = x;
                    yMaxPos = y;
                    
                    if((returnfunction = TANGOINST.LSX_SetLimit(lLSID, 1, drXmin.getValue(), xMaxPos)) == 0)
                    {
                        if((returnfunction = TANGOINST.LSX_SetLimit(lLSID, 2, drYmin.getValue(), yMaxPos)) == 0)
                        {
                            returnfunction = WaitForReady();
                        }
                    }
                }
            }
        }
        StartDataPollThread();
        return returnfunction;
    }


    
    /**
     *
     * @param x
     * @param y
     * @return
     */
    public int SetMinPos(double x, double y)
    {
        StopDataPollThread();
        int returnfunction = -1;
        DoubleByReference drXmin = new DoubleByReference();
        DoubleByReference drYmin = new DoubleByReference();
        DoubleByReference drXmax = new DoubleByReference();
        DoubleByReference drYmax = new DoubleByReference();
        
        if(connected)
        {
            if((returnfunction = TANGOINST.LSX_GetLimit(lLSID, 1, drXmin, drXmax)) == 0)
            {
                if((returnfunction = TANGOINST.LSX_GetLimit(lLSID, 2, drYmin, drYmax)) == 0)
                {
                    xMinPos = x;
                    yMinPos = y;
                    
                    if((returnfunction = TANGOINST.LSX_SetLimit(lLSID, 1, xMinPos, drXmax.getValue())) == 0)
                    {
                        if((returnfunction = TANGOINST.LSX_SetLimit(lLSID, 2, yMinPos, drYmax.getValue())) == 0)
                        {
                            returnfunction = WaitForReady();
                        }
                    }
                }
            }
        }
        StartDataPollThread();
        return returnfunction;
    }

    
    
    /**
     *
     * @param F1
     * @param F2
     * @param F3
     * @param F4
     * @return
     */
    public int GetKey(IntByReference F1, IntByReference F2, IntByReference F3, IntByReference F4)
    {
        StopDataPollThread();
        int returnfunction = -1;

        F1.setValue(0);
        F2.setValue(0);
        F3.setValue(0);
        F4.setValue(0);
        
        if(connected)
        {
            if((returnfunction = TANGOINST.LSX_GetKey(lLSID, F1, F2, F3, F4)) != 0)
            {
                F1.setValue(0);
                F2.setValue(0);
                F3.setValue(0);
                F4.setValue(0);
            }
        }
        StartDataPollThread();
        return returnfunction;
    }


    
    /**
     *
     * @param F1
     * @param F2
     * @param F3
     * @param F4
     * @return
     */
    public int GetKeyLatch(IntByReference F1, IntByReference F2, IntByReference F3, IntByReference F4)
    {
        StopDataPollThread();
        int returnfunction = -1;

        F1.setValue(0);
        F2.setValue(0);
        F3.setValue(0);
        F4.setValue(0);
        
        if(connected)
        {
            if((returnfunction = TANGOINST.LSX_GetKeyLatch(lLSID, F1, F2, F3, F4)) != 0)
            {
                F1.setValue(0);
                F2.setValue(0);
                F3.setValue(0);
                F4.setValue(0);
            }
        }
        StartDataPollThread();
        return returnfunction;
    }


    
    /**
     *
     * @param dx
     * @param dy
     * @return
     */
    public int MoveAbs(double dx, double dy)
    {
        int returnfunction = -1;
        StopDataPollThread();
        DoubleByReference drX = new DoubleByReference();
        DoubleByReference drY = new DoubleByReference();
        DoubleByReference drZ = new DoubleByReference();
        DoubleByReference drA = new DoubleByReference();
        boolean bJoyStick = JoyStkMode;
        
        if(connected)
        {
            if(JoyStkMode)  JoyStickOff();
            //dx = dx / 1000.0;
            //dy = dy / 1000.0;
            
            if(GeberZ)  returnfunction = TANGOINST.LSX_GetPosEx(lLSID, drX, drY, drZ, drA, true);
            else        returnfunction = TANGOINST.LSX_GetPos(lLSID, drX, drY, drZ, drA);
            
            if(returnfunction == 0) returnfunction = TANGOINST.LSX_MoveAbs(lLSID, dx, dy, drZ.getValue(), drA.getValue(), true);
            
            if(bJoyStick)   JoyStickOn();
        }
        
        StartDataPollThread();
        return returnfunction;
    }
    
    /**
     *
     * @param xx X-Position in mm
     * @param yy Y-Position in mm
     * @return
     */
    public int GoAbs(double xx, double yy)
    {
        int err = -1;
        if(connected)
        {
            StopDataPollThread();
            String sx = FourN.format(xx); // display resolution = 1/10 µm
            String sy = FourN.format(yy);
            String cmd = "go " + sx + " " + sy + "\r";
            err = SendString(cmd,false,0);
            jTextFieldXPos.setText(sx);
            jTextFieldYPos.setText(sy);
            StartDataPollThread();
        }
        return err;
    }
    
    
    
    public int CorrErase(char achse) {
        int err = -1;
        if(connected)
        {
            StopDataPollThread();
            String ss = "!correrase " + achse + "\r";
            err = SendString(ss, false, 0);
            StartDataPollThread();
        }
        return err;
    }
    
    
    
    public int SetCalMode(int modeX, int modeY, int modeZ) {
        int err = -1;
        if(connected)
        {
            StopDataPollThread();
            String ss = "!calmode " + modeX + " "  + modeY + " " + modeZ + "\r";
            err = SendString(ss, false, 0);
            StartDataPollThread();
        }
        return err;
    }
    
    

    

    
    
    /**
     *
     * @param dz
     * @return
     */
    public int MoveAbsZ(double dz) //µm
    {
        int retval = -1;
        StopDataPollThread();
        if(connected)
        {
            boolean bJoystick = JoyStkMode;
            if(bJoystick) JoyStickOff();
            dz = dz / 1000.0; //convert [µm] to [mm]
            dz = Math.round(10000.0 * dz) / 10000.0; //4 Nachkommastellen

            retval = TANGOINST.LSX_MoveAbsSingleAxis(lLSID, 3, dz, true);
            if(bJoystick) JoyStickOn();
        }
        StartDataPollThread();
        return retval;
    }


    
    /**
     *
     * @param axisID
     * @param dest_um
     * @return
     */
    public int MoveRelSingleAxis(int axisID, double dest_um)
    {
        int result = -1;

        if(connected)
        {
            StopDataPollThread();
            boolean bJoystick = JoyStkMode;
            if(JoyStkMode)  JoyStickOff();
            double dest_mm = dest_um / 1000.0; 
            
            result = TANGOINST.LSX_MoveRelSingleAxis(lLSID, axisID, dest_mm, true);
            
            if(bJoystick)   JoyStickOn();
            StartDataPollThread();
        }
        
        return result;
    }
    
    /**
     *
     * @param dx
     * @param dy
     * @param dz
     * @param da
     * @return
     */
    public int SetSpeed(double dx, double dy, double dz, double da)
    {
        int returnfunction = -1;
        StopDataPollThread();
        String sendStr;
        
        if(connected)
        {
            sendStr = "!speed " + FourN.format(dx) + " " + FourN.format(dy) + " " + FourN.format(dz) + " " + FourN.format(da) + "\r"; 
            if((returnfunction = SendString(sendStr, false, 0)) == 0)
            {
                returnfunction = WaitForReady();
            }
        }
        
        StartDataPollThread();
        return returnfunction;
    }

    
    /**
     *
     * @param index
     * @param value
     * @return
     */
    public int SetAnalogOut(int index, double value)
    {
        int returnfunction = -1;
        StopDataPollThread();
        String sendStr;
        
        if(connected)
        {
            sendStr = "!anaout c " + Integer.toString(index) + " " + TwoN.format(value) + "\r";
            if((returnfunction = SendString(sendStr, false, 0)) == 0)
            {
                returnfunction = WaitForReady();
            }
        }
        
        StartDataPollThread();
        return returnfunction;
    }


    
    /**
     *
     * @param index
     * @param value
     * @return
     */
    public int GetAnalogOut(int index, DoubleByReference value)
    {
        int returnfunction = -1;
        StopDataPollThread();
        String sendStr;
        String NoCR;
        
        if(connected)
        {
            sendStr = "?anaout c " + Integer.toString(index) + "\r";
            if((returnfunction = SendString(sendStr, true, 1000)) == 0)
            {  
                NoCR = pcRet.getString(0).replaceAll("\r", "");
                value.setValue(Double.parseDouble(NoCR));
            }
        }
        
        StartDataPollThread();
        return returnfunction;
    }


    
    /**
     *
     * @param index
     * @param dx
     * @param dy
     * @param dz
     * @param da
     * @return
     */
    public int SetSnapshotArray(int index, double dx, double dy, double dz, double da)
    {
        int returnfunction = -1;
        StopDataPollThread();
        String sendStr;
        
        if(connected)
        {
            sendStr = "!snsa " + Integer.toString(index) + " " + 
                    FourN.format(dx) + " " + 
                    FourN.format(dy) + " " +
                    FourN.format(dz) + " " + 
                    FourN.format(da) + "\r";
            
            if((returnfunction = SendString(sendStr, false, 0)) == 0)
            {
                returnfunction = WaitForReady();
            }
        }
        StartDataPollThread();
        return returnfunction;
    }


    
    /**
     *
     * @param mode
     * @return
     */
    public int SetSnapshotMode(int mode)
    {
        int returnfunction = -1;
        StopDataPollThread();
        String sendStr;
        
        if(connected)
        {
            sendStr = "!sns 1\r";
            if((returnfunction = SendString(sendStr, false, 0)) == 0)
            {
                if((returnfunction = WaitForReady()) == 0)
                {
                    sendStr = "!snsm " + Integer.toString(mode) + "\r";
                    if((returnfunction = SendString(sendStr, false, 0)) == 0)
                    {
                        returnfunction = WaitForReady();
                    }
                }
            }
        }
        StartDataPollThread();
        return returnfunction;
    }


    
    /**
     *
     * @param count
     * @return
     */
    public int SetSnapshotCount(int count)
    {
        int returnfunction = -1;
        StopDataPollThread();
        String sendStr;
        
        if(connected)
        {
            sendStr = "!snsc " + Integer.toString(count) + "\r";
            if((returnfunction = SendString(sendStr, false, 0)) == 0)
            {
                returnfunction = WaitForReady();
            }
        }
        StartDataPollThread();
        return returnfunction;
    }


    
    /**
     *
     * @param vel
     * @return
     */
    public int SetScanVel(double vel)
    {
        int returnfunction = -1;
        StopDataPollThread();
        String sendStr;
        
        if(connected)
        {
            sendStr = "!scanvel " + FourN.format(vel) + "\r";
            if((returnfunction = SendString(sendStr, false, 0)) == 0)
            {
                returnfunction = WaitForReady();
            }
        }
        StartDataPollThread();
        return returnfunction;
    }


    
    /**
     *
     * @param event
     * @return
     */
    public int SetSnapshotEvent(int event)
    {
        int returnfunction = -1;
        StopDataPollThread();
        String sendStr;
        
        if(connected)
        {
            if((returnfunction = TANGOINST.LSX_SetAutoStatus(lLSID, 0)) == 0)
            {
                sendStr = "!snse " + Integer.toString(event) + "\r";
                if((returnfunction = SendString(sendStr, false, 0)) == 0)
                {
                    returnfunction = WaitForReady(); //snse Rechnet sich den Wolf...
                }
            }
        }
        StartDataPollThread();
        return returnfunction;
    }


    
    /**
     *
     * @param enable
     * @return
     */
    public int SetTrigger(int enable)
    {
        int returnfunction = -1;
        StopDataPollThread();
        String sendStr;
        
        if(connected)
        {
            if((returnfunction = TANGOINST.LSX_SetAutoStatus(lLSID, 0)) == 0)
            {
                sendStr = "!trig " + Integer.toString(enable) + "\r";
                if((returnfunction = SendString(sendStr, false, 0)) == 0)
                {
                    returnfunction = WaitForReady();
                }
            }
        }
        StartDataPollThread();
        return returnfunction;
    }

    
    
    /**
     *
     * @param mode
     * @return
     */
    public int SetTriggerMode(int mode)
    {
        int returnfunction = -1;
        StopDataPollThread();
        String sendStr;
        
        if(connected)
        {
            if((returnfunction = TANGOINST.LSX_SetAutoStatus(lLSID, 0)) == 0)
            {
                sendStr = "!trigo 1\r";
                if((returnfunction = SendString(sendStr, false, 0)) == 0)
                {
                    if((returnfunction = WaitForReady()) == 0)
                    {
                        sendStr = "!trigm " + Integer.toString(mode) + "\r";
                        if((returnfunction = SendString(sendStr, false, 0)) == 0)
                        {
                            returnfunction = WaitForReady();
                        }
                    }
                }
            }
        }
        StartDataPollThread();
        return returnfunction;
    }
    
    /**
     *
     * @param length
     * @return
     */
    public int SetTriggerLength(int length)
    {
        int returnfunction = -1;
        StopDataPollThread();
        String sendStr;
        
        if(connected)
        {
            if((returnfunction = TANGOINST.LSX_SetAutoStatus(lLSID, 0)) == 0)
            {
                sendStr = "!trigs " + Integer.toString(length) + "\r";
                if((returnfunction = SendString(sendStr, false, 0)) == 0)
                {
                    returnfunction = WaitForReady();
                }
            }
        }
        StartDataPollThread();
        return returnfunction;
    }
    
    /**
     *
     * @return
     */
    public String GetStageSerialNumber()
    {
        String retval = "SN: ETS?";
        StopDataPollThread();
        String sendStr = "?stagesn 0\r";
        
        if (connected && ETS_Present) {
            if(SendString(sendStr, true, 1000) == 0)
            {
                retval = pcRet.getString(0);
            }
        }
        StartDataPollThread();
        return retval;
    }


    
    /**
     *
     * @param axis
     * @return
     */
    public int CalibrateSingleAxis(char axis)
    {
        int retval = -1;
        
        if(connected)
        {
            StopDataPollThread();
            switch(Character.toLowerCase(axis))
            {
                case 'x':
                    retval = TANGOINST.LSX_CalibrateEx(lLSID, 1);
                    break;
                case 'y':
                    retval = TANGOINST.LSX_CalibrateEx(lLSID, 2);
                    break;
                case 'z':
                    retval = TANGOINST.LSX_CalibrateEx(lLSID, 4);
                    break;
                case 'a':
                    retval = TANGOINST.LSX_CalibrateEx(lLSID, 8);
                    break;
                default:
                    break;
            }
            StartDataPollThread();
        }
        return retval;
    }


    
    /**
     *
     * @return
     */
    public int StopAllAxes()
    {
        int retval;
        StopDataPollThread();
        retval = TANGOINST.LSX_StopAxes(lLSID);
        StartDataPollThread();
        return retval;
    }

    
    
    private void Lock(boolean lock)
    {
        //Locked = lock;
        if(lock) JoyStickOff();
        else     JoyStickOn();
        jLabel1.setEnabled(!lock);
        jLabel2.setEnabled(!lock);
        jLabel3.setEnabled(!lock);
        jLabel4.setEnabled(!lock);
        jLabel5.setEnabled(!lock);
        jLabel6.setEnabled(!lock);
        jLabel7.setEnabled(!lock);
        jLabelVersion.setEnabled(!lock);
        jScrollPane1.setEnabled(!lock);
        jTextAreaLog.setEnabled(!lock);
        jTextFieldSendStr.setEnabled(!lock);
    }
            
    
    private String getTANGODLLError(int returnfunction)
    {
        switch(returnfunction)
        {
            case  1: return "no valid axis name";
            case  2: return "no executable instruction";
            case  3: return "too many characters in command line";
            case  4: return "invalid instruction";
            case  5: return "number is not inside allowed range";
            case  6: return "wrong number of parameters";
            case  7: return "either ! or ? is missing";
            case  8: return "no TVR possible, while axis active";
            case  9: return "no ON or OFF of axis possible, while TVR active";
            case 10: return "function not configured";
            case 11: return "no move instruction possible, while manual joystick enabled";
            case 12: return "limit switch activated";
            case 13: return "function not executable, because encoder detected";
            case 14: return "Error while calibrating (limit switch could not be released)";
            case 27: return "emergency STOP is active";
            case 29: return "servo amplifier are disabled (switched OFF)";
            case 50: return "one argument only expected";
            case 51: return "argument is not a number";
            case 52: return "keyword BEGIN or EOF missing";
            case 53: return "unexpected geo type";
            case 58: return "unexpected sequence";
            case 59: return "alpha and beta must not be equal";
            case 70: return "wrong CPLD data";
            case 71: return "ETS error";
            case 72: return "parameter is write protected (check lock bits)";
            case 73: return "internal error, e.g. eeprom data corruption";
            case 74: return "closed loop switched off due to parameter change";
            case 75: return "could not enable axis correction, or axis correction was disabled";
            
            case 100: return "hardware IO1 missing";
            case 101: return "Magazine not seated";
            case 102: return "magazine slot is empty";
            case 103: return "magazine slot is occopied";
            case 104: return "get slide sensor detect failure during pull from magazine";
            case 105: return "put slide sensor detect failure during insert in magazine";
            case 106: return "sensor overmodulation";
            case 107: return "magazine unknown";
            case 108: return "magnet timeout";
            case 109: return "prio handler is rear";
            case 110: return "prio handler is in front";
            case 111: return "prio handler is not locked"; 
            case 112: return "prio handler position not clear (more than 1 relevant bit is set)"; 
            case 113: return "prio handler timeout front";
            case 114: return "prio handler timeout middle";
            case 115: return "prio handler timeout rear";
            case 116: return "open door";
            case 117: return "close door";
            case 118: return "SE without PrioHandler";
            case 127: return "stop input POS3";
            case 129: return "amplifier OFF from crash detection";
            case 130: return "RF connect";
            case 131: return "RF timeout";
            case 132: return "RF adress";
            case 133: return "RF nak";
            case 134: return "RF sync";
            case 135: return "RF cancel";
            case 136: return "RF nok";
            case 137: return "RF length";
            case 138: return "RF chksum";            
              
            case 4001:
            case 4002: return "internal error";
            case 4003: return "undefined error";
            case 4004: return "Unknown interface type (may appear with Connect...)";
            case 4005: return "Error while Initializing Interface";
            case 4006: return "No connection with controller (e.g. if SetPitch is called before Connect)";
            case 4007: return "Timeout while reading from interface";
            case 4008: return "Error during command transmission to Tango controller";
            case 4009: return "Command aborted (with SetAbortFlag)";
            case 4010: return "Command is not supported by Tango controller";
            case 4011: return "Manual Joystick mode switched on (may appear with SetJoystickOn/Off)";
            case 4012: return "No move command possible, because manual joystick enabled";
            case 4013: return "Closed Loop Controller Timeout (could not settle within target window)";
            case 4014: return "Limit switch activated in travel direction";
            case 4016: return "Repeated vector start!! (Closed Loop controller)";
            case 4017: return "Error while calibrating (Limit switch not correctly released)";
                
            default:   return "Unbekannter Fehler aufgetreten\nCode: " + returnfunction;
                
        }
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButtonSeachIni;
    private javax.swing.JComboBox<String> jComboBoxComPort;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JLabel jLabel9;
    private javax.swing.JLabel jLabelVersion;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JTextArea jTextAreaLog;
    private javax.swing.JTextField jTextFieldSendStr;
    private javax.swing.JTextField jTextFieldXPos;
    private javax.swing.JTextField jTextFieldYPos;
    private javax.swing.JTextField jTextFieldZPos;
    private components.SimpleJoystick simpleJoystick1;
    // End of variables declaration//GEN-END:variables

}

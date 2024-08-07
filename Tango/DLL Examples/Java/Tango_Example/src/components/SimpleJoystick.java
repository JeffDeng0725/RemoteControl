/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package components;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Point;
import java.awt.RenderingHints;
import java.awt.Stroke;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import javax.swing.JPanel;
import javax.swing.SwingUtilities;

/**
 *
 * @author FD
 */
public class SimpleJoystick extends JPanel {

    private static final long serialVersionUID = 1L;
    private final int   joyOutputRange;
    private float joySize;     
    private final float joyWidth, joyHeight;
    private final float joyCenterX, joyCenterY;  //Joystick displayed Center
    //Display positions for text feedback values:
    private int textHorizPos, textVertPos;
    private final int fontSpace = 12;
    private float curJoyAngle;    //Current joystick angle
    private float curJoySize;     //Current joystick size
    private boolean isMouseTracking;
    private boolean isButtonPressed;
    private int mouseX, mouseY;
    private final Stroke lineStroke = new BasicStroke(10, BasicStroke.CAP_ROUND, BasicStroke.JOIN_ROUND);
    private Point position;

    /**
     *
     */
    public SimpleJoystick() {
        this.isButtonPressed = false;
        this.isMouseTracking = false;
        this.position = new Point();
        this.joySize = 100;
        this.joyOutputRange = 100;
        joyWidth  = joySize;
        joyHeight = joyWidth;
        setPreferredSize(new Dimension((int) joyWidth + 20, (int) joyHeight + 20));
        joyCenterX = getPreferredSize().width / 2;
        joyCenterY = getPreferredSize().height / 2;
        this.joySize = joyWidth / 2;
        
        setBackground(new Color(226, 226, 226));
        MouseAdapter mouseAdapter = new MouseAdapter() {

/*
            @Override
            public void mouseMoved(final MouseEvent e) {
                mouseCheck(e);
            }
*/            
            @Override
            public void mousePressed(final MouseEvent e) {
                if (SwingUtilities.isLeftMouseButton(e)) isButtonPressed = true;
                mouseCheck(e);
            }
            
            @Override
            public void mouseReleased(final MouseEvent e) {
                if (SwingUtilities.isLeftMouseButton(e)) isButtonPressed = false;
                mouseCheck(e);
            }

            @Override
            public void mouseDragged(final MouseEvent e) {
                mouseCheck(e);
            }
            
/*
            @Override
            public void mouseExited(final MouseEvent e) {
                isButtonPressed = false;
                mouseCheck(e);
            }
*/


        };
        addMouseMotionListener(mouseAdapter);
        addMouseListener(mouseAdapter);
    }
    
    /**
     *
     * @return
     */
    public Point getDeflection() {
        return this.position;
    }

    
    private void mouseCheck(final MouseEvent e) {
        mouseX = e.getX();
        mouseY = e.getY();
        float dx = mouseX - joyCenterX;
        float dy = mouseY - joyCenterY;

        isMouseTracking = isButtonPressed;
        
        if (isMouseTracking) {
            curJoyAngle = (float)Math.atan2(dy, dx);
            curJoySize  = (float)Point.distance(mouseX, mouseY, joyCenterX, joyCenterY);
        } else {
            curJoySize = 0;
        }
        if (curJoySize > joySize) curJoySize = joySize;
        
        this.position.x = (int)(joyOutputRange * (Math.cos(curJoyAngle)   * curJoySize) / joySize);
        this.position.y = (int)(joyOutputRange * (-(Math.sin(curJoyAngle) * curJoySize) / joySize));
        SwingUtilities.getRoot(SimpleJoystick.this).repaint();
    }

    /**
     *
     * @param g
     */
    @Override
    protected void paintComponent(final Graphics g) {
        super.paintComponent(g);
        Graphics2D g2 = (Graphics2D) g;
        g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING,
                RenderingHints.VALUE_ANTIALIAS_ON);
        g2.setColor(Color.LIGHT_GRAY);
        g2.fillOval((int)(joyCenterX - joyWidth / 2), (int)(joyCenterY - joyHeight / 2), (int)joyWidth, (int)joyHeight);
        //rotate and draw joystick line segment:
        Graphics2D g3 = (Graphics2D) g2.create();
        g3.translate(joyCenterX, joyCenterY);
        g3.rotate(curJoyAngle);
        g3.setColor(Color.GRAY);
        g3.setStroke(lineStroke);
        g3.drawLine(0, 0, (int) curJoySize, 0);
        g3.dispose();
        //
        g2.setColor(Color.GRAY);
        g2.fillOval((int) joyCenterX - 10, (int) joyCenterY - 10, 20, 20);
        textHorizPos = 50;
        textVertPos = (int) (joyCenterY - 50);
        g2.drawString("X: ", textHorizPos, textVertPos);
        textHorizPos += (4 * fontSpace);
        g2.drawString(String.valueOf(position.x), textHorizPos, textVertPos);
        textHorizPos = 50;
        textVertPos += 12;
        g2.drawString("Y: ", textHorizPos, textVertPos);
        textHorizPos += (4 * fontSpace);
        g2.drawString(String.valueOf(position.y), textHorizPos, textVertPos);
    }
  
}

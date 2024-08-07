// This C# example 1 demonstrates usage of Tango_dll.dll (32 bit).
// Project exe is compiled for x86 32 bit and requires .NET version 4.0.

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

using System.Runtime.InteropServices; //this is required to access standard DLL

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        [DllImport("User32.dll", SetLastError = true)]
        static extern Boolean MessageBeep(UInt32 beepType);

        [DllImport("Tango_dll.dll", SetLastError = true)]
        static extern Int32 LSX_CreateLSID(out Int32 plID);

        [DllImport("Tango_dll.dll", SetLastError = true)]
        static extern Int32 LSX_FreeLSID(Int32 ID);

        [DllImport("Tango_dll.dll", SetLastError = true)]
        static extern Int32 LSX_ConnectSimple(Int32 ID, Int32 lAnInterfaceType, String pcAComName, Int32 lABaudRate, Int32 bAShowProt);

        [DllImport("Tango_dll.dll", SetLastError = true)]
        static extern Int32 LSX_Disconnect(Int32 ID);

        [DllImport("Tango_dll.dll", SetLastError = true)]
        static extern Int32 LSX_SetShowProt(Int32 ID, Int32 bAShowProt);

        [DllImport("Tango_dll.dll", SetLastError = true)]
        static extern Int32 LSX_GetPos(Int32 ID, out Double pdX, out Double pdY, out Double pdZ, out Double pdA);

        [DllImport("Tango_dll.dll", SetLastError = true)]
        static extern Int32 LSX_Calibrate(Int32 ID);

        [DllImport("Tango_dll.dll", SetLastError = true)]
        static extern Int32 LSX_CalibrateEx(Int32 ID, Int32 iFlags);

        [DllImport("Tango_dll.dll", SetLastError = true)]
        static extern Int32 LSX_RMeasure(Int32 ID);

        [DllImport("Tango_dll.dll", SetLastError = true)]
        static extern Int32 LSX_RMeasureEx(Int32 ID, Int32 iFlags);

        [DllImport("Tango_dll.dll", SetLastError = true)]
        static extern Int32 LSX_MoveAbs(Int32 ID, Double dX, Double dY, Double dZ, Double dA, Int32 bWait);

        [DllImport("Tango_dll.dll", SetLastError = true)]
        static extern Int32 LSX_MoveAbsSingleAxis(Int32 ID, Int32 lAAxis, Double dPosition, Int32 bAWait);

        [DllImport("Tango_dll.dll", SetLastError = true)]
        static extern Int32 LSX_MoveRelSingleAxis(Int32 ID, Int32 lAAxis, Double dDelta, Int32 bAWait);

        [DllImport("Tango_dll.dll", SetLastError = true)]
        static extern Int32 LSX_GetTriggerPar(Int32 ID, out Int32 plAAxis, out Int32 plAMode, out Int32 plALength, out Double pdADistance);

        [DllImport("Tango_dll.dll", SetLastError = true)]
        static extern Int32 LSX_SetTriggerPar(Int32 ID, Int32 lAAxis, Int32 lAMode, Int32 lALength, Double dADistance);

        [DllImport("Tango_dll.dll", SetLastError = true)]
        static extern Int32 LSX_GetTriggerEncoder(Int32 ID, out Int32 plTrgEnc);

        [DllImport("Tango_dll.dll", SetLastError = true)]
        static extern Int32 LSX_SetTriggerEncoder(Int32 ID, Int32 lTrgEnc);

        [DllImport("Tango_dll.dll", SetLastError = true)]
        static extern Int32 LSX_SetTrigger(Int32 ID, Int32 lATrg);

        [DllImport("Tango_dll.dll", SetLastError = true)]
        static extern Int32 LSX_SetTrigCount(Int32 ID, Int32 lATrgCnt);

        [DllImport("Tango_dll.dll", SetLastError = true)]
        static extern Int32 LSX_GetTrigCount(Int32 ID, out Int32 plATrgCnt);

        // here use "unsafe" declaration because of the returned ASCII string
        // -----
        [DllImport("Tango_dll.dll", SetLastError = true)]
        unsafe static extern Int32 LSX_GetStageSN(Int32 ID, byte* pcAStageSN, Int32 iMaxLen);

        [DllImport("Tango_dll.dll", SetLastError = true)]
        unsafe static extern Int32 LSX_GetSerialNr(Int32 ID, byte* pcASerialNr, Int32 iMaxLen);

        [DllImport("Tango_dll.dll", SetLastError = true)]
        unsafe static extern Int32 LSX_GetDLLVersionString(Int32 ID, byte* pcAStageSN, Int32 iMaxLen);

        [DllImport("Tango_dll.dll", SetLastError = true)]
        unsafe static extern Int32 LSX_GetTangoVersion(Int32 ID, byte* pcAStageSN, Int32 iMaxLen);

        [DllImport("Tango_dll.dll", SetLastError = true)]
        unsafe static extern Int32 LSX_GetVersionStrDet(Int32 ID, byte* pcAStageSN, Int32 iMaxLen);
        // -----


        // Here you may add all other required Tango_dll.dll functions
        // For more details how to use standard DLL with C# source please read
        // http://msdn.microsoft.com/en-us/magazine/cc164123.aspx  



        public Int32 lLSID = 0; // Here in the example only one LSID (one connection) is used for the LSX_ instructions of the DLL



        public Form1()
        {
            InitializeComponent();
            EnableTools(false);

            try
            {
                string[] PortNames = System.IO.Ports.SerialPort.GetPortNames();
                for (int ii = 0; ii < 20; ii++) comboBox1.Items.Add(PortNames[ii]);
            }
            catch
            {
            }
        }


        private void EnableTools(bool bAEnable)
        {
            bt_getpos.Enabled = bAEnable;
            label1.Enabled    = bAEnable;
            label2.Enabled    = bAEnable;
            label3.Enabled    = bAEnable;
            label4.Enabled    = bAEnable;
            label5.Enabled    = bAEnable;
            label6.Enabled    = bAEnable;
            label7.Enabled    = bAEnable;
            label8.Enabled    = bAEnable;
            checkBox2.Enabled = bAEnable;

            checkBox3.Enabled = bAEnable;
            textBox1.Enabled  = bAEnable;
            textBox2.Enabled  = bAEnable;
            textBox3.Enabled  = bAEnable;
            textBox4.Enabled  = bAEnable;

            button1.Enabled   = bAEnable;
            button2.Enabled   = bAEnable;
        }


        private void bt_connect_Click(object sender, EventArgs e)
        {
            Int32 loc_err;
            byte[] loc_str = new byte[128]; // Reserve sufficient space to read the TANGO Version string

            try
            {
                if (comboBox1.Text.Length <= 0) // No COM Port selected
                {
                    MessageBox.Show("Please select a COM port from the Connect list!", "", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
                else
                {
                    // 0. Remove possibly opened LSIDs to establish only one connection
                    while (lLSID > 0)
                    {
                        LSX_Disconnect(lLSID);  // Disconnect the port of the LSID
                        LSX_FreeLSID(lLSID);    // Remove the LSID
                        lLSID -= 1;             // Decrease and repeat until LSID = 0
                    }

                    // 1. Let the DLL create a free LSID (as here the LSX functions are used

                    loc_err = LSX_CreateLSID(out lLSID);    // If a previous connection is not closed and lsid freed, the lsid will be increased. If the access of a higher lsid is to an already opened port, there will be an error returned when connectiong
                    if (loc_err != 0)
                    {
                        MessageBox.Show("Error: " + loc_err.ToString(), "LSX_CreateLSID()", MessageBoxButtons.OK, MessageBoxIcon.Error);
                        return;
                    }
                    label24.Text = "lLSID: "+lLSID.ToString();

                    // 2. Read the DLL Version

                    unsafe
                    {
                        //for (int i = 0; i < loc_str.Length; i++) loc_str[i] = 0x00;
                        fixed (byte* pstr = &loc_str[0])
                        {
                            loc_err = LSX_GetDLLVersionString(lLSID, pstr, loc_str.Length);
                            if (loc_err != 0) MessageBox.Show("Error: " + loc_err.ToString(), "LSX_GetDLLVersionString()", MessageBoxButtons.OK, MessageBoxIcon.Error);
                            else
                            {
                                string sDLLversion = System.Text.Encoding.UTF8.GetString(loc_str).Replace("\0", string.Empty);
                                label25.Text = sDLLversion;
                            }
                        }
                    }

                    // 3. Connect to the selected COM Port

                    Int32 ShowProt = 0;
                    if (checkBox1.Checked == true) ShowProt = 1;
                    loc_err = LSX_ConnectSimple(lLSID, 1, comboBox1.Text, 57600, ShowProt);
                    if (loc_err != 0)
                    {
                        MessageBox.Show("ConnectSimple() Error: " + loc_err.ToString());
                    }
                    else // Success
                    {
                        EnableTools(true);

                        // 4. When connected, readout informations from the TANGO and display them on the "labels" (label25..29) in the lower left corner

                        unsafe
                        {
                            fixed (byte* pstr = &loc_str[0])
                            {
                                for (int i = 0; i < loc_str.Length; i++) loc_str[i] = 0x00;
                                loc_err = LSX_GetTangoVersion(lLSID, pstr, loc_str.Length);
                                if (loc_err != 0) MessageBox.Show("Error: " + loc_err.ToString(), "LSX_GetTangoVersion()", MessageBoxButtons.OK, MessageBoxIcon.Error);
                                else
                                {
                                    string sTangoVersion = System.Text.Encoding.UTF8.GetString(loc_str).Replace("\0", string.Empty);
                                    label26.Text = sTangoVersion;
                                }

                                for (int i = 0; i < loc_str.Length; i++) loc_str[i] = 0x00;
                                loc_err = LSX_GetSerialNr(lLSID, pstr, loc_str.Length);
                                if (loc_err != 0) MessageBox.Show("Error: " + loc_err.ToString(), "LSX_GetSerialNr()", MessageBoxButtons.OK, MessageBoxIcon.Error);
                                else
                                {
                                    string sTangoSN = System.Text.Encoding.UTF8.GetString(loc_str).Replace("\0", string.Empty);
                                    label27.Text = "Tango SN = " + sTangoSN;
                                }

                                for (int i = 0; i < loc_str.Length; i++) loc_str[i] = 0x00;
                                loc_err = LSX_GetStageSN(lLSID, pstr, loc_str.Length);
                                if (loc_err != 0) MessageBox.Show("Error: " + loc_err.ToString(), "LSX_GetStageSN()", MessageBoxButtons.OK, MessageBoxIcon.Error);
                                else
                                {
                                    string sStageSN = System.Text.Encoding.UTF8.GetString(loc_str).Replace("\0", string.Empty);
                                    label28.Text = "Stage SN = " + sStageSN;
                                }

                                for (int i = 0; i < loc_str.Length; i++) loc_str[i] = 0x00;
                                loc_err = LSX_GetVersionStrDet(lLSID, pstr, loc_str.Length);
                                if (loc_err != 0) MessageBox.Show("Error: " + loc_err.ToString(), "LSX_GetVersionStrDet()", MessageBoxButtons.OK, MessageBoxIcon.Error);
                                else
                                {
                                    string sDet = System.Text.Encoding.UTF8.GetString(loc_str).Replace("\0", string.Empty);
                                    int iDet = Int32.Parse(sDet);
                                    if ((iDet & 0x2000) == 0) MessageBox.Show("The Tango option TRIGGER is disabled. Please contact sales at Marzhauser.", "Configuration Info", MessageBoxButtons.OK, MessageBoxIcon.Information);
                                    label29.Text = "DET = 0x" + iDet.ToString("X"); ;
                                }
                            }
                        }

                        Int32 iTrgEnc;
                        loc_err = LSX_GetTriggerEncoder(lLSID, out iTrgEnc);
                        if (loc_err != 0) MessageBox.Show("Error: " + loc_err.ToString(), "GetTriggerEncoder()", MessageBoxButtons.OK, MessageBoxIcon.Error);
                        if (iTrgEnc == 1) checkBox3.Checked = true;
                        else checkBox3.Checked = false;

                        //start with some application dependent default parameter
                        Int32 aAxis = 1;         // X axis is used as LS_GetTriggerEncoder source
                        Int32 aMode = 6;         // start mid of trigger distance, unidirectional upwards, puls rising edge, etc. details refer Tango command reference manual
                        Int32 aLength = 40;      // 40µs puls width
                        Double aDistance = 1.0;  // Trigger distance
                        loc_err = LSX_SetTriggerPar(lLSID, aAxis, aMode, aLength, aDistance);
                        if (loc_err != 0) MessageBox.Show("Error: " + loc_err.ToString(), "SetTriggerPar()", MessageBoxButtons.OK, MessageBoxIcon.Error);

                        //read parameter back from controller
                        loc_err = LSX_GetTriggerPar(lLSID, out aAxis, out aMode, out aLength, out aDistance);
                        if (loc_err != 0) MessageBox.Show("Error: " + loc_err.ToString(), "GetTriggerPar()", MessageBoxButtons.OK, MessageBoxIcon.Error);

                        textBox1.Text = aDistance.ToString("F4");
                        textBox2.Text = aLength.ToString();
                        textBox3.Text = aMode.ToString();
                        textBox4.Text = aAxis.ToString();


                        Int32 iTrgCnt;
                        loc_err = LSX_GetTrigCount(lLSID, out iTrgCnt);
                        if (loc_err != 0) MessageBox.Show("Error: " + loc_err.ToString(), "GetTrigCount()", MessageBoxButtons.OK, MessageBoxIcon.Error);
                        label23.Text = iTrgCnt.ToString();


                        //// Example sequence of calibrating, range measure and move
                        //LSX_CalibrateEx(lLSID, (1 + 2 + 4));        // Calibrate X,Y,Z only  (=7, but here written as individual numbers 1+2+4 for better readability)
                        //LSX_RMeasureEx(lLSID, (1 + 2));             // Range Measure X and Y (=3)
                        //LSX_MoveAbsSingleAxis(lLSID, 1, 0.0, 1);    // Move X axis to 0 and do not wait
                        //LSX_MoveAbsSingleAxis(lLSID, 2, 0.0, 1);    // Move Y axis to 0 and wait (now waits for all axes including the previously started X axis)
                        //LSX_MoveRelSingleAxis(lLSID, 1, 1.0, 1);    // Move X axis relative by 1 (depends on Dimension) and wait until reached
                        //LSX_MoveRelSingleAxis(lLSID, 1, 1.0, 1);    // once again
                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message.ToString());
                EnableTools(false);
            }
        }


        private void bt_disconnect_Click(object sender, EventArgs e)
        {
            if (lLSID > 0)
            {
                LSX_Disconnect(lLSID);
                LSX_FreeLSID(lLSID);
                lLSID = 0;
            }
        }


        private void UpdatePosition()
        {
            Double xx, yy, zz, aa;
            try
            {
                LSX_GetPos(lLSID, out xx, out yy, out zz, out aa);
                label1.Text = xx.ToString("F4");
                label2.Text = yy.ToString("F4");
                label3.Text = zz.ToString("F4");
                label4.Text = aa.ToString("F4");
            }
            catch
            {
            }
        }


        private void bt_getpos_Click(object sender, EventArgs e)
        {
            UpdatePosition();
        }


        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            try
            {
                Int32 ShowProt = 0;
                if (checkBox1.Checked == true) ShowProt = 1;
                LSX_SetShowProt(lLSID, ShowProt);
            }
            catch
            {
                MessageBeep(0);
            }

        }


        private void timer1_Tick(object sender, EventArgs e)
        {
            UpdatePosition();
        }

        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {
            timer1.Enabled = checkBox2.Checked;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Double dStartX, dStartY, dStartZ, dStartA;
            try
            {
                Int32 loc_err = LSX_GetPos(lLSID, out dStartX, out dStartY, out dStartZ, out dStartA);
                if (loc_err != 0) MessageBox.Show("Error: " + loc_err.ToString(), "GetPos()", MessageBoxButtons.OK, MessageBoxIcon.Error);

                //use actual given user parameter
                LSX_SetTrigger(lLSID, 0);
                Double aDistance = Double.Parse(textBox1.Text); //.Replace(",", "."));
                Int32 aLength   = Int32.Parse(textBox2.Text);
                Int32 aMode     = Int32.Parse(textBox3.Text);
                Int32 aAxis     = Int32.Parse(textBox4.Text);
                loc_err = LSX_SetTriggerPar(lLSID, aAxis, aMode, aLength, aDistance);
                if (loc_err != 0) MessageBox.Show("Error: " + loc_err.ToString(), "SetTriggerPar()", MessageBoxButtons.OK, MessageBoxIcon.Error);
                LSX_SetTrigger(lLSID, 1);


                Int32 IYMAX    = Int32.Parse(textBox8.Text);
                Double dDeltaY = Double.Parse(textBox6.Text);
                Double dDestX  = dStartX + Double.Parse(textBox5.Text); //.Replace(",", "."));

                for (int iY = 0; iY < IYMAX; iY++)
                {
                    Double dDestY = dStartY + iY * dDeltaY;
                    loc_err = LSX_MoveAbs(lLSID, dDestX, dDestY, dStartZ, dStartA, 1);
                    if (loc_err != 0) MessageBox.Show("Error: " + loc_err.ToString(), "MoveAbs()", MessageBoxButtons.OK, MessageBoxIcon.Error);

                    loc_err = LSX_MoveAbs(lLSID, dStartX, dDestY + dDeltaY, dStartZ, dStartA, 1);
                    if (loc_err != 0) MessageBox.Show("Error: " + loc_err.ToString(), "MoveAbs()", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }

                Int32 iTrgCnt;
                loc_err = LSX_GetTrigCount(lLSID, out iTrgCnt);
                if (loc_err != 0) MessageBox.Show("Error: " + loc_err.ToString(), "GetTrigCount()", MessageBoxButtons.OK, MessageBoxIcon.Error);
                label23.Text = iTrgCnt.ToString();


                if (checkBox2.Checked)
                {
                    loc_err = LSX_MoveAbs(lLSID, dStartX, dStartY, dStartZ, dStartA, 1);
                    if (loc_err != 0) MessageBox.Show("Error: " + loc_err.ToString(), "MoveAbs()", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }


            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message.ToString());
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Int32 loc_err = LSX_SetTrigCount(lLSID, 0);
            if (loc_err != 0) MessageBox.Show("Error: " + loc_err.ToString(), "SetTrigCount()", MessageBoxButtons.OK, MessageBoxIcon.Error);
            Int32 iTrgCnt;
            loc_err = LSX_GetTrigCount(lLSID, out iTrgCnt);
            if (loc_err != 0) MessageBox.Show("Error: " + loc_err.ToString(), "GetTrigCount()", MessageBoxButtons.OK, MessageBoxIcon.Error);
            label23.Text = iTrgCnt.ToString();
        }
    }
}

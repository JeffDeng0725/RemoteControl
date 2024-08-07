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
        static extern Int32 LS_ConnectSimple(Int32 lAnInterfaceType, String pcAComName, Int32 lABaudRate, Int32 bAShowProt);

        [DllImport("Tango_dll.dll", SetLastError = true)]
        static extern Int32 LS_SetShowProt(Int32 bAShowProt);

        [DllImport("Tango_dll.dll", SetLastError = true)]
        static extern Int32 LS_GetPos(out Double pdX, out Double pdY, out Double pdZ, out Double pdA);

        [DllImport("Tango_dll.dll", SetLastError = true)]
        static extern Int32 LS_MoveRelSingleAxis(Int32 lAAxis, Double dDelta, Int32 bAWait);

// Here you may add all other required Tango_dll.dll functions
// For more details how to use standard DLL with C# source please read
// http://msdn.microsoft.com/en-us/magazine/cc164123.aspx  

         
        public Form1()
        {
            InitializeComponent();

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
            label1.Enabled = bAEnable;
            label2.Enabled = bAEnable;
            label3.Enabled = bAEnable;
            label4.Enabled = bAEnable;
            label5.Enabled = bAEnable;
            label6.Enabled = bAEnable;
            label7.Enabled = bAEnable;
            label8.Enabled = bAEnable;
            bt_Xp.Enabled  = bAEnable;
            bt_Xm.Enabled  = bAEnable;
            bt_Yp.Enabled  = bAEnable;
            bt_Ym.Enabled  = bAEnable;
            checkBox2.Enabled = bAEnable;
        }


        private void bt_connect_Click(object sender, EventArgs e)
        {
            try
            {
                Int32 ShowProt = 0;
                if (checkBox1.Checked == true) ShowProt = 1;

                if (comboBox1.Text.Length > 0)
                {
                    Int32 loc_err = LS_ConnectSimple(1, comboBox1.Text, 57600, ShowProt);
                    if (loc_err == 0) EnableTools(true);
                    else MessageBeep(0);
                }
                else MessageBeep(0);
            }
            catch
            {
                MessageBeep(0);
                EnableTools(false);
            }
        }


        private void UpdatePosition()
        {
            Double xx, yy, zz, aa;
            try
            {
                LS_GetPos(out xx, out yy, out zz, out aa);
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
                LS_SetShowProt(ShowProt);
            }
            catch
            {
                MessageBeep(0);
            }

        }


        private void bt_Yp_Click(object sender, EventArgs e)
        {
            LS_MoveRelSingleAxis(2, 0.1, 1);
            UpdatePosition();
        }

        private void bt_Ym_Click(object sender, EventArgs e)
        {
            LS_MoveRelSingleAxis(2, -0.1, 1);
            UpdatePosition();
        }

        private void bt_Xp_Click(object sender, EventArgs e)
        {
            LS_MoveRelSingleAxis(1, 0.1, 1);
            UpdatePosition();
        }

        private void bt_Xm_Click(object sender, EventArgs e)
        {
            LS_MoveRelSingleAxis(1, -0.1, 1);
            UpdatePosition();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            UpdatePosition();
        }

        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {
            timer1.Enabled = checkBox2.Checked;
        }

    }

}

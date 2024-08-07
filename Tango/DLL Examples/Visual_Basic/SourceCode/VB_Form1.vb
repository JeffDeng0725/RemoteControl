Option Strict Off
Option Explicit On
Friend Class VB_Form1
    Inherits System.Windows.Forms.Form
    Private Sub Command1_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command1.Click
        Dim i As Integer
        i = LS_ConnectSimple(1, Combo1.Text, CInt(Combo2.Text), 1)
    End Sub

    Private Sub Command2_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command2.Click
        Dim i As Integer
        i = LS_Disconnect
    End Sub

    Private Sub Command3_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command3.Click
        Dim i As Integer
        i = LS_SetVel(CDbl(Text1(0).Text), CDbl(Text1(1).Text), CDbl(Text1(2).Text), CDbl(Text1(3).Text))
    End Sub

    Private Sub Command4_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command4.Click
        Dim i As Integer
        i = LS_MoveAbs(CDbl(Text2(0).Text), CDbl(Text2(1).Text), CDbl(Text2(2).Text), CDbl(Text2(3).Text), 1)
    End Sub

    Private Sub Command5_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command5.Click
        Dim i As Integer
        i = LS_MoveRel(CDbl(Text2(0).Text), CDbl(Text2(1).Text), CDbl(Text2(2).Text), CDbl(Text2(3).Text), 1)
    End Sub

    Private Sub Command6_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command6.Click
        Dim i As Integer
        i = LS_RMeasure
    End Sub

    Private Sub Command7_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles Command7.Click
        Dim i As Integer
        i = LS_Calibrate
    End Sub

    Private Sub Form1_Load(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles MyBase.Load
        Combo1.Items.Add(("COM1"))
        Combo1.Items.Add(("COM2"))
        Combo1.Items.Add(("COM3"))
        Combo1.Items.Add(("COM4"))

        Combo2.Items.Add(("9600"))
        Combo2.Items.Add(("57600"))



    End Sub
End Class
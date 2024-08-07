
Project:
Tango_VS2017_Trigger_Example.sln

This code example demonstrates usage of Tango_dll.dll with the c# programming language.
The Project exe is compiled for x64 (64 bit) and x86 (32 bit). It requires .NET version 4.0.

The program dialog is "Form1.cs".

The TANGO DLL .dll files  (here: version 1.414 for 64 and 32 bit) are stored in the \bin and \obj subfolders for x64 and x86.
The DLL's LSX functions are made available by declaration in Form1.cs source code:

{
    public partial class Form1 : Form
    {
        [DllImport("User32.dll", SetLastError = true)]
        static extern Boolean MessageBeep(UInt32 beepType);

        [DllImport("Tango_dll.dll", SetLastError = true)]
        static extern Int32 LSX_CreateLSID(out Int32 plID);
...

The function list is not complete, but shows how to declare and use the LSX instructions from the TANGO DLL in c#.
The LS instrctions should work similar and can be used if one DLL does not need to access several controllers.
Anyway, this example here uses the LSX instructions, including the lLSID, CreateLSID and FreeLSID.


For more details how to use a standard DLL with C# source code please read
http://msdn.microsoft.com/en-us/magazine/cc164123.aspx








 
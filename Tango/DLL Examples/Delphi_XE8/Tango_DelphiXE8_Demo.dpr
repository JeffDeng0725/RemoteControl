program Tango_DelphiXE8_Demo;

uses
  Forms,
  Tango_DelphiXE8_Demo_main in 'Tango_DelphiXE8_Demo_main.pas' {Form1},
  Tango_DLL in 'Tango_DLL.pas';

{$R *.RES}

begin
  Application.Initialize;
  Application.CreateForm(TForm1, Form1);
  Application.Run;
end.

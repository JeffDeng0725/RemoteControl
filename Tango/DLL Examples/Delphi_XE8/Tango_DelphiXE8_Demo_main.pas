unit Tango_DelphiXE8_Demo_main;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  Tango_DLL, StdCtrls, Spin, ComCtrls, ExtCtrls;


type
  TForm1 = class(TForm)
    Panel1: TPanel;
    Button1: TButton;
    Button2: TButton;
    Edit1: TEdit;
    Edit3: TEdit;
    Edit2: TEdit;
    Button5: TButton;
    Panel2: TPanel;
    Button3: TButton;
    Button4: TButton;
    Edit4: TEdit;
    Edit5: TEdit;
    Edit6: TEdit;
    Button6: TButton;
    InterfaceLS2: TPageControl;
    ts_RS232_2: TTabSheet;
    Label5: TLabel;
    Label6: TLabel;
    cbo_BaudRate2: TComboBox;
    cbo_ComPort2: TComboBox;
    Button7: TButton;
    Button8: TButton;
    CheckBox1: TCheckBox;
    CheckBox2: TCheckBox;
    InterfaceLS: TPageControl;
    ts_RS232: TTabSheet;
    Label1: TLabel;
    Label2: TLabel;
    cbo_BaudRate: TComboBox;
    cbo_ComPort: TComboBox;
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure Button5Click(Sender: TObject);
    procedure Button6Click(Sender: TObject);
    procedure Button7Click(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
    procedure Button8Click(Sender: TObject);
  private
    { Private-Deklarationen }
  public
    { Public-Deklarationen }
  end;

type
  TmyThread1 = class(TThread)
  protected
    procedure Execute; override;
  end;
  TmyThread2 = class(TThread)
  protected
    procedure Execute; override;
  end;



var
  Form1: TForm1;
  Th1: TmyThread1;
  Th2: TmyThread2;
  Tango1, Tango2 : Integer;
  connected1, connected2 : boolean;

implementation

{$R *.DFM}

procedure TForm1.Button1Click(Sender: TObject);
var BCtrlInitPar: TLS_ControlInitPar;
begin
  LSX_SetWriteLogText(Tango1, True);

  FillChar(BCtrlInitPar, sizeof(TLS_ControlInitPar), 0);
  with BCtrlInitPar do
  begin
    Size        := sizeof(TLS_ControlInitPar);
    ShowProt    := CheckBox1.Checked;
    ShowCmdList := True;

    InterfaceType := 1;

    ComName := cbo_ComPort.Text;
    BaudRate := StrToInt(cbo_BaudRate.Text); //Tango factory default is 57600

    ErrorCode := 0;
  end;

//  LSX_ConnectEx(Tango1, BCtrlInitPar);
  LSX_ConnectSimple(Tango1, 1, PAnsiChar(AnsiString(BCtrlInitPar.ComName)), 57600, True);
  connected1 := true;
end;

procedure TForm1.Button2Click(Sender: TObject);
begin
  if not Th1.Suspended then Th1.Suspend;
  connected2 := false;
  LSX_Disconnect(Tango1);
end;

procedure TForm1.Button3Click(Sender: TObject);
var BCtrlInitPar: TLS_ControlInitPar;
begin
  LSX_SetWriteLogText(Tango2, True);

  FillChar(BCtrlInitPar, sizeof(TLS_ControlInitPar), 0);
  with BCtrlInitPar do
  begin
    Size := sizeof(TLS_ControlInitPar);
    ShowProt    := CheckBox2.Checked;
    ShowCmdList := True;

    InterfaceType := 1;

    ComName := cbo_ComPort2.Text;
    BaudRate := StrToInt(cbo_BaudRate2.Text);

    ErrorCode := 0;
  end;

  LSX_ConnectEx(Tango2, BCtrlInitPar);
  connected2 := true;

  //LSX_ConnectSimple(Tango2, 1, 'COM2', 9600, True);
end;

procedure TForm1.Button4Click(Sender: TObject);
begin
  if not Th2.Suspended then Th2.Suspend;
  connected2 := false;
  LSX_Disconnect(Tango2);
end;

procedure TForm1.Button5Click(Sender: TObject);
begin
  if connected1 then
  LSX_MoveRel(Tango1, StrToFloat(Edit1.Text),
                 StrToFloat(Edit2.Text),
                 StrToFloat(Edit3.Text), 0, True);
end;

procedure TForm1.Button6Click(Sender: TObject);
begin
  if connected2 then
  LSX_MoveRel(Tango2, StrToFloat(Edit4.Text),
                 StrToFloat(Edit5.Text),
                 StrToFloat(Edit6.Text), 0, True);
end;



procedure TmyThread1.Execute;
begin
  while not Terminated do
  begin
    LSX_MoveAbs(Tango1, 10, 0, 0, 0, true);
    Sleep(1);
    LSX_MoveAbs(Tango1, 10, 10, 0, 0, true);
    Sleep(1);
    LSX_MoveAbs(Tango1, 0, 10, 0, 0, true);
    Sleep(1);
    LSX_MoveAbs(Tango1, 0, 0, 0, 0, true);
    Sleep(1);
  end;
end;


procedure TmyThread2.Execute;
begin
  while not Terminated do
  begin
    LSX_MoveAbs(Tango2, 1, 0, 0, 0, true);
    Sleep(1);
    LSX_MoveAbs(Tango2, 1, 1, 0, 0, true);
    Sleep(1);
    LSX_MoveAbs(Tango2, 0, 1, 0, 0, true);
    Sleep(1);
    LSX_MoveAbs(Tango2, 0, 0, 0, 0, true);
    Sleep(1);
  end;
end;



procedure TForm1.Button7Click(Sender: TObject);
begin
  if connected1 then
  if Th1.Suspended then Th1.Resume else Th1.Suspend;
end;

procedure TForm1.Button8Click(Sender: TObject);
begin
  if connected2 then
  if Th2.Suspended then Th2.Resume else Th2.Suspend;
end;


procedure TForm1.FormCreate(Sender: TObject);
begin
  cbo_ComPort.ItemIndex := 0;
  cbo_BaudRate.ItemIndex := 3;
  cbo_ComPort2.ItemIndex := 0;
  cbo_BaudRate2.ItemIndex := 3;

  Th1 := TmyThread1.Create(true);
  Th1.FreeOnTerminate := True;
  Th1.Priority := tpNormal;

  Th2 := TmyThread2.Create(true);
  Th2.FreeOnTerminate := True;
  Th2.Priority := tpNormal;

  LSX_CreateLSID(Tango1);
  LSX_CreateLSID(Tango2);
end;


procedure TForm1.FormDestroy(Sender: TObject);
begin
  LSX_FreeLSID(Tango1);
  LSX_FreeLSID(Tango2);
end;


begin
  connected1 := false;
  connected2 := false;
end.

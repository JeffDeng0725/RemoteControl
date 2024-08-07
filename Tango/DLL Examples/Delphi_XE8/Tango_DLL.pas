unit Tango_DLL;

interface

const
  TangoDLL = 'Tango_dll.dll';
  XAxis = 1;
  YAxis = 2;
  ZAxis = 3;
  AAxis = 4;

type
  TLS_ControlInitPar = packed record
    Size: Integer;
    InterfaceType: Integer;
    ComName: string[32];
    ShowProt: LongBool;
    ShowCmdList: LongBool;

    BaudRate: Integer;
    IOAddress: LongWord;
    CardIndex: Integer;

    ControlType: Integer;
    VersionStr: string[64];
    Axes: Integer;
    ErrorCode: Integer;
    NewCmds: LongBool;
    Encoder: Integer;
    Display, SpeedPoti, HandWheel, Snapshot, TVR, TriggerOut: LongBool;

    DemoMode: LongBool;

  end;

function LSX_Connect(LSID: Integer): Integer; stdcall; external TangoDLL;
function LSX_ConnectSimple(LSID: Integer; AnInterfaceType: Integer; AComName: PAnsiChar; ABaudRate: Integer; AShowProt: LongBool): Integer; stdcall; external TangoDLL;
function LSX_ConnectEx(LSID: Integer; var AControlInitPar: TLS_ControlInitPar): Integer; stdcall; external TangoDLL;
function LSX_Disconnect(LSID: Integer): Integer; stdcall; external TangoDLL;
function LSX_LoadConfig(LSID: Integer; FileName: PAnsiChar): Integer; stdcall; external TangoDLL;
function LSX_SaveConfig(LSID: Integer; FileName: PAnsiChar): Integer; stdcall; external TangoDLL;

function LSX_MoveAbs(LSID: Integer; X, Y, Z, A: Double; Wait: LongBool): Integer; stdcall; external TangoDLL;
function LSX_MoveRel(LSID: Integer; X, Y, Z, A: Double; Wait: LongBool): Integer; stdcall; external TangoDLL;
function LSX_Calibrate(LSID: Integer): Integer; stdcall; external TangoDLL;
function LSX_RMeasure(LSID: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetPitch(LSID: Integer; X, Y, Z, A: Double): Integer; stdcall; external TangoDLL;
function LSX_SetPos(LSID: Integer; X, Y, Z, A: Double): Integer; stdcall; external TangoDLL;
function LSX_SetActiveAxes(LSID: Integer; Flags: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetVel(LSID: Integer; X, Y, Z, A: Double): Integer; stdcall; external TangoDLL;
function LSX_SetAccel(LSID: Integer; X, Y, Z, A: Double): Integer; stdcall; external TangoDLL;
function LSX_SetReduction(LSID: Integer; X, Y, Z, A: Double): Integer; stdcall; external TangoDLL;
function LSX_SetDelay(LSID: Integer; Delay: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetSwitchPolarity(LSID: Integer; XP, YP, ZP, AP: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetSwitchActive(LSID: Integer; XA, YA, ZA, AA: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetJoystickOn(LSID: Integer; PositionCount, Encoder: LongBool): Integer; stdcall; external TangoDLL;
function LSX_SetJoystickOff(LSID: Integer): Integer; stdcall; external TangoDLL;
function LSX_SoftwareReset(LSID: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetDigitalOutput(LSID: Integer; Index: Integer; Value: LongBool): Integer; stdcall; external TangoDLL;
function LSX_GetDigitalInputs(LSID: Integer; var Value: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetAnalogOutput(LSID: Integer; Index: Integer; Value: Integer): Integer; stdcall; external TangoDLL;
function LSX_GetAnalogInput(LSID: Integer; Index: Integer; var Value: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetLimit(LSID: Integer; Axis: Integer; MinRange, MaxRange: Double): Integer; stdcall; external TangoDLL;
function LSX_SetLimitControl(LSID: Integer; Axis: Integer; Active: LongBool): Integer; stdcall; external TangoDLL;
function LSX_GetPos(LSID: Integer; var X, Y, Z, A: Double): Integer; stdcall; external TangoDLL;
function LSX_GetStatus(LSID: Integer; Stat: PAnsiChar; MaxLen: Integer): Integer; stdcall; external TangoDLL;
function LSX_GetEncoderMask(LSID: Integer; var Flags: Integer): Integer; stdcall; external TangoDLL;
function LSX_StopAxes(LSID: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetAbortFlag(LSID: Integer): Integer; stdcall; external TangoDLL;
function LSX_MoveRelSingleAxis(LSID: Integer; Axis: Integer; Value: Double; Wait: LongBool): Integer; stdcall; external TangoDLL;
function LSX_MoveAbsSingleAxis(LSID: Integer; Axis: Integer; Value: Double; Wait: LongBool): Integer; stdcall; external TangoDLL;
function LSX_SetControlPars(LSID: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetMotorCurrent(LSID: Integer; X, Y, Z, A: Double): Integer; stdcall; external TangoDLL;
function LSX_SetVelSingleAxis(LSID: Integer; Axis: Integer; Vel: Double): Integer; stdcall; external TangoDLL;
function LSX_SetAccelSingleAxis(LSID: Integer; Axis: Integer; Accel: Double): Integer; stdcall; external TangoDLL;
function LSX_CalibrateEx(LSID: Integer; Flags: Integer): Integer; stdcall; external TangoDLL;
function LSX_RMeasureEx(LSID: Integer; Flags: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetShowProt(LSID: Integer; ShowProt: LongBool): Integer; stdcall; external TangoDLL;
function LSX_GetAnalogInputs2(LSID: Integer; var PT100, MV, V24: Integer): Integer; stdcall; external TangoDLL;
function LSX_SendString(LSID: Integer; Str, Ret: PAnsiChar; MaxLen: Integer; ReadLine: LongBool; TimeOut: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetSpeedPoti(LSID: Integer; SpeedPoti: LongBool): Integer; stdcall; external TangoDLL;
function LSX_SetTVRMode(LSID: Integer; XT, YT, ZT, AT: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetAutoStatus(LSID: Integer; Value: Integer): Integer; stdcall; external TangoDLL;
function LSX_GetStatusAxis(LSID: Integer; StatusAxisStr: PAnsiChar; MaxLen: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetDigIO_Off(LSID: Integer; Index: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetDigIO_Polarity(LSID: Integer; Index: Integer; High: LongBool): Integer; stdcall; external TangoDLL;
function LSX_SetDigIO_EmergencyStop(LSID: Integer; Index: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetDigIO_Distance(LSID: Integer; Index: Integer; Fkt: LongBool; Dist: Double; Axis: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetDimensions(LSID: Integer; XD, YD, ZD, AD: Integer): Integer; stdcall; external TangoDLL;
function LSX_MoveRelShort(LSID: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetEncoderPeriod(LSID: Integer; X, Y, Z, A: Double): Integer; stdcall; external TangoDLL;

function LSX_SetJoystickDir(LSID: Integer; XD, YD, ZD, AD: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetEncoderMask(LSID: Integer; Value: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetGear(LSID: Integer; X, Y, Z, A: Double): Integer; stdcall; external TangoDLL;
function LSX_SetHandWheelOn(LSID: Integer; PositionCount, Encoder: LongBool): Integer; stdcall; external TangoDLL;
function LSX_SetHandWheelOff(LSID: Integer): Integer; stdcall; external TangoDLL;

function LSX_SetFactorTVR(LSID: Integer; X, Y, Z, A: Double): Integer; stdcall; external TangoDLL; 
function LSX_SetController(LSID: Integer; XC, YC, ZC, AC: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetControllerCall(LSID: Integer; CtrCall: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetControllerSteps(LSID: Integer; X, Y, Z, A: Double): Integer; stdcall; external TangoDLL;
function LSX_SetControllerFactor(LSID: Integer; X, Y, Z, A: Double): Integer; stdcall; external TangoDLL;
function LSX_SetControllerTWDelay(LSID: Integer; CtrTWDelay: Integer): Integer; stdcall; external TangoDLL;

function LSX_SetEncoderRefSignal(LSID: Integer; XR, YR, ZR, AR: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetEncoderPosition(LSID: Integer; Value: LongBool): Integer; stdcall; external TangoDLL;

function LSX_GetVersionStr(LSID: Integer; Vers: PAnsiChar; MaxLen: Integer): Integer; stdcall; external TangoDLL;
function LSX_GetError(LSID: Integer; var ErrorCode: Integer): Integer; stdcall; external TangoDLL;
function LSX_GetPosSingleAxis(LSID: Integer; Axis: Integer; var Pos: Double): Integer; stdcall; external TangoDLL;
function LSX_SetDistance(LSID: Integer; X, Y, Z, A: Double): Integer; stdcall; external TangoDLL;
function LSX_GetPosEx(LSID: Integer; var X, Y, Z, R: Double; Encoder: LongBool): Integer; stdcall; external TangoDLL;

function LSX_SetShowCmdList(LSID: Integer; ShowCmdList: LongBool): Integer; stdcall; external TangoDLL;
function LSX_SetWriteLogText(LSID: Integer; AWriteLogText: LongBool): Integer; stdcall; external TangoDLL;
function LSX_SetControllerTimeout(LSID: Integer; ACtrTimeout: Integer): Integer; stdcall; external TangoDLL;

function LSX_SetEncoderActive(LSID: Integer; Flags: Integer): Integer; stdcall; external TangoDLL;
function LSX_GetSnapshotCount(LSID: Integer; var SnsCount: Integer): Integer; stdcall; external TangoDLL;
function LSX_GetSnapshotPos(LSID: Integer; var X, Y, Z, A: Double): Integer; stdcall; external TangoDLL;
function LSX_SetCorrTblOff(LSID: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetCorrTblOn(LSID: Integer; AFileName: PAnsiChar): Integer; stdcall; external TangoDLL;
function LSX_SetFactorMode(LSID: Integer; AFactorMode: LongBool; X, Y, Z, A: Double): Integer; stdcall; external TangoDLL;
function LSX_SetSnapshot(LSID: Integer; ASnapshot: LongBool): Integer; stdcall; external TangoDLL;
function LSX_SetSnapshotPar(LSID: Integer; High, AutoMode: LongBool): Integer; stdcall; external TangoDLL;
function LSX_SetTrigger(LSID: Integer; ATrigger: LongBool): Integer; stdcall; external TangoDLL;
function LSX_SetTriggerPar(LSID: Integer; Axis, Mode, Signal: Integer; Distance: Double): Integer; stdcall; external TangoDLL;

function LSX_SetLanguage(LSID: Integer; PLN: PAnsiChar): Integer; stdcall; external TangoDLL;
function LSX_GetSwitches(LSID: Integer; var Flags: Integer): Integer; stdcall; external TangoDLL;

function LSX_GetSerialNr(LSID: Integer; SerialNr: PAnsiChar; MaxLen: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetCalibOffset(LSID: Integer; X, Y, Z, R: Double): Integer; stdcall; external TangoDLL;
function LSX_SetRMOffset(LSID: Integer; X, Y, Z, R: Double): Integer; stdcall; external TangoDLL;
function LSX_GetSnapshotPosArray(LSID: Integer; Index: Integer; var X, Y, Z, R: Double): Integer; stdcall; external TangoDLL;
function LSX_SetAxisDirection(LSID: Integer; XD, YD, ZD, AD: Integer): Integer; stdcall; external TangoDLL;

function LSX_SetCalibrateDir(LSID: Integer; XD, YD, ZD, AD: Integer): Integer; stdcall; external TangoDLL;
function LSX_LStepSave(LSID: Integer): Integer; stdcall; external TangoDLL;

function LSX_SetBPZ(LSID: Integer; AValue: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetBPZTrackballFactor(LSID: Integer; AValue: Double): Integer; stdcall; external TangoDLL;
function LSX_SetBPZTrackballBackLash(LSID: Integer; X, Y, Z, R: Double): Integer; stdcall; external TangoDLL;
function LSX_SetBPZJoyspeed(LSID: Integer; APar: Integer; AValue: Double): Integer; stdcall; external TangoDLL;
function LSX_SetJoystickWindow(LSID: Integer; AValue: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetCurrentDelay(LSID: Integer; X, Y, Z, R: Integer): Integer; stdcall; external TangoDLL;
function LSX_MoveEx(LSID: Integer; X, Y, Z, R: Double; Relative, Wait: LongBool; AxisCount: Integer): Integer; stdcall; external TangoDLL;
function LSX_WaitForAxisStop(LSID: Integer; AFlags: Integer; ATimeoutValue: Integer; var ATimeout: LongBool): Integer; stdcall; external TangoDLL;
function LSX_SendStringPosCmd(LSID: Integer; Str, Ret: PAnsiChar; MaxLen: Integer; ReadLine: LongBool; TimeOut: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetDigitalOutputs(LSID: Integer; Value: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetWriteLogTextFN(LSID: Integer; AWriteLogText: LongBool; ALogFN: PAnsiChar): Integer; stdcall; external TangoDLL;
function LSX_SetDigitalOutputsE(LSID: Integer; Value: Integer): Integer; stdcall; external TangoDLL;
function LSX_GetDigitalInputsE(LSID: Integer; var Value: Integer): Integer; stdcall; external TangoDLL;
function LSX_EnableCommandRetry(LSID: Integer; AValue: LongBool): Integer; stdcall; external TangoDLL;
function LSX_SetXYAxisComp(LSID: Integer; Value: Integer): Integer; stdcall; external TangoDLL;
function LSX_GetVersionStrDet(LSID: Integer; VersDet: PAnsiChar; MaxLen: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetCommandTimeout(LSID: Integer; AtoRead, AtoMove, AtoCalibrate: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetExtValue(LSID: Integer; AName, AValue: Integer): Integer; stdcall; external TangoDLL;
function LSX_FlushBuffer(LSID: Integer; AValue: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetProcessMessagesProc(LSID: Integer; Proc: Pointer): Integer; stdcall; external TangoDLL;
//#JL 20040305.2
function LSX_GetEEPRomValue(LSID: Integer; Offset: byte; var Value: byte): Integer; stdcall; external TangoDLL;
function LSX_SetEEPRomValue(LSID: Integer; Offset: byte; Value: byte): Integer; stdcall; external TangoDLL;
//end #JL 20040305.2
function LSX_GetXYAxisComp(LSID: Integer; var Value: Integer): Integer; stdcall; external TangoDLL;
function LSX_GetDimensions(LSID: Integer; var XD, YD, ZD, AD: Integer): Integer; stdcall; external TangoDLL;                                                                                                     
function LSX_GetPitch(LSID: Integer; var X, Y, Z, A: Double): Integer; stdcall; external TangoDLL;
function LSX_GetGear(LSID: Integer; var X, Y, Z, A: Double): Integer; stdcall; external TangoDLL;
function LSX_GetVel(LSID: Integer; var X, Y, Z, A: Double): Integer; stdcall; external TangoDLL;
function LSX_GetAccel(LSID: Integer; var X, Y, Z, A: Double): Integer; stdcall; external TangoDLL;
function LSX_SetVelFac(LSID: Integer; X, Y, Z, R: Double): Integer; stdcall; external TangoDLL;
function LSX_GetVelFac(LSID: Integer; var X, Y, Z, R: Double): Integer; stdcall; external TangoDLL;
function LSX_GetSpeedPoti(LSID: Integer; var SpePoti: LongBool): Integer; stdcall; external TangoDLL;
function LSX_GetMotorCurrent(LSID: Integer; var X, Y, Z, A: Double): Integer; stdcall; external TangoDLL;
function LSX_GetReduction(LSID: Integer; var X, Y, Z, A: Double): Integer; stdcall; external TangoDLL;
function LSX_GetCurrentDelay(LSID: Integer; var X, Y, Z, R: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetOutFuncLev(LSID: Integer; X, Y, Z, R: Double): Integer; stdcall; external TangoDLL;
function LSX_GetOutFuncLev(LSID: Integer; var X, Y, Z, R: Double): Integer; stdcall; external TangoDLL;
function LSX_GetActiveAxes(LSID: Integer; var Flags: Integer): Integer; stdcall; external TangoDLL;
function LSX_GetAxisDirection(LSID: Integer; var XD, YD, ZD, AD: Integer): Integer; stdcall; external TangoDLL;
function LSX_GetCalibOffset(LSID: Integer; var X, Y, Z, R: Double): Integer; stdcall; external TangoDLL;
function LSX_GetRMOffset(LSID: Integer; var X, Y, Z, R: Double): Integer; stdcall; external TangoDLL;
function LSX_GetCalibrateDir(LSID: Integer; var XD, YD, ZD, AD: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetCalibBackSpeed(LSID: Integer; Speed: Integer): Integer; stdcall; external TangoDLL;
function LSX_GetCalibBackSpeed(LSID: Integer; var Speed: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetRefSpeed(LSID: Integer; Speed: Integer): Integer; stdcall; external TangoDLL;
function LSX_GetRefSpeed(LSID: Integer; var Speed: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetPowerAmplifier(LSID: Integer; Amplifier: LongBool): Integer; stdcall; external TangoDLL;
function LSX_GetPowerAmplifier(LSID: Integer; var Amplifier: LongBool): Integer; stdcall; external TangoDLL;
function LSX_SetMotorTablePatch(LSID: Integer; Active: LongBool): Integer; stdcall; external TangoDLL;
function LSX_GetMotorTablePatch(LSID: Integer; var Active: LongBool): Integer; stdcall; external TangoDLL;
function LSX_SetJoystickFilter(LSID: Integer; Active: LongBool): Integer; stdcall; external TangoDLL;
function LSX_GetJoystickFilter(LSID: Integer; var Active: LongBool): Integer; stdcall; external TangoDLL;
function LSX_SetStopPolarity(LSID: Integer; HighActiv: LongBool): Integer; stdcall; external TangoDLL;
function LSX_GetStopPolarity(LSID: Integer; var HighActiv: LongBool): Integer; stdcall; external TangoDLL;
function LSX_SetVLevel(LSID: Integer; VRegion: Integer; DownLevel, UppLevel: Double): Integer; stdcall; external TangoDLL;
function LSX_GetVLevel(LSID: Integer; VRegion: Integer; var DownLevel, UppLevel: Double): Integer; stdcall; external TangoDLL;
function LSX_SetStopAccel(LSID: Integer; XD, YD, ZD, AD: Double): Integer; stdcall; external TangoDLL;
function LSX_GetStopAccel(LSID: Integer; var XD, YD, ZD, AD: Double): Integer; stdcall; external TangoDLL;
function LSX_GetVersionStrInfo(LSID: Integer; VersInfo: PAnsiChar; MaxLen: Integer): Integer; stdcall; external TangoDLL;
function LSX_GetStatusLimit(LSID: Integer; Limit: PAnsiChar; MaxLen: Integer): Integer; stdcall; external TangoDLL;
function LSX_GetSecurityErr(LSID: Integer; var Value: LongWord): Integer; stdcall; external TangoDLL;
function LSX_GetSecurityStatus(LSID: Integer; var Value: LongWord): Integer; stdcall; external TangoDLL;
function LSX_GetDelay(LSID: Integer; var Delay: Integer): Integer; stdcall; external TangoDLL;
function LSX_GetDistance(LSID: Integer; var X, Y, Z, R: Double): Integer; stdcall; external TangoDLL;
function LSX_ClearPos(LSID: Integer; Flags: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetDigJoySpeed(LSID: Integer; X, Y, Z, R: Double): Integer; stdcall; external TangoDLL;
function LSX_GetDigJoySpeed(LSID: Integer; var X, Y, Z, R: Double): Integer; stdcall; external TangoDLL;
function LSX_GetJoystickDir(LSID: Integer; var XD, YD, ZD, RD: Integer): Integer; stdcall; external TangoDLL;
function LSX_GetJoystick(LSID: Integer; var JoystickOn, Manual, PositionCount, Encoder: LongBool): Integer; stdcall; external TangoDLL;
function LSX_GetJoystickWindow(LSID: Integer; var AValue: Integer): Integer; stdcall; external TangoDLL;
function LSX_GetHandWheel(LSID: Integer; var HandWheelOn, PositionCount, Encoder: LongBool): Integer; stdcall; external TangoDLL;
function LSX_GetBPZ(LSID: Integer; var AValue: Integer): Integer; stdcall; external TangoDLL;
function LSX_GetBPZTrackballFactor(LSID: Integer; var AValue: Double): Integer; stdcall; external TangoDLL;
function LSX_GetBPZTrackballBackLash(LSID: Integer; var X, Y, Z, R: Double): Integer; stdcall; external TangoDLL;
function LSX_GetBPZJoyspeed(LSID: Integer; APar: Integer; var AValue: Double): Integer; stdcall; external TangoDLL;
function LSX_GetLimitControl(LSID: Integer; Axis: Integer; var Active: LongBool): Integer; stdcall; external TangoDLL;
function LSX_SetAutoLimitAfterCalibRM(LSID: Integer; Flags: Integer): Integer; stdcall; external TangoDLL;
function LSX_GetAutoLimitAfterCalibRM(LSID: Integer; var Flags: Integer): Integer; stdcall; external TangoDLL;
function LSX_GetSwitchPolarity(LSID: Integer; var XP, YP, ZP, RP: Integer): Integer; stdcall; external TangoDLL;
function LSX_GetSwitchActive(LSID: Integer; var XA, YA, ZA, RA: Integer): Integer; stdcall; external TangoDLL;
function LSX_GetTVRMode(LSID: Integer; var XT, YT, ZT, RT: Integer): Integer; stdcall; external TangoDLL;
function LSX_GetFactorTVR(LSID: Integer; var X, Y, Z, R: Double): Integer; stdcall; external TangoDLL;
function LSX_SetTVROutMode(LSID: Integer; XT, YT, ZT, RT: Integer): Integer; stdcall; external TangoDLL;
function LSX_GetTVROutMode(LSID: Integer; var XT, YT, ZT, RT: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetTVROutResolution(LSID: Integer; X, Y, Z, R: Integer): Integer; stdcall; external TangoDLL;
function LSX_GetTVROutResolution(LSID: Integer; var X, Y, Z, R: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetTVROutPitch(LSID: Integer; X, Y, Z, R: Double): Integer; stdcall; external TangoDLL;
function LSX_GetTVROutPitch(LSID: Integer; var X, Y, Z, R: Double): Integer; stdcall; external TangoDLL;
function LSX_SetVelTVRO(LSID: Integer; X, Y, Z, R: Double): Integer; stdcall; external TangoDLL;
function LSX_GetVelTVRO(LSID: Integer; var X, Y, Z, R: Double): Integer; stdcall; external TangoDLL;
function LSX_SetAccelTVRO(LSID: Integer; X, Y, Z, R: Double): Integer; stdcall; external TangoDLL;
function LSX_GetAccelTVRO(LSID: Integer; var X, Y, Z, R: Double): Integer; stdcall; external TangoDLL;
function LSX_SetVelSingleAxisTVRO(LSID: Integer; Axis: Integer; Vel: Double): Integer; stdcall; external TangoDLL;
function LSX_SetAccelSingleAxisTVRO(LSID: Integer; Axis: Integer; Accel: Double): Integer; stdcall; external TangoDLL;
function LSX_SetPosTVRO(LSID: Integer; X, Y, Z, R: Double): Integer; stdcall; external TangoDLL;
function LSX_GetPosTVRO(LSID: Integer; var X, Y, Z, R: Double): Integer; stdcall; external TangoDLL;
function LSX_MoveAbsTVRO(LSID: Integer; X, Y, Z, R: Double; Wait: LongBool): Integer; stdcall; external TangoDLL;
function LSX_MoveRelTVRO(LSID: Integer; X, Y, Z, R: Double; Wait: LongBool): Integer; stdcall; external TangoDLL;
function LSX_MoveRelTVROSingleAxis(LSID: Integer; Axis: Integer; Value: Double; Wait: LongBool): Integer; stdcall; external TangoDLL;
function LSX_MoveAbsTVROSingleAxis(LSID: Integer; Axis: Integer; Value: Double; Wait: LongBool): Integer; stdcall; external TangoDLL;
function LSX_GetStatusTVRO(LSID: Integer; Stat: PANsiChar; MaxLen: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetTargetWindow(LSID: Integer; X, Y, Z, R: Double): Integer; stdcall; external TangoDLL;
function LSX_GetTargetWindow(LSID: Integer; var X, Y, Z, R: Double): Integer; stdcall; external TangoDLL;
function LSX_GetEncoderPeriod(LSID: Integer; var X, Y, Z, R: Double): Integer; stdcall; external TangoDLL;
function LSX_GetEncoderRefSignal(LSID: Integer; var XR, YR, ZR, RR: Integer): Integer; stdcall; external TangoDLL;
function LSX_GetEncoderPosition(LSID: Integer; var Value: LongBool): Integer; stdcall; external TangoDLL;
function LSX_GetEncoderActive(LSID: Integer; var Flags: Integer): Integer; stdcall; external TangoDLL;
function LSX_GetController(LSID: Integer; var XC, YC, ZC, RC: Integer): Integer; stdcall; external TangoDLL;
function LSX_GetControllerCall(LSID: Integer; var CtrCall: Integer): Integer; stdcall; external TangoDLL;
function LSX_GetControllerSteps(LSID: Integer; var X, Y, Z, R: Double): Integer; stdcall; external TangoDLL;
function LSX_GetControllerFactor(LSID: Integer; var X, Y, Z, R: Double): Integer; stdcall; external TangoDLL;
function LSX_GetControllerTWDelay(LSID: Integer; var CtrTWDelay: Integer): Integer; stdcall; external TangoDLL;
function LSX_GetControllerTimeout(LSID: Integer; var ACtrTimeout: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetCtrFastMoveOn(LSID: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetCtrFastMoveOff(LSID: Integer): Integer; stdcall; external TangoDLL;
function LSX_GetCtrFastMove(LSID: Integer; var Active: LongBool): Integer; stdcall; external TangoDLL;
function LSX_ClearCtrFastMoveCounter(LSID: Integer): Integer; stdcall; external TangoDLL;
function LSX_GetCtrFastMoveCounter(LSID: Integer; var XC, YC, ZC, RC: Integer): Integer; stdcall; external TangoDLL;
function LSX_ClearEncoder(LSID: Integer; Axis: Integer): Integer; stdcall; external TangoDLL;
function LSX_GetEncoder(LSID: Integer; var XP, YP, ZP, RP: Double): Integer; stdcall; external TangoDLL;
function LSX_GetTrigger(LSID: Integer; var ATrigger: LongBool): Integer; stdcall; external TangoDLL;
function LSX_GetTriggerPar(LSID: Integer; var Axis, Mode, Signal: Integer; var Distance: Double): Integer; stdcall; external TangoDLL;
function LSX_SetTrigCount(LSID: Integer; Value: Integer): Integer; stdcall; external TangoDLL;
function LSX_GetTrigCount(LSID: Integer; var Value: Integer): Integer; stdcall; external TangoDLL;
function LSX_SetTVRInPulse(LSID: Integer; Axis: Integer; Direction: LongBool): Integer; stdcall; external TangoDLL;
function LSX_GetSnapshot(LSID: Integer; var ASnapshot: LongBool): Integer; stdcall; external TangoDLL;
function LSX_SetSnapshotFilter(LSID: Integer; Time: Integer): Integer; stdcall; external TangoDLL;
function LSX_GetSnapshotFilter(LSID: Integer; var Time: Integer): Integer; stdcall; external TangoDLL;
function LSX_GetSnapshotPar(LSID: Integer; var High, AutoMode: LongBool): Integer; stdcall; external TangoDLL;
function LSX_GetLimit(LSID: Integer; Axis: Integer; var MinRange, MaxRange: Double): Integer; stdcall; external TangoDLL;
function LSX_JoyChangeAxis(LSID: Integer; Value: LongBool): Integer; stdcall; external TangoDLL;
function LSX_GetJoyChangeAxis(LSID: Integer; var Value: LongBool): Integer; stdcall; external TangoDLL;


function LSX_CreateLSID(var LSID: Integer): Integer; stdcall; external TangoDLL;
function LSX_FreeLSID(LSID: Integer): Integer; stdcall; external TangoDLL;

implementation

end.


Option Strict Off
Option Explicit On
Module Module1
    Declare Function LSX_CreateLSID Lib "Tango_X.dll" (ByRef LSID As Integer) As Integer
    Declare Function LSX_FreeLSID Lib "Tango_X.dll" (ByVal LSID As Integer) As Integer
	Declare Function LSX_Connect Lib "Tango_X.dll" (ByVal LSID As Integer) As Integer
	Declare Function LSX_ConnectSimple Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lAnInterfaceType As Integer, ByVal pcAComName As String, ByVal lABaudRate As Integer, ByVal bAShowProt As Integer) As Integer
	Declare Function LSX_ConnectEx Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pAControlInitPar As Object) As Integer
	Declare Function LSX_Disconnect Lib "Tango_X.dll" (ByVal LSID As Integer)  As Integer
	Declare Function LSX_LoadConfig Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal pcFileName As String) As Integer
	Declare Function LSX_SaveConfig Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal pcFileName As String) As Integer
	Declare Function LSX_MoveAbs Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dA As Double, ByVal bWait As Integer) As Integer
	Declare Function LSX_MoveRel Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dA As Double, ByVal bWait As Integer) As Integer
	Declare Function LSX_Calibrate Lib "Tango_X.dll" (ByVal LSID As Integer)  As Integer
	Declare Function LSX_RMeasure Lib "Tango_X.dll" (ByVal LSID As Integer)  As Integer
	Declare Function LSX_SetPitch Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dA As Double) As Integer
	Declare Function LSX_SetPos Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dA As Double) As Integer
	Declare Function LSX_SetActiveAxes Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lFlags As Integer) As Integer
	Declare Function LSX_SetVel Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dA As Double) As Integer
	Declare Function LSX_SetAccel Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dA As Double) As Integer
	Declare Function LSX_SetReduction Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dA As Double) As Integer
	Declare Function LSX_SetDelay Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lDelay As Integer) As Integer
	Declare Function LSX_SetSwitchPolarity Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lXP As Integer, ByVal lYP As Integer, ByVal lZP As Integer, ByVal lAP As Integer) As Integer
	Declare Function LSX_SetSwitchActive Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lXA As Integer, ByVal lYA As Integer, ByVal lZA As Integer, ByVal lAA As Integer) As Integer
	Declare Function LSX_SetJoystickOn Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal bPositionCount As Integer, ByVal bEncoder As Integer) As Integer
	Declare Function LSX_SetJoystickOff Lib "Tango_X.dll" (ByVal LSID As Integer)  As Integer
	Declare Function LSX_SoftwareReset Lib "Tango_X.dll" (ByVal LSID As Integer)  As Integer
	Declare Function LSX_SetDigitalOutput Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lIndex As Integer, ByVal bValue As Integer) As Integer
	Declare Function LSX_GetDigitalInputs Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef plValue As Integer) As Integer
	Declare Function LSX_SetAnalogOutput Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lIndex As Integer, ByVal lValue As Integer) As Integer
	Declare Function LSX_GetAnalogInput Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lIndex As Integer, ByRef plValue As Integer) As Integer
    Declare Function LSX_GetHdiKeys Lib "Tango_dll.dll" (ByVal LSID As Integer, ByRef plKey1 As Integer, ByRef plKey2 As Integer, ByRef plKey3 As Integer, ByRef plKey4 As Integer) As Integer
	Declare Function LSX_SetLimit Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lAxis As Integer, ByVal dMinRange As Double, ByVal dMaxRange As Double) As Integer
	Declare Function LSX_SetLimitControl Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lAxis As Integer, ByVal bActive As Integer) As Integer
	Declare Function LSX_GetPos Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdA As Double) As Integer
	Declare Function LSX_GetStatus Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal pcStat As String, ByVal lMaxLen As Integer) As Integer
	Declare Function LSX_GetEncoderMask Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef plFlags As Integer) As Integer
	Declare Function LSX_StopAxes Lib "Tango_X.dll" (ByVal LSID As Integer)  As Integer
	Declare Function LSX_SetAbortFlag Lib "Tango_X.dll" (ByVal LSID As Integer)  As Integer
	Declare Function LSX_MoveRelSingleAxis Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lAxis As Integer, ByVal dValue As Double, ByVal bWait As Integer) As Integer
	Declare Function LSX_MoveAbsSingleAxis Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lAxis As Integer, ByVal dValue As Double, ByVal bWait As Integer) As Integer
	Declare Function LSX_SetControlPars Lib "Tango_X.dll" (ByVal LSID As Integer)  As Integer
	Declare Function LSX_SetMotorCurrent Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dA As Double) As Integer
	Declare Function LSX_SetVelSingleAxis Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lAxis As Integer, ByVal dVel As Double) As Integer
	Declare Function LSX_SetAccelSingleAxis Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lAxis As Integer, ByVal dAccel As Double) As Integer
	Declare Function LSX_CalibrateEx Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lFlags As Integer) As Integer
	Declare Function LSX_RMeasureEx Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lFlags As Integer) As Integer
	Declare Function LSX_SetShowProt Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal bShowProt As Integer) As Integer
	Declare Function LSX_GetAnalogInputs2 Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef plPT100 As Integer, ByRef plMV As Integer, ByRef plV24 As Integer) As Integer
	Declare Function LSX_SendString Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal pcStr As String, ByVal pcRet As String, ByVal lMaxLen As Integer, ByVal bReadLine As Integer, ByVal lTimeOut As Integer) As Integer
	Declare Function LSX_SetSpeedPoti Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal bSpeedPoti As Integer) As Integer
	Declare Function LSX_SetTVRMode Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lXT As Integer, ByVal lYT As Integer, ByVal lZT As Integer, ByVal lAT As Integer) As Integer
	Declare Function LSX_SetAutoStatus Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lValue As Integer) As Integer
	Declare Function LSX_GetStatusAxis Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal pcStatusAxisStr As String, ByVal lMaxLen As Integer) As Integer
	Declare Function LSX_SetDigIO_Off Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lIndex As Integer) As Integer
	Declare Function LSX_SetDigIO_Polarity Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lIndex As Integer, ByVal bHigh As Integer) As Integer
	Declare Function LSX_SetDigIO_EmergencyStop Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lIndex As Integer) As Integer
	Declare Function LSX_SetDigIO_Distance Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lIndex As Integer, ByVal bFkt As Integer, ByVal dDist As Double, ByVal lAxis As Integer) As Integer
	Declare Function LSX_SetDimensions Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lXD As Integer, ByVal lYD As Integer, ByVal lZD As Integer, ByVal lAD As Integer) As Integer
	Declare Function LSX_MoveRelShort Lib "Tango_X.dll" (ByVal LSID As Integer)  As Integer
	Declare Function LSX_SetEncoderPeriod Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dA As Double) As Integer
	Declare Function LSX_SetJoystickDir Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lXD As Integer, ByVal lYD As Integer, ByVal lZD As Integer, ByVal lAD As Integer) As Integer
	Declare Function LSX_SetEncoderMask Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lValue As Integer) As Integer
	Declare Function LSX_SetGear Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dA As Double) As Integer
	Declare Function LSX_SetHandWheelOn Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal bPositionCount As Integer, ByVal bEncoder As Integer) As Integer
	Declare Function LSX_SetHandWheelOff Lib "Tango_X.dll" (ByVal LSID As Integer)  As Integer
	Declare Function LSX_SetFactorTVR Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dA As Double) As Integer
	Declare Function LSX_SetTargetWindow Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dA As Double) As Integer
	Declare Function LSX_SetController Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lXC As Integer, ByVal lYC As Integer, ByVal lZC As Integer, ByVal lAC As Integer) As Integer
	Declare Function LSX_SetControllerCall Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lCtrCall As Integer) As Integer
	Declare Function LSX_SetControllerSteps Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dA As Double) As Integer
	Declare Function LSX_SetControllerFactor Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dA As Double) As Integer
	Declare Function LSX_SetControllerTWDelay Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lCtrTWDelay As Integer) As Integer
	Declare Function LSX_SetEncoderRefSignal Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lXR As Integer, ByVal lYR As Integer, ByVal lZR As Integer, ByVal lAR As Integer) As Integer
	Declare Function LSX_SetEncoderPosition Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal bValue As Integer) As Integer
	Declare Function LSX_GetVersionStr Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal pcVers As String, ByVal lMaxLen As Integer) As Integer
	Declare Function LSX_GetError Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef plErrorCode As Integer) As Integer
	Declare Function LSX_GetPosSingleAxis Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lAxis As Integer, ByRef pdPos As Double) As Integer
	Declare Function LSX_SetDistance Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dA As Double) As Integer
	Declare Function LSX_GetPosEx Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdR As Double, ByVal bEncoder As Integer) As Integer
	Declare Function LSX_SetShowCmdList Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal bShowCmdList As Integer) As Integer
	Declare Function LSX_SetWriteLogText Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal bAWriteLogText As Integer) As Integer
	Declare Function LSX_SetControllerTimeout Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lACtrTimeout As Integer) As Integer
	Declare Function LSX_SetEncoderActive Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lFlags As Integer) As Integer
	Declare Function LSX_GetSnapshotCount Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef plSnsCount As Integer) As Integer
	Declare Function LSX_GetSnapshotPos Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdA As Double) As Integer
	Declare Function LSX_SetCorrTblOff Lib "Tango_X.dll" (ByVal LSID As Integer)  As Integer
	Declare Function LSX_SetCorrTblOn Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal pcAFileName As String) As Integer
	Declare Function LSX_SetFactorMode Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal bAFactorMode As Integer, ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dA As Double) As Integer
	Declare Function LSX_SetSnapshot Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal bASnapshot As Integer) As Integer
	Declare Function LSX_SetSnapshotPar Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal bHigh As Integer, ByVal bAutoMode As Integer) As Integer
	Declare Function LSX_SetTrigger Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal bATrigger As Integer) As Integer
	Declare Function LSX_SetTriggerPar Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lAxis As Integer, ByVal lMode As Integer, ByVal lSignal As Integer, ByVal dDistance As Double) As Integer
	Declare Function LSX_SetLanguage Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal pcPLN As String) As Integer
	Declare Function LSX_GetSwitches Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef plFlags As Integer) As Integer
	Declare Function LSX_GetSerialNr Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal pcSerialNr As String, ByVal lMaxLen As Integer) As Integer
	Declare Function LSX_SetCalibOffset Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dR As Double) As Integer
	Declare Function LSX_SetRMOffset Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dR As Double) As Integer
	Declare Function LSX_GetSnapshotPosArray Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lIndex As Integer, ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdR As Double) As Integer
	Declare Function LSX_SetAxisDirection Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lXD As Integer, ByVal lYD As Integer, ByVal lZD As Integer, ByVal lAD As Integer) As Integer
	Declare Function LSX_SetCalibrateDir Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lXD As Integer, ByVal lYD As Integer, ByVal lZD As Integer, ByVal lAD As Integer) As Integer
	Declare Function LSX_LStepSave Lib "Tango_X.dll" (ByVal LSID As Integer)  As Integer
	Declare Function LSX_SetBPZ Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lAValue As Integer) As Integer
	Declare Function LSX_SetBPZTrackballFactor Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal dAValue As Double) As Integer
	Declare Function LSX_SetBPZTrackballBackLash Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dR As Double) As Integer
	Declare Function LSX_SetBPZJoyspeed Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lAPar As Integer, ByVal dAValue As Double) As Integer
	Declare Function LSX_SetJoystickWindow Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lAValue As Integer) As Integer
	Declare Function LSX_SetCurrentDelay Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lX As Integer, ByVal lY As Integer, ByVal lZ As Integer, ByVal lR As Integer) As Integer
	Declare Function LSX_MoveEx Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dR As Double, ByVal bRelative As Integer, ByVal bWait As Integer, ByVal lAxisCount As Integer) As Integer
	Declare Function LSX_WaitForAxisStop Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lAFlags As Integer, ByVal lATimeoutValue As Integer, ByRef pbATimeout As Integer) As Integer
	Declare Function LSX_SetProcessMessagesProc Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal Proc As Object) As Integer
	Declare Function LSX_SendStringPosCmd Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal pcStr As String, ByVal pcRet As String, ByVal lMaxLen As Integer, ByVal bReadLine As Integer, ByVal lTimeOut As Integer) As Integer
	Declare Function LSX_SetDigitalOutputs Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lValue As Integer) As Integer
	Declare Function LSX_SetWriteLogTextFN Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal bAWriteLogText As Integer, ByVal pcALogFN As String) As Integer
	Declare Function LSX_SetDigitalOutputsE Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lValue As Integer) As Integer
	Declare Function LSX_GetDigitalInputsE Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef plValue As Integer) As Integer
	Declare Function LSX_EnableCommandRetry Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal bAValue As Integer) As Integer
	Declare Function LSX_SetXYAxisComp Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lValue As Integer) As Integer
	Declare Function LSX_GetVersionStrDet Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal pcVersDet As String, ByVal lMaxLen As Integer) As Integer
	Declare Function LSX_SetCommandTimeout Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lAtoRead As Integer, ByVal lAtoMove As Integer, ByVal lAtoCalibrate As Integer) As Integer
	Declare Function LSX_SetExtValue Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lAName As Integer, ByVal lAValue As Integer) As Integer
	Declare Function LSX_FlushBuffer Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lAValue As Integer) As Integer
	Declare Function LSX_GetEEPRomValue Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal Offset As Object, ByRef pValue As Object) As Integer
	Declare Function LSX_SetEEPRomValue Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal Offset As Object, ByVal Value As Object) As Integer
	Declare Function LSX_GetXYAxisComp Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef plValue As Integer) As Integer
	Declare Function LSX_GetDimensions Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef plXD As Integer, ByRef plYD As Integer, ByRef plZD As Integer, ByRef plAD As Integer) As Integer
	Declare Function LSX_GetPitch Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdA As Double) As Integer
	Declare Function LSX_GetGear Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdA As Double) As Integer
	Declare Function LSX_GetVel Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdA As Double) As Integer
	Declare Function LSX_GetAccel Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdA As Double) As Integer
	Declare Function LSX_SetVelFac Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dR As Double) As Integer
	Declare Function LSX_GetVelFac Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdR As Double) As Integer
	Declare Function LSX_GetSpeedPoti Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pbSpePoti As Integer) As Integer
	Declare Function LSX_GetMotorCurrent Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdA As Double) As Integer
	Declare Function LSX_GetReduction Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdA As Double) As Integer
	Declare Function LSX_GetCurrentDelay Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef plX As Integer, ByRef plY As Integer, ByRef plZ As Integer, ByRef plR As Integer) As Integer
	Declare Function LSX_SetOutFuncLev Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dR As Double) As Integer
	Declare Function LSX_GetOutFuncLev Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdR As Double) As Integer
	Declare Function LSX_GetActiveAxes Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef plFlags As Integer) As Integer
	Declare Function LSX_GetAxisDirection Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef plXD As Integer, ByRef plYD As Integer, ByRef plZD As Integer, ByRef plAD As Integer) As Integer
	Declare Function LSX_GetCalibOffset Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdR As Double) As Integer
	Declare Function LSX_GetRMOffset Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdR As Double) As Integer
	Declare Function LSX_GetCalibrateDir Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef plXD As Integer, ByRef plYD As Integer, ByRef plZD As Integer, ByRef plAD As Integer) As Integer
	Declare Function LSX_SetCalibBackSpeed Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lSpeed As Integer) As Integer
	Declare Function LSX_GetCalibBackSpeed Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef plSpeed As Integer) As Integer
	Declare Function LSX_SetRefSpeed Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lSpeed As Integer) As Integer
	Declare Function LSX_GetRefSpeed Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef plSpeed As Integer) As Integer
	Declare Function LSX_SetPowerAmplifier Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal bAmplifier As Integer) As Integer
	Declare Function LSX_GetPowerAmplifier Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pbAmplifier As Integer) As Integer
	Declare Function LSX_SetMotorTablePatch Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal bActive As Integer) As Integer
	Declare Function LSX_GetMotorTablePatch Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pbActive As Integer) As Integer
	Declare Function LSX_SetJoystickFilter Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal bActive As Integer) As Integer
	Declare Function LSX_GetJoystickFilter Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pbActive As Integer) As Integer
	Declare Function LSX_SetStopPolarity Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal bHighActiv As Integer) As Integer
	Declare Function LSX_GetStopPolarity Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pbHighActiv As Integer) As Integer
	Declare Function LSX_SetVLevel Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lVRegion As Integer, ByVal dDownLevel As Double, ByVal dUppLevel As Double) As Integer
	Declare Function LSX_GetVLevel Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lVRegion As Integer, ByRef pdDownLevel As Double, ByRef pdUppLevel As Double) As Integer
	Declare Function LSX_SetStopAccel Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal dXD As Double, ByVal dYD As Double, ByVal dZD As Double, ByVal dAD As Double) As Integer
	Declare Function LSX_GetStopAccel Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pdXD As Double, ByRef pdYD As Double, ByRef pdZD As Double, ByRef pdAD As Double) As Integer
	Declare Function LSX_GetVersionStrInfo Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal pcVersInfo As String, ByVal lMaxLen As Integer) As Integer
	Declare Function LSX_GetStatusLimit Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal pcLimit As String, ByVal lMaxLen As Integer) As Integer
	Declare Function LSX_GetSecurityErr Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pValue As Object) As Integer
	Declare Function LSX_GetSecurityStatus Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pValue As Object) As Integer
	Declare Function LSX_GetDelay Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef plDelay As Integer) As Integer
	Declare Function LSX_GetDistance Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdR As Double) As Integer
	Declare Function LSX_ClearPos Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lFlags As Integer) As Integer
	Declare Function LSX_SetDigJoySpeed Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dR As Double) As Integer
	Declare Function LSX_GetDigJoySpeed Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdR As Double) As Integer
	Declare Function LSX_GetJoystickDir Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef plXD As Integer, ByRef plYD As Integer, ByRef plZD As Integer, ByRef plRD As Integer) As Integer
	Declare Function LSX_GetJoystick Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pbJoystickOn As Integer, ByRef pbManual As Integer, ByRef pbPositionCount As Integer, ByRef pbEncoder As Integer) As Integer
	Declare Function LSX_GetJoystickWindow Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef plAValue As Integer) As Integer
	Declare Function LSX_GetHandWheel Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pbHandWheelOn As Integer, ByRef pbPositionCount As Integer, ByRef pbEncoder As Integer) As Integer
	Declare Function LSX_GetBPZ Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef plAValue As Integer) As Integer
	Declare Function LSX_GetBPZTrackballFactor Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pdAValue As Double) As Integer
	Declare Function LSX_GetBPZTrackballBackLash Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdR As Double) As Integer
	Declare Function LSX_GetBPZJoyspeed Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lAPar As Integer, ByRef pdAValue As Double) As Integer
	Declare Function LSX_GetLimitControl Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lAxis As Integer, ByRef pbActive As Integer) As Integer
	Declare Function LSX_SetAutoLimitAfterCalibRM Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lFlags As Integer) As Integer
	Declare Function LSX_GetAutoLimitAfterCalibRM Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef plFlags As Integer) As Integer
	Declare Function LSX_GetSwitchPolarity Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef plXP As Integer, ByRef plYP As Integer, ByRef plZP As Integer, ByRef plRP As Integer) As Integer
	Declare Function LSX_GetSwitchActive Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef plXA As Integer, ByRef plYA As Integer, ByRef plZA As Integer, ByRef plRA As Integer) As Integer
	Declare Function LSX_GetTVRMode Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef plXT As Integer, ByRef plYT As Integer, ByRef plZT As Integer, ByRef plRT As Integer) As Integer
	Declare Function LSX_GetFactorTVR Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdR As Double) As Integer
	Declare Function LSX_SetTVROutMode Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lXT As Integer, ByVal lYT As Integer, ByVal lZT As Integer, ByVal lRT As Integer) As Integer
	Declare Function LSX_GetTVROutMode Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef plXT As Integer, ByRef plYT As Integer, ByRef plZT As Integer, ByRef plRT As Integer) As Integer
	Declare Function LSX_SetTVROutResolution Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lX As Integer, ByVal lY As Integer, ByVal lZ As Integer, ByVal lR As Integer) As Integer
	Declare Function LSX_GetTVROutResolution Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef plX As Integer, ByRef plY As Integer, ByRef plZ As Integer, ByRef plR As Integer) As Integer
	Declare Function LSX_SetTVROutPitch Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dR As Double) As Integer
	Declare Function LSX_GetTVROutPitch Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdR As Double) As Integer
	Declare Function LSX_SetVelTVRO Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dR As Double) As Integer
	Declare Function LSX_GetVelTVRO Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdR As Double) As Integer
	Declare Function LSX_SetAccelTVRO Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dR As Double) As Integer
	Declare Function LSX_GetAccelTVRO Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdR As Double) As Integer
	Declare Function LSX_SetVelSingleAxisTVRO Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lAxis As Integer, ByVal dVel As Double) As Integer
	Declare Function LSX_SetAccelSingleAxisTVRO Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lAxis As Integer, ByVal dAccel As Double) As Integer
	Declare Function LSX_SetPosTVRO Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dR As Double) As Integer
	Declare Function LSX_GetPosTVRO Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdR As Double) As Integer
	Declare Function LSX_MoveAbsTVRO Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dR As Double, ByVal bWait As Integer) As Integer
	Declare Function LSX_MoveRelTVRO Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dR As Double, ByVal bWait As Integer) As Integer
	Declare Function LSX_MoveRelTVROSingleAxis Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lAxis As Integer, ByVal dValue As Double, ByVal bWait As Integer) As Integer
	Declare Function LSX_MoveAbsTVROSingleAxis Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lAxis As Integer, ByVal dValue As Double, ByVal bWait As Integer) As Integer
	Declare Function LSX_GetStatusTVRO Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal pcStat As String, ByVal lMaxLen As Integer) As Integer
	Declare Function LSX_GetTargetWindow Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdR As Double) As Integer
	Declare Function LSX_GetEncoderPeriod Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdR As Double) As Integer
	Declare Function LSX_GetEncoderRefSignal Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef plXR As Integer, ByRef plYR As Integer, ByRef plZR As Integer, ByRef plRR As Integer) As Integer
	Declare Function LSX_GetEncoderPosition Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pbValue As Integer) As Integer
	Declare Function LSX_GetEncoderActive Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef plFlags As Integer) As Integer
	Declare Function LSX_GetController Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef plXC As Integer, ByRef plYC As Integer, ByRef plZC As Integer, ByRef plRC As Integer) As Integer
	Declare Function LSX_GetControllerCall Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef plCtrCall As Integer) As Integer
	Declare Function LSX_GetControllerSteps Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdR As Double) As Integer
	Declare Function LSX_GetControllerFactor Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdR As Double) As Integer
	Declare Function LSX_GetControllerTWDelay Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef plCtrTWDelay As Integer) As Integer
	Declare Function LSX_GetControllerTimeout Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef plACtrTimeout As Integer) As Integer
	Declare Function LSX_SetCtrFastMoveOn Lib "Tango_X.dll" (ByVal LSID As Integer)  As Integer
	Declare Function LSX_SetCtrFastMoveOff Lib "Tango_X.dll" (ByVal LSID As Integer)  As Integer
	Declare Function LSX_GetCtrFastMove Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pbActive As Integer) As Integer
	Declare Function LSX_ClearCtrFastMoveCounter Lib "Tango_X.dll" (ByVal LSID As Integer)  As Integer
	Declare Function LSX_GetCtrFastMoveCounter Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef plXC As Integer, ByRef plYC As Integer, ByRef plZC As Integer, ByRef plRC As Integer) As Integer
	Declare Function LSX_ClearEncoder Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lAxis As Integer) As Integer
	Declare Function LSX_GetEncoder Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pdXP As Double, ByRef pdYP As Double, ByRef pdZP As Double, ByRef pdRP As Double) As Integer
	Declare Function LSX_GetTrigger Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pbATrigger As Integer) As Integer
	Declare Function LSX_GetTriggerPar Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef plAxis As Integer, ByRef plMode As Integer, ByRef plSignal As Integer, ByRef pdDistance As Double) As Integer
	Declare Function LSX_SetTrigCount Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lValue As Integer) As Integer
	Declare Function LSX_GetTrigCount Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef plValue As Integer) As Integer
	Declare Function LSX_SetTVRInPulse Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lAxis As Integer, ByVal bDirection As Integer) As Integer
	Declare Function LSX_GetSnapshot Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pbASnapshot As Integer) As Integer
	Declare Function LSX_SetSnapshotFilter Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lTime As Integer) As Integer
	Declare Function LSX_GetSnapshotFilter Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef plTime As Integer) As Integer
	Declare Function LSX_GetSnapshotPar Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pbHigh As Integer, ByRef pbAutoMode As Integer) As Integer
	Declare Function LSX_GetLimit Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal lAxis As Integer, ByRef pdMinRange As Double, ByRef pdMaxRange As Double) As Integer
	Declare Function LSX_JoyChangeAxis Lib "Tango_X.dll" (ByVal LSID As Integer, ByVal bValue As Integer) As Integer
	Declare Function LSX_GetJoyChangeAxis Lib "Tango_X.dll" (ByVal LSID As Integer, ByRef pbValue As Integer) As Integer
End Module
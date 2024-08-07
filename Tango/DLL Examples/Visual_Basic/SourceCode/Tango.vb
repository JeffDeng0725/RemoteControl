Option Strict Off
Option Explicit On
Module Module1
    Declare Function LS_Connect Lib "Tango_dll.dll" () As Integer
    Declare Function LS_ConnectSimple Lib "Tango_dll.dll" (ByVal lAnInterfaceType As Integer, ByVal pcAComName As String, ByVal lABaudRate As Integer, ByVal bAShowProt As Integer) As Integer
    Declare Function LSX_ConnectSimple Lib "Tango_dll.dll" (ByVal lID As Integer, ByVal lAnInterfaceType As Integer, ByVal pcAComName As String, ByVal lABaudRate As Integer, ByVal bAShowProt As Integer) As Integer
    Declare Function LS_ConnectEx Lib "Tango_dll.dll" (ByRef pAControlInitPar As Object) As Integer
    Declare Function LS_Disconnect Lib "Tango_dll.dll" () As Integer
    Declare Function LS_LoadConfig Lib "Tango_dll.dll" (ByVal pcFileName As String) As Integer
    Declare Function LS_SaveConfig Lib "Tango_dll.dll" (ByVal pcFileName As String) As Integer
    Declare Function LS_MoveAbs Lib "Tango_dll.dll" (ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dA As Double, ByVal bWait As Integer) As Integer
    Declare Function LS_MoveRel Lib "Tango_dll.dll" (ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dA As Double, ByVal bWait As Integer) As Integer
    Declare Function LS_Calibrate Lib "Tango_dll.dll" () As Integer
    Declare Function LS_RMeasure Lib "Tango_dll.dll" () As Integer
    Declare Function LS_SetPitch Lib "Tango_dll.dll" (ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dA As Double) As Integer
    Declare Function LS_SetPos Lib "Tango_dll.dll" (ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dA As Double) As Integer
    Declare Function LS_SetActiveAxes Lib "Tango_dll.dll" (ByVal lFlags As Integer) As Integer
    Declare Function LS_SetVel Lib "Tango_dll.dll" (ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dA As Double) As Integer
    Declare Function LS_SetAccel Lib "Tango_dll.dll" (ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dA As Double) As Integer
    Declare Function LS_SetReduction Lib "Tango_dll.dll" (ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dA As Double) As Integer
    Declare Function LS_SetDelay Lib "Tango_dll.dll" (ByVal lDelay As Integer) As Integer
    Declare Function LS_SetSwitchPolarity Lib "Tango_dll.dll" (ByVal lXP As Integer, ByVal lYP As Integer, ByVal lZP As Integer, ByVal lAP As Integer) As Integer
    Declare Function LS_SetSwitchActive Lib "Tango_dll.dll" (ByVal lXA As Integer, ByVal lYA As Integer, ByVal lZA As Integer, ByVal lAA As Integer) As Integer
    Declare Function LS_SetJoystickOn Lib "Tango_dll.dll" (ByVal bPositionCount As Integer, ByVal bEncoder As Integer) As Integer
    Declare Function LS_SetJoystickOff Lib "Tango_dll.dll" () As Integer
    Declare Function LS_SoftwareReset Lib "Tango_dll.dll" () As Integer
    Declare Function LS_SetDigitalOutput Lib "Tango_dll.dll" (ByVal lIndex As Integer, ByVal bValue As Integer) As Integer
    Declare Function LS_GetDigitalInputs Lib "Tango_dll.dll" (ByRef plValue As Integer) As Integer
    Declare Function LS_SetAnalogOutput Lib "Tango_dll.dll" (ByVal lIndex As Integer, ByVal lValue As Integer) As Integer
    Declare Function LS_GetAnalogInput Lib "Tango_dll.dll" (ByVal lIndex As Integer, ByRef plValue As Integer) As Integer
    Declare Function LS_GetHdiKeys Lib "Tango_dll.dll" (ByRef plKey1 As Integer, ByRef plKey2 As Integer, ByRef plKey3 As Integer, ByRef plKey4 As Integer) As Integer
    Declare Function LS_SetLimit Lib "Tango_dll.dll" (ByVal lAxis As Integer, ByVal dMinRange As Double, ByVal dMaxRange As Double) As Integer
    Declare Function LS_SetLimitControl Lib "Tango_dll.dll" (ByVal lAxis As Integer, ByVal bActive As Integer) As Integer
    Declare Function LS_GetPos Lib "Tango_dll.dll" (ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdA As Double) As Integer
    Declare Function LS_GetStatus Lib "Tango_dll.dll" (ByVal pcStat As String, ByVal lMaxLen As Integer) As Integer
    Declare Function LS_GetEncoderMask Lib "Tango_dll.dll" (ByRef plFlags As Integer) As Integer
    Declare Function LS_StopAxes Lib "Tango_dll.dll" () As Integer
    Declare Function LS_SetAbortFlag Lib "Tango_dll.dll" () As Integer
    Declare Function LS_MoveRelSingleAxis Lib "Tango_dll.dll" (ByVal lAxis As Integer, ByVal dValue As Double, ByVal bWait As Integer) As Integer
    Declare Function LS_MoveAbsSingleAxis Lib "Tango_dll.dll" (ByVal lAxis As Integer, ByVal dValue As Double, ByVal bWait As Integer) As Integer
    Declare Function LS_SetControlPars Lib "Tango_dll.dll" () As Integer
    Declare Function LS_SetMotorCurrent Lib "Tango_dll.dll" (ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dA As Double) As Integer
    Declare Function LS_SetVelSingleAxis Lib "Tango_dll.dll" (ByVal lAxis As Integer, ByVal dVel As Double) As Integer
    Declare Function LS_SetAccelSingleAxis Lib "Tango_dll.dll" (ByVal lAxis As Integer, ByVal dAccel As Double) As Integer
    Declare Function LS_CalibrateEx Lib "Tango_dll.dll" (ByVal lFlags As Integer) As Integer
    Declare Function LS_RMeasureEx Lib "Tango_dll.dll" (ByVal lFlags As Integer) As Integer
    Declare Function LS_SetShowProt Lib "Tango_dll.dll" (ByVal bShowProt As Integer) As Integer
    Declare Function LS_GetAnalogInputs2 Lib "Tango_dll.dll" (ByRef plPT100 As Integer, ByRef plMV As Integer, ByRef plV24 As Integer) As Integer
    Declare Function LS_SendString Lib "Tango_dll.dll" (ByVal pcStr As String, ByVal pcRet As String, ByVal lMaxLen As Integer, ByVal bReadLine As Integer, ByVal lTimeOut As Integer) As Integer
    Declare Function LS_SetSpeedPoti Lib "Tango_dll.dll" (ByVal bSpeedPoti As Integer) As Integer
    Declare Function LS_SetTVRMode Lib "Tango_dll.dll" (ByVal lXT As Integer, ByVal lYT As Integer, ByVal lZT As Integer, ByVal lAT As Integer) As Integer
    Declare Function LS_SetAutoStatus Lib "Tango_dll.dll" (ByVal lValue As Integer) As Integer
    Declare Function LS_GetStatusAxis Lib "Tango_dll.dll" (ByVal pcStatusAxisStr As String, ByVal lMaxLen As Integer) As Integer
    Declare Function LS_SetDigIO_Off Lib "Tango_dll.dll" (ByVal lIndex As Integer) As Integer
    Declare Function LS_SetDigIO_Polarity Lib "Tango_dll.dll" (ByVal lIndex As Integer, ByVal bHigh As Integer) As Integer
    Declare Function LS_SetDigIO_EmergencyStop Lib "Tango_dll.dll" (ByVal lIndex As Integer) As Integer
    Declare Function LS_SetDigIO_Distance Lib "Tango_dll.dll" (ByVal lIndex As Integer, ByVal bFkt As Integer, ByVal dDist As Double, ByVal lAxis As Integer) As Integer
    Declare Function LS_SetDimensions Lib "Tango_dll.dll" (ByVal lXD As Integer, ByVal lYD As Integer, ByVal lZD As Integer, ByVal lAD As Integer) As Integer
    Declare Function LS_MoveRelShort Lib "Tango_dll.dll" () As Integer
    Declare Function LS_SetEncoderPeriod Lib "Tango_dll.dll" (ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dA As Double) As Integer
    Declare Function LS_SetJoystickDir Lib "Tango_dll.dll" (ByVal lXD As Integer, ByVal lYD As Integer, ByVal lZD As Integer, ByVal lAD As Integer) As Integer
    Declare Function LS_SetEncoderMask Lib "Tango_dll.dll" (ByVal lValue As Integer) As Integer
    Declare Function LS_SetGear Lib "Tango_dll.dll" (ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dA As Double) As Integer
    Declare Function LS_SetHandWheelOn Lib "Tango_dll.dll" (ByVal bPositionCount As Integer, ByVal bEncoder As Integer) As Integer
    Declare Function LS_SetHandWheelOff Lib "Tango_dll.dll" () As Integer
    Declare Function LS_SetFactorTVR Lib "Tango_dll.dll" (ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dA As Double) As Integer
    Declare Function LS_SetTargetWindow Lib "Tango_dll.dll" (ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dA As Double) As Integer
    Declare Function LS_SetController Lib "Tango_dll.dll" (ByVal lXC As Integer, ByVal lYC As Integer, ByVal lZC As Integer, ByVal lAC As Integer) As Integer
    Declare Function LS_SetControllerCall Lib "Tango_dll.dll" (ByVal lCtrCall As Integer) As Integer
    Declare Function LS_SetControllerSteps Lib "Tango_dll.dll" (ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dA As Double) As Integer
    Declare Function LS_SetControllerFactor Lib "Tango_dll.dll" (ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dA As Double) As Integer
    Declare Function LS_SetControllerTWDelay Lib "Tango_dll.dll" (ByVal lCtrTWDelay As Integer) As Integer
    Declare Function LS_SetEncoderRefSignal Lib "Tango_dll.dll" (ByVal lXR As Integer, ByVal lYR As Integer, ByVal lZR As Integer, ByVal lAR As Integer) As Integer
    Declare Function LS_SetEncoderPosition Lib "Tango_dll.dll" (ByVal bValue As Integer) As Integer
    Declare Function LS_GetVersionStr Lib "Tango_dll.dll" (ByVal pcVers As String, ByVal lMaxLen As Integer) As Integer
    Declare Function LS_GetError Lib "Tango_dll.dll" (ByRef plErrorCode As Integer) As Integer
    Declare Function LS_GetPosSingleAxis Lib "Tango_dll.dll" (ByVal lAxis As Integer, ByRef pdPos As Double) As Integer
    Declare Function LS_SetDistance Lib "Tango_dll.dll" (ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dA As Double) As Integer
    Declare Function LS_GetPosEx Lib "Tango_dll.dll" (ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdR As Double, ByVal bEncoder As Integer) As Integer
    Declare Function LS_SetShowCmdList Lib "Tango_dll.dll" (ByVal bShowCmdList As Integer) As Integer
    Declare Function LS_SetWriteLogText Lib "Tango_dll.dll" (ByVal bAWriteLogText As Integer) As Integer
    Declare Function LS_SetControllerTimeout Lib "Tango_dll.dll" (ByVal lACtrTimeout As Integer) As Integer
    Declare Function LS_SetEncoderActive Lib "Tango_dll.dll" (ByVal lFlags As Integer) As Integer
    Declare Function LS_GetSnapshotCount Lib "Tango_dll.dll" (ByRef plSnsCount As Integer) As Integer
    Declare Function LS_GetSnapshotPos Lib "Tango_dll.dll" (ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdA As Double) As Integer
    Declare Function LS_SetCorrTblOff Lib "Tango_dll.dll" () As Integer
    Declare Function LS_SetCorrTblOn Lib "Tango_dll.dll" (ByVal pcAFileName As String) As Integer
    Declare Function LS_SetFactorMode Lib "Tango_dll.dll" (ByVal bAFactorMode As Integer, ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dA As Double) As Integer
    Declare Function LS_SetSnapshot Lib "Tango_dll.dll" (ByVal bASnapshot As Integer) As Integer
    Declare Function LS_SetSnapshotPar Lib "Tango_dll.dll" (ByVal bHigh As Integer, ByVal bAutoMode As Integer) As Integer
    Declare Function LS_SetTrigger Lib "Tango_dll.dll" (ByVal bATrigger As Integer) As Integer
    Declare Function LS_SetTriggerPar Lib "Tango_dll.dll" (ByVal lAxis As Integer, ByVal lMode As Integer, ByVal lSignal As Integer, ByVal dDistance As Double) As Integer
    Declare Function LS_SetLanguage Lib "Tango_dll.dll" (ByVal pcPLN As String) As Integer
    Declare Function LS_GetSwitches Lib "Tango_dll.dll" (ByRef plFlags As Integer) As Integer
    Declare Function LS_GetSerialNr Lib "Tango_dll.dll" (ByVal pcSerialNr As String, ByVal lMaxLen As Integer) As Integer
    Declare Function LS_SetCalibOffset Lib "Tango_dll.dll" (ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dR As Double) As Integer
    Declare Function LS_SetRMOffset Lib "Tango_dll.dll" (ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dR As Double) As Integer
    Declare Function LS_GetSnapshotPosArray Lib "Tango_dll.dll" (ByVal lIndex As Integer, ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdR As Double) As Integer
    Declare Function LS_SetAxisDirection Lib "Tango_dll.dll" (ByVal lXD As Integer, ByVal lYD As Integer, ByVal lZD As Integer, ByVal lAD As Integer) As Integer
    Declare Function LS_SetCalibrateDir Lib "Tango_dll.dll" (ByVal lXD As Integer, ByVal lYD As Integer, ByVal lZD As Integer, ByVal lAD As Integer) As Integer
    Declare Function LS_LStepSave Lib "Tango_dll.dll" () As Integer
    Declare Function LS_SetBPZ Lib "Tango_dll.dll" (ByVal lAValue As Integer) As Integer
    Declare Function LS_SetBPZTrackballFactor Lib "Tango_dll.dll" (ByVal dAValue As Double) As Integer
    Declare Function LS_SetBPZTrackballBackLash Lib "Tango_dll.dll" (ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dR As Double) As Integer
    Declare Function LS_SetBPZJoyspeed Lib "Tango_dll.dll" (ByVal lAPar As Integer, ByVal dAValue As Double) As Integer
    Declare Function LS_SetJoystickWindow Lib "Tango_dll.dll" (ByVal lAValue As Integer) As Integer
    Declare Function LS_SetCurrentDelay Lib "Tango_dll.dll" (ByVal lX As Integer, ByVal lY As Integer, ByVal lZ As Integer, ByVal lR As Integer) As Integer
    Declare Function LS_MoveEx Lib "Tango_dll.dll" (ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dR As Double, ByVal bRelative As Integer, ByVal bWait As Integer, ByVal lAxisCount As Integer) As Integer
    Declare Function LS_WaitForAxisStop Lib "Tango_dll.dll" (ByVal lAFlags As Integer, ByVal lATimeoutValue As Integer, ByRef pbATimeout As Integer) As Integer
    Declare Function LS_SetProcessMessagesProc Lib "Tango_dll.dll" (ByVal Proc As Object) As Integer
    Declare Function LS_SendStringPosCmd Lib "Tango_dll.dll" (ByVal pcStr As String, ByVal pcRet As String, ByVal lMaxLen As Integer, ByVal bReadLine As Integer, ByVal lTimeOut As Integer) As Integer
    Declare Function LS_SetDigitalOutputs Lib "Tango_dll.dll" (ByVal lValue As Integer) As Integer
    Declare Function LS_SetWriteLogTextFN Lib "Tango_dll.dll" (ByVal bAWriteLogText As Integer, ByVal pcALogFN As String) As Integer
    Declare Function LS_SetDigitalOutputsE Lib "Tango_dll.dll" (ByVal lValue As Integer) As Integer
    Declare Function LS_GetDigitalInputsE Lib "Tango_dll.dll" (ByRef plValue As Integer) As Integer
    Declare Function LS_EnableCommandRetry Lib "Tango_dll.dll" (ByVal bAValue As Integer) As Integer
    Declare Function LS_SetXYAxisComp Lib "Tango_dll.dll" (ByVal lValue As Integer) As Integer
    Declare Function LS_GetVersionStrDet Lib "Tango_dll.dll" (ByVal pcVersDet As String, ByVal lMaxLen As Integer) As Integer
    Declare Function LS_SetCommandTimeout Lib "Tango_dll.dll" (ByVal lAtoRead As Integer, ByVal lAtoMove As Integer, ByVal lAtoCalibrate As Integer) As Integer
    Declare Function LS_SetExtValue Lib "Tango_dll.dll" (ByVal lAName As Integer, ByVal lAValue As Integer) As Integer
    Declare Function LS_FlushBuffer Lib "Tango_dll.dll" (ByVal lAValue As Integer) As Integer
    Declare Function LS_GetEEPRomValue Lib "Tango_dll.dll" (ByVal Offset As Object, ByRef pValue As Object) As Integer
    Declare Function LS_SetEEPRomValue Lib "Tango_dll.dll" (ByVal Offset As Object, ByVal Value As Object) As Integer
    Declare Function LS_GetXYAxisComp Lib "Tango_dll.dll" (ByRef plValue As Integer) As Integer
    Declare Function LS_GetDimensions Lib "Tango_dll.dll" (ByRef plXD As Integer, ByRef plYD As Integer, ByRef plZD As Integer, ByRef plAD As Integer) As Integer
    Declare Function LS_GetPitch Lib "Tango_dll.dll" (ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdA As Double) As Integer
    Declare Function LS_GetGear Lib "Tango_dll.dll" (ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdA As Double) As Integer
    Declare Function LS_GetVel Lib "Tango_dll.dll" (ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdA As Double) As Integer
    Declare Function LS_GetAccel Lib "Tango_dll.dll" (ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdA As Double) As Integer
    Declare Function LS_SetVelFac Lib "Tango_dll.dll" (ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dR As Double) As Integer
    Declare Function LS_GetVelFac Lib "Tango_dll.dll" (ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdR As Double) As Integer
    Declare Function LS_GetSpeedPoti Lib "Tango_dll.dll" (ByRef pbSpePoti As Integer) As Integer
    Declare Function LS_GetMotorCurrent Lib "Tango_dll.dll" (ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdA As Double) As Integer
    Declare Function LS_GetReduction Lib "Tango_dll.dll" (ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdA As Double) As Integer
    Declare Function LS_GetCurrentDelay Lib "Tango_dll.dll" (ByRef plX As Integer, ByRef plY As Integer, ByRef plZ As Integer, ByRef plR As Integer) As Integer
    Declare Function LS_SetOutFuncLev Lib "Tango_dll.dll" (ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dR As Double) As Integer
    Declare Function LS_GetOutFuncLev Lib "Tango_dll.dll" (ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdR As Double) As Integer
    Declare Function LS_GetActiveAxes Lib "Tango_dll.dll" (ByRef plFlags As Integer) As Integer
    Declare Function LS_GetAxisDirection Lib "Tango_dll.dll" (ByRef plXD As Integer, ByRef plYD As Integer, ByRef plZD As Integer, ByRef plAD As Integer) As Integer
    Declare Function LS_GetCalibOffset Lib "Tango_dll.dll" (ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdR As Double) As Integer
    Declare Function LS_GetRMOffset Lib "Tango_dll.dll" (ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdR As Double) As Integer
    Declare Function LS_GetCalibrateDir Lib "Tango_dll.dll" (ByRef plXD As Integer, ByRef plYD As Integer, ByRef plZD As Integer, ByRef plAD As Integer) As Integer
    Declare Function LS_SetCalibBackSpeed Lib "Tango_dll.dll" (ByVal lSpeed As Integer) As Integer
    Declare Function LS_GetCalibBackSpeed Lib "Tango_dll.dll" (ByRef plSpeed As Integer) As Integer
    Declare Function LS_SetRefSpeed Lib "Tango_dll.dll" (ByVal lSpeed As Integer) As Integer
    Declare Function LS_GetRefSpeed Lib "Tango_dll.dll" (ByRef plSpeed As Integer) As Integer
    Declare Function LS_SetPowerAmplifier Lib "Tango_dll.dll" (ByVal bAmplifier As Integer) As Integer
    Declare Function LS_GetPowerAmplifier Lib "Tango_dll.dll" (ByRef pbAmplifier As Integer) As Integer
    Declare Function LS_SetMotorTablePatch Lib "Tango_dll.dll" (ByVal bActive As Integer) As Integer
    Declare Function LS_GetMotorTablePatch Lib "Tango_dll.dll" (ByRef pbActive As Integer) As Integer
    Declare Function LS_SetJoystickFilter Lib "Tango_dll.dll" (ByVal bActive As Integer) As Integer
    Declare Function LS_GetJoystickFilter Lib "Tango_dll.dll" (ByRef pbActive As Integer) As Integer
    Declare Function LS_SetStopPolarity Lib "Tango_dll.dll" (ByVal bHighActiv As Integer) As Integer
    Declare Function LS_GetStopPolarity Lib "Tango_dll.dll" (ByRef pbHighActiv As Integer) As Integer
    Declare Function LS_SetVLevel Lib "Tango_dll.dll" (ByVal lVRegion As Integer, ByVal dDownLevel As Double, ByVal dUppLevel As Double) As Integer
    Declare Function LS_GetVLevel Lib "Tango_dll.dll" (ByVal lVRegion As Integer, ByRef pdDownLevel As Double, ByRef pdUppLevel As Double) As Integer
    Declare Function LS_SetStopAccel Lib "Tango_dll.dll" (ByVal dXD As Double, ByVal dYD As Double, ByVal dZD As Double, ByVal dAD As Double) As Integer
    Declare Function LS_GetStopAccel Lib "Tango_dll.dll" (ByRef pdXD As Double, ByRef pdYD As Double, ByRef pdZD As Double, ByRef pdAD As Double) As Integer
    Declare Function LS_GetVersionStrInfo Lib "Tango_dll.dll" (ByVal pcVersInfo As String, ByVal lMaxLen As Integer) As Integer
    Declare Function LS_GetStatusLimit Lib "Tango_dll.dll" (ByVal pcLimit As String, ByVal lMaxLen As Integer) As Integer
    Declare Function LS_GetSecurityErr Lib "Tango_dll.dll" (ByRef pValue As Object) As Integer
    Declare Function LS_GetSecurityStatus Lib "Tango_dll.dll" (ByRef pValue As Object) As Integer
    Declare Function LS_GetDelay Lib "Tango_dll.dll" (ByRef plDelay As Integer) As Integer
    Declare Function LS_GetDistance Lib "Tango_dll.dll" (ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdR As Double) As Integer
    Declare Function LS_ClearPos Lib "Tango_dll.dll" (ByVal lFlags As Integer) As Integer
    Declare Function LS_SetDigJoySpeed Lib "Tango_dll.dll" (ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dR As Double) As Integer
    Declare Function LS_GetDigJoySpeed Lib "Tango_dll.dll" (ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdR As Double) As Integer
    Declare Function LS_GetJoystickDir Lib "Tango_dll.dll" (ByRef plXD As Integer, ByRef plYD As Integer, ByRef plZD As Integer, ByRef plRD As Integer) As Integer
    Declare Function LS_GetJoystick Lib "Tango_dll.dll" (ByRef pbJoystickOn As Integer, ByRef pbManual As Integer, ByRef pbPositionCount As Integer, ByRef pbEncoder As Integer) As Integer
    Declare Function LS_GetJoystickWindow Lib "Tango_dll.dll" (ByRef plAValue As Integer) As Integer
    Declare Function LS_GetHandWheel Lib "Tango_dll.dll" (ByRef pbHandWheelOn As Integer, ByRef pbPositionCount As Integer, ByRef pbEncoder As Integer) As Integer
    Declare Function LS_GetBPZ Lib "Tango_dll.dll" (ByRef plAValue As Integer) As Integer
    Declare Function LS_GetBPZTrackballFactor Lib "Tango_dll.dll" (ByRef pdAValue As Double) As Integer
    Declare Function LS_GetBPZTrackballBackLash Lib "Tango_dll.dll" (ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdR As Double) As Integer
    Declare Function LS_GetBPZJoyspeed Lib "Tango_dll.dll" (ByVal lAPar As Integer, ByRef pdAValue As Double) As Integer
    Declare Function LS_GetLimitControl Lib "Tango_dll.dll" (ByVal lAxis As Integer, ByRef pbActive As Integer) As Integer
    Declare Function LS_SetAutoLimitAfterCalibRM Lib "Tango_dll.dll" (ByVal lFlags As Integer) As Integer
    Declare Function LS_GetAutoLimitAfterCalibRM Lib "Tango_dll.dll" (ByRef plFlags As Integer) As Integer
    Declare Function LS_GetSwitchPolarity Lib "Tango_dll.dll" (ByRef plXP As Integer, ByRef plYP As Integer, ByRef plZP As Integer, ByRef plRP As Integer) As Integer
    Declare Function LS_GetSwitchActive Lib "Tango_dll.dll" (ByRef plXA As Integer, ByRef plYA As Integer, ByRef plZA As Integer, ByRef plRA As Integer) As Integer
    Declare Function LS_GetTVRMode Lib "Tango_dll.dll" (ByRef plXT As Integer, ByRef plYT As Integer, ByRef plZT As Integer, ByRef plRT As Integer) As Integer
    Declare Function LS_GetFactorTVR Lib "Tango_dll.dll" (ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdR As Double) As Integer
    Declare Function LS_SetTVROutMode Lib "Tango_dll.dll" (ByVal lXT As Integer, ByVal lYT As Integer, ByVal lZT As Integer, ByVal lRT As Integer) As Integer
    Declare Function LS_GetTVROutMode Lib "Tango_dll.dll" (ByRef plXT As Integer, ByRef plYT As Integer, ByRef plZT As Integer, ByRef plRT As Integer) As Integer
    Declare Function LS_SetTVROutResolution Lib "Tango_dll.dll" (ByVal lX As Integer, ByVal lY As Integer, ByVal lZ As Integer, ByVal lR As Integer) As Integer
    Declare Function LS_GetTVROutResolution Lib "Tango_dll.dll" (ByRef plX As Integer, ByRef plY As Integer, ByRef plZ As Integer, ByRef plR As Integer) As Integer
    Declare Function LS_SetTVROutPitch Lib "Tango_dll.dll" (ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dR As Double) As Integer
    Declare Function LS_GetTVROutPitch Lib "Tango_dll.dll" (ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdR As Double) As Integer
    Declare Function LS_SetVelTVRO Lib "Tango_dll.dll" (ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dR As Double) As Integer
    Declare Function LS_GetVelTVRO Lib "Tango_dll.dll" (ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdR As Double) As Integer
    Declare Function LS_SetAccelTVRO Lib "Tango_dll.dll" (ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dR As Double) As Integer
    Declare Function LS_GetAccelTVRO Lib "Tango_dll.dll" (ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdR As Double) As Integer
    Declare Function LS_SetVelSingleAxisTVRO Lib "Tango_dll.dll" (ByVal lAxis As Integer, ByVal dVel As Double) As Integer
    Declare Function LS_SetAccelSingleAxisTVRO Lib "Tango_dll.dll" (ByVal lAxis As Integer, ByVal dAccel As Double) As Integer
    Declare Function LS_SetPosTVRO Lib "Tango_dll.dll" (ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dR As Double) As Integer
    Declare Function LS_GetPosTVRO Lib "Tango_dll.dll" (ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdR As Double) As Integer
    Declare Function LS_MoveAbsTVRO Lib "Tango_dll.dll" (ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dR As Double, ByVal bWait As Integer) As Integer
    Declare Function LS_MoveRelTVRO Lib "Tango_dll.dll" (ByVal dX As Double, ByVal dY As Double, ByVal dZ As Double, ByVal dR As Double, ByVal bWait As Integer) As Integer
    Declare Function LS_MoveRelTVROSingleAxis Lib "Tango_dll.dll" (ByVal lAxis As Integer, ByVal dValue As Double, ByVal bWait As Integer) As Integer
    Declare Function LS_MoveAbsTVROSingleAxis Lib "Tango_dll.dll" (ByVal lAxis As Integer, ByVal dValue As Double, ByVal bWait As Integer) As Integer
    Declare Function LS_GetStatusTVRO Lib "Tango_dll.dll" (ByVal pcStat As String, ByVal lMaxLen As Integer) As Integer
    Declare Function LS_GetTargetWindow Lib "Tango_dll.dll" (ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdR As Double) As Integer
    Declare Function LS_GetEncoderPeriod Lib "Tango_dll.dll" (ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdR As Double) As Integer
    Declare Function LS_GetEncoderRefSignal Lib "Tango_dll.dll" (ByRef plXR As Integer, ByRef plYR As Integer, ByRef plZR As Integer, ByRef plRR As Integer) As Integer
    Declare Function LS_GetEncoderPosition Lib "Tango_dll.dll" (ByRef pbValue As Integer) As Integer
    Declare Function LS_GetEncoderActive Lib "Tango_dll.dll" (ByRef plFlags As Integer) As Integer
    Declare Function LS_GetController Lib "Tango_dll.dll" (ByRef plXC As Integer, ByRef plYC As Integer, ByRef plZC As Integer, ByRef plRC As Integer) As Integer
    Declare Function LS_GetControllerCall Lib "Tango_dll.dll" (ByRef plCtrCall As Integer) As Integer
    Declare Function LS_GetControllerSteps Lib "Tango_dll.dll" (ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdR As Double) As Integer
    Declare Function LS_GetControllerFactor Lib "Tango_dll.dll" (ByRef pdX As Double, ByRef pdY As Double, ByRef pdZ As Double, ByRef pdR As Double) As Integer
    Declare Function LS_GetControllerTWDelay Lib "Tango_dll.dll" (ByRef plCtrTWDelay As Integer) As Integer
    Declare Function LS_GetControllerTimeout Lib "Tango_dll.dll" (ByRef plACtrTimeout As Integer) As Integer
    Declare Function LS_SetCtrFastMoveOn Lib "Tango_dll.dll" () As Integer
    Declare Function LS_SetCtrFastMoveOff Lib "Tango_dll.dll" () As Integer
    Declare Function LS_GetCtrFastMove Lib "Tango_dll.dll" (ByRef pbActive As Integer) As Integer
    Declare Function LS_ClearCtrFastMoveCounter Lib "Tango_dll.dll" () As Integer
    Declare Function LS_GetCtrFastMoveCounter Lib "Tango_dll.dll" (ByRef plXC As Integer, ByRef plYC As Integer, ByRef plZC As Integer, ByRef plRC As Integer) As Integer
    Declare Function LS_ClearEncoder Lib "Tango_dll.dll" (ByVal lAxis As Integer) As Integer
    Declare Function LS_GetEncoder Lib "Tango_dll.dll" (ByRef pdXP As Double, ByRef pdYP As Double, ByRef pdZP As Double, ByRef pdRP As Double) As Integer
    Declare Function LS_GetTrigger Lib "Tango_dll.dll" (ByRef pbATrigger As Integer) As Integer
    Declare Function LS_GetTriggerPar Lib "Tango_dll.dll" (ByRef plAxis As Integer, ByRef plMode As Integer, ByRef plSignal As Integer, ByRef pdDistance As Double) As Integer
    Declare Function LS_SetTrigCount Lib "Tango_dll.dll" (ByVal lValue As Integer) As Integer
    Declare Function LS_GetTrigCount Lib "Tango_dll.dll" (ByRef plValue As Integer) As Integer
    Declare Function LS_SetTVRInPulse Lib "Tango_dll.dll" (ByVal lAxis As Integer, ByVal bDirection As Integer) As Integer
    Declare Function LS_GetSnapshot Lib "Tango_dll.dll" (ByRef pbASnapshot As Integer) As Integer
    Declare Function LS_SetSnapshotFilter Lib "Tango_dll.dll" (ByVal lTime As Integer) As Integer
    Declare Function LS_GetSnapshotFilter Lib "Tango_dll.dll" (ByRef plTime As Integer) As Integer
    Declare Function LS_GetSnapshotPar Lib "Tango_dll.dll" (ByRef pbHigh As Integer, ByRef pbAutoMode As Integer) As Integer
    Declare Function LS_GetLimit Lib "Tango_dll.dll" (ByVal lAxis As Integer, ByRef pdMinRange As Double, ByRef pdMaxRange As Double) As Integer
    Declare Function LS_JoyChangeAxis Lib "Tango_dll.dll" (ByVal bValue As Integer) As Integer
    Declare Function LS_GetJoyChangeAxis Lib "Tango_dll.dll" (ByRef pbValue As Integer) As Integer
End Module
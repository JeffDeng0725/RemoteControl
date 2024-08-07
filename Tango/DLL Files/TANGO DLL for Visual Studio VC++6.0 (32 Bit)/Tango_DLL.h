// Tango_DLL.h : Haupt-Header-Datei für die DLL TANGO_DLL
//

#if !defined(AFX_TANGO_DLL_H__9C482D72_9083_4B59_835F_8120FA8DFE16__INCLUDED_)
#define AFX_TANGO_DLL_H__9C482D72_9083_4B59_835F_8120FA8DFE16__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// Hauptsymbole


/////////////////////////////////////////////////////////////////////////////
// CTango_DLLApp
// Siehe Tango_DLL.cpp für die Implementierung dieser Klasse
//

class CTango_DLLApp : public CWinApp
{
public:
	CTango_DLLApp();

// Überladungen
	// Vom Klassenassistenten generierte Überladungen virtueller Funktionen
	//{{AFX_VIRTUAL(CTango_DLLApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CTango_DLLApp)
		// HINWEIS - An dieser Stelle werden Member-Funktionen vom Klassen-Assistenten eingefügt und entfernt.
		//    Innerhalb dieser generierten Quelltextabschnitte NICHTS VERÄNDERN!
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.



#define TANGO_API __declspec(dllexport) int __stdcall




#ifdef __cplusplus
// use "C"-style names
extern "C" {
#endif


#pragma pack(1)
struct TLS_ControlInitPar
{
  int  Size;
  int  InterfaceType;
  char ComNameLength;
  char ComName[32];
  BOOL ShowProt;
  BOOL ShowCmdList;
  int  BaudRate;
  int  IOAdress;
  int  CardIndex;

  int  ControlType;
  char VersionStrLength;
  char VersionStr[64];
  int  Axes;
  int  ErrorCode;
  BOOL NewCmds;
  int  Encoder;
  BOOL Display, SpeedPoti, HandWheel, Snapshot, TVR, TriggerOut;
  BOOL DemoMode;
};



TANGO_API LSX_CreateLSID(int *plLSID);
TANGO_API LSX_FreeLSID(int lLSID);
TANGO_API LSX_Connect(int lLSID);
TANGO_API LSX_ConnectSimple(int lLSID, int lAnInterfaceType, char *pcAComName, int lABaudRate, int lAShowProt);
TANGO_API LSX_ConnectEx (int lLSID, TLS_ControlInitPar *pAControlInitPar);
TANGO_API LSX_Disconnect (int lLSID);


TANGO_API LSX_GetDLLVersionString (int lLSID, char *pcVers, int lMaxLen);
TANGO_API LSX_LoadConfig (int lLSID, char *pcFileName);
TANGO_API LSX_SaveConfig (int lLSID, char *pcFileName);
TANGO_API LSX_ReadControlPars (int lLSID);
TANGO_API LSX_SetCtrlPars (int lLSID);
TANGO_API LSX_GetStageSN (int lLSID, char *pcSN, int lMaxLen);
TANGO_API LSX_IsVel (int lLSID, double *pdX, double *pdY, double *pdZ, double *pdA);
TANGO_API LSX_IsVelSingleAxis (int lLSID, int lAxis, double *pdVel);
TANGO_API LSX_MoveAbs (int lLSID, double dX, double dY, double dZ, double dA, BOOL bWait);
TANGO_API LSX_MoveRel (int lLSID, double dX, double dY, double dZ, double dA, BOOL bWait);
TANGO_API LSX_Go (int lLSID, double dX, double dY, double dZ, double dA);
TANGO_API LSX_GoSingleAxis (int lLSID, int lAxis, double dValue);
TANGO_API LSX_GoEx (int lLSID, double dX, double dY, double dZ, double dA, int lAxisCount);
TANGO_API LSX_Calibrate (int lLSID);
TANGO_API LSX_RMeasure (int lLSID);
TANGO_API LSX_SetPitch (int lLSID, double dX, double dY, double dZ, double dA);
TANGO_API LSX_SetPos (int lLSID, double dX, double dY, double dZ, double dA);
TANGO_API LSX_SetActiveAxes (int lLSID, int lFlags);
TANGO_API LSX_SetVel (int lLSID, double dX, double dY, double dZ, double dA);
TANGO_API LSX_SetSecVel (int lLSID, double dX, double dY, double dZ, double dA);
TANGO_API LSX_SetAccel (int lLSID, double dX, double dY, double dZ, double dA);
TANGO_API LSX_SetReduction (int lLSID, double dX, double dY, double dZ, double dA);
TANGO_API LSX_SetDelay (int lLSID, int lDelay);
TANGO_API LSX_SetSwitchPolarity (int lLSID, int lXP, int lYP, int lZP, int lAP);
TANGO_API LSX_SetSwitchActive (int lLSID, int lXA, int lYA, int lZA, int lAA);
TANGO_API LSX_SetJoystickOn (int lLSID, BOOL bPositionCount, BOOL bEncoder);
TANGO_API LSX_SetJoystickOff (int lLSID);
TANGO_API LSX_SoftwareReset (int lLSID);
TANGO_API LSX_ClearProtocolWindow (int lLSID);
TANGO_API LSX_SetAuxDigitalOutput (int lLSID, int lIndex, BOOL bValue);
TANGO_API LSX_GetAuxDigitalInput (int lLSID, int lIndex, BOOL *bValue);
TANGO_API LSX_SetDigitalOutput (int lLSID, int lIndex, BOOL bValue);
TANGO_API LSX_SetDigitalOutputs (int lLSID, int lValue);
TANGO_API LSX_GetDigitalInputs (int lLSID, int *plValue);
TANGO_API LSX_SetDigitalOutputE (int lLSID, int lIndex, BOOL bValue);
TANGO_API LSX_SetDigitalOutputsE (int lLSID, int lValue);
TANGO_API LSX_GetDigitalInputsE (int lLSID, int *plValue);
TANGO_API LSX_SetAnalogOutput (int lLSID, int lIndex, int lValue);
TANGO_API LSX_SetAnalogOutputMode(int lLSID, int lValue);
TANGO_API LSX_GetAnalogOutputMode(int lLSID, int *plValue);
TANGO_API LSX_SetLedBright (int lLSID, double dBright);
TANGO_API LSX_GetAnalogInput (int lLSID, int lIndex, int *plValue);
TANGO_API LSX_GetHdiKeys (int lLSID, int *plKey1, int *plKey2, int *plKey3, int *plKey4);
TANGO_API LSX_GetSmHdiButton (int lLSID, int lButtonNr, char *pcFunction, int lMaxLen);
TANGO_API LSX_SetSmHdiButton (int lLSID, int lButtonNr, char *pcFunction);
TANGO_API LSX_SetHdiSpeedIndex (int lLSID, int lX, int lY, int lZ, int lA);
TANGO_API LSX_GetHdiSpeedIndex (int lLSID, int *plX, int *plY, int *plZ, int *plA);
TANGO_API LSX_SetHdiSpeedIndexSingleAxis (int lLSID, int lAxis, int lIndex);
TANGO_API LSX_GetHdiSpeedIndexSingleAxis (int lLSID, int lAxis, int *plIndex);
TANGO_API LSX_SetHwFactor (int lLSID, double dX, double dY, double dZ, double dA);
TANGO_API LSX_SetHwFactorB (int lLSID, double dX, double dY, double dZ, double dA);
TANGO_API LSX_GetHwFactor (int lLSID, double *pdX, double *pdY, double *pdZ, double *pdA);
TANGO_API LSX_GetHwFactorB (int lLSID, double *pdX, double *pdY, double *pdZ, double *pdA);
TANGO_API LSX_SetHwFactorSingleAxis (int lLSID, int lAxis, double dFactor);
TANGO_API LSX_SetHwFactorBSingleAxis (int lLSID, int lAxis, double dFactorB);
TANGO_API LSX_GetHwFactorSingleAxis (int lLSID, int lAxis, double *pdFactor);
TANGO_API LSX_GetHwFactorBSingleAxis (int lLSID, int lAxis, double *pdFactorB);
TANGO_API LSX_SetLimit (int lLSID, int lAxis, double dMinRange, double dMaxRange);
TANGO_API LSX_SetLimitControl (int lLSID, int lAxis, BOOL bActive);
TANGO_API LSX_GetPos (int lLSID, double *pdX, double *pdY, double *pdZ, double *pdA);
TANGO_API LSX_GetStatus (int lLSID, char *pcStat, int lMaxLen);
TANGO_API LSX_GetEncoderMask (int lLSID, int *plFlags);
TANGO_API LSX_StopAxes (int lLSID);
TANGO_API LSX_StopAxesEx (int lLSID, int lFlags);
TANGO_API LSX_SetAbortFlag (int lLSID);
TANGO_API LSX_MoveRelSingleAxis (int lLSID, int lAxis, double dValue, BOOL bWait);
TANGO_API LSX_MoveAbsSingleAxis (int lLSID, int lAxis, double dValue, BOOL bWait);
TANGO_API LSX_SetControlPars (int lLSID);
TANGO_API LSX_SetMotorCurrent (int lLSID, double dX, double dY, double dZ, double dA);
TANGO_API LSX_SetVelSingleAxis (int lLSID, int lAxis, double dVel);
TANGO_API LSX_SetSecVelSingleAxis (int lLSID, int lAxis, double dVel);
TANGO_API LSX_SetAccelSingleAxis (int lLSID, int lAxis, double dAccel);
TANGO_API LSX_CalibrateEx (int lLSID, int lFlags);
TANGO_API LSX_RMeasureEx (int lLSID, int lFlags);
TANGO_API LSX_SetShowProt (int lLSID, int lShowProt);
TANGO_API LSX_GetAnalogInputs2 (int lLSID, int *plPT100, int *plMV, int *plV24);
TANGO_API LSX_SendString (int lLSID, char *pcStr, char *pcRet, int lMaxLen, BOOL bReadLine, int lTimeOut);
TANGO_API LSX_SetSpeedPoti (int lLSID, BOOL bSpeedPoti);
TANGO_API LSX_SetTVRMode (int lLSID, int lXT, int lYT, int lZT, int lAT);
TANGO_API LSX_SetAutoStatus (int lLSID, int lValue);
TANGO_API LSX_GetAutoStatus(int lLSID, int *plValue);
TANGO_API LSX_GetStatusAxis (int lLSID, char *pcStatusAxisStr, int lMaxLen);
TANGO_API LSX_GetStA(int lLSID, int *plStaX, int *plStaY, int *plStaZ, int *plStaA);
TANGO_API LSX_SetDigIO_Off (int lLSID, int lIndex);
TANGO_API LSX_SetDigIO_Polarity (int lLSID, int lIndex, BOOL bHigh);
TANGO_API LSX_SetDigIO_EmergencyStop (int lLSID, int lIndex);
TANGO_API LSX_SetDigIO_Distance (int lLSID, int lIndex, BOOL bFkt, double dDist, int lAxis);
TANGO_API LSX_SetDimensions (int lLSID, int lXD, int lYD, int lZD, int lAD);
TANGO_API LSX_SetResolution (int lLSID, int lValue);
TANGO_API LSX_MoveRelShort (int lLSID);
TANGO_API LSX_SetEncoderPeriod (int lLSID, double dX, double dY, double dZ, double dA);
TANGO_API LSX_SetJoystickDir (int lLSID, int lXD, int lYD, int lZD, int lAD);
TANGO_API LSX_SetEncoderMask (int lLSID, int lValue);
TANGO_API LSX_SetGear (int lLSID, double dX, double dY, double dZ, double dA);
TANGO_API LSX_SetHandWheelOn (int lLSID, BOOL bPositionCount, BOOL bEncoder);
TANGO_API LSX_SetHandWheelOff (int lLSID);
TANGO_API LSX_SetFactorTVR (int lLSID, double dX, double dY, double dZ, double dA);
TANGO_API LSX_SetTargetWindow (int lLSID, double dX, double dY, double dZ, double dA);
TANGO_API LSX_SetController (int lLSID, int lXC, int lYC, int lZC, int lAC);
TANGO_API LSX_SetControllerCall (int lLSID, int lCtrCall);
TANGO_API LSX_SetControllerSteps (int lLSID, double dX, double dY, double dZ, double dA);
TANGO_API LSX_SetControllerFactor (int lLSID, double dX, double dY, double dZ, double dA);
TANGO_API LSX_SetControllerFactorSingleAxis(int lLSID, int lAxis, double dFactor1, double dFactor2);
TANGO_API LSX_SetControllerTWDelay(int lLSID, int lCtrTWDelay);
TANGO_API LSX_SetControllerTWDelaySingleAxis(int lLSID, int lAxis, int lCtrTWDelay);
TANGO_API LSX_SetEncoderRefSignal (int lLSID, int lXR, int lYR, int lZR, int lAR);
TANGO_API LSX_SetEncoderPosition (int lLSID, BOOL bValue);
TANGO_API LSX_GetVersionStr (int lLSID, char *pcVers, int lMaxLen);
TANGO_API LSX_GetTangoVersion (int lLSID, char *pcVers, int lMaxLen);
TANGO_API LSX_GetError (int lLSID, int *plErrorCode);
TANGO_API LSX_GetErrorString(int lLSID, int lErrorCode, char *pcErrorCode, int lMaxLen);
TANGO_API LSX_GetPosSingleAxis (int lLSID, int lAxis, double *pdPos);
TANGO_API LSX_SetDistance (int lLSID, double dX, double dY, double dZ, double dA);
TANGO_API LSX_GetPosEx (int lLSID, double *pdX, double *pdY, double *pdZ, double *pdR, BOOL bEncoder);
TANGO_API LSX_SetShowCmdList (int lLSID, BOOL bShowCmdList);
TANGO_API LSX_SetWriteLogText (int lLSID, BOOL bAWriteLogText);
TANGO_API LSX_SetControllerTimeout (int lLSID, int lACtrTimeout);
TANGO_API LSX_SetEncoderActive (int lLSID, int lFlags);
TANGO_API LSX_GetSnapshotCount (int lLSID, int *plSnsCount);
TANGO_API LSX_SetSnapshotCount (int lLSID, int lSnsCount);
TANGO_API LSX_GetSnapshotPos (int lLSID, double *pdX, double *pdY, double *pdZ, double *pdA);
TANGO_API LSX_SetCorrTblOff (int lLSID);
TANGO_API LSX_SetCorrTblOn (int lLSID, char *pcAFileName);
TANGO_API LSX_SetFactorMode (int lLSID, BOOL bAFactorMode, double dX, double dY, double dZ, double dA);
TANGO_API LSX_SetSnapshot (int lLSID, BOOL bASnapshot);
TANGO_API LSX_SetSnapshotPar (int lLSID, BOOL bHigh, BOOL bAutoMode);
TANGO_API LSX_SetTrigger (int lLSID, BOOL bATrigger);
TANGO_API LSX_SetTriggerPar (int lLSID, int lAxis, int lMode, int lSignal, double dDistance);
TANGO_API LSX_SetTrigCount (int lLSID, int lValue);
TANGO_API LSX_SetTriggerAxis (int lLSID, int lAxis);
TANGO_API LSX_SetTriggerMode (int lLSID, int lMode);
TANGO_API LSX_SetTriggerSignalLength (int lLSID, int lSignal);
TANGO_API LSX_SetTriggerDistance (int lLSID, double dDistance);
TANGO_API LSX_SetTriggerCompensation (int lLSID, int lCompensation);
TANGO_API LSX_SetTriggerEncoder (int lLSID, int lEncoder);
TANGO_API LSX_SetTriggerFrequency (int lLSID, double dFrequency);
TANGO_API LSX_SetTriggerRange (int lLSID, double dStartPos, double dEndPos, int lNumberOfTriggerPulses);
TANGO_API LSX_SetTriggerOutput (int lLSID, int lOutput);
TANGO_API LSX_SetTriggerPositionList (int lLSID, int lIndex, double dPosition);
TANGO_API LSX_SetTriggerPositionListIndex (int lLSID, int lIndex);
TANGO_API LSX_SetTriggerPositionListEntries (int lLSID, int lNumberOfEntries);
TANGO_API LSX_SetTriggerLevel (int lLSID, int lLevel);

TANGO_API LSX_Set2ndTriggerDelay (int lLSID, double dDelay);
TANGO_API LSX_Set2ndTriggerWidth (int lLSID, double dWidth);
TANGO_API LSX_Set2ndTriggerFrequency (int lLSID, double dFrequency);

TANGO_API LSX_SetLanguage (int lLSID, char *pcPLN);
TANGO_API LSX_GetSwitches (int lLSID, int *plFlags);
TANGO_API LSX_GetSerialNr (int lLSID, char *pcSerialNr, int lMaxLen);
TANGO_API LSX_SetCalibOffset (int lLSID, double dX, double dY, double dZ, double dR);
TANGO_API LSX_SetRMOffset (int lLSID, double dX, double dY, double dZ, double dR);
TANGO_API LSX_GetSnapshotPosArray (int lLSID, int lIndex, double *pdX, double *pdY, double *pdZ, double *pdR);
TANGO_API LSX_SetAxisDirection (int lLSID, int lXD, int lYD, int lZD, int lAD);
TANGO_API LSX_SetCalibrateDir (int lLSID, int lXD, int lYD, int lZD, int lAD);
TANGO_API LSX_LStepSave (int lLSID);
TANGO_API LSX_SetBPZ (int lLSID, int lAValue);
TANGO_API LSX_SetBPZTrackballFactor (int lLSID, double dAValue);
TANGO_API LSX_SetBPZTrackballBackLash (int lLSID, double dX, double dY, double dZ, double dR);
TANGO_API LSX_SetBPZJoyspeed (int lLSID, int lAPar, double dAValue);
TANGO_API LSX_SetJoystickWindow (int lLSID, int lAValue);
TANGO_API LSX_SetCurrentDelay (int lLSID, int lX, int lY, int lZ, int lR);
TANGO_API LSX_MoveEx (int lLSID, double dX, double dY, double dZ, double dR, BOOL bRelative, BOOL bWait, int lAxisCount);
TANGO_API LSX_WaitForAxisStop (int lLSID, int lAFlags, int lATimeoutValue, BOOL *pbATimeout);
TANGO_API LSX_SetProcessMessagesProc (int lLSID, void* pProc);
TANGO_API LSX_SendStringPosCmd (int lLSID, char *pcStr, char *pcRet, int lMaxLen, BOOL bReadLine, int lTimeOut);
TANGO_API LSX_SetWriteLogTextFN (int lLSID, BOOL bAWriteLogText, char *pcALogFN);
TANGO_API LSX_EnableCommandRetry (int lLSID, BOOL bAValue);
TANGO_API LSX_SetXYAxisComp (int lLSID, int lValue);
TANGO_API LSX_GetVersionStrDet (int lLSID, char *pcVersDet, int lMaxLen);
TANGO_API LSX_SetDllNumOfAxes (int lLSID, int lNumOfAxes);
TANGO_API LSX_SetCommandTimeout (int lLSID, int lAtoRead, int lAtoMove, int lAtoCalibrate);
TANGO_API LSX_GetCommandTimeout (int lLSID, int *plAtoRead, int *plAtoMove, int *plAtoCalibrate);
TANGO_API LSX_SetExtValue (int lLSID, int lAName, int lAValue);
TANGO_API LSX_FlushBuffer (int lLSID, int lAValue);
TANGO_API LSX_GetEEPRomValue (int lLSID, byte Offset, byte *pValue);
TANGO_API LSX_SetEEPRomValue (int lLSID, byte Offset, byte Value);
TANGO_API LSX_GetXYAxisComp (int lLSID, int *plValue);
TANGO_API LSX_GetDimensions (int lLSID, int *plXD, int *plYD, int *plZD, int *plAD);
TANGO_API LSX_GetResolution (int lLSID, int *plValue);
TANGO_API LSX_GetPitch (int lLSID, double *pdX, double *pdY, double *pdZ, double *pdA);
TANGO_API LSX_GetGear (int lLSID, double *pdX, double *pdY, double *pdZ, double *pdA);
TANGO_API LSX_GetVel (int lLSID, double *pdX, double *pdY, double *pdZ, double *pdA);
TANGO_API LSX_GetSecVel (int lLSID, double *pdX, double *pdY, double *pdZ, double *pdA);
TANGO_API LSX_GetAccel (int lLSID, double *pdX, double *pdY, double *pdZ, double *pdA);
TANGO_API LSX_SetVelFac (int lLSID, double dX, double dY, double dZ, double dR);
TANGO_API LSX_GetVelFac (int lLSID, double *pdX, double *pdY, double *pdZ, double *pdR);
TANGO_API LSX_GetSpeedPoti (int lLSID, BOOL *pbSpePoti);
TANGO_API LSX_GetMotorCurrent (int lLSID, double *pdX, double *pdY, double *pdZ, double *pdA);
TANGO_API LSX_GetReduction (int lLSID, double *pdX, double *pdY, double *pdZ, double *pdA);
TANGO_API LSX_GetCurrentDelay (int lLSID, int *plX, int *plY, int *plZ, int *plR);
TANGO_API LSX_SetOutFuncLev (int lLSID, double dX, double dY, double dZ, double dR);
TANGO_API LSX_GetOutFuncLev (int lLSID, double *pdX, double *pdY, double *pdZ, double *pdR);
TANGO_API LSX_GetActiveAxes (int lLSID, int *plFlags);
TANGO_API LSX_GetAxisDirection (int lLSID, int *plXD, int *plYD, int *plZD, int *plAD);
TANGO_API LSX_GetCalibOffset (int lLSID, double *pdX, double *pdY, double *pdZ, double *pdR);
TANGO_API LSX_GetRMOffset (int lLSID, double *pdX, double *pdY, double *pdZ, double *pdR);
TANGO_API LSX_GetCalibrateDir (int lLSID, int *plXD, int *plYD, int *plZD, int *plAD);
TANGO_API LSX_SetCalibBackSpeed (int lLSID, int lSpeed);
TANGO_API LSX_GetCalibBackSpeed (int lLSID, int *plSpeed);
TANGO_API LSX_SetRefSpeed (int lLSID, int lSpeed);
TANGO_API LSX_GetRefSpeed (int lLSID, int *plSpeed);
TANGO_API LSX_SetPowerAmplifier (int lLSID, BOOL bAmplifier);
TANGO_API LSX_GetPowerAmplifier (int lLSID, BOOL *pbAmplifier);
TANGO_API LSX_SetMotorTablePatch (int lLSID, BOOL bActive);
TANGO_API LSX_GetMotorTablePatch (int lLSID, BOOL *pbActive);
TANGO_API LSX_SetJoystickFilter (int lLSID, BOOL bActive);
TANGO_API LSX_GetJoystickFilter (int lLSID, BOOL *pbActive);
TANGO_API LSX_SetStopPolarity (int lLSID, BOOL bHighActiv);
TANGO_API LSX_GetStopPolarity (int lLSID, BOOL *pbHighActiv);
TANGO_API LSX_SetStop (int lLSID, BOOL bActiv);
TANGO_API LSX_GetStop (int lLSID, BOOL *pbActiv);
TANGO_API LSX_SetVLevel (int lLSID, int lVRegion, double dDownLevel, double dUppLevel);
TANGO_API LSX_GetVLevel (int lLSID, int lVRegion, double *pdDownLevel, double *pdUppLevel);
TANGO_API LSX_SetStopAccel (int lLSID, double dXD, double dYD, double dZD, double dAD);
TANGO_API LSX_GetStopAccel (int lLSID, double *pdXD, double *pdYD, double *pdZD, double *pdAD);
TANGO_API LSX_GetVersionStrInfo (int lLSID, char *pcVersInfo, int lMaxLen);
TANGO_API LSX_GetStatusLimit (int lLSID, char *pcLimit, int lMaxLen);
TANGO_API LSX_GetSecurityErr (int lLSID, DWORD *pdwValue);
TANGO_API LSX_GetSecurityStatus (int lLSID, DWORD *pdwValue);
TANGO_API LSX_GetDelay (int lLSID, int *plDelay);
TANGO_API LSX_GetDistance (int lLSID, double *pdX, double *pdY, double *pdZ, double *pdR);
TANGO_API LSX_ClearPos (int lLSID, int lFlags);
TANGO_API LSX_SetDigJoySpeed (int lLSID, double dX, double dY, double dZ, double dR);
TANGO_API LSX_GetDigJoySpeed (int lLSID, double *pdX, double *pdY, double *pdZ, double *pdR);
TANGO_API LSX_GetJoystickDir (int lLSID, int *plXD, int *plYD, int *plZD, int *plRD);
TANGO_API LSX_GetJoystick (int lLSID, BOOL *pbJoystickOn, BOOL *pbManual, BOOL *pbPositionCount, BOOL *pbEncoder);
TANGO_API LSX_GetJoystickWindow (int lLSID, int *plAValue);
TANGO_API LSX_GetHandWheel (int lLSID, BOOL *pbHandWheelOn, BOOL *pbPositionCount, BOOL *pbEncoder);
TANGO_API LSX_GetBPZ (int lLSID, int *plAValue);
TANGO_API LSX_GetBPZTrackballFactor (int lLSID, double *pdAValue);
TANGO_API LSX_GetBPZTrackballBackLash (int lLSID, double *pdX, double *pdY, double *pdZ, double *pdR);
TANGO_API LSX_GetBPZJoyspeed (int lLSID, int lAPar, double *pdAValue);
TANGO_API LSX_GetLimitControl (int lLSID, int lAxis, BOOL *pbActive);
TANGO_API LSX_SetAutoLimitAfterCalibRM (int lLSID, int lFlags);
TANGO_API LSX_GetAutoLimitAfterCalibRM (int lLSID, int *plFlags);
TANGO_API LSX_GetSwitchPolarity (int lLSID, int *plXP, int *plYP, int *plZP, int *plRP);
TANGO_API LSX_GetSwitchActive (int lLSID, int *plXA, int *plYA, int *plZA, int *plRA);
TANGO_API LSX_GetTVRMode (int lLSID, int *plXT, int *plYT, int *plZT, int *plRT);
TANGO_API LSX_GetFactorTVR (int lLSID, double *pdX, double *pdY, double *pdZ, double *pdR);
TANGO_API LSX_SetTVROutMode (int lLSID, int lXT, int lYT, int lZT, int lRT);
TANGO_API LSX_GetTVROutMode (int lLSID, int *plXT, int *plYT, int *plZT, int *plRT);
TANGO_API LSX_SetTVROutResolution (int lLSID, int lX, int lY, int lZ, int lR);
TANGO_API LSX_GetTVROutResolution (int lLSID, int *plX, int *plY, int *plZ, int *plR);
TANGO_API LSX_SetTVROutPitch (int lLSID, double dX, double dY, double dZ, double dR);
TANGO_API LSX_GetTVROutPitch (int lLSID, double *pdX, double *pdY, double *pdZ, double *pdR);
TANGO_API LSX_SetVelTVRO (int lLSID, double dX, double dY, double dZ, double dR);
TANGO_API LSX_GetVelTVRO (int lLSID, double *pdX, double *pdY, double *pdZ, double *pdR);
TANGO_API LSX_SetAccelTVRO (int lLSID, double dX, double dY, double dZ, double dR);
TANGO_API LSX_GetAccelTVRO (int lLSID, double *pdX, double *pdY, double *pdZ, double *pdR);
TANGO_API LSX_SetVelSingleAxisTVRO (int lLSID, int lAxis, double dVel);
TANGO_API LSX_SetAccelSingleAxisTVRO (int lLSID, int lAxis, double dAccel);
TANGO_API LSX_SetPosTVRO (int lLSID, double dX, double dY, double dZ, double dR);
TANGO_API LSX_GetPosTVRO (int lLSID, double *pdX, double *pdY, double *pdZ, double *pdR);
TANGO_API LSX_MoveAbsTVRO (int lLSID, double dX, double dY, double dZ, double dR, BOOL bWait);
TANGO_API LSX_MoveRelTVRO (int lLSID, double dX, double dY, double dZ, double dR, BOOL bWait);
TANGO_API LSX_MoveRelTVROSingleAxis (int lLSID, int lAxis, double dValue, BOOL bWait);
TANGO_API LSX_MoveAbsTVROSingleAxis (int lLSID, int lAxis, double dValue, BOOL bWait);
TANGO_API LSX_GetStatusTVRO (int lLSID, char *pcStat, int lMaxLen);
TANGO_API LSX_GetTargetWindow (int lLSID, double *pdX, double *pdY, double *pdZ, double *pdR);
TANGO_API LSX_GetEncoderSingleAxis (int lLSID, int lAxis, int *plEncoderType, double *pdPeriod, int *plRef);
TANGO_API LSX_SetEncoderSingleAxis (int lLSID, int lAxis, int lEncoderType, double dPeriod, int lRef);
TANGO_API LSX_GetEncoderPeriod (int lLSID, double *pdX, double *pdY, double *pdZ, double *pdR);
TANGO_API LSX_GetEncoderRefSignal (int lLSID, int *plXR, int *plYR, int *plZR, int *plRR);
TANGO_API LSX_GetEncoderPosition (int lLSID, BOOL *pbValue);
TANGO_API LSX_GetEncoderActive (int lLSID, int *plFlags);
TANGO_API LSX_GetController (int lLSID, int *plXC, int *plYC, int *plZC, int *plRC);
TANGO_API LSX_GetControllerCall (int lLSID, int *plCtrCall);
TANGO_API LSX_GetControllerSteps (int lLSID, double *pdX, double *pdY, double *pdZ, double *pdR);
TANGO_API LSX_GetControllerFactor (int lLSID, double *pdX, double *pdY, double *pdZ, double *pdR);
TANGO_API LSX_GetControllerFactorSingleAxis(int lLSID, int lAxis, double *pdFactor1, double *pdFactor2);
TANGO_API LSX_GetControllerTWDelay(int lLSID, int *plCtrTWDelay);
TANGO_API LSX_GetControllerTWDelaySingleAxis(int lLSID, int lAxis, int *plCtrTWDelay);
TANGO_API LSX_GetControllerTimeout (int lLSID, int *plACtrTimeout);
TANGO_API LSX_SetCtrFastMoveOn (int lLSID);
TANGO_API LSX_SetCtrFastMoveOff (int lLSID);
TANGO_API LSX_GetCtrFastMove (int lLSID, BOOL *pbActive);
TANGO_API LSX_ClearCtrFastMoveCounter (int lLSID);
TANGO_API LSX_GetCtrFastMoveCounter (int lLSID, int *plXC, int *plYC, int *plZC, int *plRC);
TANGO_API LSX_ClearEncoder (int lLSID, int lAxis);
TANGO_API LSX_GetEncoder (int lLSID, double *pdXP, double *pdYP, double *pdZP, double *pdRP);
TANGO_API LSX_GetTrigger (int lLSID, BOOL *pbATrigger);
TANGO_API LSX_GetTriggerPar (int lLSID, int *plAxis, int *plMode, int *plSignal, double *pdDistance);
TANGO_API LSX_GetTrigCount (int lLSID, int *plValue);

TANGO_API LSX_GetTriggerAxis (int lLSID, int *plAxis);
TANGO_API LSX_GetTriggerMode (int lLSID, int *plMode);
TANGO_API LSX_GetTriggerSignalLength (int lLSID, int *plSignal);
TANGO_API LSX_GetTriggerDistance (int lLSID, double *pdDistance);
TANGO_API LSX_GetTriggerCompensation (int lLSID, int *plCompensation);
TANGO_API LSX_GetTriggerEncoder (int lLSID, int *plEncoder);
TANGO_API LSX_GetTriggerFrequency (int lLSID, double *pdFrequency);
TANGO_API LSX_GetTriggerRange (int lLSID, double *pdStartPos, double *pdEndPos, int *plNumberOfTriggerPulses);
TANGO_API LSX_GetTriggerOutput (int lLSID, int *plOutput);
TANGO_API LSX_GetTriggerPositionList (int lLSID, int lIndex, double *pdPos);
TANGO_API LSX_GetTriggerPositionListIndex (int lLSID, int *plIndex);
TANGO_API LSX_GetTriggerPositionListEntries (int lLSID, int *plNumberOfEntries);
TANGO_API LSX_GetTriggerLevel (int lLSID, int *plLevel);
TANGO_API LSX_Get2ndTriggerDelay (int lLSID, double *pdDelay);
TANGO_API LSX_Get2ndTriggerWidth (int lLSID, double *pdWidth);
TANGO_API LSX_Get2ndTriggerFrequency (int lLSID, double *pdFrequency);

TANGO_API LSX_SetTVRInPulse (int lLSID, int lAxis, BOOL bDirection);
TANGO_API LSX_GetSnapshot (int lLSID, BOOL *pbASnapshot);
TANGO_API LSX_SetSnapshotFilter (int lLSID, int lTime);
TANGO_API LSX_GetSnapshotFilter (int lLSID, int *plTime);
TANGO_API LSX_GetSnapshotPar (int lLSID, BOOL *pbHigh, BOOL *pbAutoMode);
TANGO_API LSX_GetLimit (int lLSID, int lAxis, double *pdMinRange, double *pdMaxRange);
TANGO_API LSX_JoyChangeAxis (int lLSID, BOOL bValue);
TANGO_API LSX_GetJoyChangeAxis (int lLSID, BOOL *pbValue);
TANGO_API LSX_GetSyncZA (int lLSID, BOOL *pbSyncZA);
TANGO_API LSX_SetSyncZA (int lLSID, BOOL bSync);
TANGO_API LSX_GetSwapZA (int lLSID, BOOL *pbSwapZA);
TANGO_API LSX_SetSwapZA (int lLSID, BOOL bSwap);
TANGO_API LSX_GetKey (int lLSID, BOOL *pbKey1, BOOL *pbKey2, BOOL *pbKey3, BOOL *pbKey4);
TANGO_API LSX_GetKeyLatch (int lLSID, BOOL *pbKey1, BOOL *pbKey2, BOOL *pbKey3, BOOL *pbKey4);
TANGO_API LSX_ClearKeyLatch (int lLSID, int lKey);
TANGO_API LSX_SetZwTravel (int lLSID, int lIndex, double dDistance);
TANGO_API LSX_GetZwTravel (int lLSID, int lIndex, double *pdDistance);
TANGO_API LSX_ClearSnapshotPosArray (int lLSID);
TANGO_API LSX_SetSnapshotPosArray (int lLSID, int lIndex, double dX, double dY, double dZ, double dA);
TANGO_API LSX_SetSnapshotIndex (int lLSID, int lIndex);
TANGO_API LSX_GetSnapshotIndex (int lLSID, int *plIndex);
TANGO_API LSX_SetSnapshotMode (int lLSID, int lMode);
TANGO_API LSX_GetSnapshotMode (int lLSID, int *plMode);


TANGO_API LS_Connect(void);
TANGO_API LS_ConnectSimple(int lAnInterfaceType, char *pcAComName, int lABaudRate, int lAShowProt);
TANGO_API LS_ConnectEx (TLS_ControlInitPar *pAControlInitPar);
TANGO_API LS_Disconnect (void);
TANGO_API LS_GetDLLVersionString (char *pcVers, int lMaxLen);
TANGO_API LS_LoadConfig (char *pcFileName);
TANGO_API LS_SaveConfig (char *pcFileName);
TANGO_API LS_ReadControlPars (void);
TANGO_API LS_SetCtrlPars (void);
TANGO_API LS_GetStageSN (char *pcSN, int lMaxLen);
TANGO_API LS_IsVel (double *pdX, double *pdY, double *pdZ, double *pdA);
TANGO_API LS_IsVelSingleAxis (int lAxis, double *pdVel);
TANGO_API LS_MoveAbs (double dX, double dY, double dZ, double dA, BOOL bWait);
TANGO_API LS_MoveRel (double dX, double dY, double dZ, double dA, BOOL bWait);
TANGO_API LS_Go (double dX, double dY, double dZ, double dA);
TANGO_API LS_GoSingleAxis (int lAxis, double dValue);
TANGO_API LS_GoEx (double dX, double dY, double dZ, double dA, int lAxisCount);
TANGO_API LS_Calibrate (void);
TANGO_API LS_RMeasure (void);
TANGO_API LS_SetPitch (double dX, double dY, double dZ, double dA);
TANGO_API LS_SetPos (double dX, double dY, double dZ, double dA);
TANGO_API LS_SetActiveAxes (int lFlags);
TANGO_API LS_SetVel (double dX, double dY, double dZ, double dA);
TANGO_API LS_SetSecVel (double dX, double dY, double dZ, double dA);
TANGO_API LS_SetAccel (double dX, double dY, double dZ, double dA);
TANGO_API LS_SetReduction (double dX, double dY, double dZ, double dA);
TANGO_API LS_SetDelay (int lDelay);
TANGO_API LS_SetSwitchPolarity (int lXP, int lYP, int lZP, int lAP);
TANGO_API LS_SetSwitchActive (int lXA, int lYA, int lZA, int lAA);
TANGO_API LS_SetJoystickOn (BOOL bPositionCount, BOOL bEncoder);
TANGO_API LS_SetJoystickOff (void);
TANGO_API LS_SoftwareReset (void);
TANGO_API LS_ClearProtocolWindow (void);
TANGO_API LS_SetAuxDigitalOutput (int lIndex, BOOL bValue);
TANGO_API LS_GetAuxDigitalInput (int lIndex, BOOL *bValue);
TANGO_API LS_SetDigitalOutput (int lIndex, BOOL bValue);
TANGO_API LS_SetDigitalOutputs (int lValue);
TANGO_API LS_GetDigitalInputs (int *plValue);
TANGO_API LS_SetDigitalOutputE (int lIndex, BOOL bValue);
TANGO_API LS_SetDigitalOutputsE (int lValue);
TANGO_API LS_GetDigitalInputsE (int *plValue);
TANGO_API LS_SetAnalogOutput (int lIndex, int lValue);
TANGO_API LS_SetAnalogOutputMode(int lValue);
TANGO_API LS_GetAnalogOutputMode(int *plValue);
TANGO_API LS_SetLedBright (double dBright);
TANGO_API LS_GetAnalogInput (int lIndex, int *plValue);
TANGO_API LS_GetHdiKeys (int *plKey1, int *plKey2, int *plKey3, int *plKey4);
TANGO_API LS_GetSmHdiButton (int lButtonNr, char *pcFunction, int lMaxLen);
TANGO_API LS_SetSmHdiButton (int lButtonNr, char *pcFunction);
TANGO_API LS_SetHdiSpeedIndex (int lX, int lY, int lZ, int lA);
TANGO_API LS_GetHdiSpeedIndex (int *plX, int *plY, int *plZ, int *plA);
TANGO_API LS_SetHdiSpeedIndexSingleAxis (int lAxis, int lIndex);
TANGO_API LS_GetHdiSpeedIndexSingleAxis (int lAxis, int *plIndex);
TANGO_API LS_SetHwFactor (double dX, double dY, double dZ, double dA);
TANGO_API LS_SetHwFactorB (double dX, double dY, double dZ, double dA);
TANGO_API LS_GetHwFactor (double *pdX, double *pdY, double *pdZ, double *pdA);
TANGO_API LS_GetHwFactorB (double *pdX, double *pdY, double *pdZ, double *pdA);
TANGO_API LS_SetHwFactorSingleAxis (int lAxis, double dFactor);
TANGO_API LS_SetHwFactorBSingleAxis (int lAxis, double dFactorB);
TANGO_API LS_GetHwFactorSingleAxis (int lAxis, double *pdFactor);
TANGO_API LS_GetHwFactorBSingleAxis (int lAxis, double *pdFactorB);
TANGO_API LS_SetLimit (int lAxis, double dMinRange, double dMaxRange);
TANGO_API LS_SetLimitControl (int lAxis, BOOL bActive);
TANGO_API LS_GetPos (double *pdX, double *pdY, double *pdZ, double *pdA);
TANGO_API LS_GetStatus (char *pcStat, int lMaxLen);
TANGO_API LS_GetEncoderMask (int *plFlags);
TANGO_API LS_StopAxes (void);
TANGO_API LS_StopAxesEx (int lFlags);
TANGO_API LS_SetAbortFlag (void);
TANGO_API LS_MoveRelSingleAxis (int lAxis, double dValue, BOOL bWait);
TANGO_API LS_MoveAbsSingleAxis (int lAxis, double dValue, BOOL bWait);
TANGO_API LS_SetControlPars (void);
TANGO_API LS_SetMotorCurrent (double dX, double dY, double dZ, double dA);
TANGO_API LS_SetVelSingleAxis (int lAxis, double dVel);
TANGO_API LS_SetSecVelSingleAxis (int lAxis, double dVel);
TANGO_API LS_SetAccelSingleAxis (int lAxis, double dAccel);
TANGO_API LS_CalibrateEx (int lFlags);
TANGO_API LS_RMeasureEx (int lFlags);
TANGO_API LS_SetShowProt (int lShowProt);
TANGO_API LS_GetAnalogInputs2 (int *plPT100, int *plMV, int *plV24);
TANGO_API LS_SendString (char *pcStr, char *pcRet, int lMaxLen, BOOL bReadLine, int lTimeOut);
TANGO_API LS_SetSpeedPoti (BOOL bSpeedPoti);
TANGO_API LS_SetTVRMode (int lXT, int lYT, int lZT, int lAT);
TANGO_API LS_SetAutoStatus (int lValue);
TANGO_API LS_GetAutoStatus(int *plValue);
TANGO_API LS_GetStatusAxis(char *pcStatusAxisStr, int lMaxLen);
TANGO_API LS_GetStA(int *plStaX, int *plStaY, int *plStaZ, int *plStaA);
TANGO_API LS_SetDigIO_Off (int lIndex);
TANGO_API LS_SetDigIO_Polarity (int lIndex, BOOL bHigh);
TANGO_API LS_SetDigIO_EmergencyStop (int lIndex);
TANGO_API LS_SetDigIO_Distance (int lIndex, BOOL bFkt, double dDist, int lAxis);
TANGO_API LS_SetDimensions (int lXD, int lYD, int lZD, int lAD);
TANGO_API LS_SetResolution (int lValue);
TANGO_API LS_MoveRelShort (void);
TANGO_API LS_SetEncoderPeriod (double dX, double dY, double dZ, double dA);
TANGO_API LS_SetJoystickDir (int lXD, int lYD, int lZD, int lAD);
TANGO_API LS_SetEncoderMask (int lValue);
TANGO_API LS_SetGear (double dX, double dY, double dZ, double dA);
TANGO_API LS_SetHandWheelOn (BOOL bPositionCount, BOOL bEncoder);
TANGO_API LS_SetHandWheelOff (void);
TANGO_API LS_SetFactorTVR (double dX, double dY, double dZ, double dA);
TANGO_API LS_SetTargetWindow (double dX, double dY, double dZ, double dA);
TANGO_API LS_SetController (int lXC, int lYC, int lZC, int lAC);
TANGO_API LS_SetControllerCall (int lCtrCall);
TANGO_API LS_SetControllerSteps (double dX, double dY, double dZ, double dA);
TANGO_API LS_SetControllerFactor (double dX, double dY, double dZ, double dA);
TANGO_API LS_SetControllerFactorSingleAxis(int lAxis, double dFactor1, double dFactor2);
TANGO_API LS_SetControllerTWDelay(int lCtrTWDelay);
TANGO_API LS_SetControllerTWDelaySingleAxis(int lAxis, int lCtrTWDelay);
TANGO_API LS_SetEncoderRefSignal (int lXR, int lYR, int lZR, int lAR);
TANGO_API LS_SetEncoderPosition (BOOL bValue);
TANGO_API LS_GetVersionStr (char *pcVers, int lMaxLen);
TANGO_API LS_GetTangoVersion (char *pcVers, int lMaxLen);
TANGO_API LS_GetError (int *plErrorCode);
TANGO_API LS_GetErrorString(int lErrorCode, char *pcErrorCode, int lMaxLen);
TANGO_API LS_GetPosSingleAxis (int lAxis, double *pdPos);
TANGO_API LS_SetDistance (double dX, double dY, double dZ, double dA);
TANGO_API LS_GetPosEx (double *pdX, double *pdY, double *pdZ, double *pdR, BOOL bEncoder);
TANGO_API LS_SetShowCmdList (BOOL bShowCmdList);
TANGO_API LS_SetWriteLogText (BOOL bAWriteLogText);
TANGO_API LS_SetControllerTimeout (int lACtrTimeout);
TANGO_API LS_SetEncoderActive (int lFlags);
TANGO_API LS_GetSnapshotCount (int *plSnsCount);
TANGO_API LS_SetSnapshotCount (int lSnsCount);
TANGO_API LS_GetSnapshotPos (double *pdX, double *pdY, double *pdZ, double *pdA);
TANGO_API LS_SetCorrTblOff (void);
TANGO_API LS_SetCorrTblOn (char *pcAFileName);
TANGO_API LS_SetFactorMode (BOOL bAFactorMode, double dX, double dY, double dZ, double dA);
TANGO_API LS_SetSnapshot (BOOL bASnapshot);
TANGO_API LS_SetSnapshotPar (BOOL bHigh, BOOL bAutoMode);
TANGO_API LS_SetTrigger (BOOL bATrigger);
TANGO_API LS_SetTriggerPar (int lAxis, int lMode, int lSignal, double dDistance);
TANGO_API LS_SetTrigCount (int lValue);

TANGO_API LS_SetTriggerAxis (int lAxis);
TANGO_API LS_SetTriggerMode (int lMode);
TANGO_API LS_SetTriggerSignalLength (int lSignal);
TANGO_API LS_SetTriggerDistance (double dDistance);
TANGO_API LS_SetTriggerCompensation (int lCompensation);
TANGO_API LS_SetTriggerEncoder (int lEncoder);
TANGO_API LS_SetTriggerFrequency (double dFrequency);
TANGO_API LS_SetTriggerRange (double dStartPos, double dEndPos, int lNumberOfTriggerPulses);
TANGO_API LS_SetTriggerOutput (int lOutput);
TANGO_API LS_SetTriggerPositionList (int lIndex, double dPosition);
TANGO_API LS_SetTriggerPositionListIndex (int lIndex);
TANGO_API LS_SetTriggerPositionListEntries (int lNumberOfEntries);
TANGO_API LS_SetTriggerLevel (int lLevel);
TANGO_API LS_Set2ndTriggerDelay (double dDelay);
TANGO_API LS_Set2ndTriggerWidth (double dWidth);
TANGO_API LS_Set2ndTriggerFrequency (double dFrequency);

TANGO_API LS_SetLanguage (char *pcPLN);
TANGO_API LS_GetSwitches (int *plFlags);
TANGO_API LS_GetSerialNr (char *pcSerialNr, int lMaxLen);
TANGO_API LS_SetCalibOffset (double dX, double dY, double dZ, double dR);
TANGO_API LS_SetRMOffset (double dX, double dY, double dZ, double dR);
TANGO_API LS_GetSnapshotPosArray (int lIndex, double *pdX, double *pdY, double *pdZ, double *pdR);
TANGO_API LS_SetAxisDirection (int lXD, int lYD, int lZD, int lAD);
TANGO_API LS_SetCalibrateDir (int lXD, int lYD, int lZD, int lAD);
TANGO_API LS_LStepSave (void);
TANGO_API LS_SetBPZ (int lAValue);
TANGO_API LS_SetBPZTrackballFactor (double dAValue);
TANGO_API LS_SetBPZTrackballBackLash (double dX, double dY, double dZ, double dR);
TANGO_API LS_SetBPZJoyspeed (int lAPar, double dAValue);
TANGO_API LS_SetJoystickWindow (int lAValue);
TANGO_API LS_SetCurrentDelay (int lX, int lY, int lZ, int lR);
TANGO_API LS_MoveEx (double dX, double dY, double dZ, double dR, BOOL bRelative, BOOL bWait, int lAxisCount);
TANGO_API LS_WaitForAxisStop (int lAFlags, int lATimeoutValue, BOOL *pbATimeout);
TANGO_API LS_SetProcessMessagesProc (void* pProc);
TANGO_API LS_SendStringPosCmd (char *pcStr, char *pcRet, int lMaxLen, BOOL bReadLine, int lTimeOut);
TANGO_API LS_SetWriteLogTextFN (BOOL bAWriteLogText, char *pcALogFN);
TANGO_API LS_EnableCommandRetry (BOOL bAValue);
TANGO_API LS_SetXYAxisComp (int lValue);
TANGO_API LS_GetVersionStrDet (char *pcVersDet, int lMaxLen);
TANGO_API LS_SetDllNumOfAxes (int lNumOfAxes);
TANGO_API LS_SetCommandTimeout (int lAtoRead, int lAtoMove, int lAtoCalibrate);
TANGO_API LS_GetCommandTimeout (int *plAtoRead, int *plAtoMove, int *plAtoCalibrate);
TANGO_API LS_SetExtValue (int lAName, int lAValue);
TANGO_API LS_FlushBuffer (int lAValue);
TANGO_API LS_GetEEPRomValue (byte Offset, byte *pValue);
TANGO_API LS_SetEEPRomValue (byte Offset, byte Value);
TANGO_API LS_GetXYAxisComp (int *plValue);
TANGO_API LS_GetDimensions (int *plXD, int *plYD, int *plZD, int *plAD);
TANGO_API LS_GetResolution (int *plValue);
TANGO_API LS_GetPitch (double *pdX, double *pdY, double *pdZ, double *pdA);
TANGO_API LS_GetGear (double *pdX, double *pdY, double *pdZ, double *pdA);
TANGO_API LS_GetVel (double *pdX, double *pdY, double *pdZ, double *pdA);
TANGO_API LS_GetSecVel (double *pdX, double *pdY, double *pdZ, double *pdA);
TANGO_API LS_GetAccel (double *pdX, double *pdY, double *pdZ, double *pdA);
TANGO_API LS_SetVelFac (double dX, double dY, double dZ, double dR);
TANGO_API LS_GetVelFac (double *pdX, double *pdY, double *pdZ, double *pdR);
TANGO_API LS_GetSpeedPoti (BOOL *pbSpePoti);
TANGO_API LS_GetMotorCurrent (double *pdX, double *pdY, double *pdZ, double *pdA);
TANGO_API LS_GetReduction (double *pdX, double *pdY, double *pdZ, double *pdA);
TANGO_API LS_GetCurrentDelay (int *plX, int *plY, int *plZ, int *plR);
TANGO_API LS_SetOutFuncLev (double dX, double dY, double dZ, double dR);
TANGO_API LS_GetOutFuncLev (double *pdX, double *pdY, double *pdZ, double *pdR);
TANGO_API LS_GetActiveAxes (int *plFlags);
TANGO_API LS_GetAxisDirection (int *plXD, int *plYD, int *plZD, int *plAD);
TANGO_API LS_GetCalibOffset (double *pdX, double *pdY, double *pdZ, double *pdR);
TANGO_API LS_GetRMOffset (double *pdX, double *pdY, double *pdZ, double *pdR);
TANGO_API LS_GetCalibrateDir (int *plXD, int *plYD, int *plZD, int *plAD);
TANGO_API LS_SetCalibBackSpeed (int lSpeed);
TANGO_API LS_GetCalibBackSpeed (int *plSpeed);
TANGO_API LS_SetRefSpeed (int lSpeed);
TANGO_API LS_GetRefSpeed (int *plSpeed);
TANGO_API LS_SetPowerAmplifier (BOOL bAmplifier);
TANGO_API LS_GetPowerAmplifier (BOOL *pbAmplifier);
TANGO_API LS_SetMotorTablePatch (BOOL bActive);
TANGO_API LS_GetMotorTablePatch (BOOL *pbActive);
TANGO_API LS_SetJoystickFilter (BOOL bActive);
TANGO_API LS_GetJoystickFilter (BOOL *pbActive);
TANGO_API LS_SetStopPolarity (BOOL bHighActiv);
TANGO_API LS_GetStopPolarity (BOOL *pbHighActiv);
TANGO_API LS_SetVLevel (int lVRegion, double dDownLevel, double dUppLevel);
TANGO_API LS_GetVLevel (int lVRegion, double *pdDownLevel, double *pdUppLevel);
TANGO_API LS_SetStopAccel (double dXD, double dYD, double dZD, double dAD);
TANGO_API LS_GetStopAccel (double *pdXD, double *pdYD, double *pdZD, double *pdAD);
TANGO_API LS_GetVersionStrInfo (char *pcVersInfo, int lMaxLen);
TANGO_API LS_GetStatusLimit (char *pcLimit, int lMaxLen);
TANGO_API LS_GetSecurityErr (DWORD *pdwValue);
TANGO_API LS_GetSecurityStatus (DWORD *pdwValue);
TANGO_API LS_GetDelay (int *plDelay);
TANGO_API LS_GetDistance (double *pdX, double *pdY, double *pdZ, double *pdR);
TANGO_API LS_ClearPos (int lFlags);
TANGO_API LS_SetDigJoySpeed (double dX, double dY, double dZ, double dR);
TANGO_API LS_GetDigJoySpeed (double *pdX, double *pdY, double *pdZ, double *pdR);
TANGO_API LS_GetJoystickDir (int *plXD, int *plYD, int *plZD, int *plRD);
TANGO_API LS_GetJoystick (BOOL *pbJoystickOn, BOOL *pbManual, BOOL *pbPositionCount, BOOL *pbEncoder);
TANGO_API LS_GetJoystickWindow (int *plAValue);
TANGO_API LS_GetHandWheel (BOOL *pbHandWheelOn, BOOL *pbPositionCount, BOOL *pbEncoder);
TANGO_API LS_GetBPZ (int *plAValue);
TANGO_API LS_GetBPZTrackballFactor (double *pdAValue);
TANGO_API LS_GetBPZTrackballBackLash (double *pdX, double *pdY, double *pdZ, double *pdR);
TANGO_API LS_GetBPZJoyspeed (int lAPar, double *pdAValue);
TANGO_API LS_GetLimitControl (int lAxis, BOOL *pbActive);
TANGO_API LS_SetAutoLimitAfterCalibRM (int lFlags);
TANGO_API LS_GetAutoLimitAfterCalibRM (int *plFlags);
TANGO_API LS_GetSwitchPolarity (int *plXP, int *plYP, int *plZP, int *plRP);
TANGO_API LS_GetSwitchActive (int *plXA, int *plYA, int *plZA, int *plRA);
TANGO_API LS_GetTVRMode (int *plXT, int *plYT, int *plZT, int *plRT);
TANGO_API LS_GetFactorTVR (double *pdX, double *pdY, double *pdZ, double *pdR);
TANGO_API LS_SetTVROutMode (int lXT, int lYT, int lZT, int lRT);
TANGO_API LS_GetTVROutMode (int *plXT, int *plYT, int *plZT, int *plRT);
TANGO_API LS_SetTVROutResolution (int lX, int lY, int lZ, int lR);
TANGO_API LS_GetTVROutResolution (int *plX, int *plY, int *plZ, int *plR);
TANGO_API LS_SetTVROutPitch (double dX, double dY, double dZ, double dR);
TANGO_API LS_GetTVROutPitch (double *pdX, double *pdY, double *pdZ, double *pdR);
TANGO_API LS_SetVelTVRO (double dX, double dY, double dZ, double dR);
TANGO_API LS_GetVelTVRO (double *pdX, double *pdY, double *pdZ, double *pdR);
TANGO_API LS_SetAccelTVRO (double dX, double dY, double dZ, double dR);
TANGO_API LS_GetAccelTVRO (double *pdX, double *pdY, double *pdZ, double *pdR);
TANGO_API LS_SetVelSingleAxisTVRO (int lAxis, double dVel);
TANGO_API LS_SetAccelSingleAxisTVRO (int lAxis, double dAccel);
TANGO_API LS_SetPosTVRO (double dX, double dY, double dZ, double dR);
TANGO_API LS_GetPosTVRO (double *pdX, double *pdY, double *pdZ, double *pdR);
TANGO_API LS_MoveAbsTVRO (double dX, double dY, double dZ, double dR, BOOL bWait);
TANGO_API LS_MoveRelTVRO (double dX, double dY, double dZ, double dR, BOOL bWait);
TANGO_API LS_MoveRelTVROSingleAxis (int lAxis, double dValue, BOOL bWait);
TANGO_API LS_MoveAbsTVROSingleAxis (int lAxis, double dValue, BOOL bWait);
TANGO_API LS_GetStatusTVRO (char *pcStat, int lMaxLen);
TANGO_API LS_GetTargetWindow (double *pdX, double *pdY, double *pdZ, double *pdR);
TANGO_API LS_GetEncoderSingleAxis (int lAxis, int *plEncoderType, double *pdPeriod, int *plRef);
TANGO_API LS_SetEncoderSingleAxis (int lAxis, int lEncoderType, double dPeriod, int lRef);
TANGO_API LS_GetEncoderPeriod (double *pdX, double *pdY, double *pdZ, double *pdR);
TANGO_API LS_GetEncoderRefSignal (int *plXR, int *plYR, int *plZR, int *plRR);
TANGO_API LS_GetEncoderPosition (BOOL *pbValue);
TANGO_API LS_GetEncoderActive (int *plFlags);
TANGO_API LS_GetController (int *plXC, int *plYC, int *plZC, int *plRC);
TANGO_API LS_GetControllerCall (int *plCtrCall);
TANGO_API LS_GetControllerSteps (double *pdX, double *pdY, double *pdZ, double *pdR);
TANGO_API LS_GetControllerFactor (double *pdX, double *pdY, double *pdZ, double *pdR);
TANGO_API LS_GetControllerFactorSingleAxis(int lAxis, double *pdFactor1, double *pdFactor2);
TANGO_API LS_GetControllerTWDelay(int *plCtrTWDelay);
TANGO_API LS_GetControllerTWDelaySingleAxis(int lAxis, int *plCtrTWDelay);
TANGO_API LS_GetControllerTimeout (int *plACtrTimeout);
TANGO_API LS_SetCtrFastMoveOn (void);
TANGO_API LS_SetCtrFastMoveOff (void);
TANGO_API LS_GetCtrFastMove (BOOL *pbActive);
TANGO_API LS_ClearCtrFastMoveCounter (void);
TANGO_API LS_GetCtrFastMoveCounter (int *plXC, int *plYC, int *plZC, int *plRC);
TANGO_API LS_ClearEncoder (int lAxis);
TANGO_API LS_GetEncoder (double *pdXP, double *pdYP, double *pdZP, double *pdRP);
TANGO_API LS_GetTrigger (BOOL *pbATrigger);
TANGO_API LS_GetTriggerPar (int *plAxis, int *plMode, int *plSignal, double *pdDistance);
TANGO_API LS_GetTrigCount (int *plValue);

TANGO_API LS_GetTriggerAxis (int *plAxis);
TANGO_API LS_GetTriggerMode (int *plMode);
TANGO_API LS_GetTriggerSignalLength (int *plSignal);
TANGO_API LS_GetTriggerDistance (double *pdDistance);
TANGO_API LS_GetTriggerCompensation (int *plCompensation);
TANGO_API LS_GetTriggerEncoder (int *plEncoder);
TANGO_API LS_GetTriggerFrequency (double *pdFrequency);
TANGO_API LS_GetTriggerRange (double *pdStartPos, double *pdEndPos, int *plNumberOfTriggerPulses);
TANGO_API LS_GetTriggerOutput (int *plOutput);
TANGO_API LS_GetTriggerPositionList (int lIndex, double *pdPos);
TANGO_API LS_GetTriggerPositionListIndex (int *plIndex);
TANGO_API LS_GetTriggerPositionListEntries (int *plNumberOfEntries);
TANGO_API LS_GetTriggerLevel (int *plLevel);
TANGO_API LS_Get2ndTriggerDelay (double *pdDelay);
TANGO_API LS_Get2ndTriggerWidth (double *pdWidth);
TANGO_API LS_Get2ndTriggerFrequency (double *pdFrequency);

TANGO_API LS_SetTVRInPulse (int lAxis, BOOL bDirection);
TANGO_API LS_GetSnapshot (BOOL *pbASnapshot);
TANGO_API LS_SetSnapshotFilter (int lTime);
TANGO_API LS_GetSnapshotFilter (int *plTime);
TANGO_API LS_GetSnapshotPar (BOOL *pbHigh, BOOL *pbAutoMode);
TANGO_API LS_GetLimit (int lAxis, double *pdMinRange, double *pdMaxRange);
TANGO_API LS_JoyChangeAxis (BOOL bValue);
TANGO_API LS_GetJoyChangeAxis (BOOL *pbValue);
TANGO_API LS_GetSyncZA (BOOL *pbSyncZA);
TANGO_API LS_SetSyncZA (BOOL bSync);
TANGO_API LS_GetSwapZA (BOOL *pbSwapZA);
TANGO_API LS_SetSwapZA (BOOL bSwap);
TANGO_API LS_GetKey (BOOL *pbKey1, BOOL *pbKey2, BOOL *pbKey3, BOOL *pbKey4);
TANGO_API LS_GetKeyLatch (BOOL *pbKey1, BOOL *pbKey2, BOOL *pbKey3, BOOL *pbKey4);
TANGO_API LS_ClearKeyLatch (int lKey);
TANGO_API LS_SetZwTravel (int lIndex, double dDistance);
TANGO_API LS_GetZwTravel (int lIndex, double *pdDistance);
TANGO_API LS_ClearSnapshotPosArray (void);
TANGO_API LS_SetSnapshotPosArray (int lIndex, double dX, double dY, double dZ, double dA);
TANGO_API LS_SetSnapshotIndex (int lIndex);
TANGO_API LS_GetSnapshotIndex (int *plIndex);
TANGO_API LS_SetSnapshotMode (int lMode);
TANGO_API LS_GetSnapshotMode (int *plMode);


TANGO_API LSX_GetBlSmoothSingleAxis(int lLSID, int lAxis, int *plBlSmooth);
TANGO_API LS_GetBlSmoothSingleAxis(int lAxis, int *plBlSmooth);
TANGO_API LSX_SetBlSmoothSingleAxis(int lLSID, int lAxis, int lBlSmooth);
TANGO_API LS_SetBlSmoothSingleAxis(int lAxis, int lBlSmooth);


TANGO_API LSX_SetSwitchType (int lLSID, int lXP, int lYP, int lZP, int lAP);
TANGO_API LS_SetSwitchType (int lXP, int lYP, int lZP, int lAP);
TANGO_API LSX_GetSwitchType (int lLSID, int *plXP, int *plYP, int *plZP, int *plRP);
TANGO_API LS_GetSwitchType (int *plXP, int *plYP, int *plZP, int *plRP);

TANGO_API LSX_SetMotorSteps (int lLSID, int lX, int lY, int lZ, int lR);
TANGO_API LS_SetMotorSteps (int lX, int lY, int lZ, int lR);
TANGO_API LSX_GetMotorSteps (int lLSID, int *lX, int *lY, int *lZ, int *lR);
TANGO_API LS_GetMotorSteps (int *lX, int *lY, int *lZ, int *lR);

TANGO_API LSX_SetAccelFunc (int lLSID, int lX, int lY, int lZ, int lR);
TANGO_API LSX_GetAccelFunc (int lLSID, int *lX, int *lY, int *lZ, int *lR);
TANGO_API LS_SetAccelFunc (int lX, int lY, int lZ, int lR);
TANGO_API LS_GetAccelFunc (int *lX, int *lY, int *lZ, int *lR);


TANGO_API LSX_Eject (int lLSID, int maga, int keep);
TANGO_API LS_Eject (int maga, int keep);

TANGO_API LSX_Insert (int lLSID);
TANGO_API LS_Insert (void);
TANGO_API LSX_SlideSeated (int lLSID, int maga, int slot, int *status);
TANGO_API LS_SlideSeated (int maga, int slot, int *status);
TANGO_API LSX_MagazinSeated (int lLSID, int maga, int *status);
TANGO_API LS_MagazinSeated (int maga, int *status);

TANGO_API LSX_GetGripper (int lLSID, int *c1, int *s1, int *c2, int *s2);
TANGO_API LSX_SetGripper (int lLSID, int c1, int s1, int c2, int s2);
TANGO_API LS_GetGripper (int *c1, int *s1, int *c2, int *s2);
TANGO_API LS_SetGripper (int c1, int s1, int c2, int s2);

TANGO_API LSX_GetSlide (int lLSID, int maga, int slot, int mode);
TANGO_API LSX_PutSlide (int lLSID, int maga, int slot);
TANGO_API LS_GetSlide (int maga, int slot, int mode);
TANGO_API LS_PutSlide (int maga, int slot);

TANGO_API LSX_SetPrioHandlerPos (int lLSID, int php); 
TANGO_API LSX_GetPrioHandlerPos (int lLSID, int *php); 
TANGO_API LS_SetPrioHandlerPos (int php);
TANGO_API LS_GetPrioHandlerPos (int *php);

TANGO_API LSX_GetTray (int lLSID, int slot, int mode);
TANGO_API LSX_PutTray (int lLSID, int slot);
TANGO_API LS_GetTray (int slot, int mode);
TANGO_API LS_PutTray (int slot);

TANGO_API LSX_GetRFID (int lLSID, int slot, int bank, int *plRFID);
TANGO_API LS_GetRFID  (int slot, int bank, int *plRFID);

TANGO_API LSX_GetNumberOfSlots (int lLSID, int *plSlots);
TANGO_API LS_GetNumberOfSlots  (int *plSlots);

TANGO_API LSX_GetNumberOfMagazins (int lLSID, int *plMagazins);
TANGO_API LS_GetNumberOfMagazins  (int *plMagazins);


TANGO_API LSX_SetRFID (int lLSID, int slot, int bank, int lRFID);
TANGO_API LS_SetRFID  (int slot, int bank, int lRFID);
TANGO_API LSX_GetNumberOfRows    (int lLSID, int *plRows);
TANGO_API LS_GetNumberOfRows     (int *plRows);
TANGO_API LSX_GetNumberOfColumns (int lLSID, int *plMagazins);
TANGO_API LS_GetNumberOfColumns  (int *plMagazins);
TANGO_API LSX_GetLoaderType (int lLSID, int *plLoaderType);
TANGO_API LS_GetLoaderType  (int *plLoaderType);
TANGO_API LSX_GetTraySN     (int lLSID, int slot, int *plTraySN);
TANGO_API LS_GetTraySN      (int slot, int *plTraySN);
TANGO_API LSX_GetTrayType   (int lLSID, int slot, int *plTrayType);
TANGO_API LS_GetTrayType    (int slot, int *plTrayType);
TANGO_API LSX_SetTrayType(int lLSID, int slot, int TrayType);
TANGO_API LS_SetTrayType(int slot, int TrayType);
TANGO_API LSX_GetTrayOnStage(int lLSID, int *plTrayOnSTage);
TANGO_API LS_GetTrayOnStage(int *plTrayOnStage);

TANGO_API LSX_SetLabelLED(int lLSID, int lOn);
TANGO_API LS_SetLabelLED(int lOn);
TANGO_API LSX_GetLabelLED(int lLSID, int *plOn);
TANGO_API LS_GetLabelLED(int *plOn);
TANGO_API LSX_SetCabinLED(int lLSID, int lOn);
TANGO_API LS_SetCabinLED(int lOn);
TANGO_API LSX_GetCabinLED(int lLSID, int *plOn);
TANGO_API LS_GetCabinLED(int *plOn);



TANGO_API LSX_Xpos3_MoveAbsSingleAxis(int lLSID, int lAxis, double dValue, BOOL bWait);
TANGO_API LSX_Xpos3_MoveRelSingleAxis(int lLSID, int lAxis, double dValue, BOOL bWait);
TANGO_API LSX_Xpos3_SetPosSingleAxis(int lLSID, int lAxis, double dValue);
TANGO_API LSX_Xpos3_GetPosSingleAxis(int lLSID, int lAxis, double *pdValue);
TANGO_API LS_Xpos3_MoveAbsSingleAxis(int lAxis, double dValue, BOOL bWait);
TANGO_API LS_Xpos3_MoveRelSingleAxis(int lAxis, double dValue, BOOL bWait);
TANGO_API LS_Xpos3_SetPosSingleAxis(int lAxis, double dValue);
TANGO_API LS_Xpos3_GetPosSingleAxis(int lAxis, double *pdValue);

TANGO_API MsgDisconnect (char *pcAComName);
TANGO_API MsgReconnect (char *pcAComName);

/*
//unklar, da von Lang die Dokumentation fehlt
GetMsgProc
LS_SetDigJoyOff
LS_SetVelFacSingleAxis
TANGO_API LS_SetRaiseExceptions (void);
TANGO_API LS_GetAxes (void);
TANGO_API LS_SetAxis (void);
TANGO_API LS_GetConnected (void);
TANGO_API LS_GetCtrlInitPar (void);
TANGO_API LS_SetCtrlInitPar (void);
TANGO_API LS_GetCtrlPars (void);
LS_SetCtrlPars
TANGO_API LS_GetCalibPar (void);
TANGO_API LS_SetCalibPar (void);
TANGO_API LS_SetExceptionProc (void);
TANGO_API LS_SetMainWnd (void);
TANGO_API LS_GetCmdListWnd (void);
TANGO_API LS_GetProtWnd (void);
TANGO_API LS_GetConfig (void);
LS_GetAPIVersion
LS_LStepSave
LS_GetCmdListWnd
LS_SetOsziTrigMode
LS_GetOsziTrigMode
LS_SetOsziDataSize
LS_GetOsziDataSize
LS_OsziReset
LS_SetOsziOn
LS_SetOsziOff
LS_SetOsziRecordOn
LS_GetOsziStatus
LS_SetOsziPreTrigDataSize
LS_GetOsziPreTrigDataSize
LS_SetOsziTrigLevel
LS_GetOsziTrigLevel
LS_SetOsziPrescale
LS_GetOsziPrescale
LS_SetOsziChanelSignal
LS_GetOsziChanelSignal
LS_SetOszitrigaxis
LS_GetOszitrigaxis
LS_SetOsziCallBackFct
LS_SetDeceleration
LS_SetDecelSingleAxis
LS_GetDeceleration
LS_ConfigMaxAxes
TANGO_API LS_SetControlParsEx (void);

*/

#ifdef __cplusplus
// use "C"-style names
}
#endif










#endif // !defined(AFX_TANGO_DLL_H__9C482D72_9083_4B59_835F_8120FA8DFE16__INCLUDED_)

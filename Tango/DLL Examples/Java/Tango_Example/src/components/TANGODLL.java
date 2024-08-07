/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author FD
 * This Java interface adapts to either 32 or 64 bit native Tango DLL
 * matching DLL (32 or 64) depends on target operating system
 * Please find detailed documentation in
 * Tango DLL reference manual
 * and Tango instruction set manual
 */

package components;

import com.sun.jna.*;
import com.sun.jna.ptr.IntByReference;
import com.sun.jna.ptr.DoubleByReference;

public interface TANGODLL extends Library { 

    /**
     *
     * @param lLSID
     * @param lAnInterfaceType
     * @param pcAComName
     * @param lABaudRate
     * @param bAShowProt
     * @return
     */
    public int LSX_ConnectSimple (int lLSID,int lAnInterfaceType,String pcAComName,int lABaudRate,boolean bAShowProt);

    /**
     *
     * @param lLSID
     * @return
     */
    public int LSX_CreateLSID (IntByReference lLSID);

    /**
     *
     * @param lLSID
     * @return
     */
    public int LSX_Disconnect (int lLSID);

    /**
     *
     * @param lLSID
     * @param bAValue
     * @return
     */
    public int LSX_EnableCommandRetry (int lLSID, boolean bAValue);

    /**
     *
     * @param lLSID
     * @param iAValue
     * @return
     */
    public int LSX_FlushBuffer (int lLSID, int iAValue);

    /**
     *
     * @param lLSID
     * @return
     */
    public int LSX_FreeLSID (int lLSID);

    /**
     *
     * @param lLSID
     * @param pcStr
     * @param pcRet
     * @param lMaxLen
     * @param bReadLine
     * @param lTimeOut
     * @return
     */
    public int LSX_SendString (int lLSID,Pointer pcStr, Pointer pcRet, int lMaxLen, boolean bReadLine, int lTimeOut);

    /**
     *
     * @param lLSID
     * @param pcStr
     * @param pcRet
     * @param lMaxLen
     * @param bReadLine
     * @param lTimeOut
     * @return
     */
    public int LSX_SendStringPosCmd (int lLSID, Pointer pcStr, Pointer pcRet, int lMaxLen, boolean bReadLine, int lTimeOut);

    /**
     *
     * @param lLSID
     * @return
     */
    public int LSX_SetAbortFlag (int lLSID);

    /**
     *
     * @param lLSID
     * @param bShowProt
     * @return
     */
    public int LSX_SetShowProt (int lLSID, boolean bShowProt);

    /**
     *
     * @param lLSID
     * @param pcSerialNr
     * @param lMaxLen
     * @return
     */
    public int LSX_GetSerialNr (int lLSID, Pointer pcSerialNr, int lMaxLen);

    /**
     *
     * @param lLSID
     * @param pcVers
     * @param lMaxLen
     * @return
     */
    public int LSX_GetVersionStr (int lLSID, Pointer pcVers, int lMaxLen);

    /**
     *
     * @param lLSID
     * @param pcVersDet
     * @param lMaxLen
     * @return
     */
    public int LSX_GetVersionStrDet (int lLSID, Pointer pcVersDet, int lMaxLen);

    /**
     *
     * @param lLSID
     * @param pcVersInfo
     * @param lMaxLen
     * @return
     */
    public int LSX_GetVersionStrInfo (int lLSID, Pointer pcVersInfo, int lMaxLen);

    /**
     *
     * @param lLSID
     * @param plErrorCode
     * @return
     */
    public int LSX_GetError (int lLSID, IntByReference plErrorCode);

    /**
     *
     * @param lLSID
     * @param pdX
     * @param pdY
     * @param pdZ
     * @param pdA
     * @return
     */
    public int LSX_GetPos (int lLSID, DoubleByReference pdX, DoubleByReference pdY, DoubleByReference pdZ, DoubleByReference pdA);

    /**
     *
     * @param lLSID
     * @param pdX
     * @param pdY
     * @param pdZ
     * @param pdA
     * @param bEncoder
     * @return
     */
    public int LSX_GetPosEx (int lLSID, DoubleByReference pdX, DoubleByReference pdY, DoubleByReference pdZ, DoubleByReference pdA, boolean bEncoder);

    /**
     *
     * @param lLSID
     * @param lAxis
     * @param pdPos
     * @return
     */
    public int LSX_GetPosSingleAxis (int lLSID, int lAxis, DoubleByReference pdPos);

    /**
     *
     * @param lLSID
     * @param pcStat
     * @param lMaxLen
     * @return
     */
    public int LSX_GetStatus (int lLSID, Pointer pcStat, int lMaxLen);

    /**
     *
     * @param lLSID
     * @param pcStatusAxisStr
     * @param lMaxLen
     * @return
     */
    public int LSX_GetStatusAxis (int lLSID, Pointer pcStatusAxisStr, int lMaxLen);

    /**
     *
     * @param lLSID
     * @param pcLimit
     * @param lMaxLen
     * @return
     */
    public int LSX_GetStatusLimit (int lLSID, Pointer pcLimit, int lMaxLen);

    /**
     *
     * @param lLSID
     * @param lValue
     * @return
     */
    public int LSX_SetAutoStatus (int lLSID, int lValue);

    /**
     *
     * @param lLSID
     * @param pdX
     * @param pdY
     * @param pdZ
     * @param pdA
     * @return
     */
    public int LSX_GetAccel (int lLSID, DoubleByReference pdX, DoubleByReference pdY, DoubleByReference pdZ, DoubleByReference pdA);

    /**
     *
     * @param lLSID
     * @param dX
     * @param dY
     * @param dZ
     * @param dA
     * @return
     */
    public int LSX_SetAccel (int lLSID, double dX, double dY, double dZ, double dA);

    /**
     *
     * @param lLSID
     * @param plFlags
     * @return
     */
    public int LSX_GetActiveAxes (int lLSID, IntByReference plFlags);

    /**
     *
     * @param lLSID
     * @param lX
     * @param lY
     * @param lZ
     * @param lR
     * @return
     */
    public int LSX_GetAccelFunc (int lLSID, IntByReference lX, IntByReference lY, IntByReference lZ, IntByReference lR);

    /**
     *
     * @param lLSID
     * @param lX
     * @param lY
     * @param lZ
     * @param lR
     * @return
     */
    public int LSX_SetAccelFunc (int lLSID, int lX, int lY, int lZ, int lR);

    /**
     *
     * @param lLSID
     * @param lFlags
     * @return
     */
    public int LSX_SetActiveAxes (int lLSID, int lFlags);

    /**
     *
     * @param lLSID
     * @param plXD
     * @param plYD
     * @param plZD
     * @param plAD
     * @return
     */
    public int LSX_GetAxisDirection (int lLSID, IntByReference plXD, IntByReference plYD, IntByReference plZD, IntByReference plAD);

    /**
     *
     * @param lLSID
     * @param lXD
     * @param lYD
     * @param lZD
     * @param lAD
     * @return
     */
    public int LSX_SetAxisDirection (int lLSID, int lXD, int lYD, int lZD, int lAD);

    /**
     *
     * @param lLSID
     * @param plSpeed
     * @return
     */
    public int LSX_GetCalibBackSpeed (int lLSID, IntByReference plSpeed);

    /**
     *
     * @param lLSID
     * @param lSpeed
     * @return
     */
    public int LSX_SetCalibBackSpeed (int lLSID, int lSpeed);

    /**
     *
     * @param lLSID
     * @param pdX
     * @param pdY
     * @param pdZ
     * @param pdA
     * @return
     */
    public int LSX_GetCalibOffset (int lLSID, DoubleByReference pdX, DoubleByReference pdY, DoubleByReference pdZ, DoubleByReference pdA);

    /**
     *
     * @param lLSID
     * @param dX
     * @param dY
     * @param dZ
     * @param dA
     * @return
     */
    public int LSX_SetCalibOffset (int lLSID, double dX, double dY, double dZ, double dA);

    /**
     *
     * @param lLSID
     * @param plXD
     * @param plYD
     * @param plZD
     * @param plAD
     * @return
     */
    public int LSX_GetCalibrateDir (int lLSID, IntByReference plXD, IntByReference plYD, IntByReference plZD, IntByReference plAD);

    /**
     *
     * @param lLSID
     * @param lXD
     * @param lYD
     * @param lZD
     * @param lAD
     * @return
     */
    public int LSX_SetCalibrateDir (int lLSID, int lXD, int lYD, int lZD, int lAD);

    /**
     *
     * @param lLSID
     * @param plX
     * @param plY
     * @param plZ
     * @param plA
     * @return
     */
    public int LSX_GetCurrentDelay (int lLSID, IntByReference plX, IntByReference plY, IntByReference plZ, IntByReference plA);

    /**
     *
     * @param lLSID
     * @param lX
     * @param lY
     * @param lZ
     * @param lA
     * @return
     */
    public int LSX_SetCurrentDelay (int lLSID, int lX, int lY, int lZ, int lA);

    /**
     *
     * @param lLSID
     * @param plXD
     * @param plYD
     * @param plZD
     * @param plAD
     * @return
     */
    public int LSX_GetDimensions (int lLSID, IntByReference plXD, IntByReference plYD, IntByReference plZD, IntByReference plAD);

    /**
     *
     * @param lLSID
     * @param lXD
     * @param lYD
     * @param lZD
     * @param lAD
     * @return
     */
    public int LSX_SetDimensions (int lLSID, int lXD, int lYD, int lZD, int lAD);

    /**
     *
     * @param lLSID
     * @param pdX
     * @param pdY
     * @param pdZ
     * @param pdA
     * @return
     */
    public int LSX_GetGear (int lLSID, DoubleByReference pdX, DoubleByReference pdY, DoubleByReference pdZ, DoubleByReference pdA);

    /**
     *
     * @param lLSID
     * @param dX
     * @param dY
     * @param dZ
     * @param dA
     * @return
     */
    public int LSX_SetGear (int lLSID, double dX, double dY, double dZ, double dA);

    /**
     *
     * @param lLSID
     * @param pdX
     * @param pdY
     * @param pdZ
     * @param pdA
     * @return
     */
    public int LSX_GetMotorCurrent (int lLSID, DoubleByReference pdX, DoubleByReference pdY, DoubleByReference pdZ, DoubleByReference pdA);

    /**
     *
     * @param lLSID
     * @param dX
     * @param dY
     * @param dZ
     * @param dA
     * @return
     */
    public int LSX_SetMotorCurrent (int lLSID, double dX, double dY, double dZ, double dA);

    /**
     *
     * @param lLSID
     * @param lX
     * @param lY
     * @param lZ
     * @param lA
     * @return
     */
    public int LSX_GetMotorSteps (int lLSID, IntByReference lX, IntByReference lY, IntByReference lZ, IntByReference lA);

    /**
     *
     * @param lLSID
     * @param lX
     * @param lY
     * @param lZ
     * @param lA
     * @return
     */
    public int LSX_SetMotorSteps (int lLSID, int lX, int lY, int lZ, int lA);

    /**
     *
     * @param lLSID
     * @param pdX
     * @param pdY
     * @param pdZ
     * @param pdA
     * @return
     */
    public int LSX_GetPitch (int lLSID, DoubleByReference pdX, DoubleByReference pdY, DoubleByReference pdZ, DoubleByReference pdA);

    /**
     *
     * @param lLSID
     * @param dX
     * @param dY
     * @param dZ
     * @param dA
     * @return
     */
    public int LSX_SetPitch (int lLSID, double dX, double dY, double dZ, double dA);

    /**
     *
     * @param lLSID
     * @param pbAmplifier
     * @return
     */
    public int LSX_GetPowerAmplifier (int lLSID, IntByReference pbAmplifier);

    /**
     *
     * @param lLSID
     * @param bAmplifier
     * @return
     */
    public int LSX_SetPowerAmplifier (int lLSID, boolean bAmplifier);

    /**
     *
     * @param lLSID
     * @param pdX
     * @param pdY
     * @param pdZ
     * @param pdA
     * @return
     */
    public int LSX_GetReduction (int lLSID, DoubleByReference pdX, DoubleByReference pdY, DoubleByReference pdZ, DoubleByReference pdA);

    /**
     *
     * @param lLSID
     * @param dX
     * @param dY
     * @param dZ
     * @param dA
     * @return
     */
    public int LSX_SetReduction (int lLSID, double dX, double dY, double dZ, double dA);

    /**
     *
     * @param lLSID
     * @param pdX
     * @param pdY
     * @param pdZ
     * @param pdA
     * @return
     */
    public int LSX_GetRMOffset (int lLSID, DoubleByReference pdX, DoubleByReference pdY, DoubleByReference pdZ, DoubleByReference pdA);

    /**
     *
     * @param lLSID
     * @param dX
     * @param dY
     * @param dZ
     * @param dA
     * @return
     */
    public int LSX_SetRMOffset (int lLSID, double dX, double dY, double dZ, double dA);

    /**
     *
     * @param lLSID
     * @param pbSpePoti
     * @return
     */
    public int LSX_GetSpeedPoti (int lLSID, IntByReference pbSpePoti);

    /**
     *
     * @param lLSID
     * @param bSpeedPoti
     * @return
     */
    public int LSX_SetSpeedPoti (int lLSID, boolean bSpeedPoti);

    /**
     *
     * @param lLSID
     * @param pdXD
     * @param pdYD
     * @param pdZD
     * @param pdAD
     * @return
     */
    public int LSX_GetStopAccel (int lLSID, DoubleByReference pdXD, DoubleByReference pdYD, DoubleByReference pdZD, DoubleByReference pdAD);

    /**
     *
     * @param lLSID
     * @param dX
     * @param dY
     * @param dZ
     * @param dA
     * @return
     */
    public int LSX_SetStopAccel (int lLSID, double dX, double dY, double dZ, double dA);

    /**
     *
     * @param lLSID
     * @param pbHighActiv
     * @return
     */
    public int LSX_GetStopPolarity (int lLSID, IntByReference pbHighActiv);

    /**
     *
     * @param lLSID
     * @param bHighActiv
     * @return
     */
    public int LSX_SetStopPolarity (int lLSID, boolean bHighActiv);

    /**
     *
     * @param lLSID
     * @param pdX
     * @param pdY
     * @param pdZ
     * @param pdA
     * @return
     */
    public int LSX_GetVel (int lLSID, DoubleByReference pdX, DoubleByReference pdY, DoubleByReference pdZ, DoubleByReference pdA);

    /**
     *
     * @param lLSID
     * @param dX
     * @param dY
     * @param dZ
     * @param dA
     * @return
     */
    public int LSX_SetVel (int lLSID, double dX, double dY, double dZ, double dA);

    /**
     *
     * @param lLSID
     * @param pdX
     * @param pdY
     * @param pdZ
     * @param pdA
     * @return
     */
    public int LSX_GetVelFac (int lLSID, DoubleByReference pdX, DoubleByReference pdY, DoubleByReference pdZ, DoubleByReference pdA);

    /**
     *
     * @param lLSID
     * @param dX
     * @param dY
     * @param dZ
     * @param dA
     * @return
     */
    public int LSX_SetVelFac (int lLSID, double dX, double dY, double dZ, double dA);

    /**
     *
     * @param lLSID
     * @return
     */
    public int LSX_LStepSave (int lLSID);

    /**
     *
     * @param lLSID
     * @param lAxis
     * @param dAccel
     * @return
     */
    public int LSX_SetAccelSingleAxis (int lLSID, int lAxis, double dAccel);

    /**
     *
     * @param lLSID
     * @param lAxis
     * @param dVel
     * @return
     */
    public int LSX_SetVelSingleAxis (int lLSID, int lAxis, double dVel);

    /**
     *
     * @param lLSID
     * @return
     */
    public int LSX_SoftwareReset (int lLSID);

    /**
     *
     * @param lLSID
     * @return
     */
    public int LSX_Calibrate (int lLSID);

    /**
     *
     * @param lLSID
     * @param lFlags
     * @return
     */
    public int LSX_CalibrateEx (int lLSID, int lFlags);

    /**
     *
     * @param lLSID
     * @param lFlags
     * @return
     */
    public int LSX_ClearPos (int lLSID, int lFlags);

    /**
     *
     * @param lLSID
     * @param plDelay
     * @return
     */
    public int LSX_GetDelay (int lLSID, IntByReference plDelay);

    /**
     *
     * @param lLSID
     * @param lDelay
     * @return
     */
    public int LSX_SetDelay (int lLSID, int lDelay);

    /**
     *
     * @param lLSID
     * @param pdX
     * @param pdY
     * @param pdZ
     * @param pdA
     * @return
     */
    public int LSX_GetDistance (int lLSID, DoubleByReference pdX, DoubleByReference pdY, DoubleByReference pdZ, DoubleByReference pdA);

    /**
     *
     * @param lLSID
     * @param dX
     * @param dY
     * @param dZ
     * @param dA
     * @return
     */
    public int LSX_SetDistance (int lLSID, double dX, double dY, double dZ, double dA);

    /**
     *
     * @param lLSID
     * @param dX
     * @param dY
     * @param dZ
     * @param dA
     * @param bWait
     * @return
     */
    public int LSX_MoveAbs (int lLSID, double dX, double dY, double dZ, double dA, boolean bWait);

    /**
     *
     * @param lLSID
     * @param dX
     * @param dY
     * @param dZ
     * @param dA
     * @return
     */
    public int LSX_Go (int lLSID, double dX, double dY, double dZ, double dA);

    /**
     *
     * @param lLSID
     * @param lAxis
     * @param dValue
     * @param bWait
     * @return
     */
    public int LSX_MoveAbsSingleAxis (int lLSID, int lAxis, double dValue, boolean bWait);

    /**
     *
     * @param lLSID
     * @param dX
     * @param dY
     * @param dZ
     * @param dA
     * @param bRelative
     * @param bWait
     * @param lAxisCount
     * @return
     */
    public int LSX_MoveEx (int lLSID, double dX, double dY, double dZ, double dA, boolean bRelative, boolean bWait, int lAxisCount);

    /**
     *
     * @param lLSID
     * @param dX
     * @param dY
     * @param dZ
     * @param dA
     * @param bWait
     * @return
     */
    public int LSX_MoveRel (int lLSID,double dX,double dY,double dZ,double dA,boolean bWait);

    /**
     *
     * @param lLSID
     * @return
     */
    public int LSX_MoveRelShort (int lLSID);

    /**
     *
     * @param lLSID
     * @param lAxis
     * @param dValue
     * @param bWait
     * @return
     */
    public int LSX_MoveRelSingleAxis (int lLSID, int lAxis, double dValue, boolean bWait);

    /**
     *
     * @param lLSID
     * @return
     */
    public int LSX_RMeasure (int lLSID);

    /**
     *
     * @param lLSID
     * @param IFlags
     * @return
     */
    public int LSX_RMeasureEx (int lLSID, int IFlags);

    /**
     *
     * @param lLSID
     * @param dX
     * @param dY
     * @param dZ
     * @param dA
     * @return
     */
    public int LSX_SetPos (int lLSID, double dX, double dY, double dZ, double dA);

    /**
     *
     * @param lLSID
     * @return
     */
    public int LSX_StopAxes (int lLSID);

    /**
     *
     * @param lLSID
     * @param lAFlags
     * @param lATimeoutValue
     * @param pbATimeout
     * @return
     */
    public int LSX_WaitForAxisStop (int lLSID, int lAFlags, int lATimeoutValue, IntByReference pbATimeout);

    /**
     *
     * @param lLSID
     * @param pdX
     * @param pdY
     * @param pdZ
     * @param pdA
     * @return
     */
    public int LSX_GetDigJoySpeed (int lLSID, DoubleByReference pdX, DoubleByReference pdY, DoubleByReference pdZ, DoubleByReference pdA);

    /**
     *
     * @param lLSID
     * @param dX
     * @param dY
     * @param dZ
     * @param dA
     * @return
     */
    public int LSX_SetDigJoySpeed (int lLSID, double dX, double dY, double dZ, double dA);

    /**
     *
     * @param lLSID
     * @param pbHandWheelOn
     * @param pbPositionCount
     * @param pbEncoder
     * @return
     */
    public int LSX_GetHandWheel (int lLSID, IntByReference pbHandWheelOn, IntByReference pbPositionCount, IntByReference pbEncoder);

    /**
     *
     * @param lLSID
     * @param pbJoystickOn
     * @param pbManual
     * @param pbPositionCount
     * @param pbEncoder
     * @return
     */
    public int LSX_GetJoystick (int lLSID, IntByReference pbJoystickOn, IntByReference pbManual, IntByReference pbPositionCount, IntByReference pbEncoder);

    /**
     *
     * @param lLSID
     * @param plXD
     * @param plYD
     * @param plZD
     * @param plAD
     * @return
     */
    public int LSX_GetJoystickDir (int lLSID, IntByReference plXD, IntByReference plYD, IntByReference plZD, IntByReference plAD);

    /**
     *
     * @param lLSID
     * @param lXD
     * @param lYD
     * @param lZD
     * @param lAD
     * @return
     */
    public int LSX_SetJoystickDir (int lLSID, int lXD, int lYD, int lZD, int lAD);

    /**
     *
     * @param lLSID
     * @param plAValue
     * @return
     */
    public int LSX_GetJoystickWindow (int lLSID, IntByReference plAValue);

    /**
     *
     * @param lLSID
     * @param lAValue
     * @return
     */
    public int LSX_SetJoystickWindow (int lLSID, int lAValue);

    /**
     *
     * @param lLSID
     * @return
     */
    public int LSX_SetHandWheelOff (int lLSID);

    /**
     *
     * @param lLSID
     * @param bPositionCount
     * @param bEncoder
     * @return
     */
    public int LSX_SetHandWheelOn (int lLSID, boolean bPositionCount, boolean bEncoder);

    /**
     *
     * @param lLSID
     * @return
     */
    public int LSX_SetJoystickOff (int lLSID);

    /**
     *
     * @param lLSID
     * @param bPositionCount
     * @param bEncoder
     * @return
     */
    public int LSX_SetJoystickOn (int lLSID, boolean bPositionCount, boolean bEncoder);

    /**
     *
     * @param lLSID
     * @param pdX
     * @param pdY
     * @param pdZ
     * @param pdA
     * @return
     */
    public int LSX_GetHwFactor (int lLSID, DoubleByReference pdX, DoubleByReference pdY, DoubleByReference pdZ, DoubleByReference pdA);

    /**
     *
     * @param lLSID
     * @param dX
     * @param dY
     * @param dZ
     * @param dA
     * @return
     */
    public int LSX_SetHwFactor (int lLSID, double dX, double dY, double dZ, double dA);

    /**
     *
     * @param lLSID
     * @param pdX
     * @param pdY
     * @param pdZ
     * @param pdA
     * @return
     */
    public int LSX_GetHwFactorB (int lLSID, DoubleByReference pdX, DoubleByReference pdY, DoubleByReference pdZ, DoubleByReference pdA);

    /**
     *
     * @param lLSID
     * @param dX
     * @param dY
     * @param dZ
     * @param dA
     * @return
     */
    public int LSX_SetHwFactorB (int lLSID, double dX, double dY, double dZ, double dA);

    /**
     *
     * @param lLSID
     * @param lIndex
     * @param pdDistance
     * @return
     */
    public int LSX_GetZwTravel (int lLSID, int lIndex, DoubleByReference pdDistance);

    /**
     *
     * @param lLSID
     * @param lIndex
     * @param dDistance
     * @return
     */
    public int LSX_SetZwTravel (int lLSID, int lIndex, double dDistance);

    /**
     *
     * @param lLSID
     * @param pbKey1
     * @param pbKey2
     * @param pbKey3
     * @param pbKey4
     * @return
     */
    public int LSX_GetKey (int lLSID, IntByReference pbKey1, IntByReference pbKey2, IntByReference pbKey3, IntByReference pbKey4);

    /**
     *
     * @param lLSID
     * @param pbKey1
     * @param pbKey2
     * @param pbKey3
     * @param pbKey4
     * @return
     */
    public int LSX_GetKeyLatch (int lLSID, IntByReference pbKey1, IntByReference pbKey2, IntByReference pbKey3, IntByReference pbKey4);

    /**
     *
     * @param lLSID
     * @param lKey
     * @return
     */
    public int LSX_ClearKeyLatch (int lLSID, int lKey);

    /**
     *
     * @param lLSID
     * @param plAValue
     * @return
     */
    public int LSX_GetBPZ (int lLSID, IntByReference plAValue);

    /**
     *
     * @param lLSID
     * @param lAValue
     * @return
     */
    public int LSX_SetBPZ (int lLSID, int lAValue);

    /**
     *
     * @param lLSID
     * @param lAPar
     * @param pdAValue
     * @return
     */
    public int LSX_GetBPZJoyspeed (int lLSID, int lAPar, DoubleByReference pdAValue);

    /**
     *
     * @param lLSID
     * @param lAPar
     * @param dAValue
     * @return
     */
    public int LSX_SetBPZJoyspeed (int lLSID, int lAPar, double dAValue);

    /**
     *
     * @param lLSID
     * @param pdX
     * @param pdY
     * @param pdZ
     * @param pdA
     * @return
     */
    public int LSX_GetBPZTrackballBackLash (int lLSID, DoubleByReference pdX, DoubleByReference pdY, DoubleByReference pdZ, DoubleByReference pdA);

    /**
     *
     * @param lLSID
     * @param dX
     * @param dY
     * @param dZ
     * @param dA
     * @return
     */
    public int LSX_SetBPZTrackballBackLash (int lLSID, double dX, double dY, double dZ, double dA);

    /**
     *
     * @param lLSID
     * @param pdAValue
     * @return
     */
    public int LSX_GetBPZTrackballFactor (int lLSID, DoubleByReference pdAValue);

    /**
     *
     * @param lLSID
     * @param dAValue
     * @return
     */
    public int LSX_SetBPZTrackballFactor (int lLSID, double dAValue);

    /**
     *
     * @param lLSID
     * @param plFlags
     * @return
     */
    public int LSX_GetAutoLimitAfterCalibRM (int lLSID, IntByReference plFlags);

    /**
     *
     * @param lLSID
     * @param lFlags
     * @return
     */
    public int LSX_SetAutoLimitAfterCalibRM (int lLSID, int lFlags);

    /**
     *
     * @param lLSID
     * @param lAxis
     * @param pdMinRange
     * @param pdMaxRange
     * @return
     */
    public int LSX_GetLimit (int lLSID, int lAxis, DoubleByReference pdMinRange, DoubleByReference pdMaxRange);

    /**
     *
     * @param lLSID
     * @param lAxis
     * @param dMinRange
     * @param dMaxRange
     * @return
     */
    public int LSX_SetLimit (int lLSID, int lAxis, double dMinRange, double dMaxRange);

    /**
     *
     * @param lLSID
     * @param lAxis
     * @param pbActive
     * @return
     */
    public int LSX_GetLimitControl (int lLSID, int lAxis, IntByReference pbActive);

    /**
     *
     * @param lLSID
     * @param lAxis
     * @param bActive
     * @return
     */
    public int LSX_SetLimitControl (int lLSID, int lAxis, boolean bActive);

    /**
     *
     * @param lLSID
     * @param plXA
     * @param plYA
     * @param plZA
     * @param plAA
     * @return
     */
    public int LSX_GetSwitchActive (int lLSID, IntByReference plXA, IntByReference plYA, IntByReference plZA, IntByReference plAA);

    /**
     *
     * @param lLSID
     * @param lXA
     * @param lYA
     * @param lZA
     * @param lAA
     * @return
     */
    public int LSX_SetSwitchActive (int lLSID, int lXA, int lYA, int lZA, int lAA);

    /**
     *
     * @param lLSID
     * @param plFlags
     * @return
     */
    public int LSX_GetSwitches (int lLSID, IntByReference plFlags);

    /**
     *
     * @param lLSID
     * @param plXP
     * @param plYP
     * @param plZP
     * @param plAP
     * @return
     */
    public int LSX_GetSwitchPolarity (int lLSID, IntByReference plXP, IntByReference plYP, IntByReference plZP, IntByReference plAP);

    /**
     *
     * @param lLSID
     * @param lXP
     * @param lYP
     * @param lZP
     * @param lAP
     * @return
     */
    public int LSX_SetSwitchPolarity (int lLSID, int lXP, int lYP, int lZP, int lAP);

    /**
     *
     * @param lLSID
     * @param plXP
     * @param plYP
     * @param plZP
     * @param plAP
     * @return
     */
    public int LSX_GetSwitchType (int lLSID, IntByReference plXP, IntByReference plYP, IntByReference plZP, IntByReference plAP);

    /**
     *
     * @param lLSID
     * @param lXP
     * @param lYP
     * @param lZP
     * @param lAP
     * @return
     */
    public int LSX_SetSwitchType (int lLSID, int lXP, int lYP, int lZP, int lAP);

    /**
     *
     * @param lLSID
     * @param lIndex
     * @param plValue
     * @return
     */
    public int LSX_GetAnalogInput (int lLSID, int lIndex, IntByReference plValue);

    /**
     *
     * @param lLSID
     * @param plValue
     * @return
     */
    public int LSX_GetDigitalInputs (int lLSID, IntByReference plValue);

    /**
     *
     * @param lLSID
     * @param plValue
     * @return
     */
    public int LSX_GetDigitalInputsE (int lLSID, IntByReference plValue);

    /**
     *
     * @param lLSID
     * @param lIndex
     * @param lValue
     * @return
     */
    public int LSX_SetAnalogOutput (int lLSID, int lIndex, int lValue);

    /**
     *
     * @param lLSID
     * @param lIndex
     * @param bFkt
     * @param dDist
     * @param lAxis
     * @return
     */
    public int LSX_SetDigIO_Distance (int lLSID, int lIndex, boolean bFkt, double dDist, int lAxis);

    /**
     *
     * @param lLSID
     * @param lIndex
     * @return
     */
    public int LSX_SetDigIO_EmergencyStop (int lLSID, int lIndex);

    /**
     *
     * @param lLSID
     * @param lIndex
     * @return
     */
    public int LSX_SetDigIO_Off (int lLSID, int lIndex);

    /**
     *
     * @param lLSID
     * @param lIndex
     * @param bHigh
     * @return
     */
    public int LSX_SetDigIO_Polarity (int lLSID, int lIndex, boolean bHigh);

    /**
     *
     * @param lLSID
     * @param lIndex
     * @param bValue
     * @return
     */
    public int LSX_SetDigitalOutput (int lLSID, int lIndex, boolean bValue);

    /**
     *
     * @param lLSID
     * @param lValue
     * @return
     */
    public int LSX_SetDigitalOutputs (int lLSID, int lValue);

    /**
     *
     * @param lLSID
     * @param lValue
     * @return
     */
    public int LSX_SetDigitalOutputsE (int lLSID, int lValue);

    /**
     *
     * @param lLSID
     * @param lAxis
     * @return
     */
    public int LSX_ClearEncoder (int lLSID, int lAxis);

    /**
     *
     * @param lLSID
     * @param pdXP
     * @param pdYP
     * @param pdZP
     * @param pdAP
     * @return
     */
    public int LSX_GetEncoder (int lLSID, DoubleByReference pdXP, DoubleByReference pdYP, DoubleByReference pdZP, DoubleByReference pdAP);

    /**
     *
     * @param lLSID
     * @param plFlags
     * @return
     */
    public int LSX_GetEncoderActive (int lLSID, IntByReference plFlags);

    /**
     *
     * @param lLSID
     * @param lFlags
     * @return
     */
    public int LSX_SetEncoderActive (int lLSID, int lFlags);

    /**
     *
     * @param lLSID
     * @param plFlags
     * @return
     */
    public int LSX_GetEncoderMask (int lLSID, IntByReference plFlags);

    /**
     *
     * @param lLSID
     * @param lValue
     * @return
     */
    public int LSX_SetEncoderMask (int lLSID, int lValue);

    /**
     *
     * @param lLSID
     * @param dX
     * @param pdY
     * @param pdZ
     * @param pdA
     * @return
     */
    public int LSX_GetEncoderPeriod (int lLSID, DoubleByReference dX, DoubleByReference pdY, DoubleByReference pdZ, DoubleByReference pdA);

    /**
     *
     * @param lLSID
     * @param dX
     * @param dY
     * @param dZ
     * @param dA
     * @return
     */
    public int LSX_SetEncoderPeriod (int lLSID, double dX, double dY, double dZ, double dA);

    /**
     *
     * @param lLSID
     * @param pbValue
     * @return
     */
    public int LSX_GetEncoderPosition (int lLSID, IntByReference pbValue);

    /**
     *
     * @param lLSID
     * @param bValue
     * @return
     */
    public int LSX_SetEncoderPosition (int lLSID, boolean bValue);

    /**
     *
     * @param lLSID
     * @param plXR
     * @param plYR
     * @param plZR
     * @param plAR
     * @return
     */
    public int LSX_GetEncoderRefSignal (int lLSID, IntByReference plXR, IntByReference plYR, IntByReference plZR, IntByReference plAR);

    /**
     *
     * @param lLSID
     * @param lXR
     * @param lYR
     * @param lZR
     * @param lAR
     * @return
     */
    public int LSX_SetEncoderRefSignal (int lLSID, int lXR, int lYR, int lZR, int lAR);

    /**
     *
     * @param lLSID
     * @return
     */
    public int LSX_ClearCtrFastMoveCounter (int lLSID);

    /**
     *
     * @param lLSID
     * @param plXC
     * @param plYC
     * @param plZC
     * @param plRC
     * @return
     */
    public int LSX_GetController (int lLSID, IntByReference plXC, IntByReference plYC, IntByReference plZC, IntByReference plRC);

    /**
     *
     * @param lLSID
     * @param lXC
     * @param lYC
     * @param lZC
     * @param lAC
     * @return
     */
    public int LSX_SetController (int lLSID, int lXC, int lYC, int lZC, int lAC);

    /**
     *
     * @param lLSID
     * @param plCtrCall
     * @return
     */
    public int LSX_GetControllerCall (int lLSID, IntByReference plCtrCall);

    /**
     *
     * @param lLSID
     * @param lCtrCall
     * @return
     */
    public int LSX_SetControllerCall (int lLSID, int lCtrCall);

    /**
     *
     * @param lLSID
     * @param pdX
     * @param pdY
     * @param pdZ
     * @param pdA
     * @return
     */
    public int LSX_GetControllerFactor (int lLSID, DoubleByReference pdX, DoubleByReference pdY, DoubleByReference pdZ, DoubleByReference pdA);

    /**
     *
     * @param lLSID
     * @param dX
     * @param dY
     * @param dZ
     * @param dA
     * @return
     */
    public int LSX_SetControllerFactor (int lLSID, double dX, double dY, double dZ, double dA);

    /**
     *
     * @param lLSID
     * @param pdX
     * @param pdY
     * @param pdZ
     * @param pdA
     * @return
     */
    public int LSX_GetControllerSteps (int lLSID, DoubleByReference pdX, DoubleByReference pdY, DoubleByReference pdZ, DoubleByReference pdA);

    /**
     *
     * @param lLSID
     * @param dX
     * @param dY
     * @param dZ
     * @param dA
     * @return
     */
    public int LSX_SetControllerSteps (int lLSID, double dX, double dY, double dZ, double dA);

    /**
     *
     * @param lLSID
     * @param plACtrTimeout
     * @return
     */
    public int LSX_GetControllerTimeout (int lLSID, IntByReference plACtrTimeout);

    /**
     *
     * @param lLSID
     * @param lACtrTimeout
     * @return
     */
    public int LSX_SetControllerTimeout (int lLSID, int lACtrTimeout);

    /**
     *
     * @param lLSID
     * @param plCtrTWDelay
     * @return
     */
    public int LSX_GetControllerTWDelay (int lLSID, IntByReference plCtrTWDelay);

    /**
     *
     * @param lLSID
     * @param lCtrTWDelay
     * @return
     */
    public int LSX_SetControllerTWDelay (int lLSID, int lCtrTWDelay);

    /**
     *
     * @param lLSID
     * @param pbActive
     * @return
     */
    public int LSX_GetCtrFastMove (int lLSID, IntByReference pbActive);

    /**
     *
     * @param lLSID
     * @param plXC
     * @param plYC
     * @param plZC
     * @param plAC
     * @return
     */
    public int LSX_GetCtrFastMoveCounter (int lLSID, IntByReference plXC, IntByReference plYC, IntByReference plZC, IntByReference plAC);

    /**
     *
     * @param lLSID
     * @param pdX
     * @param pdY
     * @param pdZ
     * @param pdA
     * @return
     */
    public int LSX_GetTargetWindow (int lLSID, DoubleByReference pdX, DoubleByReference pdY, DoubleByReference pdZ, DoubleByReference pdA);

    /**
     *
     * @param lLSID
     * @param dX
     * @param dY
     * @param dZ
     * @param dA
     * @return
     */
    public int LSX_SetTargetWindow (int lLSID, double dX, double dY, double dZ, double dA);

    /**
     *
     * @param lLSID
     * @return
     */
    public int LSX_SetCtrFastMoveOff (int lLSID);

    /**
     *
     * @param lLSID
     * @return
     */
    public int LSX_SetCtrFastMoveOn (int lLSID);

    /**
     *
     * @param lLSID
     * @param plValue
     * @return
     */
    public int LSX_GetTrigCount (int lLSID, IntByReference plValue);

    /**
     *
     * @param lLSID
     * @param lValue
     * @return
     */
    public int LSX_SetTrigCount (int lLSID, int lValue);

    /**
     *
     * @param lLSID
     * @param pbATrigger
     * @return
     */
    public int LSX_GetTrigger (int lLSID, IntByReference pbATrigger);

    /**
     *
     * @param lLSID
     * @param bATrigger
     * @return
     */
    public int LSX_SetTrigger (int lLSID, boolean bATrigger);

    /**
     *
     * @param lLSID
     * @param plAxis
     * @param plMode
     * @param plSignal
     * @param pdDistance
     * @return
     */
    public int LSX_GetTriggerPar (int lLSID, IntByReference plAxis, IntByReference plMode, IntByReference plSignal, DoubleByReference pdDistance);

    /**
     *
     * @param lLSID
     * @param lAxis
     * @param lMode
     * @param lSignal
     * @param dDistance
     * @return
     */
    public int LSX_SetTriggerPar (int lLSID, int lAxis, int lMode, int lSignal, double dDistance);

    /**
     *
     * @param lLSID
     * @param pbASnapshot
     * @return
     */
    public int LSX_GetSnapshot (int lLSID, IntByReference pbASnapshot);

    /**
     *
     * @param lLSID
     * @param bASnapshot
     * @return
     */
    public int LSX_SetSnapshot (int lLSID, boolean bASnapshot);

    /**
     *
     * @param lLSID
     * @param plSnsCount
     * @return
     */
    public int LSX_GetSnapshotCount (int lLSID, IntByReference plSnsCount);

    /**
     *
     * @param lLSID
     * @param plTime
     * @return
     */
    public int LSX_GetSnapshotFilter (int lLSID, IntByReference plTime);

    /**
     *
     * @param lLSID
     * @param lTime
     * @return
     */
    public int LSX_SetSnapshotFilter (int lLSID, int lTime);

    /**
     *
     * @param lLSID
     * @param pbHigh
     * @param pbAutoMode
     * @return
     */
    public int LSX_GetSnapshotPar (int lLSID, IntByReference pbHigh, IntByReference pbAutoMode);

    /**
     *
     * @param lLSID
     * @param bHigh
     * @param bAutoMode
     * @return
     */
    public int LSX_SetSnapshotPar (int lLSID, boolean bHigh, boolean bAutoMode);

    /**
     *
     * @param lLSID
     * @param pdX
     * @param pdY
     * @param pdZ
     * @param pdA
     * @return
     */
    public int LSX_GetSnapshotPos (int lLSID, DoubleByReference pdX, DoubleByReference pdY, DoubleByReference pdZ, DoubleByReference pdA);

    /**
     *
     * @param lLSID
     * @param lIndex
     * @param pdX
     * @param pdY
     * @param pdZ
     * @param pdA
     * @return
     */
    public int LSX_GetSnapshotPosArray (int lLSID, int lIndex, DoubleByReference pdX, DoubleByReference pdY, DoubleByReference pdZ, DoubleByReference pdA);  
}
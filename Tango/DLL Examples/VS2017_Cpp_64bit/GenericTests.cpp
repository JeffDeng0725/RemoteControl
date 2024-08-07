

#include "stdafx.h"
#include "Util.h"
#include "Distrib/Include/TangoLSX_API.h"
#include <iostream>

extern int g_LSID;

// you may modify this example function to proof actual Tango parameters against your expected values
void TestHWConfiguration()
{
  PRINTFUNC
  double dX, dY, dZ, dA;
  int    iX, iY, iZ, iA;
  int    iFlags;

  CHECK_EQUAL(LSX_SoftwareReset(g_LSID), 0);

  int bPower;
  CHECK_EQUAL(LSX_GetPowerAmplifier(g_LSID, &bPower), 0);
  CHECK_GT(bPower, 0);

  int bPol;
  CHECK_EQUAL(LSX_GetStopPolarity(g_LSID, &bPol), 0);
  CHECK_EQUAL(bPol, 0);


  //proof active axes
  CHECK_EQUAL(LSX_GetActiveAxes(g_LSID, &iFlags), 0);
  CHECK_GTE(iFlags, 3); //compare against 7 if Z is also available

  //proof spindle pitch
  CHECK_EQUAL(LSX_GetPitch(g_LSID, &dX, &dY, &dZ, &dA), 0);
  CHECK_CLOSE(dX, 1.0, 0.1);
  CHECK_CLOSE(dY, 1.0, 0.1);
  CHECK_CLOSE(dZ, 1.0, 0.1);

  //proof gear factor
  CHECK_EQUAL(LSX_GetGear(g_LSID, &dX, &dY, &dZ, &dA), 0);
  CHECK_EQUAL(dX, 1.0);
  CHECK_EQUAL(dY, 1.0);
  CHECK_EQUAL(dZ, 1.0);

  //proof motor current
  CHECK_EQUAL(LSX_GetMotorCurrent(g_LSID, &dX, &dY, &dZ, &dA), 0);
  CHECK_CLOSE(dX, 1.00, 0.1);
  CHECK_CLOSE(dY, 1.00, 0.1);
  CHECK_CLOSE(dZ, 1.25, 0.1);

  //proof current reduction
  CHECK_EQUAL(LSX_GetReduction(g_LSID, &dX, &dY, &dZ, &dA), 0);
  CHECK_EQUAL(dX, 1.0); // 1.0 means 100 percent
  CHECK_EQUAL(dY, 1.0);
  CHECK_EQUAL(dZ, 1.0);

  //proof current delay
  CHECK_EQUAL(LSX_GetCurrentDelay(g_LSID, &iX, &iY, &iZ, &iA), 0);
  CHECK_EQUAL(iX, 0);
  CHECK_EQUAL(iY, 0);
  CHECK_EQUAL(iZ, 0);

  //proof motor steps
  CHECK_EQUAL(LSX_GetMotorSteps(g_LSID, &iX, &iY, &iZ, &iA), 0);
  CHECK_EQUAL(iX, 200);
  CHECK_EQUAL(iY, 200);
  CHECK_EQUAL(iZ, 400);

  //proof velocity
  CHECK_EQUAL(LSX_GetVel(g_LSID, &dX, &dY, &dZ, &dA), 0);
  CHECK_CLOSE(dX, 20.0, 0.1);
  CHECK_CLOSE(dY, 20.0, 0.1);
  CHECK_CLOSE(dZ, 20.0, 0.1);


  //proof velfac
  CHECK_EQUAL(LSX_GetVelFac(g_LSID, &dX, &dY, &dZ, &dA), 0);
  CHECK_CLOSE(dX, 1.0, 0.01);
  CHECK_CLOSE(dY, 1.0, 0.01);
  CHECK_CLOSE(dZ, 1.0, 0.01);

  //proof accel
  CHECK_EQUAL(LSX_GetAccel(g_LSID, &dX, &dY, &dZ, &dA), 0);
  CHECK_CLOSE(dX, 0.2, 0.01);
  CHECK_CLOSE(dY, 0.2, 0.01);
  CHECK_CLOSE(dZ, 0.25, 0.01);

  //proof stop accel
  CHECK_EQUAL(LSX_GetStopAccel(g_LSID, &dX, &dY, &dZ, &dA), 0);
  CHECK_CLOSE(dX, 1.0, 0.01);
  CHECK_CLOSE(dY, 1.0, 0.01);
  CHECK_CLOSE(dZ, 1.0, 0.01);

  //proof AccelFunc
  CHECK_EQUAL(LSX_GetAccelFunc(g_LSID, &iX, &iY, &iZ, &iA), 0);
  CHECK_EQUAL(iX, 0);
  CHECK_EQUAL(iY, 0);
  CHECK_EQUAL(iZ, 0);


  //===================================
  // proof Z axis encoder preconditions
  //===================================
  //proof Z encoder period
  CHECK_EQUAL(LSX_GetEncoderPeriod(g_LSID, &dX, &dY, &dZ, &dA), 0);
  CHECK_CLOSE(dZ, 0.002,0.00001);
// do it after cal z
//  CHECK_EQUAL(LSX_GetEncoderMask(g_LSID, &iFlags), 0);
//  CHECK_GTE(iFlags, 2); // at least Z has to be enabled

  int iVal;
  CHECK_EQUAL(LSX_GetControllerCall(g_LSID, &iVal), 0);
  CHECK_EQUAL(iVal, 5);
  CHECK_EQUAL(LSX_GetControllerTimeout(g_LSID, &iVal), 0);
  CHECK_EQUAL(iVal, 1000);
  CHECK_EQUAL(LSX_GetControllerTWDelay(g_LSID, &iVal), 0);
  CHECK_EQUAL(iVal, 100); //100 ms
  CHECK_EQUAL(LSX_GetTargetWindow(g_LSID, &dX, &dY, &dZ, &dA), 0);
  CHECK_LTE(dZ, 0.2); // 0.2 mm

  //proof motor for polfilter axis
  // ...
}

void TestStageLimits()
{
  //proof software limits after calibration
  double dXmin, dXmax;
  double dYmin, dYmax;
  double dZmin, dZmax;
  enum { XX = 1, YY, ZZ, AA };
  CHECK_EQUAL(LSX_GetLimit(g_LSID, XX, &dXmin, &dXmax), 0);
  CHECK_EQUAL(LSX_GetLimit(g_LSID, YY, &dYmin, &dYmax), 0);
  CHECK_EQUAL(LSX_GetLimit(g_LSID, ZZ, &dZmin, &dZmax), 0);
  CHECK_EQUAL(dXmin, 0);
  CHECK_EQUAL(dYmin, 0);
//  CHECK_EQUAL(dZmin, 0);
//  CHECK_CLOSE(dXmax,  78, 1);
//  CHECK_CLOSE(dYmax, 199, 1);
//  CHECK_CLOSE(dZmax,  13, 1);


  //proof Z Encoder after calibration
  int iFlags = 0;
  CHECK_EQUAL(LSX_GetEncoderActive(g_LSID, &iFlags), 0);
  CHECK_EQUAL(iFlags, 4); //Z encoder must be valid, while XY encoder are not
}

void TestMaxSensoresPerTray()
{
  int iCols = 0;
  CHECK_EQUAL(LSX_GetNumberOfColumns(g_LSID, &iCols), 0);
  CHECK_EQUAL(iCols, 6);
}

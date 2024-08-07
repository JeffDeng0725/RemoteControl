// TangoUnitTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Distrib/include/TangoLSX_API.h"
#include "GenericTests.h"
#include "SelfCheck.h"
#include <iostream>
#include <string>
#include <filesystem>
#include <direct.h>

using std::cout; using std::cin;
using std::endl; using std::string;


int       g_LSID    = 0;
unsigned  g_uTotal  = 0;	// number of total tests
unsigned  g_uFailed = 0;  // number of failed tests

// Connection params
char* szCOM = ""; //no need to know if interface type is -1
int iBaudRate = 57600;

struct CmdLineArgs
{
  bool  bTestManualSystem = false;
};

bool ParseCmdLine( int argc, char** argv, CmdLineArgs& args )
{
  if( argc > 1 )
  {
    if( !strcmp( &argv[1][0], "manual" ) )
    {
      args.bTestManualSystem = true;
      return true;
    }
    else if( !strcmp( &argv[1][0], "loader" ) )
    {
      args.bTestManualSystem = false;
      return true;
    }
  }
  return false;
}

void PrintUsage( const char* exe )
{
  std::cout << "\n\nUsage:\n\n" << exe << " <manual|loader>\n" << std::endl;
}


int main( int argc, char* argv[] )
{
/*
  CmdLineArgs args;
  if( !ParseCmdLine( argc, argv, args ) )
  {
    PrintUsage( argv[0] );
    return 0;
  }
*/
  g_uTotal  = 0;
  g_uFailed = 0;

  int err;

  //  char pfad[256];
  //  _getcwd(pfad, 256); //der Programmpfad ist jetzt in 'pfad' gespeichert 
  //  cout << "Current working directory: " << pfad << endl;
  //  free(pfad);


  std::cout << "************** SELFCHECK **************" << std::endl;
  CALL_TESTFUNC( TestTimer );
  std::cout << "*********** SELFCHECK DONE ************\n\n" << std::endl;

/*
  std::cout << "special test: send ini file to Tango and send connect() ...\n" << std::endl;

  REQUIRE(LSX_CreateLSID(&g_LSID) == 0);
  char* pfad = "C:\\Users\\fdettmar\\Desktop\\ser4.ini";
  REQUIRE(LSX_LoadConfig(g_LSID, pfad) == 0);
  REQUIRE(LSX_Connect(g_LSID) == 0);
  REQUIRE(LSX_SetShowProt(g_LSID, TRUE) == 0);
  REQUIRE(LSX_SetLanguage(g_LSID, "germ") == 0);

  PrintDate();
  PrintVersionInfo();

  std::cout << "\nTOTAL:   " << g_uTotal << "\nSUCCESS: " << (g_uTotal - g_uFailed) << "\nERRORS:  " << g_uFailed << std::endl;
  PrintPreparations("---");
  return 0;
*/


// Example: Simple C++ connect of two TANGOs and permanent reset / reconnect test of the DLL
/*
int IdTangoXY=0,IdTango_Z=0;
int result1 = 0;
int result2 = 0;

char loc_text1[128]="";
char loc_text2[128]="";
char dll_text1[128]="";
char dll_text2[128]="";
char htext[128]    ="";

result1 = LSX_CreateLSID(&IdTangoXY);
result2 = LSX_CreateLSID(&IdTango_Z);

result1 = LSX_ConnectSimple(IdTangoXY, 1, "COM11", 57600, TRUE);//FALSE);
result2 = LSX_ConnectSimple(IdTango_Z, 1, "COM7" , 57600, TRUE);//FALSE);

int ii=0;
int results[10] = {0};
while ((result1|result2) == 0)
{
ii++;
	result1 |= results[0] = LSX_GetTangoVersion(IdTangoXY, loc_text1, sizeof(loc_text1)-1);
	result2 |= results[1] = LSX_GetTangoVersion(IdTango_Z, loc_text2, sizeof(loc_text2)-1);

	result1 |= results[2] = LSX_SendString(IdTangoXY, "!reset\r", NULL, 0, FALSE, 150); loc_text1[0] = loc_text2[0] = 0; //LSX_SoftwareReset(LSID1);  loc_text1[0] = loc_text2[0] = 0;

	result1 |= results[3] = LSX_GetTangoVersion(IdTangoXY, loc_text1, sizeof(loc_text1)-1);
	result2 |= results[4] = LSX_GetTangoVersion(IdTango_Z, loc_text2, sizeof(loc_text2)-1);

	result2 |= results[5] = LSX_SendString(IdTango_Z, "!reset\r", NULL, 0, FALSE, 150); loc_text1[0] = loc_text2[0] = 0; //result2 |= LSX_SoftwareReset(LSID2);  loc_text1[0] = loc_text2[0] = 0;

	result1 |= results[6] = LSX_GetTangoVersion(IdTangoXY, loc_text1, sizeof(loc_text1)-1);
	result2 |= results[7] = LSX_GetTangoVersion(IdTango_Z, loc_text2, sizeof(loc_text2)-1);

	result1 |= results[8] = LSX_SendString(IdTangoXY, "!reset\r", NULL, 0, FALSE, 150); loc_text1[0] = loc_text2[0] = 0;
	result2 |= results[9] = LSX_SendString(IdTango_Z, "!reset\r", NULL, 0, FALSE, 150); loc_text1[0] = loc_text2[0] = 0;

	LSX_GetDLLVersionString(IdTangoXY, dll_text1, sizeof(loc_text1)-1);
	LSX_GetDLLVersionString(IdTango_Z, dll_text2, sizeof(loc_text2)-1);

	if  ((result1|result2) == 0) sprintf_s(htext,"%03d = OK", ii);
	else                         sprintf_s(htext,"%03d = ERROR (result1 = %d, result2 = %d", ii, result1, result2);
	std::cout << htext << std::endl;
}

result1 = LSX_Disconnect(IdTangoXY);
result2 = LSX_Disconnect(IdTango_Z);

result1 = LSX_FreeLSID(IdTangoXY);
result2 = LSX_FreeLSID(IdTango_Z);

IdTangoXY = 0;
IdTango_Z = 0;

return 0;
*/



  std::cout << "Initializing TANGO ...\n" << std::endl;

  REQUIRE(LSX_CreateLSID(&g_LSID) == 0);
  err = LSX_ConnectSimple(g_LSID, -1, szCOM, iBaudRate, TRUE); //try USB (MASTER) at first
  CHECK_EQUAL(err, 0);
  if (err != 0) return 1;

  REQUIRE(LSX_SetShowProt(g_LSID, TRUE) == 0);
  REQUIRE(LSX_SetLanguage(g_LSID, "germ") == 0);


  PrintDate();
  PrintVersionInfo();


  std::cout << "********** STARTING SYSTEM TEST **********" << std::endl;
  CALL_TESTFUNC(TestHWConfiguration)
  REQUIRE(LSX_CalibrateEx(g_LSID, 4) == 0); // escape Z axis (if any and Z limit switch exist)
  REQUIRE(LSX_Calibrate(g_LSID) == 0);

  CALL_TESTFUNC(TestStageLimits);



  std::cout << "********************* UNITTEST DONE *********************" << std::endl;  
  LSX_Disconnect( g_LSID );
  std::cout << "\nTOTAL:   " << g_uTotal << "\nSUCCESS: " << (g_uTotal - g_uFailed) << "\nERRORS:  " << g_uFailed << std::endl;
  return 0;
}



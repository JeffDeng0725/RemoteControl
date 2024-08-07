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
#include "ProtocolDlg.h"

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


typedef enum
{
  E_OK  =0,       // 0    = OK
  E_4001=4001,    // 4001 = NULL Pointer an Funktion übergeben oder Dateifehler oder save Fehler (oder allgemeiner interner Fehler)
  E_4002,         // 4002 = Übergebener Parameter oder ASCII String außerhalb erlaubtem Bereich  (oder allgemeiner interner Fehler)
  E_4003,         // 4003 = Falsche LSID übergeben oder falsche Achsnummer                       (oder undefinierter Fehler)
  E_4004,         // 4004 = unbekannter Schnittstellentyp                                        (bei ConnectSimple, ConnectEx, Connect)
  E_4005,         // 4005 = Fehler beim Initialisieren der Schnittstelle                         (bei ConnectSimple, ConnectEx, Connect)
  E_4006,         // 4006 = Keine Verbindung zur Steuerung                                       (z.B. noch kein Connect aufgerufen)
  E_4007,         // 4007 = Timeout während Lesen von Schnittstelle                              (keine Rückmeldung der Steuerung)
  E_4008,         // 4008 = Fehler bei Befehlsübertragung an Tango
  E_4009,         // 4009 = Befehl wurde abgebrochen (mit SetAbortFlag)
  E_4010,         // 4010 = Befehl wird von Steuerung nicht unterstützt                          (aufgrund der Firmware-Version oder des Steuerungstyps)
  E_4011,         //(4011 = Joystick-Hand eingeschaltet (kann bei SetJoystickOn/Off auftreten)
  E_4012,         //(4012 = Kein Verfahrbefehl möglich, da Joystick-Hand (manueller Modus)
  E_4013,         // 4013 = Regler-Timeout (LStep DLL: Auch bei Timeout von CAL)
  E_4014,         // 4014 = Fehler beim Kalibrieren                                              (Endschalter nicht freigefahren, Timeout oder genereller Fehler)
  E_4015,         // 4015 = Endschalter in Verfahrrichtung betätigt
  E_4016,         // 4016 = Wiederholter Vektorstart                                             (Fahrbefehl nicht möglich, da Achse bereits fährt)

  // Fehlermeldungen entsprechend Tango ?err + 4100:
  // -----------------------------------------------
  E_4100=4100,    // 4100 = OK
  E_4101,         // 4101 = Keine gültige Achsbezeichnung
  E_4102,         // 4102 = Keine ausführbare Funktion
  E_4103,         // 4103 = Zu viele Zeichen in Befehlsstring
  E_4104,         // 4104 = Kein gültiger Befehl
  E_4105,         // 4105 = Außerhalb des gültigen Zahlenbereiches
  E_4106,         // 4106 = Falsche Anzahl der Parameter
  E_4107,         // 4107 = Kein ! oder ?
  E_4108,         // 4108 = Kein TVR möglich, da Achse aktiv
  E_4109,         // 4109 = Kein Ein- oder Ausschalten der Achsen, da TVR aktiv
  E_4110,         // 4110 = Funktion nicht konfiguriert
  E_4111,         // 4111 = Kein Move-Befehl möglich, da Joystick-Hand
  E_4112,         // 4112 = Endschalter betätigt
  E_4113,         // 4113 = Funktion kann nicht ausgeführt werden, da Geber erkannt
  E_4114,         // 4114 = Fehler beim Kalibrieren (Endschalter nicht korrekt freigefahren)
  E_4115,         // 4115 = Gegenüberliegender Endschalter betätigt (bei CAL oder RM)

  E_4120=4120,    // 4120 = Treiberrelais defekt
  E_4121,         // 4121 = Es dürfen nur einzelne Vektoren gefahren werden
  E_4122,         // 4122 = Tür offen oder Einrichtbetrieb
  E_4123,         // 4123 = SECURITY Error X-Achse
  E_4124,         // 4124 = SECURITY Error Y-Achse
  E_4125,         // 4125 = SECURITY Error Z-Achse
  E_4126,         // 4126 = SECURITY Error A-Achse
  E_4127,         // 4127 = Stop aktiv
  E_4128,         // 4128 = Fehler im Türsicherheitskreis
  E_4129,         // 4129 = Endstufen nicht eingeschaltet
  E_4130,         // 4130 = GAL Sicherheitsfehler
  E_4131,         // 4131 = Joystick lässt sich nicht einschalten, da Move aktiv

} AnErrorTyp;

typedef enum
{
  AUTO_CONNECT=-1,/*-1 = Auto Connect USB oder PCI TANGO  */
  UNDEFINED   = 0,
  RS232       = 1,/* 1 = RS232 / USB-VCP                  */
  ArcNet,         /* 2 = ArcNet                           */
  DPRAM,          /* 3 = DualPort RAM                     */
  PCI,            /* 4 = PCI Karte                        */
  BOOT_CONNECT,   /* 5 = Bootloader Connect ohne Abfragen */
  ETHERNET,       /* 6 = Ethernet                         */
  MAX_IFCTYP
} AnInterfaceTyp;


enum
{
  WM_RECEIVED = 0x8000,	// Eigene Message-Identifier ab Message 0x8000
  WM_SENT     = 0x8001
};

enum {
	XX = 0,
	YY,
	ZZ,
	AA,
	AXES
};

// Read-Timeout for ReadCom() in [ms]
#define STD_RX_TIMEOUT_VAL      1500
#define WAIT_AFTER_RESET_MS     3000 // Max. Wartezeit, bis der Port wieder im System verfügbar ist (bei 4x 499 Messpunkten Korrektur im ETS dauert dies etwas mehr als 2 Sekunden, deshalb von 2000 --> 3000 geändert 20.11.2023, ML/MST)
#define WAIT_AFTER_RESET_MS_ETH 7500 // Bei Ethernet muss länger gewartet werden, da die Initialisierung des Ethernets in der TANGO alleine schon >=2s dauert, Messung am 28.07.2023: Über 6 Sekunden bis erfolgreicher Reconnect (des Interfaces, noch nicht der TANGO selbst. Diese ist bis dahin aber schon gebootet, anders als bei USB oder RS232, wo man nach Connect noch auf den Parser warten muss)


#define DEFAULT_PORT "23" // Ethernet: TCP/IP Port 23

//consider long strings like "\\.\COM100" or "192.168.100.120"
#define PORTTEXT_SIZE 16

// LSX
#define MAXHANDLE 8



// DLL / controller state
typedef struct
{
	char NumOfAxes;
	int  AutoStatus;
	BOOL bEncPosState;
	char ComName[PORTTEXT_SIZE]; // Feldgröße > 8 wegen \\.\COMnnn und IPV4 (xxx.xxx.xxx.xxx)
	long BaudRate;
	BOOL fAbort;
	BOOL bEcoStep;
	AnInterfaceTyp  Interface;

} DLL_STATE_STRUCT;




// INI DATEI
// ================================================
typedef struct {

	double FileVersion;
	int    Language;
	BOOL   UseColor;
	int	   CsvFormat;
	int    Dialog;
	BOOL   ShowEncPos;

	BOOL   bShowErrorProtocol;

	int    WinFlags;
	int    WinShow;
	int    WinLeft;
	int    WinRight;
	int    WinTop;
	int    WinBottom;

	BOOL   bServiceMode;

} STRUCT_COMMON;

typedef struct {

	int    Active;
	int    Dimension;
	double Gear;
	double Pitch;
	int    AxisDirection;

	int    Autostatus;

	double MotorCurrent;
	int    CurrentReduction;
	int    CurDelay;
	int    MotorSteps;
	int    MotorTable;
	double MaxCurInfo;

	double VMax;
	double AMax;

	double Vel;
	double SecVel;
	double Accel;
	double StopAccel;
	int    AccelFunc;

	int    ScanMode;
	double ScanVel;

	int    JoystickMode;
	int    JoystickDir;
	int    JoyWindow;
	int    JoyCurve;
	int    JoyChangeAxis;
	double JoyVel;
	double KeySpeed[3];
	int    HwFilter;
	double HwFactor;
	double HwFactorB;
	double TbFactor;
	int    HdiMode;

	BOOL   NoSetLimit;
	int    SoftLimit;
	double LimitMin;
	double LimitMax;
	int    LimitSw0Type;
	int    LimitSw0Active;
	int    LimitSw0Polarity;
	int    DummyLimitSwRefType;
	int    DummyLimitSwRefActive;
	int    DummyLimitSwRefPolarity;
	int    LimitSwEndType;
	int    LimitSwEndActive;
	int    LimitSwEndPolarity;
	int    LimitSwDirection;
	int    CalMode;
	int    ExtMode;
	int    CalRequired;
	int    CalDirection;
	double CalibOffset;
	double RmOffset;
	double CalBSpeed;
	double CalVel1;
	double CalVel2;
	double RmVel1;
	double RmVel2;
	int    CalTimeout;

	int    Encoder;
	int    EncType;
	int    EncDir;
	int    EncNas;
	int    EncoderRefSignal;
	int    EncoderRefDir;
	double EncoderRefSpeed;
	double EncoderPeriod;
	double EncVel;

	double TargetWindow;
	int    ControllerMode;
	double ControllerFactor1;
	double ControllerFactor2;
	double ControllerSteps;
	int    ControllerTWDelay;
	int    ControllerTimeout;
	int    ControllerCall;
	int    CtrSM;

	double BackLash;
	double AngleCorr;

	int    ModuloMode;
	int    EcoMove;

	int    Brake;

} STRUCT_AXIS_SETUP;

#pragma pack() 
typedef struct {

	int      TrigA;			// Achse x,y,z,a
	double   TrigF;			// Frequenz
	double   TrigD;			// Distanz
	long int TrigS;			// Signal Breite
	int      TrigM;			// Modus
	long int SecondDelay;	// Im 1:1 Modus: Verzögerung für zweites Triggersignal
	long int SecondWidth;	// Im 1:1 Modus: Pulsweite für zweites Triggersignal
	int      Output;		// Trigger Ausgang
	int      TrigComp;		// Trigger geschwindigkeitsabhängige Kompensation [µs]
	double   TrigBwidth;	// 2. Triggerausgang: Präzise Pulsbreite
	double   TrigBdelay;	// 2. Triggerausgang: Präzise Verzögerung
	double   TrigBf;		// 2. Triggerausgang: Präzise Frequenz
	BOOL	 Trig;			// An/Aus
	BOOL	 Encoder;		// Trigger auf Gebersignal
	int      TrigPol;		// Polarität für spezielle Trigger Modi

} STRUCT_TRIGGER_SETUP;

typedef struct {

	int      Mode;		// snsm
	BOOL     Level;		// snsl
	int      Filter;	// snsf
	int      Counter;	// snsc
	int      Enable;	// sns

	double   Prehome[AXES];
	double   Home[AXES];

} STRUCT_SNAPSHOT_SETUP;

typedef struct {

	int StOut;
	int StopPol;
	int NoLed;
	int IoCardPuPd;
	int ADigInTyp[4];
	int ADigInFunc[4];

} STRUCT_DLG_IO_SETUP;

typedef struct {

	int Typ;
	int InPol;
	int OutPreset;

} STRUCT_DLG_IOCARD_SETUP;

typedef struct {

	char ComName[PORTTEXT_SIZE];
	int  BaudRate;
	BOOL AutoConnect;
	BOOL ScanEts;
	BOOL SendPars;
	BOOL ShowProt;
	int  Type;
	BOOL OldComDetectMethod;

} STRUCT_CONNECT;

typedef struct {

	int KeyMode;
	double ZwTravel[3];
	char   ZwAxis;
	double ButtonSpeed[4];

} STRUCT_DLG_HDI;

typedef struct {

	BOOL   Ena[AXES];
	BOOL   CurJoyKeys;
	BOOL   CurJoyType;
	int    AnyKey;
	double CurJoyStep[AXES];
	double CurJoySpeed[AXES];
	int    CalibStep[4];
	int    RmStep[4];
	double HomePos[AXES];
	double VCal[AXES];
	double ACal[AXES];

	BOOL bUseCalVelAccelSettings;
	BOOL bUseCalRmVel;
	BOOL bUseCalRmAccel;


} STRUCT_DLG1;

typedef struct {

	BOOL ProtCommands;
	int Timeout;

} STRUCT_DLG3;

typedef struct {

	int    OptionInput;
	int    OptionOutput;
	BOOL   IoInPol;
	BOOL   Edge;
	int    Keyboard;
	int    HdiKey;
	int    AuxIoIn;
	BOOL   bPosList;

} STRUCT_TMP_IO_OPTIONS;

// ================================================
// fControllerType (interne Unterscheidung)
// -----------------------------------
#define TYPE_UNKNOWN        0x00000000

#define TYPE_LSTEP          0x00000001	// Blackfin basierte TANGOs
#define TYPE_SMST           0x00000002
#define TYPE_PCIE           0x00000004
#define TYPE_TANGO_C        0x00000008
#define TYPE_TANGO_I        0x00000010
#define TYPE_TM3            0x00000020
#define TYPE_POLLUX         0x00000040
#define TYPE_SFX            0x00000080
//                          ----------
#define TYPE_MASK_BLACKFIN	0x000000FF	// Generell: "alte" Blackfin basierte TANGOs (fControllerType & TYPE_MASK_BLACKFIN)

#define TYPE_ANJA           0x00000100	// STM32H7 basierte TANGO Desktop HE (2HE, 3HE)
#define TYPE_TANGO_I2       0x00000200	// STM32H7 basierte TANGO Integrale 2
#define TYPE_TANGO_PCIE21   0x00000400  // STM32H7 basierte TANGO PCI-E
#define TYPE_TM3_22         0x00000800  // STM32H7 basierte TANGO 3 mini
//                          0x00001000
//                          0x00002000
//                          0x00004000
#define TYPE_UNKNOWN_TANGO  0x00008000	// Der DLL noch nicht bekannte TANGO Steuerung

#define TYPEBIT_TM2         0x00100000	// Zus. Typ-Bits für erweiterte Typen "basierend auf", siehe unten
#define TYPEBIT_EINSTEIN    0x00200000
#define TYPEBIT_SMC2009     0x00400000
//                          0x00800000

#define TYPEBIT_SE          0x01000000
#define TYPEBIT_TE          0x02000000
#define TYPEBIT_HB          0x04000000
#define TYPEBIT_CLYDE       0x08000000	// Desktop 3HE basiertes Handling-System
//                          0x10000000
//                          0x20000000
//                          0x40000000
//                          0x80000000
// -----------------------------------
#define TYPE_TANGO_MINI         (TYPE_TANGO_C | TYPEBIT_TM2               )	// Erweiterte Typen
#define TYPE_EINSTEIN           (TYPE_TANGO_C | TYPEBIT_EINSTEIN          )
#define TYPE_SMC2009            (TYPE_PCIE    | TYPEBIT_SMC2009           )

#define TYPE_CASTOR_LOADER      (TYPE_TANGO_I | TYPEBIT_SE                )
#define TYPE_SLIDEEXPRESS       (TYPE_PCIE    | TYPEBIT_SE                )
#define TYPE_TRAYEXPRESS        (TYPE_PCIE    | TYPEBIT_SE | TYPEBIT_TE   )
#define TYPE_HAYA               (TYPE_PCIE    | TYPEBIT_SE | TYPEBIT_HB   )
#define TYPE_CLYDE              (TYPE_ANJA    | TYPEBIT_SE | TYPEBIT_CLYDE)
#define TYPE_ANJA_SLIDEEXPRESS  (TYPE_ANJA    | TYPEBIT_SE                )
#define TYPE_ANJA_HAYA          (TYPE_ANJA    | TYPEBIT_SE | TYPEBIT_HB   )
// -----------------------------------

/* Tango Versionen */
// -------------------------------
#define VERSION_ETS                   (double)1.347    /* Tango Version, ab der ETS unterstützt wird    */
#define VERSION_ETS_SMC2009           (double)1.464    /* Zusätzliche Option Struct CZ im ETS + Befehle */
#define VERSION_ETS_TANGO_C           (double)1.508    /* Korrekturfunktion */
#define VERSION_ETS_OPT_T_C           (double)1.527    /* SMC2009 Optionswerte */
#define VERSION_ETS_SLIDEEXPRESS      (double)1.569989 /* Tango PCI-E mit SlideExpress Option */
#define VERSION_TANGO_I_CASTOR_LOADER (double)1.649    /* Tango-I mit SlideExpress Funktionalität für CZ Castor Loader, wichtig: ab ca. 3/2015 */
#define VERSION_2D_CORR               (double)1.725999 /* 2D Korrektur muss über ?parstruct, zweite Struktur, eingelesen werden 27.03.2020 ML */
// -------------------------------
#define HDIMODE_KEYTGL_EGD  0x0001 /* ErgoDrive Tasten im Toggle Modus */
#define HDIMODE_KEYTGL_JOY  0x0002 /* Joystick Taste F1 toggle im KEYMODE anstelle F1/F4 */
#define HDIMODE_LED_BRIGHT  0x0004 /* Joystick Taste F2 für LED100 Helligkeit über Handrad */
//#define HDIMODE_          0x0008
//#define HDIMODE_          0x0010
//...     HDIMODE_          0x8000
// -------------------------------

enum
{
	UNIT_USTEP = 0, //  0
	UNIT_UM,        //  1
	UNIT_MM,        //  2
	UNIT_DEG,       //  3
	UNIT_REV,       //  4
	UNIT_CM,        //  5
	UNIT_M,         //  6
	UNIT_INCH,      //  7
	UNIT_MIL,       //  8
	UNIT_MM_V,      //  9
	UNIT_UM_V,      // 10

	UNIT_TYPES      // 11 Typen
};

#define AUTOSTATUS_MIN     0
#define AUTOSTATUS_MAX     5 // Future Use: 5


/////////////////////////////////////////////////////////////////////////////
// CTango_DLLApp
// Siehe Tango_DLL.cpp für die Implementierung dieser Klasse
//

class CTango_DLLApp : public CWinApp
{

int           read_retry   = 3;

HANDLE        hCom         = NULL;
OVERLAPPED    ovRead       = {0};
CProtocolDlg *pProtocols   = NULL;
BOOL          bProtShown   = FALSE;

BOOL          bIgnoreNoParErrors = FALSE;

DWORD         pdwThreadId  = NULL;



DLL_STATE_STRUCT DllState;

TLS_ControlInitPar ControlInitPar = {0};

char DLLComName[PORTTEXT_SIZE]      = "";
char RescuedPortName[PORTTEXT_SIZE] = "";
int  RescuedBaud          = 57600;
int  RescuedInterfaceType = RS232;
int  GlobalSetComResult   = E_OK;	// ConnectSimple: Nur zur Übergabe detaillierter Fehlernummern durch SetCom() bei ConnectSimple (). SetCom() gibt historisch bedingt nur TRUE/FALSE zurück, das wird durch diese globale Variable erweitert.

BOOL bWriteLogText        = FALSE;

BOOL fReadFunctionRunning = FALSE;
BOOL fWaiting             = FALSE;	// reicht ggf. nicht, falls eine ID z.B. Cal & Rm parallel startet (geht sowas überhaupt?)
BOOL bIgnoreWaiting       = FALSE;	// a\r Abort Kommando
int TangoConnectState     = 0;	// Globales ConnectSimple Ergebnis: 0 = nicht verbunden, 1=verbunden, 2=verbunden und TANGO Konfiguration ausgelesen

// wait loop timeouts in ms
int  TimeoutRead    =   1000;	// [ms] Wird für Handlingsystem-Funktionen "?err" Abfrage per SendString teilweise als Timeout verwendet
int  TimeoutMove    = 600000;	// [ms] 10 Minuten = unkonfiguriert deutlich höher als der TANGO-interne Default-Wert (60s)
int  TimeoutCal     = 900000;	// [ms] 15 Minuten = unkonfiguriert deutlich höher als der TANGO-interne Default-Wert (90s bzw. 60s) 
int  ReadTimeoutMs  = STD_RX_TIMEOUT_VAL;	// 1.5s (spiegelt das aktuell eingestellte Timeout wieder)
BOOL bHideEtsC      = FALSE;
BOOL bDisconnecting = FALSE; // Soll verhindern, dass beim Disconnect eine Lücke entsteht, während der COM Port noch in der DLL getrennt wird (hCom noch einen gültigen Wert hat, der Port jedoch weg ist) Jedoch wird Disconnect erst nach Verlassen eines Funktionsaufrufs ausgeführt, unterbricht diesen nicht --> wirkt nicht wie gewünscht innerhalb einer Funktion (06.04.2021 ML)
BOOL bConnecting    = FALSE; // Soll verhindern, dass beim Connect eine Lücke entsteht, während der COM Port noch in der DLL verbunden wird (hCom schon einen gültigen Wert hat, der Port jedoch noch nicht vollständig initialisiert ist)
time_t DLL_IgnoreDisconnect = 0;	// Ignorieren eines Reset-Bedingten Disconnect/Reconnect nach bereits erfolgreich durchgeführten HandleSoftwareReset() --> Ist der Fall bei z.B. STM32-basierten TANGOs, da USB im µC integriert ist


char intext[256]  = "";
char outtext[256] = "";
char sendtext[256]= "";	// Für DLL_SendString(), SendDoubleCmd() usw., da sonst unter VS2010 der Bezug des char Feldes verloren geht (muss static sein, nicht lokal)

const char AxisStr[5]      = { ' ','x','y','z','a' };	// Für Sammelbefehle inklusive ' ' bei axis=-1
const char CapAxChar[AXES] = {     'X','Y','Z','A' };	// Für 0=XX-->X,1=YY-->Y (im Text)
const char AxChar[AXES]    = {     'x','y','z','a' };	// Für 0=XX-->x,1=YY-->y (bei Befehlen)

int    Language       = 0;   // English
double TangoVersion   = 1.0; // allow different TANGO versions at different connections

int LedBrightClockInt = 0;
int LedBrightChars    = 0;

// Ethernet
WSADATA wsaData;                        // structure contains information about the Windows Sockets implementation
SOCKET  ConnectSocket = INVALID_SOCKET; //Create a SOCKET object called ConnectSocket.




STRUCT_COMMON            Common;
STRUCT_CONNECT           Connect;
STRUCT_AXIS_SETUP        AxisSetup[AXES];
STRUCT_TRIGGER_SETUP     TriggerSetup;
STRUCT_SNAPSHOT_SETUP    SnapshotSetup;
STRUCT_DLG_HDI           DlgHdiStruct;
STRUCT_DLG_IO_SETUP      DlgIoSetup = { 0 };
STRUCT_DLG_IOCARD_SETUP  DlgIoCardSetup[2] = { 0 };

STRUCT_DLG1              Dlg1Struct;
STRUCT_DLG3              Dlg3Struct;
STRUCT_TMP_IO_OPTIONS    TmpIoOptions;

int EtsMode   = 4;
int MoveDelay = 0;
int MovePause = 0;
int uSteps    = 819200;
int RealEncType[AXES] = { 0 };

int  TangoAchszahl    = 3;
int  TangoGeber       = 0;
BOOL bTangoTrigger    = FALSE;
BOOL bTangoSnapshot   = FALSE;
BOOL bConfigEncoder   = FALSE;
BOOL bTangoIoCard1    = FALSE;
BOOL bTangoIoCard2    = FALSE;
BOOL bEtsAvailable    = FALSE;
BOOL bUniversalEncoder= FALSE;
BOOL bZOnly           = FALSE;
int  fControllerType  = TYPE_UNKNOWN;

BOOL bIniLoaded       = FALSE;
BOOL bPureTextMode    = FALSE;

BOOL bSyncZA = FALSE;
BOOL bSwapZA = FALSE;

int DimResolution[UNIT_TYPES] = {0};

const int DimResolutionDefaults[UNIT_TYPES] =
{
	0,	// dim0 -> µsteps
	1,	// dim1 -> µm
	4,	// dim2 -> mm
	2,	// dim3 -> Grad
	3,	// dim4 -> U
	5,	// dim5 -> cm
	7,	// dim6 -> m
	5,	// dim7 -> Zoll
	4,	// dim8 -> mil
	4,	// dim9 -> mm_v (mst: calbspeed, vel, joyvel, speed ebenfalls in mm/s, 31.08.2007)
	1,	// dim10-> um_v (mst: calbspeed, vel, joyvel, speed in mm/s, 2021)
};

public:
	CTango_DLLApp();
	BOOL InitInstance();
	int ExitInstance();
// ================================================
void InitStructures(void);
void SetDefaultTrigger(void);
void SetDefaultSnapshot(void);
void SetDefaultAxis(int axis);

BOOL ReadIniFile(BOOL bParseWinComIni, char *cFileName);//, BOOL bIgnoreSwBSettings);
BOOL ParseSwitchBoardIni(char *cVarName, char *cVal, int *heading, int *mode);//, BOOL bIgnoreSwBSettings);
BOOL ParseWinComIni(char *cVarName, char *cVal, int *heading, int *mode);//, BOOL bIgnoreSwBSettings);
BOOL Receive16Bits(char *buffer, int *i_val);
BOOL SendTangoTrigger(BOOL bSave);
BOOL SendTangoSnapshot(BOOL bSave);
int  SetSwitch(const char* swcmd, int lXP, int lYP, int lZP, int lAP);
int  ReadIntegerCmd (char *pStr, int *plX, int *plY, int *plZ, int *plR);
int  Reconnect (BOOL bHandleSoftwareReset);
int  SendSetupToController(void);
int  GetTangoError(char* cCommandText);
BOOL ReadTangoTrigger(void);
BOOL ReadTriggerCounter(void);
BOOL ReadTrigger(void);
BOOL ReadTangoSnapshot(void);
BOOL ReadSetupFromController(void);
BOOL GetControllerSetup(int FromAxis, int ToAxis, BOOL bReadEts);
BOOL AddDlgListString(int axis, char *cCommandText);
int  SendDoubleValue(double value, char *command, int precision);
double Round(double Zahl, int Stellen);
double AsciiToFloat(char *ctext);
unsigned long AsciiToULong(char *ctext);
long int AsciiToLong(char *ctext);
int AsciiToInt(char *ctext);
int AsciiToHex(char *ctext);
BOOL ParseIni(char *cVarName, char *cVal, int *mode);
// ================================================

void swapi(int& i, int& j);
void swapd(double& i, double& j);
void ErrorLog(CString errtext);
void CreateProtocol (BOOL bCreate);
void ShowProtocol (BOOL bShow);
void AbortCleanup (void);
void ModifyCommTimeout (int Timeout);
void CloseCom (void);
int ConnectEthernet(char *ComName, int Timeout);
int ConnectSerial (char *ComName, long baud, int Timeout);
BOOL SetCom (char *ComName, long baud, int Timeout);
int ReadLineEthernet (char *buffer, int buffer_size);
int ReadCom (char *buffer, int buffer_size);
int WriteEthernet (char *buffer);
int WriteCom (char *buffer);
int CheckAutoStatus (void);
void ResetDllState (void);
int RetrieveTangoState (BOOL bForceAutoStatus);
BOOL ManipulateAutoStatus (BOOL bWait);
int WaitBlockingCommand (int Timeout_ms);
int SendDoubleCmdSingleAxis (char *Command, int lAxis, double dValue);
int Xpos3_SendDoubleCmdSingleAxis(char *Command, int lAxis, double dValue);
int SendDoubleCmd (char *Command, double dX, double dY, double dZ, double dA, int lAxCount);
int SendIntegerCmd (char *Command, int iX, int iY, int iZ, int iA, int lAxCount);
int SendFlagCmd (char *Command, int lFlags, int lAxCount);
int WaitForMove (void);
int WaitForMoveSingleAxis (int lAxis);
void AddListRetryInfo (void);
void StringToUpper(char *loc_text);
int ExtractControllerType (char *pbuffer);
void GetTangoVersion (void);

int DLL_ConnectSimple (int lAnInterfaceType, char *pcAComName, int lABaudRate, BOOL bAShowProt);
int DLL_ConnectEx (TLS_ControlInitPar *pAControlInitPar);
int DLL_Connect (void);
int DLL_Disconnect (void);
int DLL_DisconnectPort(CString aPort);
int DLL_ReconnectPort(CString aPort);
int DLL_GetDLLVersionString (char *pcVers, int lMaxLen);
int DLL_LoadConfig (char *pcFileName);
int DLL_SaveConfig (char *pcFileName);
int DLL_ReadControlPars (void);
int DLL_SetCtrlPars (void);
int DLL_SetActiveAxes (int lFlags);
int DLL_GetActiveAxes (int *plFlags);
int DLL_MoveAbs (double dX, double dY, double dZ, double dA, BOOL bWait);
int DLL_MoveAbsSingleAxis (int lAxis, double dValue, BOOL bWait);
int DLL_MoveRel (double dX, double dY, double dZ, double dA, BOOL bWait);
int DLL_MoveRelSingleAxis (int lAxis, double dValue, BOOL bWait);
int DLL_MoveEx (double dX, double dY, double dZ, double dA, BOOL bRelative, BOOL bWait, int lAxisCount);
int DLL_Go (double dX, double dY, double dZ, double dA);
int DLL_GoSingleAxis (int lAxis, double dValue);
int DLL_GoEx (double dX, double dY, double dZ, double dA, int lAxisCount);
int DLL_Calibrate (void);
int DLL_CalibrateEx (int lFlags);
int DLL_RMeasure (void);
int DLL_RMeasureEx (int lFlags);
int DLL_SetPitch (double dX, double dY, double dZ, double dA);
int DLL_SetPos (double dX, double dY, double dZ, double dA);
int DLL_SetVel (double dX, double dY, double dZ, double dA);
int DLL_SetVelSingleAxis (int lAxis, double dVel);
int DLL_SetSecVel (double dX, double dY, double dZ, double dA);
int DLL_SetSecVelSingleAxis (int lAxis, double dVel);
int DLL_SetAccel (double dX, double dY, double dZ, double dA);
int DLL_SetAccelSingleAxis (int lAxis, double dAccel);
int DLL_GetAccel (double *pdX, double *pdY, double *pdZ, double *pdA);
int DLL_SetReduction (double dX, double dY, double dZ, double dA);
int DLL_SetDelay (int lDelay);
int DLL_SetSwitchPolarity (int lXP, int lYP, int lZP, int lAP);
int DLL_SetSwitchType(int lXP, int lYP, int lZP, int lAP);
int DLL_SetSwitchActive (int lXA, int lYA, int lZA, int lAA);
int DLL_SetJoystickOn (BOOL bPositionCount, BOOL bEncoder);
int DLL_SetJoystickOff (void);
int DLL_SoftwareReset (void);
int DLL_SetAuxDigitalOutput (int lIndex, BOOL bValue);
int DLL_GetAuxDigitalInput (int lIndex, BOOL *bValue);
int DLL_GetDigitalInputs (int *plValue);
int DLL_SetDigitalOutput (int lIndex, BOOL bValue);
int DLL_SetDigitalOutputs (int lValue);
int DLL_SetDigitalOutputE (int lIndex, BOOL bValue);
int DLL_SetDigitalOutputsE (int lValue);
int DLL_GetDigitalInputsE (int *plValue);
int DLL_SetAnalogOutput (int lIndex, int lValue);
int DLL_SetAnalogOutputMode(int lValue);
int DLL_GetAnalogOutputMode(int *plValue);
int DLL_SetLedBright(double dBright);
int DLL_GetAnalogInput (int lIndex, int *plValue);
int DLL_SetSmHdiButton (int lButtonNr, char *pcFunction);
int DLL_GetSmHdiButton (int lButtonNr, char *pcFunction, int lMaxLen);
int DLL_SetHdiSpeedIndex (int lX, int lY, int lZ, int lA);
int DLL_GetHdiSpeedIndex (int *plX, int *plY, int *plZ, int *plA);
int DLL_SetHdiSpeedIndexSingleAxis (int lAxis, int lIndex);
int DLL_GetHdiSpeedIndexSingleAxis (int lAxis, int *plIndex);
int DLL_SetHwFactor (double dX, double dY, double dZ, double dA);
int DLL_SetHwFactorB (double dX, double dY, double dZ, double dA);
int DLL_GetHwFactor (double *pdX, double *pdY, double *pdZ, double *pdA);
int DLL_GetHwFactorB (double *pdX, double *pdY, double *pdZ, double *pdA);
int DLL_SetHwFactorSingleAxis (int lAxis, double dFactor);
int DLL_SetHwFactorBSingleAxis (int lAxis, double dFactorB);
int DLL_GetHwFactorSingleAxis (int lAxis, double *pdFactor);
int DLL_GetHwFactorBSingleAxis (int lAxis, double *pdFactorB);
int DLL_GetAnalogInputs2 (int *plPT100, int *plMV, int *plV24);
int DLL_SetLimit (int lAxis, double dMinRange, double dMaxRange);
int DLL_SetLimitControl (int lAxis, BOOL bActive);
int DLL_GetPos (double *pdX, double *pdY, double *pdZ, double *pdA);
int DLL_GetStatus (char *pcStat, int lMaxLen);
int DLL_IsVel (double *pdX, double *pdY, double *pdZ, double *pdA);
int DLL_IsVelSingleAxis (int lAxis, double *pdVel);
int DLL_GetEncoderMask (int *plFlags);
int DLL_StopAxes (void);
int DLL_StopAxesEx (int lFlags);
int DLL_SetAbortFlag (void);
int DLL_SetControlPars (void);
int DLL_SetMotorCurrent (double dX, double dY, double dZ, double dA);
int DLL_SetShowProt (BOOL bShowProt);
int DLL_ClearProtocolWindow (void);
int DLL_SendString (char *pcStr, char *pcRet, int lMaxLen, BOOL bReadLine, int lTimeOut);
int DLL_SetSpeedPoti (BOOL bSpeedPoti);
int DLL_SetTVRMode (int lXT, int lYT, int lZT, int lAT);
int DLL_SetAutoStatus (int lValue);
int DLL_GetAutoStatus(int *plValue);
int DLL_GetStatusAxis (char *pcStatusAxisStr, int lMaxLen);
int DLL_GetStA(int *plStaX, int *plStaY, int *plStaZ, int *plStaA);
int DLL_SetDigIO_Off (int lIndex);
int DLL_SetDigIO_Polarity (int lIndex, BOOL bHigh);
int DLL_SetDigIO_EmergencyStop (int lIndex);
int DLL_SetDigIO_Distance (int lIndex, BOOL bFkt, double dDist, int lAxis);
int DLL_SetDimensions (int lXD, int lYD, int lZD, int lAD);
int DLL_SetResolution(int lValue);
int DLL_MoveRelShort (void);
int DLL_SetEncoderPeriod (double dX, double dY, double dZ, double dA);
int DLL_SetJoystickDir (int lXD, int lYD, int lZD, int lAD);
int DLL_SetEncoderMask (int lValue);
int DLL_SetGear (double dX, double dY, double dZ, double dA);
int DLL_SetHandWheelOn (BOOL bPositionCount, BOOL bEncoder);
int DLL_SetHandWheelOff (void);
int DLL_SetFactorTVR (double dX, double dY, double dZ, double dA);
int DLL_SetTargetWindow (double dX, double dY, double dZ, double dA);
int DLL_SetController (int lXC, int lYC, int lZC, int lAC);
int DLL_SetControllerCall (int lCtrCall);
int DLL_SetControllerSteps (double dX, double dY, double dZ, double dA);
int DLL_SetControllerFactor (double dX, double dY, double dZ, double dA);
int DLL_SetControllerFactorSingleAxis (int lAxis, double dFactor1, double dFactor2);
int DLL_SetControllerTWDelay (int lCtrTWDelay);
int DLL_SetControllerTWDelaySingleAxis(int lAxis, int lCtrTWDelay);
int DLL_SetEncoderRefSignal (int lXR, int lYR, int lZR, int lAR);
int DLL_SetEncoderPosition (BOOL bValue);
int DLL_GetVersionStr (char *pcVers, int lMaxLen);
int DLL_GetTangoVersion(char *pcVers, int lMaxLen);
int DLL_GetError (int *plErrorCode);
int DLL_GetErrorString(int lErrorCode, char *pcErrorString, int lMaxLen);
int DLL_GetPosSingleAxis (int lAxis, double *pdPos);
int DLL_SetDistance (double dX, double dY, double dZ, double dA);
int DLL_GetPosEx (double *pdX, double *pdY, double *pdZ, double *pdA, BOOL bEncoder);
int DLL_SetShowCmdList (BOOL bShowCmdList);
int DLL_SetWriteLogText (BOOL bAWriteLogText);
int DLL_SetControllerTimeout (int lACtrTimeout);
int DLL_SetEncoderActive (int lFlags);
int DLL_GetSnapshotCount (int *plSnsCount);
int DLL_SetSnapshotCount(int lSnsCount);
int DLL_GetSnapshotPos (double *pdX, double *pdY, double *pdZ, double *pdA);
int DLL_GetSnapshotPosArray (int lIndex, double *pdX, double *pdY, double *pdZ, double *pdA);
int DLL_ClearSnapshotPosArray(void);
int DLL_SetSnapshotPosArray(int lIndex, double dX, double dY, double dZ, double dA);
int DLL_SetSnapshotIndex(int lIndex);
int DLL_GetSnapshotIndex(int *plIndex);
int DLL_SetSnapshotMode(int lMode);
int DLL_GetSnapshotMode(int *plMode);
int DLL_SetCorrTblOff (void);
int DLL_SetCorrTblOn (char *pcAFileName);
int DLL_SetFactorMode (BOOL bAFactorMode, double dX, double dY, double dZ, double dA);
int DLL_SetSnapshot (BOOL bASnapshot);
int DLL_SetSnapshotPar (BOOL bHigh, BOOL bAutoMode);
int DLL_SetTrigger (BOOL bATrigger);
int DLL_SetTriggerPar (int lAxis, int lMode, int lSignal, double dDistance);
int DLL_SetTriggerAxis(int lAxis);
int DLL_SetTriggerMode(int lMode);
int DLL_SetTriggerSignalLength(int lSignal);
int DLL_SetTriggerDistance(double dDistance);
int DLL_SetTriggerCompensation(int lValue);
int DLL_GetTriggerCompensation(int *plValue);
int DLL_SetLanguage (char *pcPLN);
int DLL_GetSwitches (int *plFlags);
int DLL_GetSerialNr (char *pcSerialNr, int lMaxLen);
int DLL_SetCalibOffset (double dX, double dY, double dZ, double dA);
int DLL_SetRMOffset (double dX, double dY, double dZ, double dA);
int DLL_SetAxisDirection (int lXD, int lYD, int lZD, int lAD);
int DLL_SetCalibrateDir (int lXD, int lYD, int lZD, int lAD);
int DLL_LStepSave (void);
int DLL_SetBPZ (int lAValue);
int DLL_SetBPZTrackballFactor (double dAValue);
int DLL_SetBPZTrackballBackLash (double dX, double dY, double dZ, double dA);
int DLL_SetBPZJoyspeed (int lAPar, double dAValue);
int DLL_SetJoystickWindow (int lAValue);
int DLL_SetCurrentDelay (int lX, int lY, int lZ, int lR);
int DLL_SetMotorSteps(int lX, int lY, int lZ, int lR);
int DLL_SetAccelFunc(int lX, int lY, int lZ, int lR);
int DLL_WaitForAxisStop (int lAFlags, int lATimeoutValue, BOOL *pbATimeout);
int DLL_SetProcessMessagesProc (void* pProc);
int DLL_SendStringPosCmd (char *pcStr, char *pcRet, int lMaxLen, BOOL bReadLine, int lTimeOut);
int DLL_SetWriteLogTextFN (BOOL bAWriteLogText, char *pcALogFN);
int DLL_EnableCommandRetry (BOOL bAValue);
int DLL_SetXYAxisComp (int lValue);
int DLL_GetVersionStrDet (char *pcVersDet, int lMaxLen);
int DLL_SetDllNumOfAxes (int lNumOfAxes);
int DLL_SetCommandTimeout (int lAtoRead, int lAtoMove, int lAtoCalibrate);
int DLL_GetCommandTimeout(int *plAtoRead, int *plAtoMove, int *plAtoCalibrate);
int DLL_SetExtValue (int lAName, int lAValue);
int DLL_FlushBuffer (int lAValue);
int DLL_GetEEPRomValue (byte Offset, byte *pValue);
int DLL_SetEEPRomValue (byte Offset, byte Value);
int DLL_GetXYAxisComp (int *plValue);
int DLL_GetDimensions (int *plXD, int *plYD, int *plZD, int *plAD);
int DLL_GetResolution(int *plValue);
int DLL_GetPitch (double *pdX, double *pdY, double *pdZ, double *pdA);
int DLL_GetGear (double *pdX, double *pdY, double *pdZ, double *pdA);
int DLL_GetVel (double *pdX, double *pdY, double *pdZ, double *pdA);
int DLL_GetSecVel (double *pdX, double *pdY, double *pdZ, double *pdA);
int DLL_SetVelFac (double dX, double dY, double dZ, double dA);
int DLL_GetVelFac (double *pdX, double *pdY, double *pdZ, double *pdA);
int DLL_GetSpeedPoti (BOOL *pbSpePoti);
int DLL_GetMotorCurrent (double *pdX, double *pdY, double *pdZ, double *pdA);
int DLL_GetReduction (double *pdX, double *pdY, double *pdZ, double *pdA);
int DLL_GetCurrentDelay (int *plX, int *plY, int *plZ, int *plR);
int DLL_SetOutFuncLev (double dX, double dY, double dZ, double dA);
int DLL_GetOutFuncLev (double *pdX, double *pdY, double *pdZ, double *pdA);
int DLL_GetAxisDirection (int *plXD, int *plYD, int *plZD, int *plAD);
int DLL_GetCalibOffset (double *pdX, double *pdY, double *pdZ, double *pdA);
int DLL_GetRMOffset (double *pdX, double *pdY, double *pdZ, double *pdA);
int DLL_GetCalibrateDir (int *plXD, int *plYD, int *plZD, int *plAD);
int DLL_SetCalibBackSpeed (int lSpeed);
int DLL_GetCalibBackSpeed (int *plSpeed);
int DLL_SetRefSpeed (int lSpeed);
int DLL_GetRefSpeed (int *plSpeed);
int DLL_GetBlSmoothSingleAxis(int lAxis, int *plBlSmooth);
int DLL_SetBlSmoothSingleAxis(int lAxis, int lBlSmooth);
int DLL_SetPowerAmplifier (BOOL bAmplifier);
int DLL_GetPowerAmplifier (BOOL *pbAmplifier);
int DLL_SetMotorTablePatch (BOOL bActive);
int DLL_GetMotorTablePatch (BOOL *pbActive);
int DLL_SetJoystickFilter (BOOL bActive);
int DLL_GetJoystickFilter (BOOL *pbActive);
int DLL_SetStopPolarity (BOOL bHighActiv);
int DLL_GetStopPolarity (BOOL *pbHighActiv);
int DLL_GetStop(BOOL *pbActiv);
int DLL_SetStop(BOOL bActiv);
int DLL_SetVLevel (int lVRegion, double dDownLevel, double dUppLevel);
int DLL_GetVLevel (int lVRegion, double *pdDownLevel, double *pdUppLevel);
int DLL_SetStopAccel (double dX, double dY, double dZ, double dA);
int DLL_GetStopAccel (double *pdXD, double *pdYD, double *pdZD, double *pdAD);
int DLL_GetVersionStrInfo (char *pcVersInfo, int lMaxLen);
int DLL_GetStageSN (char *pcSN, int lMaxLen);
int DLL_GetStatusLimit (char *pcLimit, int lMaxLen);
int DLL_GetSecurityErr (DWORD *pdwValue);
int DLL_GetSecurityStatus (DWORD *pdwValue);
int DLL_GetDelay (int *plDelay);
int DLL_GetDistance (double *pdX, double *pdY, double *pdZ, double *pdA);
int DLL_ClearPos (int lFlags);
int DLL_SetDigJoySpeed (double dX, double dY, double dZ, double dA);
int DLL_GetDigJoySpeed (double *pdX, double *pdY, double *pdZ, double *pdA);
int DLL_GetJoystickDir (int *plXD, int *plYD, int *plZD, int *plRD);
int DLL_GetJoystick (BOOL *pbJoystickOn, BOOL *pbManual, BOOL *pbPositionCount, BOOL *pbEncoder);
int DLL_GetJoystickWindow (int *plAValue);
int DLL_GetHandWheel (BOOL *pbHandWheelOn, BOOL *pbPositionCount, BOOL *pbEncoder);
int DLL_GetBPZ (int *plAValue);
int DLL_GetBPZTrackballFactor (double *pdAValue);
int DLL_GetBPZTrackballBackLash (double *pdX, double *pdY, double *pdZ, double *pdA);
int DLL_GetBPZJoyspeed (int lAPar, double *pdAValue);
int DLL_GetLimitControl (int lAxis, BOOL *pbActive);
int DLL_SetAutoLimitAfterCalibRM (int lFlags);
int DLL_GetAutoLimitAfterCalibRM (int *plFlags);
int DLL_GetSwitchPolarity (int *plXP, int *plYP, int *plZP, int *plRP);
int DLL_GetSwitchType (int *plXP, int *plYP, int *plZP, int *plRP);
int DLL_GetSwitchActive (int *plXA, int *plYA, int *plZA, int *plRA);
int DLL_GetTVRMode (int *plXT, int *plYT, int *plZT, int *plRT);
int DLL_GetFactorTVR (double *pdX, double *pdY, double *pdZ, double *pdA);
int DLL_SetTVROutMode (int lXT, int lYT, int lZT, int lRT);
int DLL_GetTVROutMode (int *plXT, int *plYT, int *plZT, int *plRT);
int DLL_SetTVROutResolution (int lX, int lY, int lZ, int lR);
int DLL_GetTVROutResolution (int *plX, int *plY, int *plZ, int *plR);
int DLL_SetTVROutPitch (double dX, double dY, double dZ, double dA);
int DLL_GetTVROutPitch (double *pdX, double *pdY, double *pdZ, double *pdA);
int DLL_SetVelTVRO (double dX, double dY, double dZ, double dA);
int DLL_GetVelTVRO (double *pdX, double *pdY, double *pdZ, double *pdA);
int DLL_SetAccelTVRO (double dX, double dY, double dZ, double dA);
int DLL_GetAccelTVRO (double *pdX, double *pdY, double *pdZ, double *pdA);
int DLL_SetVelSingleAxisTVRO (int lAxis, double dVel);
int DLL_SetAccelSingleAxisTVRO (int lAxis, double dAccel);
int DLL_SetPosTVRO (double dX, double dY, double dZ, double dA);
int DLL_GetPosTVRO (double *pdX, double *pdY, double *pdZ, double *pdA);
int DLL_MoveAbsTVRO (double dX, double dY, double dZ, double dA, BOOL bWait);
int DLL_MoveRelTVRO (double dX, double dY, double dZ, double dA, BOOL bWait);
int DLL_MoveRelTVROSingleAxis (int lAxis, double dValue, BOOL bWait);
int DLL_MoveAbsTVROSingleAxis (int lAxis, double dValue, BOOL bWait);
int DLL_GetStatusTVRO (char *pcStat, int lMaxLen);
int DLL_GetTargetWindow (double *pdX, double *pdY, double *pdZ, double *pdA);
int DLL_GetEncoderSingleAxis (int lAxis, int *plEncoderType, double *pdPeriod, int *plRef);
int DLL_SetEncoderSingleAxis (int lAxis, int lEncoderType, double dPeriod, int lRef);
int DLL_GetEncoderPeriod (double *pdX, double *pdY, double *pdZ, double *pdA);
int DLL_GetEncoderRefSignal (int *plXR, int *plYR, int *plZR, int *plRR);
int DLL_GetEncoderPosition (BOOL *pbValue);
int DLL_GetEncoderActive (int *plFlags);
int DLL_GetController (int *plXC, int *plYC, int *plZC, int *plRC);
int DLL_GetControllerCall (int *plCtrCall);
int DLL_GetControllerSteps (double *pdX, double *pdY, double *pdZ, double *pdA);
int DLL_GetControllerFactor (double *pdX, double *pdY, double *pdZ, double *pdA);
int DLL_GetControllerFactorSingleAxis(int lAxis, double *pdFactor1, double *pdFactor2);
int DLL_GetControllerTWDelay(int *plCtrTWDelay);
int DLL_GetControllerTWDelaySingleAxis (int lAxis, int *plCtrTWDelay);
int DLL_GetControllerTimeout (int *plACtrTimeout);
int DLL_SetCtrFastMoveOn (void);
int DLL_SetCtrFastMoveOff (void);
int DLL_GetCtrFastMove (BOOL *pbActive);
int DLL_ClearCtrFastMoveCounter (void);
int DLL_GetCtrFastMoveCounter (int *plXC, int *plYC, int *plZC, int *plRC);
int DLL_ClearEncoder (int lAxis);
int DLL_GetEncoder (double *pdXP, double *pdYP, double *pdZP, double *pdAP);
int DLL_GetTrigger (BOOL *pbATrigger);
int DLL_GetTriggerPar (int *plAxis, int *plMode, int *plSignal, double *pdDistance);
int DLL_GetTriggerRange(double *pdStartPos, double *pdEndPos, int *plNumberOfTriggerPulses);
int DLL_GetTriggerPositionList(int lIndex, double *pdPos);
int DLL_SetTriggerPositionList(int lIndex, double dPos);
int DLL_SetTriggerRange(double dStartPos, double dEndPos, int lNumberOfTriggerPulses);
int DLL_GetTriggerAxis(int *plAxis);
int DLL_GetTriggerMode(int *plMode);
int DLL_GetTriggerSignalLength(int *plSignal);
int DLL_GetTriggerDistance(double *pdDistance);
int DLL_SetTriggerOutput(int lValue);
int DLL_GetTriggerOutput(int *plValue);
int DLL_SetTriggerEncoder(int lValue);
int DLL_GetTriggerEncoder(int *plValue);
int DLL_SetTriggerFrequency(double dFrequency);
int DLL_GetTriggerFrequency(double *pdFrequency);
int DLL_Set2ndTriggerDelay(double dValue);
int DLL_Get2ndTriggerDelay(double *pdValue);
int DLL_Set2ndTriggerWidth(double dValue);
int DLL_Get2ndTriggerWidth(double *pdValue);
int DLL_Set2ndTriggerFrequency(double dValue);
int DLL_Get2ndTriggerFrequency(double *pdValue);
int DLL_SetTriggerLevel(int lValue);
int DLL_GetTriggerLevel(int *plValue);
int DLL_SetTriggerPositionListEntries(int lValue);
int DLL_GetTriggerPositionListEntries(int *plValue);
int DLL_SetTriggerPositionListIndex(int lValue);
int DLL_GetTriggerPositionListIndex(int *plValue);
int DLL_SetTrigCount (int lValue);
int DLL_GetTrigCount (int *plValue);
int DLL_SetTVRInPulse (int lAxis, BOOL bDirection);
int DLL_GetSnapshot (BOOL *pbASnapshot);
int DLL_SetSnapshotFilter (int lTime);
int DLL_GetSnapshotFilter (int *plTime);
int DLL_GetSnapshotPar (BOOL *pbHigh, BOOL *pbAutoMode);
int DLL_GetLimit (int lAxis, double *pdMinRange, double *pdMaxRange);
int DLL_JoyChangeAxis (BOOL bValue);
int DLL_GetJoyChangeAxis (BOOL *pbValue);
int DLL_GetSyncZA(BOOL *pbSyncZA);
int DLL_SetSyncZA(BOOL bSync);
int DLL_GetSwapZA(BOOL *pbSwapZA);
int DLL_SetSwapZA(BOOL bSwap);
int DLL_GetHdiKeys(int *plKey1, int *plKey2, int *plKey3, int *plKey4);
int DLL_GetKey (BOOL *pbKey1, BOOL *pbKey2, BOOL *pbKey3, BOOL *pbKey4);
int DLL_GetKeyLatch (BOOL *pbKey1, BOOL *pbKey2, BOOL *pbKey3, BOOL *pbKey4);
int DLL_ClearKeyLatch (int lKey);
int DLL_SetZwTravel (int lIndex, double dDistance);
int DLL_GetZwTravel (int lIndex, double *pdDistance);
int DLL_GetMotorSteps (int *lX, int *lY, int *lZ, int *lR);
int DLL_GetAccelFunc(int *lX, int *lY, int *lZ, int *lR);
int MsgDisconnect (char *pcAComName, time_t ltime);
int MsgReconnect (char *pcAComName);
int DLL_Eject(int maga, int keep);
int DLL_SetGripper(int c1, int s1, int c2, int s2);
int DLL_GetSlide(int maga, int slot, int mode);
int DLL_GetTray(int slot, int mode);
int DLL_GetRFID(int slot, int bank, int *plRFID);
int DLL_SetRFID(int slot, int bank, int lRFID);
int DLL_GetTraySN(int slot, int *plTraySN);
int DLL_GetTrayType(int slot, int *plTrayType);
int DLL_SetTrayType(int slot, int TrayType);
int DLL_GetClipType(int *plClipType);
int DLL_GetLoaderType(int *plLoaderType);
int DLL_GetTrayOnStage(int *plTrayOnStage);
int DLL_GetNumberOfSlots(int *plSlots);
int DLL_GetNumberOfRows(int *plRows);
int DLL_GetNumberOfMagazins(int *plMagazins);
int DLL_GetNumberOfColumns(int *plColumns);
int DLL_PutSlide(int maga, int slot);
int DLL_PutTray(int slot);
int DLL_SetPrioHandlerPos(int php);
int DLL_Insert(void);
int DLL_MagazinSeated(int maga, int *seated);
int DLL_SlideSeated(int maga, int slot, int *seated);
int DLL_GetGripper(int *c1, int *s1, int *c2, int *s2);
int DLL_GetPrioHandlerPos(int *php);
int DLL_GetLabelLED(int *plValue);
int DLL_SetLabelLED(int lValue);
int DLL_GetCabinLED(int *plValue);
int DLL_SetCabinLED(int lValue);
int DLL_Xpos3_MoveAbsSingleAxis(int lAxis, double dValue, BOOL bWait);
int DLL_Xpos3_MoveRelSingleAxis(int lAxis, double dValue, BOOL bWait);
int DLL_Xpos3_SetPosSingleAxis(int lAxis, double dValue);
int DLL_Xpos3_GetPosSingleAxis(int lAxis, double *pdPos);

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



TANGO_API LSX_CreateLSID(int *plLSID);
TANGO_API LSX_FreeLSID(int lLSID);
TANGO_API LSX_Connect(int lLSID);
TANGO_API LSX_ConnectSimple(int lLSID, int lAnInterfaceType, char *pcAComName, int lABaudRate, BOOL bAShowProt);
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
TANGO_API LSX_SetShowProt (int lLSID, BOOL bShowProt);
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
TANGO_API LS_ConnectSimple(int lAnInterfaceType, char *pcAComName, int lABaudRate, BOOL bAShowProt);
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
TANGO_API LS_SetShowProt (BOOL bShowProt);
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

TANGO_API LSX_GetClipType(int lLSID, int *plClipType);
TANGO_API LS_GetClipType (int *plClipType);

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

//TANGO_API MsgDisconnect (char *pcAComName, time_t ltime);
//TANGO_API MsgReconnect (char *pcAComName);

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

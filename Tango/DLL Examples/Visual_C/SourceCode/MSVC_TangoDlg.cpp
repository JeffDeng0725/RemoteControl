// MSVC_TangoDlg.cpp : implementation file
//

#include "stdafx.h"

#include "MSVC_Tango.h"
#include "MSVC_TangoDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMSVC_TangoDlg dialog

CMSVC_TangoDlg::CMSVC_TangoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMSVC_TangoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMSVC_TangoDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMSVC_TangoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMSVC_TangoDlg)
	DDX_Control(pDX, IDC_COMBO2, m_Combo2);
	DDX_Control(pDX, IDC_COMBO1, m_Combo1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMSVC_TangoDlg, CDialog)
	//{{AFX_MSG_MAP(CMSVC_TangoDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
	ON_BN_CLICKED(IDC_BUTTON9, OnButton9)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMSVC_TangoDlg message handlers

BOOL CMSVC_TangoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	pTango = new CTango();
	SetDlgItemText(IDC_COMBO1, "COM1");
	SetDlgItemText(IDC_COMBO2,"57600");
	SetDlgItemText(IDC_EDIT1, "0.101");
	SetDlgItemText(IDC_EDIT2, "0.202");
	SetDlgItemText(IDC_EDIT3, "0.303");
	SetDlgItemText(IDC_EDIT4, "0.404");

	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMSVC_TangoDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMSVC_TangoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}



void CMSVC_TangoDlg::OnButton1() 
{  
	// check if Tango DLL is loaded correctly
	int result = pTango->GetDLLLoadResult();
	if (result == -1)
	{
		AfxMessageBox("Error: DLL not found.\n\nCheck the .dll file name or copy the .dll file into this directory!", MB_OK);
		return;
	}
	else if (result == -2)
	{
		AfxMessageBox("Warning: Not all DLL functions present.", MB_OK);
	}

	
	// connect to Tango controller
	char cp[20], br[20];
	GetDlgItemText(IDC_COMBO1, cp, sizeof(cp));
	GetDlgItemText(IDC_COMBO2, br, sizeof(br));
  
	pTango->ConnectSimple(1, cp, atoi(br), true);	
}



void CMSVC_TangoDlg::OnButton2() 
{
	pTango->Disconnect();
}



void CMSVC_TangoDlg::OnClose() 
{	
    delete pTango;

	CDialog::OnClose();
}



void CMSVC_TangoDlg::UpdatePosition() 
{
	char x[20], y[20], z[20], a[20];

	double Pos[4];
	
	// read position from controller
	pTango->GetPosSingleAxis(1, &Pos[0]);
	pTango->GetPosSingleAxis(2, &Pos[1]);
	pTango->GetPosSingleAxis(3, &Pos[2]);
	pTango->GetPosSingleAxis(4, &Pos[3]);

	// strings
	sprintf(x, "%lf", Pos[0]);
	sprintf(y, "%lf", Pos[1]);
	sprintf(z, "%lf", Pos[2]);
	sprintf(a, "%lf", Pos[3]);

	// set position text
	SetDlgItemText(IDC_EDIT5, x);
	SetDlgItemText(IDC_EDIT6, y);
	SetDlgItemText(IDC_EDIT7, z);
	SetDlgItemText(IDC_EDIT8, a);
}



void CMSVC_TangoDlg::OnButton3() 
{
	char x[20], y[20], z[20], a[20];
	GetDlgItemText(IDC_EDIT1, x, sizeof(x));
	GetDlgItemText(IDC_EDIT2, y, sizeof(y));
	GetDlgItemText(IDC_EDIT3, z, sizeof(z));
	GetDlgItemText(IDC_EDIT4, a, sizeof(a));
	pTango->MoveRel(atof(x), atof(y), atof(z), atof(a), true);
	
	UpdatePosition();
}



void CMSVC_TangoDlg::OnButton4() 
{
	BOOL Timeout;

	char x[20], y[20], z[20], a[20];
	GetDlgItemText(IDC_EDIT1, x, sizeof(x));
	GetDlgItemText(IDC_EDIT2, y, sizeof(y));
	GetDlgItemText(IDC_EDIT3, z, sizeof(z));
	GetDlgItemText(IDC_EDIT4, a, sizeof(a));

	pTango->MoveAbsSingleAxis(1, atof(x), false);
	Sleep(111);
	pTango->MoveAbsSingleAxis(2, atof(y), false);
	Sleep(122);
	pTango->MoveAbsSingleAxis(3, atof(z), false);
	Sleep(133);
	pTango->MoveAbsSingleAxis(4, atof(a), false);
	Sleep(144);
	pTango->WaitForAxisStop(0x0F, 0, &Timeout);

	pTango->FlushBuffer(0);

	UpdatePosition();
}



void CMSVC_TangoDlg::OnButton5() 
{
	char x[20], y[20], z[20], a[20];
	GetDlgItemText(IDC_EDIT1, x, sizeof(x));
	GetDlgItemText(IDC_EDIT2, y, sizeof(y));
	GetDlgItemText(IDC_EDIT3, z, sizeof(z));
	GetDlgItemText(IDC_EDIT4, a, sizeof(a));
	pTango->MoveAbs(atof(x), atof(y), atof(z), atof(a), true);
	
  UpdatePosition();
}



void CMSVC_TangoDlg::OnButton6() 
{
  char answer[20];
  pTango->SendString("!cal x\r",answer,sizeof(answer),false,0);
  pTango->SendString("!cal y\r",answer,sizeof(answer),true,30000);

  UpdatePosition();
}



void CMSVC_TangoDlg::OnButton7() 
{
  char answer[20];
  pTango->SendString("!rm x\r",answer,sizeof(answer),false,0);
  pTango->SendString("!rm y\r",answer,sizeof(answer),true,30000);

  UpdatePosition();
}



void CMSVC_TangoDlg::OnButton8() 
{
  char answer[20];
  pTango->SendString("!cal z\r",answer,sizeof(answer),true,30000);

  UpdatePosition();
}



void CMSVC_TangoDlg::OnButton9() 
{
  char answer[20];
  pTango->SendString("!rm z\r",answer,sizeof(answer),true,30000);

  UpdatePosition();
}



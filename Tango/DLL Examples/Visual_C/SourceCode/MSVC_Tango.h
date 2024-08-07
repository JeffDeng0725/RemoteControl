// MSVC_Tango.h : main header file for the MSVC_Tango application
//

#if !defined(AFX_MSVC_Tango_H__DE982D06_1ACF_47CF_A32E_C6D736149707__INCLUDED_)
#define AFX_MSVC_Tango_H__DE982D06_1ACF_47CF_A32E_C6D736149707__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "MSVC_Tango_i.h"

/////////////////////////////////////////////////////////////////////////////
// CMSVC_TangoApp:
// See MSVC_Tango.cpp for the implementation of this class
//

class CMSVC_TangoApp : public CWinApp
{
public:
	CMSVC_TangoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMSVC_TangoApp)
	public:
	virtual BOOL InitInstance();
		virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMSVC_TangoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL m_bATLInited;
private:
	BOOL InitATL();
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MSVC_Tango_H__DE982D06_1ACF_47CF_A32E_C6D736149707__INCLUDED_)

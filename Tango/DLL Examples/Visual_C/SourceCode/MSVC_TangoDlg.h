// MSVC_TangoDlg.h : header file
//

#if !defined(AFX_MSVC_TangoDLG_H__22B86A9F_A8E2_4264_9C7A_159E2A901999__INCLUDED_)
#define AFX_MSVC_TangoDLG_H__22B86A9F_A8E2_4264_9C7A_159E2A901999__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Tango.h"

/////////////////////////////////////////////////////////////////////////////
// CMSVC_TangoDlg dialog

class CMSVC_TangoDlg : public CDialog
{
// Construction
public:
	void UpdatePosition (void);
	CMSVC_TangoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMSVC_TangoDlg)
	enum { IDD = IDD_MSVC_Tango_DIALOG };
	CComboBox	m_Combo2;
	CComboBox	m_Combo1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMSVC_TangoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CTango* pTango;


	// Generated message map functions
	//{{AFX_MSG(CMSVC_TangoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnClose();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnButton6();
	afx_msg void OnButton7();
	afx_msg void OnButton8();
	afx_msg void OnButton9();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MSVC_TangoDLG_H__22B86A9F_A8E2_4264_9C7A_159E2A901999__INCLUDED_)

// MySpy.h : main header file for the MYSPY application
//

#if !defined(AFX_MYSPY_H__7C1F79E7_E2B3_44F5_B083_82C02C297F6E__INCLUDED_)
#define AFX_MYSPY_H__7C1F79E7_E2B3_44F5_B083_82C02C297F6E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMySpyApp:
// See MySpy.cpp for the implementation of this class
//

class CMySpyApp : public CWinApp
{
public:
	CMySpyApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMySpyApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMySpyApp)
	afx_msg void OnAppAbout();
	afx_msg void OnFinder();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYSPY_H__7C1F79E7_E2B3_44F5_B083_82C02C297F6E__INCLUDED_)

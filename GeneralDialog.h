#if !defined(AFX_GENERALDIALOG_H__320E07F2_33BD_416D_AAF7_540A96F54B78__INCLUDED_)
#define AFX_GENERALDIALOG_H__320E07F2_33BD_416D_AAF7_540A96F54B78__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GeneralDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGeneralDialog dialog

class CGeneralDialog : public CDialog
{
// Construction
public:
	virtual BOOL OnInitDialog( );
	void SetCurSelHwnd(HWND hwnd);
	HWND m_CurrSelHwnd;
	CGeneralDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CGeneralDialog)
	enum { IDD = DLG_GENERAL };
	CStatic	m_WindowProc;
	CStatic	m_WindowHandle;
	CStatic	m_UserData;
	CStatic	m_RestoredRect;
	CStatic	m_Rectangel;
	CStatic	m_MenumHandle;
	CStatic	m_Instancehandle;
	CStatic	m_ClientRect;
	CComboBox	m_WndBytes;
	CEdit	m_WndCaption;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGeneralDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGeneralDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GENERALDIALOG_H__320E07F2_33BD_416D_AAF7_540A96F54B78__INCLUDED_)

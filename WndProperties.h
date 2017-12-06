#if !defined(AFX_WNDPROPERTIES_H__0A490D0A_4BE6_42EA_8A5C_5B00472847AC__INCLUDED_)
#define AFX_WNDPROPERTIES_H__0A490D0A_4BE6_42EA_8A5C_5B00472847AC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WndProperties.h : header file
//
#include "ClassDialog.h"
#include "GeneralDialog.h"
#include "ProcessDialog.h"
#include "StyleDialog.h"
#include "WindowsDialog.h"

/////////////////////////////////////////////////////////////////////////////
// CWndProperties dialog

class CWndProperties : public CDialog
{
// Construction
public:
	void SetSelWndHandle(HWND hwnd);
  virtual void OnOK( );
  virtual void OnCancel( );
	virtual BOOL OnInitDialog();
	CWndProperties(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CWndProperties)
	enum { IDD = DLG_WNDPROPERTIES };
	CTabCtrl	m_TabWndProperties;

	//}}AFX_DATA

private:
	HWND            m_SelWndHandle;
  CClassDialog    m_ClassDlg;
  CGeneralDialog  m_GenderDlg;
  CProcessDialog  m_ProcessDlg;
  CStyleDialog    m_StyleDlg;
  CWindowsDialog  m_WndDlg;
  const DWORD     m_tabDlgCount;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWndProperties)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWndProperties)
	afx_msg void OnSelchangeProperties(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WNDPROPERTIES_H__0A490D0A_4BE6_42EA_8A5C_5B00472847AC__INCLUDED_)

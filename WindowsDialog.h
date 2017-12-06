#if !defined(AFX_WINDOWSDIALOG_H__3D7286A2_DDA4_4860_9318_6DC07E032FB2__INCLUDED_)
#define AFX_WINDOWSDIALOG_H__3D7286A2_DDA4_4860_9318_6DC07E032FB2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WindowsDialog.h : header file
//
#include "SelStatic.h"
/////////////////////////////////////////////////////////////////////////////
// CWindowsDialog dialog

class CWindowsDialog : public CDialog
{
// Construction
public:
  virtual BOOL OnInitDialog( );
	void SetCurSelHwnd(HWND hwnd);
	CWindowsDialog(CWnd* pParent = NULL);   // standard constructor
// Dialog Data
	//{{AFX_DATA(CWindowsDialog)
	enum { IDD = DLG_WINDOWS };
	CSelStatic	m_textPreWnd;
	CSelStatic	m_textParentWnd;
	CSelStatic	m_textOwnerWnd;
	CSelStatic	m_textNextWnd;
	CSelStatic	m_textFirstChild;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWindowsDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWindowsDialog)
	//afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	HWND m_CurrSelHwnd;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WINDOWSDIALOG_H__3D7286A2_DDA4_4860_9318_6DC07E032FB2__INCLUDED_)

#if !defined(AFX_PROCESSDIALOG_H__ED13E823_1A24_418F_9091_E4C11CF15C1B__INCLUDED_)
#define AFX_PROCESSDIALOG_H__ED13E823_1A24_418F_9091_E4C11CF15C1B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ProcessDialog.h : header file
//
#include "SelStatic.h"
/////////////////////////////////////////////////////////////////////////////
// CProcessDialog dialog

class CProcessDialog : public CDialog
{
// Construction
public:
  virtual BOOL OnInitDialog( );
	void SetCurSelHwnd(HWND hwnd);
	CProcessDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CProcessDialog)
	enum { IDD = DLG_PROCESS };
	CStatic	m_ThreadId;
	CStatic	m_textProcessId;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProcessDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CProcessDialog)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	HWND m_CurSelHwnd;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROCESSDIALOG_H__ED13E823_1A24_418F_9091_E4C11CF15C1B__INCLUDED_)

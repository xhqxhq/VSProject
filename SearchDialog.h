#if !defined(AFX_SEARCHDIALOG_H__539AB76B_976B_4831_9717_D181A192DE28__INCLUDED_)
#define AFX_SEARCHDIALOG_H__539AB76B_976B_4831_9717_D181A192DE28__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SearchDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSearchDialog dialog
#include "SpyButton.h"
class CSearchDialog : public CDialog
{
// Construction
public:
	CSearchDialog(CWnd* pParent = NULL);   // standard constructor
	virtual BOOL OnInitDialog( );
// Dialog Data
	//{{AFX_DATA(CSearchDialog)
	enum { IDD = DLG_WINDOWSEARCH };
	CEdit	      m_editCaption;
	CEdit	      m_edtClass;
	CEdit	      m_editHandle;
	CSpyButton	m_btnFinder;
	CString	    m_TipsInfo;
	BOOL	m_IsHide;
	//}}AFX_DATA

  CRect       m_LastRect;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSearchDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSearchDialog)
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	afx_msg void OnHidespy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEARCHDIALOG_H__539AB76B_976B_4831_9717_D181A192DE28__INCLUDED_)

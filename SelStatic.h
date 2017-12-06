#if !defined(AFX_SELSTATIC_H__6F997F17_D963_4006_A309_23A447A0BC9A__INCLUDED_)
#define AFX_SELSTATIC_H__6F997F17_D963_4006_A309_23A447A0BC9A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SelStatic.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSelStatic window

class CSelStatic : public CStatic
{
// Construction
public:
	CSelStatic();

// Attributes
public:
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSelStatic)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSelStatic();

	// Generated message map functions
protected:
	//{{AFX_MSG(CSelStatic)
	afx_msg void OnClicked();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
public:
  virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SELSTATIC_H__6F997F17_D963_4006_A309_23A447A0BC9A__INCLUDED_)

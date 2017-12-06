#if !defined(AFX_SPYBUTTON_H__BC5B507A_6BB7_4907_8648_034DEFD79FAF__INCLUDED_)
#define AFX_SPYBUTTON_H__BC5B507A_6BB7_4907_8648_034DEFD79FAF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SpyButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSpyButton window

class CSpyButton : public CButton
{
// Construction
public:
	CSpyButton();

// Attributes
public:
  HCURSOR m_hCursor;      //当前鼠标光标
  HCURSOR m_hOldCursor;   //上次的鼠标光标
  HICON   m_hIconPushed; //被按下时按钮所显示的图标
  HICON   m_hIconUnPush;  //未被按下时按钮所显示的图标
  BOOL    m_bIsCapture;   //是否处于捕捉窗口
  HWND    m_lastWnd;      //上次捕获的窗口
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpyButton)
	public:

	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSpyButton();
virtual BOOL OnInitDialog( );
	// Generated message map functions
protected:
	//{{AFX_MSG(CSpyButton)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
public:
  void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPYBUTTON_H__BC5B507A_6BB7_4907_8648_034DEFD79FAF__INCLUDED_)

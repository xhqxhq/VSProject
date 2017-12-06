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
  HCURSOR m_hCursor;      //��ǰ�����
  HCURSOR m_hOldCursor;   //�ϴε������
  HICON   m_hIconPushed; //������ʱ��ť����ʾ��ͼ��
  HICON   m_hIconUnPush;  //δ������ʱ��ť����ʾ��ͼ��
  BOOL    m_bIsCapture;   //�Ƿ��ڲ�׽����
  HWND    m_lastWnd;      //�ϴβ���Ĵ���
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

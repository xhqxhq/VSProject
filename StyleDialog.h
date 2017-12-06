#if !defined(AFX_STYLEDIALOG_H__D945C1DF_F9DF_4836_96AB_DC4E898480BE__INCLUDED_)
#define AFX_STYLEDIALOG_H__D945C1DF_F9DF_4836_96AB_DC4E898480BE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StyleDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStyleDialog dialog
#define MAPWINDOWSTYLE(wndStyle) {wndStyle,_T(#wndStyle) }

class CStyleDialog : public CDialog
{
// Construction
public:
	void SetCurSelHwnd(HWND hwnd);
  virtual BOOL OnInitDialog( );
	CStyleDialog(CWnd* pParent = NULL);   // standard constructor
// Dialog Data
	//{{AFX_DATA(CStyleDialog)
	enum { IDD = DLG_STYLE };
	CListBox	m_wndExStyles;
	CStatic	m_textExWndStyles;
	CStatic	m_textWndStyles;
	CListBox	m_wndStyles;
	//}}AFX_DATA

private:
  typedef struct tagMapWndStyle
  {
    UINT nWndStyle;
    PTCHAR lpWndStyleName;
  }MapWndStyle;

  const static MapWndStyle allWndStyle[];     //¥Ê∑≈À˘”–
  const static MapWndStyle allWndExStyle[];
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStyleDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CStyleDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	HWND m_CurSelHwnd;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STYLEDIALOG_H__D945C1DF_F9DF_4836_96AB_DC4E898480BE__INCLUDED_)

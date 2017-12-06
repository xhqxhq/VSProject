#if !defined(AFX_CLASSDIALOG_H__A7C67426_F49A_4938_A99B_FD294E1B6C07__INCLUDED_)
#define AFX_CLASSDIALOG_H__A7C67426_F49A_4938_A99B_FD294E1B6C07__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClassDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CClassDialog dialog

class CClassDialog : public CDialog
{
// Construction
public:
  virtual BOOL OnInitDialog( );
	void SetCurSelHwnd(HWND hwnd);
	CClassDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CClassDialog)
	enum { IDD = DLG_CLASS };
	CStatic	m_textBrushHandle;
	CStatic	m_textCursorHandle;
	CStatic	m_textIconHandle;
	CStatic	m_textMenuName;
	CStatic	m_textWindowProc;
	CStatic	m_textWindowBytes;
	CStatic	m_textInstanceHandle;
	CStatic	m_textClassAtom;
	CComboBox	m_cbxClassBytes;
	CStatic	m_textClassBytes;
	CComboBox	m_cmbClassStyles;
	CStatic	m_textClassStyles;
	CEdit	m_editClassName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClassDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CClassDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
  typedef struct tagMAPCLASSSTYLE
  {
    UINT    m_uClassStyle; //类风格
    PTCHAR  m_CSString;    //对应字符串
  }MAPCLASSSTYLE;

//  typedef struct tagMAPCURSORS
//  {
//    LPTSTR  m_Cursor; //类风格
//    PTCHAR  m_CSString;    //对应字符串
//  }MAPCURSORS;
	HWND m_CurrSelHwnd;
  const static MAPCLASSSTYLE classStyle[];
//  const static MAPCURSORS    allCursors[];
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLASSDIALOG_H__A7C67426_F49A_4938_A99B_FD294E1B6C07__INCLUDED_)

// SearchDialog.cpp : implementation file
//

#include "stdafx.h"
#include "MySpy.h"
#include "SearchDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSearchDialog dialog


CSearchDialog::CSearchDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CSearchDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSearchDialog)
	m_TipsInfo = _T("");
	m_IsHide = FALSE;
	//}}AFX_DATA_INIT
}


void CSearchDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSearchDialog)
	DDX_Control(pDX, EDT_FINDCAPTION, m_editCaption);
	DDX_Control(pDX, EDT_FINDCLASS, m_edtClass);
	DDX_Control(pDX, EDT_FINDHANDLE, m_editHandle);
	DDX_Control(pDX, BTN_FINDER, m_btnFinder);
	DDX_Text(pDX, LABLE_SEARCHCRITERIA, m_TipsInfo);
	DDX_Check(pDX, CK_HIDESPY, m_IsHide);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSearchDialog, CDialog)
	//{{AFX_MSG_MAP(CSearchDialog)
	ON_WM_DRAWITEM()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(CK_HIDESPY, OnHidespy)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSearchDialog message handlers

BOOL CSearchDialog::OnInitDialog( )
{
  CDialog::OnInitDialog();

  //设置提示信息
  CString strBuff;
  strBuff += _T("Specity the by dragging the Finder\n");
  strBuff += _T("Tool Over a Window to select it then\n");
  strBuff += _T("releasing the mouse bytton,or by entering\n");
  strBuff += _T("a window handle[in hedadecimal],or a\n");
  strBuff += _T("caption or class string for which to search.");
  m_TipsInfo = strBuff;

  GetDlgItem(BTN_FINDER)->InvalidateRect(NULL,FALSE);
  UpdateData(FALSE);
  return TRUE;
}



void CSearchDialog::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// TODO: Add your message handler code here and/or call default
  CDialog::OnDrawItem(nIDCtl, lpDrawItemStruct);
  if(!m_btnFinder.m_bIsCapture)
  {
    return;
  }

  CString strBuff;
  strBuff.Format(_T("%08X"),(DWORD)m_btnFinder.m_lastWnd);
  m_editHandle.SetWindowText(strBuff);
  strBuff.Empty();
  int nCpyBytes = ::GetWindowText(m_btnFinder.m_lastWnd,
    strBuff.GetBufferSetLength(MAXBYTE),
    MAXBYTE);
  if(nCpyBytes)
  {
    m_editCaption.SetWindowText(strBuff);
  }
  
  strBuff.Empty();
  ::GetClassName(m_btnFinder.m_lastWnd,
    strBuff.GetBufferSetLength(MAXBYTE),
    MAXBYTE);
  m_edtClass.SetWindowText(strBuff);
  UpdateData(FALSE);
}



void CSearchDialog::OnHidespy() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
  CWnd* pMaindWnd = AfxGetApp()->GetMainWnd();
  if(m_IsHide)
  {
    pMaindWnd->GetWindowRect(&m_LastRect);
    pMaindWnd->SetWindowPos(&wndTop,-1,-1,-1,-1,SWP_HIDEWINDOW );
  }
  else
  {
    pMaindWnd->SetWindowPos(&wndTop,m_LastRect.left,
      m_LastRect.top,m_LastRect.Width(),m_LastRect.Height(),
      SWP_SHOWWINDOW);
  }
}

// WndProperties.cpp : implementation file
//

#include "stdafx.h"
#include "MySpy.h"
#include "WndProperties.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWndProperties dialog


CWndProperties::CWndProperties(CWnd* pParent /*=NULL*/)
	: CDialog(CWndProperties::IDD, pParent),m_tabDlgCount(5)
{
	//{{AFX_DATA_INIT(CWndProperties)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CWndProperties::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWndProperties)
	DDX_Control(pDX, TAB_Properties, m_TabWndProperties);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWndProperties, CDialog)
	//{{AFX_MSG_MAP(CWndProperties)
	ON_NOTIFY(TCN_SELCHANGE, TAB_Properties, OnSelchangeProperties)
	ON_BN_CLICKED(BTN_CLOSE, OnClose)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWndProperties message handlers

BOOL CWndProperties::OnInitDialog()
{
  m_ClassDlg.SetCurSelHwnd(m_SelWndHandle);
  m_GenderDlg.SetCurSelHwnd(m_SelWndHandle);
  m_ProcessDlg.SetCurSelHwnd(m_SelWndHandle);
  m_StyleDlg.SetCurSelHwnd(m_SelWndHandle);
  m_WndDlg.SetCurSelHwnd(m_SelWndHandle);

  CDialog::OnInitDialog();
  //添加选项卡标题
  m_TabWndProperties.InsertItem(0,_T("General"));
  m_TabWndProperties.InsertItem(1,_T("Styles"));
  m_TabWndProperties.InsertItem(2,_T("Windows"));
  m_TabWndProperties.InsertItem(3,_T("Class"));
  m_TabWndProperties.InsertItem(4,_T("Process"));

  //为选项卡创建对应窗口
  m_GenderDlg.Create(DLG_GENERAL,&m_TabWndProperties);
  m_ProcessDlg.Create(DLG_PROCESS,&m_TabWndProperties);
  m_ClassDlg.Create(DLG_CLASS,&m_TabWndProperties);
  m_StyleDlg.Create(DLG_STYLE,&m_TabWndProperties);
  m_WndDlg.Create(DLG_WINDOWS,&m_TabWndProperties);
  
  
  CRect rect;
  m_TabWndProperties.GetClientRect(&rect);

  //调整盛放对话框的矩形区域
  rect.top += 25;
  rect.left += 10;
  rect.right -= 10;
  rect.bottom -= 10;

  //移动对话框到Tab控件的客户区
  m_GenderDlg.MoveWindow(&rect);
  m_ProcessDlg.MoveWindow(&rect);
  m_ClassDlg.MoveWindow(&rect);
  m_StyleDlg.MoveWindow(&rect);
  m_WndDlg.MoveWindow(&rect);

  //显示窗口
  m_GenderDlg.ShowWindow(SW_NORMAL);
  return TRUE;
}

void CWndProperties::OnSelchangeProperties(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	DWORD nSeletedIndex = m_TabWndProperties.GetCurSel();
  CWnd* tabWnd[] = {&m_GenderDlg,
    &m_StyleDlg,&m_WndDlg,&m_ClassDlg,&m_ProcessDlg};
  DWORD nIndex = 0;
  while(nIndex < m_tabDlgCount)
  {
    if(nSeletedIndex == nIndex)
    {
      tabWnd[nIndex]->ShowWindow(SW_NORMAL);
    }
    else
    {
      tabWnd[nIndex]->ShowWindow(SW_HIDE);
    }
    nIndex++;
  }
	*pResult = 0;
}

void CWndProperties::SetSelWndHandle(HWND hwnd)
{
  m_SelWndHandle = hwnd;
}

void CWndProperties::OnClose() 
{
	// TODO: Add your control notification handler code here
	DestroyWindow();
}


void CWndProperties::OnOK( )
{
  DestroyWindow();
}


void CWndProperties::OnCancel( )
{
  DestroyWindow();
}


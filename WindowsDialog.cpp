// WindowsDialog.cpp : implementation file
//

#include "stdafx.h"
#include "MySpy.h"
#include "WindowsDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWindowsDialog dialog

CWindowsDialog::CWindowsDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CWindowsDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWindowsDialog)
	//}}AFX_DATA_INIT
}


void CWindowsDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWindowsDialog)
	DDX_Control(pDX, LABLE_PREWINDOW, m_textPreWnd);
	DDX_Control(pDX, LABLE_PARENTWINDOW, m_textParentWnd);
	DDX_Control(pDX, LABLE_OWNERWINDOW, m_textOwnerWnd);
	DDX_Control(pDX, LABLE_NEXTWINDOW, m_textNextWnd);
	DDX_Control(pDX, LABLE_FIRSTCHILD, m_textFirstChild);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWindowsDialog, CDialog)
	//{{AFX_MSG_MAP(CWindowsDialog)
//	ON_WM_CTLCOLOR()
	ON_WM_SETCURSOR()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWindowsDialog message handlers

void CWindowsDialog::SetCurSelHwnd(HWND hwnd)
{
  m_CurrSelHwnd = hwnd;
}


BOOL CWindowsDialog::OnInitDialog( )
{
  CDialog::OnInitDialog();
  CString strBuff;
  //获取下一个窗口的句柄
  HWND hwnd = ::GetWindow(m_CurrSelHwnd,GW_HWNDNEXT);
  strBuff.Format(_T("%08X"),(DWORD)hwnd);
  m_textNextWnd.SetWindowText(strBuff);
  m_textNextWnd.Invalidate();
  //获取上一个窗口的句柄
  strBuff.Empty();
  hwnd = ::GetWindow(m_CurrSelHwnd,GW_HWNDPREV);
  strBuff.Format(_T("%08X"),(DWORD)hwnd);
  m_textPreWnd.SetWindowText(strBuff);
  
  //获取当前窗口句柄的父窗口句柄
  strBuff.Empty();
  hwnd = ::GetParent(m_CurrSelHwnd);
  strBuff.Format (_T("%08X"),(DWORD)hwnd);
  m_textParentWnd.SetWindowText(strBuff);

  //获取第一个子窗口句柄
  strBuff.Empty();
  hwnd = ::GetWindow(m_CurrSelHwnd,GW_CHILD);
  strBuff.Format(_T("%08X"),(DWORD)hwnd);
  m_textFirstChild.SetWindowText(strBuff);

  //获取Owner 窗口的句柄
  strBuff.Empty();
  hwnd = ::GetWindow(m_CurrSelHwnd,GW_OWNER);
  strBuff.Format(_T("%08X"),(DWORD)hwnd);
  m_textOwnerWnd.SetWindowText(strBuff);

  return TRUE;
}

//HBRUSH CWindowsDialog::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
//{
//	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
//	
//	// TODO: Change any attributes of the DC here
//	switch(pWnd->GetDlgCtrlID())
//  {
//  case LABLE_NEXTWINDOW:
//  case LABLE_PREWINDOW:
//  case LABLE_PARENTWINDOW:
//  case LABLE_FIRSTCHILD:
//  case LABLE_OWNERWINDOW:
//    pDC->SetTextColor(RGB(0x76,0xEE,0x00));
//    break;
//  }
//	// TODO: Return a different brush if the default is not desired
//	return hbr;
//}


BOOL CWindowsDialog::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
	if(pWnd == GetDlgItem(LABLE_NEXTWINDOW) &&
     pWnd == GetDlgItem(LABLE_PREWINDOW) &&
     pWnd == GetDlgItem(LABLE_PARENTWINDOW) &&
     pWnd == GetDlgItem(LABLE_FIRSTCHILD) &&
     pWnd == GetDlgItem(LABLE_OWNERWINDOW))
  {
    //SetCursor(LoadCursor(NULL,IDC_HAND));
    return TRUE;
  }
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}

void CWindowsDialog::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnLButtonDown(nFlags, point);
}

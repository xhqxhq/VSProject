// ProcessDialog.cpp : implementation file
//

#include "stdafx.h"
#include "MySpy.h"
#include "ProcessDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProcessDialog dialog


CProcessDialog::CProcessDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CProcessDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProcessDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CProcessDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProcessDialog)
	DDX_Control(pDX, LABLE_THREADID, m_ThreadId);
	DDX_Control(pDX, LABLE_PROCESSID, m_textProcessId);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CProcessDialog, CDialog)
	//{{AFX_MSG_MAP(CProcessDialog)
	ON_WM_LBUTTONDOWN()
	ON_WM_CTLCOLOR()
	ON_WM_SETCURSOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProcessDialog message handlers

void CProcessDialog::SetCurSelHwnd(HWND hwnd)
{
  m_CurSelHwnd = hwnd;
}


BOOL CProcessDialog::OnInitDialog( )
{
  CDialog::OnInitDialog();
  DWORD dwThreadId = 0;
  DWORD dwProcessId = 0;
  dwThreadId = GetWindowThreadProcessId(m_CurSelHwnd,&dwProcessId);
  CString strBuff;
  strBuff.Format(_T("%08X"),dwProcessId);
  m_textProcessId.SetWindowText(strBuff);
  strBuff.Empty();
  strBuff.Format(_T("%08X"),dwThreadId);
  m_ThreadId.SetWindowText(strBuff);
  return TRUE;
}

HBRUSH CProcessDialog::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
		switch(pWnd->GetDlgCtrlID())
    {
    case LABLE_PROCESSID:
    case LABLE_THREADID:
      pDC->SetTextColor(RGB(0x76,0xEE,0x00));
      break;
  }
	// TODO: Return a different brush if the default is not desired
	return hbr;
}


BOOL CProcessDialog::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default
  if(pWnd == GetDlgItem(LABLE_THREADID) ||
     pWnd == GetDlgItem(LABLE_PROCESSID))
  {
    //SetCursor(LoadCursor(NULL,IDC_HAND));
    return TRUE;
  }
	return CDialog::OnSetCursor(pWnd, nHitTest, message);
}

void CProcessDialog::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnLButtonDown(nFlags, point);
}



// GeneralDialog.cpp : implementation file
//

#include "stdafx.h"
#include "MySpy.h"
#include "GeneralDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGeneralDialog dialog


CGeneralDialog::CGeneralDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CGeneralDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGeneralDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CGeneralDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGeneralDialog)
	DDX_Control(pDX, LABLE_WNDPROC, m_WindowProc);
	DDX_Control(pDX, LABLE_WINDHANDLE, m_WindowHandle);
	DDX_Control(pDX, LABLE_USERDATA, m_UserData);
	DDX_Control(pDX, LABLE_RESTOREDRECT, m_RestoredRect);
	DDX_Control(pDX, LABLE_RECTANGLE, m_Rectangel);
	DDX_Control(pDX, LABLE_MENUHANDLE, m_MenumHandle);
	DDX_Control(pDX, LABLE_INSTANCEHANDLE, m_Instancehandle);
	DDX_Control(pDX, LABLE_CLIENTRECT, m_ClientRect);
	DDX_Control(pDX, CMB_WINDOWBYTES, m_WndBytes);
	DDX_Control(pDX, EDT_WINDOWCAPTION, m_WndCaption);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGeneralDialog, CDialog)
	//{{AFX_MSG_MAP(CGeneralDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGeneralDialog message handlers

void CGeneralDialog::SetCurSelHwnd(HWND hwnd)
{
  m_CurrSelHwnd = hwnd;
}

BOOL CGeneralDialog::OnInitDialog()
{
  CDialog::OnInitDialog();
  //��ȡ���ڱ���
  CString strBuff;
  ::GetWindowText(m_CurrSelHwnd,
                  strBuff.GetBufferSetLength(MAXBYTE),
                  MAXBYTE);
  //������ʾ���ڱ����Edit�ؼ�
  m_WndCaption.SetWindowText(strBuff);
  m_WndCaption.SetReadOnly();

  //���ô��ھ��
  strBuff.Empty();
  strBuff.Format(_T("%08X"),(DWORD)m_CurrSelHwnd);
  m_WindowHandle.SetWindowText(strBuff);

  //��ȡ���ڹ��̺�����ַ
  strBuff.Empty();
  DWORD dwRet = GetWindowLong(m_CurrSelHwnd,GWL_WNDPROC);
//  DWORD dwErrorRet = GetLastError();
  if(dwRet)
  {
    strBuff.Format(_T("%08X"),dwRet);
  }
  else
  {
    strBuff.Format(_T("%s"),_T("[Unavailable][Unicode]"));
  }
  m_WindowProc.SetWindowText(strBuff);

  //��ȡ���ھ�������
  strBuff.Empty();
  CRect rect;
  ::GetWindowRect(m_CurrSelHwnd,&rect);
  strBuff.Format(_T("[%d,%d]-[%d,%d],%dx%d"),
                  rect.left,rect.top,rect.right,rect.bottom,
                  rect.right-rect.left,rect.bottom-rect.top);
  m_Rectangel.SetWindowText(strBuff);

  //��ȡ���ڻָ���������
  strBuff.Empty();
  WINDOWPLACEMENT wndPlacement;
  wndPlacement.flags = 0;
  wndPlacement.length = sizeof(WINDOWPLACEMENT);
  ::GetWindowPlacement(m_CurrSelHwnd,&wndPlacement);
  strBuff.Format(_T("[%d,%d]-[%d,%d],%dx%d"),
      wndPlacement.rcNormalPosition.left,
      wndPlacement.rcNormalPosition.top,
      wndPlacement.rcNormalPosition.right,
      wndPlacement.rcNormalPosition.bottom,
      wndPlacement.rcNormalPosition.right - 
      wndPlacement.rcNormalPosition.left,
      wndPlacement.rcNormalPosition.bottom - 
      wndPlacement.rcNormalPosition.top);
  m_RestoredRect.SetWindowText(strBuff);

  //��ȡ�ͻ�������
  ::GetClientRect(m_CurrSelHwnd,&rect);
  strBuff.Empty();
  strBuff.Format(_T("[%d,%d]-[%d,%d],%dx%d"),
    rect.left,rect.top,rect.right,rect.bottom,
    rect.right-rect.left,rect.bottom-rect.top);
  m_ClientRect.SetWindowText(strBuff);

  //��ȡ����Ӧ�ó���ʵ�����
  dwRet = ::GetWindowLong(m_CurrSelHwnd,GWL_HINSTANCE);
  strBuff.Empty();
  if(dwRet)
  {
    strBuff.Format(_T("%08X"),dwRet);
  }
  else
  {
    strBuff.Format(_T("%s"),_T("[Unavailable][Unicode]"));
  }
  m_Instancehandle.SetWindowText(strBuff);

  //��ȡ���ڲ˵����
  strBuff.Empty();
  HMENU hMenu = ::GetMenu(m_CurrSelHwnd);
  strBuff.Format(_T("%08X"),hMenu);
  m_MenumHandle.SetWindowText(strBuff);

  //��ȡ�û�����
  dwRet = ::GetWindowLong(m_CurrSelHwnd,GWL_USERDATA);
  strBuff.Empty();
  strBuff.Format(_T("%08X"),dwRet);
  m_UserData.SetWindowText(strBuff);

  UpdateData(FALSE);
  return TRUE;
}

// StyleDialog.cpp : implementation file
//

#include "stdafx.h"
#include "MySpy.h"
#include "StyleDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStyleDialog dialog

const CStyleDialog::MapWndStyle CStyleDialog::allWndStyle[] = 
{
  MAPWINDOWSTYLE(WS_BORDER),
  MAPWINDOWSTYLE(WS_CAPTION),
  MAPWINDOWSTYLE(WS_CHILD),
  MAPWINDOWSTYLE(WS_CHILDWINDOW),
  MAPWINDOWSTYLE(WS_CLIPCHILDREN),
  MAPWINDOWSTYLE(WS_CLIPSIBLINGS),
  MAPWINDOWSTYLE(WS_DISABLED),
  MAPWINDOWSTYLE(WS_DLGFRAME),
  MAPWINDOWSTYLE(WS_GROUP),
  MAPWINDOWSTYLE(WS_HSCROLL),
  MAPWINDOWSTYLE(WS_ICONIC),
  MAPWINDOWSTYLE(WS_MAXIMIZE),
  MAPWINDOWSTYLE(WS_MAXIMIZEBOX),
  MAPWINDOWSTYLE(WS_MINIMIZE),
  MAPWINDOWSTYLE(WS_MINIMIZEBOX),
  MAPWINDOWSTYLE(WS_OVERLAPPED),
  MAPWINDOWSTYLE(WS_OVERLAPPEDWINDOW),
  MAPWINDOWSTYLE(WS_POPUP),
  MAPWINDOWSTYLE(WS_SIZEBOX),
  MAPWINDOWSTYLE(WS_POPUPWINDOW),
  MAPWINDOWSTYLE(WS_SYSMENU),
  MAPWINDOWSTYLE(WS_TABSTOP),
  MAPWINDOWSTYLE(WS_THICKFRAME),
  MAPWINDOWSTYLE(WS_TILED),
  MAPWINDOWSTYLE(WS_TILEDWINDOW),
  MAPWINDOWSTYLE(WS_VISIBLE),
  MAPWINDOWSTYLE(WS_VSCROLL),
};


const CStyleDialog::MapWndStyle CStyleDialog::allWndExStyle[] = 
{
    //Extend Window Style
    MAPWINDOWSTYLE(WS_EX_ACCEPTFILES),
    MAPWINDOWSTYLE(WS_EX_APPWINDOW),
    MAPWINDOWSTYLE(WS_EX_CLIENTEDGE),
    //MAPWINDOWSTYLE(WS_EX_COMPOSITED),
    MAPWINDOWSTYLE(WS_EX_CONTEXTHELP),
    MAPWINDOWSTYLE(WS_EX_CONTROLPARENT),
    MAPWINDOWSTYLE(WS_EX_DLGMODALFRAME),
    //MAPWINDOWSTYLE(WS_EX_LAYERED),
    //MAPWINDOWSTYLE(WS_EX_LAYOUTRTL),
    MAPWINDOWSTYLE(WS_EX_LEFT),
    MAPWINDOWSTYLE(WS_EX_LEFTSCROLLBAR),
    MAPWINDOWSTYLE(WS_EX_LTRREADING),
    MAPWINDOWSTYLE(WS_EX_MDICHILD),
    //MAPWINDOWSTYLE(WS_EX_NOACTIVATE),
    //MAPWINDOWSTYLE(WS_EX_NOINHERITLAYOUT),
    MAPWINDOWSTYLE(WS_EX_NOPARENTNOTIFY),
    MAPWINDOWSTYLE(WS_EX_OVERLAPPEDWINDOW),
    MAPWINDOWSTYLE(WS_EX_OVERLAPPEDWINDOW),
    MAPWINDOWSTYLE(WS_EX_PALETTEWINDOW),
    MAPWINDOWSTYLE(WS_EX_RIGHT),
    MAPWINDOWSTYLE(WS_EX_RIGHTSCROLLBAR),
    MAPWINDOWSTYLE(WS_EX_RTLREADING),
    MAPWINDOWSTYLE(WS_EX_STATICEDGE),
    MAPWINDOWSTYLE(WS_EX_TOOLWINDOW),
    MAPWINDOWSTYLE(WS_EX_TOPMOST),
    MAPWINDOWSTYLE(WS_EX_TRANSPARENT),
    MAPWINDOWSTYLE(WS_EX_WINDOWEDGE)
};
CStyleDialog::CStyleDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CStyleDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStyleDialog)
	//}}AFX_DATA_INIT
}


void CStyleDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStyleDialog)
	DDX_Control(pDX, LBX_EXTENDSTYLES, m_wndExStyles);
	DDX_Control(pDX, LABLE_EXTENDEDSTYLES, m_textExWndStyles);
	DDX_Control(pDX, LABLE_WINDOWSTYLES, m_textWndStyles);
	DDX_Control(pDX, LB_WINDOWSTYLES, m_wndStyles);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStyleDialog, CDialog)
	//{{AFX_MSG_MAP(CStyleDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStyleDialog message handlers

void CStyleDialog::SetCurSelHwnd(HWND hwnd)
{
  m_CurSelHwnd = hwnd;
}

BOOL CStyleDialog::OnInitDialog( )
{
  CDialog::OnInitDialog();
//  DWORD dwLstBoxStyle = WS_CHILD|WS_VISIBLE|LBS_STANDARD|WS_HSCROLL;
//  m_wndExStyles.Create(dwLstBoxStyle,)
  CString strBuff;
  //获取窗口风格
  DWORD dwRet = ::GetWindowLong(m_CurSelHwnd,GWL_STYLE);
  //显示风格的十六进制数
  strBuff.Format(_T("%08X"),dwRet);
  m_textWndStyles.SetWindowText(strBuff);

  //显示窗口风格的宏名
  int nStyleCount = sizeof(allWndStyle)/sizeof(MapWndStyle);
  int iIndex;
  for(iIndex = 0; iIndex < nStyleCount; iIndex++)
  {
    if(dwRet & allWndStyle[iIndex].nWndStyle)
    {
      m_wndStyles.AddString(allWndStyle[iIndex].lpWndStyleName);
    }
    
  }

  //获取窗口扩展风格
  dwRet = ::GetWindowLong(m_CurSelHwnd,GWL_EXSTYLE);
  //显示扩展风格的十六进制数
  strBuff.Empty();
  strBuff.Format(_T("%08X"),dwRet);
  m_textExWndStyles.SetWindowText(strBuff);

  //显示窗口扩展风格的宏名
  nStyleCount = sizeof(allWndExStyle)/sizeof(MapWndStyle);
  for(iIndex = 0; iIndex < nStyleCount; iIndex++)
  {
    if(dwRet & allWndStyle[iIndex].nWndStyle)
    {
      m_wndExStyles.AddString(allWndExStyle[iIndex].lpWndStyleName);
    }
  }
  return TRUE;
}

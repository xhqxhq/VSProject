// ClassDialog.cpp : implementation file
//

#include "stdafx.h"
#include "MySpy.h"
#include "ClassDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClassDialog dialog

#define  MAPCSTOSTRING(cs) {cs,_T(#cs) }
const CClassDialog::MAPCLASSSTYLE CClassDialog::classStyle[] = 
{
 MAPCSTOSTRING(CS_VREDRAW),
 MAPCSTOSTRING(CS_HREDRAW),
 MAPCSTOSTRING(CS_DBLCLKS),
 MAPCSTOSTRING(CS_OWNDC),
 MAPCSTOSTRING(CS_CLASSDC),
 MAPCSTOSTRING(CS_PARENTDC),
 MAPCSTOSTRING(CS_NOCLOSE),
 MAPCSTOSTRING(CS_SAVEBITS),
 MAPCSTOSTRING(CS_BYTEALIGNCLIENT),
 MAPCSTOSTRING(CS_BYTEALIGNWINDOW),
 MAPCSTOSTRING(CS_GLOBALCLASS),
 MAPCSTOSTRING(CS_IME),
};



CClassDialog::CClassDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CClassDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CClassDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CClassDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClassDialog)
	DDX_Control(pDX, LABLE_BKGNDBRUSH, m_textBrushHandle);
	DDX_Control(pDX, LABLE_CURSORHANDLE, m_textCursorHandle);
	DDX_Control(pDX, LABLE_ICONHANDLE, m_textIconHandle);
	DDX_Control(pDX, LABLE_MENUNAME, m_textMenuName);
	DDX_Control(pDX, LABLE_WINDOWPROC, m_textWindowProc);
	DDX_Control(pDX, LABLE_WINDOWBYTES, m_textWindowBytes);
	DDX_Control(pDX, LABLE_INSTANCEHANDLE, m_textInstanceHandle);
	DDX_Control(pDX, LABLE_CLASSAUOM, m_textClassAtom);
	DDX_Control(pDX, CBX_CLASSBYTES, m_cbxClassBytes);
	DDX_Control(pDX, LABLE_CLASSBYTES, m_textClassBytes);
	DDX_Control(pDX, CMB_CLASSSTYLES, m_cmbClassStyles);
	DDX_Control(pDX, LABLE_CLASSSTYLES, m_textClassStyles);
	DDX_Control(pDX, EDT_CLASSNAME, m_editClassName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CClassDialog, CDialog)
	//{{AFX_MSG_MAP(CClassDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClassDialog message handlers

void CClassDialog::SetCurSelHwnd(HWND hwnd)
{
  m_CurrSelHwnd = hwnd;
}


BOOL CClassDialog::OnInitDialog( )
{
  CDialog::OnInitDialog();
  CString strBuff;
  DWORD dwRet = 0;
  //获取Class Name
  dwRet = GetClassName(m_CurrSelHwnd,
                       strBuff.GetBufferSetLength(MAXBYTE),
                       MAXBYTE);
  m_editClassName.SetWindowText(strBuff);
  m_editClassName.SetReadOnly();
  
  //获取Class Styles
  int iIndex;
  dwRet = GetClassLong(m_CurrSelHwnd,GCL_STYLE);
  strBuff.Empty();
  strBuff.Format(_T("%X"),dwRet);
  m_textClassStyles.SetWindowText(strBuff);

  const int nCsCount = sizeof(classStyle)/sizeof(MAPCLASSSTYLE);
  for(iIndex = 0; iIndex < nCsCount; iIndex++)
  {
    if(dwRet & classStyle[iIndex].m_uClassStyle)
    {
      m_cmbClassStyles.AddString(classStyle[iIndex].m_CSString);
    }
  }
  m_cmbClassStyles.SetCurSel(0);
  //获取Class Bytes
  dwRet = GetClassLong(m_CurrSelHwnd,GCL_CBCLSEXTRA);
  if(dwRet)
  {
    
  }
  else
  {
    m_textClassBytes.SetWindowText(_T("0"));
    m_cbxClassBytes.EnableWindow(FALSE);
  }

  //获取Class Atom
  dwRet = GetClassLong(m_CurrSelHwnd,GCW_ATOM);
  strBuff.Empty();
  strBuff.Format(_T("%08X"),dwRet);
  m_textClassAtom.SetWindowText(strBuff);

  //获取Instance Handle
  dwRet = GetClassLong(m_CurrSelHwnd,GCL_HMODULE);
  strBuff.Empty();
  strBuff.Format(_T("%08X"),dwRet);
  m_textInstanceHandle.SetWindowText(strBuff);

  //获取Window Bytes
  dwRet = GetClassLong(m_CurrSelHwnd,GCL_CBWNDEXTRA);
  strBuff.Empty();
  strBuff.Format(_T("%d"),dwRet);
  m_textWindowBytes.SetWindowText(strBuff);

  //获取WIndow Proc
  dwRet = GetClassLong(m_CurrSelHwnd,GCL_WNDPROC);
  strBuff.Empty();
  strBuff.Format(_T("%08X"),dwRet);
  m_textWindowProc.SetWindowText(strBuff);

  //获取Menu Name
  dwRet = GetClassLong(m_CurrSelHwnd,GCL_MENUNAME);
  if(dwRet)
  {
    if(lstrlen((LPCTSTR)dwRet))
    {
      m_textMenuName.SetWindowText((LPCTSTR)dwRet);
    }
    else
    {
       m_textMenuName.SetWindowText(_T("[None]"));
    }
  }
  else
  {
    m_textMenuName.SetWindowText(_T("[Unavaliable]"));
  }
  UpdateData(FALSE);

  //获取Icon Handle
  dwRet = GetClassLong(m_CurrSelHwnd,GCL_HICON);
  strBuff.Empty();
  if(dwRet)
  {
    strBuff.Format(_T("%08X"),dwRet);
    m_textIconHandle.SetWindowText(strBuff);
  }
  else
  {
    m_textIconHandle.SetWindowText(_T("[None]"));
  }
  
  //获取Cursor Handle
  dwRet = GetClassLong(m_CurrSelHwnd,GCL_HCURSOR);
  strBuff.Empty();
  m_textCursorHandle.SetWindowText(_T("IDC_ARROW"));

  //获取Bkgnd Brush
  dwRet = GetClassLong(m_CurrSelHwnd,GCL_HBRBACKGROUND);
  strBuff.Empty();
  if(dwRet)
  {
    strBuff.Format(_T("%08X"),dwRet);
    m_textBrushHandle.SetWindowText(strBuff);
  }
  else
  {
    m_textBrushHandle.SetWindowText(_T("[None]"));
  }
  return TRUE;
}

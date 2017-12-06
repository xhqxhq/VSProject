// SelStatic.cpp : implementation file
//

#include "stdafx.h"
#include "MySpy.h"
#include "SelStatic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSelStatic

CSelStatic::CSelStatic()
{
}

CSelStatic::~CSelStatic()
{
}


BEGIN_MESSAGE_MAP(CSelStatic, CStatic)
	//{{AFX_MSG_MAP(CSelStatic)
	ON_CONTROL_REFLECT(BN_CLICKED, OnClicked)
	ON_WM_CTLCOLOR()
	ON_WM_SETCURSOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSelStatic message handlers

void CSelStatic::PreSubclassWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	DWORD dwStyle = GetStyle();
  SetWindowLong(GetSafeHwnd(),GWL_STYLE,dwStyle|SS_OWNERDRAW);
	//CStatic::PreSubclassWindow();
}













void CSelStatic::OnClicked() 
{
	// TODO: Add your control notification handler code here
	int a = 0;
}

HBRUSH CSelStatic::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CStatic::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here

   pDC->SetTextColor(RGB(0x76,0xEE,0x00));
   CRect rect;
   GetWindowRect(&rect);
   pDC->DrawText(_T("xxxx"),rect,DT_LEFT );
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

BOOL CSelStatic::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	// TODO: Add your message handler code here and/or call default

  //::SetCursor(LoadCursor(NULL,IDC_HAND));
  InvalidateRect(NULL,FALSE);
    return TRUE;
}



void CSelStatic::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
  // TODO:  Add your code to draw the specified item
  CDC dc;
  dc.Attach(lpDrawItemStruct->hDC);
  dc.SetTextColor(RGB(0x76, 0xEE, 0x00));
  dc.DrawText(_T("...."), &lpDrawItemStruct->rcItem, DT_LEFT);
  dc.Detach();
}

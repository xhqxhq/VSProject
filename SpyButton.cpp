// SpyButton.cpp : implementation file
//

#include "stdafx.h"
#include "MySpy.h"
#include "SpyButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpyButton

CSpyButton::CSpyButton()
{
  m_hCursor = AfxGetApp()->LoadCursor(CURSOR_SPY);
  m_hIconPushed = AfxGetApp()->LoadIcon(ICN_PUSHED);
  m_hIconUnPush = AfxGetApp()->LoadIcon(ICN_UNPUSH);
  m_bIsCapture = FALSE;
  m_hOldCursor = NULL;
  m_lastWnd = NULL;
}

CSpyButton::~CSpyButton()
{
}


BEGIN_MESSAGE_MAP(CSpyButton, CButton)
	//{{AFX_MSG_MAP(CSpyButton)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpyButton message handlers



void CSpyButton::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
  //修改按钮的光标，并保存之前的光标
  m_hOldCursor = (HCURSOR)SetClassLong(GetSafeHwnd(),
    GCL_HCURSOR, (LONG)m_hCursor);
  SetCapture();
  m_bIsCapture = TRUE;
	CButton::OnLButtonDown(nFlags, point);
}

void CSpyButton::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
  if (m_bIsCapture)
  {
    ReleaseCapture();
    SetClassLong(GetSafeHwnd(), GCL_HCURSOR, (LONG)m_hOldCursor);
    InvalidateRect(NULL);
    ::SetCursor(m_hOldCursor);
    m_bIsCapture = FALSE;
  }

  //擦除最后一个被捕获窗口的黑色窗口
  if (m_lastWnd != NULL && !m_bIsCapture)
  {
    CDC spyDc;
    spyDc.Attach(::GetDC(NULL)); //获取屏幕DC
    spyDc.SetROP2(R2_XORPEN); //画笔与背景颜色异或

    //创建实心画笔和一个空心画刷用来突出显示被捕捉窗口
    CPen pen;
    pen.CreatePen(PS_SOLID, 6, RGB(255, 255, 255));
    LOGBRUSH logBrush;
    logBrush.lbStyle = BS_NULL;
    CBrush brush;
    brush.CreateBrushIndirect(&logBrush);

    //设置新的画笔画刷并保存之前的
    HGDIOBJ hOldPenObj = spyDc.SelectObject(pen);
    HGDIOBJ hOldBrushObj = spyDc.SelectObject(brush);

    //获取原窗口的大小
    CWnd* pOldWnd = FromHandle(m_lastWnd);
    CRect rect;
    pOldWnd->GetWindowRect(&rect);
    spyDc.Rectangle(&rect);

    spyDc.SelectObject(hOldPenObj);
    spyDc.SelectObject(hOldBrushObj);
    
    spyDc.Detach();
    m_lastWnd = NULL;
  }
	CButton::OnLButtonUp(nFlags, point);
}

void CSpyButton::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
  CPoint tepPoint = point;
  if (m_bIsCapture)
  {
    ::SetCursor(m_hCursor); //设置鼠标光标为捕获时的光标
    CDC spyDc;
    spyDc.Attach(::GetDC(NULL)); //获取屏幕DC
    spyDc.SetROP2(R2_XORPEN); //画笔与背景颜色异或

    CRect rc;//判断光标是否处于自身
    AfxGetApp()->GetMainWnd()->GetWindowRect(&rc);
    ClientToScreen(&point);
    if(rc.PtInRect(point))
    {
      spyDc.Detach();
      return;
    }

    CWnd* pParent = GetParent();
    CWnd* pCurrWnd = WindowFromPoint(point); //获取当前鼠标所在位置的窗口
    if (pCurrWnd->GetSafeHwnd() == m_lastWnd) //如果当前捕捉窗口依旧是上次捕捉窗口
    {
      spyDc.Detach();
      return;
    }
    
    if(pCurrWnd == pParent)
    {
      return;
    }

    //获取被捕捉窗口的大小
    CRect captureWndRect;
    pCurrWnd->GetWindowRect(&captureWndRect);

    //创建实心画笔和一个空心画刷用来突出显示被捕捉窗口
    CPen pen;
    pen.CreatePen(PS_SOLID, 6, RGB(255, 255, 255));
    LOGBRUSH logBrush;
    logBrush.lbStyle = BS_NULL;
    CBrush brush;
    brush.CreateBrushIndirect(&logBrush);

    //设置新的画笔画刷并保存之前的
    HGDIOBJ hOldPenObj = spyDc.SelectObject(pen);
    HGDIOBJ hOldBrushObj = spyDc.SelectObject(brush);

    //当鼠标移出原来捕获的窗口时，取消黑框
    if (m_lastWnd != pCurrWnd->GetSafeHwnd() && m_lastWnd != NULL)
    {
      //获取原窗口的大小
      CWnd* pOldWnd = FromHandle(m_lastWnd);
      CRect rect;
      pOldWnd->GetWindowRect(&rect);
      spyDc.Rectangle(&rect);
    }

    spyDc.Rectangle(&captureWndRect);
    spyDc.SelectObject(hOldPenObj);
    spyDc.SelectObject(hOldBrushObj);
    
    spyDc.Detach();
    m_lastWnd = pCurrWnd->GetSafeHwnd();
    GetParent()->InvalidateRect(NULL,FALSE);
    //SendDlgItemMessage(DLG_WINDOWSEARCH,WM_DRAWITEM);
  }
	CButton::OnMouseMove(nFlags, point);
}


void CSpyButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
  	// TODO: Add your code to draw the specified item
  	CDC btnDc;
    btnDc.Attach(lpDrawItemStruct->hDC);
    if(m_bIsCapture)
    {
      btnDc.DrawIcon(lpDrawItemStruct->rcItem.left,
                     lpDrawItemStruct->rcItem.top,
                     m_hIconPushed);

    }
    else
    {
      btnDc.DrawIcon(lpDrawItemStruct->rcItem.left,
                     lpDrawItemStruct->rcItem.top,
                     m_hIconUnPush);
    }
    btnDc.Detach();
}

BOOL CSpyButton::OnInitDialog( )
{
  SetIcon(m_hIconUnPush);
  return TRUE;
}

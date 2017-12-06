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
  //�޸İ�ť�Ĺ�꣬������֮ǰ�Ĺ��
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

  //�������һ�������񴰿ڵĺ�ɫ����
  if (m_lastWnd != NULL && !m_bIsCapture)
  {
    CDC spyDc;
    spyDc.Attach(::GetDC(NULL)); //��ȡ��ĻDC
    spyDc.SetROP2(R2_XORPEN); //�����뱳����ɫ���

    //����ʵ�Ļ��ʺ�һ�����Ļ�ˢ����ͻ����ʾ����׽����
    CPen pen;
    pen.CreatePen(PS_SOLID, 6, RGB(255, 255, 255));
    LOGBRUSH logBrush;
    logBrush.lbStyle = BS_NULL;
    CBrush brush;
    brush.CreateBrushIndirect(&logBrush);

    //�����µĻ��ʻ�ˢ������֮ǰ��
    HGDIOBJ hOldPenObj = spyDc.SelectObject(pen);
    HGDIOBJ hOldBrushObj = spyDc.SelectObject(brush);

    //��ȡԭ���ڵĴ�С
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
    ::SetCursor(m_hCursor); //���������Ϊ����ʱ�Ĺ��
    CDC spyDc;
    spyDc.Attach(::GetDC(NULL)); //��ȡ��ĻDC
    spyDc.SetROP2(R2_XORPEN); //�����뱳����ɫ���

    CRect rc;//�жϹ���Ƿ�������
    AfxGetApp()->GetMainWnd()->GetWindowRect(&rc);
    ClientToScreen(&point);
    if(rc.PtInRect(point))
    {
      spyDc.Detach();
      return;
    }

    CWnd* pParent = GetParent();
    CWnd* pCurrWnd = WindowFromPoint(point); //��ȡ��ǰ�������λ�õĴ���
    if (pCurrWnd->GetSafeHwnd() == m_lastWnd) //�����ǰ��׽�����������ϴβ�׽����
    {
      spyDc.Detach();
      return;
    }
    
    if(pCurrWnd == pParent)
    {
      return;
    }

    //��ȡ����׽���ڵĴ�С
    CRect captureWndRect;
    pCurrWnd->GetWindowRect(&captureWndRect);

    //����ʵ�Ļ��ʺ�һ�����Ļ�ˢ����ͻ����ʾ����׽����
    CPen pen;
    pen.CreatePen(PS_SOLID, 6, RGB(255, 255, 255));
    LOGBRUSH logBrush;
    logBrush.lbStyle = BS_NULL;
    CBrush brush;
    brush.CreateBrushIndirect(&logBrush);

    //�����µĻ��ʻ�ˢ������֮ǰ��
    HGDIOBJ hOldPenObj = spyDc.SelectObject(pen);
    HGDIOBJ hOldBrushObj = spyDc.SelectObject(brush);

    //������Ƴ�ԭ������Ĵ���ʱ��ȡ���ڿ�
    if (m_lastWnd != pCurrWnd->GetSafeHwnd() && m_lastWnd != NULL)
    {
      //��ȡԭ���ڵĴ�С
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

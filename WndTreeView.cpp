// WndTreeView.cpp : implementation file
//
#include <afxcview.h>
#include "stdafx.h"
#include "MySpy.h"
#include "WndTreeView.h"
#include "WndProperties.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWndTreeView

IMPLEMENT_DYNCREATE(CWndTreeView, CTreeView)

CWndTreeView::CWndTreeView()
{
}

CWndTreeView::~CWndTreeView()
{
}


BEGIN_MESSAGE_MAP(CWndTreeView, CTreeView)
	//{{AFX_MSG_MAP(CWndTreeView)
	ON_NOTIFY_REFLECT(NM_DBLCLK, OnDblclk)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(MN_PROPERTIERS, OnPropertiers)
	ON_COMMAND(MN_REFRESH, OnRefresh)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWndTreeView drawing

void CWndTreeView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// CWndTreeView diagnostics

#ifdef _DEBUG
void CWndTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CWndTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWndTreeView message handlers


BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
  CList<HWND,HWND>* pWndInfo = (CList<HWND,HWND>*)lParam;
  pWndInfo->AddTail(hwnd);
  return TRUE;
}

void CWndTreeView::OnInitialUpdate() 
{
	CTreeView::OnInitialUpdate();
	// TODO: Add your specialized code here and/or call the base class
  CTreeCtrl& treeCtrl = GetTreeCtrl();
  m_lstImg.Create(16,16,ILC_COLOR16,4,2);
  HICON hIcon1 = AfxGetApp()->LoadIcon(ICN_WND);
  HICON hIcon2 = AfxGetApp()->LoadIcon(ICN_WNDSELECTED);
  m_lstImg.Add(hIcon1);
  m_lstImg.Add(hIcon2);
  treeCtrl.SetImageList(&m_lstImg,TVSIL_NORMAL);
  FrushTreeData();
}

void CWndTreeView::FrushTreeData()
{
  //��ȡ����ͼ���������ؼ�
  CTreeCtrl& treeCtrl = GetTreeCtrl();
  //������е���
  int nCout = treeCtrl.GetCount();
  treeCtrl.DeleteAllItems();
  //�޸����ؼ����
  treeCtrl.ModifyStyle(0,TVS_HASBUTTONS|TVS_LINESATROOT|
    TVS_HASLINES|TVS_SINGLEEXPAND );
  //��ȡ����Top-Level����
  CList<HWND,HWND> Wndlsts; //���ж��㴰�ھ��
  EnumWindows(EnumWindowsProc,(LPARAM)&Wndlsts);
  
  CString strWndTitle;
  CString strClassName;
  CString strOutput;
  
  //��ȡ���洰��
  HWND currHwnd = ::GetDesktopWindow();
  ::GetWindowText(currHwnd,strWndTitle.GetBufferSetLength(MAXBYTE),MAXBYTE);
  ::GetClassName(currHwnd,strClassName.GetBufferSetLength(MAXBYTE),MAXBYTE);
  strOutput.Format(_T("%08X \"%s\" %s"),currHwnd,strWndTitle,strClassName);
  //�������洰��
  HTREEITEM curTreeItem =  treeCtrl.InsertItem(strOutput,0,1);
  treeCtrl.SetItemData(curTreeItem,(DWORD)currHwnd);
  CList<tagMultiWnd,tagMultiWnd> lstSubWnd;
  CList<tagMultiWnd,tagMultiWnd> lstAllWnd;
  //������ͼ�в��������еĴ���
  while(!Wndlsts.IsEmpty())
  {
    //�������л�ȡһ���Ӵ���
    currHwnd = Wndlsts.RemoveHead();
    ::GetWindowText(currHwnd,strWndTitle.GetBufferSetLength(MAXBYTE),MAXBYTE);
    ::GetClassName(currHwnd,strClassName.GetBufferSetLength(MAXBYTE),MAXBYTE);
    strOutput.Format(_T("%08X \"%s\" %s"), currHwnd, strWndTitle, strClassName);
    //��������ͼ��
    HTREEITEM newTreeItem = treeCtrl.InsertItem(strOutput,0,1,curTreeItem);
    //���ò�����������Ϊ����Ĵ��ھ��
    treeCtrl.SetItemData(newTreeItem,(DWORD)currHwnd);
    lstAllWnd.AddTail(tagMultiWnd(currHwnd,newTreeItem));
    //��ǰ�Ӵ��ڻ����Ӵ��ڣ���¼��ǰ�Ӵ��ڵľ���͸����
    //����λ�ã�Ȼ����뵽lsthItem������
    if(::GetWindow(currHwnd,GW_CHILD) != NULL)
    {
      lstSubWnd.AddTail(tagMultiWnd(currHwnd,newTreeItem));
    }
    
    strWndTitle.Empty();
    strClassName.Empty();
    strOutput.Empty();
  }

  while(!lstSubWnd.IsEmpty())
  {
    tagMultiWnd subWnd = lstSubWnd.RemoveHead();
    EnumChildWindows(subWnd.m_hWnd,EnumWindowsProc,(DWORD)&Wndlsts);
    while(!Wndlsts.IsEmpty())
    {
      currHwnd = Wndlsts.RemoveHead();
      ::GetWindowText(currHwnd,strWndTitle.GetBufferSetLength(MAXBYTE),MAXBYTE);
      ::GetClassName(currHwnd,strClassName.GetBufferSetLength(MAXBYTE),MAXBYTE);
      strOutput.Format(_T("%08X \"%s\" %s"), currHwnd, strWndTitle, strClassName);

      //Ѱ�Ҹô��ڵĸ����ڣ��Դ�ȷ��������ͼ�еĲ���λ��
      tagMultiWnd searchNode;
      searchNode.m_hWnd = ::GetParent(currHwnd);
      POSITION pos = lstAllWnd.Find(searchNode);
      tagMultiWnd insertLoc;
      if(pos != NULL)
      {
        insertLoc = lstAllWnd.GetAt(pos);
        //��������ͼ��
        HTREEITEM newTreeItem = treeCtrl.InsertItem(strOutput,0,1,insertLoc.m_hTreeItem);
        lstAllWnd.AddTail(tagMultiWnd(currHwnd,newTreeItem));
        //���ò�����������Ϊ����Ĵ��ھ��
        treeCtrl.SetItemData(newTreeItem,(DWORD)currHwnd);
      }
    }
  }
}


void CWndTreeView::OnDblclk(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
  //��ȡ��˫��������Ĺ������ھ��
  CTreeCtrl& treeCtrl = GetTreeCtrl();
  HTREEITEM hSelItem = treeCtrl.GetSelectedItem();
  HWND selHwnd = (HWND)treeCtrl.GetItemData(hSelItem);
  m_propertiesDlg.SetSelWndHandle(selHwnd);
  m_propertiesDlg.Create(DLG_WNDPROPERTIES,this);
  m_propertiesDlg.ShowWindow(SW_SHOW);
	*pResult = 0;
}

void CWndTreeView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CMenu mn;
  mn.LoadMenu(MN_RBTNDOWN);
  CMenu* pMn = mn.GetSubMenu(0);
  ClientToScreen(&point);
  pMn->TrackPopupMenu(TPM_LEFTALIGN|TPM_RIGHTBUTTON,
    point.x,point.y,this);
	CTreeView::OnRButtonDown(nFlags, point);
}

void CWndTreeView::OnPropertiers() 
{
	// TODO: Add your command handler code here
  //��ȡ��˫��������Ĺ������ھ��
  CTreeCtrl& treeCtrl = GetTreeCtrl();
  HTREEITEM hSelItem = treeCtrl.GetSelectedItem();
  HWND selHwnd = (HWND)treeCtrl.GetItemData(hSelItem);
  m_propertiesDlg.SetSelWndHandle(selHwnd);
  m_propertiesDlg.Create(DLG_WNDPROPERTIES,this);
  m_propertiesDlg.ShowWindow(SW_SHOW);
}

void CWndTreeView::OnRefresh() 
{
	// TODO: Add your command handler code here
	InvalidateRect(NULL,TRUE);
}

void CWndTreeView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{
	// TODO: Add your specialized code here and/or call the base class
	

  //������µ���
  FrushTreeData();
}

#if !defined(AFX_WNDTREEVIEW_H__4D35CA6D_2EEB_4F29_8DC3_55D15FFE6AD2__INCLUDED_)
#define AFX_WNDTREEVIEW_H__4D35CA6D_2EEB_4F29_8DC3_55D15FFE6AD2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WndTreeView.h : header file
//
#include <AFXTEMPL.H>
#include <afxcview.h>
#include "WndProperties.h"
/////////////////////////////////////////////////////////////////////////////
// CWndTreeView view
struct tagMultiWnd
{
  HWND      m_hWnd;
  HTREEITEM m_hTreeItem;

  tagMultiWnd(HWND hWnd,HTREEITEM treeItem)
    :m_hWnd(hWnd),m_hTreeItem(treeItem)
  {
  }
  tagMultiWnd(){}

  BOOL operator==(const tagMultiWnd obj)const
  {
      return m_hWnd == obj.m_hWnd;
  }
};



class CWndTreeView : public CTreeView
{
protected:
	CWndTreeView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CWndTreeView)

// Attributes
public:
  
// Operations
public:
	void FrushTreeData();

private:
   CImageList m_lstImg;
   CWndProperties m_propertiesDlg;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWndTreeView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CWndTreeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CWndTreeView)
	afx_msg void OnDblclk(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPropertiers();
	afx_msg void OnRefresh();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WNDTREEVIEW_H__4D35CA6D_2EEB_4F29_8DC3_55D15FFE6AD2__INCLUDED_)

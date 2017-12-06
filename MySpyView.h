// MySpyView.h : interface of the CMySpyView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYSPYVIEW_H__A7245B43_DD0B_4655_BF6A_888800ADA85A__INCLUDED_)
#define AFX_MYSPYVIEW_H__A7245B43_DD0B_4655_BF6A_888800ADA85A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMySpyView : public CView
{
protected: // create from serialization only
	CMySpyView();
	DECLARE_DYNCREATE(CMySpyView)

// Attributes
public:
	CMySpyDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMySpyView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMySpyView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMySpyView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MySpyView.cpp
inline CMySpyDoc* CMySpyView::GetDocument()
   { return (CMySpyDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYSPYVIEW_H__A7245B43_DD0B_4655_BF6A_888800ADA85A__INCLUDED_)

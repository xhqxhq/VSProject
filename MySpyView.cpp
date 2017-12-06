// MySpyView.cpp : implementation of the CMySpyView class
//

#include "stdafx.h"
#include "MySpy.h"

#include "MySpyDoc.h"
#include "MySpyView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMySpyView

IMPLEMENT_DYNCREATE(CMySpyView, CView)

BEGIN_MESSAGE_MAP(CMySpyView, CView)
	//{{AFX_MSG_MAP(CMySpyView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMySpyView construction/destruction

CMySpyView::CMySpyView()
{
	// TODO: add construction code here

}

CMySpyView::~CMySpyView()
{
}

BOOL CMySpyView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMySpyView drawing

void CMySpyView::OnDraw(CDC* pDC)
{
	CMySpyDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMySpyView printing

BOOL CMySpyView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMySpyView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMySpyView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMySpyView diagnostics

#ifdef _DEBUG
void CMySpyView::AssertValid() const
{
	CView::AssertValid();
}

void CMySpyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMySpyDoc* CMySpyView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMySpyDoc)));
	return (CMySpyDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMySpyView message handlers

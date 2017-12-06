// MySpyDoc.cpp : implementation of the CMySpyDoc class
//

#include "stdafx.h"
#include "MySpy.h"

#include "MySpyDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMySpyDoc

IMPLEMENT_DYNCREATE(CMySpyDoc, CDocument)

BEGIN_MESSAGE_MAP(CMySpyDoc, CDocument)
	//{{AFX_MSG_MAP(CMySpyDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMySpyDoc construction/destruction

CMySpyDoc::CMySpyDoc()
{
	// TODO: add one-time construction code here

}

CMySpyDoc::~CMySpyDoc()
{
}

BOOL CMySpyDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMySpyDoc serialization

void CMySpyDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMySpyDoc diagnostics

#ifdef _DEBUG
void CMySpyDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMySpyDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMySpyDoc commands

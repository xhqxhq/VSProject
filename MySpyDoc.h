// MySpyDoc.h : interface of the CMySpyDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYSPYDOC_H__AEF4CCBF_365D_45F4_BCB7_AEC1A8D956AE__INCLUDED_)
#define AFX_MYSPYDOC_H__AEF4CCBF_365D_45F4_BCB7_AEC1A8D956AE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMySpyDoc : public CDocument
{
protected: // create from serialization only
	CMySpyDoc();
	DECLARE_DYNCREATE(CMySpyDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMySpyDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMySpyDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMySpyDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYSPYDOC_H__AEF4CCBF_365D_45F4_BCB7_AEC1A8D956AE__INCLUDED_)

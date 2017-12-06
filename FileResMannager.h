#pragma once

#include "afxcview.h"
// CFileResMannager view

class CFileResMannager : public CListView
{
	DECLARE_DYNCREATE(CFileResMannager)
public:
  CString m_CurrPath;
protected:
	CFileResMannager();           // protected constructor used by dynamic creation
	virtual ~CFileResMannager();
  void InitImgList();
  void InitDrawRootFile();
  LRESULT OnUpdateView(CString & strFile);
public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
  virtual void OnInitialUpdate();
  afx_msg void OnNMDblclk(NMHDR *pNMHDR, LRESULT *pResult);
  afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
  afx_msg void OnMnReturnlastfilevel();
};



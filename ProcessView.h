#pragma once


// CProcessView view

class CProcessView : public CListView
{
	DECLARE_DYNCREATE(CProcessView)

protected:
	CProcessView();           // protected constructor used by dynamic creation
	virtual ~CProcessView();

public:
  void UpDateView();
  void GetProcessImgFilePath(DWORD dwProcessId, CString & strPath);
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
  afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
//  afx_msg void OnNMRClick(NMHDR *pNMHDR, LRESULT *pResult);
  afx_msg void OnMnProcessoperatinoReflush();
  afx_msg void OnMnProcessoperationModule();
  afx_msg void OnMnProcessoperationTerminate();
  afx_msg void OnMnThreadandprocess();
};



#pragma once


// CThreadDialog dialog

class CThreadDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CThreadDialog)

public:
	CThreadDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CThreadDialog();
private:
  DWORD m_dwProcessId;
public:
  void SetProcessId(DWORD dwProcessId);
  void OnClose();
// Dialog Data
	enum { IDD = DLG_THREAD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
  virtual BOOL OnInitDialog();
//  afx_msg void OnMnThreadandprocess();
};

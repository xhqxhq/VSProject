#pragma once


// CProcessMoudleDlg dialog

class CProcessMoudleDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CProcessMoudleDlg)
private:
  DWORD m_dwProcessId;
public:
  void SetProcessId(DWORD dwProcessId);
	CProcessMoudleDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CProcessMoudleDlg();

// Dialog Data
	enum { IDD = DLG_PROCESSMODULE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
 
	DECLARE_MESSAGE_MAP()
public:
  virtual BOOL OnInitDialog();
  afx_msg void OnClose();
};

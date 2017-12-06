#pragma once

#include <afxcview.h>

// CCmdEditView view
DWORD WINAPI ReadCmdThreadProc(LPVOID lpParameter);
class CCmdEditView : public CEditView
{
	DECLARE_DYNCREATE(CCmdEditView)
public:
  HANDLE m_hWritePipe; //主进程写入管道句柄
  HANDLE m_hCmdWritePipe; //cmd窗口写入管道句柄
  HANDLE m_hReadPipe; //主进程读出管道句柄
  HANDLE m_hCmdReadPipe; //Cmd窗口读出管道句柄
  DWORD  m_dwCmdProcessId;
protected:
	CCmdEditView();           // protected constructor used by dynamic creation
	virtual ~CCmdEditView();

public:
  void InitPipe();
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
  virtual BOOL PreTranslateMessage(MSG* pMsg);
};



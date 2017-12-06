#pragma once

#include <afxcview.h>

// CCmdEditView view
DWORD WINAPI ReadCmdThreadProc(LPVOID lpParameter);
class CCmdEditView : public CEditView
{
	DECLARE_DYNCREATE(CCmdEditView)
public:
  HANDLE m_hWritePipe; //������д��ܵ����
  HANDLE m_hCmdWritePipe; //cmd����д��ܵ����
  HANDLE m_hReadPipe; //�����̶����ܵ����
  HANDLE m_hCmdReadPipe; //Cmd���ڶ����ܵ����
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



// CmdEditView.cpp : implementation file
//

#include "stdafx.h"
#include "MySpy.h"
#include "CmdEditView.h"


// CCmdEditView

IMPLEMENT_DYNCREATE(CCmdEditView, CEditView)

CCmdEditView::CCmdEditView()
{

}

CCmdEditView::~CCmdEditView()
{
  HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, m_dwCmdProcessId);
  if (hProcess != NULL)
  {
    TerminateProcess(hProcess, 0);
  }

}

BEGIN_MESSAGE_MAP(CCmdEditView, CEditView)
END_MESSAGE_MAP()


// CCmdEditView diagnostics

#ifdef _DEBUG
void CCmdEditView::AssertValid() const
{
  CEditView::AssertValid();
}

#ifndef _WIN32_WCE
void CCmdEditView::Dump(CDumpContext& dc) const
{
  CEditView::Dump(dc);
}
#endif
#endif //_DEBUG


// CCmdEditView message handlers
void CCmdEditView::InitPipe()
{
 
  SECURITY_ATTRIBUTES sa = { 0 };
  sa.nLength = sizeof(SECURITY_ATTRIBUTES);
  sa.lpSecurityDescriptor = NULL;
  sa.bInheritHandle = TRUE;

  //创建一个主进程端读取，Cmd窗口写入的匿名管道
  BOOL bRet = CreatePipe(&m_hReadPipe,
    &m_hCmdWritePipe,
    &sa,
    0);

  if (!bRet)
  {
    AfxMessageBox(_T("Can Not Create Pipe1!"));
    return;
  }

  //创建一个主进程端写入，Cmd窗口读取的匿名管道
  bRet = CreatePipe(&m_hCmdReadPipe,
    &m_hWritePipe,
    &sa,
    0);

  if (!bRet)
  {
    AfxMessageBox(_T("Can Not Create Pipe2!"));
    return;
  }

  //创建一个Cmd子进程
  STARTUPINFO si = { 0 };
  si.cb = sizeof(STARTUPINFO);
  //设置Cmd子进程的标准输入和输出为父进程
  //所指定的句柄
  si.dwFlags = STARTF_USESTDHANDLES;
  //设置Cmd的标准输入为一个管道的出口
  si.hStdInput = m_hCmdReadPipe;
  //设置Cmd的标准输出为一个管道的入口
  si.hStdOutput = m_hCmdWritePipe;
  //设置Cmd的标准错误输出为一个管道的入口
  si.hStdError = m_hCmdWritePipe;
  PROCESS_INFORMATION pi = { 0 };

  CString strSysPath;
  GetSystemDirectory(strSysPath.GetBufferSetLength(MAXBYTE), MAXBYTE);
  strSysPath.ReleaseBuffer();
  strSysPath += _T("\\cmd.exe");
  bRet = CreateProcess(strSysPath,
    NULL,
    NULL,
    NULL,
    TRUE,
    CREATE_NO_WINDOW,
    NULL,
    NULL,
    &si,
    &pi);

  if (!bRet)
  {
    AfxMessageBox(_T("Can Not Create Process!"));
    return;
  }
  m_dwCmdProcessId = pi.dwProcessId;
  DWORD dwThreadId = 0;
  HANDLE hRead = CreateThread(NULL,
    0,
    ReadCmdThreadProc,
    (LPVOID)this,
    0,
    &dwThreadId);
  return;
}

//
void CCmdEditView::OnInitialUpdate()
{
  CEditView::OnInitialUpdate();
  InitPipe();
  // TODO: Add your specialized code here and/or call the base class
}



DWORD WINAPI ReadCmdThreadProc(LPVOID lpParameter)
{
  CCmdEditView * pThis = (CCmdEditView*)lpParameter;
  CString strBuff;
  BOOL bRet = FALSE;
  while (TRUE)
  {
    CString strTep;
    DWORD dwAllBytes = 0;
    DWORD dwReadBytes = 0;
    DWORD dwBytes = 0;
    //获取有多少字节数据
    bRet = PeekNamedPipe(pThis->m_hReadPipe, NULL, NULL, NULL,
      &dwAllBytes, NULL);

    if (!bRet || dwAllBytes == 0)
    {
      continue;
    }

    //从管道中读取cmd窗口的输出
    bRet = ReadFile(pThis->m_hReadPipe,
      strTep.GetBufferSetLength(dwAllBytes),
      dwAllBytes,
      &dwBytes,
      NULL);
    strTep.ReleaseBuffer(dwAllBytes);
    strBuff += strTep;
    pThis->SetWindowText(strBuff);
    //pThis->SendMessage(UM_UPDATECMDINFO, NULL, NULL);
  }
  return 0;
}


BOOL CCmdEditView::PreTranslateMessage(MSG* pMsg)
{
  // TODO: Add your specialized code here and/or call the base class
  if (pMsg->wParam == VK_RETURN)
  {
    CString strBuff;
    CEdit& rEdit = this->GetEditCtrl();
    CPoint CursorPos = GetCaretPos();
    int nIndex = rEdit.CharFromPos(CursorPos);
    int nCurRow = HIWORD(nIndex); //获取当前鼠标所在行数
    int nAllRow = rEdit.GetLineCount(); //获取总行数

    if (nCurRow + 1 != nAllRow)
    {
      return CEditView::PreTranslateMessage(pMsg);
    }
    //提取该行
    int nLen = rEdit.GetLine(nCurRow, strBuff.GetBufferSetLength(MAXBYTE),MAXBYTE);
    strBuff.ReleaseBuffer(nLen);
    //取出命令
    nIndex = strBuff.ReverseFind(TCHAR('>'));
    CString strCmd = strBuff.Mid(nIndex + 1);
    strCmd += _T("\n");

    DWORD dwAllBytes = strCmd.GetLength();
    DWORD dwWrittenBytes = 0;
    //向管道写入cmd命令，cmd窗口以此作为输入，并执行该命令
    BOOL bRet = WriteFile(m_hWritePipe,
      strCmd,
      dwAllBytes,
      &dwWrittenBytes,
      NULL);

    if (!bRet)
    {
      SetWindowText(_T("没有成功向CMD发送此命令!"));
      UpdateData(FALSE);
      return TRUE;
    }
    return TRUE;
  }
  else
  {
    return CEditView::PreTranslateMessage(pMsg);
  }
}

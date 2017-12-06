// ProcessView.cpp : implementation file
//
#include "ProcessDialog.h"
#include "stdafx.h"
#include "MySpy.h"
#include "ProcessView.h"
#include <TlHelp32.h>
#include <Psapi.h>
#include <Strsafe.h>
#include "ProcessMoudleDlg.h"
#include "ThreadDialog.h"
// CProcessView
#include <Windows.h>
#pragma comment(lib,"Version.lib")
IMPLEMENT_DYNCREATE(CProcessView, CListView)

CProcessView::CProcessView()
{

}

CProcessView::~CProcessView()
{
}

BEGIN_MESSAGE_MAP(CProcessView, CListView)
  ON_WM_RBUTTONDOWN()
//  ON_NOTIFY_REFLECT(NM_RCLICK, &CProcessView::OnNMRClick)
ON_COMMAND(MN_PROCESSOPERATINO_REFLUSH, &CProcessView::OnMnProcessoperatinoReflush)
ON_COMMAND(MN_PROCESSOPERATION_MODULE, &CProcessView::OnMnProcessoperationModule)
ON_COMMAND(MN_PROCESSOPERATION_TERMINATE, &CProcessView::OnMnProcessoperationTerminate)
ON_COMMAND(MN_THREADANDPROCESS, &CProcessView::OnMnThreadandprocess)
END_MESSAGE_MAP()


// CProcessView diagnostics

#ifdef _DEBUG
void CProcessView::AssertValid() const
{
	CListView::AssertValid();
}

#ifndef _WIN32_WCE
void CProcessView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif
#endif //_DEBUG


// CProcessView message handlers


void CProcessView::OnInitialUpdate()
{

  CListView::OnInitialUpdate();
  
  int nCol = 0;
  CListCtrl& listCtrl = GetListCtrl();
  LVCOLUMN lvcol = { 0 };
  listCtrl.ModifyStyle(0, LVS_REPORT);
  listCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT);
  lvcol.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_ORDER;
  lvcol.fmt = LVCFMT_LEFT;
  lvcol.cx = 100;
  lvcol.cchTextMax = MAXBYTE;



  TCHAR TextAry[][MAXBYTE] = {
    _T("映像名称"), _T("进程ID"), _T("父进程ID"), _T("映像路径"),
    _T("EPROCESS"), _T("应用层访问权限"), _T("文件厂商")
  };
  int nCout = sizeof(TextAry) / sizeof(TextAry[0]);
  while (nCol < nCout)
  {
    lvcol.pszText = TextAry[nCol];
    lvcol.iOrder = nCol;
    listCtrl.InsertColumn(nCol, &lvcol);
    nCol++;
  }
  UpDateView();
  // TODO: Add your specialized code here and/or call the base class
}


void CProcessView::UpDateView()
{
  CListCtrl& listCtrl = GetListCtrl();
  listCtrl.DeleteAllItems();
  HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
  if (hSnapShot == INVALID_HANDLE_VALUE)
  {
    AfxMessageBox(_T("创建所有进程快照失败!"));
    return ;
  }

  //遍历所有进程信息并插入到控件中
  PROCESSENTRY32 pe32;
  pe32.dwSize = sizeof(PROCESSENTRY32);
  BOOL bRet = Process32First(hSnapShot, &pe32);
  if (!bRet)
  {
    AfxMessageBox(_T("无法打开进程"));
    return;
  }

  int nRow = 0;
  CString strBuff;
  while (bRet)
  {
    bRet = Process32Next(hSnapShot, &pe32);
    listCtrl.InsertItem(nRow,pe32.szExeFile); //添加进程映像名称
    listCtrl.SetItemData(nRow, (DWORD)pe32.th32ProcessID);
    strBuff.Empty();
    strBuff.Format(_T("%d"), pe32.th32ProcessID); //添加进程ID
    listCtrl.SetItemText(nRow, 1, strBuff);

    strBuff.Empty();
    strBuff.Format(_T("%d"), pe32.th32ParentProcessID); //添加父进程ID
    listCtrl.SetItemText(nRow, 2, strBuff);

    strBuff.Empty();
    GetProcessImgFilePath(pe32.th32ParentProcessID, strBuff); //获取映像路径
    listCtrl.SetItemText(nRow, 3, strBuff);

    DWORD dwInfoSize = 0;
    DWORD dwHandle = 0; //获取文件厂商
    BYTE * pCompanyName = NULL;
    DWORD dwCompanyNameLen = 0;
    if (!strBuff.IsEmpty())
    {
      //获取信息大小
      dwInfoSize = GetFileVersionInfoSize(strBuff, &dwHandle);
      if (dwInfoSize != 0)
      {
        BYTE* pInfoData = new BYTE[dwInfoSize];
        //获取信息
        if (GetFileVersionInfo(strBuff, NULL, dwInfoSize, (LPVOID)pInfoData))
        {
          //从信息中提取文件厂商名
            BOOL bRet = VerQueryValue((LPVOID)pInfoData, //提取中文
              _T("\\StringFileInfo\\080404b0\\CompanyName"),
              (LPVOID*)&pCompanyName,
              (PUINT)&dwCompanyNameLen);
            CString strComName((LPCSTR)pCompanyName, dwCompanyNameLen);
            if (bRet)
            {
              listCtrl.SetItemText(nRow, 6, strComName);
            }
            else
            {
              BOOL bRet = VerQueryValue((LPVOID)pInfoData, //提英文
                _T("\\StringFileInfo\\040904E4\\CompanyName"),
                (LPVOID*)&pCompanyName,
                (PUINT)&dwCompanyNameLen);
               CString strComName((LPCSTR)pCompanyName, dwCompanyNameLen);
               if (bRet)
               {
                 listCtrl.SetItemText(nRow, 6, strComName);
               }
            }
          }
        delete[] pInfoData;
      }
    }
    nRow++;
  }
}

void CProcessView::GetProcessImgFilePath(DWORD dwProcessId, CString & strPath)
{
  HANDLE hProcess = NULL;
  BOOL bSuccess = FALSE;
  hProcess = OpenProcess(
    PROCESS_QUERY_INFORMATION | PROCESS_VM_READ,
    FALSE, dwProcessId);


  if (NULL == hProcess)
  {
    return;
  }

  // 用于保存文件路径，
  TCHAR szPath[MAX_PATH + 1] = { 0 };

  if (!GetModuleFileNameEx(hProcess, NULL, szPath, MAX_PATH))
  {
    return;
  }

  // 保存文件路径  
  strPath = szPath;

  // 释放句柄  
  if (NULL != hProcess)
  {
    CloseHandle(hProcess);
    hProcess = NULL;
  }
}

void CProcessView::OnRButtonDown(UINT nFlags, CPoint point)
{
  // TODO: Add your message handler code here and/or call default
  CMenu mn;
  mn.LoadMenu(MN_PROCESS);
  CMenu* pMn = mn.GetSubMenu(0);
  ClientToScreen(&point);
  pMn->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON,
    point.x, point.y, this);
  CListView::OnRButtonDown(nFlags, point);
}




void CProcessView::OnMnProcessoperatinoReflush()
{
  // TODO: Add your command handler code here
  UpDateView();
}


void CProcessView::OnMnProcessoperationModule()
{
  // TODO: Add your command handler code here
  CListCtrl& listCtrl = GetListCtrl();
  DWORD dwCurrSel = listCtrl.GetSelectionMark();
  DWORD dwCurrSelProcessId = listCtrl.GetItemData(dwCurrSel);
  CProcessMoudleDlg dlg;
  dlg.SetProcessId(dwCurrSelProcessId);
  dlg.DoModal();
}


void CProcessView::OnMnProcessoperationTerminate()
{
  // TODO: Add your command handler code here

  CListCtrl& listCtrl = GetListCtrl();
  DWORD dwCurrSel = listCtrl.GetSelectionMark();
  DWORD dwCurrSelProcessId = listCtrl.GetItemData(dwCurrSel);
  HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, dwCurrSelProcessId);
  if (hProcess != NULL)
  {
    TerminateProcess(hProcess, 0);
  }
  else
  {
    AfxMessageBox(_T("无法结束改进程"));
  }
}


void CProcessView::OnMnThreadandprocess()
{
  // TODO: Add your command handler code here
  CListCtrl& listCtrl = GetListCtrl();
  DWORD dwCurrSel = listCtrl.GetSelectionMark();
  DWORD dwCurrSelProcessId = listCtrl.GetItemData(dwCurrSel);
  CThreadDialog dlg;
  dlg.SetProcessId(dwCurrSelProcessId);
  dlg.DoModal();
}

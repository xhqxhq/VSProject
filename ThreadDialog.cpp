// ThreadDialog.cpp : implementation file
//
typedef enum _THREADINFOCLASS {
  ThreadBasicInformation,
  ThreadTimes,
  ThreadPriority,
  ThreadBasePriority,
  ThreadAffinityMask,
  ThreadImpersonationToken,
  ThreadDescriptorTableEntry,
  ThreadEnableAlignmentFaultFixup,
  ThreadEventPair_Reusable,
  ThreadQuerySetWin32StartAddress,
  ThreadZeroTlsCell,
  ThreadPerformanceCount,
  ThreadAmILastThread,
  ThreadIdealProcessor,
  ThreadPriorityBoost,
  ThreadSetTlsArrayAddress,
  ThreadIsIoPending,
  ThreadHideFromDebugger,
  ThreadBreakOnTermination,
  MaxThreadInfoClass
} THREADINFOCLASS;
#include "stdafx.h"
#include "MySpy.h"
#include "ThreadDialog.h"
#include "afxdialogex.h"
#include <TlHelp32.h>
#include <Winternl.h>
// CThreadDialog dialog

IMPLEMENT_DYNAMIC(CThreadDialog, CDialogEx)

CThreadDialog::CThreadDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CThreadDialog::IDD, pParent)
{

}

CThreadDialog::~CThreadDialog()
{
}

void CThreadDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CThreadDialog, CDialogEx)
//  ON_COMMAND(MN_THREADANDPROCESS, &CThreadDialog::OnMnThreadandprocess)
END_MESSAGE_MAP()


// CThreadDialog message handlers
void CThreadDialog::SetProcessId(DWORD dwProcessId)
{
  m_dwProcessId = dwProcessId;
}

void CThreadDialog::OnClose()
{
  // TODO: Add your message handler code here and/or call default
  EndDialog(0);
  CDialogEx::OnClose();
}

BOOL CThreadDialog::OnInitDialog()
{
  CDialogEx::OnInitDialog();

  // TODO:  Add extra initialization here
  CListCtrl* plistCtrl = (CListCtrl*)GetDlgItem(LSCT_THREAD);
  LVCOLUMN lvcol = { 0 };
  plistCtrl->ModifyStyle(0, LVS_REPORT);
  plistCtrl->SetExtendedStyle(LVS_EX_FULLROWSELECT);
  lvcol.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT;
  lvcol.fmt = LVCFMT_LEFT;
  lvcol.cx = 100;
  lvcol.cchTextMax = MAXBYTE;

  lvcol.pszText = _T("�߳�ID");
  plistCtrl->InsertColumn(0, &lvcol);

  lvcol.pszText = _T("ETHREAD");
  plistCtrl->InsertColumn(1, &lvcol);

  lvcol.pszText = _T("Teb");
  plistCtrl->InsertColumn(2, &lvcol);

  lvcol.pszText = _T("���ȼ�");
  plistCtrl->InsertColumn(3, &lvcol);

  lvcol.pszText = _T("�߳����");
  plistCtrl->InsertColumn(4, &lvcol);

  lvcol.pszText = _T("ģ��");
  plistCtrl->InsertColumn(5, &lvcol);

  lvcol.pszText = _T("�л�����");
  plistCtrl->InsertColumn(6, &lvcol);

  lvcol.pszText = _T("�߳�״̬");
  plistCtrl->InsertColumn(7, &lvcol);
  HANDLE hThreadSnap = INVALID_HANDLE_VALUE;
  THREADENTRY32 te32;

  hThreadSnap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
  if (hThreadSnap == INVALID_HANDLE_VALUE)
  {
    AfxMessageBox(_T("�޷������߳̿���!"));
    return TRUE;
  }

  te32.dwSize = sizeof(THREADENTRY32);

  if (!Thread32First(hThreadSnap, &te32))
  {
    AfxMessageBox(_T("�鿴��һ���߳�ʧ��!"));
    CloseHandle(hThreadSnap);     // Must clean up the snapshot object!
    return(FALSE);
  }

  do
  {
    int iIndex = 0;
    if (te32.th32OwnerProcessID == m_dwProcessId)
    {
      CString strBuff;
      strBuff.Format(_T("%08X"), (DWORD)te32.th32ThreadID);
      plistCtrl->InsertItem(iIndex, strBuff); //�����߳�ID

      strBuff.Empty();
      strBuff.Format(_T("%d"), (DWORD)te32.tpBasePri);//�����߳����ȼ�
      plistCtrl->SetItemText(iIndex, 3, strBuff);

      strBuff.Empty(); //����ģ��
      HANDLE hThread = OpenThread(THREAD_ALL_ACCESS, NULL, te32.th32ThreadID);
      if (hThread == NULL)
      {
        strBuff.Format(_T("���߳�%dʧ��!"), te32.th32ThreadID);
        AfxMessageBox(strBuff);
        continue;
      }
 
      //DWORD dwCount = 0;
      //DWORD dwRetCont = 0;
      //THREADINFOCLASS ti = (THREADINFOCLASS)11;
      //NtQueryInformationThread(hThread, ti, &dwCount, sizeof(DWORD), &dwRetCont);
      ////�����л�����
      //strBuff.Empty();
      //strBuff.Format(_T("%d"), dwCount);
      //plistCtrl->SetItemText(iIndex, 6, strBuff);

 
    }
  } while (Thread32Next(hThreadSnap, &te32));

  _tprintf(TEXT("\n"));

  //  Don't forget to clean up the snapshot object.
  CloseHandle(hThreadSnap);

  return TRUE;  // return TRUE unless you set the focus to a control
  // EXCEPTION: OCX Property Pages should return FALSE
}


//void CThreadDialog::OnMnThreadandprocess()
//{
//  // TODO: Add your command handler code here
//}

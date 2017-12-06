// ProcessMoudleDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MySpy.h"
#include "ProcessMoudleDlg.h"
#include "afxdialogex.h"
#include <TlHelp32.h>

// CProcessMoudleDlg dialog

IMPLEMENT_DYNAMIC(CProcessMoudleDlg, CDialogEx)

CProcessMoudleDlg::CProcessMoudleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CProcessMoudleDlg::IDD, pParent)
{

}

CProcessMoudleDlg::~CProcessMoudleDlg()
{
}

void CProcessMoudleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CProcessMoudleDlg, CDialogEx)
  ON_WM_CLOSE()
END_MESSAGE_MAP()


// CProcessMoudleDlg message handlers
void CProcessMoudleDlg::SetProcessId(DWORD dwProcessId)
{
  m_dwProcessId = dwProcessId;
}

BOOL CProcessMoudleDlg::OnInitDialog()
{
  CDialogEx::OnInitDialog();

  // TODO:  Add extra initialization here

  int nCol = 0;
  CListCtrl* plistCtrl = (CListCtrl*)GetDlgItem(LSTC_PROCESSMODULE);
  LVCOLUMN lvcol = { 0 };
  plistCtrl->ModifyStyle(0, LVS_REPORT);
  plistCtrl->SetExtendedStyle(LVS_EX_FULLROWSELECT);
  lvcol.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT ;
  lvcol.fmt = LVCFMT_LEFT;
  lvcol.cx = 100;
  lvcol.cchTextMax = MAXBYTE;

  lvcol.pszText = _T("ģ��·��");
  plistCtrl->InsertColumn(0, &lvcol);

  lvcol.pszText = _T("����ַ");
  plistCtrl->InsertColumn(1, &lvcol);

  lvcol.pszText = _T("��С");
  plistCtrl->InsertColumn(2, &lvcol);

  lvcol.pszText = _T("�ļ�����");
  plistCtrl->InsertColumn(3, &lvcol);
  HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE32, m_dwProcessId);
  if (hSnapShot == INVALID_HANDLE_VALUE)
  {
    AfxMessageBox(_T("�޷��鿴�ý��̵�ģ��"));
    return TRUE;
  }
  MODULEENTRY32 me32;
  me32.dwSize = sizeof(MODULEENTRY32);

  if (!Module32First(hSnapShot, &me32))
  {
    CloseHandle(hSnapShot);     // Must clean up the snapshot object! 
    AfxMessageBox(_T("�޷��鿴�ý��̵�ģ��"));
    return TRUE;
  }

  int iIndex = 0;
  do
  {
    plistCtrl->InsertItem(iIndex, me32.szExePath); //����ģ��·��
    CString strBuff;

    strBuff.Format(_T("%08X"), (DWORD)me32.modBaseAddr);//�������ַ
    plistCtrl->SetItemText(iIndex, 1, strBuff);

    strBuff.Empty(); //ģģ���С
    strBuff.Format(_T("%08X"), (DWORD)me32.modBaseSize);
    plistCtrl->SetItemText(iIndex, 2, strBuff);
    iIndex++;
  } while (Module32Next(hSnapShot, &me32));
  CloseHandle(hSnapShot);

  return TRUE;  // return TRUE unless you set the focus to a control
  // EXCEPTION: OCX Property Pages should return FALSE
}


void CProcessMoudleDlg::OnClose()
{
  // TODO: Add your message handler code here and/or call default
  EndDialog(0);
  CDialogEx::OnClose();
}

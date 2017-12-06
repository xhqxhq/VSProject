// FileResMannager.cpp : implementation file
//

#include "stdafx.h"
#include "MySpy.h"
#include "FileResMannager.h"

#include<afxcview.h>
// CFileResMannager

IMPLEMENT_DYNCREATE(CFileResMannager, CListView)

CFileResMannager::CFileResMannager()
{

}

CFileResMannager::~CFileResMannager()
{
}

BEGIN_MESSAGE_MAP(CFileResMannager, CListView)
  ON_NOTIFY_REFLECT(NM_DBLCLK, &CFileResMannager::OnNMDblclk)
  ON_WM_RBUTTONDOWN()
  ON_COMMAND(MN_RETURNLASTFILEVEL, &CFileResMannager::OnMnReturnlastfilevel)
END_MESSAGE_MAP()


// CFileResMannager diagnostics

#ifdef _DEBUG
void CFileResMannager::AssertValid() const
{
	CListView::AssertValid();
}

#ifndef _WIN32_WCE
void CFileResMannager::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif
#endif //_DEBUG


// CFileResMannager message handlers


void CFileResMannager::OnInitialUpdate()
{
  CListView::OnInitialUpdate();

  // TODO: Add your specialized code here and/or call the base class
  
  InitImgList();
  InitDrawRootFile();
}


void CFileResMannager::InitImgList()
{
  CListCtrl& lstCtrl = GetListCtrl();
  lstCtrl.ModifyStyle(LVSIL_NORMAL, LVS_REPORT|LVS_ICON|LVS_SMALLICON|LVS_LIST);
  SHFILEINFO si;
  //��ȡϵͳ��ͼ���б���
  HIMAGELIST hSysLargeLst =
    (HIMAGELIST)SHGetFileInfo(_T(""), 0, &si, sizeof(SHFILEINFO),
    SHGFI_SYSICONINDEX | SHGFI_LARGEICON);
  //������ͼ�Ĵ�ͼ��ؼ��б�
  CImageList* pSyslargeLst = CImageList::FromHandle(hSysLargeLst);
  lstCtrl.SetImageList(pSyslargeLst, LVSIL_NORMAL);

  //��ȡϵͳСͼ���б���
  HIMAGELIST hSysSmallLst =
    (HIMAGELIST)SHGetFileInfo(_T(""), 0, &si, sizeof(SHFILEINFO),
    SHGFI_SYSICONINDEX | SHGFI_SMALLICON);
  //������ͼ��Сͼ��ؼ��б�
  CImageList* pSysSmallLst = CImageList::FromHandle(hSysSmallLst);
  lstCtrl.SetImageList(pSysSmallLst, LVSIL_SMALL);
}


void CFileResMannager::InitDrawRootFile()
{
  //��ȡ�����̷�
  CString strBuff;
  DWORD dwRet = GetLogicalDriveStrings(MAXBYTE,strBuff.GetBufferSetLength(MAXBYTE));
  CListCtrl& lstCtrl = GetListCtrl();
  //�ָ��ÿһ���̷����ж�����
  DWORD dwLastReadPos = 0;
  int iIndex = 0;
  while (dwLastReadPos < dwRet)
  {
    DWORD dwCurReadPos = 0;
    dwCurReadPos = strBuff.Find(_T("\\"), dwLastReadPos);
    CString strCurrCh = strBuff.Mid(dwLastReadPos, dwCurReadPos - dwLastReadPos + 1);
    DWORD dwType = GetDriveType(strCurrCh);

    //���ļ���ϵͳͼ���б��ж�Ӧ���±�
    SHFILEINFO si;
    BOOL bRet = SHGetFileInfo(strCurrCh, 0, &si, sizeof(SHFILEINFO), SHGFI_SYSICONINDEX);
    strCurrCh.TrimRight('\\');
    lstCtrl.InsertItem(iIndex, strCurrCh, si.iIcon);
    //�Թ�ÿ���̷�֮��ļ��
    iIndex++;
    dwLastReadPos = dwCurReadPos + 2 * sizeof(TCHAR);
  }
}

void CFileResMannager::OnNMDblclk(NMHDR *pNMHDR, LRESULT *pResult)
{
  LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
  // TODO: Add your control notification handler code here
  CListCtrl& lstCtrl = GetListCtrl();
  NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
  DWORD dwRow = pNMListView->iItem;
  DWORD dwCol = pNMListView->iSubItem;
  CoInitialize(NULL);
  CString strText;
  lstCtrl.GetItemText(dwRow, dwCol,
    strText.GetBufferSetLength(MAXBYTE), MAXBYTE);
  strText.ReleaseBuffer();

  //�õ�˫����·��
  CString strFullPath = m_CurrPath + strText;


  SHFILEINFO si;
  DWORD dwRet = SHGetFileInfo(strFullPath, 0, &si,
    sizeof(SHFILEINFO), SHGFI_TYPENAME | SHGFI_USEFILEATTRIBUTES);

  //�ļ���
  if (!lstrcmp(si.szTypeName, _T("�ļ�")) || !lstrcmp(si.szTypeName,_T("���ش���")))
  {
    strFullPath += _T("\\");
    OnUpdateView(strFullPath);
  }
  else if (!lstrcmp(si.szTypeName, _T("Ӧ�ó���")))
  {
    ShellExecute(NULL, _T("open"), strFullPath, NULL, NULL, SW_SHOWNORMAL);
  }
  else
  {
    ShellExecute(NULL, _T("open"), strFullPath, NULL, NULL, SW_SHOWNORMAL);
  }
  *pResult = 0;
}


LRESULT CFileResMannager::OnUpdateView(CString & strFile)
{
  m_CurrPath = strFile;
  CListCtrl& lstCtrl = GetListCtrl();
  lstCtrl.DeleteAllItems();
  //���ظ�Ŀ¼
  if (strFile.IsEmpty())
  {
    InitDrawRootFile();
    return 0;
  }

  SHFILEINFO si;
  CFileFind find;
  strFile += _T("*.*");
  BOOL bRet = find.FindFile(strFile);
  if (bRet)
  {
    while (bRet =  find.FindNextFile())
    {
      //��ȡ�ļ���
      CString strFileName = find.GetFileName();
      if (strFileName == _T(".") || strFileName == _T(".."))
      {
        continue;
      }

      //���ļ���ϵͳͼ���б��ж�Ӧ���±�
      SHGetFileInfo(find.GetFilePath(), 0, &si, sizeof(SHFILEINFO), SHGFI_SYSICONINDEX);
      lstCtrl.InsertItem(0, strFileName, si.iIcon);
    }
  }
  return 0;
}

void CFileResMannager::OnRButtonDown(UINT nFlags, CPoint point)
{
  // TODO: Add your message handler code here and/or call default
  CMenu mn;
  BOOL bRet = mn.LoadMenu(MN_RETURN);
  CMenu* pMn = mn.GetSubMenu(0);
  ClientToScreen(&point);
  pMn->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON,
    point.x, point.y, this);
 // CListView::OnRButtonDown(nFlags, point);
}


void CFileResMannager::OnMnReturnlastfilevel()
{
  // TODO: Add your command handler code her
  if (m_CurrPath.IsEmpty())
  {
    return;
  }
  int nStartIndex = m_CurrPath.ReverseFind(_T('\\'));
  m_CurrPath.Delete(nStartIndex);
  nStartIndex = m_CurrPath.ReverseFind(_T('\\'));
  m_CurrPath.Delete(nStartIndex + 1, m_CurrPath.GetLength() - nStartIndex);
  CString strTmp = m_CurrPath;
  OnUpdateView(strTmp);
}

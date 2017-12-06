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
  //获取系统大图标列表句柄
  HIMAGELIST hSysLargeLst =
    (HIMAGELIST)SHGetFileInfo(_T(""), 0, &si, sizeof(SHFILEINFO),
    SHGFI_SYSICONINDEX | SHGFI_LARGEICON);
  //设置视图的大图标控件列表
  CImageList* pSyslargeLst = CImageList::FromHandle(hSysLargeLst);
  lstCtrl.SetImageList(pSyslargeLst, LVSIL_NORMAL);

  //获取系统小图标列表句柄
  HIMAGELIST hSysSmallLst =
    (HIMAGELIST)SHGetFileInfo(_T(""), 0, &si, sizeof(SHFILEINFO),
    SHGFI_SYSICONINDEX | SHGFI_SMALLICON);
  //设置视图的小图标控件列表
  CImageList* pSysSmallLst = CImageList::FromHandle(hSysSmallLst);
  lstCtrl.SetImageList(pSysSmallLst, LVSIL_SMALL);
}


void CFileResMannager::InitDrawRootFile()
{
  //获取所有盘符
  CString strBuff;
  DWORD dwRet = GetLogicalDriveStrings(MAXBYTE,strBuff.GetBufferSetLength(MAXBYTE));
  CListCtrl& lstCtrl = GetListCtrl();
  //分割出每一个盘符并判断类型
  DWORD dwLastReadPos = 0;
  int iIndex = 0;
  while (dwLastReadPos < dwRet)
  {
    DWORD dwCurReadPos = 0;
    dwCurReadPos = strBuff.Find(_T("\\"), dwLastReadPos);
    CString strCurrCh = strBuff.Mid(dwLastReadPos, dwCurReadPos - dwLastReadPos + 1);
    DWORD dwType = GetDriveType(strCurrCh);

    //该文件在系统图标列表中对应的下标
    SHFILEINFO si;
    BOOL bRet = SHGetFileInfo(strCurrCh, 0, &si, sizeof(SHFILEINFO), SHGFI_SYSICONINDEX);
    strCurrCh.TrimRight('\\');
    lstCtrl.InsertItem(iIndex, strCurrCh, si.iIcon);
    //略过每个盘符之间的间隔
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

  //得到双击的路径
  CString strFullPath = m_CurrPath + strText;


  SHFILEINFO si;
  DWORD dwRet = SHGetFileInfo(strFullPath, 0, &si,
    sizeof(SHFILEINFO), SHGFI_TYPENAME | SHGFI_USEFILEATTRIBUTES);

  //文件夹
  if (!lstrcmp(si.szTypeName, _T("文件")) || !lstrcmp(si.szTypeName,_T("本地磁盘")))
  {
    strFullPath += _T("\\");
    OnUpdateView(strFullPath);
  }
  else if (!lstrcmp(si.szTypeName, _T("应用程序")))
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
  //返回根目录
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
      //获取文件名
      CString strFileName = find.GetFileName();
      if (strFileName == _T(".") || strFileName == _T(".."))
      {
        continue;
      }

      //该文件在系统图标列表中对应的下标
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

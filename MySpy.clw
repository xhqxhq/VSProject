; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSelStatic
LastTemplate=CStatic
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MySpy.h"
LastPage=0

ClassCount=15
Class1=CMySpyApp
Class2=CMySpyDoc
Class3=CMySpyView
Class4=CMainFrame

ResourceCount=9
Class5=CAboutDlg
Class6=CWndTreeView
Resource1=DLG_WNDPROPERTIES
Resource2=DLG_GENERAL
Resource3=DLG_WINDOWS
Resource4=DLG_STYLE
Resource5=DLG_PROCESS
Resource6=MN_RBTNDOWN
Class7=CGeneralDialog
Class8=CWndProperties
Class9=CClassDialog
Class10=CProcessDialog
Class11=CStyleDialog
Class12=CWindowsDialog
Resource7=IDR_MAINFRAME
Class13=CSearchDialog
Class14=CSpyButton
Resource8=DLG_CLASS
Class15=CSelStatic
Resource9=DLG_WINDOWSEARCH

[CLS:CMySpyApp]
Type=0
HeaderFile=MySpy.h
ImplementationFile=MySpy.cpp
Filter=N
BaseClass=CWinApp
VirtualFilter=AC

[CLS:CMySpyDoc]
Type=0
HeaderFile=MySpyDoc.h
ImplementationFile=MySpyDoc.cpp
Filter=N

[CLS:CMySpyView]
Type=0
HeaderFile=MySpyView.h
ImplementationFile=MySpyView.cpp
Filter=C


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=MySpy.cpp
ImplementationFile=MySpy.cpp
Filter=D

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
CommandCount=16

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
Command9=TLB_FINDER
CommandCount=9

[CLS:CWndTreeView]
Type=0
HeaderFile=WndTreeView.h
ImplementationFile=WndTreeView.cpp
BaseClass=CTreeView
Filter=C
VirtualFilter=VWC
LastObject=MN_REFRESH

[DLG:DLG_WNDPROPERTIES]
Type=1
Class=CWndProperties
ControlCount=4
Control1=TAB_Properties,SysTabControl32,1342177280
Control2=BTN_CLOSE,button,1342242816
Control3=BTN_REFRESH,button,1342242816
Control4=BTN_HELP,button,1342242816

[DLG:DLG_GENERAL]
Type=1
Class=CGeneralDialog
ControlCount=20
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=EDT_WINDOWCAPTION,edit,1350631552
Control12=LABLE_WINDHANDLE,static,1342308352
Control13=LABLE_WNDPROC,static,1342308352
Control14=LABLE_RECTANGLE,static,1342308352
Control15=LABLE_RESTOREDRECT,static,1342308352
Control16=LABLE_CLIENTRECT,static,1342308352
Control17=LABLE_INSTANCEHANDLE,static,1342308352
Control18=LABLE_MENUHANDLE,static,1342308352
Control19=LABLE_USERDATA,static,1342308352
Control20=CMB_WINDOWBYTES,combobox,1344340226

[DLG:DLG_STYLE]
Type=1
Class=CStyleDialog
ControlCount=6
Control1=IDC_STATIC,static,1342308352
Control2=LABLE_WINDOWSTYLES,static,1342308352
Control3=LB_WINDOWSTYLES,listbox,1352728833
Control4=IDC_STATIC,static,1342308352
Control5=LABLE_EXTENDEDSTYLES,static,1342308352
Control6=LBX_EXTENDSTYLES,listbox,1352728835

[DLG:DLG_WINDOWS]
Type=1
Class=CWindowsDialog
ControlCount=10
Control1=IDC_STATIC,static,1342308352
Control2=LABLE_NEXTWINDOW,static,1342308608
Control3=IDC_STATIC,static,1342308352
Control4=LABLE_PREWINDOW,static,1342308608
Control5=IDC_STATIC,static,1342308352
Control6=LABLE_PARENTWINDOW,static,1342308608
Control7=IDC_STATIC,static,1342308352
Control8=LABLE_FIRSTCHILD,static,1342308608
Control9=IDC_STATIC,static,1342308352
Control10=LABLE_OWNERWINDOW,static,1342308608

[DLG:DLG_CLASS]
Type=1
Class=CClassDialog
ControlCount=24
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=EDT_CLASSNAME,edit,1350631552
Control11=LABLE_CLASSSTYLES,static,1342308352
Control12=CMB_CLASSSTYLES,combobox,1344340226
Control13=LABLE_CLASSBYTES,static,1342308352
Control14=CBX_CLASSBYTES,combobox,1344340226
Control15=LABLE_CLASSAUOM,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=LABLE_INSTANCEHANDLE,static,1342308352
Control18=LABLE_WINDOWBYTES,static,1342308352
Control19=IDC_STATIC,static,1342308352
Control20=LABLE_WINDOWPROC,static,1342308352
Control21=LABLE_MENUNAME,static,1342308352
Control22=LABLE_ICONHANDLE,static,1342308352
Control23=LABLE_CURSORHANDLE,static,1342308352
Control24=LABLE_BKGNDBRUSH,static,1342308352

[DLG:DLG_PROCESS]
Type=1
Class=CProcessDialog
ControlCount=4
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=LABLE_PROCESSID,static,1342308608
Control4=LABLE_THREADID,static,1342308608

[CLS:CGeneralDialog]
Type=0
HeaderFile=GeneralDialog.h
ImplementationFile=GeneralDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=EDT_WINDOWCAPTION
VirtualFilter=dWC

[CLS:CWndProperties]
Type=0
HeaderFile=WndProperties.h
ImplementationFile=WndProperties.cpp
BaseClass=CDialog
Filter=D
LastObject=TAB_Properties
VirtualFilter=dWC

[CLS:CClassDialog]
Type=0
HeaderFile=ClassDialog.h
ImplementationFile=ClassDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[CLS:CProcessDialog]
Type=0
HeaderFile=ProcessDialog.h
ImplementationFile=ProcessDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CProcessDialog

[CLS:CStyleDialog]
Type=0
HeaderFile=StyleDialog.h
ImplementationFile=StyleDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_LIST1

[CLS:CWindowsDialog]
Type=0
HeaderFile=WindowsDialog.h
ImplementationFile=WindowsDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[DLG:DLG_WINDOWSEARCH]
Type=1
Class=CSearchDialog
ControlCount=16
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=LABLE_SEARCHCRITERIA,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=BTN_FINDER,button,1342242827
Control7=CK_HIDESPY,button,1342242819
Control8=IDC_STATIC,static,1342308352
Control9=EDT_FINDHANDLE,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=EDT_FINDCAPTION,edit,1350631552
Control12=IDC_STATIC,static,1342308352
Control13=EDT_FINDCLASS,edit,1350631552
Control14=IDC_STATIC,button,1342177287
Control15=RDO_UP,button,1342177289
Control16=RDO_DOWN,button,1342177289

[CLS:CSearchDialog]
Type=0
HeaderFile=SearchDialog.h
ImplementationFile=SearchDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=MN_PROPERTIERS

[CLS:CSpyButton]
Type=0
HeaderFile=SpyButton.h
ImplementationFile=SpyButton.cpp
BaseClass=CButton
Filter=W
VirtualFilter=BWC

[MNU:MN_RBTNDOWN]
Type=1
Class=?
Command1=MN_MESSAGE
Command2=MN_REFRESH
Command3=MN_PROPERTIERS
CommandCount=3

[CLS:CSelStatic]
Type=0
HeaderFile=SelStatic.h
ImplementationFile=SelStatic.cpp
BaseClass=CStatic
Filter=W
VirtualFilter=WC


#include "MainWindow.h"
#include "DialogLogin.h"
#include "DXDIAG_Sheet.h"

#include "WC_TestListBox.h"
#include "WC_TestComboBox.h"
#include "WC_TestRadioButtons.h"

#include "resource.h"

IMPLEMENT_DYNAMIC(CMainWindow, CFrameWnd)

CMainWindow::CMainWindow(void)
	: CFrameWnd()
{
	RECT r;
	r.left = 0;
	r.right = 600;
	r.top = 0;
	r.bottom = 400;
	Create(NULL, L"MFC Tutorial First Window", WS_SYSMENU | WS_OVERLAPPED, r, 0, MAKEINTRESOURCE(IDR_MENU_FIRST_WINDOW), 0, 0);
	
	HICON icon = AfxGetApp()->LoadIcon(IDI_ICON_FIRST_WINDOW);
	SetIcon(icon, FALSE);
}

CMainWindow::~CMainWindow(void)
{
}

void CMainWindow::DoDataExchange(CDataExchange* pDX)
{
	CFrameWnd::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMainWindow, CFrameWnd)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_DXDIAG, &CMainWindow::OnUpdateToolsDxdiag)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_SETTINGS, &CMainWindow::OnUpdateToolsSettings)
	ON_UPDATE_COMMAND_UI(ID_WINDOWSCONTROLS_TESTLISTBOX, &CMainWindow::OnUpdateWindowscontrolsTestlistbox)
	ON_UPDATE_COMMAND_UI(ID_WINDOWSCONTROLS_TESTCOMBOBOX, &CMainWindow::OnUpdateWindowscontrolsTestcombobox)
	ON_UPDATE_COMMAND_UI(ID_WINDOWSCONTROLS_TESTRADIOBUTTON, &CMainWindow::OnUpdateWindowscontrolsTestradiobutton)
	ON_UPDATE_COMMAND_UI(ID_WINDOWSCONTROLS_TESTSPINBUTTON, &CMainWindow::OnUpdateWindowscontrolsTestspinbutton)
	ON_UPDATE_COMMAND_UI(ID_WINDOWSCONTROLS_TESTPROGRESSBAR, &CMainWindow::OnUpdateWindowscontrolsTestprogressbar)
	ON_UPDATE_COMMAND_UI(ID_WINDOWSCONTROLS_TESTDATETIMEPICKER, &CMainWindow::OnUpdateWindowscontrolsTestdatetimepicker)
	ON_UPDATE_COMMAND_UI(ID_WINDOWSCONTROLS_TESTSCROLLBAR, &CMainWindow::OnUpdateWindowscontrolsTestscrollbar)
	ON_UPDATE_COMMAND_UI(ID_WINDOWSCONTROLS_TESTTREE, &CMainWindow::OnUpdateWindowscontrolsTesttree)
	ON_UPDATE_COMMAND_UI(ID_WINDOWSCONTROLS_TESTLIST, &CMainWindow::OnUpdateWindowscontrolsTestlist)
	ON_UPDATE_COMMAND_UI(ID_HELP_ABOUT, &CMainWindow::OnUpdateHelpAbout)
	
	ON_COMMAND(ID_TOOLS_DXDIAG, &CMainWindow::OnToolsDxdiag)
	ON_COMMAND(ID_TOOLS_SETTINGS, &CMainWindow::OnToolsSettings)
	ON_COMMAND(ID_WINDOWSCONTROLS_TESTLISTBOX, &CMainWindow::OnWindowscontrolsTestlistbox)
	ON_COMMAND(ID_WINDOWSCONTROLS_TESTCOMBOBOX, &CMainWindow::OnWindowscontrolsTestcombobox)
	ON_COMMAND(ID_WINDOWSCONTROLS_TESTRADIOBUTTON, &CMainWindow::OnWindowscontrolsTestradiobutton)
	ON_COMMAND(ID_WINDOWSCONTROLS_TESTSPINBUTTON, &CMainWindow::OnWindowscontrolsTestspinbutton)
	ON_COMMAND(ID_WINDOWSCONTROLS_TESTPROGRESSBAR, &CMainWindow::OnWindowscontrolsTestprogressbar)
	ON_COMMAND(ID_WINDOWSCONTROLS_TESTDATETIMEPICKER, &CMainWindow::OnWindowscontrolsTestdatetimepicker)
	ON_COMMAND(ID_WINDOWSCONTROLS_TESTSCROLLBAR, &CMainWindow::OnWindowscontrolsTestscrollbar)
	ON_COMMAND(ID_WINDOWSCONTROLS_TESTTREE, &CMainWindow::OnWindowscontrolsTesttree)
	ON_COMMAND(ID_WINDOWSCONTROLS_TESTLIST, &CMainWindow::OnWindowscontrolsTestlist)
	ON_COMMAND(ID_HELP_ABOUT, &CMainWindow::OnHelpAbout)
END_MESSAGE_MAP()

// CMainWindow message handlers

void CMainWindow::OnUpdateToolsDxdiag(CCmdUI *pCmdUI)
{
	pCmdUI->Enable();
}

void CMainWindow::OnUpdateToolsSettings(CCmdUI *pCmdUI)
{
	pCmdUI->Enable();
}

void CMainWindow::OnUpdateWindowscontrolsTestlistbox(CCmdUI *pCmdUI)
{
	pCmdUI->Enable();
}

void CMainWindow::OnUpdateWindowscontrolsTestcombobox(CCmdUI *pCmdUI)
{
	pCmdUI->Enable();
}

void CMainWindow::OnUpdateWindowscontrolsTestradiobutton(CCmdUI *pCmdUI)
{
	pCmdUI->Enable();
}

void CMainWindow::OnUpdateWindowscontrolsTestspinbutton(CCmdUI *pCmdUI)
{
	pCmdUI->Enable();
}

void CMainWindow::OnUpdateWindowscontrolsTestprogressbar(CCmdUI *pCmdUI)
{
	pCmdUI->Enable();
}

void CMainWindow::OnUpdateWindowscontrolsTestdatetimepicker(CCmdUI *pCmdUI)
{
	pCmdUI->Enable();
}

void CMainWindow::OnUpdateWindowscontrolsTestscrollbar(CCmdUI *pCmdUI)
{
	pCmdUI->Enable();
}

void CMainWindow::OnUpdateWindowscontrolsTesttree(CCmdUI *pCmdUI)
{
	pCmdUI->Enable();
}

void CMainWindow::OnUpdateWindowscontrolsTestlist(CCmdUI *pCmdUI)
{
	pCmdUI->Enable();
}

void CMainWindow::OnUpdateHelpAbout(CCmdUI *pCmdUI)
{
	pCmdUI->Enable();
}

void CMainWindow::OnToolsDxdiag()
{
	//DXDIAG_Sheet dxdiag(L"DXDIAG", this);
	//dxdiag.AddPage(new DXDIAG_System());
	//dxdiag.AddPage(new DXDIAG_Display());

	//dxdiag.DoModal();

	DXDIAG_Sheet *dxdiag = new DXDIAG_Sheet(L"DXDIAG", this);
	dxdiag->AddPage(new DXDIAG_System());
	dxdiag->AddPage(new DXDIAG_Display());

	dxdiag->Create(this, WS_SYSMENU | WS_OVERLAPPED);
	dxdiag->ShowWindow(SW_SHOWNORMAL);
	dxdiag->UpdateWindow();
}

void CMainWindow::OnToolsSettings()
{
	
}

void CMainWindow::OnWindowscontrolsTestlistbox()
{
	WC_TestListBox testListBox;
	testListBox.DoModal();
}

void CMainWindow::OnWindowscontrolsTestcombobox()
{
	WC_TestComboBox testComboBox;
	testComboBox.DoModal();
}

void CMainWindow::OnWindowscontrolsTestradiobutton()
{
	WC_TestRadioButtons testRB;
	testRB.DoModal();
}

void CMainWindow::OnWindowscontrolsTestspinbutton()
{
	
}

void CMainWindow::OnWindowscontrolsTestprogressbar()
{
	
}

void CMainWindow::OnWindowscontrolsTestdatetimepicker()
{
	
}

void CMainWindow::OnWindowscontrolsTestscrollbar()
{
	
}

void CMainWindow::OnWindowscontrolsTesttree()
{
	
}

void CMainWindow::OnWindowscontrolsTestlist()
{
	
}

void CMainWindow::OnHelpAbout()
{
	AfxMessageBox(L"Author: Nguyen Chiem Minh Vu\nnguyenchiemminhvu@gmail.com\n093.435.9954");
}
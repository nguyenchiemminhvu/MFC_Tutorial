#include "MainApp.h"

#include "FirstWindow.h"
#include "DialogLogin.h"

#include "resource.h"

CMainApp theApp;

CMainApp::CMainApp(void)
{
}

CMainApp::~CMainApp(void)
{
}

BOOL CMainApp::InitInstance()
{
	if (!CWinApp::InitInstance())
		return FALSE;

	CDialogLogin *dLogin = new CDialogLogin();
	int loginRes = dLogin->DoModal();
	if (loginRes == IDOK)
	{
		AfxMessageBox(L"Login successfully");
	}
	else
	{
		delete dLogin;
		return FALSE;
	}

	CFirstWindow *firstWin = new CFirstWindow();
	m_pMainWnd = firstWin;
	firstWin->ShowWindow(SW_SHOWNORMAL);
	firstWin->CenterWindow();
	firstWin->UpdateWindow();

	delete dLogin;

	return TRUE;
}
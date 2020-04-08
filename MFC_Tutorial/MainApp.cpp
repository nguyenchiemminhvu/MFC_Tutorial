#include "MainApp.h"

#include "FirstWindow.h"

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

	CFirstWindow *firstWin = new CFirstWindow();

	m_pMainWnd = firstWin;
	
	firstWin->ShowWindow(SW_SHOWNORMAL);
	firstWin->UpdateWindow();

	return TRUE;
}
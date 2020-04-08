#include "MainApp.h"

#include "MainWindow.h"
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
	if (loginRes != IDOK)
	{
		delete dLogin;
		return FALSE;
	}

	CMainWindow *firstWin = new CMainWindow();
	m_pMainWnd = firstWin;
	firstWin->ShowWindow(SW_SHOWNORMAL);
	firstWin->CenterWindow();
	firstWin->UpdateWindow();
	firstWin->LoadAccelTable(MAKEINTRESOURCE(IDR_ACCELERATOR_1));

	m_hAccel = LoadAccelerators(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_ACCELERATOR_1));
	delete dLogin;

	return TRUE;
}

BOOL CMainApp::ProcessMessageFilter(int code, LPMSG msg)
{
	if (code >= 0 && AfxGetApp()->m_pMainWnd && m_hAccel)
	{
		if (::TranslateAccelerator(AfxGetApp()->m_pMainWnd->m_hWnd, m_hAccel, msg))
		{
			AfxMessageBox(L"TEST");
			return TRUE;
		}
	}

	return CWinApp::ProcessMessageFilter(code, msg);
}
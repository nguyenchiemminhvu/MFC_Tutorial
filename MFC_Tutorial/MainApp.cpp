#include "MainApp.h"

#include "MainWindow.h"
#include "DialogLogin.h"

#include "oracl.h"
#include "resource.h"

#include <string>
#include <fstream>

CMainApp theApp;

CMainApp::CMainApp(void)
{
	OStartup();
}

CMainApp::~CMainApp(void)
{
	OShutdown();
}

BOOL CMainApp::InitInstance()
{
	if (!CWinApp::InitInstance())
		return FALSE;

	// create needed folders
	DWORD att = GetFileAttributes(L".\\DOWNLOADS");
	if (!(att != INVALID_FILE_ATTRIBUTES && (att & FILE_ATTRIBUTE_DIRECTORY))) // check dir not exists
	{
		if (!CreateDirectory(L".\\DOWNLOADS", NULL))
		{
			AfxMessageBox(L"Can not create folders");
			return FALSE;
		}
	}

	att = GetFileAttributes(L".\\CONFIGS");
	if (!(att != INVALID_FILE_ATTRIBUTES && (att & FILE_ATTRIBUTE_DIRECTORY))) // check dir not exists
	{
		if (!CreateDirectory(L".\\CONFIGS", NULL))
		{
			AfxMessageBox(L"Can not create folders");
			return FALSE;
		}
	}

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
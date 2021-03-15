#include "MainApp.h"

#include "MainWindow.h"
#include "DialogLogin.h"

#include "oracl.h"
#include "resource.h"

#include <string>
#include <fstream>

#include <winreg.h>

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

	// register the application
	RegisterTheApplication();

	//CDialogLogin *dLogin = new CDialogLogin();
	//int loginRes = dLogin->DoModal();
	//if (loginRes != IDOK)
	//{
	//	delete dLogin;
	//	return FALSE;
	//}

	CMainWindow *firstWin = new CMainWindow();
	m_pMainWnd = firstWin;
	firstWin->ShowWindow(SW_SHOWNORMAL);
	firstWin->CenterWindow();
	firstWin->UpdateWindow();
	firstWin->LoadAccelTable(MAKEINTRESOURCE(IDR_ACCELERATOR_1));

	m_hAccel = LoadAccelerators(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_ACCELERATOR_1));
	//delete dLogin;

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

void CMainApp::RegisterTheApplication()
{
	HKEY key;

	ULONG res = RegOpenKeyEx(
		HKEY_LOCAL_MACHINE,
		L"SOFTWARE\\MFC_Tutorial\\",
		REG_OPTION_NON_VOLATILE,
		KEY_ALL_ACCESS,
		&key
	);
	
	if (res != ERROR_SUCCESS)
	{
		// Setup registry values for the first time
		DWORD dispos;
		RegCreateKeyEx(
			HKEY_LOCAL_MACHINE,
			L"SOFTWARE\\MFC_Tutorial\\",
			0,
			NULL,
			REG_OPTION_NON_VOLATILE,
			KEY_ALL_ACCESS,
			NULL,
			&key,
			&dispos
		);
		
		int CountAccess = 0;
		RegSetValueEx(
			key, 
			L"CountAccess", 
			0, 
			REG_DWORD, 
			(BYTE *)(void*)(&CountAccess), 
			sizeof(CountAccess)
		);

		WCHAR version[] = L"1.0.0";
		RegSetValueEx(
			key,
			L"Version",
			0,
			REG_SZ,
			(LPBYTE)(version),
			(DWORD)((lstrlen(version)+1) * 2)
		);
	}
	else
	{
		// increase access time
		DWORD CountAccess;
		DWORD Len;
		RegQueryValueEx(
			key,
			L"CountAccess",
			0,
			0,
			(LPBYTE)(&CountAccess),
			&Len
		);

		CountAccess++;
		RegSetValueEx(
			key,
			L"CountAccess",
			0,
			REG_DWORD,
			(BYTE*)(void*)(&CountAccess),
			sizeof(DWORD)
		);
	}

	RegCloseKey(key);
}
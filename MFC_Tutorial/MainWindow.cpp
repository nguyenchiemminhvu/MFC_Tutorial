#include "MainWindow.h"
#include "DialogLogin.h"

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
END_MESSAGE_MAP()

// CMainWindow message handlers

void CMainWindow::OnUpdateToolsDxdiag(CCmdUI *pCmdUI)
{
	pCmdUI->Enable();
}

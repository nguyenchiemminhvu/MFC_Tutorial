#include "FirstWindow.h"
#include "DialogLogin.h"
#include <winuser.h>
#include "resource.h"

IMPLEMENT_DYNAMIC(CFirstWindow, CFrameWnd)

CFirstWindow::CFirstWindow(void)
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

CFirstWindow::~CFirstWindow(void)
{
}

void CFirstWindow::DoDataExchange(CDataExchange* pDX)
{
	CFrameWnd::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFirstWindow, CFrameWnd)
	ON_UPDATE_COMMAND_UI(ID_HELP_ABOUT, &CFirstWindow::OnUpdateHelpAbout)
	ON_UPDATE_COMMAND_UI(ID_FILE_NEWLOGIN, &CFirstWindow::OnUpdateFileNewlogin)
	ON_COMMAND(ID_FILE_NEWLOGIN, &CFirstWindow::OnFileNewlogin)
	ON_COMMAND(ID_HELP_ABOUT, &CFirstWindow::OnHelpAbout)
END_MESSAGE_MAP()

// CFirstWindow message handlers

void CFirstWindow::OnUpdateHelpAbout(CCmdUI *pCmdUI)
{
	pCmdUI->Enable();
}


void CFirstWindow::OnUpdateFileNewlogin(CCmdUI *pCmdUI)
{
	pCmdUI->Enable();
}

void CFirstWindow::OnFileNewlogin()
{
	CDialogLogin d;
	d.DoModal();
}

void CFirstWindow::OnHelpAbout()
{
	AfxMessageBox(L"About");
}

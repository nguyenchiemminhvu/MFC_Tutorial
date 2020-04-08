#include "FirstWindow.h"

CFirstWindow::CFirstWindow(void)
	: CFrameWnd()
{
	RECT r;
	r.left = 0;
	r.right = 600;
	r.top = 0;
	r.bottom = 400;
	Create(NULL, L"MFC Tutorial First Window", WS_SYSMENU | WS_OVERLAPPED, r, 0, 0, 0, 0);
}

CFirstWindow::~CFirstWindow(void)
{
}

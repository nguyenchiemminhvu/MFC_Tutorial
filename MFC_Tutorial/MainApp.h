#pragma once

#ifndef __MAIN_APP_H__
#define __MAIN_APP_H__

#include <afxwin.h>

class CMainApp :
	public CWinApp
{
public:
	CMainApp(void);
	virtual ~CMainApp(void);

public:
	BOOL InitInstance();
};

extern CMainApp theApp;

#endif // __MAIN_APP_H__
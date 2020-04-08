#pragma once

#ifndef __MAIN_APP_H__
#define __MAIN_APP_H__

#include <afxwin.h>

class CMainApp :
	public CWinApp
{
public:
	HACCEL m_hAccel;

public:
	CMainApp(void);
	virtual ~CMainApp(void);

public:
	BOOL InitInstance();

public:
	afx_msg BOOL ProcessMessageFilter(int code, LPMSG msg);
};

extern CMainApp theApp;

#endif // __MAIN_APP_H__
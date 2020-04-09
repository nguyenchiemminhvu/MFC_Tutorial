#pragma once

#ifndef __MAIN_WINDOW_H__
#define __MAIN_WINDOW_H__

#include <afxwin.h>

class CMainWindow :
	public CFrameWnd
{
	DECLARE_DYNAMIC(CMainWindow)

public:
	CMainWindow(void);
	virtual ~CMainWindow(void);

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	afx_msg void OnUpdateToolsDxdiag(CCmdUI *pCmdUI);
	afx_msg void OnUpdateToolsSettings(CCmdUI *pCmdUI);
	afx_msg void OnUpdateHelpAbout(CCmdUI *pCmdUI);
	afx_msg void OnHelpAbout();
	afx_msg void OnToolsDxdiag();
	afx_msg void OnToolsSettings();
};

#endif // __MAIN_WINDOW_H__
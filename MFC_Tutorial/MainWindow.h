#pragma once

#include <afxwin.h>

class CMainWindow :
	public CFrameWnd
{
	DECLARE_DYNAMIC(CMainWindow)

public:
	CMainWindow(void);
	virtual ~CMainWindow(void);

public:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	afx_msg void OnUpdateToolsDxdiag(CCmdUI *pCmdUI);
	afx_msg void OnUpdateHelpAbout(CCmdUI *pCmdUI);
	afx_msg void OnHelpAbout();
	afx_msg void OnToolsDxdiag();
};

#pragma once

#include <afxwin.h>

class CFirstWindow :
	public CFrameWnd
{
	DECLARE_DYNAMIC(CFirstWindow)

public:
	CFirstWindow(void);
	virtual ~CFirstWindow(void);

public:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnUpdateHelpAbout(CCmdUI *pCmdUI);
	afx_msg void OnUpdateFileNewlogin(CCmdUI *pCmdUI);
	afx_msg void OnFileNewlogin();
	afx_msg void OnHelpAbout();
};

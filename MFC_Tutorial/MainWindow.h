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
	afx_msg void OnUpdateWindowscontrolsTestlistbox(CCmdUI *pCmdUI);
	afx_msg void OnUpdateWindowscontrolsTestcombobox(CCmdUI *pCmdUI);
	afx_msg void OnUpdateWindowscontrolsTestradiobutton(CCmdUI *pCmdUI);
	afx_msg void OnUpdateWindowscontrolsTestcheckbox(CCmdUI *pCmdUI);
	afx_msg void OnUpdateWindowscontrolsTestspinbutton(CCmdUI *pCmdUI);
	afx_msg void OnUpdateWindowscontrolsTestprogressbar(CCmdUI *pCmdUI);
	afx_msg void OnUpdateWindowscontrolsTestdatetimepicker(CCmdUI *pCmdUI);
	afx_msg void OnUpdateWindowscontrolsTestscrollbar(CCmdUI *pCmdUI);
	afx_msg void OnUpdateWindowscontrolsTesttree(CCmdUI *pCmdUI);
	afx_msg void OnUpdateWindowscontrolsTestlist(CCmdUI *pCmdUI);
	afx_msg void OnUpdateHelpAbout(CCmdUI *pCmdUI);

	afx_msg void OnToolsDxdiag();
	afx_msg void OnToolsSettings();
	afx_msg void OnWindowscontrolsTestlistbox();
	afx_msg void OnWindowscontrolsTestcombobox();
	afx_msg void OnWindowscontrolsTestradiobutton();
	afx_msg void OnWindowscontrolsTestcheckbox();
	afx_msg void OnWindowscontrolsTestspinbutton();
	afx_msg void OnWindowscontrolsTestprogressbar();
	afx_msg void OnWindowscontrolsTestdatetimepicker();
	afx_msg void OnWindowscontrolsTestscrollbar();
	afx_msg void OnWindowscontrolsTesttree();
	afx_msg void OnWindowscontrolsTestlist();
	afx_msg void OnHelpAbout();
};

#endif // __MAIN_WINDOW_H__
#pragma once

#ifndef __DIALOG_LOGIN_H__
#define __DIALOG_LOGIN_H__

#include <afxwin.h>
#include "resource.h"

#include "ConnectionInfo.h"

class CDialogLogin : 
	public CDialog
{
	DECLARE_DYNAMIC(CDialogLogin)

public:
	CDialogLogin(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialogLogin();

	virtual bool TestConnection(CString db, CString u, CString p);

// Dialog Data
	enum { IDD = IDD_DIALOG_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

	afx_msg virtual BOOL OnInitDialog();
	afx_msg void OnBnClicked_CheckLogin();
	afx_msg void OnBnClicked_OK();
	afx_msg void OnBnClicked_Cancel();

public:
	CEdit m_editDBName;
	CEdit m_editUsername;
	CEdit m_editPassword;

	CButton m_checkLogin;
	CButton m_buttonLogin;

private:
	CConnectionInfo conInfo;
};

#endif // __DIALOG_LOGIN_H__
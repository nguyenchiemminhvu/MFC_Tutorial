#pragma once

#ifndef __DIALOG_LOGIN_H__
#define __DIALOG_LOGIN_H__

#include <afxwin.h>
#include "resource.h"

class CDialogLogin : 
	public CDialog
{
	DECLARE_DYNAMIC(CDialogLogin)

public:
	CDialogLogin(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialogLogin();

// Dialog Data
	enum { IDD = IDD_DIALOG_LOGIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};

#endif // __DIALOG_LOGIN_H__
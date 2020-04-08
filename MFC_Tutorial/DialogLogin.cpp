// DialogLogin.cpp : implementation file
//

#include "stdafx.h"
#include "DialogLogin.h"

IMPLEMENT_DYNAMIC(CDialogLogin, CDialog)

CDialogLogin::CDialogLogin(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogLogin::IDD, pParent)
{
	
}

CDialogLogin::~CDialogLogin()
{
}

void CDialogLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogLogin, CDialog)
END_MESSAGE_MAP()


// CDialogLogin message handlers
BOOL CDialogLogin::OnInitDialog()
{
	if (!CDialog::OnInitDialog())
		return FALSE;

	HICON iconLogin = AfxGetApp()->LoadIcon(IDI_ICON_LOGIN);
	SetIcon(iconLogin, FALSE);

	return TRUE;
}
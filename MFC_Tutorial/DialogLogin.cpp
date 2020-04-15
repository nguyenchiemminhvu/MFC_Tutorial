// DialogLogin.cpp : implementation file
//

#include "stdafx.h"
#include "DialogLogin.h"
#include "oracl.h"

#include <stdio.h>

char *DB_NAME = new char[30];
char *USER_NAME = new char[30];
char *PASS_WORD = new char[30];

IMPLEMENT_DYNAMIC(CDialogLogin, CDialog)

CDialogLogin::CDialogLogin(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogLogin::IDD, pParent)
{
	
}

CDialogLogin::~CDialogLogin()
{
}

bool CDialogLogin::TestConnection(CString d, CString u, CString p)
{
	CT2A _d(d), _u(u), _p(p);
	const char *cDBName = _d.m_psz;
	const char *cUsername = _u.m_psz;
	const char *cPassword = _p.m_psz;

	sprintf(DB_NAME, "%s", cDBName);
	sprintf(USER_NAME, "%s", cUsername);
	sprintf(PASS_WORD, "%s", cPassword);

	ODatabase db;
	db.Open(cDBName, cUsername, cPassword);
	if (!db.IsOpen())
	{
		return false;
	}
	
	db.Close();
	return true;
}

void CDialogLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_EDIT_DBNAME, m_editDBName);
	DDX_Control(pDX, IDC_EDIT_USERNAME, m_editUsername);
	DDX_Control(pDX, IDC_EDIT_PASSWORD, m_editPassword);

	DDX_Control(pDX, IDC_CHECK_LOGIN, m_checkLogin);
	DDX_Control(pDX, ID_BTN_LOGIN_OK, m_buttonLogin);
}


BEGIN_MESSAGE_MAP(CDialogLogin, CDialog)
	ON_BN_CLICKED(IDC_CHECK_LOGIN, &CDialogLogin::OnBnClicked_CheckLogin)
	ON_BN_CLICKED(ID_BTN_LOGIN_OK, &CDialogLogin::OnBnClicked_OK)
	ON_BN_CLICKED(ID_BTN_LOGIN_CANCEL, &CDialogLogin::OnBnClicked_Cancel)
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

void CDialogLogin::OnBnClicked_CheckLogin()
{
	UpdateData(TRUE);
}

void CDialogLogin::OnBnClicked_OK()
{
	m_editDBName.GetWindowText(conInfo.DBName);
	m_editUsername.GetWindowText(conInfo.UserName);
	m_editPassword.GetWindowText(conInfo.Password);

	if (TestConnection(conInfo.DBName, conInfo.UserName, conInfo.Password))
	{
		// Save connection info to file
		if (m_checkLogin.GetCheck())
		{
		}

		CDialog::OnOK();
	}
	else
	{
		m_editDBName.SetWindowText(L"");
		m_editUsername.SetWindowText(L"");
		m_editPassword.SetWindowText(L"");
		AfxMessageBox(L"Failed to connect!");
	}
}

void CDialogLogin::OnBnClicked_Cancel()
{
	CDialog::OnCancel();
}

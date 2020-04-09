// DialogLogin.cpp : implementation file
//

#include "stdafx.h"
#include "DialogLogin.h"
#include "oracl.h"

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

	UpdateData(TRUE);
	m_checkLogin.SetCheck(1);
	if (m_checkLogin.GetCheck())
		m_buttonLogin.EnableWindow(TRUE);
	else
		m_buttonLogin.EnableWindow(FALSE);

	return TRUE;
}

void CDialogLogin::OnBnClicked_CheckLogin()
{
	UpdateData(TRUE);
	if (m_checkLogin.GetCheck())
		m_buttonLogin.EnableWindow(TRUE);
	else
		m_buttonLogin.EnableWindow(FALSE);
}

void CDialogLogin::OnBnClicked_OK()
{
	CString DBName, Username, Password;
	m_editDBName.GetWindowText(DBName);
	m_editUsername.GetWindowText(Username);
	m_editPassword.GetWindowText(Password);

	if (TestConnection(DBName, Username, Password))
	{
		CString res;
		res.Append(L"Connected!\n");
		res.Append(Username);
		res.Append(L"/");
		res.Append(DBName);
		AfxMessageBox(res);

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

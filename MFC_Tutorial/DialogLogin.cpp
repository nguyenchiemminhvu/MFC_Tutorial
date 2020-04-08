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

	DDX_Control(pDX, IDC_EDIT_DBNAME, m_editDBName);
	DDX_Control(pDX, IDC_EDIT_USERNAME, m_editUsername);
	DDX_Control(pDX, IDC_EDIT_PASSWORD, m_editPassword);
}


BEGIN_MESSAGE_MAP(CDialogLogin, CDialog)
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

void CDialogLogin::OnBnClicked_OK()
{
	CString DBName, Username, Password;
	m_editDBName.GetWindowText(DBName);
	m_editUsername.GetWindowText(Username);
	m_editPassword.GetWindowText(Password);

	CString combine;
	combine.Append(L"Connection:\n");
	combine.Append(DBName);
	combine.Append(L"\n");
	combine.Append(Username);
	combine.Append(L"\n");
	combine.Append(Password);
	AfxMessageBox(combine);

	CDialog::OnOK();
}

void CDialogLogin::OnBnClicked_Cancel()
{
	CDialog::OnCancel();
}

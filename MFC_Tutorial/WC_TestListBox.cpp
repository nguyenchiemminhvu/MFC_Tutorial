// WC_TestListBox.cpp : implementation file
//

#include "stdafx.h"
#include "WC_TestListBox.h"


// WC_TestListBox dialog

IMPLEMENT_DYNAMIC(WC_TestListBox, CDialog)

WC_TestListBox::WC_TestListBox(CWnd* pParent /*=NULL*/)
	: CDialog(WC_TestListBox::IDD, pParent)
	, m_leftSelected(_T(""))
	, m_rightSelected(_T(""))
{

}

WC_TestListBox::~WC_TestListBox()
{
}

void WC_TestListBox::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_BUTTON_LEFT_TO_RIGHT, m_BtnLeftToRight);
	DDX_Control(pDX, IDC_BUTTON_RIGHT_TO_LEFT, m_BtnRightToLeft);

	DDX_LBString(pDX, IDC_LIST_LEFT, m_leftSelected);
	DDX_Control(pDX, IDC_LIST_LEFT, m_ListBoxLeft);

	DDX_LBString(pDX, IDC_LIST_RIGHT, m_rightSelected);
	DDX_Control(pDX, IDC_LIST_RIGHT, m_ListBoxRight);
}


BEGIN_MESSAGE_MAP(WC_TestListBox, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_LEFT_TO_RIGHT, &WC_TestListBox::OnBnClickedButtonLeftToRight)
	ON_BN_CLICKED(IDC_BUTTON_RIGHT_TO_LEFT, &WC_TestListBox::OnBnClickedButtonRightToLeft)

	ON_LBN_SELCHANGE(IDC_LIST_LEFT, &WC_TestListBox::OnLbnSelchangeListLeft)
	ON_LBN_SELCHANGE(IDC_LIST_RIGHT, &WC_TestListBox::OnLbnSelchangeListRight)

	ON_BN_CLICKED(IDOK, &WC_TestListBox::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &WC_TestListBox::OnBnClickedCancel)
END_MESSAGE_MAP()


// WC_TestListBox message handlers
BOOL WC_TestListBox::OnInitDialog()
{
	if (!CDialog::OnInitDialog())
		return FALSE;

	HBITMAP bmLeftToRight = (HBITMAP)LoadImage(
		AfxGetApp()->m_hInstance,
		MAKEINTRESOURCE(IDB_BITMAP_LEFT_TO_RIGHT),
		IMAGE_BITMAP,
		0,0, // use actual size
		LR_DEFAULTCOLOR
	);
	m_BtnLeftToRight.ModifyStyle(0, BS_BITMAP);
	m_BtnLeftToRight.SetBitmap(bmLeftToRight);
	m_BtnLeftToRight.EnableWindow(FALSE);

	HBITMAP bmRightToLeft = (HBITMAP)LoadImage(
		AfxGetApp()->m_hInstance,
		MAKEINTRESOURCE(IDB_BITMAP_RIGHT_TO_LEFT),
		IMAGE_BITMAP,
		0,0, // use actual size
		LR_DEFAULTCOLOR
	);
	m_BtnRightToLeft.ModifyStyle(0, BS_BITMAP);
	m_BtnRightToLeft.SetBitmap(bmRightToLeft);
	m_BtnRightToLeft.EnableWindow(FALSE);

	// Init Left ListBox
	for (int i = 1; i < 10; i++)
	{
		CString option;
		option.Format(L"Option %d", i);
		m_ListBoxLeft.AddString(option);
	}
	
	return TRUE;
}

void WC_TestListBox::OnBnClickedButtonLeftToRight()
{
	m_ListBoxLeft.DeleteString(m_ListBoxLeft.GetCurSel());
	m_ListBoxRight.AddString(m_leftSelected);
	m_leftSelected = L"";

	if (m_ListBoxLeft.GetCount() == 0)
	{
		m_BtnLeftToRight.EnableWindow(FALSE);
	}
}

void WC_TestListBox::OnBnClickedButtonRightToLeft()
{
	m_ListBoxRight.DeleteString(m_ListBoxRight.GetCurSel());
	m_ListBoxLeft.AddString(m_rightSelected);
	m_rightSelected = L"";

	if (m_ListBoxRight.GetCount() == 0)
	{
		m_BtnRightToLeft.EnableWindow(FALSE);
	}
}

void WC_TestListBox::OnLbnSelchangeListLeft()
{
	m_ListBoxLeft.GetText(m_ListBoxLeft.GetCurSel(), m_leftSelected);
	m_BtnLeftToRight.EnableWindow(TRUE);
}

void WC_TestListBox::OnLbnSelchangeListRight()
{
	m_ListBoxRight.GetText(m_ListBoxRight.GetCurSel(), m_rightSelected);
	m_BtnRightToLeft.EnableWindow(TRUE);
}

void WC_TestListBox::OnBnClickedOk()
{
	CDialog::OnOK();
}

void WC_TestListBox::OnBnClickedCancel()
{
	CDialog::OnCancel();
}

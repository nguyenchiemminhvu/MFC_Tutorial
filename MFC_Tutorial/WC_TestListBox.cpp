// WC_TestListBox.cpp : implementation file
//

#include "stdafx.h"
#include "WC_TestListBox.h"


// WC_TestListBox dialog

IMPLEMENT_DYNAMIC(WC_TestListBox, CDialog)

WC_TestListBox::WC_TestListBox(CWnd* pParent /*=NULL*/)
	: CDialog(WC_TestListBox::IDD, pParent)
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
}


BEGIN_MESSAGE_MAP(WC_TestListBox, CDialog)
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

	HBITMAP bmRightToLeft = (HBITMAP)LoadImage(
		AfxGetApp()->m_hInstance,
		MAKEINTRESOURCE(IDB_BITMAP_RIGHT_TO_LEFT),
		IMAGE_BITMAP,
		0,0, // use actual size
		LR_DEFAULTCOLOR
	);
	m_BtnRightToLeft.ModifyStyle(0, BS_BITMAP);
	m_BtnRightToLeft.SetBitmap(bmRightToLeft);
	
	return TRUE;
}
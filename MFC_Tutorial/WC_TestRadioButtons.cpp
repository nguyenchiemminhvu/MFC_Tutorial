// WC_TestRadioButtons.cpp : implementation file
//

#include "stdafx.h"
#include "WC_TestRadioButtons.h"


IMPLEMENT_DYNAMIC(WC_TestRadioButtons, CDialog)

WC_TestRadioButtons::WC_TestRadioButtons(CWnd* pParent /*=NULL*/)
	: CDialog(WC_TestRadioButtons::IDD, pParent)
{

}

WC_TestRadioButtons::~WC_TestRadioButtons()
{
}

void WC_TestRadioButtons::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RADIO_1_OPTION_1, m_G1_Option1);
	DDX_Control(pDX, IDC_RADIO_1_OPTION_2, m_G1_Option2);
	DDX_Control(pDX, IDC_RADIO_1_OPTION_3, m_G1_Option3);

	DDX_Control(pDX, IDC_RADIO_2_OPTION_1, m_G2_Option1);
	DDX_Control(pDX, IDC_RADIO_2_OPTION_2, m_G2_Option2);
	DDX_Control(pDX, IDC_RADIO_2_OPTION_3, m_G2_Option3);

	DDX_Control(pDX, IDC_STATIC_OPTION, m_listOption);
}


BEGIN_MESSAGE_MAP(WC_TestRadioButtons, CDialog)
	ON_BN_CLICKED(IDC_RADIO_1_OPTION_1, &WC_TestRadioButtons::OnBnClickedRadio1Option1)
	ON_BN_CLICKED(IDC_RADIO_1_OPTION_2, &WC_TestRadioButtons::OnBnClickedRadio1Option2)
	ON_BN_CLICKED(IDC_RADIO_1_OPTION_3, &WC_TestRadioButtons::OnBnClickedRadio1Option3)
	ON_BN_CLICKED(IDC_RADIO_2_OPTION_1, &WC_TestRadioButtons::OnBnClickedRadio2Option1)
	ON_BN_CLICKED(IDC_RADIO_2_OPTION_2, &WC_TestRadioButtons::OnBnClickedRadio2Option2)
	ON_BN_CLICKED(IDC_RADIO_2_OPTION_3, &WC_TestRadioButtons::OnBnClickedRadio2Option3)
END_MESSAGE_MAP()


// WC_TestRadioButtons message handlers
BOOL WC_TestRadioButtons::OnInitDialog()
{
	if (!CDialog::OnInitDialog())
		return FALSE;

	return TRUE;
}

void WC_TestRadioButtons::OnBnClickedRadio1Option1()
{
	UpdateSettings();
}

void WC_TestRadioButtons::OnBnClickedRadio1Option2()
{
	UpdateSettings();
}

void WC_TestRadioButtons::OnBnClickedRadio1Option3()
{
	UpdateSettings();
}

void WC_TestRadioButtons::OnBnClickedRadio2Option1()
{
	UpdateSettings();
}

void WC_TestRadioButtons::OnBnClickedRadio2Option2()
{
	UpdateSettings();
}

void WC_TestRadioButtons::OnBnClickedRadio2Option3()
{
	UpdateSettings();
}

void WC_TestRadioButtons::UpdateSettings()
{
	m_listOption.SetWindowText(L"");

	CString options;

	// Group 1
	if (m_G1_Option1.GetCheck())
		options.Append(L"Group 1 - Option 1\n");
	if (m_G1_Option2.GetCheck())
		options.Append(L"Group 1 - Option 2\n");
	if (m_G1_Option3.GetCheck())
		options.Append(L"Group 1 - Option 3\n");

	// Group 2
	if (m_G2_Option1.GetCheck())
		options.Append(L"Group 2 - Option 1\n");
	if (m_G2_Option2.GetCheck())
		options.Append(L"Group 2 - Option 2\n");
	if (m_G2_Option3.GetCheck())
		options.Append(L"Group 2 - Option 3\n");

	m_listOption.SetWindowText(options);
}
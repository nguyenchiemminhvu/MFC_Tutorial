// WC_TestSlider.cpp : implementation file
//

#include "stdafx.h"
#include "WC_TestSlider.h"


IMPLEMENT_DYNAMIC(WC_TestSlider, CDialog)

WC_TestSlider::WC_TestSlider(CWnd* pParent /*=NULL*/)
	: CDialog(WC_TestSlider::IDD, pParent)
{

}

WC_TestSlider::~WC_TestSlider()
{
}

void WC_TestSlider::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(WC_TestSlider, CDialog)
END_MESSAGE_MAP()


// WC_TestSlider message handlers

BOOL WC_TestSlider::OnInitDialog()
{
	if (!CDialog::OnInitDialog())
		return FALSE;

	
	return TRUE;
}
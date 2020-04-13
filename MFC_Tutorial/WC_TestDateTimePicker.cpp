// WC_TestDateTimePicker.cpp : implementation file
//

#include "stdafx.h"
#include "WC_TestDateTimePicker.h"


IMPLEMENT_DYNAMIC(WC_TestDateTimePicker, CDialog)

WC_TestDateTimePicker::WC_TestDateTimePicker(CWnd* pParent /*=NULL*/)
	: CDialog(WC_TestDateTimePicker::IDD, pParent)
{

}

WC_TestDateTimePicker::~WC_TestDateTimePicker()
{
}

void WC_TestDateTimePicker::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(WC_TestDateTimePicker, CDialog)
END_MESSAGE_MAP()


// WC_TestDateTimePicker message handlers

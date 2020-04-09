// DXDIAG_Display.cpp : implementation file
//

#include "stdafx.h"
#include "DXDIAG_Display.h"


// DXDIAG_Display dialog

IMPLEMENT_DYNAMIC(DXDIAG_Display, CPropertyPage)

DXDIAG_Display::DXDIAG_Display()
	: CPropertyPage(DXDIAG_Display::IDD)
{

}

DXDIAG_Display::~DXDIAG_Display()
{
}

void DXDIAG_Display::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DXDIAG_Display, CPropertyPage)
END_MESSAGE_MAP()


// DXDIAG_Display message handlers

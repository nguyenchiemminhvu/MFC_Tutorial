// DXDIAG_System.cpp : implementation file
//

#include "stdafx.h"
#include "DXDIAG_System.h"


// DXDIAG_System dialog

IMPLEMENT_DYNAMIC(DXDIAG_System, CPropertyPage)

DXDIAG_System::DXDIAG_System()
	: CPropertyPage(DXDIAG_System::IDD)
{

}

DXDIAG_System::~DXDIAG_System()
{
}

void DXDIAG_System::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DXDIAG_System, CPropertyPage)
END_MESSAGE_MAP()


// DXDIAG_System message handlers

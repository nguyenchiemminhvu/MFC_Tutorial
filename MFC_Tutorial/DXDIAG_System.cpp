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
	DDX_Control(pDX, IDC_SYSTEM_DATE_TIME, m_System_CurDateTime);
	DDX_Control(pDX, IDC_SYSTEM_COMPUTER_NAME, m_System_ComputerName);
	DDX_Control(pDX, IDC_SYSTEM_OP, m_System_OP);
	DDX_Control(pDX, IDC_SYSTEM_LANGUAGE, m_System_Language);
	DDX_Control(pDX, IDC_SYSTEM_MANUFACTORING, m_System_Manufactoring);
	DDX_Control(pDX, IDC_SYSTEM_MODEL, m_System_Model);
	DDX_Control(pDX, IDC_SYSTEM_BIOS, m_System_BIOS);
	DDX_Control(pDX, IDC_SYSTEM_PROCESSOR, m_System_Processor);
	DDX_Control(pDX, IDC_SYSTEM_MEMORY, m_System_Memory);
	DDX_Control(pDX, IDC_SYSTEM_PAGE_FILE, m_System_PageFile);
	DDX_Control(pDX, IDC_SYSTEM_DX_VERSION, m_System_DXVersion);
}


BEGIN_MESSAGE_MAP(DXDIAG_System, CPropertyPage)
END_MESSAGE_MAP()


// DXDIAG_System message handlers
BOOL DXDIAG_System::OnInitDialog()
{
	if (!CDialog::OnInitDialog())
		return FALSE;
	
	
	return TRUE;
}
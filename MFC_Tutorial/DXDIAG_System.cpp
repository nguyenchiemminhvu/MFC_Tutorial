// DXDIAG_System.cpp : implementation file
//

#include "stdafx.h"
#include "DXDIAG_System.h"

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <winperf.h>

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
	ON_WM_TIMER()
END_MESSAGE_MAP()


// DXDIAG_System message handlers
BOOL DXDIAG_System::OnInitDialog()
{
	if (!CDialog::OnInitDialog())
		return FALSE;
	
	WCHAR lpComputerName[255];
	DWORD lpComputerNameSize;
	GetComputerName(lpComputerName, &lpComputerNameSize);
	m_System_ComputerName.SetWindowText(lpComputerName);

	//HKEY_LOCAL_MACHINE/ARDWARE/DESCRIPTION/System/BIOS/BIOSVersion
	m_System_BIOS.SetWindowText(L"NULL");

	const int bytesToMB = 1024 * 1024;
	MEMORYSTATUSEX memStatus;
	memStatus.dwLength = sizeof(memStatus);
	GlobalMemoryStatusEx(&memStatus);

	WCHAR lpMemory[255];
	swprintf(lpMemory, L"%d (MB) RAM", memStatus.ullTotalPhys / bytesToMB);
	m_System_Memory.SetWindowText(lpMemory);

	WCHAR lpPageFile[255];
	swprintf(lpPageFile, L"%d MB used, %d MB available", memStatus.ullTotalPageFile / bytesToMB, memStatus.ullAvailPageFile / bytesToMB);
	m_System_PageFile.SetWindowText(lpPageFile);

	SetTimer(1, 1, NULL);
	
	return TRUE;
}

void DXDIAG_System::OnTimer(UINT_PTR nIDEvent)
{
	CTime curTime = CTime::GetTickCount();
	int hh = curTime.GetHour();
	int mm = curTime.GetMinute();
	int ss = curTime.GetSecond();

	CString hhStr, mmStr, ssStr;
	hhStr.Format(L"%02d", hh);
	mmStr.Format(L"%02d", mm);
	ssStr.Format(L"%02d", ss);

	m_System_CurDateTime.SetWindowText(hhStr + ":" + mmStr + ":" + ssStr);

	CDialog::OnTimer(nIDEvent);
}
// IO_DrivesInfo.cpp : implementation file
//

#include "stdafx.h"
#include "IO_DrivesInfo.h"


IMPLEMENT_DYNAMIC(IO_DrivesInfo, CDialog)

IO_DrivesInfo::IO_DrivesInfo(CWnd* pParent /*=NULL*/)
	: CDialog(IO_DrivesInfo::IDD, pParent)
{

}

IO_DrivesInfo::~IO_DrivesInfo()
{
}

void IO_DrivesInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_DRIVES, m_comboDrives);
}


BEGIN_MESSAGE_MAP(IO_DrivesInfo, CDialog)
	ON_CBN_SELCHANGE(IDC_COMBO_DRIVES, &IO_DrivesInfo::OnCbnSelchangeComboDrives)
END_MESSAGE_MAP()


// IO_DrivesInfo message handlers

BOOL IO_DrivesInfo::OnInitDialog()
{
	if (!CDialog::OnInitDialog())
		return FALSE;

	DWORD availableDrives = GetLogicalDrives();
	for (int i = 0; i < 26; i++)
	{
		if (availableDrives & (1 << i))
		{
			WCHAR drive[255];
			swprintf(drive, L"%c:\\", 'A' + i);
			
			m_comboDrives.AddString(drive);
		}
	}

	return TRUE;
}

void IO_DrivesInfo::OnCbnSelchangeComboDrives()
{
	CString selectedDrive;
	m_comboDrives.GetLBText(m_comboDrives.GetCurSel(), selectedDrive);

	WIN32_FILE_ATTRIBUTE_DATA att;
	if (!GetFileAttributesEx(selectedDrive, GetFileExInfoStandard, &att))
		return;

	PULARGE_INTEGER a, b, c;
	GetDiskFreeSpaceEx(selectedDrive, a, b, c);

	WCHAR res[255];
	swprintf(res, L"%llu, %llu", b, c);

	AfxMessageBox(res);
}

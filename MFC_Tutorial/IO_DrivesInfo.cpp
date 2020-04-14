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
}


BEGIN_MESSAGE_MAP(IO_DrivesInfo, CDialog)
END_MESSAGE_MAP()


// IO_DrivesInfo message handlers

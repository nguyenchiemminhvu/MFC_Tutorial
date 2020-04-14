// IO_FileProcessing.cpp : implementation file
//

#include "stdafx.h"
#include "IO_FileProcessing.h"


IMPLEMENT_DYNAMIC(IO_FileProcessing, CDialog)

IO_FileProcessing::IO_FileProcessing(CWnd* pParent /*=NULL*/)
	: CDialog(IO_FileProcessing::IDD, pParent)
{

}

IO_FileProcessing::~IO_FileProcessing()
{
}

void IO_FileProcessing::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(IO_FileProcessing, CDialog)
END_MESSAGE_MAP()


// IO_FileProcessing message handlers

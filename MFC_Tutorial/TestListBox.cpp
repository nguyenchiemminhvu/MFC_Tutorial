// TestListBox.cpp : implementation file
//

#include "stdafx.h"
#include "TestListBox.h"


// TestListBox dialog

IMPLEMENT_DYNAMIC(TestListBox, CDialog)

TestListBox::TestListBox(CWnd* pParent /*=NULL*/)
	: CDialog(TestListBox::IDD, pParent)
{

}

TestListBox::~TestListBox()
{
}

void TestListBox::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TestListBox, CDialog)
END_MESSAGE_MAP()


// TestListBox message handlers

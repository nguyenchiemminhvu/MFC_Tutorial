// WC_TestTree.cpp : implementation file
//

#include "stdafx.h"
#include "WC_TestTree.h"

#include <oracl.h>

IMPLEMENT_DYNAMIC(WC_TestTree, CDialog)

WC_TestTree::WC_TestTree(CWnd* pParent /*=NULL*/)
	: CDialog(WC_TestTree::IDD, pParent)
{

}

WC_TestTree::~WC_TestTree()
{
}

void WC_TestTree::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(WC_TestTree, CDialog)
END_MESSAGE_MAP()


// WC_TestTree message handlers

BOOL WC_TestTree::OnInitDialog()
{
	if (!CDialog::OnInitDialog())
		return FALSE;

	
	return TRUE;
}
// DXDIAG_Sheet.cpp : implementation file
//

#include "stdafx.h"
#include "DXDIAG_Sheet.h"

IMPLEMENT_DYNAMIC(DXDIAG_Sheet, CPropertySheet)

DXDIAG_Sheet::DXDIAG_Sheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	
}

DXDIAG_Sheet::DXDIAG_Sheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{

}

DXDIAG_Sheet::~DXDIAG_Sheet()
{
}


BEGIN_MESSAGE_MAP(DXDIAG_Sheet, CPropertySheet)
END_MESSAGE_MAP()


// DXDIAG_Sheet message handlers

#pragma once

#ifndef __DXDIAG_SHEET_H__
#define __DXDIAG_SHEET_H__

#include <afxdlgs.h>

#include "DXDIAG_System.h"
#include "DXDIAG_Display.h"

class DXDIAG_Sheet : public CPropertySheet
{
	DECLARE_DYNAMIC(DXDIAG_Sheet)

public:
	DXDIAG_Sheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	DXDIAG_Sheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~DXDIAG_Sheet();

protected:
	DECLARE_MESSAGE_MAP()

public:
	afx_msg virtual BOOL OnInitDialog();
};

#endif // __DXDIAG_SHEET_H__
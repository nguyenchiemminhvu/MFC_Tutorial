#pragma once

#ifndef __DXDIAG_DISPLAY_H__
#define __DXDIAG_DISPLAY_H__

#include "resource.h"

class DXDIAG_Display : public CPropertyPage
{
	DECLARE_DYNAMIC(DXDIAG_Display)

public:
	DXDIAG_Display();
	virtual ~DXDIAG_Display();

// Dialog Data
	enum { IDD = IDD_DXDIAG_DISPLAY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};

#endif // __DXDIAG_DISPLAY_H__
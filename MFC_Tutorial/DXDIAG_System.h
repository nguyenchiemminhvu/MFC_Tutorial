#pragma once

#ifndef __DXDIAG_SYSTEM_H__
#define __DXDIAG_SYSTEM_H__

#include "resource.h"

class DXDIAG_System : public CPropertyPage
{
	DECLARE_DYNAMIC(DXDIAG_System)

public:
	DXDIAG_System();
	virtual ~DXDIAG_System();

// Dialog Data
	enum { IDD = IDD_DXDIAG_SYSTEM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};

#endif // __DXDIAG_SYSTEM_H__
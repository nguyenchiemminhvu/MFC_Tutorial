#pragma once

#ifndef __DXDIAG_SYSTEM_H__
#define __DXDIAG_SYSTEM_H__

#include "resource.h"
#include "afxwin.h"

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
	afx_msg virtual BOOL OnInitDialog();

public:
	CStatic m_System_CurDateTime;
	CStatic m_System_ComputerName;
	CStatic m_System_OP;
	CStatic m_System_Language;
	CStatic m_System_Manufactoring;
	CStatic m_System_Model;
	CStatic m_System_BIOS;
	CStatic m_System_Processor;
	CStatic m_System_Memory;
	CStatic m_System_PageFile;
	CStatic m_System_DXVersion;
};

#endif // __DXDIAG_SYSTEM_H__
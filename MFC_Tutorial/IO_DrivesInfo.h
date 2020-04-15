#pragma once

#ifndef __IO_DRIVES_INFO_H__
#define __IO_DRIVES_INFO_H__

#include <afxwin.h>
#include "resource.h"

class IO_DrivesInfo : public CDialog
{
	DECLARE_DYNAMIC(IO_DrivesInfo)

public:
	IO_DrivesInfo(CWnd* pParent = NULL);   // standard constructor
	virtual ~IO_DrivesInfo();

// Dialog Data
	enum { IDD = IDD_DIALOG_DRIVES_INFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

protected:
	afx_msg virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeComboDrives();

private:
	CComboBox m_comboDrives;
};

#endif // __IO_DRIVES_INFO_H__
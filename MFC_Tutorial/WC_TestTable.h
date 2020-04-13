#pragma once

#ifndef __WC_TEST_TABLE_H__
#define __WC_TEST_TABLE_H__

#include <afxwin.h>
#include "resource.h"

class WC_TestTable : public CDialog
{
	DECLARE_DYNAMIC(WC_TestTable)

public:
	WC_TestTable(CWnd* pParent = NULL);   // standard constructor
	virtual ~WC_TestTable();

// Dialog Data
	enum { IDD = IDD_WC_TABLE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

protected:
	afx_msg virtual BOOL OnInitDialog();

	afx_msg void OnCbnSelchangeComboDept();

private:
	CComboBox m_comboDept;
	CString m_selectedDept;
};

#endif // __WC_TEST_TABLE_H__
#pragma once

#ifndef __WC_TEST_SPIN_BUTTON_H__
#define __WC_TEST_SPIN_BUTTON_H__

#include <afxwin.h>
#include "resource.h"

class WC_TestSpinButton : public CDialog
{
	DECLARE_DYNAMIC(WC_TestSpinButton)

public:
	WC_TestSpinButton(CWnd* pParent = NULL);   // standard constructor
	virtual ~WC_TestSpinButton();

// Dialog Data
	enum { IDD = IDD_WC_SPINBUTTON };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

protected:
	afx_msg virtual BOOL OnInitDialog();

	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();

	afx_msg void OnCbnSelchangeComboDept();

	afx_msg void OnDeltaposSpinBonus(NMHDR *pNMHDR, LRESULT *pResult);

private:
	CComboBox m_comboDept;
	CString m_selectedDept;
	int m_selectedDeptID;

	CEdit m_editBonus;
};

#endif // __WC_TEST_SPIN_BUTTON_H__
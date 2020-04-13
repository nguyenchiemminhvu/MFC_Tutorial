#pragma once

#ifndef __WC_TEST_RADIO_BUTTON_H__
#define __WC_TEST_RADIO_BUTTON_H__

#include <afxwin.h>
#include "resource.h"

class WC_TestRadioButtons : public CDialog
{
	DECLARE_DYNAMIC(WC_TestRadioButtons)

public:
	WC_TestRadioButtons(CWnd* pParent = NULL);   // standard constructor
	virtual ~WC_TestRadioButtons();

// Dialog Data
	enum { IDD = IDD_WC_RADIOBUTTON };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg virtual BOOL OnInitDialog();

	afx_msg void OnBnClickedRadio1Option1();
	afx_msg void OnBnClickedRadio1Option2();
	afx_msg void OnBnClickedRadio1Option3();
	afx_msg void OnBnClickedRadio2Option1();
	afx_msg void OnBnClickedRadio2Option2();
	afx_msg void OnBnClickedRadio2Option3();

private:
	CButton m_G1_Option1;
	CButton m_G1_Option2;
	CButton m_G1_Option3;

private:
	CButton m_G2_Option1;
	CButton m_G2_Option2;
	CButton m_G2_Option3;

private:
	CStatic m_listOption;

private:
	void UpdateSettings();
};

#endif // __WC_TEST_RADIO_BUTTON_H__
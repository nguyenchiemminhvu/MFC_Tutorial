#pragma once

#ifndef __WC_TEST_COMBOBOX_H__
#define __WC_TEST_COMBOBOX_H__

#include <afxwin.h>

#include "resource.h"

class WC_TestComboBox : public CDialog
{
	DECLARE_DYNAMIC(WC_TestComboBox)

public:
	WC_TestComboBox(CWnd* pParent = NULL);   // standard constructor
	virtual ~WC_TestComboBox();

// Dialog Data
	enum { IDD = IDD_WC_COMBOBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

protected:
	afx_msg virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeComboImages();

private:
	CString m_selectedFileName;
	CComboBox m_comboBoxImages;
};

#endif // __WC_TEST_COMBOBOX_H__
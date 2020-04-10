#pragma once

#ifndef __WC_TEST_LISTBOX_H__
#define __WC_TEST_LISTBOX_H__

#include <afxwin.h>

#include "resource.h"

class WC_TestListBox : public CDialog
{
	DECLARE_DYNAMIC(WC_TestListBox)

public:
	WC_TestListBox(CWnd* pParent = NULL);   // standard constructor
	virtual ~WC_TestListBox();

// Dialog Data
	enum { IDD = IDD_WC_LISTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

protected:
	afx_msg virtual BOOL OnInitDialog();

	afx_msg void OnBnClickedButtonLeftToRight();
	afx_msg void OnBnClickedButtonRightToLeft();

	afx_msg void OnLbnSelchangeListLeft();
	afx_msg void OnLbnSelchangeListRight();

	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();

public:
	CButton m_BtnLeftToRight;
	CButton m_BtnRightToLeft;

	CString m_leftSelected;
	CListBox m_ListBoxLeft;

	CString m_rightSelected;
	CListBox m_ListBoxRight;
};

#endif // __WC_TEST_LISTBOX_H__
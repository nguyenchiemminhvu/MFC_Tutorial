#pragma once

#ifndef __WC_TEST_SLIDER_H__
#define __WC_TEST_SLIDER_H__

#include <afxwin.h>

#include "resource.h"

class WC_TestSlider : public CDialog
{
	DECLARE_DYNAMIC(WC_TestSlider)

public:
	WC_TestSlider(CWnd* pParent = NULL);   // standard constructor
	virtual ~WC_TestSlider();

// Dialog Data
	enum { IDD = IDD_WC_TESTSLIDER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

protected:
	afx_msg virtual BOOL OnInitDialog();
};

#endif // __WC_TEST_SLIDER_H__
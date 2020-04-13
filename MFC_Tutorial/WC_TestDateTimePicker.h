#pragma once

#ifndef __WC_TEST_DATETIME_PICKER_H__
#define __WC_TEST_DATETIME_PICKER_H__

#include <afxwin.h>
#include "resource.h"

class WC_TestDateTimePicker : public CDialog
{
	DECLARE_DYNAMIC(WC_TestDateTimePicker)

public:
	WC_TestDateTimePicker(CWnd* pParent = NULL);   // standard constructor
	virtual ~WC_TestDateTimePicker();

// Dialog Data
	enum { IDD = IDD_WC_DATETIMEPICKER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};

#endif // __WC_TEST_DATETIME_PICKER_H__
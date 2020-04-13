#pragma once

#ifndef __WC_TEST_TREE_H__
#define __WC_TEST_TREE_H__

#include <afxwin.h>
#include "resource.h"

class WC_TestTree : public CDialog
{
	DECLARE_DYNAMIC(WC_TestTree)

public:
	WC_TestTree(CWnd* pParent = NULL);   // standard constructor
	virtual ~WC_TestTree();

// Dialog Data
	enum { IDD = IDD_WC_TREE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

protected:
	afx_msg virtual BOOL OnInitDialog();
};

#endif // __WC_TEST_TREE_H__
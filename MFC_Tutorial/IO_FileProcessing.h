#pragma once

#ifndef __IO_FILE_PROCESSING_H__
#define __IO_FILE_PROCESSING_H__

#include <afxwin.h>
#include "resource.h"

class IO_FileProcessing : public CDialog
{
	DECLARE_DYNAMIC(IO_FileProcessing)

public:
	IO_FileProcessing(CWnd* pParent = NULL);   // standard constructor
	virtual ~IO_FileProcessing();

// Dialog Data
	enum { IDD = IDD_DIALOG_FILE_PROCESSING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

protected:
	afx_msg virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonFileOpen();
	afx_msg void OnBnClickedButtonFileSave();

private:
	CEdit m_editContent;
};

#endif // __IO_FILE_PROCESSING_H__
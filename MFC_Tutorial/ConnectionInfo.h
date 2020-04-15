#pragma once

#ifndef __CONNECTION_INFO_H__
#define __CONNECTION_INFO_H__

#include <afxwin.h>

class CConnectionInfo : public CObject
{
public:
	DECLARE_SERIAL(CConnectionInfo);
	virtual void Serialize(CArchive &ar);

public:
	CString DBName;
	CString UserName;
	CString Password;

public:
	CConnectionInfo();
	virtual ~CConnectionInfo();
};

#endif // __CONNECTION_INFO_H__
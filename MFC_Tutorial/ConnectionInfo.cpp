// ConnectionInfo.cpp : implementation file
//

#include "stdafx.h"
#include "ConnectionInfo.h"

IMPLEMENT_SERIAL(CConnectionInfo, CObject, 0);

// CConnectionInfo

CConnectionInfo::CConnectionInfo()
{
}

CConnectionInfo::~CConnectionInfo()
{
}


// CConnectionInfo member functions

void CConnectionInfo::Serialize(CArchive &ar)
{
	CObject::Serialize(ar);

	if (ar.IsStoring())
	{
		ar << DBName << UserName << Password;
	}
	else
	{
		ar >> DBName >> UserName >> Password;
	}
}
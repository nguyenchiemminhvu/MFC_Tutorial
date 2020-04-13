// WC_TestTable.cpp : implementation file
//

#include "stdafx.h"
#include "WC_TestTable.h"

#include <oracl.h>

IMPLEMENT_DYNAMIC(WC_TestTable, CDialog)

WC_TestTable::WC_TestTable(CWnd* pParent /*=NULL*/)
	: CDialog(WC_TestTable::IDD, pParent)
	, m_selectedDept(_T(""))
{

}

WC_TestTable::~WC_TestTable()
{
}

void WC_TestTable::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_DEPT, m_comboDept);
	DDX_CBString(pDX, IDC_COMBO_DEPT, m_selectedDept);
}


BEGIN_MESSAGE_MAP(WC_TestTable, CDialog)
	ON_CBN_SELCHANGE(IDC_COMBO_DEPT, &WC_TestTable::OnCbnSelchangeComboDept)
END_MESSAGE_MAP()


// WC_TestTable message handlers

BOOL WC_TestTable::OnInitDialog()
{
	if (!CDialog::OnInitDialog())
		return FALSE;

	extern char * DB_NAME;
	extern char * USER_NAME;
	extern char * PASS_WORD;

	ODatabase db(DB_NAME, USER_NAME, PASS_WORD);
	if (!db.IsOpen())
	{
		AfxMessageBox(L"Can not open database");
		return FALSE;
	}

	ODynaset listDept(db, "select * from DEPARTMENTS");
	OField fName = listDept.GetField("DEPARTMENT_NAME");
	while (!listDept.IsEOF())
	{
		OValue name;
		fName.GetValue(&name);

		WCHAR wName[50];
		mbstowcs(wName, name, 50);
		m_comboDept.AddString(wName);

		listDept.MoveNext();
	}

	db.Close();

	return TRUE;
}

void WC_TestTable::OnCbnSelchangeComboDept()
{
	m_comboDept.GetLBText(m_comboDept.GetCurSel(), m_selectedDept);

	// Load employee's info of selected department into table

}

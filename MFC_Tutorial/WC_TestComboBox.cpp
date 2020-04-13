// WC_TestComboBox.cpp : implementation file
//

#include "stdafx.h"
#include "WC_TestComboBox.h"

#include "oracl.h"

#include <string>
#include <fstream>

IMPLEMENT_DYNAMIC(WC_TestComboBox, CDialog)

WC_TestComboBox::WC_TestComboBox(CWnd* pParent /*=NULL*/)
	: CDialog(WC_TestComboBox::IDD, pParent)
{

}

WC_TestComboBox::~WC_TestComboBox()
{
}

void WC_TestComboBox::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_EMP, m_listEMP);
	DDX_Control(pDX, IDC_COMBO_IMAGES, m_comboDept);
}


BEGIN_MESSAGE_MAP(WC_TestComboBox, CDialog)
	ON_CBN_SELCHANGE(IDC_COMBO_DEPT, &WC_TestComboBox::OnCbnSelchangeComboDept)
END_MESSAGE_MAP()


// WC_TestComboBox message handlers

BOOL WC_TestComboBox::OnInitDialog()
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

void WC_TestComboBox::OnCbnSelchangeComboDept()
{
	m_listEMP.ResetContent();
	CString wDeptName;
	m_comboDept.GetLBText(m_comboDept.GetCurSel(), wDeptName);

	extern char * DB_NAME;
	extern char * USER_NAME;
	extern char * PASS_WORD;

	ODatabase db(DB_NAME, USER_NAME, PASS_WORD);
	if (!db.IsOpen())
	{
		AfxMessageBox(L"Can not open database");
		return;
	}

	char sql[255];

	CString DeptIDQuery = "select * from DEPARTMENTS where DEPARTMENT_NAME = ";
	DeptIDQuery.Append(L"'");
	DeptIDQuery.Append(wDeptName);
	DeptIDQuery.Append(L"'");
	wcstombs(sql, DeptIDQuery, 255);

	ODynaset deptID(db, sql);
	OValue DeptIDValue;
	deptID.GetField("DEPARTMENT_ID").GetValue(&DeptIDValue);
	
	sprintf(sql, "%s %d", "select * from EMPLOYEES where DEPARTMENT_ID = ", (int)DeptIDValue);
	ODynaset emps(db, sql);
	OField empID = emps.GetField("EMPLOYEE_ID");
	OField empName = emps.GetField("LAST_NAME");
	OField empSal = emps.GetField("SALARY");
	while (!emps.IsEOF())
	{
		OValue id, name, sal;
		empID.GetValue(&id);
		empName.GetValue(&name);
		empSal.GetValue(&sal);

		char line[255];
		sprintf(line, "%d, %s, %d", (int)id, (const char *)name, (int)sal);
		WCHAR emp[255];
		mbstowcs(emp, line, 255);
		m_listEMP.AddString(emp);

		emps.MoveNext();
	}
}

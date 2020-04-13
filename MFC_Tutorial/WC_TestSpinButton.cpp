// WC_TestSpinButton.cpp : implementation file
//

#include "stdafx.h"
#include "WC_TestSpinButton.h"

#include <oracl.h>

IMPLEMENT_DYNAMIC(WC_TestSpinButton, CDialog)

WC_TestSpinButton::WC_TestSpinButton(CWnd* pParent /*=NULL*/)
	: CDialog(WC_TestSpinButton::IDD, pParent)
	, m_selectedDept(_T(""))
	, m_selectedDeptID(-1)
{

}

WC_TestSpinButton::~WC_TestSpinButton()
{
}

void WC_TestSpinButton::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_DEPT, m_comboDept);
	DDX_CBString(pDX, IDC_COMBO_DEPT, m_selectedDept);
	DDX_Control(pDX, IDC_EDIT_BONUS, m_editBonus);
}


BEGIN_MESSAGE_MAP(WC_TestSpinButton, CDialog)
	ON_BN_CLICKED(IDOK, &WC_TestSpinButton::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &WC_TestSpinButton::OnBnClickedCancel)

	ON_CBN_SELCHANGE(IDC_COMBO_DEPT, &WC_TestSpinButton::OnCbnSelchangeComboDept)

	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_BONUS, &WC_TestSpinButton::OnDeltaposSpinBonus)
END_MESSAGE_MAP()


// WC_TestSpinButton message handlers
BOOL WC_TestSpinButton::OnInitDialog()
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

	m_editBonus.SetWindowText(L"0");

	return TRUE;
}

void WC_TestSpinButton::OnBnClickedOk()
{
	CString wBonus;
	m_editBonus.GetWindowText(wBonus);

	int iBonus = 0;
	for (int i = 0; i < wBonus.GetLength(); i++)
	{
		iBonus = iBonus * 10 + wBonus[i] - '0';
	}

	extern char * DB_NAME;
	extern char * USER_NAME;
	extern char * PASS_WORD;

	ODatabase db(DB_NAME, USER_NAME, PASS_WORD);
	if (!db.IsOpen())
	{
		AfxMessageBox(L"Can not open database");
		return;
	}

	db.GetSession().BeginTransaction();

	db.GetParameters().Add("amount", iBonus, OPARAMETER_INVAR, OTYPE_NUMBER);
	db.GetParameters().Add("dept", m_selectedDeptID, OPARAMETER_INVAR, OTYPE_NUMBER);

	oresult res = db.ExecuteSQL("begin HR_PACKAGE_1.send_bonus_dept(:amount, :dept); end;");
	if (res != OSUCCESS)
	{
		db.GetSession().Rollback();
		return;
	}
	
	db.GetSession().Commit();

	db.GetParameters().Remove("amount");
	db.GetParameters().Remove("dept");

	OnOK();
}

void WC_TestSpinButton::OnBnClickedCancel()
{
	OnCancel();
}

void WC_TestSpinButton::OnCbnSelchangeComboDept()
{
	m_comboDept.GetLBText(m_comboDept.GetCurSel(), m_selectedDept);
	
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

	char deptName[30];
	wcstombs(deptName, m_selectedDept, 30);

	sprintf(sql, "select * from DEPARTMENTS where DEPARTMENT_NAME = '%s'", deptName);

	ODynaset deptID(db, sql);
	OField fID = deptID.GetField("DEPARTMENT_ID");
	
	OValue vID;
	fID.GetValue(&vID);
	m_selectedDeptID = (int)vID;

	db.Close();
}

void WC_TestSpinButton::OnDeltaposSpinBonus(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	
	WCHAR res[255];
	swprintf(res, L"%d", pNMUpDown->iPos * 100);
	m_editBonus.SetWindowText(res);

	*pResult = 0;
}

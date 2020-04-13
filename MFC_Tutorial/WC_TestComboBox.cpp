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
	, m_selectedFileName(_T(""))
{

}

WC_TestComboBox::~WC_TestComboBox()
{
}

void WC_TestComboBox::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_IMAGES, m_comboBoxImages);
	DDX_CBString(pDX, IDC_COMBO_IMAGES, m_selectedFileName);
}


BEGIN_MESSAGE_MAP(WC_TestComboBox, CDialog)
	ON_CBN_SELCHANGE(IDC_COMBO_IMAGES, &WC_TestComboBox::OnCbnSelchangeComboImages)
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

	ODynaset listImages(db, "select * from IMAGES");
	OField image_name = listImages.GetField("IMAGE_NAME");
	OField image_data = listImages.GetField("IMAGE_DATA");
	while (!listImages.IsEOF())
	{
		OValue name, data;
		image_name.GetValue(&name);
		image_data.GetValue(&data);

		std::string file_name = ".\\DOWNLOADS\\"; file_name += (const char *)name;
		OBlob bo = (OBlob)data;

		bo.CopyToFile(file_name.c_str(), bo.GetSize(), bo.GetOptimumChunkSize());

		WCHAR w_file_name[30];
		mbstowcs(w_file_name, (const char *)name, 30);
		m_comboBoxImages.AddString(w_file_name);

		listImages.MoveNext();
	}

	db.Close();

	return TRUE;
}

void WC_TestComboBox::OnCbnSelchangeComboImages()
{
	m_comboBoxImages.GetLBText(m_comboBoxImages.GetCurSel(), m_selectedFileName);

	// load selected image into picture control

}

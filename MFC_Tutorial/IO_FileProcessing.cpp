// IO_FileProcessing.cpp : implementation file
//

#include "stdafx.h"
#include "IO_FileProcessing.h"


IMPLEMENT_DYNAMIC(IO_FileProcessing, CDialog)

IO_FileProcessing::IO_FileProcessing(CWnd* pParent /*=NULL*/)
	: CDialog(IO_FileProcessing::IDD, pParent)
{

}

IO_FileProcessing::~IO_FileProcessing()
{
}

void IO_FileProcessing::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_CONTENT, m_editContent);
}


BEGIN_MESSAGE_MAP(IO_FileProcessing, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_FILE_OPEN, &IO_FileProcessing::OnBnClickedButtonFileOpen)
	ON_BN_CLICKED(IDC_BUTTON_FILE_SAVE, &IO_FileProcessing::OnBnClickedButtonFileSave)
END_MESSAGE_MAP()


// IO_FileProcessing message handlers

BOOL IO_FileProcessing::OnInitDialog()
{
	if (!CDialog::OnInitDialog())
		return FALSE;

	
	return TRUE;
}

void IO_FileProcessing::OnBnClickedButtonFileOpen()
{
	CString path;

	WCHAR filter[] = L"TXT Files (*.txt)|*.txt|All Files (*.*)|*.*||";
	CFileDialog dlg(TRUE, L"txt", 0, OFN_READONLY, filter, this);
	if (dlg.DoModal() == IDOK)
	{
		path = dlg.GetPathName();

		// Read content from file
		CStdioFile file(path, CFile::modeRead | CFile::typeText);
		ULONGLONG fileLength = file.GetLength();

		m_editContent.Clear();
		CString content;

		CString line;
		while (file.ReadString(line))
		{
			content.Append(line);
			content.Append(L"\n");
		}

		m_editContent.SetWindowText(content);

		file.Close();
	}
}

void IO_FileProcessing::OnBnClickedButtonFileSave()
{
	CString path;

	WCHAR filter[] = L"TXT Files (*.txt)|*.txt|All Files (*.*)|*.*||";
	CFileDialog dlg(FALSE, L"txt", 0, OFN_OVERWRITEPROMPT, filter, this);
	if (dlg.DoModal() == IDOK)
	{
		path = dlg.GetPathName();

		// Write to file
		WCHAR *content = new WCHAR[m_editContent.GetWindowTextLength()];
		m_editContent.GetWindowText(content, m_editContent.GetWindowTextLength());

		CStdioFile file(path, CFile::modeCreate | CFile::modeWrite | CFile::typeText);
		file.WriteString(content);

		file.Close();
	}
}

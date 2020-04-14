#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Runtime::InteropServices;

#include "oracl.h"


namespace MFC_Tutorial 
{
	/// <summary>
	/// Summary for WC_TestTableCLR
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class WC_TestTableCLR : public System::Windows::Forms::Form
	{
	private:
		System::Windows::Forms::ComboBox^  ComboDept;
		System::Windows::Forms::DataGridView^  Grid_EMP;

	public:
		WC_TestTableCLR(void)
		{
			InitializeComponent();
			
			extern char * DB_NAME;
			extern char * USER_NAME;
			extern char * PASS_WORD;

			ODatabase db(DB_NAME, USER_NAME, PASS_WORD);
			if (!db.IsOpen())
			{
				AfxMessageBox(L"Can not open database");
				return;
			}

			ODynaset listDept(db, "select * from DEPARTMENTS");
			OField fName = listDept.GetField("DEPARTMENT_NAME");
			while (!listDept.IsEOF())
			{
				OValue name;
				fName.GetValue(&name);
				this->ComboDept->Items->Add(gcnew String((const char *)name));

				listDept.MoveNext();
			}

			db.Close();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~WC_TestTableCLR()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->ComboDept = (gcnew System::Windows::Forms::ComboBox());
			this->Grid_EMP = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Grid_EMP))->BeginInit();
			this->SuspendLayout();
			// 
			// ComboDept
			// 
			this->ComboDept->FormattingEnabled = true;
			this->ComboDept->Location = System::Drawing::Point(13, 13);
			this->ComboDept->Name = L"ComboDept";
			this->ComboDept->Size = System::Drawing::Size(121, 21);
			this->ComboDept->TabIndex = 0;
			this->ComboDept->SelectedIndexChanged += gcnew System::EventHandler(this, &WC_TestTableCLR::ComboDept_SelectedIndexChanged);
			// 
			// Grid_EMP
			// 
			this->Grid_EMP->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Grid_EMP->Location = System::Drawing::Point(140, 12);
			this->Grid_EMP->Name = L"Grid_EMP";
			this->Grid_EMP->Size = System::Drawing::Size(359, 276);
			this->Grid_EMP->TabIndex = 1;
			// 
			// WC_TestTableCLR
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(511, 300);
			this->Controls->Add(this->Grid_EMP);
			this->Controls->Add(this->ComboDept);
			this->Name = L"WC_TestTableCLR";
			this->Text = L"Test Table CLR";
			this->Load += gcnew System::EventHandler(this, &WC_TestTableCLR::WC_TestTableCLR_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->Grid_EMP))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: 
		System::Void WC_TestTableCLR_Load(System::Object^  sender, System::EventArgs^  e) 
		{

		}

		System::Void ComboDept_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
		{
			String ^selectedDept = (String^)this->ComboDept->Items[((System::Windows::Forms::ComboBox^)sender)->SelectedIndex];
			
			IntPtr pDept = Marshal::StringToHGlobalAnsi(selectedDept);
			char * dept = (char *)pDept.ToPointer();

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

			sprintf(sql, "%s '%s'", "select * from DEPARTMENTS where DEPARTMENT_NAME = ", dept);
			ODynaset deptID(db, sql);
			int dID;
			deptID.GetField("DEPARTMENT_ID").GetValue(&dID);

			DataTable ^ tableEMP = gcnew DataTable();
			tableEMP->Columns->Add(gcnew String("ID"));
			tableEMP->Columns->Add(gcnew String("NAME"));
			tableEMP->Columns->Add(gcnew String("SALARY"));

			sprintf(sql, "%s %d", "select * from EMPLOYEES where DEPARTMENT_ID = ", dID);
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
				sprintf(line, "%d %s %d", (int)id, (const char *)name, (int)sal);
				WCHAR res[255];
				mbstowcs(res, line, 255);

				DataRow ^row = tableEMP->NewRow();
				row["ID"] = (int)id;
				row["NAME"] = gcnew String((const char *)name);
				row["SALARY"] = (int)sal;
				tableEMP->Rows->Add(row);

				emps.MoveNext();
			}

			this->Grid_EMP->DataSource = tableEMP;

			Marshal::FreeHGlobal(pDept);
		}
	};
}

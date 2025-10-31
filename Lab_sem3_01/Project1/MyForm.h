#pragma once

namespace Lab_sem3_01 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ enterNBox;
	private: System::Windows::Forms::TextBox^ enterMBox;
	private: System::Windows::Forms::Button^ createMatrixBtn;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::DataGridView^ matrixView;
	private: System::Windows::Forms::Button^ calcBtn;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;




	protected:

	protected:

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->enterNBox = (gcnew System::Windows::Forms::TextBox());
			this->enterMBox = (gcnew System::Windows::Forms::TextBox());
			this->createMatrixBtn = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->matrixView = (gcnew System::Windows::Forms::DataGridView());
			this->calcBtn = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->matrixView))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(30, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(735, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"��� ��������� ������ N*M. ����� ��� ���������� �������";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(35, 80);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(79, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"������� N:";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(35, 106);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(80, 16);
			this->label3->TabIndex = 1;
			this->label3->Text = L"������� M:";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// enterNBox
			// 
			this->enterNBox->Location = System::Drawing::Point(121, 75);
			this->enterNBox->Name = L"enterNBox";
			this->enterNBox->Size = System::Drawing::Size(100, 20);
			this->enterNBox->TabIndex = 2;
			// 
			// enterMBox
			// 
			this->enterMBox->Location = System::Drawing::Point(121, 106);
			this->enterMBox->Name = L"enterMBox";
			this->enterMBox->Size = System::Drawing::Size(100, 20);
			this->enterMBox->TabIndex = 2;
			// 
			// createMatrixBtn
			// 
			this->createMatrixBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->createMatrixBtn->Location = System::Drawing::Point(228, 75);
			this->createMatrixBtn->Name = L"createMatrixBtn";
			this->createMatrixBtn->Size = System::Drawing::Size(115, 51);
			this->createMatrixBtn->TabIndex = 3;
			this->createMatrixBtn->Text = L"������� �����";
			this->createMatrixBtn->UseVisualStyleBackColor = true;
			this->createMatrixBtn->Click += gcnew System::EventHandler(this, &MyForm::createMatrixBtn_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(35, 152);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(116, 16);
			this->label4->TabIndex = 1;
			this->label4->Text = L"������� ������:";
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// matrixView
			// 
			this->matrixView->AllowUserToAddRows = false;
			this->matrixView->AllowUserToDeleteRows = false;
			this->matrixView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->matrixView->Location = System::Drawing::Point(34, 172);
			this->matrixView->Name = L"matrixView";
			this->matrixView->Size = System::Drawing::Size(533, 480);
			this->matrixView->TabIndex = 4;
			// 
			// calcBtn
			// 
			this->calcBtn->Enabled = false;
			this->calcBtn->Location = System::Drawing::Point(574, 466);
			this->calcBtn->Name = L"calcBtn";
			this->calcBtn->Size = System::Drawing::Size(344, 62);
			this->calcBtn->TabIndex = 5;
			this->calcBtn->Text = L"����������";
			this->calcBtn->UseVisualStyleBackColor = true;
			this->calcBtn->Click += gcnew System::EventHandler(this, &MyForm::calcBtn_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(574, 554);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(108, 24);
			this->label5->TabIndex = 6;
			this->label5->Text = L"���������:";
			this->label5->Visible = false;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(688, 554);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(24, 24);
			this->label6->TabIndex = 6;
			this->label6->Text = L"X";
			this->label6->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(930, 686);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->calcBtn);
			this->Controls->Add(this->matrixView);
			this->Controls->Add(this->createMatrixBtn);
			this->Controls->Add(this->enterMBox);
			this->Controls->Add(this->enterNBox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->matrixView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void createMatrixBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		int n, m;
		if (!Int32::TryParse(enterNBox->Text, n) || !Int32::TryParse(enterMBox->Text, m)) {
			MessageBox::Show("����������, ������� ���������� ����� ��� N � M", "������",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (n <= 0 || m <= 0) {
			MessageBox::Show("N � M ������ ���� �������������� �������", "������",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		matrixView->Columns->Clear();
		matrixView->Rows->Clear();

		for (int j = 0; j < m; j++) {
			matrixView->Columns->Add(gcnew DataGridViewTextBoxColumn());
		}

		matrixView->Rows->Add(n);

		calcBtn->Enabled = true;
	}

private: System::Void calcBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	int positiveCount = 0;
	bool found = false;

	for (int i = 0; i < matrixView->Rows->Count; i++) {
		for (int j = 0; j < matrixView->Columns->Count; j++) {
			if (matrixView->Rows[i]->Cells[j]->Value == nullptr ||
				String::IsNullOrWhiteSpace(matrixView->Rows[i]->Cells[j]->Value->ToString())) {
				MessageBox::Show("����������, ������� ���������� ����� � ������", "������",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
		}
	}

	for (int j1 = 0; j1 < matrixView->Columns->Count; j1++) {
		for (int j2 = j1 + 1; j2 < matrixView->Columns->Count; j2++) {
			bool isSame = true;

			for (int i = 0; i < matrixView->Rows->Count; i++) {
				String^ val1 = matrixView->Rows[i]->Cells[j1]->Value->ToString();
				String^ val2 = matrixView->Rows[i]->Cells[j2]->Value->ToString();

				if (val1 != val2) {
					isSame = false;
					break;
				}
			}

			if (isSame) {
				label6->Text = (j1 + 1) + " � " + (j2 + 1);
				found = true;
				break;
			}
		}
		if (found) {
			break;
		}
	}
	
	if (!found) {
		label6->Text = "�� �������";
	}
	label5->Visible = true;
	label6->Visible = true;
}
};
}

#pragma once

#include "Elevator.h"
#include "Logger.h"

namespace Elevator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:

		Elevator^ elevator;

		MainForm(void)
		{
			InitializeComponent();
			
			buttonPanelDataGridView->RowCount = 10;
			for (int i = 0; i < buttonPanelDataGridView->RowCount; ++i)
			{
				buttonPanelDataGridView->Rows[i]->Cells[0]->Value = i.ToString();
			}

			elevator = gcnew Elevator();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::TextBox^  logTextBox;
	private: System::Windows::Forms::DataGridView^  buttonPanelDataGridView;
	public: 
	protected: 


	private: System::Windows::Forms::DataGridViewTextBoxColumn^  LevelNumbers;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  Levels;

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
			this->logTextBox = (gcnew System::Windows::Forms::TextBox());
			this->buttonPanelDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->LevelNumbers = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Levels = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->buttonPanelDataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// logTextBox
			// 
			this->logTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->logTextBox->BackColor = System::Drawing::Color::White;
			this->logTextBox->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->logTextBox->Location = System::Drawing::Point(2, 3);
			this->logTextBox->Multiline = true;
			this->logTextBox->Name = L"logTextBox";
			this->logTextBox->ReadOnly = true;
			this->logTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->logTextBox->Size = System::Drawing::Size(432, 347);
			this->logTextBox->TabIndex = 0;
			this->logTextBox->WordWrap = false;
			// 
			// buttonPanelDataGridView
			// 
			this->buttonPanelDataGridView->AllowUserToAddRows = false;
			this->buttonPanelDataGridView->AllowUserToDeleteRows = false;
			this->buttonPanelDataGridView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttonPanelDataGridView->BackgroundColor = System::Drawing::SystemColors::ActiveCaption;
			this->buttonPanelDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->buttonPanelDataGridView->ColumnHeadersVisible = false;
			this->buttonPanelDataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {this->LevelNumbers, 
				this->Levels});
			this->buttonPanelDataGridView->Location = System::Drawing::Point(440, 3);
			this->buttonPanelDataGridView->Name = L"buttonPanelDataGridView";
			this->buttonPanelDataGridView->ReadOnly = true;
			this->buttonPanelDataGridView->RowHeadersVisible = false;
			this->buttonPanelDataGridView->Size = System::Drawing::Size(77, 347);
			this->buttonPanelDataGridView->TabIndex = 1;
			this->buttonPanelDataGridView->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::Leveldata_CellClick);
			// 
			// LevelNumbers
			// 
			this->LevelNumbers->HeaderText = L"#";
			this->LevelNumbers->Name = L"LevelNumbers";
			this->LevelNumbers->ReadOnly = true;
			this->LevelNumbers->Width = 20;
			// 
			// Levels
			// 
			this->Levels->HeaderText = L"";
			this->Levels->Name = L"Levels";
			this->Levels->ReadOnly = true;
			this->Levels->Width = 20;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLight;
			this->ClientSize = System::Drawing::Size(517, 351);
			this->Controls->Add(this->buttonPanelDataGridView);
			this->Controls->Add(this->logTextBox);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Name = L"MainForm";
			this->Text = L"Elevator";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->buttonPanelDataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		System::Void Leveldata_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
		{
			elevator->onRequested(e->RowIndex);
		}
private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}


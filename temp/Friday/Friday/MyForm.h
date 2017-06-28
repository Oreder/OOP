#pragma once

namespace Friday {

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
	private: System::Windows::Forms::PictureBox^  view;
	protected:
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;
	private: System::Windows::Forms::Button^  openFileBtn;

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
			this->view = (gcnew System::Windows::Forms::PictureBox());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->openFileBtn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->view))->BeginInit();
			this->SuspendLayout();
			// 
			// view
			// 
			this->view->BackColor = System::Drawing::Color::White;
			this->view->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->view->Location = System::Drawing::Point(2, 3);
			this->view->Name = L"view";
			this->view->Size = System::Drawing::Size(496, 389);
			this->view->TabIndex = 0;
			this->view->TabStop = false;
			// 
			// openFileBtn
			// 
			this->openFileBtn->Location = System::Drawing::Point(522, 20);
			this->openFileBtn->Name = L"openFileBtn";
			this->openFileBtn->Size = System::Drawing::Size(91, 26);
			this->openFileBtn->TabIndex = 1;
			this->openFileBtn->Text = L"Open File";
			this->openFileBtn->UseVisualStyleBackColor = true;
			this->openFileBtn->Click += gcnew System::EventHandler(this, &MyForm::openFileBtn_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(657, 435);
			this->Controls->Add(this->openFileBtn);
			this->Controls->Add(this->view);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->view))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void openFileBtn_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	};
}

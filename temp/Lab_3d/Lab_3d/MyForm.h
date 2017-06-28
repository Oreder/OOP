#pragma once

namespace Lab_3d {

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
	private: System::Windows::Forms::PictureBox^  pictureBox;
	protected:
	private: System::Windows::Forms::Button^  fileloadBtn;

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
			this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->fileloadBtn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox
			// 
			this->pictureBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox->Location = System::Drawing::Point(1, 1);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(524, 423);
			this->pictureBox->TabIndex = 0;
			this->pictureBox->TabStop = false;
			this->pictureBox->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox_MouseDown);
			// 
			// fileloadBtn
			// 
			this->fileloadBtn->Location = System::Drawing::Point(568, 22);
			this->fileloadBtn->Name = L"fileloadBtn";
			this->fileloadBtn->Size = System::Drawing::Size(81, 30);
			this->fileloadBtn->TabIndex = 1;
			this->fileloadBtn->Text = L"Load file";
			this->fileloadBtn->UseVisualStyleBackColor = true;
			this->fileloadBtn->Click += gcnew System::EventHandler(this, &MyForm::fileloadBtn_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(775, 426);
			this->Controls->Add(this->fileloadBtn);
			this->Controls->Add(this->pictureBox);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		Point Mous;		// Mouse position

	private: System::Void fileloadBtn_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		
	}
	private: System::Void pictureBox_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
	{
		Mous.X = e->X;	// save current mouse position
		Mous.Y = e->Y;
	}



	};
}

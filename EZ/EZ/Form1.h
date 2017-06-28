#pragma once

#include "..\entry.h"

namespace EZ {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected: 
	private: System::Windows::Forms::Button^  btn_load;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Button^  btn_shift;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Button^  btn_scale;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::Button^  btn_rotate;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;

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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btn_load = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->btn_shift = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->btn_scale = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->btn_rotate = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::White;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(1, 1);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(565, 462);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// btn_load
			// 
			this->btn_load->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btn_load->Location = System::Drawing::Point(572, 3);
			this->btn_load->Name = L"btn_load";
			this->btn_load->Size = System::Drawing::Size(121, 35);
			this->btn_load->TabIndex = 31;
			this->btn_load->Text = L"Load from file";
			this->btn_load->UseVisualStyleBackColor = true;
			this->btn_load->Click += gcnew System::EventHandler(this, &Form1::btn_load_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label10);
			this->groupBox1->Controls->Add(this->btn_shift);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(572, 44);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(121, 137);
			this->groupBox1->TabIndex = 32;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"  Move   ";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(15, 75);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(25, 13);
			this->label10->TabIndex = 10;
			this->label10->Text = L"DZ:";
			// 
			// btn_shift
			// 
			this->btn_shift->BackColor = System::Drawing::SystemColors::Control;
			this->btn_shift->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btn_shift->Location = System::Drawing::Point(17, 100);
			this->btn_shift->Name = L"btn_shift";
			this->btn_shift->Size = System::Drawing::Size(93, 31);
			this->btn_shift->TabIndex = 2;
			this->btn_shift->Text = L"Move";
			this->btn_shift->UseVisualStyleBackColor = true;
			this->btn_shift->Click += gcnew System::EventHandler(this, &Form1::btn_shift_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(15, 24);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(25, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"DX:";
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(50, 72);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(60, 20);
			this->textBox3->TabIndex = 27;
			this->textBox3->Text = L"0,0";
			this->textBox3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox3_KeyPress);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(15, 50);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(25, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"DY:";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(50, 21);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(60, 20);
			this->textBox1->TabIndex = 8;
			this->textBox1->Text = L"0,0";
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox1_KeyPress);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(50, 47);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(60, 20);
			this->textBox2->TabIndex = 9;
			this->textBox2->Text = L"0,0";
			this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox2_KeyPress);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->textBox5);
			this->groupBox2->Controls->Add(this->btn_scale);
			this->groupBox2->Controls->Add(this->textBox4);
			this->groupBox2->Controls->Add(this->textBox6);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->groupBox2->Location = System::Drawing::Point(572, 187);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(121, 133);
			this->groupBox2->TabIndex = 33;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L" Resize  ";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(15, 75);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(24, 13);
			this->label1->TabIndex = 33;
			this->label1->Text = L"KZ:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(15, 24);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(24, 13);
			this->label6->TabIndex = 31;
			this->label6->Text = L"KX:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(15, 50);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(24, 13);
			this->label7->TabIndex = 32;
			this->label7->Text = L"KY:";
			// 
			// textBox5
			// 
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox5->Location = System::Drawing::Point(50, 47);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(60, 20);
			this->textBox5->TabIndex = 30;
			this->textBox5->Text = L"1,0";
			this->textBox5->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox5_KeyPress);
			// 
			// btn_scale
			// 
			this->btn_scale->BackColor = System::Drawing::SystemColors::Control;
			this->btn_scale->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btn_scale->Location = System::Drawing::Point(12, 98);
			this->btn_scale->Name = L"btn_scale";
			this->btn_scale->Size = System::Drawing::Size(98, 29);
			this->btn_scale->TabIndex = 3;
			this->btn_scale->Text = L"Resize";
			this->btn_scale->UseVisualStyleBackColor = true;
			this->btn_scale->Click += gcnew System::EventHandler(this, &Form1::btn_scale_Click);
			// 
			// textBox4
			// 
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox4->Location = System::Drawing::Point(50, 21);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(60, 20);
			this->textBox4->TabIndex = 29;
			this->textBox4->Text = L"1,0";
			this->textBox4->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox4_KeyPress);
			// 
			// textBox6
			// 
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox6->Location = System::Drawing::Point(50, 72);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(60, 20);
			this->textBox6->TabIndex = 18;
			this->textBox6->Text = L"1,0";
			this->textBox6->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox6_KeyPress);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->textBox9);
			this->groupBox3->Controls->Add(this->label5);
			this->groupBox3->Controls->Add(this->label4);
			this->groupBox3->Controls->Add(this->textBox8);
			this->groupBox3->Controls->Add(this->label11);
			this->groupBox3->Controls->Add(this->textBox7);
			this->groupBox3->Controls->Add(this->btn_rotate);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->groupBox3->Location = System::Drawing::Point(572, 326);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(121, 137);
			this->groupBox3->TabIndex = 34;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Rotation  ";
			// 
			// textBox9
			// 
			this->textBox9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox9->Location = System::Drawing::Point(50, 73);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(60, 20);
			this->textBox9->TabIndex = 29;
			this->textBox9->Text = L"0,0";
			this->textBox9->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox9_KeyPress);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(17, 76);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(23, 13);
			this->label5->TabIndex = 28;
			this->label5->Text = L"oZ:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(16, 50);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(23, 13);
			this->label4->TabIndex = 26;
			this->label4->Text = L"oY:";
			// 
			// textBox8
			// 
			this->textBox8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox8->Location = System::Drawing::Point(50, 47);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(60, 20);
			this->textBox8->TabIndex = 11;
			this->textBox8->Text = L"0,0";
			this->textBox8->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox8_KeyPress);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(17, 24);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(23, 13);
			this->label11->TabIndex = 23;
			this->label11->Text = L"oX:";
			// 
			// textBox7
			// 
			this->textBox7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->textBox7->Location = System::Drawing::Point(50, 21);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(60, 20);
			this->textBox7->TabIndex = 25;
			this->textBox7->Text = L"0,0";
			this->textBox7->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::textBox7_KeyPress);
			// 
			// btn_rotate
			// 
			this->btn_rotate->BackColor = System::Drawing::SystemColors::Control;
			this->btn_rotate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->btn_rotate->Location = System::Drawing::Point(12, 101);
			this->btn_rotate->Name = L"btn_rotate";
			this->btn_rotate->Size = System::Drawing::Size(98, 30);
			this->btn_rotate->TabIndex = 4;
			this->btn_rotate->Text = L"Rotate";
			this->btn_rotate->UseVisualStyleBackColor = true;
			this->btn_rotate->Click += gcnew System::EventHandler(this, &Form1::btn_rotate_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(697, 465);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->btn_load);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Form1";
			this->Text = L"Wire-frame model";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btn_shift_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 if (TestBoxes(SHIFT_ACT) != 1)
				 return;

				struct Entry_Data data;
				data.shift.dx = Convert::ToDouble(textBox1->Text);
				data.shift.dy = Convert::ToDouble(textBox2->Text);
				data.shift.dz = Convert::ToDouble(textBox3->Text);
				ACTION_RET res = Main_Function(&data, SHIFT_ACT);

				if (res == NO_DATA)
					MessageBox::Show("Data does not exist!", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Stop);
			 }
private: System::Void btn_scale_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (TestBoxes(SCALE_ACT) != 1)
				 return;

			 struct Entry_Data data;
			 data.scale.kx = Convert::ToDouble(textBox4->Text);
			 data.scale.ky = Convert::ToDouble(textBox5->Text);
			 data.scale.kz = Convert::ToDouble(textBox6->Text);
			 ACTION_RET res = Main_Function(&data, SCALE_ACT);

			 if (res == NO_DATA)
				 MessageBox::Show("Data does not exist!", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Stop);
		 }
private: System::Void btn_rotate_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (TestBoxes(ROTATE_ACT) != 1)
				 return;

			 struct Entry_Data data;
			 data.rotate.ox = Convert::ToDouble(textBox7->Text);
			 data.rotate.oy = Convert::ToDouble(textBox8->Text);
			 data.rotate.oz = Convert::ToDouble(textBox9->Text);
			 ACTION_RET res = Main_Function(&data, ROTATE_ACT);

			 if (res == NO_DATA)
				 MessageBox::Show("Data does not exist!", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Stop);
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
		 {
			 struct Entry_Data data;
			 struct Canvas_Itself pb;
			 pb.picture_box = pictureBox1;
			 data.canvas = &pb;
			 Main_Function(&data, INIT_ACT);
		 }
private: System::Void btn_load_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if (openFileDialog1->ShowDialog() != System::Windows::Forms::DialogResult::OK)
				 return;

			 struct Entry_Data data;
			 char* name = (char*)(void*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(openFileDialog1->FileName);
			 data.filename = name;
			 ACTION_RET res = Main_Function(&data, LOAD_ACT);
			 
			 switch (res)
			 {
				 case FILE_NOT_OPEN:
					 MessageBox::Show("Can not open file!", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Stop);
				 break;

				 case FATAL_ERROR:
					 MessageBox::Show("Error in allocating memory!", "Error", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Error);
					 break;

				 case EMPTY_FILE:
					 MessageBox::Show("File is empty!", "Exclamation", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Exclamation);
					 break;

				 case WRONG_DATA:
					 MessageBox::Show("Given data has something wrong!", "Warning", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Exclamation);
					 break;
			 }
		 }
private: System::Void textBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) { KeyPress(sender, e, textBox1); }
private: System::Void textBox2_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) { KeyPress(sender, e, textBox2); }
private: System::Void textBox3_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) { KeyPress(sender, e, textBox3); }
private: System::Void textBox4_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) { KeyPress(sender, e, textBox4); }
private: System::Void textBox5_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) { KeyPress(sender, e, textBox5); }
private: System::Void textBox6_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) { KeyPress(sender, e, textBox6); }
private: System::Void textBox7_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) { KeyPress(sender, e, textBox7); }
private: System::Void textBox8_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) { KeyPress(sender, e, textBox8); }
private: System::Void textBox9_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) { KeyPress(sender, e, textBox9); }

private: System::Void KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e, TextBox^ tb) 
		 {
            if (e->KeyChar == '-' && (tb->Text->ToString()->Length == 0 || tb->Text->IndexOf('-') == -1))
            {
                return;
            }
            if ((e->KeyChar >= '0') && (e->KeyChar <= '9'))
                return;

            if (e->KeyChar == '.')
            {
                // point is replaced by comma
                e->KeyChar = ',';
            }
            if (e->KeyChar == ',')
            {
                if (tb->Text->IndexOf(',') != -1)
                {
                    // comma sign is now existed
                    e->Handled = true;
                }
                return;
            }

            if (Char::IsControl(e->KeyChar))
                return;

            e->Handled = true;
		 }

private: int TestBoxes(Selected_Action reg) 
		 {
            String^ s1 = textBox1->Text->ToString();
            String^ s2 = textBox2->Text->ToString();
            String^ s3 = textBox3->Text->ToString();
            String^ s4 = textBox4->Text->ToString();
            String^ s5 = textBox5->Text->ToString();
            String^ s6 = textBox6->Text->ToString();
            String^ s7 = textBox7->Text->ToString();
            String^ s8 = textBox8->Text->ToString();
            String^ s9 = textBox9->Text->ToString();

            switch (reg)
            {
                case SHIFT_ACT:
                    if (s1 != "" && s2 != "" && s3 != "")
                        return 1;
                    break;

                case SCALE_ACT:
                    if (s4 != "" && s5 != "" && s6 != "")
                        return 1;
                    break;

                case ROTATE_ACT:
                    if (s7 != "" && s8 != "" && s9 != "")
                        return 1;
                    break;
            }

			MessageBox::Show("Please input in all the given boxes!", "Warning", Windows::Forms::MessageBoxButtons::OK, Windows::Forms::MessageBoxIcon::Stop);
            return 0;
		 }
private: System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) 
		 {
			 struct Entry_Data data;
			 Main_Function(&data, CLOSE_ACT);
		 }
};
}


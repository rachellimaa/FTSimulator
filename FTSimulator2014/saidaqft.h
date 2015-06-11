#pragma once
#include <string.h>
#include"qft.h"

namespace FTSimulator2014 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for saidaqft
	/// </summary>
	public ref class saidaqft : public System::Windows::Forms::Form
	{
	public:
		saidaqft(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}


	public:
		saidaqft(String^ myFile, String^ myPath)
		{
			file = myFile;
			path = myPath;
			InitializeComponent();
			//
			//TODO: Adicione o código do construtor aqui
			//
		}

	public:saidaqft(System::Windows::Forms::Form ^ frm1, String^ myFile, String^ myPath)
	{
		otherform = frm1;
		InitializeComponent();
		file = myFile;
		path = myPath;

	}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~saidaqft()
		{
			if (components)
			{
				delete components;
			}
		}


	private: String^ path;
	private: String^ file;
	private: System::Windows::Forms::Button^  button4;
	protected:
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::LinkLabel^  linkLabel2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::LinkLabel^  linkLabel1;
	private: System::Windows::Forms::TextBox^  textBox1;

	
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(saidaqft::typeid));
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->linkLabel2 = (gcnew System::Windows::Forms::LinkLabel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.Image")));
			this->button4->Location = System::Drawing::Point(21, 10);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(29, 33);
			this->button4->TabIndex = 60;
			this->button4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &saidaqft::button4_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(253, 144);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(256, 134);
			this->listBox1->TabIndex = 56;
			// 
			// linkLabel2
			// 
			this->linkLabel2->AutoSize = true;
			this->linkLabel2->Location = System::Drawing::Point(124, 187);
			this->linkLabel2->Name = L"linkLabel2";
			this->linkLabel2->Size = System::Drawing::Size(69, 13);
			this->linkLabel2->TabIndex = 55;
			this->linkLabel2->TabStop = true;
			this->linkLabel2->Text = L"output_qft.txt";
			this->linkLabel2->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &saidaqft::linkLabel2_LinkClicked);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(336, 103);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(114, 20);
			this->label3->TabIndex = 54;
			this->label3->Text = L"QFT - Output";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(168, 41);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(487, 17);
			this->label2->TabIndex = 53;
			this->label2->Text = L"FTSimulator is an open-source tool for Classical and Quantum Fourier Transforms.";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(291, 332);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(147, 13);
			this->label1->TabIndex = 52;
			this->label1->Text = L"Visit our project homepage at:";
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Location = System::Drawing::Point(308, 364);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(119, 13);
			this->linkLabel1->TabIndex = 51;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"https://goo.gl/UA5C8R";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(294, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(182, 36);
			this->textBox1->TabIndex = 49;
			this->textBox1->TabStop = false;
			this->textBox1->Text = L"FTSimulator";
			// 
			// saidaqft
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->ClientSize = System::Drawing::Size(701, 386);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->linkLabel2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->textBox1);
			this->Name = L"saidaqft";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FTSimulator";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	

		  private: System::Windows::Forms::Form ^ otherform;
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();
	otherform->Show();
}
private: System::Void linkLabel2_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
	listBox1->Items->Clear();

	try
	{
		String^ textFile = String::Concat(path, ("\\output\\output_qft.txt"));
		StreamReader ^reader = gcnew  System::IO::StreamReader(textFile);
		MessageBox::Show("Operation was Successful");



		do
		{
			listBox1->Items->Add(reader->ReadLine());
		} while (reader->Peek() != -1);
		reader->Close();
	}
	catch (FileNotFoundException ^ex)
	{
		listBox1->Items->Add(ex);
	}

	catch (System::Exception ^e)
	{
		listBox1->Items->Add(e);
	}
}
};
}

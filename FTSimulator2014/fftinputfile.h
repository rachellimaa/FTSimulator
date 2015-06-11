#include "fft.h"
#include <string.h>
#include "pag5.h"
#include <algorithm>


#pragma once

namespace FTSimulator2014 {

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;
	using namespace System::IO;



	/// <summary>
	/// Summary for fftinputfile
	/// </summary>
	public ref class fftinputfile : public System::Windows::Forms::Form
	{
	public:
		fftinputfile()
		{
			
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~fftinputfile()
		{
			if (components)
			{
				delete components;
			}
		}
		
//  construtor
 
public:fftinputfile(System::Windows::Forms::Form ^ frm1)
	{
		otherform = frm1;
		InitializeComponent();

	}

	

	private: System::Windows::Forms::Button^  button2;
	private: String^ temp;
	private: String^ path;
	public: String^ openFileDialog1;
	public: String^ listBox1_SelectedIndexChanged;

	protected:

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::LinkLabel^  linkLabel1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Button^  button4;


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(fftinputfile::typeid));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(449, 159);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(89, 56);
			this->button2->TabIndex = 43;
			this->button2->Text = L"Browse Files";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &fftinputfile::button2_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(70, 176);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(87, 20);
			this->label4->TabIndex = 41;
			this->label4->Text = L"Input Files:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(215, 94);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(193, 20);
			this->label3->TabIndex = 40;
			this->label3->Text = L"Fast Fourier Transform";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(80, 43);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(487, 17);
			this->label2->TabIndex = 39;
			this->label2->Text = L"FTSimulator is an open-source tool for Classical and Quantum Fourier Transforms.";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(238, 311);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(147, 13);
			this->label1->TabIndex = 38;
			this->label1->Text = L"Visit our project homepage at:";
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Location = System::Drawing::Point(252, 336);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(119, 13);
			this->linkLabel1->TabIndex = 37;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"https://goo.gl/UA5C8R";
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &fftinputfile::linkLabel1_LinkClicked);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(518, 253);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 32);
			this->button1->TabIndex = 36;
			this->button1->Text = L" > Proceed";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &fftinputfile::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->CausesValidation = false;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(241, 4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(182, 36);
			this->textBox1->TabIndex = 35;
			this->textBox1->TabStop = false;
			this->textBox1->Text = L"FTSimulator";
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(176, 174);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(247, 30);
			this->listBox1->TabIndex = 44;
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.Image")));
			this->button4->Location = System::Drawing::Point(21, 12);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(29, 33);
			this->button4->TabIndex = 46;
			this->button4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &fftinputfile::button4_Click);
			// 
			// fftinputfile
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->ClientSize = System::Drawing::Size(697, 358);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"fftinputfile";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FTSimulator";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void MarshalString(String ^ s, string& os) {
		using namespace Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}


	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

		using namespace Runtime::InteropServices;
		OpenFileDialog^ openFileDialog1 = gcnew System::Windows::Forms::OpenFileDialog();
		openFileDialog1->ShowDialog();
		temp = openFileDialog1->FileName;
		path = System::IO::Path::GetDirectoryName(openFileDialog1->FileName);
		this->listBox1->Items->Add(temp);

	

	}
			

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (temp != nullptr){

			// transformação do nome do arquivo
			string stringTransformed = "a";
			MarshalString(temp, stringTransformed);

			// transformação do caminho do arquivo
			string pathTransformed = "a";
			MarshalString(path, pathTransformed);

			String^ textFile = String::Concat(path, ("..\\output"));
			System::IO::Directory::CreateDirectory(textFile);
			
			
			bool b = CFFT::fftFromFile(stringTransformed, pathTransformed);
			if (!b){
			
				
				
				MessageBox::Show("Results in the folder output!");
				
				// Abrir próxima tela
				pag5 ^ form = gcnew pag5(this, temp, path);
				this->Visible = false;
				form->ShowDialog();
			}

			else {
				MessageBox::Show("Invalid file type");
			
				// Recomeçar da tela inicial
			}
		}
		else
		{
			MessageBox::Show("Choose at least one file");
		}

		}

	


	

			 private: System::Windows::Forms::Form ^ otherform;


	
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();
	otherform->Show();
}

private: System::Void linkLabel1_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
	System::Diagnostics::Process::Start("https://goo.gl/UA5C8R");
}
};
};


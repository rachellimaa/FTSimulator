#pragma once
#include "fft.h"
#include <string.h>

namespace FTSimulator2014 {

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for SaidaPreDefined
	/// </summary>
	public ref class SaidaPreDefined : public System::Windows::Forms::Form
	{
	public:
		SaidaPreDefined(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	//public:SaidaPreDefined(System::Windows::Forms::Form ^ frm1)
//	{
//		otherform = frm1;
//		InitializeComponent();

//	}

	public:
		SaidaPreDefined(String^ myFile, String^ myPath)
		{
			file = myFile;
			path = myPath;
			InitializeComponent();
			file = "fft_real_input.txt";
			//
			//TODO: Adicione o código do construtor aqui
			//
		}

	public:SaidaPreDefined(System::Windows::Forms::Form ^ frm1, String^ myFile, String^ myPath)
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
		~SaidaPreDefined()
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

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::LinkLabel^  linkLabel1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::LinkLabel^  linkLabel2;
	private: System::Windows::Forms::LinkLabel^  linkLabel3;
	private: System::Windows::Forms::LinkLabel^  linkLabel4;
	private: System::Windows::Forms::LinkLabel^  linkLabel5;
	private: System::Windows::Forms::Button^  button1;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(SaidaPreDefined::typeid));
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->linkLabel2 = (gcnew System::Windows::Forms::LinkLabel());
			this->linkLabel3 = (gcnew System::Windows::Forms::LinkLabel());
			this->linkLabel4 = (gcnew System::Windows::Forms::LinkLabel());
			this->linkLabel5 = (gcnew System::Windows::Forms::LinkLabel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.Image")));
			this->button4->Location = System::Drawing::Point(30, 13);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(29, 33);
			this->button4->TabIndex = 68;
			this->button4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &SaidaPreDefined::button4_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(262, 147);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(256, 134);
			this->listBox1->TabIndex = 67;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(267, 93);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(256, 20);
			this->label3->TabIndex = 65;
			this->label3->Text = L"Pre defined Functions - Output";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(177, 44);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(487, 17);
			this->label2->TabIndex = 64;
			this->label2->Text = L"FTSimulator is an open-source tool for Classical and Quantum Fourier Transforms.";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(300, 313);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(147, 13);
			this->label1->TabIndex = 63;
			this->label1->Text = L"Visit our project homepage at:";
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Location = System::Drawing::Point(317, 340);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(119, 13);
			this->linkLabel1->TabIndex = 62;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"https://goo.gl/UA5C8R";
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &SaidaPreDefined::linkLabel1_LinkClicked);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(320, 5);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(182, 36);
			this->textBox1->TabIndex = 61;
			this->textBox1->TabStop = false;
			this->textBox1->Text = L"FTSimulator";
			// 
			// linkLabel2
			// 
			this->linkLabel2->AutoSize = true;
			this->linkLabel2->Location = System::Drawing::Point(75, 147);
			this->linkLabel2->Name = L"linkLabel2";
			this->linkLabel2->Size = System::Drawing::Size(109, 13);
			this->linkLabel2->TabIndex = 69;
			this->linkLabel2->TabStop = true;
			this->linkLabel2->Text = L"fft_imaginary_input.txt";
			this->linkLabel2->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &SaidaPreDefined::linkLabel2_LinkClicked);
			// 
			// linkLabel3
			// 
			this->linkLabel3->AutoSize = true;
			this->linkLabel3->Location = System::Drawing::Point(78, 187);
			this->linkLabel3->Name = L"linkLabel3";
			this->linkLabel3->Size = System::Drawing::Size(116, 13);
			this->linkLabel3->TabIndex = 70;
			this->linkLabel3->TabStop = true;
			this->linkLabel3->Text = L"fft_imaginary_output.txt";
			this->linkLabel3->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &SaidaPreDefined::linkLabel3_LinkClicked);
			// 
			// linkLabel4
			// 
			this->linkLabel4->AutoSize = true;
			this->linkLabel4->Location = System::Drawing::Point(78, 223);
			this->linkLabel4->Name = L"linkLabel4";
			this->linkLabel4->Size = System::Drawing::Size(82, 13);
			this->linkLabel4->TabIndex = 71;
			this->linkLabel4->TabStop = true;
			this->linkLabel4->Text = L"fft_real_input.txt";
			this->linkLabel4->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &SaidaPreDefined::linkLabel4_LinkClicked);
			// 
			// linkLabel5
			// 
			this->linkLabel5->AutoSize = true;
			this->linkLabel5->Location = System::Drawing::Point(78, 254);
			this->linkLabel5->Name = L"linkLabel5";
			this->linkLabel5->Size = System::Drawing::Size(89, 13);
			this->linkLabel5->TabIndex = 72;
			this->linkLabel5->TabStop = true;
			this->linkLabel5->Text = L"fft_real_output.txt";
			this->linkLabel5->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &SaidaPreDefined::linkLabel5_LinkClicked);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(574, 235);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 32);
			this->button1->TabIndex = 73;
			this->button1->Text = L" > LaTeX";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &SaidaPreDefined::button1_Click);
			// 
			// SaidaPreDefined
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->ClientSize = System::Drawing::Size(711, 371);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->linkLabel5);
			this->Controls->Add(this->linkLabel4);
			this->Controls->Add(this->linkLabel3);
			this->Controls->Add(this->linkLabel2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->textBox1);
			this->Name = L"SaidaPreDefined";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FTSimulator";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Windows::Forms::Form ^ otherform;
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Hide();
		// Deletar arquivos do diretório output aqui!
		listBox1->Items->Clear();
		System::IO::File::Delete(path + "./output/fft_imaginary_output.txt");
		System::IO::File::Delete(path + "./output/fft_imaginary_input.txt");
		System::IO::File::Delete(path + "./output/fft_real_output.txt");
	    System::IO::File::Delete(path + "./output/fft_real_input.txt");
		otherform->Show();
	}
	private: System::Void linkLabel1_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
		System::Diagnostics::Process::Start("https://goo.gl/UA5C8R");

	}
	private: System::Void linkLabel2_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
		
		file = "fft_imaginary_input.txt";
		path = Directory::GetCurrentDirectory();
		
		listBox1->Items->Clear();

		try
		{
			String^ textFile = String::Concat(path, ("\\output\\fft_imaginary_input.txt"));
			StreamReader ^reader = gcnew  System::IO::StreamReader(textFile);


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
	};


	private: System::Void linkLabel3_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
		file = "fft_imaginary_output.txt";
		path = Directory::GetCurrentDirectory();

		listBox1->Items->Clear();

		try
		{
			String^ textFile = String::Concat(path, ("\\output\\fft_imaginary_output.txt"));
			StreamReader ^reader = gcnew  System::IO::StreamReader(textFile);


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
private: System::Void linkLabel4_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
	
	
	path = Directory::GetCurrentDirectory();

	listBox1->Items->Clear();

	try
	{
		String^ textFile = String::Concat(path, ("\\output\\fft_real_input.txt"));
		StreamReader ^reader = gcnew  System::IO::StreamReader(textFile);


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
private: System::Void linkLabel5_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
	file = "fft_real_output.txt";

	path = Directory::GetCurrentDirectory();

	listBox1->Items->Clear();

	try
	{
		
		String^ textFile = String::Concat(path, ("\\output\\fft_real_output.txt"));
		StreamReader ^reader = gcnew  System::IO::StreamReader(textFile);


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

		 private: System::Void MarshalString2(String ^ s, string& os) {
			 using namespace Runtime::InteropServices;
			 const char* chars =
				 (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			 os = chars;
			 Marshal::FreeHGlobal(IntPtr((void*)chars));
		 }


private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	
	// transformação do nome do arquivo
	std::string fileTransformed = "a";
	MarshalString2(file, fileTransformed);

	// transformação do caminho do arquivo
	std::string pathTransformed = "a";
	MarshalString2(path, pathTransformed);

	CFFT::fftToLatex(fileTransformed,pathTransformed);
	MessageBox::Show("Operation was Successful");

}
};

}
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
	/// Sumário para pag5
	/// </summary>
	public ref class pag5 : public System::Windows::Forms::Form
	{

	
	public:
		pag5(String^ myFile, String^ myPath)
		{
			file = myFile;
			path = myPath;
			InitializeComponent();
			//
			//TODO: Adicione o código do construtor aqui
			//
		}

	private: String^ path;
	private: String^ file;
	protected:
		/// <summary>
		/// Limpar os recursos que estão sendo usados.
		/// </summary>
		~pag5()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::LinkLabel^  linkLabel1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::LinkLabel^  linkLabel2;
	private: System::Windows::Forms::ListBox^  listBox1;

	private:
		/// <summary>
		/// Variável de designer necessária.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necessário para suporte do Designer - não modifique
		/// o conteúdo deste método com o editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->linkLabel2 = (gcnew System::Windows::Forms::LinkLabel());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(124, 40);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(487, 17);
			this->label2->TabIndex = 14;
			this->label2->Text = L"FTSimulator is an open-source tool for Classical and Quantum Fourier Transforms.";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(303, 327);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(147, 13);
			this->label1->TabIndex = 13;
			this->label1->Text = L"Visit our project homepage at:";
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Location = System::Drawing::Point(284, 350);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(193, 13);
			this->linkLabel1->TabIndex = 12;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"https://code.google.com/p/ftsimulator/";
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &pag5::linkLabel1_LinkClicked);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(580, 259);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 32);
			this->button1->TabIndex = 10;
			this->button1->Text = L" > LaTeX";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &pag5::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(272, 1);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(182, 36);
			this->textBox1->TabIndex = 9;
			this->textBox1->Text = L"FTSimulator";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(319, 85);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(64, 20);
			this->label3->TabIndex = 15;
			this->label3->Text = L"Output";
			this->label3->Click += gcnew System::EventHandler(this, &pag5::label3_Click);
			// 
			// linkLabel2
			// 
			this->linkLabel2->AutoSize = true;
			this->linkLabel2->Location = System::Drawing::Point(48, 128);
			this->linkLabel2->Name = L"linkLabel2";
			this->linkLabel2->Size = System::Drawing::Size(132, 13);
			this->linkLabel2->TabIndex = 16;
			this->linkLabel2->TabStop = true;
			this->linkLabel2->Text = L"./output/fft_real_output.txt";
			this->linkLabel2->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &pag5::linkLabel2_LinkClicked);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(232, 128);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(256, 134);
			this->listBox1->TabIndex = 17;
			// 
			// pag5
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->ClientSize = System::Drawing::Size(713, 372);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->linkLabel2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"pag5";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"pag5";
			this->Load += gcnew System::EventHandler(this, &pag5::pag5_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void linkLabel1_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
				 System::Diagnostics::Process::Start("https://code.google.com/p/ftsimulator/");
	}
private: System::Void pag5_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void linkLabel2_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e) {
			 listBox1->Items->Clear();
			 MessageBox::Show(String::Concat(path, ("\\output\\fft_real_output.txt")));
			 try
			 {
				 String^ textFile = String::Concat(path, ("\\output\\fft_real_output.txt"));
				 StreamReader ^reader = gcnew  System::IO::StreamReader(textFile);
		

				 do
				 {
					 listBox1->Items->Add(reader->ReadLine());
				 } while (reader->Peek() != -1);
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

}
};
}

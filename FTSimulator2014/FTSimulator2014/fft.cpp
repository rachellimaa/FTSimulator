//   fft.cpp - impelementation of class
//   of fast Fourier transform - FFT
//
//   The code is property of LIBROW
//   You can use it on your own
//   When utilizing credit LIBROW site

//   Include declaration file

#include "fft.h"
#include "latexParser.h"
#include "interface.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <climits>
#include <string>


#define MAX_SIZE 16
#define PI 3.14159265358979323846

using namespace std;
using std::cout;
using std::ifstream;
using std::cin;
using std::ios;
using namespace System::Windows::Forms;
using namespace System;


complex CFFT::*cSignal;



//   FORWARD FOURIER TRANSFORM
//     Input  - input data
//     Output - transform result
//     N      - length of both input data and result
bool CFFT::Forward(const complex *const Input, complex *const Output, const unsigned int N)
{
	//   Check input parameters
	if (!Input || !Output || N < 1 || N & (N - 1) )//Essa última condição verifica
		return false;							   //se N é múltiplo de 2 (N = 2^k)	
	//   Initialize data
	Rearrange(Input, Output, N);
	//   Call FFT implementation
	Perform(Output, N);
	//   Succeeded
	return true;
}

//   FORWARD FOURIER TRANSFORM, INPLACE VERSION
//     Data - both input data and output
//     N    - length of input data
bool CFFT::Forward(complex *const Data, const unsigned int N)
{
	//   Check input parameters
	if (!Data || N < 1 || N & (N - 1))
		return false;
	//   Rearrange
	Rearrange(Data, N);
	//   Call FFT implementation
	Perform(Data, N);
	//   Succeeded
	return true;
}

//   INVERSE FOURIER TRANSFORM
//     Input  - input data
//     Output - transform result
//     N      - length of both input data and result
//     Scale  - if to scale result           //A mulpiplicação de (1/N) na IFFT é feita por Scale
bool CFFT::Inverse(const complex *const Input, complex *const Output,
				   const unsigned int N, const bool Scale /* = true */){
	//   Check input parameters
	if (!Input || !Output || N < 1 || N & (N - 1))
		return false;
	//   Initialize data
	Rearrange(Input, Output, N);
	//   Call FFT implementation
	Perform(Output, N, true);
	//   Scale if necessary
	if (Scale)
		CFFT::Scale(Output, N);
	//   Succeeded
	return true;
}

//   INVERSE FOURIER TRANSFORM, INPLACE VERSION
//     Data  - both input data and output
//     N     - length of both input data and result
//     Scale - if to scale result
bool CFFT::Inverse(complex *const Data, const unsigned int N, const bool Scale /* = true */)
{
	//   Check input parameters
	if (!Data || N < 1 || N & (N - 1))
		return false;
	//   Rearrange
	Rearrange(Data, N);
	//   Call FFT implementation
	Perform(Data, N, true);
	//   Scale if necessary
	if (Scale)
		CFFT::Scale(Data, N);
	//   Succeeded
	return true;
}

//   Rearrange function
void CFFT::Rearrange(const complex *const Input, complex *const Output, const unsigned int N)
{
	//   Data entry position
	unsigned int Target = 0;
	//   Process all positions of input signal
	for (unsigned int Position = 0; Position < N; ++Position)
	{
		//  Set data entry
		Output[Target] = Input[Position];
		//   Bit mask
		unsigned int Mask = N;
		//   While bit is set
		while (Target & (Mask >>= 1))
			//   Drop bit
			Target &= ~Mask;
		//   The current bit is 0 - set it
		Target |= Mask;
	}
}

//   Inplace version of rearrange function
void CFFT::Rearrange(complex *const Data, const unsigned int N)
{
	//   Swap position
	unsigned int Target = 0;
	//   Process all positions of input signal
	for (unsigned int Position = 0; Position < N; ++Position)
	{
		//   Only for not yet swapped entries
		if (Target > Position)
		{
			//   Swap entries
			const complex Temp(Data[Target]);
			Data[Target] = Data[Position];
			Data[Position] = Temp;
		}
		//   Bit mask
		unsigned int Mask = N;
		//   While bit is set
		while (Target & (Mask >>= 1))
			//   Drop bit
			Target &= ~Mask;
		//   The current bit is 0 - set it
		Target |= Mask;
	}
}

//   FFT implementation
void CFFT::Perform(complex *const Data, const unsigned int N, const bool Inverse /* = false */)
{
	const double pi = Inverse ? 3.14159265358979323846 : -3.14159265358979323846;
	//   Iteration through dyads, quadruples, octads and so on...
	for (unsigned int Step = 1; Step < N; Step <<= 1)
	{
		//   Jump to the next entry of the same transform factor
		const unsigned int Jump = Step << 1;
		//   Angle increment
		const double delta = pi / double(Step);
		//   Auxiliary sin(delta / 2)
		const double Sine = sin(delta * .5);
		//   Multiplier for trigonometric recurrence
		const complex Multiplier(-2. * Sine * Sine, sin(delta));
		//   Start value for transform factor, fi = 0
		complex Factor(1.);
		//   Iteration through groups of different transform factor
		for (unsigned int Group = 0; Group < Step; ++Group)
		{
			//   Iteration within group 
			for (unsigned int Pair = Group; Pair < N; Pair += Jump)
			{
				//   Match position
				const unsigned int Match = Pair + Step;
				//   Second term of two-point transform
				const complex Product(Factor * Data[Match]);
				//   Transform for fi + pi
				Data[Match] = Data[Pair] - Product;
				//   Transform for fi
				Data[Pair] += Product;
			}
			//   Successive transform factor via trigonometric recurrence
			Factor = Multiplier * Factor + Factor;
		}
	}
}

//   Scaling of inverse FFT result  //A mulpiplicação de (1/N) na IFFT é feita por Scale
void CFFT::Scale(complex *const Data, const unsigned int N)
{
	const double Factor = 1. / double(N);
	//   Scale all data entries
	for (unsigned int Position = 0; Position < N; ++Position)
		Data[Position] *= Factor;
}

void CFFT::fftToLatex(string filename) {
	int arraySize = getFileSize(filename);
	CPARSER::parser(arraySize);
	CPARSER::generatesPDF();

}

/*
 Executa a FFT a partir do caminho de um arquivo informado como parâmetro
*/
bool CFFT::fftFromFile(string filename){

	int arraySize = getFileSize(filename);
	// Verify if array size is a power of 2
	if (arraySize  < 1 || arraySize & (arraySize - 1)){
		return 1;
	}
	complex(*cSignal) = new complex[arraySize];
	bool t1 = createFFTArray(cSignal, arraySize, filename);
	bool t2 = createFFTInputFiles(cSignal, arraySize);
	Forward(cSignal, arraySize);
	bool t3 = FFTArrayToFile(cSignal, arraySize);

	return t1 || t2 || t3;
}

void CFFT::fftFromFunction(int function) {
	complex(*cSignal) = new complex[MAX_SIZE];
	generateArrayPredefinedFunction(cSignal, function);
	createFFTInputFiles(cSignal, MAX_SIZE);
	Forward(cSignal, MAX_SIZE);
	FFTArrayToFile(cSignal, MAX_SIZE);
}

void CFFT::performFFT() {
	//deprecated
}

int CFFT::getFileSize(string filename){

	int size = 0;
	int endPoint = -1;
	string str[2];
	int i = 0;

	try{
		ifstream dados(filename, ios::in); 
		if (dados.is_open()){
			while ((dados.good())&&(endPoint == -1)){
				int atual = dados.get();
				if (char(atual) == '('){
					size +=1;
				} else if (char(atual) == '.'){
					endPoint = 0;
				}
			}
		}
		dados.close();		
	} catch (ifstream::failure e){
		
	}

	return size;

}

bool CFFT::createFFTArray(complex *cSignal, int arraySize, string filename){

	try {
		ifstream dados(filename, ios::in);
		string str;
		char real_char[10];
		char imaginario_char[10];
		double real_float;
		double imaginario_float;
		int i = 0;

		if(dados.is_open()){
			while (dados.good())
			{
				dados >> str;
					//Delimita os pontos iniciais dos numero real do arquivo
					int n = str.find('(');
					int m = str.find(',');
					
					//Pega o numero real do Arquivo e o converte em float
					str.copy(real_char, m-n-1 /*Quantos char's é para copiar*/, 
								n+1 /*Onde Começa a copiar*/);
					real_char[m-1]='\0'; //Termino do array de char
					real_float = atof(real_char); //Convertendo o char em double

					//Delimita os pontos iniciais dos numero imaginário do arquivo
					n = str.find(',');
					m = str.find(')');

					//Pega o numero imaginario do Arquivo e o converte em float
					str.copy(imaginario_char, m-n-1  /*Quantos char's é para copiar*/,
								n+1 /*Onde Começa a copiar*/);
					imaginario_char[m-n-1]='\0'; //Termino do array de char
					imaginario_float = atof(imaginario_char); //Convertendo o char em double

					//Passa os dados para a classe complex
					*(cSignal+i)=complex (real_float,imaginario_float);
				//	cout << "Real: " << real_float << " Img: "  << imaginario_float;
					
					i++;
			

			}}


	} catch (ifstream::failure e){
		return 1;
	}
	return 0;


}

bool CFFT::FFTArrayToFile(complex *cSignal, int arraySize){

	 try{
		//Creates the output files
		ofstream myfile_1 ("./output/fft_real_output.txt");
		ofstream myfile_2 ("./output/fft_imaginary_output.txt");

		//Saving the FFT matrix
		if (myfile_1.is_open() && myfile_2.is_open()){
			for(int i=0; i < arraySize; i++){
				myfile_1 << (cSignal + i)->re() << "\n";
				myfile_2 << (cSignal + i)->im() << "\n";
			}
			//Fechando os arquivos
			myfile_1.close();
			myfile_2.close();
		}
	 } catch (ifstream::failure e){
		 return 1;
	}

	 return 0;


}

bool CFFT::createFFTInputFiles(complex *cSignal, int arraySize){

	//Cria o Arquivo de saida de dados em .txt para futuras utilizações
	ofstream myfile_1 ("./output/fft_real_input.txt");
	ofstream myfile_2 ("./output/fft_imaginary_input.txt");

	//Salvando a Matriz no Arquivo
	try {
		if (myfile_1.is_open() && myfile_2.is_open()){
			for(int i=0; i < arraySize; i++){
				myfile_1 << (cSignal+ i)->re() << "\n";
				myfile_2 << (cSignal+ i)->im() << "\n";
			}
			//Fechando os arquivos
			myfile_1.close();
			myfile_2.close();
		}
	} catch (ifstream::failure e){
		return 1;
	}

	return 0;
}

void CFFT::generateArrayPredefinedFunction(complex *cSignal, int option){

			switch (option){
				case 1:
					for(int k = 0; k < MAX_SIZE; k++)
						*(cSignal+k)=complex (sin((float)(k*2*PI)/MAX_SIZE),0);
					break;

				case 2:
					for(int k = 0; k < MAX_SIZE; k++)
						*(cSignal+k)=complex (cos((float)(k*2*PI)/MAX_SIZE),0);
					break;

				case 3:
					for(int k = 0; k < MAX_SIZE; k++)
						*(cSignal+k)=complex (1,0);
					break;

				case 4:
					for(int k = 0; k < MAX_SIZE; k++){
						if(k<(MAX_SIZE)/2)
							*(cSignal+k)=complex(1,0);
						else
							*(cSignal+k)=complex(0,0);
					}
					break;

				case 5:
					for(int k = 0; k < MAX_SIZE; k++)
						*(cSignal+k)=complex((float)k/MAX_SIZE,0);
					break;

				case 6:
					*cSignal = complex(1,0);
					break;
			}






}

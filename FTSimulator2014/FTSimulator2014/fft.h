//   fft.h - declaration of class
//   of fast Fourier transform - FFT
//
//   The code is property of LIBROW
//   You can use it on your own
//   When utilizing credit LIBROW site

#ifndef _FFT_H_
#define _FFT_H_

//   Include complex numbers header
#include "complex.h"
#include <string>

class CFFT
{
public:
	//   FORWARD FOURIER TRANSFORM
	//     Input  - input data
	//     Output - transform result
	//     N      - length of both input data and result
	static bool Forward(const complex *const Input, complex *const Output, const unsigned int N);

	//   FORWARD FOURIER TRANSFORM, INPLACE VERSION
	//     Data - both input data and output
	//     N    - length of input data
	static bool Forward(complex *const Data, const unsigned int N);

	//   INVERSE FOURIER TRANSFORM
	//     Input  - input data
	//     Output - transform result
	//     N      - length of both input data and result
	//     Scale  - if to scale result
	static bool Inverse(const complex *const Input, complex *const Output, const unsigned int N, const bool Scale = true);

	//   INVERSE FOURIER TRANSFORM, INPLACE VERSION
	//     Data  - both input data and output
	//     N     - length of both input data and result
	//     Scale - if to scale result
	static bool Inverse(complex *const Data, const unsigned int N, const bool Scale = true);


	// Performs the FFT
	static void CFFT::performFFT();
	static bool CFFT::fftFromFile(std::string filename);
	static void CFFT::fftToLatex(std::string filename);
	static void CFFT::fftFromFunction(int function);
	

protected:
	//   Rearrange function and its inplace version
	static void Rearrange(const complex *const Input, complex *const Output, const unsigned int N);
	static void Rearrange(complex *const Data, const unsigned int N);

	//   FFT implementation
	static void Perform(complex *const Data, const unsigned int N, const bool Inverse = false);

	//   Scaling of inverse FFT result
	static void Scale(complex *const Data, const unsigned int N);

	

	private:
		static int getFileSize(std::string filename);
		static bool createFFTArray(complex *cSignal, int arraySize, std::string filename);
		static bool createFFTInputFiles(complex *cSignal, int arraySize);
		static bool FFTArrayToFile(complex *cSignal, int arraySize);
		static void generateArrayPredefinedFunction(complex *cSignal, int option);
};

#endif
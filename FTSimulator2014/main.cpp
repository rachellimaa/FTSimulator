#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <stdio.h>
#include "fft.h"
#include "interface.h"
#include "qft.h"


using std::cout;
using std::cin;
using std::ios;
using std::endl;
using std::ifstream;

using namespace std;


int main()
{

	CINTERFACE::printLogo();
	if (CINTERFACE::transformType() == 1){
	  // Chamar FFT
		CFFT::performFFT(); 
	} else {
      // Chamar QFT
	//	CQFT::performQFT();
	}

	CINTERFACE::exitMessage();

}




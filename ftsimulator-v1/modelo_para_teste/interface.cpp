#include <iostream>
#include <fstream>
#include "interface.h"
#include <stdio.h>

using std::cout;
using std::cin;
using std::ios;
using std::endl;
using std::ifstream;

#define MAX_SIZE 16


/*
Initializes the user interface
*/
void CINTERFACE::printLogo(){
 
	ifstream logotipo;
	logotipo.open("./data/logo-ascii.txt",ifstream::in); //Abre o arquivo logo.txt

	int ch = logotipo.get();
	while (logotipo.good()) {
		cout << (char) ch;
		ch = logotipo.get();
	 }

   logotipo.close();

   cout << "\n\n\n";

   cout << "FTSimulator is an open-source tool for Classical and Quantum Fourier Transforms\n";
   cout << "Visit our project homepage at http://ftsimulator.googlecode.com \n\n";

}


/* Reads the user option regarding the Fourier transform type selected */
int CINTERFACE::transformType(){
	int transformOption = 0;
   
	cout << "There are two types of Fourier Transforms available. Choose your option below:\n";
	cout << "1. Fast Fourier Transform\n";
	cout <<  "2. Quantum Fourier Transform\n";
	cout << "\nPress the number of the choice selected: ";
	cin >> *(&transformOption);

	while ((transformOption != 1)&&(transformOption != 2)){
		cout << "\n\nThere are two types of Fourier Transforms available. Choose your option below:\n";
		cout << "1. Fast Fourier Transform\n";
		cout <<  "2. Quantum Fourier Transform\n";
		cout << "\nPress the number of the choice selected: ";
		cin >> *(&transformOption);
	}
	return transformOption;

}


int CINTERFACE::initialFFTMessage(){
	system("CLS");
	int userOption = 0;

	cout << "Do you want to use an input file or pre-defined functions?";
	cout << "\n1. Input File;";
	cout << "\n2. Pre-defined functions";
	cout << "\nPress the number of the choice selected: ";
	cin >> *(&userOption);

	while ((userOption != 1)&&(userOption != 2)){
		cout << "\n\nDo you want to use an input file or pre-defined functions?";
		cout << "\n1. Input File;";
		cout << "\n2. Pre-defined functions";
		cout << "\nPress the number of the choice selected: ";
		cin >> *(&userOption);
	}

	return userOption;

}


int CINTERFACE::preDefinedFunctions(){
	system("CLS");
	int userOption = 0;

	cout << "You might choose among the following predefined functions "
	<< "(" << MAX_SIZE << " points will be generated): \n" ;
	cout << "1. Sin;\n";
	cout << "2. Cosin;\n";
	cout << "3. Constant;\n";
	cout << "4. Retangular Pulse;\n";
	cout << "5. Triangular Sawtooth\n";
	cout << "6. Dirac Impulse \n";
	cout << "\nPress the number of the choice selected: ";
	cin >> *(&userOption);

	while ((userOption < 1)||(userOption > 6)){
		cout << "\n\nYou might choose among the following predefined functions "
		<< "(" << MAX_SIZE << " points will be generated): \n" ;
		cout << "1. Sin;\n";
		cout << "2. Cosin;\n";
		cout << "3. Constant;\n";
		cout << "4. Retangular Pulse;\n";
		cout << "5. Triangular Sawtooth\n";
		cout << "6. Dirac Impulse \n";
		cout << "\nPress the number of the choice selected: ";
		cin >> *(&userOption);

	}

  return userOption;

}

int CINTERFACE::generateLaTeXData(){

  int userChoice = -1;

  system("CLS");
  cout << "Would you like to generate LaTeX files from the Fourier Transform output?";
  cout << "\n0. No";
  cout <<"\n1. Yes";
  cout <<"\nInform your option: ";

  cin >> *(&userChoice);

  while ((userChoice != 1)&&(userChoice != 0)){
	cout << "\n\n\nWould you like to generate LaTeX files from the Fourier Transform output?";
	 cout << "\n0. No";
	 cout <<"\n1. Yes";
	cout <<"\nInform your option: ";
		cin >> *(&userChoice);
	}

  return userChoice;

}

void CINTERFACE::fftSuccessful(){

	cout << "\n\nFFT was performed successfully!\n";

}

void CINTERFACE::qftSuccessful(){

	cout << "\n\nQFT was performed successfully!\n";

}




void CINTERFACE::exitMessage(){
  
	 cout << "\nFTSimulator finished its execution.\n";
     system("PAUSE");
	 exit(0);

}

void CINTERFACE::errorInputFFTFile(){
	system("CLS");
	cout << "The input file for the Fast Fourier Transform is not well formated.\n";
	cout << "Due to that, the transform could not be executed. Check the user guide for instructions.\n";
	system("PAUSE");
	exit(1);
}

void CINTERFACE::errorOutputFFTFile(){
	system("CLS");
	cout << "The output files for the Fast Fourier Transform could not be created.\n";
	cout << "Due to that, the transform could not be executed. Check the user guide for instructions.\n";
	system("PAUSE");
	exit(1);
}

void CINTERFACE::errorInputFFTPower(){
	system("CLS");
	cout << "The input file for the Fast Fourier Transform must consist in a vector which is a power of 2^n.\n";
	cout << "Due to that, the transform could not be executed. Check the user guide for instructions.\n";
	system("PAUSE");
	exit(1);
}

void CINTERFACE::errorInputQFTFile(){
	system("CLS");
	cout << "The input file for the Quantum Fourier Transform is not well formated.\n";
	cout << "Due to that, the transform could not be executed. Check the user guide for instructions.\n";
	system("PAUSE");
	exit(1);
}


void CINTERFACE::errorOutputQFTFile(){
	system("CLS");
	cout << "The output files for the Fast Fourier Transform could not be created.\n";
	cout << "Due to that, the transform could not be executed. Check the user guide for instructions.\n";
	system("PAUSE");
	exit(1);
}

void CINTERFACE::errorInputQFTMatrix(){
	system("CLS");
	cout << "The input file for the Quantum Fourier Transform must consist in a matrix of order 2^n ( n > 1).\n";
	cout << "Due to that, the transform could not be executed. Check the user guide for instructions.\n";
	system("PAUSE");
	exit(1);
}


void CINTERFACE::pause(){
	system("PAUSE");
}











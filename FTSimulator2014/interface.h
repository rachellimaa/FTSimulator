#ifndef _INTERFACE_H_
#define _INTERFACE_H_

class CINTERFACE
{

	public:
		static void printLogo();
		static int transformType();
		static int initialFFTMessage();
		static int generateLaTeXData();
		static void fftSuccessful();
		static int preDefinedFunctions();
		static void exitMessage();
		static void errorInputFFTFile();
		static void errorOutputFFTFile();
		static void errorInputFFTPower();
		static void qftSuccessful();
		static void errorInputQFTFile();
		static void errorOutputQFTFile();
		static void errorInputQFTMatrix();
		static void pause();
};







#endif
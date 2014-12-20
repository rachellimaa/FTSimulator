#ifndef _QFT_H_
#define _QFT_H_

#include "complex.h"
#include <string>



class CQFT{

public:
	static void CQFT::performQFT(std::string filename);

private:
	static void CQFT::createQFTArray(complex **qSignal,int matrixSize, std::string filename);
	static int CQFT::matrixSize(std::string filename);
	static void CQFT::qft(complex **qSignal, int matrixSize);
    static void CQFT::qftOperator(complex **, int );
	static void CQFT::createQFTOutput(complex **,int );

	
};



#endif
#ifndef _QFT_H_
#define _QFT_H_

#include "complex.h"



class CQFT{

public:
	static void CQFT::performQFT();

private:
	static void CQFT::createQFTArray(complex **qSignal,int matrixSize);
	static int CQFT::matrixSize();
	static void CQFT::qft(complex **qSignal, int matrixSize);
    static void CQFT::qftOperator(complex **, int );
	static void CQFT::createQFTOutput(complex **,int );

	
};



#endif
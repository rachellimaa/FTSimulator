#ifndef _QFT_H_
#define _QFT_H_

#include "complex.h"
#include <string>



class CQFT{

public:
	static int CQFT::performQFT(std::string filename, std::string path);

private:
	static int CQFT::createQFTArray(complex **qSignal,int matrixSize, std::string filename, std::string path);
	static int CQFT::matrixSize(std::string filename, std::string path);
	static void CQFT::qft(complex **qSignal, int matrixSize);
    static void CQFT::qftOperator(complex **, int );
	static int CQFT::createQFTOutput(complex **,int ,std::string);

	
};



#endif
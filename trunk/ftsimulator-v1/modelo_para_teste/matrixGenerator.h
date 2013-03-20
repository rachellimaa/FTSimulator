#ifndef _MATRIXGENERATOR_H_
#define _MATRIXGENERATOR_H_
#include <fstream>
#include "complex.h"
using std::ifstream;


class CMATRIXGENERATOR
{

public:
	static void initializePRNG();
    static complex getComplex();
};

#endif
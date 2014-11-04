#include <random>
#include <ctime>
#include "complex.h"
#include <iostream>
#include <fstream>
#include "matrixGenerator.h"

using std::cout;



void CMATRIXGENERATOR::initializePRNG(){
	srand((unsigned)time(0));
}




complex CMATRIXGENERATOR::getComplex(){
	double real = (double)rand()/(double)RAND_MAX;
	double imaginario = (double)rand()/(double)RAND_MAX;
	return complex(real,imaginario);
}

void generateMatrix(complex *qSignal, int size){
	
   
	/*
	for (int i = 0; i < size; i++){
	   for (int j = 0; j < size; j++){
		   // generate complex matrix here
	   }
   } */

   
}
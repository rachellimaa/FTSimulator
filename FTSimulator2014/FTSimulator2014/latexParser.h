#ifndef _LATEXPARSER_H_
#define _LATEXPARSER_H_
#include <fstream>
using std::ifstream;


class CPARSER
{

	public:
		static void generatesPDF();
		static double findMaxValue(int, ifstream &, ifstream &);
		static void parser(int);
		static void mergeFiles();

};

#endif
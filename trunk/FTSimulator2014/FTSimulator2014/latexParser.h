#ifndef _LATEXPARSER_H_
#define _LATEXPARSER_H_
#include <fstream>
using std::ifstream;


class CPARSER
{

	public:
		static void generatesPDF(std::string);
		static double findMaxValue(int, ifstream &, ifstream &);
		static void parser(int, std::string);
		static void mergeFiles();

};

#endif
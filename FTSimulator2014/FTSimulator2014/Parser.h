#ifndef _PARSER_H_
#define _PARSER_H_

#include <fstream>

using std::ifstream;
using std::ofstream;

class Parser{
	private:
		void gera_grafico(int, int);
		ifstream input, real_input, imaginario_input, real_fft, imaginario_fft;
		ofstream output;
	public:
		Parser();
		~Parser();
		void parsing();
};

#endif
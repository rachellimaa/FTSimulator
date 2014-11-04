#include <iostream>
#include <fstream>
#include "complex.h"
#include "latexParser.h"
#define PI 3.14159265358979323846

using namespace std;
using std::cout;
using std::ios;
using std::ifstream;



void CPARSER::parser(int arraySize){

	//Creates the .tex output files
     ofstream absoluto_input ("input_fft_absolute.tex");
	 ofstream fase_input ("input_fft_phase.tex");
	 ofstream absoluto_fft ("output_fft_absolute.tex");
	 ofstream fase_fft ("output_fft_phase.tex");

	 // Open the fft input files
	 ifstream real_input("fft_real_input.txt", ios::in);
	 ifstream imaginario_input("fft_imaginary_input.txt", ios::in);

	// Open the output files of the Fourier Transform
	ifstream real_fft("fft_real_output.txt", ios::in);
	ifstream imaginario_fft("fft_imaginary_output.txt", ios::in);

	try {
		if (absoluto_input.is_open() && fase_input.is_open() &&
			real_input.is_open() && imaginario_input.is_open() &&
			real_fft.is_open() && imaginario_fft.is_open()){


	        // Corrigir chamada
			double max_y = findMaxValue(arraySize, real_input, imaginario_input);

			absoluto_input << "\\documentclass{minimal}\n";
			absoluto_input << "\\usepackage{tikz}\n";
			absoluto_input << "\\usetikzlibrary{plotmarks}\n";
			absoluto_input << "\n";
			absoluto_input << "\\begin{document}\n";
			absoluto_input << "\n";
			absoluto_input << "\\begin{tikzpicture}[x=.5cm, y=0.3cm]\n";
			absoluto_input << "\n";
			absoluto_input << "%axis\n";
			absoluto_input << "\\draw (-2,0) -- coordinate (x axis mid)(" << arraySize << ",0);\n";
			absoluto_input << "\\draw (-1,-1) -- coordinate (y axis mid)(-1," << max_y << ");\n";
			absoluto_input << "\n";
			absoluto_input << "%ticks\n";
			absoluto_input << "\\foreach \\x in {0,...," << arraySize;
			absoluto_input << "}\n";
			absoluto_input << "\\draw (\\x,1pt) -- (\\x,-3pt)\n";
			absoluto_input << "node[anchor=north] {\\x};\n";
			absoluto_input << "\n";
			absoluto_input << "%ticks\n";
			absoluto_input << "\\foreach \\y in {" << max_y/2 << ", " << max_y << "}\n";
			absoluto_input << "\\draw (-0.9,\\y) -- (-1.1,\\y)\n";
			absoluto_input << "node[left=0.1cm] {\\y};\n";
			absoluto_input << "\n";
			absoluto_input << "%ticks\n";
			absoluto_input << "\\foreach \\y in {1,...," << max_y << "}\n";
			absoluto_input << "\\draw (-0.9,\\y) -- (-1.1,\\y);\n";
			absoluto_input << "\n";
			absoluto_input << "%label\n";
			absoluto_input << "\\node[below=0.8cm] at (x axis mid) {$n$};\n";
			absoluto_input << "\\node[left=0.8cm]   at (y axis mid) {$"
					 << "\\left| x[n] \\right|$};\n";
			absoluto_input << "\n";


			// Corrigir chamada
			max_y = findMaxValue(arraySize, real_fft, imaginario_fft);

			absoluto_fft << "\\documentclass{minimal}\n";
			absoluto_fft << "\\usepackage{tikz}\n";
			absoluto_fft << "\\usetikzlibrary{plotmarks}\n";
			absoluto_fft << "\n";
			absoluto_fft << "\\begin{document}\n";
			absoluto_fft << "\n";
			absoluto_fft << "\\begin{tikzpicture}[x=.5cm, y=0.3cm]\n";
			absoluto_fft << "\n";
			absoluto_fft << "%axis\n";
			absoluto_fft << "\\draw (-2,0) -- coordinate (x axis mid)(" << arraySize << ",0);\n";
			absoluto_fft << "\\draw (-1,-1) -- coordinate (y axis mid)(-1," << max_y << ");\n";
			absoluto_fft << "\n";
			absoluto_fft << "%ticks\n";
			absoluto_fft << "\\foreach \\x in {0,...," << arraySize;
			absoluto_fft << "}\n";
			absoluto_fft << "\\draw (\\x,1pt) -- (\\x,-3pt)\n";
			absoluto_fft << "node[anchor=north] {\\x};\n";
			absoluto_fft << "\n";
			absoluto_fft << "%ticks\n";
			absoluto_fft << "\\foreach \\y in {" << max_y/2 << ", " << max_y << "}\n";
			absoluto_fft << "\\draw (-0.9,\\y) -- (-1.1,\\y)\n";
			absoluto_fft << "node[left=0.1cm] {\\y};\n";
			absoluto_fft << "\n";
			absoluto_fft << "%ticks\n";
			absoluto_fft << "\\foreach \\y in {1,...," << max_y << "}\n";
			absoluto_fft << "\\draw (-0.9,\\y) -- (-1.1,\\y);\n";
			absoluto_fft << "\n";
			absoluto_fft << "%label\n";
			absoluto_fft << "\\node[below=0.8cm] at (x axis mid) {$k$};\n";
			absoluto_fft << "\\node[left=0.8cm]   at (y axis mid) {$"
					 << "\\left| X[k] \\right|$};\n";
			absoluto_fft << "\n";
		

			fase_input << "\\documentclass{minimal}\n";
			fase_input << "\\usepackage{tikz}\n";
			fase_input << "\\usetikzlibrary{plotmarks}\n";
			fase_input << "\n";
			fase_input << "\\begin{document}\n";
			fase_input << "\n";
			fase_input << "\\begin{tikzpicture}[x=.5cm, y=0.3cm]\n";
			fase_input << "\n";
			fase_input << "%axis\n";
			fase_input << "\\draw (-2,0) -- coordinate (x axis mid)(" << arraySize  << ",0);\n";
			fase_input << "\\draw (-1," << -PI << ") -- coordinate (y axis mid)(-1," << PI << ");\n";
			fase_input << "\n";
			fase_input << "%ticks\n";
			fase_input << "\\foreach \\x in {0,...," << arraySize;
			fase_input << "}\n";
			fase_input << "\\draw (\\x,1pt) -- (\\x,-3pt)\n";
			fase_input << "node[anchor=north] {\\x};\n";
			fase_input << "\n";
			fase_input << "%ticks\n";
			fase_input << "\\foreach \\y in {" << -PI << ", " << PI << "}\n";
			fase_input << "\\draw (-0.9,\\y) -- (-1.1,\\y)\n";
			fase_input << "node[left=0.1cm] {\\y};\n";
			fase_input << "\n";
			fase_input << "%ticks\n";
			fase_input << "\\foreach \\y in {-2,...,2}\n";
			fase_input << "\\draw (-0.9,\\y) -- (-1.1,\\y);\n";
			fase_input << "\n";
			fase_input << "%label\n";
			fase_input << "\\node[below=0.8cm] at (x axis mid) {$n$};\n";
			fase_input << "\\node[left=0.8cm]   at (y axis mid) {$"
					   << "\\angle{x[n]} $};\n";
			fase_input << "\n";

			fase_fft << "\\documentclass{minimal}\n";
			fase_fft << "\\usepackage{tikz}\n";
			fase_fft << "\\usetikzlibrary{plotmarks}\n";
			fase_fft << "\n";
			fase_fft << "\\begin{document}\n";
			fase_fft << "\n";
			fase_fft << "\\begin{tikzpicture}[x=.5cm, y=0.3cm]\n";
			fase_fft << "\n";
			fase_fft << "%axis\n";
			fase_fft << "\\draw (-2,0) -- coordinate (x axis mid)(" << arraySize << ",0);\n";
			fase_fft << "\\draw (-1," << -PI << ") -- coordinate (y axis mid)(-1," << PI << ");\n";
			fase_fft << "\n";
			fase_fft << "%ticks\n";
			fase_fft << "\\foreach \\x in {0,...," << arraySize ;
			fase_fft << "}\n";
			fase_fft << "\\draw (\\x,1pt) -- (\\x,-3pt)\n";
			fase_fft << "node[anchor=north] {\\x};\n";
			fase_fft << "\n";
			fase_fft << "%ticks\n";
			fase_fft << "\\foreach \\y in {" << -PI << ", " << PI << "}\n";
			fase_fft << "\\draw (-0.9,\\y) -- (-1.1,\\y)\n";
			fase_fft << "node[left=0.1cm] {\\y};\n";
			fase_fft << "\n";
			fase_fft << "%ticks\n";
			fase_fft << "\\foreach \\y in {-2,...,2}\n";
			fase_fft << "\\draw (-0.9,\\y) -- (-1.1,\\y);\n";
			fase_fft << "\n";
			fase_fft << "%label\n";
			fase_fft << "\\node[below=0.8cm] at (x axis mid) {$k$};\n";
			fase_fft << "\\node[left=0.8cm]   at (y axis mid) {$"
					   << "\\angle{X[k]} $};\n";
			fase_input << "\n";


			ifstream real_input("fft_real_input.txt", ios::in);
		    ifstream imaginario_input("fft_imaginary_input.txt", ios::in);

			// Open the output files of the Fourier Transform
			ifstream real_fft("fft_real_output.txt", ios::in);
			ifstream imaginario_fft("fft_imaginary_output.txt", ios::in);

        
			float valor_real_input = 0, valor_imag_input = 0, tangente_input = 0, 
				  valor_real_fft = 0, valor_imag_fft = 0, tangente_fft = 0;

      		for(int i=0; i < arraySize; i++){

				real_input >> valor_real_input;
				imaginario_input >> valor_imag_input;

				if(valor_real_input == 0 && valor_imag_input == 0)
					tangente_input = 0;
				else if(valor_real_input == 0)
					tangente_input = 10000000;
				else
					tangente_input = valor_imag_input/valor_real_input;

				real_fft >> valor_real_fft;
				imaginario_fft >> valor_imag_fft;
				tangente_fft = valor_imag_fft/valor_real_fft;

				if(valor_real_fft == 0 && valor_imag_fft == 0)
					tangente_fft = 0;
				else if(valor_real_fft == 0)
					tangente_fft = 1000000000;
				else
					tangente_fft = valor_imag_fft/valor_real_fft;

				absoluto_input << "\\draw[black,thick] (" << i << ",0) --(" << i << ", "
						 << sqrt(pow(valor_real_input,2) + pow(valor_imag_input,2)) << ");\n";
				absoluto_input << "\\node at (" << i << ", "
						 << sqrt(pow(valor_real_input,2) + pow(valor_imag_input,2)) << ") {$\\bullet$};\n";

				fase_input << "\\draw[black,thick] (" << i << ",0) --(" << i << ", "
						 << atan(tangente_input) << ");\n";
				fase_input << "\\node at (" << i << ", "
						 << atan(tangente_input) << ") {$\\bullet$};\n";


				absoluto_fft << "\\draw[black,thick] (" << i << ",0) --(" << i << ", "
						 << sqrt(pow(valor_real_fft,2) + pow(valor_imag_fft,2)) << ");\n";
				absoluto_fft << "\\node at (" << i << ", "
						 << sqrt(pow(valor_real_fft,2) + pow(valor_imag_fft,2)) << ") {$\\bullet$};\n";

				fase_fft << "\\draw[black,thick] (" << i << ",0) --(" << i << ", "
						 << atan(tangente_fft) << ");\n";
				fase_fft << "\\node at (" << i << ", "
						 << atan(tangente_fft) << ") {$\\bullet$};\n";
			}

			absoluto_input << "\\end{tikzpicture}\n";
			absoluto_input << "\\end{document}\n";

			fase_input << "\\end{tikzpicture}\n";
			fase_input << "\\end{document}\n";

			absoluto_fft << "\\end{tikzpicture}\n";
			absoluto_fft << "\\end{document}\n";

			fase_fft << "\\end{tikzpicture}\n";
			fase_fft << "\\end{document}\n";

			//Fechando os arquivos
			absoluto_input.close();
			fase_input.close();
			real_input.close();
			imaginario_input.close();

		} 
		} catch (ifstream::failure e){
			// Mensagem de erro

}

	

}



double CPARSER::findMaxValue(int arraySize, ifstream &real, ifstream &imaginary){

	double max = 0;
	float valor_real = 0, valor_imag = 0;

	for(int i=0; i < arraySize; i++){
		real >> valor_real;
		imaginary >> valor_imag;

			if((sqrt(pow(valor_real, 2)+pow(valor_imag,2))) > max)
				max = sqrt(pow(valor_real, 2)+pow(valor_imag,2));  
	}

	return max;
	
}

void CPARSER::generatesPDF(){
	system("pdflatex input_fft_absolute.tex");
	system("pdflatex input_fft_phase.tex");
	system("pdflatex output_fft_absolute.tex");
	system("pdflatex output_fft_phase.tex");

	system("start input_fft_absolute.pdf");
	system("start input_fft_phase.pdf");
	system("start output_fft_absolute.pdf");
	system("start output_fft_phase.pdf");
}






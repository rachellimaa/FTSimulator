#include "qft.h"
#include "complex.h"
#include "interface.h"
#include <iostream>
#include <fstream>
#include <climits>
#include <string>

#define PI 3.14159265358979323846

using namespace std;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::string;
using std::cout;

complex CQFT::**qSignal;
complex CQFT::**qftOp;


int CQFT::performQFT(string filename, string path){

	try {
		const int matrixSize = CQFT::matrixSize(filename, path);
		if (matrixSize == -1){
			return 1; // erro
		}
		complex(**qSignal) = new complex*[matrixSize];
		for (int i = 0; i < matrixSize; i++){
			qSignal[i] = new complex[matrixSize];
		}
		int retorno = createQFTArray(qSignal, matrixSize, filename, path);
		if (retorno == 1){
			return 1; // erro
		}
		qft(qSignal, matrixSize);
		retorno = createQFTOutput(qSignal, matrixSize, path);
		if (retorno == 1){
			return 1;
		}
	}
	catch (exception e){
		return 1;
	}


	return 0; 
}




int CQFT::matrixSize(string filename, string path){

	ifstream dados(filename, ios::in); //Abre o arquivo input.txt

	int size = 0;
	int line = 0;
	int endPoint = -1;
	//string str[10];
	int i = 0;

	try{
		ifstream dados(filename, ios::in); 
		if (dados.is_open()){
			while ((dados.good())&&(endPoint == -1)){
				int atual = dados.get();
				if (char(atual) == '('){
					size +=1;
				} else if (char(atual) == ';'){
					size = 0;
					line += 1;
				}else if (char(atual) == '!'){
					endPoint = 0;
				}
			}
		}
		dados.close();

		if (line+1 != size) {
			return -1;
		}

	} catch (ifstream::failure e){
		return -1;
	}

	return size;
}

int CQFT::createQFTArray(complex **qSignal,int matrixSize, std::string filename, std::string path){


	try {
        ifstream dados(filename, ios::in); //Abre o arquivo input.txt

		string str;
		char real_char[5000];
		char imaginario_char[5000];
		double real_float;
		double imaginario_float;
		int i = 0;
		int j = 0;
		int l = 0;
		int ponto = -1;
		int p = 0; // Contador do numero de elementos da matriz

		if(dados.is_open()){
			while(dados.good() && (ponto == -1)){
				dados >> str;

				//Delimita os pontos iniciais dos numero real do arquivo
				int n = str.find('(');
				int m = str.find(',');

					
				//Pega o numero real do Arquivo e o converte em float
				str.copy(real_char, m-n-1, n+1); // Qtde de chars a serem copiados
				real_char[m-1]='\0'; //Termino do array de char
				real_float = atof(real_char); //Convertendo o char em double
				
				//Delimita os pontos iniciais dos numero imaginário do arquivo
				n = str.find(',');
				m = str.find(')');

				l = str.find(';');
				//Pega o numero imaginario do Arquivo e o converte em float
				str.copy(imaginario_char, m-n-1 , n+1 );
				imaginario_char[m-n-1]='\0'; //Termino do array de char
				imaginario_float = atof(imaginario_char); //Convertendo o char em double
					
				//Passa os dados para a variável Data
				qSignal[i][j] = complex (real_float,imaginario_float);
					
				
				
				if(l != -1){
					j++;
					i = 0;
				}
				else{
					i++;
				}
				
				

				ponto = str.find('!');
				
			}


		double abs_value = 0.0;

		for(int n = 0; n < matrixSize; n++){
				abs_value += sqrt(qSignal[n][n].norm());
		}

		
		if(abs_value > 1.05 || abs_value < 0.95){
			return 1;
		}

		}} catch (ifstream::failure e){
			return 1;

		}
	

		return 0;

}

void CQFT::qft(complex **qSignal, int matrixSize){

	complex (**qftMatrix) = new complex*[matrixSize];
	for (int i = 0; i < matrixSize; i++){
		qftMatrix[i] = new complex[matrixSize];		
	}

	qftOperator(qftMatrix, matrixSize);

	complex (**auxiliary) = new complex*[matrixSize];
	for (int i = 0; i < matrixSize; i++){
		auxiliary[i] = new complex[matrixSize];		
	}

	for(int i = 0; i < matrixSize; i++) 
		for(int j = 0; j < matrixSize; j++)
			for(int k = 0; k < matrixSize; k++)
				auxiliary[i][j] += (qftMatrix[i][k])*(qSignal[k][j]);
	
	for (int i = 0; i < matrixSize; i++)
		qSignal[i] = new complex[matrixSize];	// Zerando a matrix para que seja possível preenchê-la novamente	
	

	for(int i = 0; i < matrixSize; i++) 
		for(int j = 0; j < matrixSize; j++)
			for(int k = 0; k < matrixSize; k++)
				qSignal[i][j] += (auxiliary[i][k])*(qftMatrix[k][j].conjugate());

}

void CQFT::qftOperator(complex **qftOp, int N){
	double aux; 
	
	for(int i = 0; i < N; i++)
		for(int j = 0; j< N; j++){
			qftOp[i][j] = complex((double) (1/sqrt((float) N))*cos(2*PI*i*((float) j/((int) N))), (double) (1/sqrt((float) N))*sin(2*PI*i*((float) j/((int) N))));
			
			if(fabs(qftOp[i][j].re()) < 0.00001){
				aux = qftOp[i][j].im();
				qftOp[i][j] = complex(0, aux);
			}
			if(fabs(qftOp[i][j].im()) < 0.00001){
				aux = qftOp[i][j].re();
				qftOp[i][j] = complex(aux, 0);
			}

		}

	
}

int CQFT::createQFTOutput(complex **qSignal,int matrixSize, std::string path){
	try{
		ofstream data(path + "./output/output_qft.txt", ios::out); //Abre o arquivo output.txt

		if (data.is_open()){
			for(int i=0; i < matrixSize; i++){
				for (int j=0; j < matrixSize; j++){
					data << "(" << qSignal[i][j].re() << "," << qSignal[i][j].im() << ")";				 
					if (j + 1 == matrixSize&&(i+1 != matrixSize)) {
						data << ";\n";
					} else if ((j+1 == matrixSize)&&(i+1 == matrixSize)) {
						data << "!";					
					}
					else {
						data << "\n";
					}
				}
			}
			
			
			//Fechando os arquivos
			data.close();
		}
	 } catch (ifstream::failure e){
		return 1;

	}
	return 0;


}


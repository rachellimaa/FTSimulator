#ifndef _DATAMANAGEMENT_H_
#define _DATAMANAGEMENT_H_

class DataManagement{
	public:
		DataManagement();
		~DataManagement();
		processInputFile();
		createOutputFile();
	private:
		ofstream real_input, imaginario_input, real_fft, imaginario_fft;
		ofstream output;
};

#endif
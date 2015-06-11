#include "FTSimulatorMainGUI.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	
	FTSimulator2014::FTSimulatorMainGUI janelaPrincipal;
	Application::Run(%janelaPrincipal);
}


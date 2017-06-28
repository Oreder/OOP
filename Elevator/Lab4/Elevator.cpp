// Lab4.cpp : main project file.

#include "stdafx.h"
#include "Form1.h"
#include "Logger.h"

using namespace Elevator;

[STAThreadAttribute]
int main(array<System::String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	auto mainForm = gcnew MainForm();
	Logger::mainForm = mainForm;

	Application::Run(mainForm);
	return 0;
}

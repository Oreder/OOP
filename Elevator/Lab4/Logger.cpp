#include "stdafx.h"
#include "Logger.h"

#include "Form1.h"

namespace Elevator
{
	void Logger::Log(String^ msg)
	{
		((MainForm^)mainForm)->logTextBox->Text += msg + "\r\n";
	}
};
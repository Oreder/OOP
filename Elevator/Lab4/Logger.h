#pragma once

namespace Elevator
{
	using namespace System::Windows::Forms;

	public ref class Logger
	{
	public:
		static Form^ mainForm;
		static void Log(System::String^ msg);
	};
};
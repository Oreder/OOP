// Test_11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Source.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Rect HCN;

	HCN.setLength(12);
	HCN.setWidth(18);

	std::cout << "Area: " << HCN.area() <<std::endl;

	HCN.~Rect();

	system("pause");
	return 0;
}


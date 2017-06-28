#include "chicken.h"
#include <iostream>
using namespace std;

chicken::chicken()
{
	cout << "Khanh\n";
}


chicken::~chicken()
{
	if (getChicken)
	{
		getChicken = nullptr;
	}
	cout << "Sheep!\n";
}


chicken * chicken::getChicken = nullptr;


chicken * chicken::requestGetChicken()
{
	if (getChicken == nullptr)
	{
		getChicken = new chicken();
	}

	return getChicken;
}
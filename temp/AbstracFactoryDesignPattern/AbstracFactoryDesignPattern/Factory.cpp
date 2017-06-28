#include "Factory.h"
#include <iostream>

GUI * Factory::createGUI(const char * type)
{
	GUI * tmp = nullptr;
	if (type == "C")
		tmp = new Chicken;
	else if (type == "S")
		tmp = new Sheep;
	else if (type == "E")
		tmp = new Elephant;

	return tmp;
}

void Chicken::say()
{
	std::cout << "Chicken\n";
}

void Sheep::say()
{
	std::cout << "Sheep\n";
}

void Elephant::say()
{
	std::cout << "Elephant\n";
}
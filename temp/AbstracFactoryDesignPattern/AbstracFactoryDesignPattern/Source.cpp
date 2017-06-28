#include "Factory.h"
#include <iostream>

int main()
{
	// Create factory
	Factory f;

	// Create three pointer to our GUIs
	GUI * PC;
	GUI * PS;
	GUI * PE;

	// Create the concrete types
	PC = f.createGUI("C");
	PS = f.createGUI("S");
	PE = f.createGUI("E");

	// Call the say() functions of each one
	PC->say();
	PS->say();
	PE->say();

	// Delete all items
	delete PC;
	delete PS;
	delete PE;
	
	system("pause");
	return 0;
}
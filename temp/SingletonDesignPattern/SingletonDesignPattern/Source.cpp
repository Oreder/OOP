#include "chicken.h"
#include <iostream>
using namespace std;

int main()
{
	chicken *p1, *p2;

	p1 = chicken::requestGetChicken();
	p2 = chicken::requestGetChicken();

	printf("\nAddress of first chicken: %p\n", p1);

	p1 = nullptr;
	printf("\nAddress of first chicken: %p\n", p1);

	p1 = chicken::requestGetChicken();
	
	printf("\nAddress of first chicken: %p\n", p1);
	printf("Address of second chicken: %p\n", p2);

	system("pause");

	return 0;
}
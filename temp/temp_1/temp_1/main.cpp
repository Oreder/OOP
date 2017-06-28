#include "temp.h"
#include <iostream>
using namespace std;

void setArr(Array<int> *p)
{
	for (int i = 0; i < p->getSize(); i++)
	{
		p->operator*(i) = i + 1;
		//p->operator[](i) = i + 1;
	}
}

int main()
{
	Array<int> a(5);
	setArr(&a);

	for (int i = 0; i < a.getSize(); i++)
		cout << a[i] << " ";

	system("pause");
	return 0;
}
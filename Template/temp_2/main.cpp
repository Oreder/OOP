#include "set.h"
//#include "test.h"
#include "exceptions.h"
#include <iostream>

int main()
{
	try 
	{
		const Set_t<int> a(5, 6, -2, 7, 5, 1);

		std::cout << a <<std::endl;

		const Set_t<int> b(3, 0, -1, -2);

		std::cout << b << std::endl;

		Set_t<int> c = a - b;

		c += 6;
		c -= 4;
		c.add(b);

		std::cout << c << std::endl;

		std::cout << a + b <<std::endl;

		std::cout << c * a <<std::endl;
		//printf("Size: %d\n\n", b.getSize());
		//PrintSet(a, TInt);
	}
	catch (MExceptionBase &err)
	{
		printf("\n== Exception: %s\n", err.what());
	}

	system("pause");
	return 0;
}
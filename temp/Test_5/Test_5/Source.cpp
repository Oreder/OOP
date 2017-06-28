#include <iostream>

int main()
{
	int x1 = 100, x2 = 0;
	std::cout << "#: " << x1 << " : " << x2 << "\n";

	_asm
	{
		push x1
		push x2
		pop	 x1
		pop  x2
	}

	std::cout << "#: " << x1 << " : " << x2 << "\n";
	system("pause");
	return 0;
}
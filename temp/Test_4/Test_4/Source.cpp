#include <iostream>

int main()
{
	int counter = 4;
	short dec;

	while (1)
	{
		std::cout << "Input number from 0 to 15: ";
		std::cin >> dec;

		std::cout << "Binary type: ";
		while (counter)
		{
			if (dec & 8)
				std::cout << 1;
			else
				std::cout << 0;
			dec = dec << 1;
			counter--;
		}

		std::cout << '\n';
		counter = 4;
	}

	system("pause");
	return 0;
}
#include <iostream>

union
{
	unsigned char data;
	struct
	{
		unsigned char low : 4;
		unsigned char high : 4;
	} binary;
} bcd;

int main()
{
	bcd.data = 16;

	std::cout << "# Data: " << (int)bcd.data << std::endl;

	std::cout << "# High: " << (int)bcd.binary.high <<std::endl;

	std::cout << "# Low : " << (int)bcd.binary.low << std::endl;

	system("pause");
	return 0;
}
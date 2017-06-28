#include <iostream>
double POW(double x, int n)
{
	double res = 1.0; 
	for (int i = 1; i < n; i++)
		res *= x;
	return res;
}


int main()
{
	for (int i = 1; i < 25; i++)
		std::cout << "#" << i << " " << (int)(POW(sqrt(2.0) + 1, i)) <<"\n";

	system("pause");
	return 0;
	

}
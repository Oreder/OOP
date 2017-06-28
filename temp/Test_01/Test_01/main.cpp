#include <iostream>
using namespace std;

int main()		// Pythagore numbers
{
	int n, k = 0;
	cout << "Input N: ";
	cin >> n;
	cout << "\nResult:\n";

	for (int x = 1; x < n; x++)
		for (int y = x + 1; y < n; y++)
			for (int z = (int)sqrt(pow(x, 2) + pow(y, 2)); z < n; z++)
			{
				if (pow(x, 2) + pow(y, 2) == pow(z, 2))
				{
					k++; printf("#%2d (", k);
					cout << x << ", " << y << ", " << z << ")\n";
				}
			}
	
	if (!k)
		cout << "> Nothing was found!\n";

	getchar(); getchar();
	return 0;
}
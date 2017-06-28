#include "Header.h"

int main()
{
	//int *arr = new int[10];
	//for (int i = 0; i < sizeof(arr); i++)
		//*(arr + i) = i + 1;
	int arr[] = { 1, 5, 3, -2, 4, 7 };

	print_1(arr, 6);

	print_2(*arr, 6);

	//delete[] arr;
	system("Pause");
	return 0;
}
#include <iostream>// <stdio.h>
//#include <stdlib.h>
//using namespace std;


int* create_array(const int n)
{
	int *tmp = new int[n];
	return tmp;
}

void print_array(const int *a, const int size)
{
	std::cout << "ARRAY: ";
	for (int i = 0; i < size; i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;
}

void set_array(int *a, const int n)
{
	for (int i = 0; i < n; i++)
		a[i] = i + 1;
}

void free_array(int *a)
{
	delete[] a;
}

void swap(int &a, int &b)
{
	int tmp = a; a = b; b = tmp;
}

int main()
{
	int n, m;

	std::cout << "Input: ";
	std::cin >> n >> m;

	if (n <= 0)
		printf("Error #1: Invalid input!\n");
	else
		printf("");

	//int *a = (int*) malloc(12 * sizeof(int));
	int *a = create_array(n);
	
	set_array(a, n);

	print_array(a, n);

	free_array(a);

	//delete [] a;

	swap(n, m);
	std::cout << n << " : " << m << std::endl;

	system("pause");
	//getchar(); getchar();
	return 0;
}
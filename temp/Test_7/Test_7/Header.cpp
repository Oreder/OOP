#include "Header.h"

void print_1(int arr[], const size_t n)
{
	std::cout << "#1: ";
	for (int j = 0; j < n; j++)
		std::cout << arr[j] << " ";
	std::cout << "\n";
}

void print_2(int &arr, const size_t n)
{
	std::cout << "#2: ";
	for (int j = 0; j < n /* sizeof(arr) */; j++)
		std::cout << *(&(arr) + j) << " ";
	std::cout << "\n";
}
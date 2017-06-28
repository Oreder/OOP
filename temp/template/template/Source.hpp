#pragma once

#include <iostream>
using namespace std;

template <typename T>
Set_t<T>:Set_t(int temp_size)
{
	data = new T[temp_size];
	size = temp_size;
}

template <typename T>
Set_t<T>::~Set_t()
{
	delete []data;
	size = 0;
}

template <typename T>
Set_t<T>::Set_t(const Set_t& tmp)
{
	size = tmp.size;
	for (int i = 0; i < size; i++)
	    data[i] = tmp.data[i];
}

template <typename T>
void Set_t<T>::print()
{
	for (int i = 0; i < size; i++)
	    cout << "Template data: " << data[i] << endl;
}
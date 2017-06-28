#include "temp.h"
#include <assert.h>

template <typename T>
Array<T>::Array()
{
	this->size = 0;
	this->arr = nullptr;
}

template <typename T>
Array<T>::Array(int n)
{
	this->size = n;
	this->arr = new int[n];
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->arr;
}

template <typename T>
void Array<T>::Erase()
{
	delete[] this->arr;
	// We need to make sure we set m_pnData to 0 here, otherwise it will
    // be left pointing at deallocated memory!
	this->arr = nullptr;
	this->size = 0;
}

template <typename T>
T& Array<T>::operator[](int index)
{
	assert(index >= 0 && index < Array<T>::size);
	return Array<T>::arr[index];
}

template <typename T>
T& Array<T>::operator*(int index)
{
	assert(index >= 0 && index < Array<T>::size);
	return *(Array<T>::arr + index);
}

template <typename T>
int Array<T>::getSize()
{
	return this->size;
}
#ifndef __TEMP_H__
#define __TEMP_H__

template <typename T>
class Array
{
private:
	int size;
	int *arr;
public:
	Array();
	Array(int n);
	~Array();
	void Erase();
	T& operator[](int index);
	T& operator *(int index);
	int getSize();
};

#include "code.hpp"

#endif
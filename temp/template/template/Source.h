#pragma once
//#ifndef __SOURCE_H__
//#define __SOURCE_H__

template <typename T>
class Set_t
{
public:
	~Set_t();
	Set_t(int size);
	Set_t(const Set_t& tmp);
	void print();

	template <typename T2>
	friend ostream& Set_t<T2>::operator <<(ostream &s, const Set_t<T2> &tmp);

private:
	T *data;
	size_t = size;
};


#include "Source.hpp"

//#endif
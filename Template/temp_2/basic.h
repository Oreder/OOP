#ifndef __BASIC_H__
#define __BASIC_H__

class Set_Basic
{
public:
	Set_Basic();

	size_t getSize() const;
	bool isEmpty() const;

protected:
	virtual void setMaxSize(size_t maxSize) = 0;	

	size_t _size;
	size_t _maxSize;
};

#include "basic.hpp"
#endif
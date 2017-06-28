#include "basic.h"

Set_Basic::Set_Basic(): _size(0), _maxSize(0){}

size_t Set_Basic::getSize() const
{
	return _size;
}

bool Set_Basic::isEmpty() const
{
	return (_size == 0);
}
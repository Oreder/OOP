#include "MBase.h"

MBase::MBase()
	: size(0)
	, maxsize(0)
{ }

size_t MBase::getSize() const
{
	return size;
}

bool MBase::isEmpty() const
{
	return (size == 0);
}
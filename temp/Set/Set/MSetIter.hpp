#include "MSetIter.h"

#include "MException.h"


template <typename T>
MSetIter<T>::MSetIter(const MSet<T>& set) 
	: pset(&set) 
	, cur(0) 
{ }

template <typename T>
MSetIter<T>::~MSetIter()
{ }

template <typename T>
const T& MSetIter<T>::value() const
{
	if (!valid())
	{
		throw MExcOutOfRange();
	}

	return pset->arr[cur];
}

template <typename T>
const T& MSetIter<T>::operator * () const 
{
	return value();
}

template <typename T>
bool MSetIter<T>::valid() const
{
	return (cur >= 0) && (cur < pset->size);
}

template <typename T>
bool MSetIter<T>::next()
{
	cur++;
	return valid();
}

template <typename T>
bool MSetIter<T>::operator ++ ()
{
	return next();
}

template <typename T>
bool MSetIter<T>::prev()
{
	cur--;
	return valid();
}

template <typename T>
bool MSetIter<T>::operator -- ()
{
	return prev();
}

template <typename T>
bool MSetIter<T>::equal(const MSetIter<T>& other) const
{
	if (pset != other.pset)
	{
		throw MExcObjectPointer();
	}

	return (cur == other.cur);
}

template <typename T>
bool MSetIter<T>::operator == (const MSetIter<T>& other) const
{
	return equal(other);
}

template <typename T>
bool MSetIter<T>::operator != (const MSetIter<T>& other) const
{
	return !equal(other);
}
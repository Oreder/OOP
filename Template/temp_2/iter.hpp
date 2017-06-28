#include "iter.h"
#include "exceptions.h"

template <typename T>
SetIter<T>::SetIter(const Set_t<T>& set): pset(&set), cur(0){}

template <typename T>
SetIter<T>::~SetIter(){}

template <typename T>
const T& SetIter<T>::value() const
{
	if (!valid())
	{
		throw MExcOutOfRange();
	}

	return pset->arr[cur];
}

template <typename T>
const T& SetIter<T>::operator * () const 
{
	return value();
}

template <typename T>
bool SetIter<T>::valid() const
{
	return (cur >= 0) && (cur < pset->size);
}

template <typename T>
bool SetIter<T>::next()
{
	cur++;
	return valid();
}

template <typename T>
SetIter<T>& SetIter<T>::operator ++ ()
{
	cur++;
	if (!valid())
		cur--;

	return *this;
}

template <typename T>
SetIter<T> SetIter<T>::operator ++(int)
{
	SetIter<T> ret(*this);
	this->next();
    return ret;
}

template <typename T>
bool SetIter<T>::prev()
{
	cur--;
	return valid();
}

template <typename T>
SetIter<T>& SetIter<T>::operator -- ()
{
	cur--;
	if (!valid())
		cur++;
	return *this;
}

template <typename T>
SetIter<T> SetIter<T>::operator --(int)
{
	SetIter<T> ret(*this);
	this->prev();
    return ret;
}

template <typename T>
bool SetIter<T>::equal(const SetIter<T>& other) const
{
	if (pset != other.pset)
	{
		throw MExcObjectPointer();
	}

	return (cur == other.cur);
}

template <typename T>
bool SetIter<T>::operator == (const SetIter<T>& other) const
{
	return equal(other);
}

template <typename T>
bool SetIter<T>::operator != (const SetIter<T>& other) const
{
	return !equal(other);
}
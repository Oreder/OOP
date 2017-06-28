//#include "set.h"
#include <stdarg.h>

template <typename T>
Set_t<T>::Set_t()//: _size(0), _maxSize(0), _data(nullptr){}
{
	_size = 0;
	_maxSize = 0;
	_data = nullptr;
}

template <typename T>
void Set_t<T>::setMaxSize(size_t maxSize)
{
	if (maxSize < 0)
	{
		throw MExcInvalidSize();
	}
	else if (maxSize == 0)
	{
		delete[] _data;
		_size = 0;
		_maxSize = 0;
		_data = nullptr;
	}
	else
	{
		T* _newData = new T[maxSize];
		if (!_newData)
			throw MExcMemoryAlloc();

		size_t _needSize = maxSize;
		if (maxSize > _size)
			_needSize = _size;

		for (size_t i = 0; i < _needSize; i++)
			_newData[i] = _data[i];

		delete[] _data;
		
		_data = _newData;
		_maxSize = maxSize;
		if (_size > _maxSize)
			_size = _maxSize;
	}
}

template <typename T>
Set_t<T>::Set_t(size_t n, ...): _data(nullptr)
{
	if (n < 0)
		throw MExcInvalidSize();
	
	setMaxSize(n);
	
	va_list va;
	va_start(va, n);

	for (size_t i = 0; i < n; i++)
	{
		T tmp = va_arg(va, T);
		add(tmp);
	}

	va_end(va);
}

template <typename T>
Set_t<T>::~Set_t()
{
	if (_data)
		delete[] _data;
	
	_size = 0;
	_maxSize = 0;
	_data = nullptr;
}

template <typename T>
T Set_t<T>::getElement(size_t index) const
{
	if (index < 0 || index >= _size)
		throw MExcInvalidSize();
	
	return _data[index];
}

//
//template <typename T>
//Set_t<T>& Set_t<T>::operator [] (size_t index)
//{
//	return getElement(index);
//}

template <typename T>
Set_t<T>::Set_t(const Set_t &other): _data(nullptr)
{
	setMaxSize(other._size);
	
	for (size_t i = 0; i < _size; i++)
		_data[i] = other.getElement(i);
}

template <typename T>
Set_t<T>::Set_t(Set_t &&other): _data(nullptr)
{
	_size = other._size;
	_maxSize = other._maxSize;
	_data = other._data;
	
	other._size = 0;
	other._maxSize = 0;
	other._data = nullptr;	
}

template <typename T>
Set_t<T>& Set_t<T>::operator = (const Set_t<T>& other)
{
	if (_data)
		delete[] _data;
	
	_size = other._size;
	setMaxSize(other._maxSize);

	for (size_t i = 0; i < _size; i++)
		_data[i] = other.getElement(i);
	
	return *this;
}

template <typename T>
Set_t<T>& Set_t<T>::operator = (Set_t<T>&& other)
{
	if (_data)
		delete[] _data;

	_size = other._size;
	_maxSize = other._maxSize;
	_data = other._data;
	
	other._size = 0;
	other._maxSize = 0;
	other._data = nullptr;

	return *this;
}

template <typename T>
void Set_t<T>::expandSize()
{
	if (_size >= _maxSize)
	{
		if (_maxSize == 0)
			setMaxSize(8);
		else
		{
			size_t newSize = _maxSize * 2;
			setMaxSize(newSize);
		}
	}

	_size++;
}

template <typename T>
bool Set_t<T>::add(const T& element)
{
	if (!contain(element))
	{
		expandSize();
		_data[_size - 1] = element;

		return true;
	}

	return false;
}

template <typename T>
Set_t<T>& Set_t<T>::operator +=	(const T& element)
{
	add(element);

	return *this;
}

template <typename T>
bool Set_t<T>::remove(const T& element)
{
	size_t i;
	if (findElement(element, i))
	{
		_size--;
		_data[i] = _data[_size];
		return true;
	}
	return false;
}

template <typename T>
Set_t<T>& Set_t<T>::operator -= (const T& element)
{
	remove(element);

	return *this;
}

template <typename T>
bool Set_t<T>::remove(const Set_t<T>& other)
{
	bool removed = false;

	for (size_t i = 0; i < other._size; i++)
		removed = remove(other._data[i]) || removed;
	
	return removed;
}

template <typename T>
Set_t<T>& Set_t<T>::operator -= (const Set_t<T>& other)
{
	remove(other);
	return *this;
}

template <typename T>
bool Set_t<T>::contain(const T& element) const
{
	for (size_t i = 0; i < _size; i++)
	{
		if (_data[i] == element)
			return true;
	}
	return false;
}

template <typename T>
bool Set_t<T>::contain(const Set_t<T>& other) const
{
	if (_size < other.getSize())
		return false;

	for (size_t i = 0; i < other.getSize(); i++)
	{
		if (!contain(other.getElement(i)))
			return false;
	}
	
	return true;
}

template <typename T>
bool Set_t<T>::operator <= (const Set_t<T>& other) const
{
	return contain(other);
}

template <typename T>
bool Set_t<T>::operator < (const Set_t<T>& other) const
{
	return other.contain(*this) && !equal(other);
}

template <typename T>
bool Set_t<T>::operator > (const Set_t<T>& other) const
{
	return contain(other) && !equal(other);
}

template <typename T>
bool Set_t<T>::operator == (const Set_t<T>& other) const
{
	return equal(other);
}

template <typename T>
bool Set_t<T>::operator != (const Set_t<T>& other) const
{
	return equal(other);
}

template <typename T>
bool Set_t<T>::equal(const Set_t<T>& other) const
{
	return (_size == getSize(other)) && in(other);
}

template <typename T>
Set_t<T> Set_t<T>::join(const Set_t& other) const
{
	Set_t<T> retSet(*this);
	
	retSet.add(other);
	
	return retSet;
}

template <typename T>
Set_t<T> Set_t<T>::operator + (const Set_t& other) const
{
	return join(other);
}

template <typename T>
bool Set_t<T>::add(const Set_t &other)
{
	bool added = false;
	
	for (size_t i = 0; i < other._size; i++)
		added = add(other._data[i]) || added;
	
	return added;
}

template< typename T>
Set_t<T>& Set_t<T>::operator += (const Set_t& other)
{
	add(other);
	return *this;
}

template <typename T>
Set_t<T> Set_t<T>::subtract(const Set_t<T>& other) const
{
	Set_t<T> retSet(*this);
	
	retSet.remove(other);
	
	return retSet;
}

template <typename T>
Set_t<T> Set_t<T>::operator - (const Set_t<T>& other) const
{
	return subtract(other);
}

template <typename T>
Set_t<T> Set_t<T>::intersect(const Set_t<T>& other) const
{
	Set_t<T> retSet;

	for (size_t i = 0; i < this->getSize(); i++)
	{
		if (other.contain(this->getElement(i)))
			retSet.add(this->getElement(i));
	}

	return retSet;
}

template <typename T>
Set_t<T> Set_t<T>::operator * (const Set_t<T>& other) const
{
	return intersect(other);
}

template <typename T>
Set_t<T> Set_t<T>::sym(const Set_t& other) const
{
	Set_t<T> retSet;

	for (size_t i = 0; i < this->getSize(); i++)
	{
		if (other->contain(this->getElement(i) == false))
			retSet.add(this->getElement(i));
	}

	for (size_t i = 0; i < other->getSize(); i++)
	{
		if (this->contain(other.getElement(i)) == false)
			retSet.add(other.getElement(i));
	}

	return retSet;
}

template <typename T>
bool Set_t<T>::findElement(const T& element, size_t& index) const
{
	size_t i;
	for (i = 0;  i < _size && _data[i] != element; i++);

	return i < _size;
}

template <typename T>
std::ostream& operator << (std::ostream& s, const Set_t<T>& t)
{
	s << "# SET:";
	for (size_t i = 0; i < t.getSize(); i++)
		s << " " << t.getElement(i);

	return s;
}
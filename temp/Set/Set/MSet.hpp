#include "MSet.h"

#include "MException.h"
#include <stdarg.h>


	// Конструктор по умолчанию
template <typename T>
MSet<T>::MSet()
	: arr(nullptr)
{ }

	// Конструктор копирования
template <typename T>
MSet<T>::MSet(const MSet<T>& other)
	: arr(nullptr)
{
	setMaxSize(other.size);
	
	for (size_t i = 0; i < size; i++)
		arr[i] = other.arr[i];
}

	// Конструктор перемещения
template <typename T>
MSet<T>::MSet(MSet<T>&& other)
	: arr(nullptr)
{
	size = other.size;
	maxsize = other.maxsize;
	arr = other.arr;
	
	other.size = 0;
	other.maxsize = 0;
	other.arr = nullptr;
}

	// Задание множества перечислением
template <typename T>
MSet<T>::MSet(size_t n, ...)
	: arr(nullptr)
{
	if (n < 0)
	{
		throw MExcInvalidSize();
	}

	setMaxSize(n);

	va_list va;
    va_start(va, n);

	for (size_t i = 0; i < n; i++)
	{
		T el = va_arg(va, T);
		add(el);
	}

    va_end(va);
}

	// Деструктор
template <typename T>
MSet<T>::~MSet()
{
	freeArr();
}

//-----------------------------------------------------------------------------

	// Присваивание (копирование)
template <typename T>
MSet<T>& MSet<T>::operator =  (const MSet<T>& other)
{
	freeArr();
	
	setSize(other.getSize());
	
	for (size_t i = 0; i < size; i++)
		arr[i] = other.arr[i];
	
	return *this;
}

	// Присваивание (перемещение)
template <typename T>
MSet<T>& MSet<T>::operator =  (MSet<T>&& other)
{
	freeArr();
	
	size = other.size;
	maxsize = other.maxsize;
	arr = other.arr;
	
	other.size = 0;
	other.maxsize = 0;
	other.arr = nullptr;
	
	return *this;
}

	// Очистка множества
template <typename T>
void MSet<T>::clear()
{
	freeArr();
}

	// Добавление элемента
template <typename T>
bool MSet<T>::add(const T& elem)
{
	if (!contains(elem))
	{
		incSize();
		arr[size - 1] = elem;
		
		return true;
	}
	else
		return false;
}

template <typename T>
MSet<T>& MSet<T>::operator += (const T& elem)
{
	add(elem);
	
	return *this;
}

	// Удаление элемента
template <typename T>
bool MSet<T>::remove(const T& elem)
{
	size_t num;
	
	if (findElem(elem, num))
	{
		size--;
		arr[num] = arr[size];
		
		return true;
	}
	else
		return false;
}

template <typename T>
MSet<T>& MSet<T>::operator -= (const T& elem)
{
	remove(elem);
	
	return *this;
}

	// Добавление множества (к исходному)
template <typename T>
bool MSet<T>::add(const MSet<T>& other)
{
	bool added = false;
	
	for (size_t i = 0; i < other.size; i++)
		added = add(other.arr[i]) || added;
	
	return added;
}

template <typename T>
MSet<T>& MSet<T>::operator += (const MSet<T>& other)
{
	add(other);
	
	return *this;
}

	// Удаление множества (из исходного)
template <typename T>
bool MSet<T>::remove(const MSet<T>& other)
{
	bool removed = false;
	
	for (size_t i = 0; i < other.size; i++)
		removed = removed || remove(other.arr[i]);
	
	return removed;
}

template <typename T>
MSet<T>& MSet<T>::operator -= (const MSet<T>& other)
{
	remove(other);
	
	return *this;
}	

	// Содержится ли элемент в множестве
template <typename T>
bool MSet<T>::contains(const T& elem) const
{
	size_t num;
	
	return findElem(elem, num);
}

	// Содержит ли множество другое множество
template <typename T>
bool MSet<T>::contains(const MSet<T>& other) const
{
	if (size < other.size)
		return false;

	bool foundAll = true;
	
	for (size_t i = 0; i < other.size && foundAll; i++)
		if (!contains(other.arr[i]))
			foundAll = false;
		
	return foundAll;
}

template <typename T>
bool MSet<T>::operator <  (const MSet<T>& other) const
{
	return other.contains(*this);
}

template <typename T>
bool MSet<T>::operator >  (const MSet<T>& other) const
{
	return contains(other);
}						

	// Объединение множеств
template <typename T>
MSet<T> MSet<T>::join(const MSet<T>& other) const
{
	MSet<T> retSet(*this);
	
	retSet.add(other);
	
	return retSet;	
}

template <typename T>
MSet<T> MSet<T>::operator +  (const MSet<T>& other) const
{
	return join(other);
}

	// Вычитание множеств
template <typename T>
MSet<T> MSet<T>::subtract(const MSet<T>& other) const
{
	MSet<T> retSet(*this);
	
	retSet.remove(other);
	
	return retSet;
}

template <typename T>
MSet<T> MSet<T>::operator -  (const MSet<T>& other) const
{
	return subtract(other);
}

	// Пересечение множеств
template <typename T>
MSet<T> MSet<T>::intersect(const MSet<T>& other) const
{
	MSet<T> retSet();
	
	MSet* minSet, maxSet;
	
	if (this->size < other.size)
	{
		minSet = this;
		maxSet = &other;
	}
	else
	{
		minSet = &other;
		maxSet = this;
	}
	
	for (size_t i = 0; i < minSet.size; i++)
		if (maxSet.contains(minSet.arr[i]))
			retSet.add(minSet.arr[i]);
		
	return retSet;
}	

	// Проверка множеств на равенство
template <typename T>
bool MSet<T>::equal(const MSet<T>& other) const
{
	return (size == other.size) && contains(other);
} 

template <typename T>
bool MSet<T>::operator == (const MSet<T>& other) const
{
	return equal(other);
}

template <typename T>
bool MSet<T>::operator != (const MSet<T>& other) const
{
	return !equal(other);
}

//-----------------------------------------------------------------------------

template <typename T>
void MSet<T>::setMaxSize(size_t newSize)
{
	if (newSize < 0)
	{
		throw MExcInvalidSize();
	}
	else if (newSize == 0)
	{
		freeArr();
	}
	else
	{
		T* newArr = new T[newSize];
		if (!newArr)
		{
			throw MExcMemoryAlloc();
		}

		size_t minSize;
		if (newSize < size)
			minSize = newSize;
		else
			minSize = size;

		for (size_t i = 0; i < minSize; i++)
			newArr[i] = arr[i];

		delete [] arr;

		arr = newArr;
		maxsize = newSize;
		if (size > maxsize)
			size = maxsize;
	}
}

template <typename T>
void MSet<T>::incSize()
{
	if (size >= maxsize)
		grow();
	
	size++;
}

template <typename T>
void MSet<T>::grow()
{
	if (maxsize == 0)
	{
		setMaxSize(8);
	}
	else
	{
		size_t newSize = maxsize * 2;
		setMaxSize(newSize);
	}
}

template <typename T>
void MSet<T>::freeArr()
{
	if (arr)
		delete [] arr;
	
	arr = nullptr;
	size = 0;
	maxsize = 0;
}

template <typename T>
bool MSet<T>::findElem(const T& elem, size_t& num) const
{
	bool found = false;
	
	for (size_t i = 0; i < size && !found; i++)
		if (arr[i] == elem)
		{
			num = i;
			found = true;
		}
	
	return found;	
}

//-----------------------------------------------------------------------------

template <typename T>
std::ostream& operator << (std::ostream& os, const MSet<T>& set)
{
	for (size_t i = 0; i < set.size; i++)
		os << set.arr[i] << " ";

	return os;
}
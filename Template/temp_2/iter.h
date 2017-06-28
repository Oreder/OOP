#ifndef __ITER_H__
#define __ITER_H__

#include "set.h"

template <typename T>
class SetIter
{
	public:
		SetIter(const Set_t<T>& set);		
		~SetIter();

		const T& value() const;
		const T& operator * () const;

		SetIter& valid() const;

		bool next();
		SetIter& operator ++ ();
		SetIter operator ++(int);

		bool prev();
		SetIter& operator -- ();
		SetIter operator --(int);

		bool equal(const SetIter& other) const;
		bool operator == (const SetIter& other) const;
		bool operator != (const SetIter& other) const;

	private:
		const Set_t<T>* pset;
		size_t cur;
};

#include "iter.hpp"
#endif
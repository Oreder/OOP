#pragma once

#include "MSet.h"


template <typename T>
class MSetIter
{
	public:
		MSetIter(const MSet<T>& set);		
		~MSetIter();

		const T& value() const;
		const T& operator * () const;

		bool valid() const;

		bool next();
		bool operator ++ ();

		bool prev();
		bool operator -- ();

		bool equal(const MSetIter& other) const;
		bool operator == (const MSetIter& other) const;
		bool operator != (const MSetIter& other) const;

	private:
		const MSet<T>* pset;
		size_t cur;
};

#include "MSetIter.h"
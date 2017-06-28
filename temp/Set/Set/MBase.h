#pragma once


class MBase
{
	public:
		MBase();
		
		size_t getSize() const;
		bool isEmpty() const;
		
	protected:
		virtual void setMaxSize(size_t newSize) = 0;		
	
		size_t size;
		size_t maxsize;
};

#include "MBase.hpp"
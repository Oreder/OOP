#pragma once

#include <exception>


class MExceptionBase : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return "Base exception";
		}
};

//-----------------------------------------------------------------------------

class MExcOutOfRange : public MExceptionBase
{
	public:
		virtual const char* what() const throw()
		{
			return "Out of range";
		}
};

class MExcObjectPointer : public MExceptionBase
{
	public:
		virtual const char* what() const throw()
		{
			return "Pointers to different objects";
		}
};

class MExcMemoryAlloc : public MExceptionBase
{
	public:
		virtual const char* what() const throw()
		{
			return "Memory allocation error";
		}
};

class MExcInvalidSize : public MExceptionBase
{
	public:
		virtual const char* what() const throw()
		{
			return "Invalid size";
		}
};

class MExcNoElement : public MExceptionBase
{
	public:
		virtual const char* what() const throw()
		{
			return "No elements";
		}
};
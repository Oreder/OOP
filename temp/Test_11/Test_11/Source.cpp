#include "stdafx.h"
#include "Source.h"

Rect::Rect()
{
	std::cout << "Initialized!" << std::endl;
}

Rect::~Rect()
{
	std::cout << "Free!" << std::endl;
}


void Rect::setLength(int x)
{
	length = x;
}

int Rect::getLength()
{
	return length;
}

void Rect::setWidth(int x)
{
	width = x;
}

int Rect::getWidth()
{
	return width;
}

int Rect::area()
{
	if (length <= 0 || width <= 0)
	{
		std::cout << "Error #1: SIZE ERROR!\n";
		return -1;
	}

	return length * width;
}
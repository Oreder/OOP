#ifndef __SOURCE_H__
#define __SOURCE_H__
#include <iostream>

class Rect
{
	private:
		int length, width;

	public:
		Rect();		// constructor
		~Rect();	// deconstructor
		
		void setLength(int);	// GET - SET: data between private and another class
		int getLength();

		void setWidth(int);
		int getWidth();

		int area();		// function
};

#endif
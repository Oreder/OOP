#ifndef __SET_H__
#define __SET_H__
#include <iostream>
#include "exceptions.h"
#include "basic.h"
//using namespace std;

template <typename T>
class Set_t: public Set_Basic
{
public:
	Set_t();								// Constructor initialization
	Set_t(size_t n, ...);					// Constructor given set by arguments
	Set_t(const Set_t &other);				// Constructor copy from another set
	Set_t(Set_t && other);					// Constructor copy from another set
	~Set_t();								// Destructor

	Set_t& operator = (const Set_t& other);
	Set_t& operator = (Set_t&& other);

	T getElement(size_t index) const;				// Get element
	//Set_t& operator [](size_t index);

	bool add(const T& element);				// Add element
	bool add(const Set_t& other);			// Add set
	bool remove(const T& element);			// Remove element
	bool remove(const Set_t& other);		// Remove set
	bool contain(const T& element) const;			// Contain element
	bool contain(const Set_t& other) const;			// Check subset
	bool equal(const Set_t& other) const;

	Set_t join(const Set_t& other) const;			// Join sets
	Set_t subtract(const Set_t& other) const;		// Subtract sets
	Set_t intersect(const Set_t& other) const;		// Intersection
	Set_t sym(const Set_t& other) const;			// Symmetric difference of two sets


	Set_t& operator +=	(const T& element);
	Set_t& operator +=  (const Set_t& other);
	Set_t& operator -=	(const T& element);
	Set_t& operator -=  (const Set_t& other);

	bool operator <= (const Set_t& other) const;
	bool operator <	(const Set_t& other) const;		// Check inequality
	bool operator >	(const Set_t& other) const;
	
	bool operator == (const Set_t& other) const;	// Check equality
	bool operator != (const Set_t& other) const;
	
	Set_t operator + (const Set_t& other) const;
	Set_t operator - (const Set_t& other) const;
	Set_t operator * (const Set_t& other) const;	
	//Set_t operator >< (const Set_t& other);

	template <typename T>
	friend class SetIter;

	template <typename T2>
	friend std::ostream& operator << (std::ostream &s, const Set_t<T2> &t);	

private:
	T* _data;
	void expandSize();
	bool findElement(const T& element, size_t& index) const;
	void setMaxSize(size_t newSize);
};

#include "set.hpp"
#endif
#pragma once

#include "MBase.h"
#include <iostream>


template <typename T>
class MSet : public MBase
{
	template <typename T>
	friend class MSetIter;

	template <typename T>
	friend std::ostream& operator << (std::ostream& os, const MSet<T>& set);
	
	public:
		MSet();
		MSet(const MSet& other); 	// Конструктор копирования
		MSet(MSet&& other); 		// Конструктор перемещения
		MSet(size_t n, ...);		// Задание множества перечислением
		~MSet();					// Деструктор
		
			// Присваивание
		MSet& operator =  (const MSet& other);		// Копирование
		MSet& operator =  (MSet&& other);			// Перемещение
		
			// Очистка множества
		void clear(); 
		
			// Добавление элемента
		bool add(const T& elem);
		MSet& operator += (const T& elem);
		
			// Удаление элемента
		bool remove(const T& elem);
		MSet& operator -= (const T& elem);
		
			// Добавление множества (к исходному)
		bool add(const MSet& other);
		MSet& operator += (const MSet& other);
		
			// Удаление множества (из исходного)
		bool remove(const MSet& other);
		MSet& operator -= (const MSet& other);	
		
			// Содержится ли элемент в множестве
		bool contains(const T& elem) const;
		
			// Содержит ли множество другое множество
		bool contains(const MSet& other) const;
		bool  operator <  (const MSet& other) const;
		bool  operator >  (const MSet& other) const;						
		
			// Объединение множеств
		MSet join(const MSet& other) const;
		MSet  operator +  (const MSet& other) const;
		
			// Вычитание множеств
		MSet subtract(const MSet& other) const;
		MSet  operator -  (const MSet& other) const;
		
			// Пересечение множеств
		MSet intersect(const MSet& other) const; 		
		
			// Проверка множеств на равенство
		bool equal(const MSet& other) const; 
		bool  operator == (const MSet& other) const;
		bool  operator != (const MSet& other) const;			
	
	private:
		void setMaxSize(size_t newSize);
		void incSize();
		void grow();
		void freeArr();
		
		bool findElem(const T& elem, size_t& num) const;
	
		T *arr;
};

#include "MSet.hpp"
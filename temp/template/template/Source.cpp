#include <iostream>
using namespace std;

template <typename T>
Set_t<T>::~Set_t()
{
	data = 0;
}

template <typename T>
Set_t<T>::Set_t(const T& tmp)
{
	data = tmp;
}

template <typename T>
void Set_t<T>::print()
{
	cout << "Template data: " << data << endl;
}
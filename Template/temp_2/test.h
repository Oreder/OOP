#pragma once

enum eType {TInt, TChar, TDouble};

template <typename T>
void PrintSet(const Set_t<T> pSet, eType type);

#include "test.hpp"
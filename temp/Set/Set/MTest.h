#pragma once

#include "MSet.h"

class MTest
{
public:
	char c;
};

enum eType {TInt, TDouble, TClass};

void PrintSet(const MBase *set, eType type);

#include "MTest.hpp"
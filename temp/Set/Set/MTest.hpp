#include "MTest.h"

MSet<int> IntInitialize(int n)
{
	MSet<int> temp(n);
	for (int i = 0; i < n; i++)
		temp.add(i+1);
	return temp;
}

void PrintSet(const MBase *set, eType type)
{
	int n = set->getSize();

	if (n < 0)
		printf("Notice: Size of set is now smaller than 0!\n");
	
	else if (n == 0)
		printf("Notice: Set is now empty!\n");
	
	else
	{
		printf("#SET: {");

		switch(type)
		{
		case TInt:
			{
				const MSet<int> *pSet = static_cast<const MSet<int> *>(set);
				for (int i = 0; i < n - 1; i++)
					printf(" %d, ");
			}
		}
	}
}

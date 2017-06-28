#include "test.h"
#include <stdio.h>

template <typename T>
void PrintSet(const Set_t<T> pSet, eType type)
{
	size_t n = pSet.getSize();

	if (n < 0)
		printf("# Notice: Size of set is smaller than 0!\n");
	else if (n == 0)
		printf("# Notice: Set is now empty!\n");
	else
	{
		printf("# SET: ");

		switch (type)
		{
		case TInt:
			for (size_t i = 0; i < n; i++)
				printf("%d ", pSet.getElement(i));
			break;

		case TChar:
			for (size_t i = 0; i < n; i++)
				printf("%c ", pSet.getElement(i));
			break;

		case TDouble:
			for (size_t i = 0; i < n; i++)
				printf("%.2f ", pSet.getElement(i));
			break;
		
		default:
			printf("Unknown type!");
			break;
		}

		printf("\n");
	}
}
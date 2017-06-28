// Test_3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

#define Nmax 100
int main()
{
	char str[Nmax] = "4444 4444 1 22 55555 333";
	std::cout << "Input string: " << str;

	int i = 0, imin = 0, imax = 0, lmin = Nmax, lmax = 0,
		n = 0, L_all = strlen(str);
	
	while (1)
	{
		while (str[i] == ' ' && str[i] != '\0')
			i++;
		
		if (i == L_all)		// end string
			break;
		
		int j = i;	// save first position
		while (str[i] != ' ' && str[i] != '\0')
			i++;		// until last character of word
		
		n++;	// count number words
		if (n == 1)
		{
			lmin = i - j;	// first word case
			lmax = lmin;
		}
		else
		{
			if (i - j < lmin)
			{
				lmin = i - j;
				imin = j;		// indentify SHORT word
			}

			if (i - j > lmax)
			{
				lmax = i - j;
				imax = j;
			}
		}
	}

	/* STEP 2: SWAP STRINGS */
	char out[Nmax], *short_word =  "";
	
	for (int i = imin; i < lmin; i++)
		short_word[i - imin] = str[i];

	std::cout << "SHORT: " << short_word;
	
	system("pause");
	return 0;
}


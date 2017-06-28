#include <string.h>
#include <stdlib.h>
#include <iostream>
#define Nmax 100

int main()
{
	const char str[Nmax] = "Hello how are you, I am fine";
	
	/* STEP 1: IDENTIFY SHORT AND LONG STRINGS */
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
	char *out = (char *)malloc((L_all + 1) * sizeof(char));
	int p1 = imin, p2 = imax, L1 = lmin, L2 = lmax;
	
	if (imin > imax)
	{
		p1 = imax; p2 = imin;		// save position of LONG and SHORT
		L1 = lmax; L2 = lmin;
	}
	
	i = 0;		// copy string
	for (; i < p1; i++)
		out[i] = str[i];

	for (int j = p2; j < p2 + L2; j++)
		out[i++] = str[j];

	for (int j = p1 + L1; j < p2; j++)
		out[i++] = str[j];

	for (int j = p1; j < p1 + L1; j++)
		out[i++] = str[j];

	for (; str[i] != '\0'; i++)
		out[i] = str[i];

	out[L_all] = '\0';			// set end of string
	
	std::cout << "[INPUT]  String: " << str << "\n";
	std::cout << "[OUTPUT] String: " << out << "\n";
	free(out);
	system("pause");
	return 0;
}


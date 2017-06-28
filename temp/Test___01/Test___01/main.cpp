#include <stdio.h>
#include <math.h>

int main()
{
	/*int n, k = 0;
	printf("Input N: ");
	scanf("%d", &n);

	for (int i = 1; i < (int)sqrt((double)n); i++)
	{
		if ((n % i) == 0)
		{
			printf("# (%d: %d)\n", i, n/i);
			k++;
		}
	}

	printf("\n# TOTAL PAIRS (a, b): %d\n", k);*/

	int n;
	printf("Input N: ");
	scanf("%d", &n);

	int tmp = (int)sqrt((double)n);
	if (n == tmp * tmp)
		printf("# %d is a Square number!", n);
	else
		printf("# %d is not a Square number!", n);

	getchar();
	getchar();
	return 0;
}
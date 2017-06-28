#include <iostream>
#include <string.h>
#define Nmax 100

void input(char[], size_t);
void output(const char[]);
void test_copy(char[], const char[]);
void set_lower(char[]);
void set_upper(char[]);

int main()
{
	// INPUT - OUTPUT
	char *str = new char[Nmax + 1];
	input(str, Nmax + 1);
	output(str);
	
	// COPY STRING		
	/* char *tmp = new char[12];
	 * test_copy(tmp, str);
	 * output(tmp);
	 * delete[] tmp;
	 */

	// UPPER - LOWER
	/* set_upper(str); output(str);
	 * set_lower(str); output(str);
	 */

	/*	char *s = "Hello world#";
	 *	strrev(s);
	 *	output(s);
	 */

	delete[] str;
	system("Pause");
	return 0;
}

void input(char str[], size_t length)
{
	std::cout << "Input string: ";
	std::cin.getline(str, length);
}

void output(const char str[])
{
	std::cout << "# Length: " << strlen(str) << std::endl;
	std::cout << "# String: " << str << std::endl;
}

/*	======= NOT WORK ========
void test_copy(char dest[], const char src[])
{
	strcpy(dest, src);
}

void set_lower(char src[])
{
	strlwr(src);
}

void set_upper(char src[])
{
	strupr(src);
}
*/
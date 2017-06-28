#include <iostream>
#include "Source.h"
using namespace std;

int main()
{
    Stack<int> s(5);
    s.push(12);
    s.push(1);
	s.push(100);
    cout << "Hello World: " << s.pop() << " and "<< s.pop() << endl;

    if (s.isEmpty())
        cout << "\nStack is empty\n\n";
	else
	{
		s.~Stack();
		//if (s.isEmpty())
			cout << "\nFree!\n\n";
	}
	system("pause");
    return 0;
}
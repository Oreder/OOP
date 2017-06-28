#include <iostream>

union Figure_t // 24
{
	struct Circle // 8
	{
		double R;
	} C;

	struct Rectangle  // 16
	{
		double height;
		double width;
	} R;

	struct Triangle // 24
	{
		double a, b, c;
	} T;
};

int main()
{
	Figure_t temp;
	
	printf("Size of union: %d\n\n", sizeof(temp.R));
	//temp.C.R = 3.0;
	
	temp.R.height = 10.0;
	temp.R.width = 5.0;
	
	//temp.T.a = 6.0;
	//temp.T.b = 4.0;
	temp.T.c = 5.0;

	printf("Value: %.2f\n", temp.C.R);
	printf("Rectangle's height: %.2lf\n", temp.R.height);

	printf("Rectangle's width: %.2lf\n", temp.R.width);
	printf("Last side: %.2lf\n", temp.T.c);

	Figure_t a[5];
	//std::cin<<
	//scanf("%f", &);

	system("pause");
	return 0;
}
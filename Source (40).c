#include <stdio.h>

int power(int base, int exponent);

int main()
{
	int num1=2, num2=3;
	
	printf("%d", power(num1, num2));
	getch();
	return 0;
}

int power(int base, int exponent)
{
	if (exponent == 1)
		return  base;
	else
		return base*power(base, exponent - 1);
}
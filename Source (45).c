//Greatest Common Divisor
#include <stdio.h>

int GCD(int x, int y);

int main()
{
	int num1,num2;
	printf("Write two numbers: ");
	scanf_s("%d%d", &num1, &num2);
	printf("The GCD is %d ",GCD(num1,num2));

	getch();
	return 0;
}

int GCD(int x, int y)
{
	int min,GCD1;
	min = x;
	if(y<x)
	{
		min = y;
	}
	for (int i = 1; i <= min; i++)
	{
		if (x%i == 0 && y%i == 0)
		{
			GCD1 = i;
		}
	}
	return GCD1;
}
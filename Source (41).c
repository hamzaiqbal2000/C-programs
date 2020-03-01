#include <stdio.h>

int GCD(int x, int y);

int main()
{
	int num1, num2;
	printf("Write two numbers: ");
	scanf_s("%d%d", &num1, &num2);
	printf("\nThe GCD is %d", GCD(num1, num2));

	getch();
	return 0;
}

int GCD(int x, int y)
{
	for (int i; x != y; i++)
	{
		if (x > y)
		{
			return GCD(x - y, y);
		}
		else
		{
			return GCD(x, y - x);
		}
	}
	return x;
}
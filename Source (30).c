#include <stdio.h>

int main()
{
	int a[10], i;
	printf("Enter 10 numbers: ");
	for (i = 0; i <= 9; i++)
	scanf_s("%d", &a[i]);
	int min=a[0];
	for (i = 1; i <= 9; i++)
	{
		if (min < a[i])
			min = a[i];
	}

	printf("Smallest Number:%d", min);

	getch();
	return 0;
}
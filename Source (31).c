#include <stdio.h>

int main()
{
	int arr[10], i,se=0,so=0;
	printf("Enter 10 numbers: ");
	for (i = 0; i <= 9; i++)
		scanf_s("%d", &arr[i]);

	for (i = 0; i <= 9; i++)
	{
		if (arr[i] % 2 == 0)
			se = se + arr[i];
		else
			so = so + arr[i];
	}
	printf("Sum of even:%d", se);
	printf("\nSum of odd:%d", so);
	getch();
	return 0;
}
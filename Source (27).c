#include <stdio.h>

void Average();

int main()
{
	Average();
	getch();
	return 0;
}

void Average()
{
	int a[4],i;
	float avg, sum = 0.0;
	printf("Enter 4 numbers: ");
	for (i = 0; i <= 3; i++)
		scanf_s("%d", &a[i]);

	for (i = 0; i <= 3; i++)
		sum = sum + a[i];

	avg = sum / 4;
	printf("Average of the four numbers is:%.2f", avg);
}

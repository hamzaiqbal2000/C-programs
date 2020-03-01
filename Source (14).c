#include <stdio.h>

void printArray(int x[], int y, int z);

int main()
{
	int a[20],num1;
	printf("How many number you want to print:");
	scanf_s("%d", &num1);
	printf("Enter the numbers\n");
	for (int i = 0; i < num1; i++)
		scanf_s("%d", &a[i]);
	printArray(a, 0, num1);
	getch();
	return 0;
}


void printArray(int x[], int y, int z)
{
	if (y >= z)
		return;
	printf("%d ", x[y]);
	printArray(x, y + 1, z);
}

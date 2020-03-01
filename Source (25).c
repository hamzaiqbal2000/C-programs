#include <stdio.h>

void copy();

int main()
{
	copy();
	getch();
	return 0;
}

void copy()
{
	int A[] = { 5,6,7,8,9 },B[10],n=5,i;
	printf("B array:");
	for (i = 0; i < n; i++)
	{
		B[i] = A[i];
		printf("%d ", B[i]);
	}
}
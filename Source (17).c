#include <stdio.h>

int main()
{
	int i,a[20],b[10],n;
	printf("How many numbers you want to enter: ");
	scanf_s("%d", &n);
	printf("Enter the numbers for A: ");
	for (i = 0; i < n; i++) {
		scanf_s("%d", &a[i]);
	}
	printf("Enter the numbers for B: ");
	for (i = 0; i < n; i++) {
		scanf_s("%d", &b[i]);
	}

	for (i = 0; i < n; i++) {
		a[n + i] = b[i];
	}

	for (i = 0; i < n+n; i++) {
		printf("%d ",a[i]);
	}

	getch();
	return 0;


}
#include <stdio.h>

int main()
{
	int temp,positions=0, n=7, a[7] = { 1,2,3,4,5,6,7 },rotate;
	printf("Do you want to rotate left or right(0/1): ");
	scanf_s("%d", &rotate);
	printf("How many positions you want to move: ");
	scanf_s("%d", &positions);
	if (rotate == 0) {
		for (int i = 0; i < positions; i++) {
			temp = a[0];
			for (int j = 0; j < n; j++)
				a[j] = a[j + 1];
			a[n - 1] = temp;
		}
	}
	else {
		for (int i = 0; i < positions; i++) {
			temp = a[n - 1];
			for (int j = n-1; j >=0; j--)
				a[j] = a[j-1];
			a[0] = temp;
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	getch();
	return 0;
}
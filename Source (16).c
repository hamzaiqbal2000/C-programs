#include <stdio.h>

int main()
{
	int num1, a[] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("Enter the number you want to get pair of: ");
	scanf_s("%d", &num1);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (a[i] + a[j] == num1) {
				printf("Sum(%d,%d)\n", a[i], a[j]);
			}
		}
	}
	getch();
	return 0;

}
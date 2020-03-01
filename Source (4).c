#include <stdio.h>

int factorial(int x);
int main()
{
	int num1,result;
	printf("Enter the number you want to calculate factorial of:");
	scanf_s("%d", &num1);
	result=factorial(num1);
	printf("factorial of number is %d", result);
	getch();
	return 0;
}

int factorial(int x)
{
	int fact=1;
	for (int i = x; i >= 1; i--) {

		fact = fact * i;
	}
	return fact;
}
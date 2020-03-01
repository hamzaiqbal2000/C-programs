#include <stdio.h>
#include <stdlib.h>
/*int main()
{
	int num1=3, num2=5, *p1, *p2;
	p1 = &num1;
	p2 = &num2;
	printf("Sum of the two numbers is %d", *p1 + *p2);
	getch();
	return 0;
}*/
/*int sum(int *x, int *y);
int main()
{
	int num1, num2 ,Sum;
	printf("Input first numvber:");
	scanf_s("%d", &num1);
	printf("Input Second numvber:");
	scanf_s("%d", &num2);
	Sum=sum(&num1, &num2);
	printf("Sum=%d", Sum);
	getch();
	return 0;

}
int sum(int *x, int *y)
{
	int Sum = *x + *y;
	return Sum;
}*/
/*int max(int *x, int *y);
int main()
{
	int num1, num2,Max;
	printf("Input the first number:");
	scanf_s("%d", &num1);
	printf("Input the Second number:");
	scanf_s("%d",& num2);
	Max = max(&num1, &num2);
	printf("Maximum number is %d", Max);
	getch();
	return 0;
}
int max(int *x, int *y)
{
	int Max;
	if (*x > *y)
		Max = *x;
	else
		Max = *y;
	return Max;
}*/

/*int main()
{
	int a[5], *p;
	p = &a[0];
	printf("Input 5 numbers:");
	for (int i = 0; i < 5; i++)
		scanf_s("%d", p + i);
	for (int i = 0; i < 5; i++)
		printf("%d ", *(p + i));
	getch();
	return 0;
}*/

/*#include <stdio.h>
#include <string.h>

void changePosition(char *ch1, char *ch2)
{
	char tmp;
	tmp = *ch1;
	*ch1 = *ch2;
	*ch2 = tmp;
}
void charPermu(char *cht, int stno, int endno)
{
	int i;
	if (stno == endno)
		printf("%s  ", cht);
	else
	{
		for (i = stno; i <= endno; i++)
		{
			changePosition((cht + stno), (cht + i));
			charPermu(cht, stno + 1, endno);
			changePosition((cht + stno), (cht + i));
		}
	}
}

int main()
{
	char str[] = "abcd";
	printf("\n\n Pointer : Generate permutations of a given string :\n");
	printf("--------------------------------------------------------\n");
	int n = strlen(str);
	printf(" The permutations of the string are : \n");
	charPermu(str, 0, n - 1);
	printf("\n\n");
	return 0;
}*/

/*int main()
{
	int i, n;
	float *element;
	printf("Input total number of elements(1-100):");
	scanf_s("%d", &n);
	element = (float*)calloc(n, sizeof(float));
	if (element == NULL) {
		printf("No memory is allocated");
		exit(0);
	}
	printf("\n");
	for (i = 0; i < n; i++) {
		printf("Number %d:", i + 1);
		scanf_s("%f", element + i);
	}
	for (int i = 0; i < n; i++) {
		if (*element < *(element + i))
			*element = *(element + i);
	}
	printf("largest element is %.2f\n\n", *element);
	getch();
	return 0;
}*/
/*int length(char *p) {
	int i;
	for (i = 0; *(p + i) != '\0'; i++);
	return i;
}
int main()
{
	char s[] = "computer";
	int d;
	d = length(s);
	printf("%d", d);
	int f=strlen(s);
	printf("\n%d", f);
	getch();
	return 0;
}*/

/*void factorial(int x,int *y);
int main()
{
	int num1,result;
	printf("Input the number:");
	scanf_s("%d", &num1);
	factorial(num1,&result);
	printf("Factorial of %d is %d", num1, result);
	getch();
	return 0;
}
void factorial(int x,int *y)
{
	*y = 1;
	for (int i = 1; i <=x; i++) {
		*y = *y*i;
	}
}*/
/*void count(int *x);
int main()
{
	char s[] = "computer";
	count(s);
	getch();
	return 0;
}
void count(char *x)
{
	int even = 0,odd=0;
	
	for (int i = 0; *(x+i)!='\0'; i++) {
		if (*(x + i) == 'a' || *(x + i) == 'e' || *(x + i) == 'i' || *(x + i) == 'o' || *(x + i) == 'u')
			even++;
		else
			odd++;
	}
	printf("No of vowels=%d\n", even);
	printf("No of consonents=%d", odd);
}*/

int* find(int *x, int *y);
int main()
{
	int num1=4, num2=2;
	int *result;
	result = max(&num1, &num2);
	printf("The larger number is %d", *result);
	getch();
	return 0;
}
int* find(int *x, int *y) {
	if (*x > *y)
		return x;
	else
		return y;
}
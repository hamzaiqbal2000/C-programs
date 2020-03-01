#include <stdio.h>

/*void star();
void sort();
int main()
{
	//star();
	sort();
	getch();
	return 0;
}

void star() {
	for (int i = 1; i < 6; i++) {
		int k = 1;
		for (int j = 1; j <= 6; j++) {
			if (j <= i) {
				if (k == 1) {
					printf("%d", k);
					k = 0;
				}
				else {
					printf("%d", k);
					k = 1;
				}
			}
			else
				printf(" ");
		}
		printf("\n");
	}
}
void sort()
{
	char s[20],ch;
	printf("Enter a string:");
	gets(s);
	for (int j = 0; !(s[j]=='\0'); j++) {
		if (s[j] > s[j + 1]) {
				ch = s[j];
				s[j] = s[j + 1];
				s[j + 1] = ch;
		}
	}

	printf("String in Alphabetical order is %s", s);
	getch();
	return 0;
}*/

void reverse(int x,int *p);
int main()
{
	int a[20], num1;
	printf("How many numbers you want to enter:");
	scanf_s("%d", &num1);
	printf("Enter the numbers:");
	for (int i = 0; i < num1; i++)
		scanf_s("%d", &a[i]);
	reverse(num1, a);
	for (int i = 0; i < num1; i++)
		printf("%d ", a[i]);
	getch();
	return 0;
}
void reverse(int x, int *p)
{
	int temp;
	for (int i = 0; i < x / 2; i++) {
		temp = *(p + i);
		*(p + i) = *(p+x - i - 1);
		*(p+x - i - 1) = temp;
	}
}
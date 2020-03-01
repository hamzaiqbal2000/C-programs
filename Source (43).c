/*#include <stdio.h>

long fibonacci(long n);

int main()
{
	long result, num;
	printf("Enter an integer: ");
    scanf_s("%ld", &num);
	result = fibonacci (num);
	printf("%ld", result);

	getch();
	return 0;

}
long fibonacci(long n)
{
	if (n <= 1)
		return n;
	else
		return fibonacci(n - 1) + fibonacci(n - 2);
}*/

 /* Fig. 5.15: fig05_15.c
 Recursive fibonacci function */
#include <stdio.h>
long fibonacci(long n); /* function prototype */
/* function main begins program execution */
 int main(void)
 {
	 long result; /* fibonacci value */
	 long number; /* number input by user */
	
	 /* obtain integer from user */
		 printf("Enter an integer: ");
	scanf_s("%ld", &number);
	result = fibonacci(number);
	 /* calculate fibonacci value for number input by user */
 /* display result */
 printf("Fibonacci( %ld ) = %ld\n", number, result);
 getch();
 return 0; /* indicates successful termination */
 } /* end main */



/* Recursive definition of function fibonacci */
long fibonacci(long n)
{
	/* base case */
	if (n == 0 || n == 1) {
		return n;
	} /* end if */
	else { /* recursive step */
		return fibonacci(n - 1) + fibonacci(n - 2);
	} /* end else */
} /* end function fibonacci */
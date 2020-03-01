 #include <stdio.h>

void star1(); void star11(); void star21();
void star2(); void star12(); void star22();
void star3(); void star13();
void star4(); void star14();
void star5(); void star15();
void star6(); void star16();
void star7(); void star17();
void star8(); void star18();
void star9(); void star19();
void star10(); void star20();

int main()
{
	//star1();
	//star2();
	//star3();
	//star4();
	//star5();
	//star6();
	//star7();
	//star8();
	//star9();
	//star10();
	//star11();
	//star12();
	//star13();
	//star14();
	//star15();
	//star16();
	//star17();
	//star18();
	//star19();
	//star20();
	//star21();
	star22();
	getch();
	return 0;
}
void star1()
{
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			if (j >= 5 - i + 1)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}
void star2()
{
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			if (j>=i)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}
void star3()
{
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			if (j<=5-i+1)
				printf("*");
			else 
				printf(" ");
		}
		printf("\n");
	}
}
void star4()
{
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 9; j++) {
			if (j>=5-i+1 && j<=5+i-1)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}
void star5()
{
	for (int i = 1; i <= 5; i++) {
		int k = 1;
		for (int j = 1; j <= 9; j++) {
			if (j >= 6 - i && j <= 4 + i && k) {
				printf("*");
				k = 0;
			}
			else {
				printf(" ");
				k = 1;
			}
		}
		printf("\n");
	}
}
void star6()
{
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 9; j++) {
			if (j <= 6-i || j >= 4+i)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}
void star7()
{
	for (int i = 1; i <= 7; i++) {
		for (int j = 1; j <= 7; j++) {
			if (j>=5-i && j<=3+i && i<5)
				printf("*");
			else if (j >= i - 3 && j <= 11 - i && i>=5)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}
void star8()
{
	for (int i = 1; i <= 7; i++) {
		for (int j = 1; j <= 4; j++) {
			if (j <= i && i <= 4)
				printf("*");
			else if (j <= 8 - i && i > 4)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}

}
void star9()
{
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 7; j++) {
			if (j>=i && j<=8-i)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}

}
void star10()
{
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 8; j++) {
			if (j>=5-i && j<=9-i)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}
void star11()
{
	for (int i = 1; i <= 4; i++) {
		int k = 1;
		for (int j = 1; j <= 7; j++) {
			if (j>=5-i && j<=3+i) {
				printf("%d", k);
				j < 4 ? k++ : k--;	 
			}
			else
				printf(" ");
		}
		printf("\n");
	}
}
void star12()
{
	for (int i = 1; i <= 4; i++) {
		char ch = 'A';
		for (int j = 1; j <= 7; j++) {
			if (j <= 5 - i || j >= 3 + i) {
				printf("%c", ch);
			}
			else {
				printf(" ");
			}
			j < 4 ? ch++ : ch--;
		}
		printf("\n");
	}
}
void star13()
{
	for (int i = 1; i <= 4; i++) {
		int k = i;
		for (int j = 1; j <= 7; j++) {
			if (j >= 5 - i && j <= 3 + i) {
				printf("%d", k);
				j < 4 ? k++ : k--;
			}
			else
				printf(" ");
		}
		printf("\n");
	}
}

void star14(){
	for (int i = 1; i <= 7; i++) {
		int k = 7 - i;
		for (int j = 1; j <= 7; j++) {
			if (j <= 8 - i) {
				printf("%d",k);
				k--;
			}
			else
				printf(" ");
		}
		printf("\n");
	}

}

void star15()
{
	for (int i = 1; i <= 9; i++) {
		int k = 1;
		for (int j = 1; j <= 5; j++) {
			if (j >= 6 - i && i <= 5) {
				printf("%d",k);
				k++;
			}
			else if (j >= i - 4 && i > 5) {
				printf("%d",k);
				k++;
			}
			else
				printf(" ");
		}
		printf("\n");
	}
}
void star16()
{
	for (int i = 1; i <= 7; i++) {
		for (int j = 1; j <= 7; j++) {
			if (j==i || j==8-i) {
				if (i==j)
					printf("\\");
				else
					printf("/");
			}
			else
				printf("*");

		}
		printf("\n");
	}
}

void star17()
{
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			if ((j<=6-i || j>=4+i) && i<=4)
				printf("*");
			else if ((j<=i-4 || j>=14-i) && i>4)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}

}

void star18()
{
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 9; j++) {
			if (j >= i && j <= 10 - i)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}

void star19()
{
	for (int i = 1; i <= 4; i++) {
		char ch = 65;
		for (int j = 1; j <= 7; j++) {
			if (j >= 5 - i && j <= 3 + i) {
				printf("%c",ch);
				if (j < 4)
					ch++;
				else
					ch--;
			}
			else
				printf(" ");
		}
		printf("\n");
	}
}

void star20()
{
	for (int i = 1; i <= 4; i++) {
		char ch=65;
		int k = 1;
		for (int j = 1; j <= 8; j++) {
			if (j >= 5 - i && j <= 4 + i) {
				if (j <= 4) {
					printf("%c", ch);
					ch++;
				}
				else {
					printf("%d", k);
					k++;
				}
			}
			else
				printf(" ");
		}
		printf("\n");
	}
}

void star21()
{
	int k = 0;
	for (int i = 1; i <= 5; i++) {
		
		if (i > 2)
			k++;
		for (int j = 1; j <= 8; j++) {
			
			if (j <= k + i) {
				
				printf("*");
			}
			else
				printf(" ");
		}
		printf("\n");
	}
}

void star22()
{
	for (int i = 1; i <= 7; i++) {
		for (int j = 1; j <= 7; j++) {
			if ((i==1||i==7||j==1||j==7)||(i>=3&&i<=5&&j>=3&&j<=5)&&(i==3||i==5||j==3||j==5))
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}

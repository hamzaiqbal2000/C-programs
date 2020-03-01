#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void player1();

int main()
{
	srand((unsigned int)time(0));
	player1();
	_getche();
	return 0;
}

void player1()
{
	int a = 0, sum;
	int player = 0, dealer = 0;
	char quit = 'a', command = 'a';
	do {
		int i = 10, t[10] = { 0 }, z[10];
		char r[10], s[10];
		char arr[] = { 'A','2','3','4','5','6','7','8','9','J','K','Q' };
		r[0] = arr[rand() % 11], r[1] = arr[rand() % 11];
		printf("Player's Hand: %c %c", r[0], r[1]);
		s[0] = arr[rand() % 11], s[1] = arr[rand() % 11];
		printf("\nDealer's Hand: %c X", s[0]);

		printf("\nEnter command:");
		scanf_s(" %c", &command);
		r[2] = arr[rand() % 11];
		r[3] = arr[rand() % 11];
		r[4] = arr[rand() % 11];
		s[2] = arr[rand() % 11];
		if (command == 'h')
		{
			for (i = 0;; i++)
			{

				if (i == 0)
				{
					printf("Player's Hand: %c %c %c", r[0], r[1], r[2]);
					for (int j = 0; j <= 3; j++)
					{
						if (r[j] >= '2' && r[j] <= '9')
							t[j] = r[j] - '0';
					}
					for (int j = 0; j <= 2; j++)
					{
						if (r[j] == 'A')
						{
							t[j] = 11;
						}
						if (r[j] == 'J' || r[j] == 'Q' || r[j] == 'K')
							t[j] = 10;
					}
					if ((t[0] + t[1] + t[2]) > 21)
						printf("\nDealer's Hand: %c %c", s[0], s[1]);
					else
						printf("\nDealer's Hand: %c X", s[0]);
				}

				if (i == 1)
				{
					printf("\nPlayer's Hand: %c %c %c %c", r[0], r[1], r[2], r[3]);
					printf("\nDealer's Hand: %c %c", s[0], s[1]);
				}
				if (i == 2)
				{
					printf("\nPlayer's Hand: %c %c %c %c %c", r[0], r[1], r[2], r[3], r[4]);
					printf("\nDealer's Hand: %c %c", s[0], s[1]);
				}
				for (int j = 0; j <= 4; j++)
				{
					if (r[j] >= '2' && r[j] <= '9')
						t[j] = r[j] - '0';
				}
				for (int j = 0; j <= 4; j++)
				{
					if (r[j] == 'A')
					{
						t[j] = 11;
						if (i == j)
							a++;
					}
					
					if (r[j] == 'J' || r[j] == 'Q' || r[j] == 'K')
						t[j] = 10;
				}
				
			
				if (i == 0)
				{
					if ((t[0] + t[1] + t[2]) > 21)
					{
						sum = (t[0] + t[1] + t[2]);
						for (int i = a; i > 0; i--)
						{
							sum = sum - 10;
						}
						if (sum > 21) {
							printf("\nPlayer busts");
							dealer++;
							break;
						}
						if (sum == 21) {
							printf("\nPlayer wins");
							player++;
							break;
						}
					}
					if ((t[0] + t[1] + t[2]) == 21)
					{
						printf("\nPlayer wins");
						player++;
						break;
					}
				}
				if (i == 1)
				{
					if ((t[0] + t[1] + t[2] + t[3]) > 21)
					{
						sum = (t[0] + t[1] + t[2] + t[3]);
						for (int i = a; i > 0; i--)
						{
							sum = sum - 10;
						}
						if (sum > 21) {
							printf("\nPlayer busts");
							dealer++;
							break;
						}
						if (sum == 21) {
							printf("\nPlayer wins");
							player++;
							break;
						}
					}
					if ((t[0] + t[1] + t[2] + t[3]) == 21)
					{
						printf("\nPlayer wins");
						player++;
						break;
					}
				}
				if (i == 2)
				{
					if ((t[0] + t[1] + t[2] + t[3] + t[4]) > 21)
					{
						printf("\nPlayer busts");
						dealer++;
						break;
					}
					if ((t[0] + t[1] + t[2] + t[3] + t[4]) == 21)
					{
						printf("\nPlayer wins");
						player++;
						break;
					}
				}
				printf("\nEnter command:");
				scanf_s(" %c", &command);
				if (command == 'q') {
					printf("Dealer wins");
					dealer++;
					break;
				}
				if (!(command == 'h'))
					break;
			}
		}

		if (command == 's')
		{
			if (i == 0)
			{
				printf("Player's Hand: %c %c %c", r[0], r[1], r[2]);
				printf("\nDealer's Hand: %c %c %c", s[0], s[1], s[2]);
			}
			else
			{
				printf("Player's Hand: %c %c", r[0], r[1]);
				printf("\nDealer's Hand: %c %c %c", s[0], s[1], s[2]);
			}

			for (int j = 0; j <= 3; j++)
			{
				if (s[j] >= '2' && s[j] <= '9')
					z[j] = s[j] - '0';
			}
			for (int j = 0; j <= 2; j++)
			{
				if (s[j] == 'A')
					z[j] = 11;
				if (s[j] == 'J' || s[j] == 'Q' || s[j] == 'K')
					z[j] = 10;
			}
			{
				if (((z[0] + z[1] + z[2]) >= 17) && ((z[0] + z[1] + z[2]) > (t[0] + t[1] + t[2])))
				{
					printf("\nDealer wins");
					dealer++;
				}
				if (((z[0] + z[1] + z[2]) >= 17) && ((z[0] + z[1] + z[2]) == (t[0] + t[1] + t[2])))
					printf("\nPush");
				if (((z[0] + z[1] + z[2]) >= 17) && ((z[0] + z[1] + z[2]) < (t[0] + t[1] + t[2])))
				{
					printf("\nPlayer wins");
					player++;
				}

				if ((z[0] + z[1] + z[2]) < 17)
				{
					printf("\nDealer busts");
					player++;
				}
			}
		}
		printf("\nEnter 'q' to quit, anything else to play another game:");
		scanf_s(" %c", &quit);
	} while (!(quit == 'q'));
	printf("Total score\nPlayer wins=%d\nDealer wins=%d", player, dealer);
}

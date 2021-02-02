#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int calc();
int replace_on_number(int* Mas);
void selection(int* Mas, int step = 0);
void checking_exit(int CHIS, int* Mas);
void used_letter(char a);


struct about_table {
	char mass_word[5][9];
	int  mass_w_int[5][9];
	int word_count;
	int len[8];
	int row = 0;
	int column = 0;
	int count_letter = 0;

};

char eng_letters[26];
int eng_letter_int[26];
unsigned int timee;
int check_decisions = 0;

struct about_table mass_reb;

int main()
{
	setlocale(LC_ALL, "Rus");
	int i = 0;
	int mass_numbers[10];
	char str[100];
	printf("Введите строку: ");
	fgets(str, 100, stdin);

	while (str[i - 1] != '=')
	{
		mass_reb.column = 0;
		while (str[i] != '+' && str[i] != '=') {
			used_letter(str[i]);
			mass_reb.mass_word[mass_reb.row][mass_reb.column] = str[i];
			i++;
			mass_reb.column++;
		}
		mass_reb.mass_word[mass_reb.row][mass_reb.column] = '\0';
		mass_reb.len[mass_reb.row] = mass_reb.column;
		mass_reb.row++;
		i++;
	}

	mass_reb.column = 0;
	while (str[i] != '\n') {
		used_letter(str[i]);
		mass_reb.mass_word[mass_reb.row][mass_reb.column] = str[i];
		i++;
		mass_reb.column++;
	}
	mass_reb.mass_word[mass_reb.row][mass_reb.column] = '\0';
	mass_reb.len[mass_reb.row] = mass_reb.column;
	mass_reb.word_count = mass_reb.row + 1;

	if (mass_reb.count_letter > 10)
	{
		printf("\nОшибка в выражении. Много букв.\n");
		exit(0);
	}

	timee = clock();

	for (i = 0; i <= 9; i++)
	{
		mass_numbers[i] = i;
	}

	selection(mass_numbers);

	if (check_decisions == 0)
	{
		printf("\nНет решения.\n");
	}
}

int calc()
{
	int mass_sum_word[5];
	int final_sum = 0;
	int j, i = 0;
	int ten = 1;
	int summa = 0;

	for (i = 0; i < mass_reb.word_count; i++)
	{
		ten = 1;
		summa = 0;
		for (j = mass_reb.len[i] - 1; j >= 0; j--) {
			summa += mass_reb.mass_w_int[i][j] * ten;
			ten *= 10;
		}
		mass_sum_word[i] = summa;
		final_sum += mass_sum_word[i];
	}
	final_sum -= mass_sum_word[i - 1];
	
	if (final_sum == mass_sum_word[i - 1]) {
		printf("\nОтвет: %d", mass_sum_word[0]);
		for (j = 1; j < mass_reb.word_count - 1; j++)
		{
			printf(" + %d ", mass_sum_word[j]);
		}
		printf("= %d \n", mass_sum_word[mass_reb.word_count - 1]);
		printf("\nВремя: %u ms\n\n", (clock() - timee));
		check_decisions = 1;
		return 1;
	}
	else {
		return 0;
	}
}

int replace_on_number(int* mass_number)
{
	int i, j = 0, ii, jj;
	for (i = 0; i < mass_reb.count_letter; i++)
	{
		eng_letter_int[i] = mass_number[j];
		j++;

		for (ii = 0; ii < mass_reb.word_count; ii++)
		{
			for (jj = 0; jj < mass_reb.len[ii]; jj++)
			{
				if (mass_reb.mass_word[ii][jj] == eng_letters[i])
				{
					mass_reb.mass_w_int[ii][jj] = eng_letter_int[i];
				}
			}
		}
	}

	//0
	int sum = 0, num = 0, k;
	for (k = 0; k < mass_reb.word_count; k++)
	{
		if (mass_reb.mass_w_int[k][0] == 0)
		{
			return 0;
		}
		num = mass_reb.mass_w_int[k][mass_reb.len[k] - 1];
		sum += num;
	}

	//1 и послед
	sum -= num;
	if (sum > 9)
	{
		sum %= 10;
	}
	if (sum != num) {
		return 0;
	}
	return 1;
}

void checking_exit(int step, int* mass_number) {
	if (step == mass_reb.count_letter)
	{
		if (replace_on_number(mass_number))
		{
			if (calc())
			{
				exit(0);
			}
		}
	}
}

void selection(int* mass_number, int step)
{
	int i, a;
	if (step >= mass_reb.count_letter)
	{
		checking_exit(step, mass_number);
		return;
	}

	for (i = step; i < 10; ++i)
	{
		a = mass_number[i];
		mass_number[i] = mass_number[step];
		mass_number[step] = a;
		selection(mass_number, step + 1);
		a = mass_number[i];
		mass_number[i] = mass_number[step];
		mass_number[step] = a;
	}
	return;
}

void used_letter(char letter) 
{
	for (int i = 0; i < mass_reb.count_letter; i++)
	{
		if (letter == eng_letters[i])
		{
			return;
		}
	}
	eng_letters[mass_reb.count_letter] = letter;
	eng_letter_int[mass_reb.count_letter] = -2;
	mass_reb.count_letter++;
}
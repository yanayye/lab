#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void used_letters();
int check_numbers_on_letters();
int calc();
void replace_on_number(int* Mas);
void selection();

struct about_rebus {
	char mass_word[5][9];
	int  mass_w_int[5][9];
	int word_count;
	int len[8];
	int row = 0;
	int column = 0;
};

char eng_letters[] = { 'A', 'B', 'C' , 'D' , 'E' , 'F' , 'G' , 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S' , 'T' , 'U' , 'V' , 'W' , 'X', 'Y', 'Z' };
int eng_letter_int[] = { -1, -1, -1 , -1 , -1, -1 ,-1 , -1, -1, -1, -1, - 1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 ,-1 , -1 , -1, -1, -1 };
unsigned int timee;
struct about_rebus mass_reb;

int main() 
{
	setlocale(LC_ALL, "Rus");
	int i = 0;
	char str[100];
	printf("Введите строку: ");
	fgets(str, 100, stdin);

	while (str[i-1] != '=')
	{
		mass_reb.column = 0;
		while (str[i] != '+' && str[i] != '=') {
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
		mass_reb.mass_word[mass_reb.row][mass_reb.column] = str[i];
		i++;
		mass_reb.column++;
	}
	mass_reb.mass_word[mass_reb.row][mass_reb.column] = '\0';
	mass_reb.len[mass_reb.row] = mass_reb.column;
	mass_reb.word_count = mass_reb.row+1;

	timee = clock();
	selection();
}


void selection()
{
	used_letters();
	int mass_number[10];
	int i0, i1, i2, i3, i4, i5, i6, i7, i8, i9;

	for (int i0 = 0; i0 < 10; i0++)
	{
		mass_number[0] = i0;
		for (i1 = 0; i1 < 10; i1++)
		{
			if (i1 != i0)
			{
				mass_number[1] = i1;
				for (i2 = 0; i2 < 10; i2++)
				{
					if (i2 != i0 && i2 != i1)
					{
						mass_number[2] = i2;
						for (i3 = 0; i3 < 10; i3++)
						{
							if (i3 != i0 && i3 != i1 && i3 != i2)
							{
								mass_number[3] = i3;
								for (i4 = 0; i4 < 10; i4++)
								{
									if (i4 != i0 && i4 != i1 && i4 != i2 && i4 != i3)
									{
										mass_number[4] = i4;
										for (i5 = 0; i5 < 10; i5++)
										{
											if (i5 != i0 && i5 != i1 && i5 != i2 && i5 != i3 && i5 != i4)
											{
												mass_number[5] = i5;
												for (i6 = 0; i6 < 10; i6++)
												{
													if (i6 < 10 && i6 != i0 && i6 != i1 && i6 != i2 && i6 != i3 && i6 != i4 && i6 != i5)
													{
														mass_number[6] = i6;
														for (i7 = 0; i7 < 10; i7++)
														{
															if (i7 != i0 && i7 != i1 && i7 != i2 && i7 != i3 && i7 != i4 && i7 != i5 && i7 != i6)
															{
																mass_number[7] = i7;
																for (i8 = 0; i8 < 10; i8++)
																{
																	if (i8 != i0 && i8 != i1 && i8 != i2 && i8 != i3 && i8 != i4 && i8 != i5 && i8 != i6 && i8 != i7)
																	{
																		mass_number[8] = i8;
																		for (i9 = 0; i9 < 10; i9++)
																		{
																			if (i9 != i0 && i9 != i1 && i9 != i2 && i9 != i3 && i9 != i4 && i9 != i5 && i9 != i6 && i9 != i7 && i9 != i8)
																			{
																				mass_number[9] = i9;
																				replace_on_number(mass_number);
																				if (check_numbers_on_letters())
																				{
																					if (calc())
																					{
																						return;
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return;
}

void used_letters()
{
	int i, j, k;
	for (i = 0; i < 26; i++)
	{
		for (j = 0; j < mass_reb.word_count; j++)
		{
			for (k = 0; k < mass_reb.len[j]; k++)
			{
				if (mass_reb.mass_word[j][k] == eng_letters[i])
				{
					eng_letter_int[i] = -2;
					mass_reb.mass_w_int[j][k] = eng_letter_int[i];
				}
			}

		}
	}
}

int check_numbers_on_letters()
{
	int i, j, k;
	for (i = 0; i < 26; i++)
	{
		if (eng_letter_int[i] != -1)
		{
			for (j = 0; j < mass_reb.word_count; j++)
			{
				for (k = 0; k < mass_reb.len[j]; k++)
				{
					if (mass_reb.mass_word[j][k] == eng_letters[i])
					{
						mass_reb.mass_w_int[j][k] = eng_letter_int[i];
					}
				}

			}
		}
	}
	return 1;
}

int calc()
{
	int mass_sum_word[5];
	int final_sum = 0;
	int j, i = 0;
	int ten;
	int summa;

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
		return 1;
	}
	else {
		return 0;
	}
}

void replace_on_number(int* mass_number)
{
	int i, j = 0;
	for (i = 0; i < 26; i++)
	{
		if (eng_letter_int[i] != -1)
		{
			eng_letter_int[i] = mass_number[j];
			j++;
		}
	}
}

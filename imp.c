/* DIGITAL SIGNATURE(S):
   ====================

   List the student author(s) of this code below:

   Fullname                    Seneca Email Address
   --------------------------- ----------------------------
   1)Harkirat Singh Virdi      hsvirdi7@myseneca.ca
   2)Tahsin Rahman             trahman31@myseneca.ca
   3)Ulviyya Bakhshizade       ubakhshizade@myseneca.ca

   +--------------------------------------------------------+
   |                FILE: file_helper.c                     |
   +--------------------------------------------------------+
   |           2  0  2  0  ~  S  U  M  M  E  R              |
   |                 I  P  C  :  B  T  P                    |
   |                 1  4  4  :  1  0  0                    |
   |              FINAL ASSESSMENT PART - 2                 |
   |                                                        |
   |     S  E  N  E  C  A            C  O  L  L  E  G  E    |
   |                                                        |
   |                                                        |
   +--------------------------------------------------------+ */
#define _CRT_SECURE_NO_WARNINGS

#include "imp.h"
#include <stdio.h>

void clearKeyboard(void)
{
	while (getchar() != '\n')
	{
		/* empty execution code block on purpose */
	}
}

int getInt(void)
{
	char newline = 'x';
	int value = 0;

	while (newline != '\n')
	{
		scanf("%d%c", &value, &newline);
		if (newline != '\n')
		{
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
			scanf("%d%c", &value, &newline);
		}
	}

	return value;
}

int getIntInRange(int min, int max)
{
	int number = 0;
	number = getInt();
	while (number < min || number > max)
	{
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		number = getInt();
	}
	return number;
}
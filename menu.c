/* DIGITAL SIGNATURE(S):
   ====================

   List the student author(s) of this code below:

   Fullname                    Seneca Email Address
   --------------------------- ----------------------------
   1)Harkirat Singh Virdi      hsvirdi7@myseneca.ca
   2)Tahsin Rahman             trahman31@myseneca.ca
   3) Ulviyya Bakhshizade      ubakhshizade@myseneca.ca

   +--------------------------------------------------------+
   |                   FILE: menu.c                         |
   +--------------------------------------------------------+
   |           2  0  2  0  ~  S  U  M  M  E  R              |
   |                 I  P  C  :  B  T  P                    |
   |                 1  4  4  :  1  0  0                    |
   |              FINAL ASSESSMENT PART - 2                 |
   |                                                        |
   |     S  E  N  E  C  A            C  O  L  L  E  G  E    |
   +--------------------------------------------------------+ */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "imp.h"
#include "skiers.h"
#include <ctype.h>

void menu(struct SkierInfo const skierInfo[], int const size)
{
	int user_choice = 1;
	puts("************** X-Country Ski Race Reporting ************** ");/* Header */
	while (userChoice(skierInfo, size, displayMenu()))
	{
		/* Empty body is intentional */
	}

	puts("\nKeep on Skiing!");
}

int displayMenu(void)
{
	printf("What would you like to do?\n"                                 /* Description */
		"0 - Exit\n"                                                   /* Options */
		"1 - Print top 3 skiers in a category\n"
		"2 - Print all skiers in a category\n"
		"3 - Print last 3 skiers in a category\n"
		"4 - Print winners in all categories\n"
		": ");


	return getIntInRange(0, 4);
}

int userChoice(struct SkierInfo const skierInfo[], int const  size, int const user_choice)
{
	int dont_exit = 1;
	switch (user_choice)
	{
	case 0: /* Exit */
		dont_exit = 0;
		break;

	case 1:
		printTop3Skiers(skierInfo, size);
		break;

	case 2:
		printAllSkiers(skierInfo, size);
		break;

	case 3:
		printLast3Skiers(skierInfo, size);
		break;

	case 4:
		printWinners(skierInfo, size);
		break;

	default: /* Error */
		puts("Wrong user option! Aborting");
		dont_exit = 0;
	}

	return dont_exit;
}

void printTop3Skiers(struct SkierInfo skierInfo[], int size)
{
	printTopOrLeastThreeList(skierInfo, size, 1);
}

char getCategory(void)
{
	char newline = '\0', category = '\0';
	int result = 0;

	printf("\nWhich category (S, M, L): ");

	while (!result) {
		scanf(" %c%c", &category, &newline);

		category = (char)toupper((unsigned char)category); /* Cast to unsigned char is important before being assigned to a signed type*/

		if (newline != '\n') {
			clearKeyboard();
			printf("*** INVALID INPUT *** <Please enter a valid category (S, M, L)>: ");
		}
		else if (category != 'S' && category != 'L' && category != 'M') {
			printf("*** INVALID INPUT *** <Please enter a valid category (S, M, L)>: ");
		}
		else {
			result = 1;
		}
	}

	return category;
}

void printAllSkiers(struct SkierInfo const skierInfo[], int const size)
{
	int i, hour, min;
	char time[16];
	char const* withdrewString = NULL;
	char category = '\0';
	category = getCategory();

	static struct SkierInfo skiersInThisCategory[MAXRECORD];
	struct SkierInfo* skier = NULL;

	int skiersInThisCategorySize;

	skiersInThisCategorySize = copySkiersInThisCategory(skiersInThisCategory, skierInfo, size, category, 1);
	qsort(skiersInThisCategory, skiersInThisCategorySize, sizeof(struct SkierInfo), skierCmpVoidPointer); /*sorts the array without returing any value*/

	puts("\n"
		"Skier                Age Group  Time  Withdrew\n"
		"----------------------------------------------");
	for (i = 0; i < skiersInThisCategorySize; ++i)
	{
		skier = &skiersInThisCategory[i];

		if (!skier->withdrawn)
		{
			displayTime(skier->finishTime - skier->startTime, &hour, &min);
			snprintf(time, sizeof(time), "%2d:%02d", hour, min); /*formats and stores a series of characters and values in the array buffer*/
			withdrewString = "No";
		}
		else
		{
			snprintf(time, sizeof(time), "%5s", "N/A");
			withdrewString = "Yes";
		}

		printf("%-20s %9s %5s %9s\n", skier->name, ageGroup(skier->age), time, withdrewString);
	}

	putchar('\n');
}

void printLast3Skiers(struct SkierInfo const skierInfo[], int const size)
{
	printTopOrLeastThreeList(skierInfo, size, 0);
}

void printWinners(struct SkierInfo const skierInfo[], int const size)
{
	static struct SkierInfo groupS[MAXRECORD];
	static struct SkierInfo groupM[MAXRECORD];
	static struct SkierInfo groupL[MAXRECORD];
	char time[16];

	struct SkierInfo* skier;

	int sizeS, sizeM, sizeL, i, hour, min;
	sizeS = copySkiersInThisCategory(groupS, skierInfo, size, 'S', 0);
	sizeM = copySkiersInThisCategory(groupM, skierInfo, size, 'M', 0);
	sizeL = copySkiersInThisCategory(groupL, skierInfo, size, 'L', 0);

	/*sorts the array without returning any value*/

	qsort(groupS, sizeS, sizeof(*groupS), skierCmpVoidPointer);
	qsort(groupM, sizeM, sizeof(*groupM), skierCmpVoidPointer);
	qsort(groupL, sizeL, sizeof(*groupL), skierCmpVoidPointer);

	struct SkierInfo* winners[] = {
		sizeS ? groupS : NULL,
		sizeM ? groupM : NULL,
		sizeL ? groupL : NULL,
	};

	puts("\n"
		"Skier                Age Group  Category  Time\n"
		"----------------------------------------------");

	for (i = 0; i < 3; ++i)
	{
		skier = winners[i];
		if (skier)
		{
			displayTime(skier->finishTime - skier->startTime, &hour, &min);
			printf("%-20s %9s %9s %2d:%02d\n", skier->name, ageGroup(skier->age), category(skier->raceLength), hour, min);
		}
		else
		{
			printf("%-20s %9s %9s %5s\n", "Not Awarded", ageGroup(25 * i), category("SML"[i]), "N/A"); // 25 * i approximates the age
		}
	}

	putchar('\n');
}

void printTopOrLeastThreeList(struct SkierInfo skierInfo[], int size, int isTop)
{
	int i, hour, min;
	char category = '\0';
	category = getCategory();

	static struct SkierInfo skiersInThisCategory[MAXRECORD];
	struct SkierInfo* skier = NULL;

	int skiersInThisCategorySize;
	int size_to_display = 3;

	skiersInThisCategorySize = copySkiersInThisCategory(skiersInThisCategory, skierInfo, size, category, 0);
	qsort(skiersInThisCategory, skiersInThisCategorySize, sizeof(struct SkierInfo), skierCmpVoidPointer);

	//printTopOrLeastList(skiersInThisCategory, skiersInThisCategorySize, 3);

	if (skiersInThisCategorySize < size_to_display)
		size_to_display = skiersInThisCategorySize;


	puts("\n"
		"Skier                Age Group  Time\n"
		"------------------------------------");

	for (i = 0; i < size_to_display; ++i)
	{
		if (isTop)
			skier = &skiersInThisCategory[i];
		else
			skier = &skiersInThisCategory[skiersInThisCategorySize - i - 1];

		displayTime(skier->finishTime - skier->startTime, &hour, &min);

		printf("%-20s %9s %2d:%02d\n", skier->name, ageGroup(skier->age), hour, min);
	}

	for (; i < 3; ++i)
		printf("%-20s %9s %5s\n", "Not Awarded", "N/A", "N/A");

	putchar('\n');
}

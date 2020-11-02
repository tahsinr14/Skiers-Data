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
   +--------------------------------------------------------+ */

#define _CRT_SECURE_NO_WARNINGS
#include "skiers.h"


int copySkiersInThisCategory(struct SkierInfo destination[], struct SkierInfo const source[], int source_size, char category, int canWithdraw)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < source_size; ++i)
	{
		if (source[i].raceLength == category && (canWithdraw || !(source[i].withdrawn)))
		{
			destination[j++] = source[i];
		}
	}

	return j;
}

int skierCmp(struct SkierInfo const* arg1, struct SkierInfo const* arg2)
{
	double time1 = arg1->finishTime - arg1->startTime;
	double time2 = arg2->finishTime - arg2->startTime;
	int result = 0;

	if (arg1->withdrawn && arg2->withdrawn)
		result = 0;
	if (time1 < time2 || arg2->withdrawn)
		result = -1;
	else if (time2 < time1 || arg1->withdrawn)
		result = 1;

	return result;
}


int skierCmpVoidPointer(void const* arg1, void const* arg2)
{
	return skierCmp((struct SkierInfo*)arg1, (struct SkierInfo*)arg2);
}

char const* ageGroup(int age)
{
	char const* group = "Junior";
	if (age >= 35) {
		group = "Senior";
	}
	else if (age >= 21)
	{
		group = "Adult";
	}
	return group;
}

void displayTime(double const time, int* hour, int* minute)
{
	// hour + (min / 60.0);
	*hour = (int)(time);
	*minute = (int)(time * 60) % 60;
}

char const* category(char const c)
{
	char const* result = "10 km";
	if (c == 'M' || c == 'm')
	{
		result = "25 km";
	}
	else if (c == 'L' || c == 'l')
	{
		result = "50 km";
	}
	return result;
}

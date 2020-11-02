/* DIGITAL SIGNATURE(S):
   ====================

   List the student author(s) of this code below:

   Fullname                    Seneca Email Address
   --------------------------- ----------------------------
   1)Harkirat Singh Virdi      hsvirdi7@myseneca.ca
   2)Tahsin Rahman             trahman31@myseneca.ca
   3)Ulviyya Bakhshizade       ubakhshizade@myseneca.ca

   +--------------------------------------------------------+
   |                   FILE: menu.h                         |
   +--------------------------------------------------------+
   |           2  0  2  0  ~  S  U  M  M  E  R              |
   |                 I  P  C  :  B  T  P                    |
   |                 1  4  4  :  1  0  0                    |
   |              FINAL ASSESSMENT PART - 2                 |
   |                                                        |
   |     S  E  N  E  C  A            C  O  L  L  E  G  E    |
   +--------------------------------------------------------+ */

#ifndef SKIERS_H
#define SKIERS_H


#include "file_helper.h"

// returns number of skiers copied
int copySkiersInThisCategory(struct SkierInfo destination[], struct SkierInfo const source[], int source_size, char category, int canWithdraw);

int skierCmp(struct SkierInfo const* arg1, struct SkierInfo const* arg2);
int skierCmpVoidPointer(void const* arg1, void const* arg2);
//void printSkier(struct SkierInfo const* skier);

char const* ageGroup(int age);
void displayTime(double time, int* hour, int* minute);
char const* category(char c);


#endif
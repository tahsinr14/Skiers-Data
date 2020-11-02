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
#ifndef MENU_H
#define MENU_H

#include "file_helper.h"
#define MAXRECORD 2000
void menu(struct SkierInfo skierInfo[], int size);

int displayMenu(void);
int userChoice(struct SkierInfo const skierInfo[], int size, int user_choice);

void printTop3Skiers(struct SkierInfo const  skierInfo[], int size);
char getCategory(void);


void printAllSkiers(struct SkierInfo const skierInfo[], int size);
void printLast3Skiers(struct SkierInfo const skierInfo[], int size);
void printWinners(struct SkierInfo const skierInfo[], int size);

void printTopOrLeastThreeList(struct SkierInfo skierInfo[], int size, int isTop);




#endif
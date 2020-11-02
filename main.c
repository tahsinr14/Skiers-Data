/* DIGITAL SIGNATURE(S):
   ====================

   List the student author(s) of this code below:

   Fullname                    Seneca Email Address
   --------------------------- ----------------------------
   1)Harkirat Singh Virdi      hsvirdi7@myseneca.ca
   2)Tahsin Rahman             trahman31@myseneca.ca
   3)Ulviyya Bakhshizade       ubakhshizade@myseneca.ca

   +--------------------------------------------------------+
   |                   FILE: main.c                         |
   +--------------------------------------------------------+
   |           2  0  2  0  ~  S  U  M  M  E  R              |
   |                 I  P  C  :  B  T  P                    |
   |                 1  4  4  :  1  0  0                    |
   |              FINAL ASSESSMENT PART - 2                 |
   |                                                        |
   |     S  E  N  E  C  A            C  O  L  L  E  G  E    |
   +--------------------------------------------------------+ */

#define _CRT_SECURE_NO_WARNINGS

#include "file_helper.h"
#include "menu.h"
#define DATAFILE "data.txt"




int main(void)
{
	// TODO: Code the necessary logic for your solution below
	//
	// NOTE: Use modularity whenever possible in your design
	//
	// HINTS:
	// 1) You will need to load the file data and store
	//    it to a data structure array 
	//    (MUST USE: provided "readFileRecord" function)
	struct SkierInfo info[MAXRECORD];
	FILE* data_file = NULL;
	int size = 0;

	data_file = fopen(DATAFILE, "r");
	if (!data_file)
	{
		printf("Failed to open file %s\n", DATAFILE);
		return -1;
	}
	while (!readFileRecord(data_file, &info[size]))
	{
		++size;
	}

	
	fclose(data_file);
	//
	// 2) Create a menu system to provide the user with
	//    the reporting options
	//
	// 3) Generate the user-selected report
	menu(info,size);
	return 0;
}
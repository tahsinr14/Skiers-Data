/* DIGITAL SIGNATURE(S):
   ====================

   List the student author(s) of this code below:

   Fullname                    Seneca Email Address
   --------------------------- ----------------------------
   1)Harkirat Singh Virdi      hsvirdi7@myseneca.ca
   2)Tahsin Rahman             trahman31@myseneca.ca
   3)Ulviyya Bakhshizade       ubakhshizade@myseneca.ca

   +--------------------------------------------------------+
   |                FILE: file_helper.h                     |
   +--------------------------------------------------------+
   |           2  0  2  0  ~  S  U  M  M  E  R              |
   |                 I  P  C  :  B  T  P                    |
   |                 1  4  4  :  1  0  0                    |
   |              FINAL ASSESSMENT PART - 2                 |
   |                                                        |
   |     S  E  N  E  C  A            C  O  L  L  E  G  E    |
   +--------------------------------------------------------+ */

#ifndef FILE_HELPER_H
#define FILE_HELPER_H

#include <stdio.h>

/********************************************************/
/* Define the missing members for the SkierInfo data    */
/* used to store Skier information read from a file     */
/********************************************************/
struct SkierInfo
{
	// TODO:  Fill in the missing members:
    char name[81];
    int age;
    char raceLength;

    double startTime;
    double midwayTime;
    double finishTime;

    int withdrawn;
};



/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
/*!!!        DO NOT ALTER THE CONTENTS BELOW       !!!*/
/*!!!             ( function prototype )           !!!*/
/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

/********************************************************/
/* Read all the information on one skier from the       */
/* file and store it in the struct. Return true         */
/* when end of file has been reached.                   */
/********************************************************/
int readFileRecord(FILE* fp, struct SkierInfo* info);

#endif

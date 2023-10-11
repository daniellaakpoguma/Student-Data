/*******************************************************************
* Student Name: Akpoguma Oghenerukevwe
* Student Number:041075624
* Course: 23S_CST8234
* Declaration:
* This is my own original work except where sources have been cited.
*******************************************************************/


#define MAX_SIZE 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ass2.h"
#include "sort.h"
#include "calculate.h"

int main (int argc, char *argv[]){
    char *filename;
    FILE *filePointer;
    struct Student students[MAX_SIZE];
    int studentCount;
    int i;

    if (argc == 1){
      printf ("No arguments provided.\n");
    }else if (argc != 2) {
        printf("Incorrect amount of arguments provided. \n");
        return 1;
    }

    /*reading file name from command line*/
    filename = argv[1]; 

    filePointer =  fopen(filename, "rb");

    if (filePointer == NULL) {
      printf("Error opening the file %s\n", filename);
      return 1;
    }

    studentCount = 0;

    /*Reading students into the students array*/ 
    while (fread(&students[studentCount], sizeof(struct Student), 1, filePointer) == 1) {
        studentCount++;
    }

    fclose(filePointer);

    /* Sort students by student number */
    qsort(students, studentCount, sizeof(struct Student), compareStudentsByID);

    /* Print sorted studenst and their letter grades*/
    for (i = 0; i < studentCount; i++) {
        struct Student *student = &students[i];
        char *letterGrade = sortGrades(student); /* create letter grade */

        printf("Student ID: %d, Percent Mark: %.2f, Letter Grade: %s\n",
               student->studentID, student->percentMark, letterGrade);
    }
 
    calculateMedian(students, studentCount);  /* calculate median grade */
    calculateAverage(students, studentCount); /* calculate average grade */

  return 0;
}
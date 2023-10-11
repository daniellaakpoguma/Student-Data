/*******************************************************************
* Student Name: Akpoguma Oghenerukevwe
* Student Number:041075624
* Course: 23S_CST8234
* Declaration:
* This is my own original work except where sources have been cited.
*******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ass2.h"
#include "sort.h"
#include "calculate.h"

/**
 * Fucntion to calculate the average grade
*/
void calculateAverage(struct Student students[], int studentCount){
    float totalSum = 0.0;   /* value that holds sum */
    float average;  /* value that holds average */
    int i;
    for (i = 0; i < studentCount; i++) {
        totalSum += students[i].percentMark;
    }

    /* Calculate the average and print the result */
    average = totalSum / studentCount;
    printf("Average Percent Mark: %.2f\n", average);
}

void calculateMedian(struct Student students[], int studentCount){
    float median;
    qsort(students, studentCount, sizeof(struct Student), compareStudentsByNumericGrade);
    if (studentCount % 2 == 0) {
        /*If the number of students is even, average the two middle values*/ 
        median = (students[(studentCount / 2) - 1].percentMark + students[studentCount / 2].percentMark) / 2.0;
    } else {
        /* If the number of students is odd, the median is the middle value*/
       median = students[studentCount / 2].percentMark;
    }
    printf("Median Percent Mark:  %.2f\n", median);
}


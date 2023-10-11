/*******************************************************************
* Student Name: Akpoguma Oghenerukevwe
* Student Number:041075624
* Course: 23S_CST8234
* Declaration:
* This is my own original work except where sources have been cited.
*******************************************************************/

#include <stdio.h>
#include "ass2.h"

int compareStudentsByID(const void *a, const void *b) {
    const struct Student *studentA = (const struct Student *)a;
    const struct Student *studentB = (const struct Student *)b;
    return studentA->studentID - studentB->studentID;
}

int compareStudentsByNumericGrade(const void* a, const void* b) {
    const struct Student *studentA = (const struct Student *)a;
    const struct Student *studentB = (const struct Student *)b;
    int end;
    double percentMarkA = studentA->percentMark;
    double percentMarkB = studentB->percentMark;

    /* Sort the percentages */
    if (percentMarkA < percentMarkB) {
        end = -1;
    } else if (percentMarkA > percentMarkB) {
        end = 1;
    } 
    return end;
}

char* sortGrades(struct Student *studentA) {
    char *letterGrade;
    if (studentA->percentMark >= 90){
        letterGrade = "A+";
    }else if (studentA->percentMark >= 85){
        letterGrade = "A";
    }else if (studentA->percentMark >= 80){
        letterGrade = "A-";
    }else if (studentA->percentMark >= 77){
        letterGrade = "B+";
    }else if (studentA->percentMark >= 73){
        letterGrade = "B";
    }else if (studentA->percentMark >= 70){
        letterGrade = "B-";
    }else if (studentA->percentMark >= 67){
        letterGrade = "C+";
    }else if (studentA->percentMark >= 63){
        letterGrade = "C";
    }else if (studentA->percentMark >= 60){
        letterGrade = "C-";
    }else if (studentA->percentMark >= 57){
        letterGrade = "D+";
    }else if (studentA->percentMark >= 53){
        letterGrade = "D";
    }else if (studentA->percentMark >= 50){
        letterGrade = "D-";
    }else if (studentA->percentMark >= 0){
        letterGrade = "F";
    } else {
        letterGrade = "Invalid";
    }
    return letterGrade;
}






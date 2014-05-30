/*---------------------------------
* C Fields
* 90.267 C Programming
* Programming Assignment #4
* 4/22/2014
* Structures
*----------------------------------*/

/*---------------------------------
*Reprogram asignment #3 by using structures
*
*----------------------------------*/

#include <stdio.h>

#define MAXIMUMSTUDENTS 50

struct studentRecord
{
    int  id;
    int  score;
    char grade;
}classRecords[MAXIMUMSTUDENTS];


struct  studentRecord bestStudent(struct studentRecord Table[], int studentCount);
void    displayArrays(struct studentRecord Table[], int count);
int     fill_arrays( struct studentRecord Table[] );
void    setStudentGrades( struct studentRecord *Student, int classGrades[]);
float   averageGrade(struct studentRecord Table[], int classSize);
int     getAboveAverage(struct studentRecord Table[], int studentCount, int average);

int main(void)
{
    
    int classGrades[5] = { 0,0,0,0,0 }; // [0] = # of A's ... [4] = # of F's

    int i, studentCount, aboveAvgCount, indexTopScore = 0;
    float classAverage;
    struct studentRecord beststudentrecord;

    //  Welcome statements
    printf ("Welcome, Please enter upto %i pairs of Student ID's & scores.\n", MAXIMUMSTUDENTS);
    printf ("To halt the data entry process, enter 0 for the Student ID.\n\n");

    //  Gather Input
    studentCount = fill_arrays(classRecords);
    //  Disregard computation & printing when there is an immediate exit
    if ( studentCount != 0 ) {
/*

    //  Build letter grades from numerical grades
        setStudentGrades(studentScore, studentGrade, classGrades, studentCount);
*/
    //  Print ID's, Numerical & Alphabetical grades
        printf ("Report - Original data:\n");

        for (i = 0; i < studentCount; ++i){
          setStudentGrades(&classRecords[i], classGrades);
        }

        displayArrays(classRecords, studentCount);

    //  Class average, # of students above class average
        classAverage = averageGrade(classRecords, studentCount);
        printf ("The average test score was: %3.2f, \n", classAverage);

    // Determine the student with the best grades
        beststudentrecord = bestStudent(classRecords, studentCount);
        printf ("The Student ID # %i received the highest score of: %i, for a grade of: %c\n", beststudentrecord.id, beststudentrecord.score, beststudentrecord.grade);

    //  Alphabetical Grade Distribution
        printf ("The grade distribution is:\n");
        printf ("\tA: %i\n\tB: %i\n\tC: %i\n\tD: %i\n\tF: %i\n\n", classGrades[0], classGrades[1], classGrades[2], classGrades[3], classGrades[4]);
    
    //  Determine the # of students who scored over the class average
        aboveAvgCount = getAboveAverage(classRecords, studentCount, classAverage);
        printf ("There were %d students that scored above the class average.\n", aboveAvgCount);

    }
}

void setStudentGrades( struct studentRecord *Student, int classGrades[] )
{
    

    switch(Student->score) {
    case 90 ... 100:
        Student->grade = 'A';
        classGrades[0] += 1;
        break;

    case 80 ... 89:
        Student->grade = 'B';
        classGrades[1] += 1;
        break;

    case 70 ... 79:
        Student->grade = 'C';
        classGrades[2] += 1;
        break;

    case 60 ... 69:
        Student->grade = 'D';
        classGrades[3] += 1;
        break;

    case 1 ... 59:
        Student->grade = 'F';
        classGrades[4] += 1;
        break;
    }

}

int fill_arrays( struct studentRecord Table[] )
{
    int i;

    for ( i = 0; i < MAXIMUMSTUDENTS; ++i ) {
        printf ("\tStudent's ID: ");
        scanf  ("%i", &Table[i].id );
        //  Exit loop when student ID equals 0
        if ( Table[i].id == 0 ) {
            printf("End of data collection.\n\n");
            break;
        }

        do {
            printf ("\tEnter Grade: ");
            scanf  ("%i", &Table[i].score);

            if ( Table[i].score >= 0 && Table[i].score <= 100 )
              break;
            else
              printf ("\t*Error: Input %d, is out of range.*\n\tPlease use an integer from 0 to 100.\n", Table[i].score);
        }
        while (1);

    }

    return i; // becomes studentCount
}
void displayArrays(struct studentRecord Table[], int count )
{
    int i;

    printf ("\t--------------------\n");
    printf ("\t ID : Score : Grade\n");
    printf ("\t--------------------\n");
    for (i = 0; i < count; ++i) {
        printf ("\t%4i   %3i      %c \n", Table[i].id, Table[i].score, Table[i].grade);
    }
    printf ("\t--------------------\n\n");
}

float averageGrade(struct studentRecord Table[], int classSize)
{
    int i, sum = 0;

    for ( i = 0; i < classSize; ++i ) {
        sum += Table[i].score;
    }

    return (float)sum / classSize;
}

struct studentRecord bestStudent(struct studentRecord Table[], int studentCount)
{
    int i, max, bestRecordNum = 0;

    for (i = 0; i < studentCount; ++i)
        if (Table[i].score > max) {
            max = Table[i].score;
            bestRecordNum = i;
        }

    return Table[bestRecordNum];
}

int getAboveAverage(struct studentRecord Table[], int studentCount, int average)
{
    int i, studentCountAboveAvg = 0;

    for (i = 0; i < studentCount; ++i)
        if (Table[i].score > average) {
            studentCountAboveAvg += 1;
        }

    return studentCountAboveAvg;
}
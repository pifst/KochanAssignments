/*---------------------------------
* Christopher Fields
* 90.267 C Programming
* Programming Assignment #4
* 4/21/2014
* Structures
*----------------------------------*/

/*---------------------------------
*Reprogram pg #3 thru the use of structures:
*
* After checking input integrity & building Grade array
* - Print the 3 arrays (function)
* Sort arrays in ascending order by student id
* - Print 3 arrays (function)
* compute average; return value to main
* - print from main
* find student id with higest score; return index to main
* - print from main: name, score, letter grade
* Using switch/case statements;
* - print # of A's, B's, C's, D's, F's
* - print number of grades above average
* Sort arrays in descending order by test score
* - Print 3 arrays (function)
*----------------------------------*/

#include <stdio.h>

#define MAXIMUMSTUDENTS 50
#define ASCENDING        0
#define DESCENDING       1

  int  fill_arrays        (int studentID[], int studentScore[]);
 void  setStudentGrades   (int studentScore[], char studentGrade[], int classGrades[], int studentCount);
 void  displayArrays      (int studentID[], int studentScore[], char studentGrade[], int studentCount);
float  averageGrade       (int scores[], int classSize);
  int  bestStudent        (int studentScore[], int studentCount);
  int  getAboveAverage    (int studentScore[], int studentCount, int average);
 void  sortStudentData    (int array1[], int array2[], char array3[], int n, int direction);


int main(void)
{
    int studentID[MAXIMUMSTUDENTS], studentScore[MAXIMUMSTUDENTS];
    char studentGrade[MAXIMUMSTUDENTS];
    int classGrades[5]; // [0] = # of A's ... [4] = # of F's
    int studentCount, aboveAvgCount, indexTopScore = 0;
    float classAverage;

    //  Welcome statements
    printf ("Welcome, Please enter upto %i pairs of Student ID's & scores.\n", MAXIMUMSTUDENTS);
    printf ("To halt the data entry process, enter 0 for the Student ID.\n\n");

    //  Gather Input
    studentCount = fill_arrays(studentID, studentScore);

    //  Disregard computation & printing when there is an immediate exit
    if ( studentCount != 0 ) {

    //  Build letter grades from numerical grades
        setStudentGrades(studentScore, studentGrade, classGrades, studentCount);

    //  Print ID's, Numerical & Alphabetical grades
        printf ("Report - Original data:\n");
        displayArrays(studentID, studentScore, studentGrade, studentCount);

    //  Sort the arrays thru ascending order of StudentID[]
        printf ("Report - Student ID Ascending:\n");
        sortStudentData(studentID, studentScore, studentGrade, studentCount, ASCENDING);
        displayArrays(studentID, studentScore, studentGrade, studentCount);

    //  Class average, # of students above class average
        classAverage = averageGrade(studentScore, studentCount);
        printf ("The average test score was: %3.2f, ", classAverage);
        aboveAvgCount = getAboveAverage(studentScore, studentCount, classAverage);
        printf ("of which %d students scored over the average.\n", aboveAvgCount);

    //  Find the classes' best student
        indexTopScore = bestStudent(studentScore, studentCount);
        printf ("The Student ID # %i received the highest score of: %i, for a grade of: %c\n", studentID[indexTopScore], studentScore[indexTopScore], studentGrade[indexTopScore]);
    
    //  Alphabetical Grade Distribution
        printf ("The grade distribution is:\n");
        printf ("\tA: %i\n\tB: %i\n\tC: %i\n\tD: %i\n\tF: %i\n\n", classGrades[0], classGrades[1], classGrades[2], classGrades[3], classGrades[4]);

    //  Sort the arrays thru descending order of StudentScore[]
        printf ("Report - Student Score Descending:\n");
        sortStudentData(studentScore, studentID, studentGrade, studentCount, DESCENDING);
        displayArrays(studentID, studentScore, studentGrade, studentCount);
    }
}

void sortStudentData(int array1[], int array2[], char array3[], int n, int DIRECTION)
{
   /* Function to sort a passed array in [pre-determined] order */
    int i, j, k, temp, temp2, temp3;

    for( i = 0; i < (n - 1); ++i )

      for( j = i + 1; j < n; ++j )

        switch(DIRECTION) {

        case ASCENDING:
            if ( array1[i] > array1[j] ) {
              /* swap array1 id elements */
              temp = array1[i];
              array1[i] = array1[j];
              array1[j] = temp;

              /* swap the array2 elements */
              temp2 = array2[i];
              array2[i] = array2[j];
              array2[j] = temp2;

              /* swap the array3 elements */
              temp3 = array3[i];
              array3[i] = array3[j];
              array3[j] = temp3;
            }
        break;

        case DESCENDING:
            if ( array1[i] < array1[j] ) {
              /* swap array1 id elements */
              temp = array1[i];
              array1[i] = array1[j];
              array1[j] = temp;

              /* swap the array2 elements */
              temp2 = array2[i];
              array2[i] = array2[j];
              array2[j] = temp2;

              /* swap the array3 elements */
              temp3 = array3[i];
              array3[i] = array3[j];
              array3[j] = temp3;
            }
        break;

        default:
          printf ("Error: sorting direction is not recognized.");
      }

    return;
}

int getAboveAverage(int studentScore[], int studentCount, int average)
{
    int i, aboveAverage = 0;

    for (i = 0; i < studentCount; ++i)
        if (studentScore[i] > average) {
            aboveAverage += 1;
        }

    return aboveAverage;
}

int bestStudent(int studentScore[], int studentCount)
{
    int i, max, maxIndex = 0;

    for (i = 0; i < studentCount; ++i)
        if (studentScore[i] > max) {
            max = studentScore[i];
            maxIndex = i;
        }

    return maxIndex;
}

float averageGrade(int scores[], int classSize)
{
    int i, sum = 0;

    for ( i = 0; i < classSize; ++i ) {
        sum += scores[i];
    }

    return (float)sum / classSize;
}

void displayArrays(int studentID[], int studentScore[], char studentGrade[], int studentCount)
{
    int i;

    printf ("\t--------------------\n");
    printf ("\t ID : Score : Grade\n");
    printf ("\t--------------------\n");
    for (i = 0; i < studentCount; ++i) {
        printf ("\t%4i   %3i      %1c \n", studentID[i], studentScore[i], studentGrade[i]);
    }
    printf ("\t--------------------\n\n");
}

void setStudentGrades(int studentScore[], char studentGrade[], int classGrades[], int studentCount)
{
    int i;

    for ( i = 0; i < studentCount; ++i ) {

        switch(studentScore[i]) {
        case 90 ... 100:
            studentGrade[i] = 'A';
            classGrades[0] += 1;
            break;

        case 80 ... 89:
            studentGrade[i] = 'B';
            classGrades[1] += 1;
            break;

        case 70 ... 79:
            studentGrade[i] = 'C';
            classGrades[2] += 1;
            break;

        case 60 ... 69:
            studentGrade[i] = 'D';
            classGrades[3] += 1;
            break;

        case 0 ... 59:
            studentGrade[i] = 'F';
            classGrades[4] += 1;
            break;
        }
    }
}

int fill_arrays(int studentID[], int studentScore[])
{
    int i;

    for ( i = 0; i < MAXIMUMSTUDENTS; ++i ) {
        printf ( "\tStudent's ID: " );
        scanf  ( "%i", &studentID[i] );

        //  Exit loop when student ID equals 0
        if ( studentID[i] == 0 ) {
            printf("End of data collection.\n\n");
            break;
        }

        do {
            printf ("\tEnter Grade: ");
            scanf  ("%i", &studentScore[i] );

            if ( studentScore[i] >= 0 && studentScore[i] <= 100 )
              break;
            else
              printf ("\t*Error: Input %d, is out of range.*\n\tPlease use an integer from 0 to 100.\n", studentScore[i]);
        }
        while (1);

    }

    return i; // becomes studentCount
}

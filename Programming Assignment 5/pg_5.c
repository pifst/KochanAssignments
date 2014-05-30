/*---------------------------------
* C Fields
* 90.267 C Programming
* Programming Assignment #5
* 5/6/2014
* Voting Application
*----------------------------------*/

/*---------------------------------
* The purpose of this assignment is to reinforce the relationship between 
* array names and pointers, dynamic memory allocation, passing arrays and 
* pointer arithmetic.
*----------------------------------*/

#include <stdio.h>
#include <stdlib.h>

void fillArrays     (int array1[], int array2[], int count);
void displayArrays  (int *array1, int *array2, int count);
 int countVotes     (int *array, int count);
 int electionWinner (int array[], int count);

int main(void)
{
    int totalCandidates, totalVotes, winnerIndex = 0;
    int *candidateID, *votesReceived;

    printf ("Welcome, How many candiates are running in this election? > ");
    scanf ("%i", &totalCandidates);

    candidateID   = (int *) calloc (totalCandidates,sizeof(int));
    votesReceived = (int *) calloc (totalCandidates,sizeof(int));

    if (candidateID == NULL || votesReceived == NULL) {
       printf("\n\ncalloc() failed in file %s at line # %d", __FILE__,__LINE__);
       exit(1);
    }

    fillArrays(&candidateID[0], &votesReceived[0], totalCandidates);

    displayArrays(candidateID, votesReceived, totalCandidates);
    
    totalVotes = countVotes(votesReceived, totalCandidates);
    printf ("The total votes cast: %d\n", totalVotes);

    winnerIndex = electionWinner(votesReceived, totalCandidates);
    printf ("The election winner is ID number %d with: %i votes\n", candidateID \
        [winnerIndex], votesReceived[winnerIndex]);
}

/* when calling the fillArrays pass the arrays to the function using array subscript 
notation and use array subscript notation in all of your procesing statements in the 
function. */
void fillArrays(int array1[], int array2[], int count)
{
    int i;

    for ( i = 0; i < count; ++i ) {
        printf ( "\tCanidates's ID: " );
        scanf  ( "%i", &array1[i] );

        do {
            printf ("\tEnter # of received votes: ");
            scanf  ("%i", &array2[i] );

            if ( array2[i] > 0 )
              break;
            else
              printf ("\t*Error: Input %d, is out of range.*\n\tPlease use a number 0 \
               or higher.\n", array2[i]);
        }
        while (1);
    }
}

/* When calling displayArrays pass the arrays as pointers and use "pointer reference 
notation ex: *(ptr + i)" */
void displayArrays(int *array1, int *array2, int count)
{
    int i;

    printf ("\t-------------------------\n");
    printf ("\t| Canidate ID |  Vote # |\n");
    printf ("\t-------------------------\n");
    for (i = 0; i < count; ++i) {
        printf ("\t|     %4i    |   %4i  |\n", *(array1 +i), *(array2 +i) );
    }
    printf ("\t-------------------------\n");
    return 0;
}

/* For countVotes pass the arrays as pointers to the functions and use 
"pointer arithmetic" ex: *ptr++ for summing up the votes. */
int countVotes(int *array, int count)
{
    int i = 0;
    int sum = 0;

    for ( i = 0; i < count; ++i ) {
        sum += *array++;
    }

    return sum;
}

/* Use notation of your choice. */
int electionWinner(int array[], int count)
{
    int i, max, maxIndex = 0;

    for (i = 0; i < count; ++i)
        if (array[i] > max) {
            max = array[i];
            maxIndex = i;
        }

    return maxIndex;
}
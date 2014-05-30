/*---------------------------------
 *  C Fields
 *  90.267 C Programming
 *  Programming Assignment #1
 *  2/24/2014
 *  Part 1 of 2: Whileloop
 *----------------------------------*/

/*---------------------------------- 
 *  Test Cases:
 *  1. 10 gallons, $.39 per Liter
 *  2. 5 gallons, $.50 per Liter
 *----------------------------------*/

/*
 This program prompts for two inputs:
    1) Amount of fuel purchased in gallons
    2) Cost of fuel in dollars per liter
 Using this information the program generates a bill of sale,
 consisting of volume of fuel used in gallons, liters, and cost.
 This version of the program iterates using a while loop.
 */

//  Declaring libraries
#include <stdio.h>

//  Adds ability to format printf by region
#include <locale.h>


int main(void)
{
    // Set locality to English/United States, UTF-8
    setlocale(LC_NUMERIC, "en_US.UTF-8");
    
    
	//  Declare Variables
	int gallon_input, count = 1;
	float calc_liters, costperLiter_input, calc_cost;
    
    
	//  Define Constant
    float const liters_per_gallon = 3.785;
    
    
    //  Gather tested user input
    do {
        printf ("Gallons of fuel purchased -> ");
        scanf ("%i", &gallon_input);
        
        // Provide error feedback if gallon_input is out of range
        if ( gallon_input <= 0 || gallon_input > 100 )
            printf ("Error: Input should be an integer from 1 to 100 \n");
    }
    //  Ends loop on false;
    while ( gallon_input <= 0 || gallon_input > 100 );
    
    //  Gather untested user input
    printf ("Cost per liter -> ");
	scanf ("%f", &costperLiter_input);
    
    //  Print header of invoice
	printf ("\n\t  Gasoline Charges\n\n");
	printf ("Gallons\t\tLiters\t\tCost\n");
    printf ("--------------------------------\n");
    
    //  Loop iterates, printing data until count exceeds gallon_input
	while ( count <= gallon_input ) {
        
        //  Calculate liters & cost per iteration of count
		calc_liters = liters_per_gallon * count;
		calc_cost = costperLiter_input * calc_liters;
        
        //  Print row of data
        //  ' in $%'3.2f formats a comma every 3 signifigant numbers
		printf ("\t%2d\t\t%2.3f\t\t$%'3.2f\n", count, calc_liters, calc_cost);
        
        //  Increment by one
		count++;
	}
    
    printf ("--------------------------------\n");
    
	return 0;
}
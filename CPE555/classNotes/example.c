/*
 * Example program for CPE-555 Real-Time and Embedded Systems
 * Stevens Institute of Technology
 * Instructor: Richard Prego
 * Fall 2018
 */

#include <stdio.h>

/* declare array of numbers (integer type) */
int numbers[4];

/* declare functions that are defined below */
void populate_array();
int check_for_even(int number);

/* main function */
int main()
{
    /* declare local variable to use as a flag */
    int is_even;

    /* print a welcome message */
    printf("Welcome to the program!\n");

    /* call a function that requests user to enter numbers */
    populate_array();

    /* use a for loop to loop through the array */
    for (int i = 0; i < 4; ++i)
    {
        /* call a function to check even/odd */
        is_even = check_for_even(numbers[i]);

        /* print even or odd based on result */
        if (is_even == 1)
        {
            printf("numbers[%d] = %d, EVEN\n", i, numbers[i]);
        }
        else
        {
            printf("numbers[%d] = %d, ODD\n", i, numbers[i]);
        }
    }

    return 0;
}

/* function for requesting numbers from user */
void populate_array()
{
    /* use a for loop to request 4 numbers */
    for (int i = 0; i < 4; ++i)
    {
        /* print the prompt */
        printf("Enter # %d: ", i);

        /* read the number that was typed */
        scanf("%d", &numbers[i]);
    }
}

/* function to check for even/odd */
int check_for_even(int number)
{
    /* check if odd (mod result is 1) */
    if ((number % 2) == 1)
    {
        /* result of function call is 0 if odd */
        return 0;
    }
    else
    {
        /* result of function call is 1 if even */
        return 1;
    }
}

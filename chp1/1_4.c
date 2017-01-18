/*
 * Write a program to print the corresponding Celsius to
 * Fahrenheit table
 * C = (5/9)*(F-32)
 * F = C/(5/9) + 32
 */

#include <stdio.h>

#define LOWER 0
#define UPPER 30
#define STEP  2 

int main(void)
{
    float centi, fahren;

    centi = 0;

    printf(" centi fahren\n");    
    while(centi <= UPPER) {
        fahren = centi / (5.0 / 9.0) + 32; 
        printf("%6.0f %6.1f\n",centi, fahren);
        centi += STEP;
    }

    return 0;
}

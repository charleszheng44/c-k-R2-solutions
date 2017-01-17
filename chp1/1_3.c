/*
 * Modify the temperature conversion program to print a heading
 * above the table
 * C = (5/9)*(F-32)
 */

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20

int main(void)
{
    float fahre, centi;

    fahre = 0;
    
    printf("%6s %6s\n", "fahre", "centi");
    while(fahre <= UPPER)  {
        centi = 5.0 / 9.0 * (fahre - 32);
        printf("%6.0f %6.1f\n", fahre, centi);
        fahre += STEP;
    }

    return 0;

}

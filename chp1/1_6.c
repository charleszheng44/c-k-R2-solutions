/*
 * Verify that the expression getchar() != EOF is 0 or 1
 * ctrl-D is refered to EOF
 */

#include <stdio.h>

int main(void) 
{
    printf("Plz enter a character:\n");
    printf("The expression getchar() != EOF evaluates to %d\n", getchar() != EOF); 
    return 0;
}

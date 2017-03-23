/*
 * In a two's complement number representation, our version of itoa does not handle the 
 * largest negative number, that is, the value of n equal to -(2 to the power (wordsize - 1)) . 
 * Explain why not. Modify it to print that value correctly regardless of the machine on which 
 * it runs.
 *
 * The range of the two's complement number is from -(2 to the power (wordsize - 1)) to 
 * (2 to the power (wordsize - 1)) - 1, in our itoa, if the input is a negtive number, we will
 * first get its absolute value. Thus we can not represent the absoult value of 
 * -(2 to the power (wordsize - 1)). 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define str_len 20

void reverse(char s[]) 
{
    int i, j;
    char tmp;
    for(i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

void itoa(int n, char s[]) 
{ 
    int i, sign;
    i = 0;

    if((sign = n) < 0) {
        n = -n;
    }

    do {
        s[i++] = abs(n % 10) + '0';
    } while( n /= 10 );
    if(sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

int main(void) 
{
    int n = -128;
    char s[str_len];
    itoa(n, s);
    printf("%d -> %s\n", n, s);
    return 0;
}

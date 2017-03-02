/*
 * Write a function invert(x,p,n) that returns x with the n bits that 
 * begin at position p inverted (i.e., 1 changed into 0 and vice versa), 
 * leaving the others unchanged.
 */

#include <stdio.h>
#include <stdlib.h>
#define STR_LEN 32

const char *integer_to_binary_str(unsigned int n);
unsigned int invert(unsigned int x, int p, int n);

int main(void)
{
    unsigned int x = 5732;
    printf("%u -> %u\n", x, invert(5732, 6, 3));
    return 0;
}

unsigned int invert(unsigned int x, int p, int n)
{
    unsigned mask = ~(~0U << n) << (p+1-n);
    return x ^ mask;
}

const char *integer_to_binary_str(unsigned int n)
{
    char buff[STR_LEN];
    char reminder;
    int j = 0;
    while(n >= 1) {
        
        reminder = (n % 2 == 1 ? '1' : '0');
        buff[j++] = reminder; 

        n = n / 2; 
    } 

    char *bin_str = malloc(j * sizeof(char));
    int i;
    for(i = 0, j = j-1; j >= 0; j--, i++) {
        bin_str[i] = buff[j];
    }
   
    return (const char *)bin_str; 
}

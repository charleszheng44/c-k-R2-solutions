/*
 * Write a function setbits(x,p,n,y) that returns x with the n bits that begin at 
 * position p set to the rightmost n bits of y, leaving the other bits unchanged.
 */

#include <stdio.h>
#include <stdlib.h>
#define STR_LEN 32

const char *integer_to_binary_str(int n);

int main(void)
{
    int n = 56;
    const char *bin_str = integer_to_binary_str(n);
    printf("The binary format of %d is %s\n", n, bin_str);
    return 0;
}

const char *integer_to_binary_str(int n)
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

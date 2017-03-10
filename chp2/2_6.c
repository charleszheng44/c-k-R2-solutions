/*
 * Write a function setbits(x,p,n,y) that returns x with the n bits that begin at 
 * position p set to the rightmost n bits of y, leaving the other bits unchanged.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define STR_LEN 32

const char *integer_to_binary_str(unsigned int n);
unsigned int setbits(unsigned int x, int p, int n, unsigned int y);

int main(void)
{
   
    unsigned int x = 156;
    unsigned int y = 56;
    
    int p = 23;
    int n = 4;

    printf("%u\n", setbits(x, p, n, y)); 

    return 0;
}

unsigned int setbits(unsigned int x, int p, int n, unsigned int y)
{
    size_t len = sizeof(unsigned int) * CHAR_BIT; 
    // get [1...1][0..0][1...1]
    unsigned int zero_mask = (~0 << (len-p)) | (~0 >> (len-p-n)); 
    unsigned int one_mask = ~zero_mask;
    // set the n bits in x start at p as 0
    unsigned int tmp_x = zero_mask & x;

    unsigned int tmp_y = (~0 << (len-p-n)) & one_mask;

    return tmp_x | tmp_y;
    
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

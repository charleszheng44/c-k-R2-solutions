/*
 * In a two's complement number system, x &= (x-1) deletes the rightmost 
 * 1-bit in x . Explain why. Use this observation to write a faster 
 * version of bitcount . 
 *
 * eg.
 * 
 * 156 => 010011100 (which contains 4 bits)
 *
 */

#include <stdio.h>

int bitcount(unsigned int x);

int main(void)
{
    unsigned int x = 156;
    printf("%u has %d bits\n", x, bitcount(x));
    return 0;
}

int bitcount(unsigned int x) 
{
    int b;
    for(b = 0; x != 0; x &= (x-1)) {
        printf("%u\n", x);
        b ++;
    }
    return b;
}

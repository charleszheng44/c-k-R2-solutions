/*
 * Write a function rightrot(x,n) that returns the value of the 
 * integer x rotated to the right by n bit positions.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define STR_LEN 1024

unsigned int rightrot(unsigned int x, unsigned int n);

int main(void)
{
    unsigned int a = 156;
    unsigned int b = rightrot(156, 3);

    printf("%u -> %u\n", a, b);
    return 0;
}

unsigned int rightrot(unsigned int x, unsigned int n)
{
    size_t len = sizeof(x) * CHAR_BIT;
    size_t rot;

    if(n >= len) {
        rot = n % len;
    } else {
        rot = n;
    }

    if((x == 0) || (rot == 0)) {
        return x;
    }

    return (x >> rot) | (x << (len - rot));
}

/*
 * Write a function rightrot(x,n) that returns the value of the 
 * integer x rotated to the right by n bit positions.
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define STR_LEN 1024

const char *integer_to_binary_str(unsigned int n);
unsigned int rightrot(unsigned int x, unsigned int n);

int main(void)
{
    unsigned int a = 156;
    unsigned int b = rightrot(156, 3);

    printf("%u : %s -> %u : %s \n", a, integer_to_binary_str(a), b, integer_to_binary_str(b));
    return 0;
}

unsigned int rightrot(unsigned int x, unsigned int n)
{

    unsigned int y = x;
    unsigned int len = 0;
    size_t s = sizeof(x) * CHAR_BIT;

    while(y >= 1) {
        y = y / 2;
        len ++;     
    }
    
    printf("num of bits: %u\n", len);

    unsigned int rot;

    if(n >= len) {
        rot = n % len;
    } else {
        rot = n;
    }

    printf("rotate of bits: %u\n", rot);
    if((x == 0) || (rot == 0)) {
        return x;
    }
   
    unsigned int a = x >> rot;
    unsigned int b = (x & (~(~0U << rot))) << (len - rot);
     
    printf("num a: %u binary format: %s\n", a, integer_to_binary_str(a));
    printf("num b: %u binary format: %s\n", b, integer_to_binary_str(b));

    return (a | b);
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

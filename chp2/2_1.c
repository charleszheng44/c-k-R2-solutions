/*
 * Write a program to determine the ranges of char , short , int , and long variables, 
 * both signed and unsigned , by printing appropriate values from standard headers and by 
 * direct computation. Harder if you compute them: determine the ranges of the various 
 * floating-point types.
 */

#include <stdio.h>
#include <limits.h>

int main(void) 
{
    printf("The range of char is: [%d, %d]\n", CHAR_MIN, CHAR_MAX);
    printf("The range of short is: [%d, %d]\n", SHRT_MIN, SHRT_MAX);
    printf("The range of int is: [%d, %d]\n", INT_MIN, INT_MAX);
    printf("The range of long is: [%ld, %ld]\n", LONG_MIN, LONG_MAX);

    printf("The range of unsigned char is: [%d, %u]\n", 0, UCHAR_MAX);
    printf("The range of unsigned short is: [%d, %u]\n", 0, USHRT_MAX);
    printf("The range of unsigned int is: [%d, %u]\n", 0, UINT_MAX);
    printf("The range of unsigned long is: [%d, %lu]\n", 0, ULONG_MAX);

    return 0;

}



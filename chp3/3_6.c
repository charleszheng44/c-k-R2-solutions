/*
 * Write a version of itoa that accepts three arguments instead of two. The third argument is 
 * a minimum field width; the converted number must be padded with blanks on the left if 
 * necessary to make it wide enough.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 64

void itoa(int n, char s[], int w);
static void reverse(char s[]);

int main(void)
{

    int i = -13541;
    int w = 10;
    char s[STR_LEN];
    itoa(i, s, w);
    printf("%s\n", s);
    return 0;
}

void itoa(int n, char s[], int w)
{
   
    if(w >= STR_LEN) {
        fprintf(stderr, "The max field width can not be longer thatn %d\n", STR_LEN);
        exit(1);
    }

    int i = 0; 
    int sign = n;

    do{
        
        s[i++] = abs(n % 10) + '0';

    } while(n /= 10);
    
    if(sign < 0) {
        s[i++] = '-';
    }

    int len = i;

    if(len < w) {
        int j;
        for(j = w-len; j > 0; j--, i++) {
            s[i] = ' ';
        }
    }
    s[i] = '\0';
    reverse(s);
}

static void reverse(char s[])
{
    int i, j;
    char tmp;
    for(i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

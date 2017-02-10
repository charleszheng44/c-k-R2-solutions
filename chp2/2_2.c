/*
 * Write a loop equivalent to the for loop above without using && or || .
 * 
 * for(i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
 *     s[i] = c;
 */

#include <stdio.h>
#define MAX_STR_LEN     1024

int main(void)
{
    int i;
    int lim = MAX_STR_LEN;

    char str[MAX_STR_LEN];
    char c;

    for(i = 0; i < lim-1; ++i) {
        c = getchar();
        if(c == '\n') {
            break;
        }

        if(c == EOF) {
            break;
        }
        str[i] = c;
    } 

    if(c == '\n') {
        str[i++] = c;
    }

    str[i] = '\0';

    return 0;
}

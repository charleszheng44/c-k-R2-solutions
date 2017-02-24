/*
 * Write an alternate version of squeeze(s1,s2) that deletes each
 * character in s1 that matches any character in the string s2.
 */

#include <stdio.h>

int squeeze(char s[], char t[]);

int main(void) 
{
    char s[] = "abcadef";
    char t[] = "ae";
    squeeze(s, t);
    printf("The squeezed string is %s\n", s);
    return 0;
}

int squeeze(char s[], char t[])
{
    int i, j, k;
    for(k = 0; t[k] != '\0'; k++) {
        for(i = j = 0; s[i] != '\0'; i++) {
            if(s[i] != t[k]) {
                s[j++] = s[i];
            }    
        }
        s[j] = '\0';
    }
}

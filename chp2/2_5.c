/*
 * Write the function any(s1,s2) , which returns the first location in the string s1 where any 
 * character from the string s2 occurs, or -1 if s1 contains no characters from s2 . 
 * (The standard library function strpbrk does the same job but returns a pointer to the location.)
 */

#include <stdio.h>

int any(char s1[], char s2[]);

int main(void)
{
    char s1[] = "aklauwjdkj";
    char s2[] = "bces";
    int r;

    r = any(s1, s2); 
    if(r == -1) {
        puts("There is no character in s1 that appears in s2 as well\n");
    }
    return 0;
}

int any(char s1[], char s2[]) 
{
    int i,j;

    for(i = 0; s2[i] != '\0'; i++)
    {
        for(j = 0; s1[j] != '\0'; j++) {
            if(s1[j] == s2[i]) {
                printf("The first character is %c at %d\n", s1[j], j);
                return j;
            }
        }
    } 

    return -1;
}

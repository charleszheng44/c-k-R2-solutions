/*
 * Write the function strrindex(s,t) , which returns the position of the rightmost occurrence of t in s , 
 * or -1 if there is none.
 */

#include <stdio.h>
#include <string.h>

int strlindex(const char *s, const char *t);
int strrindex(const char *s, const char *t);

int main(void)
{
    char *s = "thistrisateststring";
    char *t = "str";
    printf("%s first appears at %d of %s\n", t, strlindex(s, t), s);
    printf("%s last appears at %d of %s\n", t, strrindex(s, t), s);
    return 0;
}

int strlindex(const char *s, const char *t)
{
    if(strlen(t) == 0) {
        return -1;
    }

    int i;

    for(i = 0; s[i] != '\0'; i++) {

        int j, k;

        for(j = 0, k = i; t[j] != '\0', t[j] == s[k]; j++, k++)
            ;

        if(t[j] == '\0')
            return i;

    }

    return -1;
}

int strrindex(const char *s, const char *t)
{
   
    if(strlen(t) == 0) {
        return -1;
    }

    int last;
    int i;
    
    for(i = 0, last = -1; s[i] != '\0'; i++) {

        int j, k;

        for(j = 0, k = i; t[j] != '\0', t[j] == s[k]; j++, k++)
           ;

        if(t[j] == '\0') {
            last = i;
        }
         
    }

    return last;
}


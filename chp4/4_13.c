/*
 * Write a recursive version of the function reverse(s), which reverses 
 * the string s in place. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *s);
static void reverse_intl(char *s, int size);

int main(void)
{
    char *str = "string";
    char *str_cpy = malloc(sizeof(*str));
    strcpy(str_cpy, str);
    reverse(str_cpy);
    printf("%s --(reverse)--> %s\n", str, str_cpy);
    return 0;
}

void reverse(char *s) 
{
    reverse_intl(s, strlen(s));
}

static void reverse_intl(char *s, int size)
{
    char tmp;
    if (size < 2) {
        return; 
    } else {
        reverse_intl(s + 1, size - 2);
        tmp = s[0];
        s[0] = s[size - 1];
        s[size - 1] = tmp;
        return;
    }
}

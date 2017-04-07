/*
 * Write a routine ungets(s) that will push back an entire string onto the input. Should ungets know about 
 * buf and bufp , or should it just use ungetch ?
 */

#include <stdio.h>
#include <string.h>

#define BUFSIZE 1024

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(char c) 
{
    if(bufp >= BUFSIZE) {
        fprintf(stderr, "ungetch: too many characters\n"); 
    } else {
        buf[bufp++] = c;   
    }
}

void ungets(char *s)
{
    int i = strlen(s) - 1;
    while(i >= 0) {
        ungetch(s[i--]);
    }
}

int main(void)
{
    char *s = "hello this is a test!";
    ungets(s);
    char c = getch();
    while( c != '\0') {
        printf("%c\n", c);
        c = getch();
    }
    return 0;
}

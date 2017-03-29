#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NUMBER  0
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int);
int getop(char s[]);

int main() {
    int type;
    char s[BUFSIZE];

    while ((type = getop(s)) != EOF) {
        if(type == NUMBER) {
            printf("+++++%s\n", s);
        }
    } 
    return 0;
} 

int getop(char s[])
{
    int i, c;
    while((s[0] = c = getch()) == ' ' || c == '\t') 
        ;
    s[1] = '\0';
    if(!isdigit(c) && c != '.')
        return c;
    i = 0;
    if(isdigit(c))
        while(isdigit(s[++i] = c = getch()))
            ;
    if(c == '.')
        while(isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if(c != EOF)
        ungetch(c);
    return NUMBER;
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
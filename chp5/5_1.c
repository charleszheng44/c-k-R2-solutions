#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFF_SIZE   64

int getch(void);
void ungetch(int);
int getint(int *);

char buf[BUFF_SIZE];
int bufp = 0;

int getch(void) 
{
    if(bufp > 0) {
        return buf[--bufp];
    } else {
        return getchar();
    }
}

void ungetch(int c)
{
    if(bufp >= BUFF_SIZE) {
        fprintf(stderr, "buffer overflow.\n");
    } else {
        buf[bufp++] = c;
    }
}

int getint(int *pn)
{
    char c;
    char tmp = 0;
    int sign;

    while(isspace(c = getch()))
        ;
    
    if(!isdigit(c) && c != EOF && c != '-' && c != '+') {
        ungetch(c);
        return 0;    
    }
    
    sign = (c == '-') ? -1 : 1; 

    if(c == '-' || c == '+') {
        tmp = c;
        c = getch();
    }

    if(!isdigit(c)) {
        ungetch(c);
        if(tmp != 0) {
            ungetch(tmp);
        }
        return tmp;
    } 
    
    for(*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
    } 

    *pn *= sign;
    if(c != EOF) {
        ungetch(c);
    }
    return c;
}

int main(void)
{
    int i, *pn, c;
    i = 0;
    pn = &i;
    c = getint(pn); 
        
    printf("The integer get from stdin is %d the return character is %c\n", *pn, c); 

    return 0;
}

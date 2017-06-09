
/*
 * Write getfloat, the floating-point analog of getint. 
 * What type does getfloat return as its function value?
 *
 * The return value of getfloat is still int
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUF_SIZE    64

int getch(void);
void ungetch(int);
int getfloat(float *);

char buf[BUF_SIZE];
int bufp = 0;

int getch(void) 
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp > BUF_SIZE) {
        fprintf(stderr, "buffer overflow");
    } else {
        buf[bufp++] = c;
    }

}

int getfloat(float *pn) 
{
    int c;
    int tmp = 0;
    int sign; 

    while(isspace(c = getch()))
        ;

    if(!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c);
        return 0;
    }

    if(c == '.') {
        goto PROC_DECIMAL;
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
    }
    
    for(*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
    }
    
    if(c != '.') {
        *pn = *pn * sign;
        return 0;
    }

PROC_DECIMAL: 
    
    if(!isdigit(c = getch())) {
        ungetch(c);
        return c;
    } 
    
    float curr_digit = 0.1;

    while(isdigit(c)) {
        *pn = *pn + curr_digit * (c - '0'); 
        curr_digit = curr_digit / 10;
    } 
    
    if(c != EOF) {
        ungetch(c);
    } 

    return c;
}

int main(void)
{
    return 0;
}

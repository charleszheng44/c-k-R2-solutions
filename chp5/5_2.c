
/*
 * Write getfloat, the floating-point analog of getint. 
 * What type does getfloat return as its function value?
 *
 * The return value of getfloat is still int
 */

#include <stdio.h>
#include <stdlib.h>

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

int getfloat(float *) 
{
}

int main(void)
{
    return 0;
}

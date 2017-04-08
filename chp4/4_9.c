/*
 * Our getch and ungetch do not handle a pushed-back EOF correctly. Decide what their properties 
 * ought to be if an EOF is pushed back, then implement your design.
 *
 * The reason why the code in K&R can't handle EOF is because it is defined as follows:
 * #define EOF -1
 * i.e. its value is negative and a char array can't hold a negative value.
 * Change the buffer type to int and the problem is solved.
 */

#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 100

int getch(void);
void ungetch(char c);

int buf[BUFSIZE];
int bufp = 0;

int main(void)
{
    char c;
    
    printf("The input from stdin is:\n");    
    while((c = getch()) != EOF) {
        printf("%c\n", c);
    }

    return 0;
}

int getch(void)
{
    return (bufp == 0) ? getchar() : buf[--bufp];
}

void ungetch(char c)
{
    if(bufp > BUFSIZE) {
        fprintf(stderr, "ungetch: too many character\n");
        exit(1);
    } else {
        buf[bufp++] = c;
    }
}

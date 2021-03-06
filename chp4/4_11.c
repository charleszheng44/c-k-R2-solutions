/*
 * Modify getop so that it doesn't need to use ungetch. Hint: use an 
 * internal static variable.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "stack.h"

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
    double op1, op2;
    double test;

    while ((type = getop(s)) != EOF) {
        switch(type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '*':
                push(pop() * pop());
                break;
            case '/':
                if((op2 = pop()) == 0.0) {
                    fprintf(stderr, "division by zero\n");
                    exit(1);
                }
                push(pop() - op2);
                break;
            case '%':
                if((op2 = pop()) == 0.0) {
                    fprintf(stderr, "division by zero\n");
                    exit(1);
                }
                push(fmod(pop(), op2));
                break;
            case '\n':
                printf("%f\n", pop());
                break;
            default:
                fprintf(stderr, "unknown operator %c", type);
                exit(1);
        }
    } 
    return 0;
} 

int getop(char s[])
{

    static int buf = 0;
    int i, c, next;

    if(buf) {
        c = buf; 
    } else {
        c = getch();
    }

    while((s[0] = c) == ' ' || c == '\t') 
            c = getch();
    
    s[1] = '\0';
    if(!isdigit(c) && c != '.' && c != '-')
        return c;
    
    if(c == '-') {
        if(!isdigit(next = getch()) && next != '.') {
            // '-' is an operator
            return c;
        }
        c = next;
    } else {
        c = getch();
    }

    // at this moment, we have processed the first
    // character and got the second character

    i = 0;
    while(isdigit(s[++i] = c))
        c = getch();
    
    if(c == '.')
        while(isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if(c != EOF)
        buf = c;
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

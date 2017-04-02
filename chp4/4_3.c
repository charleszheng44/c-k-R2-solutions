/*
 * Given the basic framework, it's straightforward to extend the calculator. 
 * Add the modulus ( % ) operator and provisions for negative numbers.
 *
 * TODO: In c the modulus operator is actually the remainder operator
 * Simplly using fmod(float f1, float f2)? or implement a real modulus 
 * operator?
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
    int i, c, next;
    while((s[0] = c = getch()) == ' ' || c == '\t') 
        ;
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

    i = 0;
    while(isdigit(s[++i] = c))
        c = getch();
    
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

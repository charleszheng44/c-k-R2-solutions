/*
 * Add access to library functions like sin , exp , and pow . See <math.h> in Appendix B, Section 4.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include "stack.h"

#define NUMBER      0
#define MATH_OPT    1     
#define BUFSIZE     100

char buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int);
int getop(char s[]);
void run_math_func(char s[]);

int main() {
    int type;
    char s[BUFSIZE];
    double op2;
    double test;

    while ((type = getop(s)) != EOF) {
        switch(type) {
            case NUMBER:
                push(atof(s));
                break;
            case MATH_OPT:
                run_math_func(s);
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
   
    i = 0; 

    if(isalpha(c)) {
        // first, process the possible math operator

        while(isalpha(s[++i] = c = getch())) 
            ;
        s[i] = '\0';

        if(c != EOF)
            ungetch(c);

        return MATH_OPT;

    } else {

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

void run_math_func(char s[]) 
{
    if(strcmp(s, "sin") == 0) {

        push(sin(pop()));

    } else if(strcmp(s, "exp") == 0) {

        push(exp(pop()));

    } else if(strcmp(s, "pow") == 0) {

        double power = pop();
        double base = pop();
        push(pow(base, power));

    } else {

        fprintf(stderr, "unsupported operator %s\n", s);
        exit(1);

    }
}

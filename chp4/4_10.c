/* 
 * TODO
 * An alternate organization uses getline to read an entire input line; 
 * this makes getch and ungetch unnecessary. Revise the calculator to 
 * use this approach.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#include "stack.h"

#define NUMBER          '0'
#define MAX_BUF_SIZE    1024

static int my_getline(char line[], int size);
static int getop(char s[], char line[]); 
static int line_i;

int main(void)
{ 

    char line[MAX_BUF_SIZE];
    char s[MAX_BUF_SIZE];
    int line_len;
    int type;
    double op_2;

    while((line_len = my_getline(line, MAX_BUF_SIZE)) != 0) {

        line_i = 0;

        while((type = getop(s, line)) != '\0') {
            switch(type) {
                case NUMBER:
                    push(atof(s));
                    break;

                case '+':
                    push(pop() + pop());
                    break;

                case '-':
                    op_2 = pop();
                    push(pop() - op_2);
                    break;

                case '*':
                    push(pop() * pop());
                    break;

                case '/':
                    op_2 = pop();
                    push(pop() / op_2);
                    break;

                case '%':
                    op_2 = pop();
                    push(fmod(pop(), op_2));
                    break;

                case '\n':
                    printf("%f\n", pop());
                    break;

                default:
                    fprintf(stderr, "unknown operator %d\n", type);
                    exit(EXIT_FAILURE);                

            }

        }

    }

    return 0;

}

static int getop(char s[], char line[])
{
    int j, c;
    while((s[0] = c = line[line_i++]) == ' ' || c == '\t') 
        ;
    
    s[1] = '\0';
    if(!isdigit(c) && c != '.') {
        return c;
    } 
    
    j = 0;
    if(isdigit(c)) {
        while(isdigit(s[++j] = c = line[line_i++])) 
            ;
    }
    
    if(c == '.') {
        while(isdigit(s[++j] = c = line[line_i++])) 
            ;
    }

    s[++j] = '\0';
    line_i --;
    return NUMBER; 

}

static int my_getline(char line[], int size) 
{
    char c;
    int i;
    i = 0;

    while((c = getchar()) != '\n' && c != EOF && i < size) {
        line[i++]  = c;
    }

    if(i >= size) {
        fprintf(stderr, "Too many characters\n");
        exit(EXIT_FAILURE);
    }
    
    if(c == '\n' || c == EOF) {
        line[i++] = '\n';
    }

    line[i++] = '\0';
    return i;
}

/* 
 * TODO
 * An alternate organization uses getline to read an entire input line; 
 * this makes getch and ungetch unnecessary. Revise the calculator to 
 * use this approach.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "stack.h"

#define NUMBER          0
#define MAX_BUF_SIZE    1024

static int my_getline(char line[], int size);
static int getop(char s[], char line[]); 

int main(void)
{ 

    char line[MAX_BUF_SIZE];
    char s[MAX_BUF_SIZE]
    int line_len;
    int type;
    int op_2;

    while((line_len = my_getline(line, MAX_BUF_SIZE)) != 0) {

        while(type = getop(s, line)) {

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
                    push(pop() + pop());
                    break;

                case '/':
                    op_2 = pop();
                    push(pop() / op_2);
                    break;

                case '%':
                    op_2 = pop();
                    push(pop() % op_2);
                    break;

                default:
                    fprintf(stderr, "unknown operator %c\n", type);
                    exit(EXIT_FAILURE);                

            }

        }

    }

    return 0;

}

static int getop(char s[], char line[])
{
    int i, j;
    
    i = 0;

    while((s[0] = line[i]) == ' ' || s[0] == '\t') {
        i ++;
    }
    
    s[1] = '\0';

    j = 0;
    
    if(!isdigit(line[i]) && line[i] != '.') {
        return line[i];
    } 
    
    if(isdigit(line[i])) {
        while(isdigit(line[i])) {
            s[j++] = line[i++]; 
        }
    }
    
    if(line[i] == '.') {
        s[j++] = line[i++];
        while(isdigit(line[i])) {
            s[j++] = line[i++];
        }
    }

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

    line[i] = '\0';
    return i+1;
}

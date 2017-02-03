/*
 * Write a program to check a C program for rudimentary syntax errors 
 * like unbalanced parentheses, brackets and braces. Don't forget about 
 * quotes, both single and double, escape sequences, and comments. 
 * (This program is hard if you do it in full generality.)
 *
 * This program does not consider the order of each symbol in a single line 
 */

#include <stdio.h>

#define MAXLINE     1024

int get_line(char *line, int size);

int main(void) 
{
    char line[MAXLINE];
    int line_len;

    int parenthesis, brace, bracket, s_quote, d_quote;

    parenthesis = 0;
    brace = 0;
    bracket = 0;
    
    s_quote = 1;
    d_quote = 1; 

    int i;
    while((line_len = get_line(line, MAXLINE)) > 0) {
        for(i = 0; i < line_len; i++) {
            switch(line[i]) {
                case '(':
                    parenthesis += 1;
                    break;
                case ')':
                    parenthesis -= 1;
                    break;
                case '[':
                    brace += 1;
                    break;
                case ']':
                    brace -= 1;
                    break;
                case '{':
                    bracket += 1;
                    break;
                case '}':
                    bracket -= 1;
                    break;
                case '\'':
                    s_quote *= -1;
                    break;
                case '"':
                    d_quote *= -1;
                    break;
                default:
                    // do nothing
                    break;
            }
        }
    }


    if(s_quote != 1) {
        fprintf(stderr, "Mismatching single quote\n");
    }
    if(d_quote != 1) {
        fprintf(stderr, "Mismatching double quote\n");
    }

    if(parenthesis != 0) {
        fprintf(stderr, "Mismatching parenthesis\n");
    }
    if(brace != 0) {
        fprintf(stderr, "Mismatching brace\n");
    }
    if(bracket != 0) {
        fprintf(stderr, "Mismatching bracket\n");
    }

    return 0;
}

int get_line(char *line, int size)
{

    char c;
    int i;

    i = 0;

    while((c = getchar()) != EOF && c != '\n') { 
        line[i] = c;
        if((++i) >= size) {
            fprintf(stderr, "Line length exceed the limit\n");
        } 
    }

    if(c == '\n') {
        line[i++] = c;
    }

    line[i] = '\0';
    return i;
}

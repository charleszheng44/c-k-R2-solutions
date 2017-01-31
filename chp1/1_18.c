/*
 * Write a program to remove all trailing blanks and tabs from each 
 * line of input, and to delete entirely blank lines.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1024

int get_line(char *line, int size);

int main(void)
{
    int line_len;
    char line[MAXLINE];
    int i;
    int j;

    line_len = get_line(line, MAXLINE);

    // skip the line[line_len-1], which is '\0'
    for(i = line_len - 2; i >= 0; i--) {
        if(line[i] == ' ' || line[i] == '\t') {
            i--;
        } 
        break;
    } 

    for(j = 0; j <= i; j++) {
        putchar(line[j]);
    }

    return 0;
}

int get_line(char *line, int size)
{

    char c;
    int i;

    i = 0;

    while((c = getchar()) != EOF && c != '\n') {
        if(i >= size) {
            fprintf(stderr, "The line length exceed the limit\n");
            exit(EXIT_FAILURE);
        }
        line[i++] = c;
    }
    
    if(c == '\n') {
        line[i++] = '\n';
    }
    
    line[i] = '\0';

    return i;
}

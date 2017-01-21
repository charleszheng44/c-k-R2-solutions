/*
 * Write a program to print all input lines that are longer than 
 * 80 characters.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1024

int getline_zc(char *line, int limit);

int main(void) 
{
    int line_len;

    line_len = 0;
    char line[MAXLINE];
    while((line_len = getline_zc(line, MAXLINE)) > 0) {
        printf("%d\n", line_len);
        if(line_len > 80) {
            printf("%s\n", line);
        }
    }
    return 0; 

}

int getline_zc(char *line, int limit) 
{
    
    char c; 
    int i;
    
    i = 0;

    while((c = getchar()) != EOF && c != '\n' && i < limit - 1) {
        line[i] = c;
        i++; 
    }

    if(i >= limit - 1) {
        fprintf(stderr, "Line length exceed the limit\n");
        exit(1);
    }

    if(c == '\n') {
        line[i++] = '\n';
    }

    line[i] = '\0';
    i++;
    return i;
}


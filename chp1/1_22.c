/*
 * Write a program to "fold" long input lines into two or more shorter 
 * lines after the last non-blank character that occurs before the n-th 
 * column of input. Make sure your program does something intelligent with 
 * very long lines, and if there are no blanks or tabs before the specified 
 * column.
 */

#include <stdio.h>
#include <stdlib.h>
#define MAXLINE     1024
#define LEN_LIMIT   30

int cut(char *line, int len, int limit);
int get_line(char *line, int size);

int main(void) 
{
    char line[MAXLINE];
    int lin_len;
    int offset;
    int i;
   
    offset = 0; 

    while((line_len = get_line(line, MAXLINE)) != -1) {
        if(line_len <= LEN_LIMIT) {
            printf("%d", line);
        } else {
            while(line + LEN_LIMIT <= len) {
                offset = cut(line, line_len, LEN_LIMIT);
                for(i = 0; i <= offset; i++) {
                    putchar(line[i]);
                }
                putchar('\n');
                line += offset; 
            }  
            
            printf("%s\n", line);
        } 
    }
}

int cut(char *line, int len, int limit)
{
    char c;
    int i;
    int end_wrd_pos;
    int in_wrd;

    i = 0;
    end_wrd_pos = 0;
    in_wrd = 0;
    
    for(; i < len; i++) {
        if(i == limit) {
            if( end_wrd_pos == 0) {
                fprintf(stderr, "Word length exceed the limit\n");
            } else {
                return end_wrd_pos;
            }
        }

        if(line[i] == ' ' || line[i] == '\t') {
            if(in_wrd) {
                end_wrd_pos = i-1;
            }
        } else {
            if(!in_wrd) {
                in_wrd = 1;
            }
        }

    } 
    
}

int get_line(char *line, int size)
{
    char c;
    int i;

    i = 0;
   
    while((c = getchar()) != EOF && c != '\n' && i < size) {
        line[i++] = c;
    }
    
    if(i >= size) {
        fprintf(stderr, "Line length exceed the limit");
        exit(EXIT_FAILURE);
    }

    if(c == '\n') {
        line[i++] = c;
    } 

    line[i++] = '\0';
    
    if(c == EOF) {
        i = -1
    }

    return i;
}

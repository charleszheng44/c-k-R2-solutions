/*
 * Revise the main routine of the longest-line program so it 
 * will correctly print the length of arbitrarily long input 
 * lines, and as much as possible of the text.
 */

#include <stdio.h>

#define MAXLINE 20

int getline_zc(char *line, int limit);
void copy(char *from, char *to);

int main(void)
{
    char line[MAXLINE];
    char longest[MAXLINE];
    int line_len;
    int max;

    max = 0;
    line_len = 0;

    while((line_len = getline_zc(line, MAXLINE)) > 0) {
        printf("%d\n", line_len);
        if(line_len > max) {
            copy(line, longest);
            max = line_len;
        }
    }

    if(max > 0) {
        if(max > MAXLINE) {
            printf("Storage limit exceeded by %d\n", max - MAXLINE);
            printf("String length is %d\n", max); 
            printf("String is %s\n", longest);
        } else {
            printf("String length is %d\n", max); 
            printf("String is %s\n", longest);
        }
    }

    return 0;
}

int getline_zc(char *line, int limit)
{

    char c;
    int i;
    i = 0;

    for(i = 0; ((c = getchar()) != EOF) && c != '\n' && i < limit-1; i++) {
        line[i] = c;
    }
    
    if(i >= limit - 1) {
        while((c = getchar()) != '\n') {
            i++;
        }
    }

    if(c == '\n') {
        line[i++] = '\n';
    }
    line[i] = '\0';
    return i; 
}

void copy(char *from, char *to)
{

    int i;

    for(i = 0; from[i] != '\0'; i++) {
        to[i] = from[i];
    }

}



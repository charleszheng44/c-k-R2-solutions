/*
 * Write a function reverse(s) that reverses the character string s. 
 * Use it to write a program that reverses its input a line at a time.
 */

#include <stdio.h>

#define MAXLINE 1024

int getline_zc(char *line, int limit);
void reverse_str(char *orig_str, char *rev_str, int str_len);

int main(void) 
{
    int str_len;
    char line[MAXLINE];
    char rev_str[MAXLINE];

    while((str_len = getline_zc(line, MAXLINE)) > 0) {
        reverse_str(line, rev_str, str_len);     
        printf("The input string is: %s\n", line);
        printf("The reversed string is: %s\n", rev_str);
    }

    return 0;
}

int getline_zc(char *line, int limit) 
{
    char c;
    int i;
    
    for(i = 0; i < limit && ((c = getchar()) != EOF) && c != '\n'; i++) {
        line[i] = c;
    }
    
    if(i >= limit) {
        printf("Input string length exceeded the limit\n");
    } 
    
    return i;
}

void reverse_str(char *orig_str, char *rev_str, int str_len)
{
    int i, j;
    for(i = str_len - 1, j = 0; i >= 0 ;i--, j++) {
        rev_str[j] = orig_str[i];
    }
}

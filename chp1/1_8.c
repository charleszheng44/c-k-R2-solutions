/*
 * Write a program to count blanks, tabs and new lines
 */


#include <stdio.h>

#define MAX 1024

int main(void)
{
   
    char inp_str[MAX];
    fgets(inp_str, MAX, stdin);
 
    printf("The input is: %s\n", inp_str);

    char c; 
    int count;
    int i;

    for(i = 0, c = inp_str[0], count = 0; c != '\0' && c != '\n' && i <= MAX; i++) {
        c = inp_str[i];
        if(c == ' ' || c == '\t' || c == '\n') {
            printf("%d\n", count);
            count ++;
        }
    }

    printf("The number of blank, tab and new line is: %d\n", count);
    return 0;

}

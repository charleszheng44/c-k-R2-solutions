/*
 * Write a program entab that replaces strings of blanks with the 
 * minimum number of tabs and blanks to achieve the same spacing. Use 
 * the same stops as for detab . When either a tab or a single blank 
 * would suffice to reach a tab stop, which should be given preference?
 */

#include <stdio.h>
#include <stdlib.h>

#define TAB     5
#define MAXLINE 1024

int getline_zc(char *line, int size);

int main(void)
{
    char line[MAXLINE];
    int inp_len;
    char c;
    int i;
    int ns;

    inp_len = getline_zc(line, MAXLINE);
    i = 0;
    ns = 0;

    c = line[i];

    while(c != '\0') {

        if( c == ' ') {
            ns++;
            if(ns == TAB) {
                putchar('\t');
                ns = 0;
            }
        } else {
            while(ns > 0) {
                putchar(' ');
                ns--;
            }
            putchar(c);
        }

        c = line[++i];
    }
}

int getline_zc(char *line, int size) 
{
    char c;
    int i;
    
    i = 0;
    
    while((c = getchar()) != EOF) {
        if(i >= size) {
            fprintf(stderr, "Input line length exceed the limit\n");
            exit(EXIT_FAILURE);
        }
        
        if(c != '\n') {
            line[i++] = c;
        } else {
            line[i++] = c;
            line[i] = '\0';
            break;
        }

    }    
    return i;
}

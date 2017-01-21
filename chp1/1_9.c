/*
 * Write a program to copy its input to its output, replacing each
 * each string of one or more blanks by a single blank
 */

#include <stdio.h>

int main(void)
{
    char c;
    int in_space = 0;

    while((c = getchar()) != EOF) {

        if(c == ' ' || c == '\t' || c == '\n') {

            if(!in_space) {
                in_space = 1;
            }

        } else {

            if(in_space) {
                putchar(' ');
                in_space = 0;
            }
            putchar(c);

        }

    }

    putchar('\n');

    return 0;
}

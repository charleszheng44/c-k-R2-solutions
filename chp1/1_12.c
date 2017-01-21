/*
 * Write a program that prints its input one word per line
 */

#include <stdio.h>

int main(void) 
{
    
    char c;
    int in_space = 0;

    while((c = getchar() ) != EOF) {
        if(c == ' ' || c == '\t' ) {
            if(!in_space) {
                in_space = 1;         
                putchar('\n');
            }        
        } else {
            if(in_space) {
                in_space = 0;
            }
            putchar(c);
        }
    }

    return 0;
}

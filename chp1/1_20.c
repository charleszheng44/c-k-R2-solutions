/*
 * Write a program detab that replaces tabs in the input with 
 * the proper number of blanks to space to the next tab stop. 
 * Assume a fixed set of tab stops, say every n columns. 
 * Should n be a variable or a symbolic parameter?
 *
 * Notice that: A tab character should advance to the next tab 
 * stop. Historically tab stops were every 8th character, although 
 * smaller values are in common use today and most editors can be 
 * configured.
 */

#include <stdio.h>

#define TAB 5

int num_of_spaces(int i);

int main(void)
{

    char c;
    int i;
    int num_space;

    i = 0;
    num_space = 0;
    
    while((c = getchar()) != EOF) {
        if(c == '\t') {
            num_space = num_of_spaces(i);
            while(num_space -- > 0) {
                putchar(' ');
                i++;
            }
        } else if (c == '\n') {
            putchar(c);  
            i = 0;
        } else {
            putchar(c);
            i++;
        }
    }

}

int num_of_spaces(int i)
{
    return (TAB - i % TAB);
}

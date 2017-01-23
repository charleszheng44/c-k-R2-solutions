/*
 * Write a program to print a histogram of the frequencies 
 * of different characters in its input.
 */

#include <stdio.h>
#include <ctype.h>

#define chr_to_index(c) (c-'a')

int main(void)
{

    char c;
    int i;
    int freq_arr[26] = {0};

    while((c = getchar()) != EOF) {
        if(isalpha(c)) {
            i = chr_to_index(c);
            freq_arr[i] ++;
        }
    }

    for(i = 0; i < 26; i++) {
        printf("%d ", freq_arr[i]);
    }
    puts("\n");

    return 0;
}

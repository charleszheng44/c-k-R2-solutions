/*
 * Write a program to print a histogram of the frequencies 
 * of different characters in its input.
 * TODO: implement the draw_histogram(int *wrd_len_arr, int size)
 */

#include <stdio.h>
#include <ctype.h>

#define chr_to_index(c) (c-'a')

void draw_histogram(int *wrd_len_arr, int size);

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

void draw_histogram(int *wrd_len_arr, int size)
{
	puts("Not implement yet\n");
}


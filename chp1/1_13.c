/*
 * Write a program to print a histogram of the lengths of words in its input. 
 * It is easy to draw the histogram with the bars horizontal; a vertical 
 * orientation is more challenging.
 * TODO implement the draw_histogram(int *wrd_len_arr, int size)
 */

#include <stdio.h>
#include <stdlib.h>

void draw_histogram(int *wrd_len_arr, int size);

int main(void) 
{
    int wrd_len_arr[20] = {0};
    char c;
    int i;
    int in_wrd;
    int wrd_len;

    in_wrd = 0;
    wrd_len = 0;

    for(i = 0; (c = getchar()) != EOF; i++) {

        if(c == ' ' || c == '\t' || c == '\n') {
            if(in_wrd) {
                in_wrd = 0;
                if(wrd_len > 20) {
                    fprintf(stderr, "Word length exceeds the limit\n" );
                    exit(1);
                }
                wrd_len_arr[wrd_len-1] ++;
                wrd_len = 0;
            } 
        } else {
            if(in_wrd) {
                wrd_len ++;
            } else {
                in_wrd = 1;
                wrd_len = 1;
            }
        }

    }
   
    draw_histogram(wrd_len_arr);

    return 0;
}

void draw_histogram(int *wrd_len_arr, int size)
{
	puts("Not implement yet\n");
}


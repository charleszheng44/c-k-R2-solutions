/*
 * Write a function expand(s1,s2) that expands shorthand notations like a-z in the string s1 
 * into the equivalent complete list abc...xyz in s2 . Allow for letters of either case and 
 * digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z . Arrange that a 
 * leading or trailing - is taken literally.
 * TODO test
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUFF_SIZE 256

typedef enum char_type {
   NUMBER,
   ALPHA
} char_type;

void expand(char *s1, char **s2);
char_type get_char_type(char head, char tail);

int main(void)
{
    return 0;
}

void expand(char *s1, char **s2) 
{
    int i, j, notation = 0;
    char head, tail, last_char;

    for(i = 0, j=0; i < strlen(s1); i++) {

        if(isalpha(s1[i]) && !notation) {

            last_char = s1[i];
            (*s2)[j++] = s1[i];

        } else if(isalpha(s1[i]) && notation) {

            tail = s1[i];
            get_char_type(head, tail);
            int k, tmp = 0;

            if(head == tail) {

                (*s2)[j++] = head;

            } else if (head > tail) {

                for(k = 0; k <= (head-tail); k++) {
                    (*s2)[j++] = head - k;
                }

            } else {

                for(k = 0; k <= (tail-head); k++) {
                    (*s2)[j++] = head + k;
                } 

            }

            last_char = tail;

        } else if(s1[i] == '-' && last_char != 0) {

            head = last_char;

        }
             
    }
}

char_type get_char_type(char head, char tail) 
{
    if(isalpha(head)) { 

        if(!isalpha(tail)) {
            goto WRONG_FMT_ERR;
        } else {
            if(islower(head) && islower(tail) || isupper(head) && isupper(tail)) { 
                return ALPHA;        
            } else {
                goto WRONG_FMT_ERR;
            } 
        }
        
    } else if(isdigit(head)){
       if(isdigit(tail)) {
           return NUMBER;
       } else {
           goto WRONG_FMT_ERR;
       }
    } else {
        goto WRONG_FMT_ERR;
    }

WRONG_FMT_ERR:

   fprintf(stderr, "%c and %c are not same kind of char\n", head, tail);
   exit(1); 
}

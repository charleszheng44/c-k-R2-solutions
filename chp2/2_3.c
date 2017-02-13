/*
 * Write the function htoi(s), which converts a string of hexadecimal digits 
 * (including an optional 0x or 0X) into its equivalent integer value. The allowable 
 * digits are 0 through 9, a through f, and A through F.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_DIGIT   20

int htoi(const char *s, int size);
int get_hex(char *hex_num, int size);
int hex_digit_to_dec_digit(char hex_char);

int main(void)
{
    char hex_num[MAX_DIGIT];
    int dec_num;
    int num_digits;
    num_digits = get_hex(hex_num, MAX_DIGIT);

    dec_num = htoi((const char *)hex_num, num_digits);
    printf("The hexadecimal number %s is converted to %d\n", hex_num, dec_num);
    return 0;
}

int get_hex(char *hex_num, int size) 
{
    char c;
    int i = 0;

    // trim the heading blank
    while((c = getchar()) == '\t' || c == ' ' || c == '\n')
        ;

    // process the first two difit 
    if(c == '0') {
        if((c = getchar()) == 'x' || c == 'X') {
            hex_num[i] = '0'; // hex_num[0] = '0'
            hex_num[i++] = c; // hex_num[1] = 'x' or 'X' 
            while((c = getchar()) != '\t' && c != ' ' && c != '\n') {

                if(i >= size) {
                    fprintf(stderr, "The number of hexadecimal digits is out of bound\n");
                    exit(EXIT_FAILURE);
                }

                if((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') \
                        || (c >= 'A' && c <= 'F')) {
                    hex_num[i++] = c;
                } else {
                    fprintf(stderr, "The allowable digits are 0 through 9, a through f, \
                            and A through F.\n"); 
                }
            }
        } else {
            fprintf(stderr, "Wrong format!\n"); 
            exit(EXIT_FAILURE);
        }
    } else {
        if((c > '0' && c <= '9') || (c >= 'a' && c <= 'f') \
                || (c >= 'A' && c <= 'F')) {
            hex_num[i++] = c;
            while((c = getchar()) != '\t' && c != ' ' && c != '\n') {

                if(i >= size) {
                    fprintf(stderr, "The number of hexadecimal digits is out of bound\n");
                    exit(EXIT_FAILURE);
                }

                if((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') \
                        || (c >= 'A' && c <= 'F')) {
                    hex_num[i++] = c;
                } else {
                    fprintf(stderr, "The allowable digits are 0 through 9, a through f, \
                            and A through F.\n"); 
                }
            }
        }
    }

    hex_num[i] = '\0';

    return i; 

}

int htoi(const char *s, int size)
{
    int i;
    int j;
    int dec_num;

    if(size == 0) {
        fprintf(stderr, "The hexadecimal number has 0 digit\n");
        exit(EXIT_FAILURE);
    }

    if(s[0] == '0' && size > 1 && (s[1] != 'x' || s[1] != 'X')) {
        fprintf(stderr, "Incorrect input format\n");
        exit(EXIT_FAILURE);

    }

    dec_num = 0;

    if(s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        size = size - 2; 
    } 

    for(i = size-1, j = 0; i > 0; i--, j++) {
        curr_num = hex_digit_to_dec_digit(s[i]) * pow(16, j);
        dec_num += curr_num;
    } 
    
    return dec_num;
}

int hex_digit_to_dec_digit(char hex_char) {
    int dec_num;
    if(hex_char > '0' && hex_char < '9') {
        dec_num = hex_char - '0'
    } else if(hex_char > 'a' && hex_char < 'f') {
        dec_num = hex_char - 'a' + 16;
    } else if(hex_char > 'A' && hex_char < 'F') {
        dec_num = hex_char - 'A' + 16;
    }

    return dec_num; 
}

/*
 * Write the function htoi(s), which converts a string of hexadecimal digits 
 * (including an optional 0x or 0X) into its equivalent integer value. The allowable 
 * digits are 0 through 9, a through f, and A through F.
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_DIGIT   20

int htoi(const char *s);
void get_hex(char *hex_num, int size);

int main(void)
{
    char hex_num[MAX_DIGIT];
    int dec_num;
    get_hex(hex_num, MAX_DIGIT);
    dec_num = htoi((const char *)hex_num);
    printf("The hexadecimal number %s is converted to %d\n", hex_num, dec_num);
    return 0;
}

void get_hex(char *hex_num, int size) 
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

                if(i > size) {
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

                if(i > size) {
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

    return hex_num; 

}

int htoi(const char *s)
{
    //TODO
}

/*
 * Write the function itob(n,s,b) that converts the integer n into a base b character 
 * representation in the string s. In particular, itob(n,s,16) formats n as a hexadecimal 
 * integer in s .
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define STR_LEN 64

void itob(int n, char s[], int base);
static void itob_generic(int n, char s[], int base);
static void itob_hex(int n, char s[]);
static void reverse(char s[], int n);

int main(void)
{
    srand(time(NULL));
    int n, i;
    for(i = 0; i < 10; i++) {
        n = rand() % (6587 + 1 - 123) + 123;
        char bin_s[STR_LEN];
        char oct_s[STR_LEN];
        char hex_s[STR_LEN];

        itob(n, bin_s, 2);
        itob(n, oct_s, 8);
        itob(n, hex_s, 16);
        
        printf("====================\nDecimal: %d\nBinary: %s\nOctal: %s\nHexadecimal: %s\n====================\n", n, bin_s, oct_s, hex_s);
    } 
    return 0;
}


void itob(int n, char s[], int base)
{
    if(base <= 0) {
        fprintf(stderr, "Base number must be larger than 0.\n");
        exit(1);
    }

    if(base != 10 && base != 8 && base != 2 && base != 16) {
        fprintf(stderr, "The base can only be 2, 8, 10 or 16.\n");
        exit(1);
    }    

    if(base == 16){
        itob_hex(n, s);
    } else {
        itob_generic(n, s, base);
    }

}

static void itob_generic(int n, char s[], int base) 
{
    int j = 0;
    int sign = n;

    do{
        s[j++] = abs(n % base) + '0';
    } while(n /= base);

    if(sign < 0) {
        s[j++] = '-';
    }

    reverse(s, j); 
    s[j] = '\0';
}

static void itob_hex(int n, char s[])
{
    int rmd, j = 0;
    int sign = n;
    char rmd_char;
    do{
        rmd = abs(n % 16);
        switch(rmd) {
            case 10:
                rmd_char = 'A';
                break;
            case 11:
                rmd_char = 'B';
                break;
            case 12:
                rmd_char = 'C';
                break;
            case 13:
                rmd_char = 'D';
                break;
            case 14:
                rmd_char = 'E';
                break;
            case 15:
                rmd_char = 'F';
                break;
            default:
                rmd_char = rmd + '0';
                break;
        }
        s[j++] = rmd_char;
    } while(n /= 16);

    if(sign < 0) {
        s[j++] = '-';
    }

    reverse(s, j); 
    s[j] = '\0';
}

static void reverse(char s[], int n)
{
    int i, j;
    char tmp;
    for(i = 0, j = n - 1; i < j; i++, j--) {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

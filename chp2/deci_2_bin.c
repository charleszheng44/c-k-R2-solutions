/*
 * print decimal number in binary format
 * 
 * This program can only print out the decimal number in range [0, 511]
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>

void show_help();
unsigned long decimal_to_binary(int i);

int main(int argc, char *argv[]) 
{
    extern char *optarg;
    extern int optind, opterr, optopt;
    
    int opt; 
    int decimal_num = 0;
    unsigned long binary_num = 0;
    
    while((opt = getopt(argc, argv, "n:h")) != -1) {
        switch(opt) {
            case 'n':
                decimal_num = atoi(optarg); 
                binary_num = decimal_to_binary(decimal_num);
                break;
            case 'h':
                show_help();
                return 0;
            default:
                fprintf(stderr, "Unknown option %c\n", opt);
                show_help();
                exit(EXIT_FAILURE);
        }
    }    

    printf("The binary format of %d is %lu\n", decimal_num, binary_num); 
    return 0;
}

void show_help()
{
    printf("This is a help message\n");
}

unsigned long decimal_to_binary(int i)
{

    if( i > 511 || i < 0) {
        fprintf(stderr, "The input decimal number out of range. The input range is [0, 511].\n");
        exit(EXIT_FAILURE);
    } else if(i == 0) {
        return 0;
    } else {
        return (i % 2 + 10 * (decimal_to_binary(i / 2)));
    }
}

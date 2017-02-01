/*
 * Write a program to remove all comments from a C program. Don't 
 * forget to handle quoted strings and character constants properly. 
 * C comments do not nest.
 */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int opt;
    char *inp_fn;
    extern char *optarg;
    extern int optind, optopt;

    while((opt = getopt(argc, argv, "f:h")) != -1) {
        if(opt == 'f') {
            inp_fn = optarg;
        } else if( opt == 'h') {
            printf("\nuse option -f to specify a c source file\n\n");
        }
    }
    
    if(optind < argc) {
        printf("non-option ARGV-elements:");
        while(optind < argc) {
            printf("%s ", argv[optind++]);
        }
        puts("\n");
    }
    return 0;
}

void remove_comment(const char* c_fn) 
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(c_fn, "r");
    while((read = getline(&line, &len, fp)) != -1) {
        int i;
        for(i = 0; i < read; i++) {
            //remove the heading blanks
            if(line[i] != ' ' && line[i] != '\t') {
                break;
            }
        } 

        if(i >= read || line[i] == '/') {
            continue;
        } else {
            printf("%s", line);
        }

    }

    if(line) {
        free(line);
    }
    fclose(fp);
}

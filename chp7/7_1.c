#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
  
    int c; 
    
    char *opt = argv[1]; 
    if(strcmp(opt, "toLow") == 0) {
        while((c = getchar()) != EOF) {
            putchar(tolower(c));
        }
    } else if(strcmp(opt, "toUp") == 0) {
        while((c = getchar()) != EOF) {
            putchar(toupper(c));
        }
    } else {
        fprintf(stderr, "unknown option %s, the available options are:\
                 toLow, toUp\n", opt);
        return 1;
    }

    return 0;
}

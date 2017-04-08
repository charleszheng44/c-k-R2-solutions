/*
 * Suppose there will never be more than one character of pushback. Modify getch and ungetch accordingly.
 */

#include <stdio.h>
#include <stdlib.h>

int buf = EOF;

int getch(void);
void ungetch(char c);

int main(void) 
{
    char c;
    ungetch('c');
    printf("Keyboard input is:\n");
    while((c = getch()) != EOF) {
        printf("%c\n", c);
    }
    return 0;
}

int getch(void)
{
    char c;

    if(buf == EOF) {
        c = getchar();
    } else {
        c = buf;
        buf = EOF; 
    }

    return c;
}

void ungetch(char c) 
{
    if(buf != EOF) {
        fprintf(stderr, "ungetch: buffer is not empty\n");
        exit(1);
    } else {
        buf = c;
    }
}

/*
 * Experiment to find out what happens when printf 's argument 
 * string contains \c, where c is some character not listed above. 
 * The escape sequences listed above are
 * \n (newline)
 * \t (tab)
 * \b (backspace)
 * \" (double quote)
 * \\ (blackslash)
 */

#include <stdio.h>

int main(void) 
{
    printf("Audible or visual alert. \a\n");
    printf("Form feed. \f\n");
    printf("Move to initial positin of the current line. \r\n");
    printf("Vertical tab \v\n");

    return 0;
}

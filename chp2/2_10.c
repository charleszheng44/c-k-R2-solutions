/*
 * Rewrite the function lower, which converts upper case letters to 
 * lower case, with a conditional expression instead of if-else .
 */

#include<stdio.h>
#include<string.h>

char lower(char c);

int main(void)
{
    int i;
    char upper_char_arr[] = "ABCDE";
    char lower_char;
    int arr_len = strlen(upper_char_arr);
    for(i = 0; i < arr_len; i++) {
        lower_char = lower(upper_char_arr[i]);
        printf("%c -> %c\n", upper_char_arr[i], lower_char);
    }
    return 0;
}

char lower(char c)
{
    return (c >= 'A' && c <= 'Z' ? c - 'A' + 'a' : c);

}

/*
 * Write a function escape(s,t) that converts characters like newline and tab into visible escape 
 * sequences like \n and \t as it copies the string t to s . Use a switch . Write a function for 
 * the other direction as well, converting escape sequences into the real characters.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void escape(char **s, char *t);
void unescape(char **s, char *t);

int main(void)
{
    char *t = "this is a test \n \n \n \" \" \"";
    char *s;
    escape(&s, t); 
    printf("The original string is: %s\n==========================================\n", t);
    printf("The escaped string is: %s\n==========================================\n", s);
    char *t_1;
    unescape(&t_1, s);
    printf("The unescaped string is: %s\n", t_1);
    return 0;
}

void escape(char **s, char *t) 
{
    int i, j;
    *s = (char *)malloc(strlen(t) * sizeof(char));

    for(i = 0, j = 0; t[i] != '\0'; i++, j++) {
        switch(t[i]) {
            case '\n':
                (*s)[j++] = '\\';
                (*s)[j] = 'n';
                break;
            case '\t':
                (*s)[j++] = '\\';
                (*s)[j] = 't';
                break;
            case '\a':
                (*s)[j++] = '\\';
                (*s)[j] = 'a';
                break;
            case '\b':
                (*s)[j++] = '\\';
                (*s)[j] = 'b';
                break;
            case '\f':
                (*s)[j++] = '\\';
                (*s)[j] = 'f';
                break;
            case '\r':
                (*s)[j++] = '\\';
                (*s)[j] = 'r';
                break;
            case '\v':
                (*s)[j++] = '\\';
                (*s)[j] = 'v';
                break;
            case '\\':
                (*s)[j++] = '\\';
                (*s)[j] = '\\';
                break;
            case '\'':
                (*s)[j++] = '\\';
                (*s)[j] = '\'';
                break;
            case '\"':
                (*s)[j++] = '\\';
                (*s)[j] = '\"';
                break;
            default:
                (*s)[j] = t[i];
                break;
        }
    }
    (*s)[j] = '\0';
}

void unescape(char **s, char *t) 
{
    int i, j;
    *s = (char *)malloc(strlen(t) * sizeof(char));

    for(i = 0, j = 0; t[i] != '\0'; i++, j++) {
        if(t[i] == '\\') {
            i++;
            switch(t[i]) {
                case 'n':
                    (*s)[j] = '\n';
                    break;
                case 't':
                    (*s)[j] = '\t';
                    break;
                case 'a':
                    (*s)[j] = '\a';
                    break;
                case 'b':
                    (*s)[j] = '\b';
                    break;
                case 'f':
                    (*s)[j] = '\f';
                    break;
                case 'r':
                    (*s)[j] = '\r';
                    break;
                case 'v':
                    (*s)[j] = '\v';
                    break;
                case '\\':
                    (*s)[j] = '\\';
                    break;
                case '\'':
                    (*s)[j] = '\'';
                    break;
                case '\"':
                    (*s)[j] = '\"';
                    break;
                default:
                    (*s)[j++] = '\\';
                    (*s)[j] = t[i];
                    break;
            }
        } else {
            (*s)[j] = t[i];
        }
    }
    (*s)[j] = '\0';
}

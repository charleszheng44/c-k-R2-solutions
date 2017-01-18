#include <stdio.h>

int main(void)
{
    printf("%-6s:\t%ld\n", "Char", sizeof(char));
    printf("%-6s:\t%ld\n", "Int", sizeof(int));
    printf("%-6s:\t%ld\n", "Short", sizeof(short));
    printf("%-6s:\t%ld\n", "Long", sizeof(long));
    printf("%-6s:\t%ld\n", "Float", sizeof(float));
    printf("%-6s:\t%ld\n", "Double", sizeof(double));
    return 0;
}

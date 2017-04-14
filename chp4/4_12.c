/* 
 * Adapt the ideas of printd to write a recursive version of itoa ; that 
 * is, convert an integer into a string by calling a recursive routine.
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUF_SIZE    1024

static void reverse(char a[], int size);
static void itoa(int i, char a[]);
static void itoa_2(int i, char a[]);
static int itoa_recur(int i, int j, char a[], int *n);
static int num_digit = 0;

int main(void)
{
    srandom(time(NULL));
    int i = rand();
    char a[MAX_BUF_SIZE];
    char b[MAX_BUF_SIZE];
    itoa(i, a); 
    itoa_2(i, b);
    printf("%d -> %s\n", i, a);
    printf("%d -> %s\n", i, b);
    return 0;
}

void reverse(char a[], int size)
{
    int i;
    int j;
    char tmp;

    for(i = 0, j = size - 1; i < j; i++, j--) {
        tmp = a[i];
        a[i] = a[j]; 
        a[j] = tmp;
    }
}

void itoa(int i, char a[])
{
    int j = 0;
    
    if(i < 0) {
        a[j++] = '-';
    }

    do {
        a[j++] =(i % 10) + '0'; 
    } while((i /= 10) != 0);

    a[j] = '\0';
    
    reverse(a, j);
}

void itoa_2(int i, char a[]) 
{
    int num_digit = 0;
    int *n = &num_digit; 
    itoa_recur(i, 0, a, n);
    a[++(*n)] = '\0';
    reverse(a, num_digit);
}

int itoa_recur(int i, int j, char a[], int *n)
{
    *n = (j > *n ? j : *n);

    if(i < 0) {
        a[j++] = '-';
        i = -i;        
    } 

    if(i / 10 != 0) {
        itoa_recur(i / 10, j + 1, a, n);
    }

    a[j] = i % 10 + '0';
}



/*
 * Our binary search makes two tests inside the loop, when one would suffice (at the price of 
 * more tests outside). Write a version with only one test inside the loop and measure the difference 
 * in run-time.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bin_search(int x, int arr[], int n);
void gen_rand_int_arr(int *arr, int low, int high, int n);
void print_arr(int arr[], int n);

int main(void)
{
    int arr[10]; 
    int pos;
    gen_rand_int_arr(arr, 3, 25, 10);
    print_arr(arr, 10);
    pos = bin_search(10, arr, 10);
    printf("%d\n", pos);
    return 0;
}

void print_arr(int arr[], int n)
{
    printf("{");
    int i;
    for(i = 0; i < n-1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d}\n", arr[n-1]);
}

void gen_rand_int_arr(int *arr, int low, int high, int n)
{
    int cmp_func(const void *a, const void *b) {
        return (*(int *)a - *(int *)b);
    }

    srand(time(NULL));
    int i, curr_num;
    for(i = 0; i < n; i++) {
        curr_num = rand() % (high + 1 - low) + low;
        arr[i] = curr_num;
    }
    qsort(arr, n, sizeof(int), &cmp_func);
}

int bin_search(int x, int arr[], int n) 
{
    int low, mid, high;
    low = 0;
    high = n-1;
    mid = (low + high) / 2;

    while(low <= high && x != arr[mid]) {
        if(x > arr[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
        mid = (low + high) / 2;
    }

    if(x == arr[mid]) {
        return mid;
    } else {
        return -1;
    }
}

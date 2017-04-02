#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE  100

static double op_stack[STACK_SIZE];
static int cur = 0;

void push(double op)
{
    if(cur < STACK_SIZE) {
        op_stack[cur++] = op;
    } else {
        fprintf(stderr, "operator stack is full\n");
        exit(1);
    }
}

double pop(void)
{
    if(cur >= 0) {
        return op_stack[--cur];
    } else {
        fprintf(stderr, "operator stack is empty\n");
        exit(1);
    }
}

double peek(void)
{
    if(cur >= 0) {
        return op_stack[cur];
    } else {
        fprintf(stderr, "operator stack is empty\n");
        exit(1);
    }
}

void dup_top(void)
{
    double tmp = pop();
    
    push(tmp);
    push(tmp);
}

void swap_top(void)
{
    double tmp_1 = pop();
    double tmp_2 = pop();

    push(tmp_2);
    push(tmp_1);
}

void clear_stack(void)
{
    cur = 0;
}

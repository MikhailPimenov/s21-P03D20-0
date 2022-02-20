#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "get_fun_to_one.h"

void push(char* stack, char elem, int* top) {
    if (*top == 49) {
        printf("Overflow");
    } else {
        *top = *top + 1;
        stack[*top] = elem;
    }
}

char pop(char* stack, int* top) {
    char item;
    if (*top == -1) {
        printf("Underflow");
    } else {
        item = stack[*top];
        *top = *top - 1;
    }
    return item;
}

/*
void display() {
    int i;
    for(i = top; i >= 0; i--) {
        printf("%d", stack[i]);
    }
} */

void push_double(double* stack, double elem, int* top) {
    if (*top == 49) {
        printf("Overflow");
    } else {
        *top = *top + 1;
        stack[*top] = elem;
    }
}

double pop_double(double* stack, int* top) {
    double item;
    if (*top == -1) {
        printf("Underflow");
    } else {
        item = stack[*top];
        *top = *top - 1;
    }
    return item;
}
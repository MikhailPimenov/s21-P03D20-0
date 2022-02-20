#ifndef GET_FUN
#define GET_FUN
#include <stdio.h>
#include <stdlib.h>

#define width 80
#define height 25

void init_mas(char** matrix);
void consol_show(char** matrix);

int reverse(char* out_mas, char* input_str);
void push(char* stack, char elem, int* top);
char pop(char* stack, int* top);
// void display();
int convert_mas_to_postfix(char* out_mas, char* input_mas, int length_mas);
int isDigit(char x);
int isAlpha(char x);
int showPriority(char symbol);

double calculate(char* out_mas, int len_mas, int* top, double x);

double char_to_int(char number);

void push_double(double* stack, double elem, int* top);
double pop_double(double* stack, int* top);
#endif // GET_FUN
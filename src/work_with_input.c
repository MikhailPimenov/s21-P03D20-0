#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "get_fun_to_one.h"
int top = -1;
char stack[50] = {'a'};
// Скидываем мусор. Т.е. для сброса левой кобки со стека.
char trash = 'a';

int reverse(char* out_mas, char* input_str) {
    int len, from_begin = 0, from_end = 0;
    len = strlen(input_str);
    from_end = len - 1;
    int size_mas = 1;
    while (from_end >= 0) {
        if (input_str[from_end] != ' ') {
            out_mas = (char*) realloc(out_mas, size_mas++ * sizeof(char));
            if (input_str[from_end] == '(') {
                out_mas[from_begin] = ')';
                from_end = from_end - 1;
                from_begin = from_begin + 1;
            } else if (input_str[from_end] == ' ') {
                from_end = from_end - 1;
            } else if (input_str[from_end] == ')') {
                out_mas[from_begin] = '(';
                from_end = from_end - 1;
                from_begin = from_begin + 1;
            } else if (input_str[from_end] == 'n') {
                out_mas[from_begin] = 's';
                from_end = from_end - 3;
                from_begin = from_begin + 1;
            } else if (input_str[from_end] == 's') {
                out_mas[from_begin] = 'c';
                from_end = from_end - 3;
                from_begin = from_begin + 1;
            } else if (input_str[from_end] == 'g' && input_str[(from_end-1)] == 't' && +
            input_str[(from_end-2)] == 'c') {
                out_mas[from_begin] = 'g';
                from_end = from_end - 3;
                from_begin = from_begin + 1;
            } else if (input_str[from_end] == 'g') {
                out_mas[from_begin] = 't';
                from_end = from_end - 2;
                from_begin = from_begin + 1;
            } else {
                out_mas[from_begin] = input_str[from_end];
                from_end = from_end - 1;
                from_begin = from_begin + 1;
            }
        } else {
            from_end = from_end - 1;
        }
    }
    return from_begin;
}

int convert_mas_to_postfix(char* out_mas, char* input_mas, int length_mas) {
    printf(" ");
    int i_input_mas = 0;
    int j_out_mas = 0;
    out_mas = (char*) realloc(out_mas, (length_mas + 5) * sizeof(char));
    while (i_input_mas < length_mas) {
        if (input_mas[i_input_mas] == '(') {
            push(stack, input_mas[i_input_mas], &top);
            i_input_mas++;
        } else if (input_mas[i_input_mas] == ')') {
            while ((top != -1) && (stack[top] != '(')) {
                out_mas[j_out_mas] = pop(stack, &top);
                j_out_mas++;
            }
            if (top == -1) {
                printf("Бля! Нечего брать со стэка.");
            }
            trash = pop(stack, &top);
            i_input_mas++;
        } else if (input_mas[i_input_mas] == '+' || input_mas[i_input_mas] == '-' || +
         input_mas[i_input_mas] == '*' || input_mas[i_input_mas] == '/' || +
         input_mas[i_input_mas] == '%' || input_mas[i_input_mas] == '^' || +
         input_mas[i_input_mas] == 's' || input_mas[i_input_mas] == 'c' || +
         input_mas[i_input_mas] == 't' || input_mas[i_input_mas] == 'g') {
            while ((top != -1) && (stack[top] != '(') && +
            (showPriority(stack[top]) > showPriority(input_mas[i_input_mas]))) {
                out_mas[j_out_mas] = pop(stack, &top);
                j_out_mas++;
            }
            push(stack, input_mas[i_input_mas], &top);
            i_input_mas++;
        } else if (isDigit(input_mas[i_input_mas]) == 1 || isAlpha(input_mas[i_input_mas]) == 1) {
            out_mas[j_out_mas] = input_mas[i_input_mas];
            j_out_mas++; i_input_mas++;
        } else {
        }
    }
    while (top != -1) {
        out_mas[j_out_mas] = pop(stack, &top);
        j_out_mas++;
    }
    return j_out_mas;
}

int isDigit(char x) {
    char str_model[] = "1234567890";
    int amount_number = strspn(&x, str_model);
    if (amount_number == 1) {
        return 1;
    } else {
        return 0;
    }
}

int isAlpha(char x) {
    //  ch >= 97 && ch <= 122) || (ch >= 65 && ch <= 90
    if (((x >= 'a' && x <= 'z') || (x >='A' && x <= 'Z')) && +
    (x != 's' && x != 'c' && x != 't' && x != 'g')) {
        return 1;
    } else {
        return 0;
    }
}

int showPriority(char symbol) {
    if ((symbol == 's') || (symbol == 'c') || (symbol == 't') || (symbol == 'g')) {
        return 4;
    } else if (symbol == '^') {
        return 3;
    } else if ((symbol == '*') || (symbol == '/') || (symbol == '%')) {
        return 2;
    } else {
        return 1;
    }
}


double calculate(char* out_mas, int len_mas, int* top, double x) {
    *top = -1;
    double item = 0;
    double item_1 = 0;

    int item_int = 0;
    int item_int_1 = 0;
    double result = 0;

    double stack[50] = {0.00};

    for (int i = 0; i < len_mas; i++) {
        if (isDigit(out_mas[i]) == 1) {
            push_double(stack, char_to_int(out_mas[i]), top);
        } else {
            if ((out_mas[i]) == 's') {
                item = pop_double(stack, top);
                push_double(stack, sin(item), top);
            } else if ((out_mas[i]) == 'c') {
                item = pop_double(stack, top);
                push_double(stack, cos(item), top);

            } else if ((out_mas[i]) == 'x') {
                push_double(stack, x, top);

            } else if ((out_mas[i]) == 't') {
                item = pop_double(stack, top);
                push_double(stack, tan(item), top);
            } else if ((out_mas[i]) == 't') {
                item = pop_double(stack, top);
                push_double(stack, 1/(tan(item)), top);
            } else if ((out_mas[i]) == '*' && *top != -1) {
                item = pop_double(stack, top);
                item_1 = pop_double(stack, top);
                push_double(stack, item * item_1, top);
            } else if ((out_mas[i]) == '/' && *top != -1) {
                item = pop_double(stack, top);
                item_1 = pop_double(stack, top);
                push_double(stack, item_1 / item, top);
            } else if ((out_mas[i]) == '%' && *top != -1) {
                item_int = pop_double(stack, top);
                item_int_1 = pop_double(stack, top);
                result = item_int_1 % item_int;
                push_double(stack, result, top);
            } else if ((out_mas[i]) == '^' && *top != -1) {
                item = pop_double(stack, top);
                item_1 = pop_double(stack, top);
                push_double(stack, pow(item_1, item), top);

            } else if ((out_mas[i]) == '+' && *top != -1) {
                item = pop_double(stack, top);
                item_1 = pop_double(stack, top);
                push_double(stack, (item_1 + item), top);

            } else if ((out_mas[i]) == '-' && *top != -1) {
                item = pop_double(stack, top);
                item_1 = pop_double(stack, top);
                push_double(stack, (item_1 - item), top);
            } else {
                printf("Error in calculation!");
            }
        }
    }
    return stack[0];
}

double char_to_int(char number) {
    int num = number - '0';
    double num_1 = num;
    return num;
}







































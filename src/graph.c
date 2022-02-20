#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "get_fun_to_one.h"
#include "work_with_input.c"
#include "stack_process.c"
#include "work_with_massiv.c"

#define width 80
#define height 25

int main (void) {
    char **matrix = (char**) malloc(height * sizeof(char*));
    for (int i = 0; i < height; i++)
        matrix[i] = (char*) malloc(width * sizeof(char));
    init_mas(matrix);
    //consol_show(matrix);
    char* mas = (char*) malloc(1 * sizeof(char));
    char* out_mas = (char*) malloc(1 * sizeof(char));
    char* input_str = "x + 1";

    int length_mas = reverse(mas, input_str);

    int len = convert_mas_to_postfix(out_mas, mas, length_mas);
    for (int i = 0; i < len; i++) {
        printf("%c", out_mas[i]);
    }

    printf("\n");
    double Ox = 0.005;
    double Oy = 0;
    int j = 0;
    for (int i = 0; i <= 80; i++) {
        Oy = calculate(out_mas, len, &top, Ox);
        j = round(Oy/0.08)-1;
        Ox = Ox + 0.005;
        printf("%d %lf %lf\n", j, Oy, Ox);
        if (j >= 0 && j <= 25) {
            matrix[j][i] = '*';
        } else {
            continue;
        }
        }
    
    consol_show(matrix);
    return 0;
}


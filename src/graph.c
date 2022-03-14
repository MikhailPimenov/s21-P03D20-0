#include <stdio.h>
#include <stdlib.h>

#include "drawing/drawing.h"
#include "translating_calculating/calculate_reverse_polish_notation.h"
#include "translating_calculating/translating.h"
#include "translating_calculating/shunting_yard.h"

#include "data_structures/lexeme.h"
#include "data_structures/stack.h"

#include "drawing/drawing.h"

#include "parsing_expression/parse_to_lexemes.h"

#include "parsing_expression/string_to_int.h"
#include "parsing_expression/string_to_double.h"

#include "translating_calculating/calculation_error_codes.h"

#include "parsing_expression/check_expression_and_count_lexemes.h"

#include "field/allocate_deallocate_field.h"

// #define TEST_GRAPH_

#ifdef TEST_GRAPH_
#include "data_structures/lexeme_test.h"
#include "data_structures/stack_test.h"
#include "translating_calculating/shunting_yard_test.h"
#include "translating_calculating/calculate_reverse_polish_notation_test.h"
#include "parsing_expression/parse_to_lexemes_test.h"
#include "parsing_expression/string_to_int_test.h"
#include "parsing_expression/string_to_double_test.h"
#include "parsing_expression/check_expression_and_count_lexemes_test.h"
#endif //  TEST_GRAPH_





// #include <stdio.h>
// #include <stdlib.h>
#include <errno.h>
#include <stdint.h>

// if typedef doesn't exist (msvc, blah)
typedef intptr_t ssize_t;

ssize_t getline_allocate(char **line_pointer, size_t *allocated_length, FILE *stream) {

    if (line_pointer == NULL || stream == NULL || allocated_length == NULL) {
        errno = EINVAL;
        return -1;
    }

    int symbol = '\0';
    symbol = getc(stream);
    if (symbol == EOF) {
        return -1;
    }

    const size_t initial_buffer_size = 128u;
    if (*line_pointer == NULL) {
        *line_pointer = malloc(initial_buffer_size);
        if (*line_pointer == NULL) {
            return -1;
        }
        *allocated_length = initial_buffer_size;
    }

    size_t position = 0;
    while(symbol != EOF) {
        if (position + 1 >= *allocated_length) {
            size_t new_size = *allocated_length + (*allocated_length >> 2);
            if (new_size < initial_buffer_size) {
                new_size = initial_buffer_size;
            }

            char *new_line_pointer = realloc(*line_pointer, new_size);
            if (new_line_pointer == NULL) {
                if (*line_pointer) {
                    free(*line_pointer);
                    *line_pointer = NULL;
                }

                return -1;
            }
            *allocated_length = new_size;
            *line_pointer = new_line_pointer;
        }

        ((unsigned char *)(*line_pointer))[position ++] = symbol;
        if (symbol == '\n') {
            break;
        }
        symbol = getc(stream);
    }

    (*line_pointer)[position] = '\0';
    return position;
}




void input_expression_allocate(char **expression, int actual_length_without_terminator);
void free_expression(char **expression);

int check_expression_and_count_lexemes(const char *infix_notation_row, int length_without_terminator, int *amount_of_lexemes_out);
// void parse_to_lexemes_allocate(const char *infix_notation_row, int length, Lexeme **infix_notation_out, int *length_out);

// TODO: change int *length_out or remove it, because it is possible to find length of the postfix_notation outside shunting_yard function!
void shunting_yard(const Lexeme *infix_notation, int length, Lexeme *postfix_notation, int *length_out);


// Definition area - [0; 4 Pi]
void create_definition_area(double *definition_area_already_allocated, int amount_of_columns, double minimum_x, double maximum_x) {
    const double delta_x = (maximum_x - minimum_x) / (double)amount_of_columns;

    for (int column = 0; column < amount_of_columns; ++column)
        definition_area_already_allocated[column] = minimum_x + delta_x;

}



int calculate_values_for_definition_area(
    double *values,
    double *definition_area,
    int length,
    const Lexeme *const postfix_notation,
    int length_of_postfix_notation,
    int (*calculate_rpn_function)(const Lexeme *const, int, double*)
) {
    for (int column = 0; column < length; ++column) {
        const int status = calculate_reversed_polish_notation(
            postfix_notation,
            length_of_postfix_notation,
            values + column
        );

        if (status != C_SUCCESS) {
            return status;
        }
    }
    return C_SUCCESS;
}


void set_array_of_rows_from_y_values(int *array_of_rows_out, const double *const array_of_y, int length, int amount_of_possible_rows) {
    for (int index = 0; index < length; ++index) {
        const int filled_row = get_row_number_from_y(array_of_y[index], amount_of_possible_rows);
        array_of_rows_out[index] = filled_row;
    }
}

void set_empty_field(char **field, int rows, int columns, char empty_symbol) {
    for (int row = 0; row < rows; ++row)
        for (int column = 0; column < columns; ++column)
            field[row][column] = empty_symbol;
}
// int free_on_exit(char **line, int exit_code) {
//     if (*line) {
//         free(*line);
//         *line = NULL;
//     }
//     return exit_code;
// }
// int free_on_successful_exit(char **line) {
//     return free_on_exit(line, 0);
// }
// int free_on_failed_exit(char **line) {
//     return free_on_exit(line, -1);
// }
void set_graph_on_empty_field(char **field, int rows, int columns, int *array_of_rows, int length, char filled_symbol) {
    for (int column = 0; column < columns; ++column)
        if (0 <= array_of_rows[column] && array_of_rows[column] < rows) 
            field[array_of_rows[column]][column] = filled_symbol;
}

int program(int rows, int columns, char filled_symbol, char blank_symbol) {
    char *expression = NULL;
    size_t allocated_length = 0u;
    const ssize_t actual_length = getline_allocate(&expression, &allocated_length, stdin);

    if (actual_length == -1) {
        printf("Error: could not allocate memory for input expression!\n");
        return -1;
    }

    int amount_of_infix_lexemes = 0;
    const int length_without_terminator = actual_length - 1;
    const int status_check = check_expression_and_count_lexemes(expression, length_without_terminator, &amount_of_infix_lexemes);
    
    if (status_check != EC_EXPRESSION_IS_CORRECT) {
        printf("Error: expression is not correct!\n");
        // return free_on_failed_exit(&expression);

        if (expression) {
            free(expression);
            expression = NULL;
        }
        return -1;
    }

    Lexeme *infix_notation = malloc(amount_of_infix_lexemes * sizeof(Lexeme));
    if (infix_notation == NULL) {
        printf("Error: could not allocate memory for lexemes in infix notation!\n");
        if (expression) {
            free(expression);
            expression = NULL;
        }
        return -1;
    }

    create_lexemes(expression, length_without_terminator, infix_notation, amount_of_infix_lexemes);
    //  TODO: change shunting_yard(), it will be waiting already calculated length of postfix notation, not finding it by itself
    //  TODO: modify tests

    Lexeme *postfix_notation = malloc(amount_of_infix_lexemes * sizeof(Lexeme));  //  TODO: allocate the exact number of postfix notation lexemes, but not number of infix notation lexemes
    if (infix_notation == NULL) {
        printf("Error: could not allocate memory for lexemes in postfix notation!\n");
        if (expression) {
            free(expression);
            expression = NULL;
        }
        if (infix_notation) {
            free(infix_notation);
            infix_notation = NULL;
        }
        return -1;
    }

    int amount_of_postfix_lexemes = 0;
    shunting_yard(infix_notation, amount_of_infix_lexemes, postfix_notation, &amount_of_postfix_lexemes);

    double *array_x = malloc(columns * sizeof(double));
    if (array_x == NULL) {
        printf("Error: could not allocate memory for definition area!\n");

        if (postfix_notation) {
            free(postfix_notation);
            postfix_notation = NULL;
        }
        if (infix_notation) {
            free(infix_notation);
            infix_notation = NULL;
        }
        if (expression) {
            free(expression);
            expression = NULL;
        }
        return -1;
    }

    double *array_y = malloc(columns * sizeof(double));
    if (array_y == NULL) {
        printf("Error: could not allocate memory for values!\n");

        if (array_x) {
            free(array_x);
            array_x = NULL;
        }
        if (postfix_notation) {
            free(postfix_notation);
            postfix_notation = NULL;
        }
        if (infix_notation) {
            free(infix_notation);
            infix_notation = NULL;
        }
        if (expression) {
            free(expression);
            expression = NULL;
        }
        return -1;
    }

    const int status_caclulation = calculate_values_for_definition_area(
        array_y,
        array_x,
        columns,
        postfix_notation,
        amount_of_postfix_lexemes,
        calculate_reversed_polish_notation);

    if (status_caclulation != C_SUCCESS) {
        printf("Error: something went wrong during computation of reversed polish notation!\n");

        if (array_y) {
            free(array_y);
            array_y = NULL;
        }
        if (array_x) {
            free(array_x);
            array_x = NULL;
        }
        if (postfix_notation) {
            free(postfix_notation);
            postfix_notation = NULL;
        }
        if (infix_notation) {
            free(infix_notation);
            infix_notation = NULL;
        }
        if (expression) {
            free(expression);
            expression = NULL;
        }

        return -1;
    }

    int *array_of_rows = malloc(columns * sizeof(int));
    if (array_of_rows == NULL) {
        printf("Error: could not allocate memory for array of rows!\n");

        if (array_y) {
            free(array_y);
            array_y = NULL;
        }
        if (array_x) {
            free(array_x);
            array_x = NULL;
        }
        if (postfix_notation) {
            free(postfix_notation);
            postfix_notation = NULL;
        }
        if (infix_notation) {
            free(infix_notation);
            infix_notation = NULL;
        }
        if (expression) {
            free(expression);
            expression = NULL;
        }
        return -1;
    }
    
    set_array_of_rows_from_y_values(array_of_rows, array_y, columns, rows);

    char **field = NULL;
    const int status_allocation_field = allocate_field(&field, rows, columns);
    if (status_allocation_field != A_ALLOCATED_SUCCESSFULLY) {
        printf("Error: could not allocate memory for field!\n");

        if (array_y) {
            free(array_y);
            array_y = NULL;
        }
        if (array_x) {
            free(array_x);
            array_x = NULL;
        }
        if (postfix_notation) {
            free(postfix_notation);
            postfix_notation = NULL;
        }
        if (infix_notation) {
            free(infix_notation);
            infix_notation = NULL;
        }
        if (expression) {
            free(expression);
            expression = NULL;
        }
        return -1;
    }




    set_empty_field(field, rows, columns, blank_symbol);
    set_graph_on_empty_field(field, rows, columns, array_of_rows, rows, filled_symbol);

    draw_field(field, rows, columns);


    // TODO: deallocate everything!
    return 0;
}

// void set_lexeme_placeholders_array(Lexeme *lexemes, int length, double value_for_placeholder);


int main() {


    #ifdef TEST_GRAPH_
    printf("Test in main():\n");
    stack_test_visual();
    get_lexeme_test_visual(get_lexeme);  
    shunting_yard_test(shunting_yard);
    calculate_reverse_polish_notation_test(calculate_reversed_polish_notation);
    string_to_int_test(string_to_int);
    string_to_double_test(string_to_double);
    parse_to_lexemes_test(parse_to_lexemes_allocate);
    check_expression_and_count_lexemes_test(check_expression_and_count_lexemes);
    #endif //  TEST_GRAPH_


    // shunting_yard_test(shunting_yard, "Testing shunting_yard:");

    // draw_field(example_field, rows, columns);

    // printf("After draw_print():\n");
    // char *expression = NULL;
    // size_t allocated_length = 0u;
    // ssize_t actual_length = getline(&expression, &allocated_length, stdin);


    // Defined in header <stdio.h>
    // char *lineptr = NULL;
    // size_t n = 0u;
    // ssize_t actual_length =  getline_allocate(&lineptr, &n, stdin);


    return 0;
}

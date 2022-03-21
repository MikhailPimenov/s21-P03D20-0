#include <stdio.h>
#include <stdlib.h>

#include "drawing/drawing.h"
#include "translating_calculating/calculate_reverse_polish_notation.h"
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
    double current_x = minimum_x;

    for (int column = 0; column < amount_of_columns; ++column) {
        definition_area_already_allocated[column] = current_x;
        current_x += delta_x;
    }
}

void print_array_int(const int *const array, int length) {
    for (int index = 0; index < length; ++index) {
        printf("%d\n", array[index]);
    }
    printf("\n");
}
void print_array_double(const double *const array, int length) {
    for (int index = 0; index < length; ++index) {
        printf("%lf\n", array[index]);
    }
    printf("\n");
}

// TODO: move somewhere this struct, it is supposed to be in header file, perhaps in drawing module
typedef struct Value {
    double value;
    int row;
    int is_not_empty;
} Value;

void print_graph(const double *const x, const Value *const values, int length) {
    printf("   x\t\t\tcolumn\t\t  y\t\t\trow\t\tstatus\n");
    for (int index = 0; index < length; ++index) {
        printf(
            "%lf\t\t%d\t\t%lf\t\t%d\t\t%s\n", 
            x[index], 
            index, 
            values[index].value, 
            values[index].row, 
            (values[index].is_not_empty? "filled" : "empty" ));
    }
}

int calculate_values_for_definition_area(
    Value *values,
    double *definition_area,
    int length,
    const Lexeme *const postfix_notation,
    int length_of_postfix_notation,
    int (*calculate_rpn_function)(const Lexeme *const, int, double*)
) {
    Lexeme *postfix_notation_with_filled_placeholders = malloc(length_of_postfix_notation * sizeof(Lexeme));
    copy_lexemes_array(postfix_notation_with_filled_placeholders, postfix_notation, length_of_postfix_notation);
    // printf("Copy of lexeme array:\n");
    // print_lexeme_array(postfix_notation_with_filled_placeholders, length_of_postfix_notation);

    // printf("Lexeme arrays with substituted placeholders:\n");
    for (int column = 0; column < length; ++column) {
        // printf("Value to fill placeholder: %lf\n", definition_area[column]);
        set_lexeme_placeholders_array(
            postfix_notation_with_filled_placeholders, 
            length_of_postfix_notation, 
            definition_area[column]
        );
        // print_lexeme_array(postfix_notation_with_filled_placeholders, length_of_postfix_notation);

        
        const int status = calculate_rpn_function(
            postfix_notation_with_filled_placeholders,
            length_of_postfix_notation,
            &(values[column].value)
        );

        values[column].is_not_empty = (status == C_SUCCESS) ? 1 : 0;
        // TODO: not to return, but assign status to array of statuses for each x
        // if (status != C_SUCCESS) {
            // if (postfix_notation_with_filled_placeholders) {
                // free(postfix_notation_with_filled_placeholders);
                // postfix_notation_with_filled_placeholders = NULL;
            // }
            // return status;
        // }
    }

    if (postfix_notation_with_filled_placeholders) {
        free(postfix_notation_with_filled_placeholders);
        postfix_notation_with_filled_placeholders = NULL;
    }

    return C_SUCCESS;
}


void set_array_of_rows_from_y_values(/*int *array_of_rows_out,*/  Value *const array_of_y, int length, int amount_of_possible_rows) {
    for (int index = 0; index < length; ++index) {
        if (array_of_y[index].is_not_empty) {
            const int filled_row = get_row_number_from_y(array_of_y[index].value, amount_of_possible_rows);
            // array_of_rows_out[index] = filled_row;
            array_of_y[index].row = filled_row;
            continue;
        }
        array_of_y[index].row = 0; 
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


void set_graph_on_empty_field(char **field, int rows, int columns, /*int *array_of_rows*/const Value *const array_of_rows, int length, char filled_symbol) {
    const int limiting_length = (length <= columns) ? length : columns;
    for (int column = 0; column < limiting_length; ++column) {
        // printf("column #%d\n", column);
        
        if (array_of_rows[column].is_not_empty && 0 <= array_of_rows[column].row && array_of_rows[column].row < rows) 
            field[array_of_rows[column].row][column] = filled_symbol;
    }
}

int program(int rows, int columns, char filled_symbol, char blank_symbol) {
    static const int show_every_stage = 1;
    char *expression = NULL;
    size_t allocated_length = 0u;
    printf("Enter expression without spaces and with braces, for example -0.5*x or sin(x), or sin(cos(2*x)):\n");
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
    
    if (show_every_stage) {
        printf("List of lexemes in infix notation:\n");
        print_lexeme_array(infix_notation, amount_of_infix_lexemes);
    }
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
    
    if (show_every_stage) {
        printf("List of lexemes in postfix notation:\n");
        print_lexeme_array(postfix_notation, amount_of_postfix_lexemes);
    }

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
    const double pi_constant = 3.14;
    create_definition_area(array_x, columns, 0.0, 4.0 * pi_constant);
    
    // if (show_every_stage) {
        // printf("Discrete definition area:\n");
        // print_array_double(array_x, columns);
    // }
    
    Value *array_y = malloc(columns * sizeof(Value));
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

    /*const int status_caclulation =*/ calculate_values_for_definition_area(
        array_y,
        array_x,
        columns,
        postfix_notation,
        amount_of_postfix_lexemes,
        calculate_reversed_polish_notation);

    // if (show_every_stage) {
        // printf("Discrete values:\n");
        // print_array_double(array_y, columns);
    // }
    
    // if (status_caclulation != C_SUCCESS) {
    //     printf("Error: something went wrong during computation of reversed polish notation!\n");

    //     if (array_y) {
    //         free(array_y);
    //         array_y = NULL;
    //     }
    //     if (array_x) {
    //         free(array_x);
    //         array_x = NULL;
    //     }
    //     if (postfix_notation) {
    //         free(postfix_notation);
    //         postfix_notation = NULL;
    //     }
    //     if (infix_notation) {
    //         free(infix_notation);
    //         infix_notation = NULL;
    //     }
    //     if (expression) {
    //         free(expression);
    //         expression = NULL;
    //     }

    //     return -1;
    // }

    // int *array_of_rows = malloc(columns * sizeof(int));
    // if (array_of_rows == NULL) {
    //     printf("Error: could not allocate memory for array of rows!\n");

    //     if (array_y) {
    //         free(array_y);
    //         array_y = NULL;
    //     }
    //     if (array_x) {
    //         free(array_x);
    //         array_x = NULL;
    //     }
    //     if (postfix_notation) {
    //         free(postfix_notation);
    //         postfix_notation = NULL;
    //     }
    //     if (infix_notation) {
    //         free(infix_notation);
    //         infix_notation = NULL;
    //     }
    //     if (expression) {
    //         free(expression);
    //         expression = NULL;
    //     }
    //     return -1;
    // }
    
    set_array_of_rows_from_y_values(/*array_of_rows, */array_y, columns, rows);
    print_graph(array_x, array_y, columns);
    // if (show_every_stage) {
    //     printf("Numbers of rows which will be filled:\n");
    //     print_array_int(array_of_rows, columns);
    // }
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
    set_graph_on_empty_field(field, rows, columns, /*array_of_rows,*/array_y, columns, filled_symbol);


    draw_field(field, rows, columns);



    deallocate_field(&field);

    // if (array_of_rows) {
        // free(array_of_rows);
        // array_of_rows = NULL;
    // }
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

    return 0;
}

// void set_lexeme_placeholders_array(Lexeme *lexemes, int length, double value_for_placeholder);


int main() {


    #ifdef TEST_GRAPH_
    printf("Test in main():\n");
    // stack_test_visual();
    // get_lexeme_test_visual(get_lexeme);  // TODO: modify to print lexeme type correctly
    string_to_int_test(string_to_int);
    string_to_double_test(string_to_double);
    check_expression_and_count_lexemes_test(check_expression_and_count_lexemes);
    parse_to_lexemes_test(parse_to_lexemes_allocate);
    shunting_yard_test(shunting_yard);
    calculate_reverse_polish_notation_test(calculate_reversed_polish_notation);
    #endif //  TEST_GRAPH_

    program(35, 85, '*', '.');

    return 0;
}

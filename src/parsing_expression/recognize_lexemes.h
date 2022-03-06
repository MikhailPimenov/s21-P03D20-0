#ifndef SRC_PARSING_EXPRESSION_RECOGNIZE_LEXEMES_H_
#define SRC_PARSING_EXPRESSION_RECOGNIZE_LEXEMES_H_

#include <stdlib.h>
#include <stdio.h>
#include "string_to_number_error_codes.h"
#include "string_to_double.h"


enum recognition_status {
    RS_RECOGNIZED = 1,
    RS_NOT_RECOGNIZED = 0
};

int is_symbol_recognized(const char *infix_notation_row, int length_without_terminator, char symbol_to_recognize);
const char *recognize_sinlge_symbol_and_create_lexeme(const char *infix_notation_row, int length_without_terminator, char symbol_to_recognize, int *lexeme_counter_out);
const char *recognize_placeholder_symbol_and_count_it(const char *infix_notation_row, int length_without_terminator, int *lexeme_counter_out);
const char *recognize_opening_brace_and_count_it(const char *infix_notation_row, int length_without_terminator, int *lexeme_counter_out);
const char *recognize_closing_brace_and_count_it(const char *infix_notation_row, int length_without_terminator, int *lexeme_counter_out);
const char *recognize_add_symbol_and_count_it(const char *infix_notation_row, int length_without_terminator, int *lexeme_counter_out);
const char *recognize_subtract_symbol_and_count_it(const char *infix_notation_row, int length_without_terminator, int *lexeme_counter_out);
const char *recognize_multiply_symbol_and_count_it(const char *infix_notation_row, int length_without_terminator, int *lexeme_counter_out);
const char *recognize_divide_symbol_and_count_it(const char *infix_notation_row, int length_without_terminator, int *lexeme_counter_out);
const char *recognize_power_symbol_and_count_it(const char *infix_notation_row, int length_without_terminator, int *lexeme_counter_out);


int is_function_recognized(const char *infix_notation_row, int length_without_terminator, const char *function_name_as_string, int function_name_length_without_terminator);
const char *recognize_function_and_create_lexeme(const char *infix_notation_row, int length_without_terminator, const char *function_name_as_string, int function_name_length_without_terminator, int *lexeme_counter_out);
const char *recognize_sine_and_count_it(const char *infix_notation_row, int length_without_terminator, int *lexeme_counter_out);
const char *recognize_cosine_and_count_it(const char *infix_notation_row, int length_without_terminator, int *lexeme_counter_out);
const char *recognize_tangent_and_count_it(const char *infix_notation_row, int length_without_terminator, int *lexeme_counter_out);
const char *recognize_cotangent_and_count_it(const char *infix_notation_row, int length_without_terminator, int *lexeme_counter_out);
const char *recognize_natural_logarithm_and_count_it(const char *infix_notation_row, int length_without_terminator, int *lexeme_counter_out);
const char *recognize_square_root_and_count_it(const char *infix_notation_row, int length_without_terminator, int *lexeme_counter_out);
const char *recognize_double_and_create_lexeme(const char *infix_notation_row, int length_without_terminator, int *lexeme_counter_out);

#endif  //   SRC_PARSING_EXPRESSION_RECOGNIZE_LEXEMES_H_
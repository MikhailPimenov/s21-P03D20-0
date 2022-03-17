#ifndef SRC_PARSING_EXPRESSION_CREATE_LEXEMES_H_
#define SRC_PARSING_EXPRESSION_CREATE_LEXEMES_H_

#include "../data_structures/lexeme.h"
#include "recognize_lexemes.h"

void create_lexemes(const char *infix_notation_row, int length_without_terminator, Lexeme *lexemes, int lexemes_length);

/*
const char *recognize_placeholder_symbol_and_create_lexeme(const char *infix_notation_row, int length_without_terminator, Lexeme *const lexeme_out, int *lexemes_created_out);
const char *recognize_opening_brace_and_create_lexeme(const char *infix_notation_row, int length_without_terminator, Lexeme *const lexeme_out, int *lexemes_created_out);
const char *recognize_closing_brace_and_create_lexeme(const char *infix_notation_row, int length_without_terminator, Lexeme *const lexeme_out, int *lexemes_created_out);
const char *recognize_add_symbol_and_create_lexeme(const char *infix_notation_row, int length_without_terminator, Lexeme *const lexeme_out, int *lexemes_created_out);
const char *recognize_multiply_symbol_and_create_lexeme(const char *infix_notation_row, int length_without_terminator, Lexeme *const lexeme_out, int *lexemes_created_out);
const char *recognize_divide_symbol_and_create_lexeme(const char *infix_notation_row, int length_without_terminator, Lexeme *const lexeme_out, int *lexemes_created_out);
const char *recognize_power_symbol_and_create_lexeme(const char *infix_notation_row, int length_without_terminator, Lexeme *const lexeme_out, int *lexemes_created_out);

const char *recognize_subtract_symbol_and_create_three_lexemes_instead_of_one(
    const char *infix_notation_row, 
    int length_without_terminator, 
    Lexeme *const lexeme1_in_array_out, 
    Lexeme *const lexeme2_in_array_out, 
    Lexeme *const lexeme3_in_array_out,
    int lexemes_length,
    int *lexemes_created_out);
const char *recognize_subtract_symbol_and_create_two_lexemes_instead_of_one(
    const char *infix_notation_row,
    int length_without_terminator,
    Lexeme *const lexeme1_in_array_out,
    Lexeme *const lexeme2_in_array_out,
    int lexemes_length,
    int *lexemes_created_out);

const char *recognize_sine_and_create_lexeme(const char *infix_notation_row, int length_without_terminator, Lexeme *const lexeme_out, int *lexemes_created_out);
const char *recognize_cosine_and_create_lexeme(const char *infix_notation_row, int length_without_terminator, Lexeme *const lexeme_out, int *lexemes_created_out);
const char *recognize_tangent_and_create_lexeme(const char *infix_notation_row, int length_without_terminator, Lexeme *const lexeme_out, int *lexemes_created_out);
const char *recognize_cotangent_and_create_lexeme(const char *infix_notation_row, int length_without_terminator, Lexeme *const lexeme_out, int *lexemes_created_out);
const char *recognize_natural_logarithm_and_create_lexeme(const char *infix_notation_row, int length_without_terminator, Lexeme *const lexeme_out, int *lexemes_created_out);
const char *recognize_square_root_and_create_lexeme(const char *infix_notation_row, int length_without_terminator, Lexeme *const lexeme_out, int *lexemes_created_out);
const char *recognize_double_and_create_lexeme(const char *infix_notation_row, int length_without_terminator, Lexeme *const lexeme_out, int *lexemes_created_out);
*/

#endif  //  SRC_PARSING_EXPRESSION_CREATE_LEXEMES_H_
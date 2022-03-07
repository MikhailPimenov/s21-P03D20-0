#ifndef SRC_DATA_STRUCTURES_LEXEME_H_
#define SRC_DATA_STRUCTURES_LEXEME_H_

#include <stdio.h>
#include "../translating_calculating/common.h"

enum Lexeme_types {
    LT_OPERAND = 0,
    LT_ACTION = 1,
    LT_OPERAND_PLACEHOLDER = 2,
    LT_BRACE = 3
};

typedef struct Lexeme {
    char data[8];
    int actual_type;
} Lexeme;

enum operator_precedence {
    OP_LOWEST = -1,
    OP_LOW = 0,
    OP_MEDIUM = 1,
    OP_HIGH = 2
};

void print_lexeme(const Lexeme* lexeme);

void print_lexeme_with_endline_and_type(const Lexeme *const lexeme);

void print_lexeme_array(const Lexeme *const array, int length);

void get_lexeme(const Lexeme *const lexeme, double *const operand_out, char *const action_out);

void set_lexeme(Lexeme *const lexeme, int actual_type, double operand, char action);

void set_lexeme_placeholders_array(Lexeme *lexemes, int length, double value_for_placeholder);

int are_lexemes_equal(const Lexeme *const left, const Lexeme *const right);

int are_lexeme_arrays_equal(const Lexeme *const first, const Lexeme *const second, int length);

int is_operand(const Lexeme *lexeme);

int is_action(const Lexeme *lexeme);

int is_brace(const Lexeme *lexeme);

int get_precedence(const Lexeme *lexeme);

int has_lower_precedence(const Lexeme *left, const Lexeme *right);

int has_top_higher_precedence(Lexeme top, Lexeme current_lexeme);

int is_opening_brace(Lexeme lexeme);

int is_closing_brace(Lexeme lexeme);

#endif //  SRC_DATA_STRUCTURES_LEXEME_H_
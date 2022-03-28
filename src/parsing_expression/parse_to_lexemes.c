#include "parse_to_lexemes.h"


void parse_to_lexemes_allocate(const char *infix_notation_row, int length_without_terminator, Lexeme **infix_notation_out, int *lexeme_list_length_out) {
    // printf("parse_to_lexemes_allocate():\n");
    // printf("%s\n", infix_notation_row);
    // printf("length = %d\n", length_without_terminator);

    // if (infix_notation_out)
    //     infix_notation_out = NULL;
    // *lexeme_list_length_out = 0;
    // printf("checking and counting...\n");
    int amount_of_lexemes = 0;
    const int status_check = check_expression_and_count_lexemes(infix_notation_row, length_without_terminator, &amount_of_lexemes);
    // printf("amount = %d\n", amount_of_lexemes);
    if (status_check != EC_EXPRESSION_IS_CORRECT) {
        printf("STRING IS NOT CORRECT!\n");
        return;
    }

    // printf("checked and counted: %d\n", amount_of_lexemes);
    Lexeme *lexemes = malloc(amount_of_lexemes * sizeof(Lexeme));
    if (lexemes == NULL) {
        *lexeme_list_length_out = 0;
        *infix_notation_out = NULL;
        return;
    }

    create_lexemes(infix_notation_row, length_without_terminator, lexemes, amount_of_lexemes);

    // print_lexeme_array(lexemes, amount_of_lexemes);
    // printf("pointer to pointer = %p\n", infix_notation_out);
    *infix_notation_out = lexemes;
    *lexeme_list_length_out = amount_of_lexemes;
    // printf("pointer = %p\n", *infix_notation_out);
    // print_lexeme_array(*infix_notation_out, amount_of_lexemes);
    // *lexeme_list_length_out = amount_of_lexemes;
}
#include "parse_to_lexemes.h"

// static int get_amount_of_lexemes(const char *infix_notation_row, int length_without_terminator) {

// }

void parse_to_lexemes_allocate(const char *infix_notation_row, int length_without_terminator, Lexeme **infix_notation_out, int *lexeme_list_length_out) {
    printf("parse_to_lexemes():\n");
    printf("%s\n", infix_notation_row);
    printf("length = %d\n", length_without_terminator);

    if (infix_notation_out)
        infix_notation_out = NULL;
    *lexeme_list_length_out = 0;
    // print_lexeme_array(infix_notation_row, *length_out);
}
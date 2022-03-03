#include "parse_to_lexemes.h"


void parse_to_lexemes_allocate(const char *infix_notation_row, int length, Lexeme **infix_notation_out, int *length_out) {
    printf("parse_to_lexemes():\n");
    printf("%s\n", infix_notation_row);
    printf("length = %d\n", length);

    if (infix_notation_out)
        infix_notation_out = NULL;
    *length_out = 0;
    // print_lexeme_array(infix_notation_row, *length_out);
}
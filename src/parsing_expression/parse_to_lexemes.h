#ifndef SRC_PARSING_EXPRESSION_PARSE_TO_LEXEMES_H_
#define SRC_PARSING_EXPRESSION_PARSE_TO_LEXEMES_H_

#include <stdlib.h>

#include "../data_structures/lexeme.h"
#include "../data_structures/stack.h"


void parse_to_lexemes_allocate(const char *infix_notation_row, int length, Lexeme **infix_notation_out, int *length_out);

#endif  //  SRC_PARSING_EXPRESSION_PARSE_TO_LEXEMES_H_

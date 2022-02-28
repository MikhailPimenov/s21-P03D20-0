#ifndef SRC_TRANSLATING_CALCULATING_SHUNTING_YARD_H_
#define SRC_TRANSLATING_CALCULATING_SHUNTING_YARD_H_

#include <stdlib.h>

#define LEXEME_T_

#include "../data_structures/lexeme.h"
#include "../data_structures/stack.h"


void shunting_yard(const Lexeme *infix_notation, int length, Lexeme *postfix_notation, int *length_out);

#endif //  SRC_TRANSLATING_CALCULATING_SHUNTING_YARD_H_
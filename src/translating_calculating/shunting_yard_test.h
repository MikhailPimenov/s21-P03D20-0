#ifndef SRC_TRANSLATING_CALCULATING_SHUNTING_YARD_TEST_H_
#define SRC_TRANSLATING_CALCULATING_SHUNTING_YARD_TEST_H_

#include <stdio.h>

#define LEXEME_T_

#include "common.h"
#include "../data_structures/lexeme.h"

// void shunting_yard_test(const char *(*shunting_yard_function)(const char*), const char* greetings);
// void shunting_yard_test(void (*shunting_yard_function)(const Lexeme* infix_notation, int length, Lexeme* postfix_notation, int *length_out));
// void shunting_yard_test(void (*shunting_yard_function)(const Lexeme* infix_notation, int length, Lexeme* postfix_notation, int *length_out), const char *greetings);
void shunting_yard_test(void (*shunting_yard_function)(const Lexeme *, int, Lexeme *, int *));

#endif //  SRC_TRANSLATING_CALCULATING_SHUNTING_YARD_TEST_H_

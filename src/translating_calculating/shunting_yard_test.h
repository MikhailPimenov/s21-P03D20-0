#ifndef SRC_TRANSLATING_CALCULATING_SHUNTING_YARD_TEST_H_
#define SRC_TRANSLATING_CALCULATING_SHUNTING_YARD_TEST_H_

#include <stdio.h>

#define LEXEME_T_

#include "common.h"
#include "../data_structures/lexeme.h"

void shunting_yard_test(void (*shunting_yard_function)(const Lexeme *, int, Lexeme *, int *));

#endif //  SRC_TRANSLATING_CALCULATING_SHUNTING_YARD_TEST_H_

#ifndef SRC_TRANSLATING_CALCUCATING_CALCULATE_REVERSED_POLISH_NOTATION_TEST_
#define SRC_TRANSLATING_CALCUCATING_CALCULATE_REVERSED_POLISH_NOTATION_TEST_

#define LEXEME_T_

#include <stdio.h>
#include <math.h>

#include "../data_structures/lexeme.h"
#include "../translating_calculating/common.h"

#include "calculation_error_codes.h"

void calculate_reverse_polish_notation_test(int (*calculate_reversed_polish_notation_function)(const Lexeme *const, int, double*));

#endif  //  SRC_TRANSLATING_CALCUCATING_CALCULATE_REVERSED_POLISH_NOTATION_TEST_
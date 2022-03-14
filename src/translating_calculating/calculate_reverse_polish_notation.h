#ifndef SRC_TRANSLATING_CALCUCATING_CALCULATE_REVERSED_POLISH_NOTATION_
#define SRC_TRANSLATING_CALCUCATING_CALCULATE_REVERSED_POLISH_NOTATION_

#define LEXEME_T_

#include <stdio.h>
#include <math.h>

#include "../data_structures/lexeme.h"
#include "../data_structures/stack.h"
#include "../translating_calculating/common.h"

#include "calculation_error_codes.h"

int calculate_reversed_polish_notation(const Lexeme *const postfix_notation, int length, double *result_out);

#endif  //  SRC_TRANSLATING_CALCUCATING_CALCULATE_REVERSED_POLISH_NOTATION_
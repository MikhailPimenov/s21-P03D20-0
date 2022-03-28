#ifndef SRC_PROGRAM_PROGRAM_H_
#define SRC_PROGRAM_PROGRAM_H_

#include <stdlib.h>

#include "../data_structures/lexeme.h"
#include "../translating_calculating/calculation_error_codes.h"
#include "../translating_calculating/calculate_reverse_polish_notation.h"
#include "../field/allocate_deallocate_field.h"
#include "../drawing/drawing.h"
#include "../input/input.h"
#include "../parsing_expression/create_lexemes.h"
#include "../parsing_expression/expression_check_error_codes.h"
#include "../parsing_expression/check_expression_and_count_lexemes.h"
#include "../translating_calculating/shunting_yard.h"

int program(int rows, int columns, char filled_symbol, char blank_symbol);

#endif  //  SRC_PROGRAM_PROGRAM_H_
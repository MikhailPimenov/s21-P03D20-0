#include <stdio.h>
#include "drawing/drawing.h"
#include "translating_calculating/calculate_reverse_polish_notation.h"
#include "translating_calculating/translating.h"
#include "translating_calculating/shunting_yard.h"

#include "data_structures/lexeme.h"
#include "data_structures/stack.h"

#include "parsing_expression/parse_to_lexemes.h"

#include "parsing_expression/string_to_int.h"
#include "parsing_expression/string_to_double.h"

#include "parsing_expression/check_expression_and_count_lexemes.h"
// #define TEST_GRAPH_

#ifdef TEST_GRAPH_
#include "data_structures/lexeme_test.h"
#include "data_structures/stack_test.h"
#include "translating_calculating/shunting_yard_test.h"
#include "translating_calculating/calculate_reverse_polish_notation_test.h"
#include "parsing_expression/parse_to_lexemes_test.h"
#include "parsing_expression/string_to_int_test.h"
#include "parsing_expression/string_to_double_test.h"
#include "parsing_expression/check_expression_and_count_lexemes_test.h"
#endif //  TEST_GRAPH_



int main() {
    #ifdef TEST_GRAPH_
    printf("Test in main():\n");
    // stack_test_visual();
    // get_lexeme_test_visual(get_lexeme);  
    shunting_yard_test(shunting_yard);
    calculate_reverse_polish_notation_test(calculate_reversed_polish_notation);
    string_to_int_test(string_to_int);
    string_to_double_test(string_to_double);
    parse_to_lexemes_test(parse_to_lexemes_allocate);
    check_expression_and_count_lexemes_test(check_expression_and_count_lexemes);
    #endif //  TEST_GRAPH_


    // shunting_yard_test(shunting_yard, "Testing shunting_yard:");

    // draw_field(example_field, rows, columns);

    // printf("After draw_print():\n");

    return 0;
}

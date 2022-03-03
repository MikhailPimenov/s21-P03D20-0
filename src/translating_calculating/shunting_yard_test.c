#include "shunting_yard_test.h"

static void compare_and_print_input_output_and_resolution(
    int case_number,
    const Lexeme *const input,
    int input_length,
    const Lexeme *const expected_output,
    int expected_output_length,
    const Lexeme *const actual_output,
    int actual_output_length, 
    int silent_on_success
) {
    printf("test #%d:\t", case_number);
    if (expected_output_length == actual_output_length && are_lexeme_arrays_equal(expected_output, actual_output, expected_output_length)) {
        printf("ok\n");
        if (silent_on_success)
            return;
    } else {
        printf("FAILED\n");
    }

    printf("input:\n");
    print_lexeme_array(input, input_length);
    printf("output expected:\n");
    print_lexeme_array(expected_output, expected_output_length);
    printf("output   actual:\n");
    print_lexeme_array(actual_output, actual_output_length);

    printf("\n");
}

void shunting_yard_test(void (*shunting_yard_function)(const Lexeme *, int, Lexeme *, int *)) {
    printf("shunting_yard_test():\n");
    // const char *case1 = "2 + 1";
    // const char *expected1 = "2 1 +";

    //  if 1 there won't be detailed input/output info for successfully passed test
    int silent_on_success = 1;  

    {
        const int length1 = 3;
        Lexeme case1[3];
        set_lexeme(case1 + 0, LT_OPERAND, 2.0, '\0');
        set_lexeme(case1 + 1, LT_ACTION,  0.0,  '+');
        set_lexeme(case1 + 2, LT_OPERAND, 1.0, '\0');

        Lexeme expected1[3];
        set_lexeme(expected1 + 0, LT_OPERAND, 2.0, '\0');
        set_lexeme(expected1 + 1, LT_OPERAND, 1.0, '\0');
        set_lexeme(expected1 + 2, LT_ACTION,  0.0,  '+');

        Lexeme actual1[3];
        const int expected_length1 = 3;
        int actual_length1 = -1;
        shunting_yard_function(case1, length1, actual1, &actual_length1);
        compare_and_print_input_output_and_resolution(1, case1, length1, expected1, expected_length1, actual1, actual_length1, silent_on_success);
    }

    {
        const int length2 = 5;
        Lexeme case2[5];
        set_lexeme(case2 + 0, LT_OPERAND, 59.0, '\0');
        set_lexeme(case2 + 1, LT_ACTION,   0.0,  '+');
        set_lexeme(case2 + 2, LT_OPERAND,  7.0, '\0');
        set_lexeme(case2 + 3, LT_ACTION,   0.0,  '/');
        set_lexeme(case2 + 4, LT_OPERAND,  2.0, '\0');

        Lexeme expected2[5];
        set_lexeme(expected2 + 0, LT_OPERAND, 59.0, '\0');
        set_lexeme(expected2 + 1, LT_OPERAND,  7.0, '\0');
        set_lexeme(expected2 + 2, LT_OPERAND,  2.0, '\0');
        set_lexeme(expected2 + 3, LT_ACTION,   0.0,  '/');
        set_lexeme(expected2 + 4, LT_ACTION,   0.0,  '+');

        Lexeme actual2[5];
        const int expected_length2 = 5;
        int actual_length2 = -1;
        shunting_yard_function(case2, length2, actual2, &actual_length2);
        compare_and_print_input_output_and_resolution(2, case2, length2, expected2, expected_length2, actual2, actual_length2, silent_on_success);
    }

    {
        const int length3 = 7;
        Lexeme case3[7];
        set_lexeme(case3 + 0, LT_ACTION,  0.0, '(' );
        set_lexeme(case3 + 1, LT_OPERAND, 5.0, '\0');
        set_lexeme(case3 + 2, LT_ACTION,  0.0, '+' );
        set_lexeme(case3 + 3, LT_OPERAND, 7.0, '\0');
        set_lexeme(case3 + 4, LT_ACTION,  0.0, ')' );
        set_lexeme(case3 + 5, LT_ACTION,  0.0, '/' );
        set_lexeme(case3 + 6, LT_OPERAND, 2.0, '\0');

        Lexeme expected3[5];
        set_lexeme(expected3 + 0, LT_OPERAND, 5.0, '\0');
        set_lexeme(expected3 + 1, LT_OPERAND, 7.0, '\0');
        set_lexeme(expected3 + 2, LT_ACTION,  0.0, '+' );
        set_lexeme(expected3 + 3, LT_OPERAND, 2.0, '\0');
        set_lexeme(expected3 + 4, LT_ACTION,  0.0, '/' );

        Lexeme actual3[5];
        const int expected_length3 = 5;
        int actual_length3 = -1;
        shunting_yard_function(case3, length3, actual3, &actual_length3);
        compare_and_print_input_output_and_resolution(3, case3, length3, expected3, expected_length3, actual3, actual_length3, silent_on_success);
    }

    {
        // // const char *case4 = " 5 * 2 - 3";
        // // const char *expected4 = "5 2 * 3 -";
        const int length4 = 5;
        Lexeme case4[5];
        set_lexeme(case4 + 0, LT_OPERAND, 5.0, '\0');
        set_lexeme(case4 + 1, LT_ACTION,  0.0, '*' );
        set_lexeme(case4 + 2, LT_OPERAND, 2.0, '\0');
        set_lexeme(case4 + 3, LT_ACTION,  0.0, '-' );
        set_lexeme(case4 + 4, LT_OPERAND, 3.0, '\0');

        Lexeme expected4[5];
        set_lexeme(expected4 + 0, LT_OPERAND, 5.0, '\0');
        set_lexeme(expected4 + 1, LT_OPERAND, 2.0, '\0');
        set_lexeme(expected4 + 2, LT_ACTION,  0.0, '*' );
        set_lexeme(expected4 + 3, LT_OPERAND, 3.0, '\0');
        set_lexeme(expected4 + 4, LT_ACTION,  0.0, '-' );

        Lexeme actual4[5];
        const int expected_length4 = 5;
        int actual_length4 = -1;
        shunting_yard_function(case4, length4, actual4, &actual_length4);
        compare_and_print_input_output_and_resolution(4, case4, length4, expected4, expected_length4, actual4, actual_length4, silent_on_success);
    }

    {
        // const char *case5 = " 5 * ( 2 - 3 )";
        // const char *expected5 = "5 2 3 - *";
        const int length5 = 7;
        Lexeme case5[7];
        set_lexeme(case5 + 0, LT_OPERAND, 5.0, '\0');
        set_lexeme(case5 + 1, LT_ACTION,  0.0,  '*');
        set_lexeme(case5 + 2, LT_ACTION,  0.0,  '(');
        set_lexeme(case5 + 3, LT_OPERAND, 2.0, '\0');
        set_lexeme(case5 + 4, LT_ACTION,  0.0, '-' );
        set_lexeme(case5 + 5, LT_OPERAND, 3.0, '\0');
        set_lexeme(case5 + 6, LT_ACTION,  0.0, ')' );

        Lexeme expected5[5];
        set_lexeme(expected5 + 0, LT_OPERAND, 5.0, '\0');
        set_lexeme(expected5 + 1, LT_OPERAND, 2.0, '\0');
        set_lexeme(expected5 + 2, LT_OPERAND, 3.0, '\0');
        set_lexeme(expected5 + 3, LT_ACTION,  0.0, '-' );
        set_lexeme(expected5 + 4, LT_ACTION,  0.0,  '*');

        Lexeme actual5[5];
        const int expected_length5 = 5;
        int actual_length5 = -1;
        shunting_yard_function(case5, length5, actual5, &actual_length5);
        compare_and_print_input_output_and_resolution(5, case5, length5, expected5, expected_length5, actual5, actual_length5, silent_on_success);
    }

    {
        // const char *case5 = " 5 * ( 2 - 3 )";
        // const char *expected5 = "5 2 3 - *";

        // 1-5 -> 1, -, 5
        // 1-5 -> 1, +, -5
        // -1 + 5 ->

        // -5 -> ((-1) * 5) -> -1, 5, *
        // -(5 + 6) - 4 -> ((-1) * (5 + 6)) - 4
        // 4 / -(5 + 6) -> incorrect
        // 4 / (-(5 + 6)) -> 4 / ((-1) * (5 + 6))
        // 

        // const int length6 = 7;
        // Lexeme case6[7];
        // set_lexeme(case6 + 0, LT_OPERAND, 5.0, '\0');
        // set_lexeme(case6 + 1, LT_ACTION,  0.0,  '*');
        // set_lexeme(case6 + 2, LT_ACTION,  0.0,  '(');
        // set_lexeme(case6 + 3, LT_OPERAND, 2.0, '\0');
        // set_lexeme(case6 + 4, LT_ACTION,  0.0, '-' );
        // set_lexeme(case6 + 5, LT_OPERAND, 3.0, '\0');
        // set_lexeme(case6 + 6, LT_ACTION,  0.0, ')' );

        // Lexeme expected6[5];
        // set_lexeme(expected6 + 0, LT_OPERAND, 5.0, '\0');
        // set_lexeme(expected6 + 1, LT_OPERAND, 2.0, '\0');
        // set_lexeme(expected6 + 2, LT_OPERAND, 3.0, '\0');
        // set_lexeme(expected6 + 3, LT_ACTION,  0.0, '-' );
        // set_lexeme(expected6 + 4, LT_ACTION,  0.0,  '*');

        // Lexeme actual6[5];
        // const int expected_length6 = 5;
        // int actual_length6 = -1;
        // shunting_yard_function(case6, length6, actual6, &actual_length6);
        // compare_and_print_input_output_and_resolution(6, case6, length6, expected6, expected_length6, actual6, actual_length6, silent_on_success);
    }
}
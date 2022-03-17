#include "shunting_yard_test.h"

static void __compare_and_print_input_output_and_resolution(
    int case_number,
    const Lexeme *const input,
    int input_length,
    const Lexeme *const expected_output,
    int expected_output_length,
    const Lexeme *const actual_output,
    int actual_output_length, 
    int silent_on_success
) {
    printf("Test #%d:\t", case_number);
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
    printf("\nshunting_yard_test():\n");
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
        __compare_and_print_input_output_and_resolution(1, case1, length1, expected1, expected_length1, actual1, actual_length1, silent_on_success);
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
        __compare_and_print_input_output_and_resolution(2, case2, length2, expected2, expected_length2, actual2, actual_length2, silent_on_success);
    }

    {
        const int length3 = 7;
        Lexeme case3[7];
        set_lexeme(case3 + 0, LT_BRACE,   0.0, '(' );
        set_lexeme(case3 + 1, LT_OPERAND, 5.0, '\0');
        set_lexeme(case3 + 2, LT_ACTION,  0.0, '+' );
        set_lexeme(case3 + 3, LT_OPERAND, 7.0, '\0');
        set_lexeme(case3 + 4, LT_BRACE,   0.0, ')' );
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
        __compare_and_print_input_output_and_resolution(3, case3, length3, expected3, expected_length3, actual3, actual_length3, silent_on_success);
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
        __compare_and_print_input_output_and_resolution(4, case4, length4, expected4, expected_length4, actual4, actual_length4, silent_on_success);
    }

    {
        // const char *case5 = " 5 * ( 2 - 3 )";
        // const char *expected5 = "5 2 3 - *";
        const int length5 = 7;
        Lexeme case5[7];
        set_lexeme(case5 + 0, LT_OPERAND, 5.0, '\0');
        set_lexeme(case5 + 1, LT_ACTION,  0.0,  '*');
        set_lexeme(case5 + 2, LT_BRACE,   0.0,  '(');
        set_lexeme(case5 + 3, LT_OPERAND, 2.0, '\0');
        set_lexeme(case5 + 4, LT_ACTION,  0.0, '-' );
        set_lexeme(case5 + 5, LT_OPERAND, 3.0, '\0');
        set_lexeme(case5 + 6, LT_BRACE,   0.0,  ')');

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
        __compare_and_print_input_output_and_resolution(5, case5, length5, expected5, expected_length5, actual5, actual_length5, silent_on_success);
    }

    {
        // const char *case5 = " x * ( 2 - 3 )";
        // const char *expected5 = "x 2 3 - *";
        const int length6 = 7;
        Lexeme case6[7];
        set_lexeme(case6 + 0, LT_PLACEHOLDER,         0.0,  'x');
        set_lexeme(case6 + 1, LT_ACTION,              0.0,  '*');
        set_lexeme(case6 + 2, LT_BRACE,               0.0,  '(');
        set_lexeme(case6 + 3, LT_OPERAND,             2.0, '\0');
        set_lexeme(case6 + 4, LT_ACTION,              0.0, '-' );
        set_lexeme(case6 + 5, LT_OPERAND,             3.0, '\0');
        set_lexeme(case6 + 6, LT_BRACE,               0.0,  ')');

        Lexeme expected6[5];
        set_lexeme(expected6 + 0, LT_PLACEHOLDER,         0.0,  'x');
        set_lexeme(expected6 + 1, LT_OPERAND,             2.0, '\0');
        set_lexeme(expected6 + 2, LT_OPERAND,             3.0, '\0');
        set_lexeme(expected6 + 3, LT_ACTION,              0.0, '-' );
        set_lexeme(expected6 + 4, LT_ACTION,              0.0,  '*');

        Lexeme actual6[5];
        const int expected_length6 = 5;
        int actual_length6 = -1;
        shunting_yard_function(case6, length6, actual6, &actual_length6);
        __compare_and_print_input_output_and_resolution(6, case6, length6, expected6, expected_length6, actual6, actual_length6, silent_on_success);


    }

    {
        // const char *case5 = " x * ( x - 3 )";
        // const char *expected5 = "x x 3 - *";
        const int length7 = 7;
        Lexeme case7[7];
        set_lexeme(case7 + 0, LT_PLACEHOLDER,         0.0,  'x');
        set_lexeme(case7 + 1, LT_ACTION,              0.0,  '*');
        set_lexeme(case7 + 2, LT_BRACE,               0.0,  '(');
        set_lexeme(case7 + 3, LT_PLACEHOLDER,         0.0,  'x');
        set_lexeme(case7 + 4, LT_ACTION,              0.0,  '-');
        set_lexeme(case7 + 5, LT_OPERAND,             3.0, '\0');
        set_lexeme(case7 + 6, LT_BRACE,               0.0,  ')');

        Lexeme expected7[5];
        set_lexeme(expected7 + 0, LT_PLACEHOLDER, 0.0,  'x');
        set_lexeme(expected7 + 1, LT_PLACEHOLDER, 0.0,  'x');
        set_lexeme(expected7 + 2, LT_OPERAND,             3.0, '\0');
        set_lexeme(expected7 + 3, LT_ACTION,              0.0,  '-');
        set_lexeme(expected7 + 4, LT_ACTION,              0.0,  '*');

        Lexeme actual7[5];
        const int expected_length7 = 5;
        int actual_length7 = -1;
        shunting_yard_function(case7, length7, actual7, &actual_length7);
        __compare_and_print_input_output_and_resolution(7, case7, length7, expected7, expected_length7, actual7, actual_length7, silent_on_success);



    }


    {
        // const char *case5 = " 5 * ( 2 - x )";
        // const char *expected5 = "5 2 x - *";
        const int length8 = 7;
        Lexeme case8[7];
        set_lexeme(case8 + 0, LT_OPERAND,             5.0, '\0');
        set_lexeme(case8 + 1, LT_ACTION,              0.0,  '*');
        set_lexeme(case8 + 2, LT_BRACE,               0.0,  '(');
        set_lexeme(case8 + 3, LT_OPERAND,             2.0, '\0');
        set_lexeme(case8 + 4, LT_ACTION,              0.0,  '-');
        set_lexeme(case8 + 5, LT_PLACEHOLDER,         0.0,  'x');
        set_lexeme(case8 + 6, LT_BRACE,               0.0,  ')');

        Lexeme expected8[5];
        set_lexeme(expected8 + 0, LT_OPERAND,             5.0, '\0');
        set_lexeme(expected8 + 1, LT_OPERAND,             2.0, '\0');
        set_lexeme(expected8 + 2, LT_PLACEHOLDER,         0.0,  'x');
        set_lexeme(expected8 + 3, LT_ACTION,              0.0,  '-');
        set_lexeme(expected8 + 4, LT_ACTION,              0.0,  '*');

        Lexeme actual8[5];
        const int expected_length8 = 5;
        int actual_length8 = -1;
        shunting_yard_function(case8, length8, actual8, &actual_length8);
        __compare_and_print_input_output_and_resolution(8, case8, length8, expected8, expected_length8, actual8, actual_length8, silent_on_success);



    }

     {
        // const char *case5 = " x * ( x - x )";
        // const char *expected5 = "x x x - *";
        const int length9 = 7;
        Lexeme case9[7];
        set_lexeme(case9 + 0, LT_PLACEHOLDER,         0.0,  'x');
        set_lexeme(case9 + 1, LT_ACTION,              0.0,  '*');
        set_lexeme(case9 + 2, LT_BRACE,               0.0,  '(');
        set_lexeme(case9 + 3, LT_PLACEHOLDER,         0.0,  'x');
        set_lexeme(case9 + 4, LT_ACTION,              0.0,  '-');
        set_lexeme(case9 + 5, LT_PLACEHOLDER,         0.0,  'x');
        set_lexeme(case9 + 6, LT_BRACE,               0.0,  ')');

        Lexeme expected9[5];
        set_lexeme(expected9 + 0, LT_PLACEHOLDER,         0.0,  'x');
        set_lexeme(expected9 + 1, LT_PLACEHOLDER,         0.0,  'x');
        set_lexeme(expected9 + 2, LT_PLACEHOLDER,         0.0,  'x');
        set_lexeme(expected9 + 3, LT_ACTION,              0.0,  '-');
        set_lexeme(expected9 + 4, LT_ACTION,              0.0,  '*');

        Lexeme actual9[5];
        const int expected_length9 = 5;
        int actual_length9 = -1;
        shunting_yard_function(case9, length9, actual9, &actual_length9);
        __compare_and_print_input_output_and_resolution(9, case9, length9, expected9, expected_length9, actual9, actual_length9, silent_on_success);

    }

    {
        // const char *case5 = " -1.0 * x ^ 2.0 ";
        // const char *expected5 = " -1.0 x 2.0 ^ * ";
        const int length10 = 5;
        Lexeme case10[5];
        set_lexeme(case10 + 0, LT_OPERAND,     -1.0, '\0');
        set_lexeme(case10 + 1, LT_ACTION,       0.0,  '*');
        set_lexeme(case10 + 2, LT_PLACEHOLDER,  0.0,  'x');
        set_lexeme(case10 + 3, LT_ACTION,       0.0,  '^');
        set_lexeme(case10 + 4, LT_OPERAND,      2.0, '\0');


        Lexeme expected10[5];
        set_lexeme(expected10 + 0, LT_OPERAND,     -1.0, '\0');
        set_lexeme(expected10 + 1, LT_PLACEHOLDER,  0.0,  'x');
        set_lexeme(expected10 + 2, LT_OPERAND,      2.0, '\0');
        set_lexeme(expected10 + 3, LT_ACTION,       0.0,  '^');
        set_lexeme(expected10 + 4, LT_ACTION,       0.0,  '*');


        Lexeme actual10[5];
        const int expected_length10 = 5;
        int actual_length10 = -1;
        shunting_yard_function(case10, length10, actual10, &actual_length10);
        __compare_and_print_input_output_and_resolution(10, case10, length10, expected10, expected_length10, actual10, actual_length10, silent_on_success);
    }

    {
        // const char *case5 = " ( -1.0 * x ) ^ 2.0 ";
        // const char *expected5 = " -1.0 x * 2.0 ^";
        const int length11 = 7;
        Lexeme case11[7];
        set_lexeme(case11 + 0, LT_BRACE,        0.0,  '(');
        set_lexeme(case11 + 1, LT_OPERAND,     -1.0, '\0');
        set_lexeme(case11 + 2, LT_ACTION,       0.0,  '*');
        set_lexeme(case11 + 3, LT_PLACEHOLDER,  0.0,  'x');
        set_lexeme(case11 + 4, LT_BRACE,        0.0,  ')');
        set_lexeme(case11 + 5, LT_ACTION,       0.0,  'p');
        set_lexeme(case11 + 6, LT_OPERAND,      2.0, '\0');


        Lexeme expected11[5];
        set_lexeme(expected11 + 0, LT_OPERAND,     -1.0, '\0');
        set_lexeme(expected11 + 1, LT_PLACEHOLDER,  0.0,  'x');
        set_lexeme(expected11 + 2, LT_ACTION,       0.0,  '*');
        set_lexeme(expected11 + 3, LT_OPERAND,      2.0, '\0');
        set_lexeme(expected11 + 4, LT_ACTION,       0.0,  'p');


        Lexeme actual11[5];
        const int expected_length11 = 5;
        int actual_length11 = -1;
        shunting_yard_function(case11, length11, actual11, &actual_length11);
        __compare_and_print_input_output_and_resolution(11, case11, length11, expected11, expected_length11, actual11, actual_length11, silent_on_success);

    }

    // {
    //     // const char *case5 = " -1.00 * x ^ 2.00 ";
    //     // const char *expected5 = "x x x - *";
    //     const int length9 = 7;
    //     Lexeme case9[7];
    //     set_lexeme(case9 + 0, LT_PLACEHOLDER,         0.0,  'x');
    //     set_lexeme(case9 + 1, LT_ACTION,              0.0,  '*');
    //     set_lexeme(case9 + 2, LT_BRACE,               0.0,  '(');
    //     set_lexeme(case9 + 3, LT_PLACEHOLDER,         0.0,  'x');
    //     set_lexeme(case9 + 4, LT_ACTION,              0.0,  '-');
    //     set_lexeme(case9 + 5, LT_PLACEHOLDER,         0.0,  'x');
    //     set_lexeme(case9 + 6, LT_BRACE,               0.0,  ')');

    //     Lexeme expected9[5];
    //     set_lexeme(expected9 + 0, LT_PLACEHOLDER,         0.0,  'x');
    //     set_lexeme(expected9 + 1, LT_PLACEHOLDER,         0.0,  'x');
    //     set_lexeme(expected9 + 2, LT_PLACEHOLDER,         0.0,  'x');
    //     set_lexeme(expected9 + 3, LT_ACTION,              0.0,  '-');
    //     set_lexeme(expected9 + 4, LT_ACTION,              0.0,  '*');

    //     Lexeme actual9[5];
    //     const int expected_length9 = 5;
    //     int actual_length9 = -1;
    //     shunting_yard_function(case9, length9, actual9, &actual_length9);
    //     __compare_and_print_input_output_and_resolution(9, case9, length9, expected9, expected_length9, actual9, actual_length9, silent_on_success);

    // }
}
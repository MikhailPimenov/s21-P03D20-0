#include "calculate_reverse_polish_notation_test.h"

static void __compare_and_print_input_output_and_resolution(
    int case_number, 
    int status_expected, 
    int status_actual, 
    double expected, 
    double actual, 
    double epsilon, 
    const Lexeme *lexemes, 
    int length
) {
    printf("Test #%d:\t", case_number);
    if ((status_actual == status_expected) && are_double_equal(expected, actual, epsilon)) {
        printf("ok\n");
        return;
    }
    
    printf("FAILED\n");
    printf("Error code: %d\n", status_actual);
    printf("input:\n");
    print_lexeme_array(lexemes, length);
    printf("expected: %lf\n", expected);
    printf("actual  : %lf\n", actual);
}

void calculate_reverse_polish_notation_test(int (*calculate_reversed_polish_notation_function)(const Lexeme *const, int, double*)) {
    printf("\ncalculate_reverse_polish_notation_test():\n");
    
    static const double epsilon = 1e-12;
    // static const int E_SUCCESS = 0;
    int status = -1;
    
    Lexeme case1[5];
    const int length1 = 5;

    set_lexeme(case1 + 0, LT_OPERAND, 2.0, '\0');
    set_lexeme(case1 + 1, LT_OPERAND, 4.0, '\0');
    set_lexeme(case1 + 2, LT_ACTION,  0.0, '*' );
    set_lexeme(case1 + 3, LT_OPERAND, 8.0, '\0');
    set_lexeme(case1 + 4, LT_ACTION,  0.0, '+' );

    const double expected1 = 16.0;
    double actual1 = -14.87;
    status = calculate_reversed_polish_notation_function(case1, length1, &actual1);
    __compare_and_print_input_output_and_resolution(1, status, C_SUCCESS, expected1, actual1, epsilon, case1, length1);


    Lexeme case2[5];
    const int length2 = 5;

    set_lexeme(case2 + 0, LT_OPERAND, 2.0, '\0');
    set_lexeme(case2 + 1, LT_OPERAND, 4.0, '\0');
    set_lexeme(case2 + 2, LT_OPERAND, 8.0, '\0');
    set_lexeme(case2 + 3, LT_ACTION,  0.0, '+' );
    set_lexeme(case2 + 4, LT_ACTION,  0.0, '*' );

    const double expected2 = 24.0;
    double actual2 = -14.89;
    status = calculate_reversed_polish_notation_function(case2, length2, &actual2);
    __compare_and_print_input_output_and_resolution(2, status, C_SUCCESS, expected2, actual2, epsilon, case2, length2);


    Lexeme case3[5];
    const int length3 = 5;

    set_lexeme(case3 + 0, LT_OPERAND,  3.0, '\0');
    set_lexeme(case3 + 1, LT_OPERAND,  2.0, '\0');
    set_lexeme(case3 + 2, LT_ACTION,   0.0, '*' );
    set_lexeme(case3 + 3, LT_OPERAND, 11.0, '\0');
    set_lexeme(case3 + 4, LT_ACTION,   0.0, '-' );

    const double expected3 = -5.0;
    double actual3 = -13.88;
    status = calculate_reversed_polish_notation_function(case3, length3, &actual3);
    __compare_and_print_input_output_and_resolution(3, status, C_SUCCESS, expected3, actual3, epsilon, case3, length3);


    Lexeme case4[11];
    const int length4 = 11;

    set_lexeme(case4 +  0, LT_OPERAND,  2.0, '\0');
    set_lexeme(case4 +  1, LT_OPERAND,  5.0, '\0');
    set_lexeme(case4 +  2, LT_ACTION,   0.0, '*' );
    set_lexeme(case4 +  3, LT_OPERAND,  4.0, '\0');
    set_lexeme(case4 +  4, LT_ACTION,   0.0, '+' );
    set_lexeme(case4 +  5, LT_OPERAND,  3.0, '\0');
    set_lexeme(case4 +  6, LT_OPERAND,  2.0, '\0');
    set_lexeme(case4 +  7, LT_ACTION,   0.0, '*' );
    set_lexeme(case4 +  8, LT_OPERAND,  1.0, '\0');
    set_lexeme(case4 +  9, LT_ACTION,   0.0, '+' );
    set_lexeme(case4 + 10, LT_ACTION,   0.0, '/' );

    const double expected4 = 2.0;
    double actual4 = -15.88;
    status = calculate_reversed_polish_notation_function(case4, length4, &actual4);
    __compare_and_print_input_output_and_resolution(4, status, C_SUCCESS, expected4, actual4, epsilon, case4, length4);


    Lexeme case5[3];
    const int length5 = 3;

    set_lexeme(case5 +  0, LT_OPERAND,  88.0, '\0');
    set_lexeme(case5 +  1, LT_OPERAND,  -1.0, '\0');
    set_lexeme(case5 +  2, LT_ACTION,    0.0, '*' );

    const double expected5 = -88.0;
    double actual5 = -15.88;
    status = calculate_reversed_polish_notation_function(case5, length5, &actual5);
    __compare_and_print_input_output_and_resolution(5, status, C_SUCCESS, expected5, actual5, epsilon, case5, length5);


    const double pi_constant = acos(-1);
    Lexeme case6[2];
    const int length6 = 2;

    set_lexeme(case6 +  0, LT_OPERAND,  pi_constant, '\0');
    set_lexeme(case6 +  1, LT_ACTION,   0.0,         's' );

    const double expected6 = 0.0;
    double actual6 = -15.88;
    status = calculate_reversed_polish_notation_function(case6, length6, &actual6);
    __compare_and_print_input_output_and_resolution(6, status, C_SUCCESS, expected6, actual6, epsilon, case6, length6);


    Lexeme case7[2];
    const int length7 = 2;

    set_lexeme(case7 +  0, LT_OPERAND,  pi_constant / 6.0, '\0');
    set_lexeme(case7 +  1, LT_ACTION,   0.0,         's' );

    const double expected7 = 0.5;
    double actual7 = -15.88;
    status = calculate_reversed_polish_notation_function(case7, length7, &actual7);
    __compare_and_print_input_output_and_resolution(7, status, C_SUCCESS, expected7, actual7, epsilon, case7, length7);


    Lexeme case8[2];
    const int length8 = 2;

    set_lexeme(case8 +  0, LT_OPERAND,  -pi_constant / 6.0, '\0');
    set_lexeme(case8 +  1, LT_ACTION,   0.0,                's' );

    const double expected8 = -0.5;
    double actual8 = -15.88;
    status = calculate_reversed_polish_notation_function(case8, length8, &actual8);
    __compare_and_print_input_output_and_resolution(8, status, C_SUCCESS, expected8, actual8, epsilon, case8, length8);


    Lexeme case9[2];
    const int length9 = 2;

    set_lexeme(case9 +  0, LT_OPERAND,  0.0, '\0');
    set_lexeme(case9 +  1, LT_ACTION,   0.0, 'c' );

    const double expected9 = 1.0;
    double actual9 = -15.88;
    status = calculate_reversed_polish_notation_function(case9, length9, &actual9);
    __compare_and_print_input_output_and_resolution(9, status, C_SUCCESS, expected9, actual9, epsilon, case9, length9);


    Lexeme case10[2];
    const int length10 = 2;

    set_lexeme(case10 +  0, LT_OPERAND,  pi_constant, '\0');
    set_lexeme(case10 +  1, LT_ACTION,   0.0, 'c' );

    const double expected10 = -1.0;
    double actual10 = -15.88;
    status = calculate_reversed_polish_notation_function(case10, length10, &actual10);
    __compare_and_print_input_output_and_resolution(10, status, C_SUCCESS, expected10, actual10, epsilon, case10, length10);


    Lexeme case11[2];
    const int length11 = 2;

    set_lexeme(case11 +  0, LT_OPERAND,  pi_constant / 4.0, '\0');
    set_lexeme(case11 +  1, LT_ACTION,   0.0,               't' );

    const double expected11 = 1.0;
    double actual11 = -15.88;
    status = calculate_reversed_polish_notation_function(case11, length11, &actual11);
    __compare_and_print_input_output_and_resolution(11, status, C_SUCCESS, expected11, actual11, epsilon, case11, length11);


    Lexeme case12[2];
    const int length12 = 2;

    set_lexeme(case12 +  0, LT_OPERAND,  pi_constant / 4.0, '\0');
    set_lexeme(case12 +  1, LT_ACTION,   0.0,               'g' );

    const double expected12 = 1.0;
    double actual12 = -15.88;
    status = calculate_reversed_polish_notation_function(case12, length12, &actual12);
    __compare_and_print_input_output_and_resolution(12, status, C_SUCCESS, expected12, actual12, epsilon, case12, length12);


    Lexeme case13[2];
    const int length13 = 2;

    set_lexeme(case13 +  0, LT_OPERAND,  4.0, '\0');
    set_lexeme(case13 +  1, LT_ACTION,   0.0, 'r' );

    const double expected13 = 2.0;
    double actual13 = -15.88;
    status = calculate_reversed_polish_notation_function(case13, length13, &actual13);
    __compare_and_print_input_output_and_resolution(13, status, C_SUCCESS, expected13, actual13, epsilon, case13, length13);
    

    Lexeme case14[3];
    const int length14 = 3;

    set_lexeme(case14 +  0, LT_OPERAND_PLACEHOLDER,  0.0, '\0');
    set_lexeme(case14 +  1, LT_OPERAND,              1.0, '\0');
    set_lexeme(case14 +  2, LT_ACTION,               0.0, '+' );

    const double expected14 = 1.0;
    double actual14 = -15.88;
    status = calculate_reversed_polish_notation_function(case14, length14, &actual14);
    __compare_and_print_input_output_and_resolution(14, status, C_SUCCESS, expected14, actual14, epsilon, case14, length14);



    //  TODO: create test-cases for zero-division, invalid tg, invalid ctg, invalid ln, invalid sqrt, invalid power
}
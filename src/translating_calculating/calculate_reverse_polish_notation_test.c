#include "calculate_reverse_polish_notation_test.h"

void calculate_reverse_polish_notation_test(int (*calculate_reversed_polish_notation_function)(const Lexeme *const, int, double*)) {
    static const double epsilon = 1e-12;
    static const int E_SUCCESS = 0;
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
    printf("Test # 1: ");
    if ((status == E_SUCCESS) && are_double_equal(expected1, actual1, epsilon)) {
        printf("ok\n");
    } else {
        printf("FAILED\n");
        printf("Error code: %d\n", status);
        printf("input:\n");
        print_lexeme_array(case1, length1);
        printf("expected: %.48lf\n", expected1);
        printf("actual  : %.48lf\n", actual1);
    }

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
    printf("Test # 2: ");
    if ((status == E_SUCCESS) && are_double_equal(expected2, actual2, epsilon)) {
        printf("ok\n");
    } else {
        printf("FAILED\n");
        printf("Error code: %d\n", status);
        printf("input:\n");
        print_lexeme_array(case2, length2);
        printf("expected: %lf\n", expected2);
        printf("actual  : %lf\n", actual2);
    }

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
    printf("Test # 3: ");
    if ((status == E_SUCCESS) && are_double_equal(expected3, actual3, epsilon)) {
        printf("ok\n");
    } else {
        printf("FAILED\n");
        printf("Error code: %d\n", status);
        printf("input:\n");
        print_lexeme_array(case3, length3);
        printf("expected: %lf\n", expected3);
        printf("actual  : %lf\n", actual3);
    }


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
    printf("Test # 4: ");
    if ((status == E_SUCCESS) && are_double_equal(expected4, actual4, epsilon)) {
        printf("ok\n");
    } else {
        printf("FAILED\n");
        printf("Error code: %d\n", status);
        printf("input:\n");
        print_lexeme_array(case4, length4);
        printf("expected: %lf\n", expected4);
        printf("actual  : %lf\n", actual4);
    }


    Lexeme case5[2];
    const int length5 = 2;

    set_lexeme(case5 +  0, LT_OPERAND,  88.0, '\0');
    set_lexeme(case5 +  1, LT_ACTION,   0.0, 'm' );

    const double expected5 = -88.0;
    double actual5 = -15.88;
    status = calculate_reversed_polish_notation_function(case5, length5, &actual5);
    printf("Test # 5: ");
    if ((status == E_SUCCESS) && are_double_equal(expected5, actual5, epsilon)) {
        printf("ok\n");
    } else {
        printf("FAILED\n");
        printf("Error code: %d\n", status);
        printf("input:\n");
        print_lexeme_array(case5, length5);
        printf("expected: %lf\n", expected5);
        printf("actual  : %lf\n", actual5);
    }


    const double pi_constant = acos(-1);
    Lexeme case6[2];
    const int length6 = 2;

    set_lexeme(case6 +  0, LT_OPERAND,  pi_constant, '\0');
    set_lexeme(case6 +  1, LT_ACTION,   0.0,         's' );

    const double expected6 = 0.0;
    double actual6 = -15.88;
    status = calculate_reversed_polish_notation_function(case6, length6, &actual6);
    printf("Test # 6: ");
    if ((status == E_SUCCESS) && are_double_equal(expected6, actual6, epsilon)) {
        printf("ok\n");
    } else {
        printf("FAILED\n");
        printf("Error code: %d\n", status);
        printf("input:\n");
        print_lexeme_array(case6, length6);
        printf("expected: %lf\n", expected6);
        printf("actual  : %lf\n", actual6);
    }



    Lexeme case7[2];
    const int length7 = 2;

    set_lexeme(case7 +  0, LT_OPERAND,  pi_constant / 6.0, '\0');
    set_lexeme(case7 +  1, LT_ACTION,   0.0,         's' );

    const double expected7 = 0.5;
    double actual7 = -15.88;
    status = calculate_reversed_polish_notation_function(case7, length7, &actual7);
    printf("Test # 7: ");
    if ((status == E_SUCCESS) && are_double_equal(expected7, actual7, epsilon)) {
        printf("ok\n");
    } else {
        printf("FAILED\n");
        printf("Error code: %d\n", status);
        printf("input:\n");
        print_lexeme_array(case7, length7);
        printf("expected: %lf\n", expected7);
        printf("actual  : %lf\n", actual7);
    }


    Lexeme case8[2];
    const int length8 = 2;

    set_lexeme(case8 +  0, LT_OPERAND,  -pi_constant / 6.0, '\0');
    set_lexeme(case8 +  1, LT_ACTION,   0.0,                's' );

    const double expected8 = -0.5;
    double actual8 = -15.88;
    status = calculate_reversed_polish_notation_function(case8, length8, &actual8);
    printf("Test # 8: ");
    if ((status == E_SUCCESS) && are_double_equal(expected8, actual8, epsilon)) {
        printf("ok\n");
    } else {
        printf("FAILED\n");
        printf("Error code: %d\n", status);
        printf("input:\n");
        print_lexeme_array(case8, length8);
        printf("expected: %lf\n", expected8);
        printf("actual  : %lf\n", actual8);
    }


    Lexeme case9[2];
    const int length9 = 2;

    set_lexeme(case9 +  0, LT_OPERAND,  0.0, '\0');
    set_lexeme(case9 +  1, LT_ACTION,   0.0, 'c' );

    const double expected9 = 1.0;
    double actual9 = -15.88;
    status = calculate_reversed_polish_notation_function(case9, length9, &actual9);
    printf("Test # 9: ");
    if ((status == E_SUCCESS) && are_double_equal(expected9, actual9, epsilon)) {
        printf("ok\n");
    } else {
        printf("FAILED\n");
        printf("Error code: %d\n", status);
        printf("input:\n");
        print_lexeme_array(case9, length9);
        printf("expected: %lf\n", expected9);
        printf("actual  : %lf\n", actual9);
    }


    Lexeme case10[2];
    const int length10 = 2;

    set_lexeme(case10 +  0, LT_OPERAND,  pi_constant, '\0');
    set_lexeme(case10 +  1, LT_ACTION,   0.0, 'c' );

    const double expected10 = -1.0;
    double actual10 = -15.88;
    status = calculate_reversed_polish_notation_function(case10, length10, &actual10);
    printf("Test #10: ");
    if ((status == E_SUCCESS) && are_double_equal(expected10, actual10, epsilon)) {
        printf("ok\n");
    } else {
        printf("FAILED\n");
        printf("Error code: %d\n", status);
        printf("input:\n");
        print_lexeme_array(case10, length10);
        printf("expected: %lf\n", expected10);
        printf("actual  : %lf\n", actual10);
    }

    Lexeme case11[2];
    const int length11 = 2;

    set_lexeme(case11 +  0, LT_OPERAND,  pi_constant / 4.0, '\0');
    set_lexeme(case11 +  1, LT_ACTION,   0.0,               't' );

    const double expected11 = 1.0;
    double actual11 = -15.88;
    status = calculate_reversed_polish_notation_function(case11, length11, &actual11);
    printf("Test #11: ");
    if ((status == E_SUCCESS) && are_double_equal(expected11, actual11, epsilon)) {
        printf("ok\n");
    } else {
        printf("FAILED\n");
        printf("Error code: %d\n", status);
        printf("input:\n");
        print_lexeme_array(case11, length11);
        printf("expected: %lf\n", expected11);
        printf("actual  : %lf\n", actual11);
    }

    Lexeme case12[2];
    const int length12 = 2;

    set_lexeme(case12 +  0, LT_OPERAND,  pi_constant / 4.0, '\0');
    set_lexeme(case12 +  1, LT_ACTION,   0.0,               'g' );

    const double expected12 = 1.0;
    double actual12 = -15.88;
    status = calculate_reversed_polish_notation_function(case12, length12, &actual12);
    printf("Test #12: ");
    if ((status == E_SUCCESS) && are_double_equal(expected12, actual12, epsilon)) {
        printf("ok\n");
    } else {
        printf("FAILED\n");
        printf("Error code: %d\n", status);
        printf("input:\n");
        print_lexeme_array(case12, length12);
        printf("expected: %lf\n", expected12);
        printf("actual  : %lf\n", actual12);
    }
    // compare_actual_and_expected_and_print_resolution(12, status, E_SUCCESS, expected12, actual12);
    //  TODO: implement fucntion "compare_actual_and_expected_and_print_resolution"
    //  TODO: create test-cases for zero-division, invalid tg, invalid ctg, invalid ln, invalid sqrt, invalid power
}
#include "parse_to_lexemes_test.h"

static void __compare_and_print_input_output_and_resolution(
    int case_number, 
    const char *input,
    int input_length,
    const Lexeme *const expected,
    int expected_length,
    const Lexeme *const actual,
    int actual_length,
    int silent_on_success 
) {
    printf("Test #%d:\t", case_number);
    if ((actual_length == expected_length) && are_lexeme_arrays_equal(actual, expected, actual_length)) {
        printf("ok\n");
        if (silent_on_success)
            return;
    } else {
        printf("FAILED\n");
    }

    printf("input:\n");
    printf("%s\n", input);
    printf("input length = %d\n", input_length);
    printf("expected:\n");
    print_lexeme_array(expected, expected_length);
    printf("expected length = %d\n", expected_length);
    printf("actual  :\n");
    print_lexeme_array(actual, actual_length);
    printf("actual length   = %d\n", actual_length);
    printf("\n");
}

void parse_to_lexemes_test(void (*parse_to_lexemes_allocate_function)(const char*, int, Lexeme **, int *)) {
    printf("\nparse_to_lexemes_test():\n");
    int silent_on_success = 1;

    {
        const char *case1 = "2+1";
        const int length_without_terminator_1 = 3;

        Lexeme expected1[3];
        const int expected_length1 = 3;

        set_lexeme(expected1 + 0, LT_OPERAND, 2.0, '\0');
        set_lexeme(expected1 + 1, LT_ACTION,  0.0, '+' );
        set_lexeme(expected1 + 2, LT_OPERAND, 1.0, '\0');

        Lexeme *actual1 = NULL;
        int actual_length1 = -1;

        parse_to_lexemes_allocate_function(case1, length_without_terminator_1, &actual1, &actual_length1);
        __compare_and_print_input_output_and_resolution(
            1, 
            case1, 
            length_without_terminator_1, 
            expected1, 
            expected_length1, 
            actual1, 
            actual_length1,
            silent_on_success); 

        if (actual1)
            free(actual1);
    }

    {
        const char *case2 = "59+7/2";
        const int length_without_terminator_2 = 6;
        
        Lexeme expected2[5];
        const int expected_length2 = 5;

        set_lexeme(expected2 + 0, LT_OPERAND, 59.0, '\0');
        set_lexeme(expected2 + 1, LT_ACTION,  0.0,  '+' );
        set_lexeme(expected2 + 2, LT_OPERAND, 7.0,  '\0');
        set_lexeme(expected2 + 3, LT_ACTION,  0.0,  '/' );
        set_lexeme(expected2 + 4, LT_OPERAND, 2.0,  '\0');

        Lexeme *actual2 = NULL;
        int actual_length2 = -1;
        
        parse_to_lexemes_allocate_function(case2, length_without_terminator_2, &actual2, &actual_length2);
        __compare_and_print_input_output_and_resolution(
            2, 
            case2, 
            length_without_terminator_2, 
            expected2, 
            expected_length2, 
            actual2, 
            actual_length2,
            silent_on_success); 

        if (actual2)
            free(actual2);
    }

    {
        const char *case3 = "(5+7)/2";
        const int length_without_terminator_3 = 7;
        
        Lexeme expected3[7];
        const int expected_length3 = 7;

        set_lexeme(expected3 + 0, LT_BRACE,   0.0,  '(' );
        set_lexeme(expected3 + 1, LT_OPERAND, 5.0, '\0');
        set_lexeme(expected3 + 2, LT_ACTION,  0.0,  '+' );
        set_lexeme(expected3 + 3, LT_OPERAND, 7.0,  '\0');
        set_lexeme(expected3 + 4, LT_BRACE,   0.0,  ')' );
        set_lexeme(expected3 + 5, LT_ACTION,  0.0,  '/' );
        set_lexeme(expected3 + 6, LT_OPERAND, 2.0,  '\0');

        Lexeme *actual3 = NULL;
        int actual_length3 = -1;
        
        parse_to_lexemes_allocate_function(case3, length_without_terminator_3, &actual3, &actual_length3);
        __compare_and_print_input_output_and_resolution(
            3, 
            case3, 
            length_without_terminator_3, 
            expected3, 
            expected_length3, 
            actual3, 
            actual_length3,
            silent_on_success);

        if (actual3)
            free(actual3);
    }

    {
        const char *case4 = "(5+7)/2";
        const int length_without_terminator_4 = 7;
        
        Lexeme expected4[7];
        const int expected_length4 = 7;

        set_lexeme(expected4 + 0, LT_BRACE,   0.0,  '(' );
        set_lexeme(expected4 + 1, LT_OPERAND, 5.0, '\0');
        set_lexeme(expected4 + 2, LT_ACTION,  0.0,  '+' );
        set_lexeme(expected4 + 3, LT_OPERAND, 7.0,  '\0');
        set_lexeme(expected4 + 4, LT_BRACE,   0.0,  ')' );
        set_lexeme(expected4 + 5, LT_ACTION,  0.0,  '/' );
        set_lexeme(expected4 + 6, LT_OPERAND, 2.0,  '\0');

        Lexeme *actual4 = NULL;
        int actual_length4 = -1;
        
        parse_to_lexemes_allocate_function(case4, length_without_terminator_4, &actual4, &actual_length4);
        __compare_and_print_input_output_and_resolution(
            4, 
            case4, 
            length_without_terminator_4, 
            expected4, 
            expected_length4, 
            actual4, 
            actual_length4,
            silent_on_success);
        if (actual4)
            free(actual4);
    }

    {
        const char *case5 = "517*(20-39)";
        const int length_without_terminator_5 = 11;
        
        Lexeme expected5[9];
        const int expected_length5 = 9;

        set_lexeme(expected5 + 0, LT_OPERAND, 517.0,  '\0');
        set_lexeme(expected5 + 1, LT_ACTION,    0.0,  '*' );
        set_lexeme(expected5 + 2, LT_BRACE,     0.0,  '(' );
        set_lexeme(expected5 + 3, LT_OPERAND,  20.0,  '\0');
        set_lexeme(expected5 + 4, LT_ACTION,    0.0,  '+' );
        set_lexeme(expected5 + 5, LT_OPERAND,  -1.0,  '\0');
        set_lexeme(expected5 + 6, LT_ACTION,    0.0,  '*' );
        set_lexeme(expected5 + 7, LT_OPERAND,  39.0,  '\0');
        set_lexeme(expected5 + 8, LT_BRACE,     0.0,  ')' );

        Lexeme *actual5 = NULL;
        int actual_length5 = -1;
        
        parse_to_lexemes_allocate_function(case5, length_without_terminator_5, &actual5, &actual_length5);
        __compare_and_print_input_output_and_resolution(
            5, 
            case5, 
            length_without_terminator_5, 
            expected5, 
            expected_length5, 
            actual5, 
            actual_length5,
            silent_on_success);
        if (actual5)
            free(actual5);
    }

    {
        const char *case6 = "sin(2)";
        const int length_without_terminator_6 = 6;
        
        Lexeme expected6[4];
        const int expected_length6 = 4;

        set_lexeme(expected6 + 0, LT_ACTION,  0.0,  's');
        set_lexeme(expected6 + 1, LT_BRACE,   0.0,   '(');
        set_lexeme(expected6 + 2, LT_OPERAND, 2.0, '\0');
        set_lexeme(expected6 + 3, LT_BRACE,   0.0,   ')');

        Lexeme *actual6 = NULL;
        int actual_length6 = -1;
        
        parse_to_lexemes_allocate_function(case6, length_without_terminator_6, &actual6, &actual_length6);
        __compare_and_print_input_output_and_resolution(
            6, 
            case6, 
            length_without_terminator_6, 
            expected6, 
            expected_length6, 
            actual6, 
            actual_length6,
            silent_on_success);
        
        if (actual6)
            free(actual6);
    }

    {
        const char *case7 = "cos(14)/sqrt(88)";
        const int length_without_terminator_7 = 16;
        
        Lexeme expected7[9];
        const int expected_length7 = 9;

        set_lexeme(expected7 + 0, LT_ACTION,  0.0,   'c');
        set_lexeme(expected7 + 1, LT_BRACE,   0.0,   '(');
        set_lexeme(expected7 + 2, LT_OPERAND, 14.0, '\0');
        set_lexeme(expected7 + 3, LT_BRACE,   0.0,   ')');
        set_lexeme(expected7 + 4, LT_ACTION,  0.0,   '/');
        set_lexeme(expected7 + 5, LT_ACTION,  0.0,   'r');
        set_lexeme(expected7 + 6, LT_BRACE,   0.0,   '(');
        set_lexeme(expected7 + 7, LT_OPERAND, 88.0, '\0');
        set_lexeme(expected7 + 8, LT_BRACE,   0.0,   ')');

        Lexeme *actual7 = NULL;
        int actual_length7 = -1;

        parse_to_lexemes_allocate_function(case7, length_without_terminator_7, &actual7, &actual_length7);
        __compare_and_print_input_output_and_resolution(
            7, 
            case7, 
            length_without_terminator_7, 
            expected7, 
            expected_length7, 
            actual7, 
            actual_length7,
            silent_on_success);

        if (actual7)
            free(actual7);
    }

    {
        const char *case8 = "(sin(2+2^3)+tg(1))+ctg(0.5)+cos(14/88+sqrt(9)*ln(88))*69";
        const int length_without_terminator_8 = 56;
        
        Lexeme expected8[39];
        const int expected_length8 = 39;

        set_lexeme(expected8 + 0,  LT_BRACE,   0.0,   '(');
    
        set_lexeme(expected8 + 1,  LT_ACTION,  0.0,   's');
        set_lexeme(expected8 + 2,  LT_BRACE,   0.0,   '(');
        set_lexeme(expected8 + 3,  LT_OPERAND, 2.0,  '\0');
        set_lexeme(expected8 + 4,  LT_ACTION,  0.0,   '+');
        set_lexeme(expected8 + 5,  LT_OPERAND, 2.0,  '\0');
        set_lexeme(expected8 + 6,  LT_ACTION,  0.0,   '^');
        set_lexeme(expected8 + 7,  LT_OPERAND, 3.0,  '\0');
        set_lexeme(expected8 + 8,  LT_BRACE,   0.0,   ')');
    
        set_lexeme(expected8 + 9,  LT_ACTION,  0.0,   '+');

        set_lexeme(expected8 + 10, LT_ACTION,  0.0,   't');
        set_lexeme(expected8 + 11, LT_BRACE,   0.0,   '(');
        set_lexeme(expected8 + 12, LT_OPERAND, 1.0,  '\0');
        set_lexeme(expected8 + 13, LT_BRACE,   0.0,   ')');

        set_lexeme(expected8 + 14, LT_BRACE,   0.0,   ')');


        set_lexeme(expected8 + 15, LT_ACTION,  0.0,   '+');


        set_lexeme(expected8 + 16, LT_ACTION,  0.0,   'g');
        set_lexeme(expected8 + 17, LT_BRACE,   0.0,   '(');
        set_lexeme(expected8 + 18, LT_OPERAND, 0.5,  '\0');
        set_lexeme(expected8 + 19, LT_BRACE,   0.0,   ')');

        set_lexeme(expected8 + 20, LT_ACTION,  0.0,   '+');


        set_lexeme(expected8 + 21, LT_ACTION,  0.0,   'c');
        set_lexeme(expected8 + 22, LT_BRACE,   0.0,   '(');
        set_lexeme(expected8 + 23, LT_OPERAND, 14.0, '\0');
        set_lexeme(expected8 + 24, LT_ACTION,  0.0,   '/');
        set_lexeme(expected8 + 25, LT_OPERAND, 88.0, '\0');

        set_lexeme(expected8 + 26, LT_ACTION,  0.0,   '+');

        set_lexeme(expected8 + 27, LT_ACTION,  0.0,   'r');
        set_lexeme(expected8 + 28, LT_BRACE,   0.0,   '(');
        set_lexeme(expected8 + 29, LT_OPERAND, 9.0,  '\0');
        set_lexeme(expected8 + 30, LT_BRACE,   0.0,   ')');
        set_lexeme(expected8 + 31, LT_ACTION,  0.0,   '*');

        set_lexeme(expected8 + 32, LT_ACTION,  0.0,   'l');
        set_lexeme(expected8 + 33, LT_BRACE,   0.0,   '(');
        set_lexeme(expected8 + 34, LT_OPERAND, 88.0, '\0');
        set_lexeme(expected8 + 35, LT_BRACE,   0.0,   ')');
        set_lexeme(expected8 + 36, LT_BRACE,   0.0,   ')');

        set_lexeme(expected8 + 37, LT_ACTION,  0.0,   '*');
        set_lexeme(expected8 + 38, LT_OPERAND, 69.0, '\0');

        Lexeme *actual8 = NULL;
        int actual_length8 = -1;
        
        parse_to_lexemes_allocate_function(case8, length_without_terminator_8, &actual8, &actual_length8);
        __compare_and_print_input_output_and_resolution(
            8, 
            case8, 
            length_without_terminator_8, 
            expected8, 
            expected_length8, 
            actual8, 
            actual_length8,
            silent_on_success);
        
        if (actual8)
            free(actual8);
    }


    {
        const char *case9 = "cos(14)/sqrt(x)";
        const int length_without_terminator_9 = 15;
        
        Lexeme expected9[9];
        const int expected_length9 = 9;

        set_lexeme(expected9 + 0, LT_ACTION,              0.0,   'c');
        set_lexeme(expected9 + 1, LT_BRACE,               0.0,   '(');
        set_lexeme(expected9 + 2, LT_OPERAND,             14.0, '\0');
        set_lexeme(expected9 + 3, LT_BRACE,               0.0,   ')');
        set_lexeme(expected9 + 4, LT_ACTION,              0.0,   '/');
        set_lexeme(expected9 + 5, LT_ACTION,              0.0,   'r');
        set_lexeme(expected9 + 6, LT_BRACE,               0.0,   '(');
        set_lexeme(expected9 + 7, LT_PLACEHOLDER,         0.0,   'x');
        set_lexeme(expected9 + 8, LT_BRACE,               0.0,   ')');

        Lexeme *actual9 = NULL;
        int actual_length9 = -1;
        
        parse_to_lexemes_allocate_function(case9, length_without_terminator_9, &actual9, &actual_length9);
        __compare_and_print_input_output_and_resolution(
            9, 
            case9, 
            length_without_terminator_9, 
            expected9, 
            expected_length9, 
            actual9, 
            actual_length9,
            silent_on_success);

        if (actual9)
            free(actual9);
    }

    {
        const char *case10 = "(sin(2+2^3)+tg(1))+ctg(0.5)+cos(14/88-sqrt(9)*ln(88))*69";
        const int length_without_terminator_10 = 56;
        
        Lexeme expected10[41];
        const int expected_length10 = 41;

        set_lexeme(expected10 + 0,  LT_BRACE,   0.0,   '(');
    
        set_lexeme(expected10 + 1,  LT_ACTION,  0.0,   's');
        set_lexeme(expected10 + 2,  LT_BRACE,   0.0,   '(');
        set_lexeme(expected10 + 3,  LT_OPERAND, 2.0,  '\0');
        set_lexeme(expected10 + 4,  LT_ACTION,  0.0,   '+');
        set_lexeme(expected10 + 5,  LT_OPERAND, 2.0,  '\0');
        set_lexeme(expected10 + 6,  LT_ACTION,  0.0,   '^');
        set_lexeme(expected10 + 7,  LT_OPERAND, 3.0,  '\0');
        set_lexeme(expected10 + 8,  LT_BRACE,   0.0,   ')');
    
        set_lexeme(expected10 + 9,  LT_ACTION,  0.0,   '+');

        set_lexeme(expected10 + 10, LT_ACTION,  0.0,   't');
        set_lexeme(expected10 + 11, LT_BRACE,   0.0,   '(');
        set_lexeme(expected10 + 12, LT_OPERAND, 1.0,  '\0');
        set_lexeme(expected10 + 13, LT_BRACE,   0.0,   ')');

        set_lexeme(expected10 + 14, LT_BRACE,   0.0,   ')');


        set_lexeme(expected10 + 15, LT_ACTION,  0.0,   '+');


        set_lexeme(expected10 + 16, LT_ACTION,  0.0,   'g');
        set_lexeme(expected10 + 17, LT_BRACE,   0.0,   '(');
        set_lexeme(expected10 + 18, LT_OPERAND, 0.5,  '\0');
        set_lexeme(expected10 + 19, LT_BRACE,   0.0,   ')');

        set_lexeme(expected10 + 20, LT_ACTION,  0.0,   '+');


        set_lexeme(expected10 + 21, LT_ACTION,  0.0,   'c');
        set_lexeme(expected10 + 22, LT_BRACE,   0.0,   '(');
        set_lexeme(expected10 + 23, LT_OPERAND, 14.0, '\0');
        set_lexeme(expected10 + 24, LT_ACTION,  0.0,   '/');
        set_lexeme(expected10 + 25, LT_OPERAND, 88.0, '\0');

        set_lexeme(expected10 + 26, LT_ACTION,  0.0,   '+');
        set_lexeme(expected10 + 27, LT_OPERAND, -1.0, '\0');
        set_lexeme(expected10 + 28, LT_ACTION,  0.0,   '*');

        set_lexeme(expected10 + 29, LT_ACTION,  0.0,   'r');
        set_lexeme(expected10 + 30, LT_BRACE,   0.0,   '(');
        set_lexeme(expected10 + 31, LT_OPERAND, 9.0,  '\0');
        set_lexeme(expected10 + 32, LT_BRACE,   0.0,   ')');
        set_lexeme(expected10 + 33, LT_ACTION,  0.0,   '*');

        set_lexeme(expected10 + 34, LT_ACTION,  0.0,   'l');
        set_lexeme(expected10 + 35, LT_BRACE,   0.0,   '(');
        set_lexeme(expected10 + 36, LT_OPERAND, 88.0, '\0');
        set_lexeme(expected10 + 37, LT_BRACE,   0.0,   ')');
        set_lexeme(expected10 + 38, LT_BRACE,   0.0,   ')');

        set_lexeme(expected10 + 39, LT_ACTION,  0.0,   '*');
        set_lexeme(expected10 + 40, LT_OPERAND, 69.0, '\0');

        Lexeme *actual10 = NULL;
        int actual_length10 = -1;
        
        parse_to_lexemes_allocate_function(case10, length_without_terminator_10, &actual10, &actual_length10);
        __compare_and_print_input_output_and_resolution(
            10, 
            case10, 
            length_without_terminator_10, 
            expected10, 
            expected_length10, 
            actual10, 
            actual_length10,
            silent_on_success);

        if (actual10)
            free(actual10);
    }

    {
        const char *case11 = "-14";
        const int length_without_terminator_11 = 3;

        Lexeme expected11[3];
        const int expected_length11 = 3;

        set_lexeme(expected11 + 0, LT_OPERAND, -1.0, '\0');
        set_lexeme(expected11 + 1, LT_ACTION,   0.0,  '*');
        set_lexeme(expected11 + 2, LT_OPERAND, 14.0, '\0');

        Lexeme *actual11 = NULL;
        int actual_length11 = -1;

        parse_to_lexemes_allocate_function(case11, length_without_terminator_11, &actual11, &actual_length11);
        __compare_and_print_input_output_and_resolution(
            11, 
            case11, 
            length_without_terminator_11, 
            expected11, 
            expected_length11, 
            actual11, 
            actual_length11,
            silent_on_success); 

        if (actual11)
            free(actual11);
    }

    {
        const char *case12 = "0-14";
        const int length_without_terminator_12 = 4;

        Lexeme expected12[5];
        const int expected_length12 = 5;

        set_lexeme(expected12 + 0, LT_OPERAND,  0.0, '\0');
        set_lexeme(expected12 + 1, LT_ACTION,   0.0,  '+');
        set_lexeme(expected12 + 2, LT_OPERAND, -1.0, '\0');
        set_lexeme(expected12 + 3, LT_ACTION,   0.0,  '*');
        set_lexeme(expected12 + 4, LT_OPERAND, 14.0, '\0');

        Lexeme *actual12 = NULL;
        int actual_length12 = -1;

        parse_to_lexemes_allocate_function(case12, length_without_terminator_12, &actual12, &actual_length12);
        __compare_and_print_input_output_and_resolution(
            12, 
            case12, 
            length_without_terminator_12, 
            expected12, 
            expected_length12, 
            actual12, 
            actual_length12,
            silent_on_success); 

        if (actual12)
            free(actual12);
    }
    {
        const char *case13 = "-(14)";
        const int length_without_terminator_13 = 5;

        Lexeme expected13[5];
        const int expected_length13 = 5;

        set_lexeme(expected13 + 0, LT_OPERAND, -1.0, '\0');
        set_lexeme(expected13 + 1, LT_ACTION,   0.0,  '*');
        set_lexeme(expected13 + 2, LT_BRACE,    0.0,  '(');
        set_lexeme(expected13 + 3, LT_OPERAND, 14.0, '\0');
        set_lexeme(expected13 + 4, LT_BRACE,    0.0,  ')');

        Lexeme *actual13 = NULL;
        int actual_length13 = -1;

        parse_to_lexemes_allocate_function(case13, length_without_terminator_13, &actual13, &actual_length13);
        __compare_and_print_input_output_and_resolution(
            13,
            case13, 
            length_without_terminator_13, 
            expected13, 
            expected_length13, 
            actual13, 
            actual_length13,
            silent_on_success); 

        if (actual13)
            free(actual13);
    }

    {
        const char *case14 = "-(14+sin(x)*88)";
        const int length_without_terminator_14 = 15;

        Lexeme expected14[12];
        const int expected_length14 = 12;

        set_lexeme(expected14 +  0, LT_OPERAND,    -1.0, '\0');
        set_lexeme(expected14 +  1, LT_ACTION,      0.0,  '*');
        set_lexeme(expected14 +  2, LT_BRACE,       0.0,  '(');
        set_lexeme(expected14 +  3, LT_OPERAND,    14.0, '\0');
        set_lexeme(expected14 +  4, LT_ACTION,      0.0,  '+');
        set_lexeme(expected14 +  5, LT_ACTION,      0.0,  's');
        set_lexeme(expected14 +  6, LT_BRACE,       0.0,  '(');
        set_lexeme(expected14 +  7, LT_PLACEHOLDER, 0.0,  'x');
        set_lexeme(expected14 +  8, LT_BRACE,       0.0,  ')');
        set_lexeme(expected14 +  9, LT_ACTION,      0.0,  '*');
        set_lexeme(expected14 + 10, LT_OPERAND,    88.0, '\0');
        set_lexeme(expected14 + 11, LT_BRACE,       0.0,  ')');

        Lexeme *actual14 = NULL;
        int actual_length14 = -1;

        parse_to_lexemes_allocate_function(case14, length_without_terminator_14, &actual14, &actual_length14);
        __compare_and_print_input_output_and_resolution(
            14,
            case14, 
            length_without_terminator_14, 
            expected14, 
            expected_length14, 
            actual14, 
            actual_length14,
            silent_on_success); 

        if (actual14)
            free(actual14);
    }



    {
        const char *case15 = "+14";
        const int length_without_terminator_15 = 3;

        Lexeme expected15[1];
        const int expected_length15 = 1;

        set_lexeme(expected15 + 0, LT_OPERAND, 14.0, '\0');

        Lexeme *actual15 = NULL;
        int actual_length15 = -1;

        parse_to_lexemes_allocate_function(case15, length_without_terminator_15, &actual15, &actual_length15);
        __compare_and_print_input_output_and_resolution(
            15, 
            case15, 
            length_without_terminator_15, 
            expected15, 
            expected_length15, 
            actual15, 
            actual_length15,
            silent_on_success); 

        if (actual15)
            free(actual15);
    }

    {
        const char *case16 = "(-(-((x+1))))";  // -> '(' , -1.0, '*', '(', -1.0, '*', '(', '(', 'x', '+', '1', ')', ')', ')', ')'
        const int length_without_terminator_16 = 13;

        Lexeme expected16[15];
        const int expected_length16 = 15;

        set_lexeme(expected16 +  0, LT_BRACE,       0.0,  '(');
        set_lexeme(expected16 +  1, LT_OPERAND,    -1.0, '\0');
        set_lexeme(expected16 +  2, LT_ACTION,      0.0,  '*');
        set_lexeme(expected16 +  3, LT_BRACE,       0.0,  '(');
        set_lexeme(expected16 +  4, LT_OPERAND,    -1.0, '\0');
        set_lexeme(expected16 +  5, LT_ACTION,      0.0,  '*');
        set_lexeme(expected16 +  6, LT_BRACE,       0.0,  '(');
        set_lexeme(expected16 +  7, LT_BRACE,       0.0,  '(');
        set_lexeme(expected16 +  8, LT_PLACEHOLDER, 0.0,  'x');
        set_lexeme(expected16 +  9, LT_ACTION,      0.0,  '+');
        set_lexeme(expected16 + 10, LT_OPERAND,     1.0, '\0');
        set_lexeme(expected16 + 11, LT_BRACE,       0.0,  ')');
        set_lexeme(expected16 + 12, LT_BRACE,       0.0,  ')');
        set_lexeme(expected16 + 13, LT_BRACE,       0.0,  ')');
        set_lexeme(expected16 + 14, LT_BRACE,       0.0,  ')');

        Lexeme *actual16 = NULL;
        int actual_length16 = -1;

        parse_to_lexemes_allocate_function(case16, length_without_terminator_16, &actual16, &actual_length16);
        __compare_and_print_input_output_and_resolution(
            16, 
            case16, 
            length_without_terminator_16, 
            expected16, 
            expected_length16, 
            actual16, 
            actual_length16,
            silent_on_success); 

        if (actual16)
            free(actual16);
    }

    {
        const char *case17 = "+(-(-(+(x+1))))";  // -> '(' , -1.0, '*', '(', -1.0, '*', '(', '(', 'x', '+', '1', ')', ')', ')', ')'
        const int length_without_terminator_17 = 15;

        Lexeme expected17[15];
        const int expected_length17 = 15;

        set_lexeme(expected17 +  0, LT_BRACE,       0.0,  '(');
        set_lexeme(expected17 +  1, LT_OPERAND,    -1.0, '\0');
        set_lexeme(expected17 +  2, LT_ACTION,      0.0,  '*');
        set_lexeme(expected17 +  3, LT_BRACE,       0.0,  '(');
        set_lexeme(expected17 +  4, LT_OPERAND,    -1.0, '\0');
        set_lexeme(expected17 +  5, LT_ACTION,      0.0,  '*');
        set_lexeme(expected17 +  6, LT_BRACE,       0.0,  '(');
        set_lexeme(expected17 +  7, LT_BRACE,       0.0,  '(');
        set_lexeme(expected17 +  8, LT_PLACEHOLDER, 0.0,  'x');
        set_lexeme(expected17 +  9, LT_ACTION,      0.0,  '+');
        set_lexeme(expected17 + 10, LT_OPERAND,     1.0, '\0');
        set_lexeme(expected17 + 11, LT_BRACE,       0.0,  ')');
        set_lexeme(expected17 + 12, LT_BRACE,       0.0,  ')');
        set_lexeme(expected17 + 13, LT_BRACE,       0.0,  ')');
        set_lexeme(expected17 + 14, LT_BRACE,       0.0,  ')');

        Lexeme *actual17 = NULL;
        int actual_length17 = -1;

        parse_to_lexemes_allocate_function(case17, length_without_terminator_17, &actual17, &actual_length17);
        __compare_and_print_input_output_and_resolution(
            17, 
            case17, 
            length_without_terminator_17, 
            expected17, 
            expected_length17, 
            actual17, 
            actual_length17,
            silent_on_success); 

        if (actual17)
            free(actual17);
    }



    {
        const char *case18 = "+(-(((-((((((+(x+1))))))))))+1)";  
        // -> '(' , -1.0, '*', '(', '(', '(', -1.0, '*', 
        // '(', '(', '(', '(', '(', '(', '(', 'x', '+', 
        // '1', ')', ')', ')', ')', ')', ')', ')', ')', ')', ')', '+', 1.0, ')' 

        const int length_without_terminator_18 = 31;

        Lexeme expected18[31];
        const int expected_length18 = 31;

        set_lexeme(expected18 +  0, LT_BRACE,       0.0,  '(');
        set_lexeme(expected18 +  1, LT_OPERAND,    -1.0, '\0');
        set_lexeme(expected18 +  2, LT_ACTION,      0.0,  '*');
        set_lexeme(expected18 +  3, LT_BRACE,       0.0,  '(');
        set_lexeme(expected18 +  4, LT_BRACE,       0.0,  '(');
        set_lexeme(expected18 +  5, LT_BRACE,       0.0,  '(');
        set_lexeme(expected18 +  6, LT_OPERAND,    -1.0, '\0');
        set_lexeme(expected18 +  7, LT_ACTION,      0.0,  '*');
        set_lexeme(expected18 +  8, LT_BRACE,       0.0,  '(');
        set_lexeme(expected18 +  9, LT_BRACE,       0.0,  '(');
        set_lexeme(expected18 + 10, LT_BRACE,       0.0,  '(');
        set_lexeme(expected18 + 11, LT_BRACE,       0.0,  '(');
        set_lexeme(expected18 + 12, LT_BRACE,       0.0,  '(');
        set_lexeme(expected18 + 13, LT_BRACE,       0.0,  '(');
        set_lexeme(expected18 + 14, LT_BRACE,       0.0,  '(');
        set_lexeme(expected18 + 15, LT_PLACEHOLDER, 0.0,  'x');
        set_lexeme(expected18 + 16, LT_ACTION,      0.0,  '+');
        set_lexeme(expected18 + 17, LT_OPERAND,     1.0, '\0');
        set_lexeme(expected18 + 18, LT_BRACE,       0.0,  ')');
        set_lexeme(expected18 + 19, LT_BRACE,       0.0,  ')');
        set_lexeme(expected18 + 20, LT_BRACE,       0.0,  ')');
        set_lexeme(expected18 + 21, LT_BRACE,       0.0,  ')');
        set_lexeme(expected18 + 22, LT_BRACE,       0.0,  ')');
        set_lexeme(expected18 + 23, LT_BRACE,       0.0,  ')');
        set_lexeme(expected18 + 24, LT_BRACE,       0.0,  ')');
        set_lexeme(expected18 + 25, LT_BRACE,       0.0,  ')');
        set_lexeme(expected18 + 26, LT_BRACE,       0.0,  ')');
        set_lexeme(expected18 + 27, LT_BRACE,       0.0,  ')');
        set_lexeme(expected18 + 28, LT_ACTION,      0.0,  '+');
        set_lexeme(expected18 + 29, LT_OPERAND,     1.0, '\0');
        set_lexeme(expected18 + 30, LT_BRACE,       0.0,  ')');

        Lexeme *actual18 = NULL;
        int actual_length18 = -1;

        parse_to_lexemes_allocate_function(case18, length_without_terminator_18, &actual18, &actual_length18);
        __compare_and_print_input_output_and_resolution(
            18, 
            case18, 
            length_without_terminator_18, 
            expected18, 
            expected_length18, 
            actual18, 
            actual_length18,
            silent_on_success); 

        if (actual18)
            free(actual18);
    }
}



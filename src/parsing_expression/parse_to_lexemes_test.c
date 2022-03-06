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
    printf("actual  :\n");
    print_lexeme_array(actual, actual_length);
    printf("\n");
}

void parse_to_lexemes_test(void (*parse_to_lexemes_allocate_function)(const char*, int, Lexeme **, int *)) {
    printf("parse_to_lexemes_test():\n");
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

        printf("pointer to pointer = %p\n", &actual1);
        printf("pointer = %p\n", actual1);

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

        // if (actual1)
            // free(actual1);
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
    }

    {
        const char *case3 = "(5+7)/2";
        const int length_without_terminator_3 = 7;
        
        Lexeme expected3[7];
        const int expected_length3 = 7;

        set_lexeme(expected3 + 0, LT_ACTION,  0.0,  '(' );
        set_lexeme(expected3 + 1, LT_OPERAND, 5.0, '\0');
        set_lexeme(expected3 + 2, LT_ACTION,  0.0,  '+' );
        set_lexeme(expected3 + 3, LT_OPERAND, 7.0,  '\0');
        set_lexeme(expected3 + 4, LT_ACTION,  0.0,  ')' );
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
    }

    {
        const char *case4 = "(5+7)/2";
        const int length_without_terminator_4 = 7;
        
        Lexeme expected4[7];
        const int expected_length4 = 7;

        set_lexeme(expected4 + 0, LT_ACTION,  0.0,  '(' );
        set_lexeme(expected4 + 1, LT_OPERAND, 5.0, '\0');
        set_lexeme(expected4 + 2, LT_ACTION,  0.0,  '+' );
        set_lexeme(expected4 + 3, LT_OPERAND, 7.0,  '\0');
        set_lexeme(expected4 + 4, LT_ACTION,  0.0,  ')' );
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
    }

    {
        const char *case5 = "517*(20-39)";
        const int length_without_terminator_5 = 11;
        
        Lexeme expected5[9];
        const int expected_length5 = 9;

        set_lexeme(expected5 + 0, LT_OPERAND, 517.0, '\0');
        set_lexeme(expected5 + 1, LT_ACTION,  0.0,   '*' );
        set_lexeme(expected5 + 2, LT_ACTION,  0.0,   '(' );
        set_lexeme(expected5 + 3, LT_OPERAND, 20.0,  '\0');
        set_lexeme(expected5 + 4, LT_ACTION,  0.0,   '+' );
        set_lexeme(expected5 + 5, LT_OPERAND, -1.0,  '\0');
        set_lexeme(expected5 + 6, LT_ACTION,  0.0,   '*' );
        set_lexeme(expected5 + 7, LT_OPERAND, 39.0,  '\0');
        set_lexeme(expected5 + 8, LT_ACTION,  0.0,   ')' );

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
    }

    {
        const char *case6 = "sin(2)";
        const int length_without_terminator_6 = 6;
        
        Lexeme expected6[2];
        const int expected_length6 = 2;

        set_lexeme(expected6 + 1, LT_ACTION,  0.0,  's');
        set_lexeme(expected6 + 0, LT_OPERAND, 2.0, '\0');

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
    }

    {
        const char *case7 = "cos(14)/sqrt(88)";
        const int length_without_terminator_7 = 16;
        
        Lexeme expected7[9];
        const int expected_length7 = 9;

        set_lexeme(expected7 + 0, LT_ACTION,  0.0,   'c');
        set_lexeme(expected7 + 1, LT_ACTION,  0.0,   '(');
        set_lexeme(expected7 + 2, LT_OPERAND, 14.0, '\0');
        set_lexeme(expected7 + 3, LT_ACTION,  0.0,   ')');
        set_lexeme(expected7 + 4, LT_ACTION,  0.0,   '/');
        set_lexeme(expected7 + 5, LT_ACTION,  0.0,   'r');
        set_lexeme(expected7 + 6, LT_ACTION,  0.0,   '(');
        set_lexeme(expected7 + 7, LT_OPERAND, 88.0, '\0');
        set_lexeme(expected7 + 8, LT_ACTION,  0.0,   ')');

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
    }

    {
        const char *case8 = "(sin(2+2^3)+tg(1))+ctg(0.5)+cos(14/88+sqrt(9)*ln(88))*69";
        const int length_without_terminator_8 = 56;
        
        Lexeme expected8[39];
        const int expected_length8 = 39;

        set_lexeme(expected8 + 0,  LT_ACTION,  0.0,   '(');
    
        set_lexeme(expected8 + 1,  LT_ACTION,  0.0,   's');
        set_lexeme(expected8 + 2,  LT_ACTION,  0.0,   '(');
        set_lexeme(expected8 + 3,  LT_OPERAND, 2.0,  '\0');
        set_lexeme(expected8 + 4,  LT_ACTION,  0.0,   '+');
        set_lexeme(expected8 + 5,  LT_OPERAND, 2.0,  '\0');
        set_lexeme(expected8 + 6,  LT_ACTION,  0.0,   '^');
        set_lexeme(expected8 + 7,  LT_OPERAND, 3.0,  '\0');
        set_lexeme(expected8 + 8,  LT_ACTION,  0.0,   ')');
    
        set_lexeme(expected8 + 9,  LT_ACTION,  0.0,   '+');

        set_lexeme(expected8 + 10, LT_ACTION,  0.0,   't');
        set_lexeme(expected8 + 11, LT_ACTION,  0.0,   '(');
        set_lexeme(expected8 + 12, LT_OPERAND, 1.0,  '\0');
        set_lexeme(expected8 + 13, LT_ACTION,  0.0,   ')');

        set_lexeme(expected8 + 14, LT_ACTION,  0.0,   ')');


        set_lexeme(expected8 + 15, LT_ACTION,  0.0,   '+');


        set_lexeme(expected8 + 16, LT_ACTION,  0.0,   'g');
        set_lexeme(expected8 + 17, LT_ACTION,  0.0,   '(');
        set_lexeme(expected8 + 18, LT_OPERAND, 0.5,  '\0');
        set_lexeme(expected8 + 19, LT_ACTION,  0.0,   ')');

        set_lexeme(expected8 + 20, LT_ACTION,  0.0,   '+');


        set_lexeme(expected8 + 21, LT_ACTION,  0.0,   'c');
        set_lexeme(expected8 + 22, LT_ACTION,  0.0,   '(');
        set_lexeme(expected8 + 23, LT_OPERAND, 14.0, '\0');
        set_lexeme(expected8 + 24, LT_ACTION,  0.0,   '/');
        set_lexeme(expected8 + 25, LT_OPERAND, 88.0, '\0');

        set_lexeme(expected8 + 26, LT_ACTION,  0.0,   '+');

        set_lexeme(expected8 + 27, LT_ACTION,  0.0,   'r');
        set_lexeme(expected8 + 28, LT_ACTION,  0.0,   '(');
        set_lexeme(expected8 + 29, LT_OPERAND, 9.0,  '\0');
        set_lexeme(expected8 + 30, LT_ACTION,  0.0,   ')');
        set_lexeme(expected8 + 31, LT_ACTION,  0.0,   '*');

        set_lexeme(expected8 + 32, LT_ACTION,  0.0,   'l');
        set_lexeme(expected8 + 33, LT_ACTION,  0.0,   '(');
        set_lexeme(expected8 + 34, LT_OPERAND, 88.0, '\0');
        set_lexeme(expected8 + 35, LT_ACTION,  0.0,   ')');
        set_lexeme(expected8 + 36, LT_ACTION,  0.0,   ')');

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
    }

    {
        const char *case9 = "cos(14)/sqrt(x)";
        const int length_without_terminator_9 = 17;
        
        Lexeme expected9[9];
        const int expected_length9 = 9;

        set_lexeme(expected9 + 0, LT_ACTION,              0.0,   'c');
        set_lexeme(expected9 + 1, LT_ACTION,              0.0,   '(');
        set_lexeme(expected9 + 2, LT_OPERAND,             14.0, '\0');
        set_lexeme(expected9 + 3, LT_ACTION,              0.0,   ')');
        set_lexeme(expected9 + 4, LT_ACTION,              0.0,   '/');
        set_lexeme(expected9 + 5, LT_ACTION,              0.0,   'r');
        set_lexeme(expected9 + 6, LT_ACTION,              0.0,   '(');
        set_lexeme(expected9 + 7, LT_OPERAND_PLACEHOLDER, 0.0,  '\0');
        set_lexeme(expected9 + 8, LT_ACTION,              0.0,   ')');

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
    }

    {
        const char *case10 = "(sin(2+2^3)+tg(1))+ctg(0.5)+cos(14/88-sqrt(9)*ln(88))*69";
        const int length_without_terminator_10 = 56;
        
        Lexeme expected10[41];
        const int expected_length10 = 41;

        set_lexeme(expected10 + 0,  LT_ACTION,  0.0,   '(');
    
        set_lexeme(expected10 + 1,  LT_ACTION,  0.0,   's');
        set_lexeme(expected10 + 2,  LT_ACTION,  0.0,   '(');
        set_lexeme(expected10 + 3,  LT_OPERAND, 2.0,  '\0');
        set_lexeme(expected10 + 4,  LT_ACTION,  0.0,   '+');
        set_lexeme(expected10 + 5,  LT_OPERAND, 2.0,  '\0');
        set_lexeme(expected10 + 6,  LT_ACTION,  0.0,   '^');
        set_lexeme(expected10 + 7,  LT_OPERAND, 3.0,  '\0');
        set_lexeme(expected10 + 8,  LT_ACTION,  0.0,   ')');
    
        set_lexeme(expected10 + 9,  LT_ACTION,  0.0,   '+');

        set_lexeme(expected10 + 10, LT_ACTION,  0.0,   't');
        set_lexeme(expected10 + 11, LT_ACTION,  0.0,   '(');
        set_lexeme(expected10 + 12, LT_OPERAND, 1.0,  '\0');
        set_lexeme(expected10 + 13, LT_ACTION,  0.0,   ')');

        set_lexeme(expected10 + 14, LT_ACTION,  0.0,   ')');


        set_lexeme(expected10 + 15, LT_ACTION,  0.0,   '+');


        set_lexeme(expected10 + 16, LT_ACTION,  0.0,   'g');
        set_lexeme(expected10 + 17, LT_ACTION,  0.0,   '(');
        set_lexeme(expected10 + 18, LT_OPERAND, 0.5,  '\0');
        set_lexeme(expected10 + 19, LT_ACTION,  0.0,   ')');

        set_lexeme(expected10 + 20, LT_ACTION,  0.0,   '+');


        set_lexeme(expected10 + 21, LT_ACTION,  0.0,   'c');
        set_lexeme(expected10 + 22, LT_ACTION,  0.0,   '(');
        set_lexeme(expected10 + 23, LT_OPERAND, 14.0, '\0');
        set_lexeme(expected10 + 24, LT_ACTION,  0.0,   '/');
        set_lexeme(expected10 + 25, LT_OPERAND, 88.0, '\0');

        set_lexeme(expected10 + 26, LT_ACTION,  0.0,   '+');
        set_lexeme(expected10 + 27, LT_OPERAND, -1.0, '\0');
        set_lexeme(expected10 + 28, LT_ACTION,  0.0,   '*');

        set_lexeme(expected10 + 29, LT_ACTION,  0.0,   'r');
        set_lexeme(expected10 + 30, LT_ACTION,  0.0,   '(');
        set_lexeme(expected10 + 31, LT_OPERAND, 9.0,  '\0');
        set_lexeme(expected10 + 32, LT_ACTION,  0.0,   ')');
        set_lexeme(expected10 + 33, LT_ACTION,  0.0,   '*');

        set_lexeme(expected10 + 34, LT_ACTION,  0.0,   'l');
        set_lexeme(expected10 + 35, LT_ACTION,  0.0,   '(');
        set_lexeme(expected10 + 36, LT_OPERAND, 88.0, '\0');
        set_lexeme(expected10 + 37, LT_ACTION,  0.0,   ')');
        set_lexeme(expected10 + 38, LT_ACTION,  0.0,   ')');

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
    }
}
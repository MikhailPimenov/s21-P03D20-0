#include "shunting_yard_test.h"


static int are_lexeme_arrays_equal(const Lexeme *const first, const Lexeme *const second, int length) {
    for (int index = 0; index < length; ++index) {
        if (!are_lexemes_equal(first + index, second + index)) {
            return 0;
        }
    }
    return 1;
}

void shunting_yard_test(void (*shunting_yard_function)(const Lexeme *, int, Lexeme *, int *)) {
    // const char *case1 = "2 + 1";
    // const char *expected1 = "2 1 +";

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
        printf("test # 1: ");
        if (expected_length1 == actual_length1 && are_lexeme_arrays_equal(expected1, actual1, expected_length1)) {
            printf("ok\n");
        } else 
        {
            printf("FAILED\n");
            printf("input:\n");
            print_lexeme_array(case1, length1);
            printf("output expected:\n");
            print_lexeme_array(expected1, expected_length1);
            printf("output   actual:\n");
            print_lexeme_array(actual1, actual_length1);
        }
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
        printf("test # 2: ");
        if (expected_length2 == actual_length2 && are_lexeme_arrays_equal(expected2, actual2, expected_length2))
        {
            printf("ok\n");
        } else {
            printf("FAILED\n");
            printf("input:\n");
            print_lexeme_array(case2, length2);
            printf("output expected:\n");
            print_lexeme_array(expected2, expected_length2);
            printf("output   actual:\n");
            print_lexeme_array(actual2, actual_length2);
        }
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
        printf("test # 3: ");
        if (expected_length3 == actual_length3 && are_lexeme_arrays_equal(expected3, actual3, expected_length3))
        {
            printf("ok\n");
        }
        else
        {
            printf("FAILED\n");
            printf("input:\n");
            print_lexeme_array(case3, length3);
            printf("output expected:\n");
            print_lexeme_array(expected3, expected_length3);
            printf("output   actual:\n");
            print_lexeme_array(actual3, actual_length3);
        }
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
        printf("test # 4: ");
        if (expected_length4 == actual_length4 && are_lexeme_arrays_equal(expected4, actual4, expected_length4)) {
            printf("ok\n");
        } else {
            printf("FAILED\n");
            printf("input:\n");
            print_lexeme_array(case4, length4);
            printf("output expected:\n");
            print_lexeme_array(expected4, expected_length4);
            printf("output   actual:\n");
            print_lexeme_array(actual4, actual_length4);
        }
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
        printf("test # 5: ");
        if (expected_length5 == actual_length5 && are_lexeme_arrays_equal(expected5, actual5, expected_length5)) {
            printf("ok\n");
        } else {
            printf("FAILED\n");
            printf("input:\n");
            print_lexeme_array(case5, length5);
            printf("output expected:\n");
            print_lexeme_array(expected5, expected_length5);
            printf("output   actual:\n");
            print_lexeme_array(actual5, actual_length5);
        }
    }
}
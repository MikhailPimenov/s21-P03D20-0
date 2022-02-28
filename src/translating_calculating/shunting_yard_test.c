#include "shunting_yard_test.h"
// /*

//     LT_OPERAND = 0,
//     LT_ACTION = 1
// };

// typedef struct Lexeme {
//     int data;
//     int actual_type;
// } Lexeme;

// void get_lexeme(const Lexeme *lexeme, int *operand_out, char *action_out) {
//     *operand_out = 0;
//     *action_out = '\0';
//     // *actual_type_out = lexeme->actual_type;

//     //  expecting integer (number, operand)
//     if (lexeme->actual_type == LT_OPERAND) {
//         *operand_out = lexeme->data;
//         return;
//     }

//     //  expecting char (symbol, operator, action)
//     const int *const pointer_to_int = &(lexeme->data);
//     const char *const pointer_to_char = (char*)pointer_to_int;
//     *action_out = *pointer_to_char;

//     // *action_out = *((char*)(&(lexeme->data)));   // same in one line
// }
// */
// /*
// "+"
// "-" (unary and binary) unary '-' -> m
// "*"
// "/"
// "()"
// sin(x) -> s
// cos(x) -> c
// tan(x) -> t
// ctg(x) -> g
// sqrt(x) -> r
// ln(x) - l
// */

// /*
// void visual_test_get_lexeme(void get_lexeme(const Lexeme*, int *, char *)){
//     Lexeme lexemes[33];
//     lexemes[0] = (Lexeme){.data = 56, .actual_type = LT_OPERAND};
//     lexemes[1] = (Lexeme){.data = '-', .actual_type = LT_ACTION};
//     lexemes[2] = (Lexeme){.data = 14, .actual_type = LT_OPERAND};
//     lexemes[3] = (Lexeme){.data = 88, .actual_type = LT_OPERAND};
//     lexemes[4] = (Lexeme){.data = '*', .actual_type = LT_ACTION};
//     lexemes[5] = (Lexeme){.data = 1488, .actual_type = LT_OPERAND};
//     lexemes[6] = (Lexeme){.data = '-', .actual_type = LT_ACTION};
//     lexemes[7] = (Lexeme){.data = 228, .actual_type = LT_OPERAND};
//     lexemes[8] = (Lexeme){.data = -99, .actual_type = LT_OPERAND};
//     lexemes[9] = (Lexeme){.data = '/', .actual_type = LT_ACTION};
//     lexemes[10] = (Lexeme){.data = '+', .actual_type = LT_ACTION};
//     lexemes[11] = (Lexeme){.data = '/', .actual_type = LT_ACTION};
//     lexemes[12] = (Lexeme){.data = -1, .actual_type = LT_OPERAND};
//     lexemes[13] = (Lexeme){.data = -0, .actual_type = LT_OPERAND};
//     lexemes[14] = (Lexeme){.data = 10, .actual_type = LT_OPERAND};
//     lexemes[15] = (Lexeme){.data = -0, .actual_type = LT_OPERAND};
//     lexemes[16] = (Lexeme){.data = 'm', .actual_type = LT_ACTION};
//     lexemes[17] = (Lexeme){.data = 's', .actual_type = LT_ACTION};
//     lexemes[18] = (Lexeme){.data = 't', .actual_type = LT_ACTION};
//     lexemes[19] = (Lexeme){.data = 'g', .actual_type = LT_ACTION};
//     lexemes[20] = (Lexeme){.data = -5, .actual_type = LT_OPERAND};
//     lexemes[21] = (Lexeme){.data = 25, .actual_type = LT_OPERAND};
//     lexemes[22] = (Lexeme){.data = -0, .actual_type = LT_OPERAND};
//     lexemes[23] = (Lexeme){.data = 'm', .actual_type = LT_ACTION};
//     lexemes[24] = (Lexeme){.data = 's', .actual_type = LT_ACTION};
//     lexemes[25] = (Lexeme){.data = '(', .actual_type = LT_ACTION};
//     lexemes[26] = (Lexeme){.data = -50, .actual_type = LT_OPERAND};
//     lexemes[27] = (Lexeme){.data = 250, .actual_type = LT_OPERAND};
//     lexemes[28] = (Lexeme){.data = -60, .actual_type = LT_OPERAND};
//     lexemes[29] = (Lexeme){.data = 'l', .actual_type = LT_ACTION};
//     lexemes[30] = (Lexeme){.data = 't', .actual_type = LT_ACTION};
//     lexemes[31] = (Lexeme){.data = ')', .actual_type = LT_ACTION};
//     lexemes[32] = (Lexeme){.data = 'g', .actual_type = LT_ACTION};

//     const int length = 33;

//     for (int index = 0; index < length; ++index) {
//         int actual_type = -1;
//         int operand = -1;
//         char action = '\0';
//         get_lexeme(lexemes + index, &operand, &action);
//         if (lexemes[index].actual_type == LT_OPERAND) {
//             printf("operand = %d\n", operand);
//         }
//         if (lexemes[index].actual_type == LT_ACTION) {
//             printf("action  = %c\n", action);
//         }

//     }
// }

// */
// /*

//     printf("%s\n", greetings);

//     int is_test_failed = 0;

//     const char *case1 = "2 + 1";
//     const char *expected1 = "2 1 +";
//     const char *actual1 = shunting_yard_function(case1);
//     is_test_failed = _get_test_resolution_and_print_output(expected1, actual1, 1);

//     const char *case2 = "59 + 7 / 2";
//     const char *expected2 = "59 7 2 / +";
//     const char *actual2 = shunting_yard_function(case2);
//     is_test_failed = _get_test_resolution_and_print_output(expected2, actual2, 2);

//     const char *case3 = "( 5 + 7 ) / 2";
//     const char *expected3 = "5 7 + 2 /";
//     const char *actual3 = shunting_yard_function(case3);
//     is_test_failed = _get_test_resolution_and_print_output(expected3, actual3, 3);

//     const char *case4 = " 5 * 2 - 3";
//     const char *expected4 = "5 2 * 3 -";
//     const char *actual4 = shunting_yard_function(case4);
//     is_test_failed = _get_test_resolution_and_print_output(expected4, actual4, 4);

//     const char *case5 = " 5 * ( 2 - 3 )";
//     const char *expected5 = "5 2 3 - *";
//     const char *actual5 = shunting_yard_function(case5);
//     is_test_failed = _get_test_resolution_and_print_output(expected5, actual5, 5);

//     const char *case6 = " 5 * ( 2 - 3 )";
//     const char *expected6 = "5 2 3 - *";
//     const char *actual6 = shunting_yard_function(case6);
//     is_test_failed = _get_test_resolution_and_print_output(expected6, actual6, 6);

//     "sin(cos(2*x))";
//     const char *case7 = "sin(2)";
//     const char *expected7 = "5 2 3 - *";
//     const char *actual7 = shunting_yard_function(case7);
//     is_test_failed = _get_test_resolution_and_print_output(expected7, actual7, 7);

// */

// static int are_two_lexemes_equal(const Lexeme* first, const Lexeme* second) {
//     return (first->actual_type == second->actual_type) && (first->data == second->data);
// }

// static int are_equal(const Lexeme *first_array, const Lexeme *second_array, int length) {
//     for (int index = 0; index < length; ++index) {
//         if (!are_two_lexemes_equal(first_array + index, second_array + index))
//             return 0;
//     }
//     return 1;
// }

// void shunting_yard_test(void (*shunting_yard_function)(const Lexeme*, int, Lexeme*, int *), const char *greetings) {
//     printf("%s\n", greetings);
// // void test_shunting_yard(void (*shunting_yard_function)(const Lexeme *, int, Lexeme *, int*)) {
//     // const char *case1 = "2 + 1";
//     // const char *expected1 = "2 1 +";

//     const int length1 = 3;
//     Lexeme case1[3];
//     case1[0] = (Lexeme){.data = 2, .actual_type = LT_OPERAND};
//     case1[1] = (Lexeme){.data = '+', .actual_type = LT_ACTION};
//     case1[2] = (Lexeme){.data = 1, .actual_type = LT_OPERAND};

//     Lexeme expected1[3];
//     expected1[0] = (Lexeme){.data = 2, .actual_type = LT_OPERAND};
//     expected1[1] = (Lexeme){.data = 1, .actual_type = LT_OPERAND};
//     expected1[2] = (Lexeme){.data = '+', .actual_type = LT_ACTION};

//     Lexeme actual1[3];
//     const int expected_length1 = 3;
//     int actual_length1 = -1;
//     shunting_yard_function(case1, length1, actual1, &actual_length1);
//     printf("test # 1: ");
//     if (expected_length1 == actual_length1 && are_equal(expected1, actual1, length1)) {
//         printf("ok\n");
//     } else {
//         printf("FAILED\n");
//     }

//     // const char *case2 = "59 + 7 / 2";
//     // const char *expected2 = "59 7 2 / +";

//     const int length2 = 5;
//     Lexeme case2[5];
//     case2[0] = (Lexeme){.data = 59, .actual_type = LT_OPERAND};
//     case2[1] = (Lexeme){.data = '+', .actual_type = LT_ACTION};
//     case2[2] = (Lexeme){.data = 7, .actual_type = LT_OPERAND};
//     case2[3] = (Lexeme){.data = '/', .actual_type = LT_ACTION};
//     case2[4] = (Lexeme){.data = 2, .actual_type = LT_OPERAND};

//     Lexeme expected2[5];
//     expected2[0] = (Lexeme){.data = 59, .actual_type = LT_OPERAND};
//     expected2[1] = (Lexeme){.data = 7, .actual_type = LT_OPERAND};
//     expected2[2] = (Lexeme){.data = 2, .actual_type = LT_OPERAND};
//     expected2[3] = (Lexeme){.data = '/', .actual_type = LT_ACTION};
//     expected2[4] = (Lexeme){.data = '+', .actual_type = LT_ACTION};

//     Lexeme actual2[5];
//     const int expected_length2 = 5;
//     int actual_length2 = -1;
//     shunting_yard_function(case2, length2, actual2, &actual_length2);
//     printf("test # 2: ");
//     if (expected_length2 == actual_length2 && are_equal(expected2, actual2, length2)) {
//         printf("ok\n");
//     } else {
//         printf("FAILED\n");
//     }

//     // const char *case3 = "( 5 + 7 ) / 2";
//     // const char *expected3 = "5 7 + 2 /";

//     {
//     const int length3 = 7;
//     Lexeme case3[7];
//     case3[0] = (Lexeme){.data = '(', .actual_type = LT_ACTION};
//     case3[1] = (Lexeme){.data = 5, .actual_type = LT_OPERAND};
//     case3[2] = (Lexeme){.data = '+', .actual_type = LT_ACTION};
//     case3[3] = (Lexeme){.data = 7, .actual_type = LT_OPERAND};
//     case3[4] = (Lexeme){.data = ')', .actual_type = LT_ACTION};
//     case3[5] = (Lexeme){.data = '/', .actual_type = LT_ACTION};
//     case3[6] = (Lexeme){.data = 2, .actual_type = LT_OPERAND};

//     Lexeme expected3[5];
//     expected3[0] = (Lexeme){.data = 5, .actual_type = LT_OPERAND};
//     expected3[1] = (Lexeme){.data = 7, .actual_type = LT_OPERAND};
//     expected3[2] = (Lexeme){.data = '+', .actual_type = LT_ACTION};
//     expected3[3] = (Lexeme){.data = 2, .actual_type = LT_OPERAND};
//     expected3[4] = (Lexeme){.data = '/', .actual_type = LT_ACTION};

//     Lexeme actual3[5];
//     const int expected_length3 = 5;
//     int actual_length3 = -1;
//     shunting_yard_function(case3, length3, actual3, &actual_length3);
//     printf("test # 3: ");
//     if (expected_length3 == actual_length3 && are_equal(expected3, actual3, length3)) {
//         printf("ok\n");
//     } else {
//         printf("FAILED\n");
//     }
//     }

//     // const char *case4 = " 5 * 2 - 3";
//     // const char *expected4 = "5 2 * 3 -";
//     const int length4 = 5;
//     Lexeme case4[5];
//     case4[0] = (Lexeme){.data = 5, .actual_type = LT_OPERAND};
//     case4[1] = (Lexeme){.data = '*', .actual_type = LT_ACTION};
//     case4[2] = (Lexeme){.data = 2, .actual_type = LT_OPERAND};
//     case4[3] = (Lexeme){.data = '-', .actual_type = LT_ACTION};
//     case4[4] = (Lexeme){.data = 3, .actual_type = LT_OPERAND};

//     Lexeme expected4[5];
//     expected4[0] = (Lexeme){.data = 5, .actual_type = LT_OPERAND};
//     expected4[1] = (Lexeme){.data = 2, .actual_type = LT_OPERAND};
//     expected4[2] = (Lexeme){.data = '*', .actual_type = LT_ACTION};
//     expected4[3] = (Lexeme){.data = 3, .actual_type = LT_OPERAND};
//     expected4[4] = (Lexeme){.data = '-', .actual_type = LT_ACTION};

//     Lexeme actual4[5];
//     const int expected_length4 = 5;
//     int actual_length4 = -1;
//     shunting_yard_function(case4, length4, actual4, &actual_length4);
//     printf("test # 4: ");
//     if (expected_length4 == actual_length4 && are_equal(expected4, actual4, length4)) {
//         printf("ok\n");
//     } else {
//         printf("FAILED\n");
//     }

//     // const char *case5 = " 5 * ( 2 - 3 )";
//     // const char *expected5 = "5 2 3 - *";
//     const int length5 = 7;
//     Lexeme case5[7];
//     case5[0] = (Lexeme){.data = 5, .actual_type = LT_OPERAND};
//     case5[1] = (Lexeme){.data = '*', .actual_type = LT_ACTION};
//     case5[2] = (Lexeme){.data = '(', .actual_type = LT_ACTION};
//     case5[3] = (Lexeme){.data = 2, .actual_type = LT_OPERAND};
//     case5[4] = (Lexeme){.data = '-', .actual_type = LT_ACTION};
//     case5[5] = (Lexeme){.data = 3, .actual_type = LT_OPERAND};
//     case5[6] = (Lexeme){.data = ')', .actual_type = LT_ACTION};

//     Lexeme expected5[7];
//     expected5[0] = (Lexeme){.data = 5, .actual_type = LT_OPERAND};
//     expected5[1] = (Lexeme){.data = 2, .actual_type = LT_OPERAND};
//     expected5[2] = (Lexeme){.data = 3, .actual_type = LT_OPERAND};
//     expected5[3] = (Lexeme){.data = '-', .actual_type = LT_ACTION};
//     expected5[4] = (Lexeme){.data = '*', .actual_type = LT_ACTION};

//     Lexeme actual5[5];
//     const int expected_length5 = 5;
//     int actual_length5 = -1;
//     shunting_yard_function(case5, length5, actual5, &actual_length5);
//     printf("test # 5: ");
//     if (expected_length5 == actual_length5 && are_equal(expected5, actual5, length5)) {
//         printf("ok\n");
//     } else {
//         printf("FAILED\n");
//     }

//     // const char *case6 = " 5 * ( 2 - 3 )";
//     // const char *expected6 = "5 2 3 - *";

// }

static void print_lexeme_array(const Lexeme *const array, int length) {
    for (int index = 0; index < length; ++index) {
        print_lexeme(array + index);
    }
    printf("\n");
}

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
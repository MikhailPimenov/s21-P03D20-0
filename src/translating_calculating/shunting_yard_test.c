#include "shunting_yard_test.h"




void shunting_yard_test(const char *(*shunting_yard_function)(const char*), const char* greetings) {
    printf("%s\n", greetings);
    
    int is_test_failed = 0;

    const char *case1 = "2 + 1";
    const char *expected1 = "2 1 +";
    const char *actual1 = shunting_yard_function(case1);
    is_test_failed = _get_test_resolution_and_print_output(expected1, actual1, 1);

    const char *case2 = "59 + 7 / 2";
    const char *expected2 = "59 7 2 / +";
    const char *actual2 = shunting_yard_function(case2);
    is_test_failed = _get_test_resolution_and_print_output(expected2, actual2, 2);

    const char *case3 = "( 5 + 7 ) / 2";
    const char *expected3 = "5 7 + 2 /";
    const char *actual3 = shunting_yard_function(case3);
    is_test_failed = _get_test_resolution_and_print_output(expected3, actual3, 3);

    const char *case4 = " 5 * 2 - 3";
    const char *expected4 = "5 2 * 3 -";
    const char *actual4 = shunting_yard_function(case4);
    is_test_failed = _get_test_resolution_and_print_output(expected4, actual4, 4);

    const char *case5 = " 5 * ( 2 - 3 )";
    const char *expected5 = "5 2 3 - *";
    const char *actual5 = shunting_yard_function(case5);
    is_test_failed = _get_test_resolution_and_print_output(expected5, actual5, 5);

    const char *case6 = " 5 * ( 2 - 3 )";
    const char *expected6 = "5 2 3 - *";
    const char *actual6 = shunting_yard_function(case6);
    is_test_failed = _get_test_resolution_and_print_output(expected6, actual6, 6);


    "sin(cos(2*x))";
    const char *case7 = "sin(2)";
    const char *expected7 = "5 2 3 - *";
    const char *actual7 = shunting_yard_function(case7);
    is_test_failed = _get_test_resolution_and_print_output(expected7, actual7, 7);


    // const char *case5 = "sin ( cos ( 2 * x ) )";
    // const char *expected5 = "???";
    
    printf("Final result: ");
    (is_test_failed) ? printf("FAIL\n\n") : printf("SUCCESS\n\n");
}

#include "string_to_double_test.h"


static void __compare_and_print_input_output_and_resolution(
    int case_number,
    const char* input,
    int input_length_without_terminator,
    int expected_status,
    int actual_status,
    const char *expected_pointer,
    const char *actual_pointer,
    double expected_number,
    double actual_number,
    double epsilon,
    int silent_on_success
) {
    printf("Test #%d:\t", case_number);
    if (expected_status  == actual_status  && 
        expected_pointer == actual_pointer && 
        are_double_equal(expected_number, actual_number, epsilon)) {
        printf("ok\n");
        if (silent_on_success)
            return;
    } else {
        printf("FAILED\n");
    }

    printf("input:\n");
    printf("string               = \"%s\"\n", input);
    printf("length               = %d\n", input_length_without_terminator);
    printf("expected:\n");
    printf("status               = %d\n", expected_status);
    printf("pointer to next part = %p\n", expected_pointer);
    printf("converted number     = %lf\n", expected_number);
    printf("actual:\n");
    printf("status               = %d\n", actual_status);
    printf("pointer to next part = %p\n", actual_pointer);
    printf("converted number     = %lf\n", actual_number);

    printf("\n");
}


void string_to_double_test(const char*(string_to_double_function)(const char*, int, double*, int*)) {
    printf("\nstring_to_double_test():\n");
    // static const int E_SUCCESS = 0;
    static const double epsilon = 1e-12;
    static const int silent_on_success = 1;

    const char *case1 = "123.56";
    const int length_without_terminator1 = 6;


    const double expected1 = 123.56;
    const char *next_part_expected1 = case1 + 6;  //  points exactly to '\0' which goes right after "123.56"
    const int expected_status1 = CS_SUCCESSFUL_CONVERSION;

    double actual1 = -14.87;
    int actual_status1 = -1;
    const char *next_part_actual1 = string_to_double_function(case1, length_without_terminator1, &actual1, &actual_status1);

    __compare_and_print_input_output_and_resolution(
        1,
        case1,
        length_without_terminator1,
        expected_status1,
        actual_status1,
        next_part_expected1,
        next_part_actual1,
        expected1,
        actual1,
        epsilon,
        silent_on_success);



    const char *case2 = "0.12345";
    const int length_without_terminator2 = 7;


    const double expected2 = 0.12345;
    const char *next_part_expected2 = case2 + 7;  //  points exactly to '\0' which goes right after "0.12345"
    const int expected_status2 = CS_SUCCESSFUL_CONVERSION;

    double actual2 = -14.87;
    int actual_status2 = -1;
    const char *next_part_actual2 = string_to_double_function(case2, length_without_terminator2, &actual2, &actual_status2);

    __compare_and_print_input_output_and_resolution(
        2,
        case2,
        length_without_terminator2,
        expected_status2,
        actual_status2,
        next_part_expected2,
        next_part_actual2,
        expected2,
        actual2,
        epsilon,
        silent_on_success);


    const char *case3 = "-0.12345";
    const int length_without_terminator3 = 8;


    const double expected3 = -0.12345;
    const char *next_part_expected3 = case3 + 8;  //  points exactly to '\0' which goes right after "-0.12345"
    const int expected_status3 = CS_SUCCESSFUL_CONVERSION;

    double actual3 = -14.87;
    int actual_status3 = -1;
    const char *next_part_actual3 = string_to_double_function(case3, length_without_terminator3, &actual3, &actual_status3);

    __compare_and_print_input_output_and_resolution(
        3,
        case3,
        length_without_terminator3,
        expected_status3,
        actual_status3,
        next_part_expected3,
        next_part_actual3,
        expected3,
        actual3,
        epsilon,
        silent_on_success);


    const char *case4 = "513.0";
    const int length_without_terminator4 = 5;


    const double expected4 = 513.0;
    const char *next_part_expected4 = case4 + 5;  //  points exactly to '\0' which goes right after "123.56"
    const int expected_status4 = CS_SUCCESSFUL_CONVERSION;

    double actual4 = -14.87;
    int actual_status4 = -1;
    const char *next_part_actual4 = string_to_double_function(case4, length_without_terminator4, &actual4, &actual_status4);

    __compare_and_print_input_output_and_resolution(
        4,
        case4,
        length_without_terminator4,
        expected_status4,
        actual_status4,
        next_part_expected4,
        next_part_actual4,
        expected4,
        actual4,
        epsilon,
        silent_on_success);




    const char *case5 = "513";
    const int length_without_terminator5 = 3;


    const double expected5 = 513.0;
    const char *next_part_expected5 = case5 + 3;  //  points exactly to '\0' which goes right after "513"
    const int expected_status5 = CS_SUCCESSFUL_CONVERSION;

    double actual5 = -14.87;
    int actual_status5 = -1;
    const char *next_part_actual5 = string_to_double_function(case5, length_without_terminator5, &actual5, &actual_status5);

    __compare_and_print_input_output_and_resolution(
        5,
        case5,
        length_without_terminator5,
        expected_status5,
        actual_status5,
        next_part_expected5,
        next_part_actual5,
        expected5,
        actual5,
        epsilon,
        silent_on_success);



    const char *case6 = "14.88";
    const int length_without_terminator6 = 5;


    const double expected6 = 14.88;
    const char *next_part_expected6 = case6 + 5;  //  points exactly to '\0' which goes right after "14.88"
    const int expected_status6 = CS_SUCCESSFUL_CONVERSION;

    double actual6 = -14.87;
    int actual_status6 = -1;
    const char *next_part_actual6 = string_to_double_function(case6, length_without_terminator6, &actual6, &actual_status6);

    __compare_and_print_input_output_and_resolution(
        6,
        case6,
        length_without_terminator6,
        expected_status6,
        actual_status6,
        next_part_expected6,
        next_part_actual6,
        expected6,
        actual6,
        epsilon,
        silent_on_success);


    const char *case7 = "14141414.88888888";
    const int length_without_terminator7 = 17;


    const double expected7 = 14141414.88888888;
    const char *next_part_expected7 = case7 + 17;  //  points exactly to '\0' which goes right after "14141414.88888888"
    const int expected_status7 = CS_SUCCESSFUL_CONVERSION;

    double actual7 = -14.87;
    int actual_status7 = -1;
    const char *next_part_actual7 = string_to_double_function(case7, length_without_terminator7, &actual7, &actual_status7);

    __compare_and_print_input_output_and_resolution(
        7,
        case7,
        length_without_terminator7,
        expected_status7,
        actual_status7,
        next_part_expected7,
        next_part_actual7,
        expected7,
        actual7,
        epsilon,
        silent_on_success);


    const char *case8 = "-14141414.88888888";
    const int length_without_terminator8 = 18;


    const double expected8 = -14141414.88888888;
    const char *next_part_expected8 = case8 + 18;  //  points exactly to '\0' which goes right after "-14141414.88888888"
    const int expected_status8 = CS_SUCCESSFUL_CONVERSION;

    double actual8 = -14.87;
    int actual_status8 = -1;
    const char *next_part_actual8 = string_to_double_function(case8, length_without_terminator8, &actual8, &actual_status8);

    __compare_and_print_input_output_and_resolution(
        8,
        case8,
        length_without_terminator8,
        expected_status8,
        actual_status8,
        next_part_expected8,
        next_part_actual8,
        expected8,
        actual8,
        epsilon,
        silent_on_success);


    const char *case9 = "sin(-14141414.88888888)";
    const int length_without_terminator9 = 23;


    const double expected9 = 0.0;
    const char *next_part_expected9 = case9;  //  points to the beginning because conversion is failed
    const int expected_status9 = CS_FAILED_CONVERSION;

    double actual9 = -14.87;
    int actual_status9 = -1;
    const char *next_part_actual9 = string_to_double_function(case9, length_without_terminator9, &actual9, &actual_status9);

    __compare_and_print_input_output_and_resolution(
        9,
        case9,
        length_without_terminator9,
        expected_status9,
        actual_status9,
        next_part_expected9,
        next_part_actual9,
        expected9,
        actual9,
        epsilon,
        silent_on_success);

}

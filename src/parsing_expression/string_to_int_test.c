#include "string_to_int_test.h"

static void __compare_and_print_input_output_and_resolution(
    int case_number,
    const char* input,
    int input_length_without_terminator,
    int expected_status,
    int actual_status,
    const char *expected_pointer,
    const char *actual_pointer,
    int expected_number,
    int actual_number,
    int silent_on_success
) {
    printf("Test #%d:\t", case_number);
    if (expected_status  == actual_status  && 
        expected_pointer == actual_pointer && 
        expected_number  == actual_number) {
        printf("ok\n");
        if (silent_on_success)
            return;
    } else {
        printf("FAILED\n");
    }

    printf("input:\n");
    printf("string               = \"%s\"\n", input);
    printf("input length = %d\n", input_length_without_terminator);
    printf("expected:\n");
    printf("status               = %d\n", expected_status);
    printf("pointer to next part = %p\n", expected_pointer);
    printf("converted number     = %d\n", expected_number);
    printf("actual:\n");
    printf("status               = %d\n", actual_status);
    printf("pointer to next part = %p\n", actual_pointer);
    printf("converted number     = %d\n", actual_number);

    printf("\n");
}

void string_to_int_test(const char*(string_to_int_function)(const char*, int, int*, int*)) {
    printf("\nstring_to_int_test():\n");
    const int silent_on_success = 1;

    const char *const case1 = "123";
    const int length_without_terminator1 = 3;
    const int expected1 = 123;
    const char *const next_part_expected1 = case1 + 3;  //  pointer to '\0' which goes right after "123"
    const int conversion_status_expected1 = CS_SUCCESSFUL_CONVERSION;


    int actual1 = 0;
    int conversion_status_actual1 = -1; 
    const char *next_part_actual1 = string_to_int_function(case1, length_without_terminator1, &actual1, &conversion_status_actual1);
    
    __compare_and_print_input_output_and_resolution(
        1, 
        case1, 
        length_without_terminator1,
        conversion_status_expected1,
        conversion_status_actual1,
        next_part_expected1, 
        next_part_actual1, 
        expected1, 
        actual1, 
        silent_on_success);


    const char *const case2 = "0";
    const int length_without_terminator2 = 1;
    const int expected2 = 0;
    const char *const next_part_expected2 = case2 + 1;  //  pointer to '\0' which goes right after "0"
    const int conversion_status_expected2 = CS_SUCCESSFUL_CONVERSION;


    int actual2 = 0;
    int conversion_status_actual2 = -1; 
    const char *next_part_actual2 = string_to_int_function(case2, length_without_terminator2, &actual2, &conversion_status_actual2);
    
    __compare_and_print_input_output_and_resolution(
        2, 
        case2, 
        length_without_terminator2,
        conversion_status_expected2,
        conversion_status_actual2,
        next_part_expected2, 
        next_part_actual2, 
        expected2, 
        actual2, 
        silent_on_success);
   
    const char *const case3 = "9001";
    const int length_without_terminator3 = 4;
    const int expected3 = 9001;
    const char *const next_part_expected3 = case3 + 4;  //  pointer to '\0' which goes right after "9001"
    const int conversion_status_expected3 = CS_SUCCESSFUL_CONVERSION;


    int actual3 = 0;
    int conversion_status_actual3 = -1; 
    const char *next_part_actual3 = string_to_int_function(case3, length_without_terminator3, &actual3, &conversion_status_actual3);
    
    __compare_and_print_input_output_and_resolution(
        3, 
        case3, 
        length_without_terminator3,
        conversion_status_expected3,
        conversion_status_actual3,
        next_part_expected3, 
        next_part_actual3, 
        expected3, 
        actual3, 
        silent_on_success);


    const char *const case4 = "9096501";
    const int length_without_terminator4 = 7;
    const int expected4 = 9096501;
    const char *const next_part_expected4 = case4 + 7;  //  pointer to '\0' which goes right after "9096501"
    const int conversion_status_expected4 = CS_SUCCESSFUL_CONVERSION;


    int actual4 = 0;
    int conversion_status_actual4 = -1; 
    const char *next_part_actual4 = string_to_int_function(case4, length_without_terminator4, &actual4, &conversion_status_actual4);
    
    __compare_and_print_input_output_and_resolution(
        4, 
        case4, 
        length_without_terminator4,
        conversion_status_expected4,
        conversion_status_actual4,
        next_part_expected4, 
        next_part_actual4, 
        expected4, 
        actual4, 
        silent_on_success);

    
    const char *const case5 = "9096501-99";
    const int length_without_terminator5 = 10;
    const int expected5 = 9096501;
    const char *const next_part_expected5 = case5 + 7;  //  pointer to '-' which goes right after "9096501"
    const int conversion_status_expected5 = CS_SUCCESSFUL_CONVERSION;


    int actual5 = 0;
    int conversion_status_actual5 = -1; 
    const char *next_part_actual5 = string_to_int_function(case5, length_without_terminator5, &actual5, &conversion_status_actual5);
    
    __compare_and_print_input_output_and_resolution(
        5, 
        case5, 
        length_without_terminator5,
        conversion_status_expected5,
        conversion_status_actual5,
        next_part_expected5, 
        next_part_actual5, 
        expected5, 
        actual5, 
        silent_on_success);

    
    const char *const case6 = "9096501*(45";
    const int length_without_terminator6 = 11;
    const int expected6 = 9096501;
    const char *const next_part_expected6 = case6 + 7;  //  pointer to '*' which goes right after "9096501"
    const int conversion_status_expected6 = CS_SUCCESSFUL_CONVERSION;


    int actual6 = 0;
    int conversion_status_actual6 = -1; 
    const char *next_part_actual6 = string_to_int_function(case6, length_without_terminator6, &actual6, &conversion_status_actual6);
    
    __compare_and_print_input_output_and_resolution(
        6, 
        case6, 
        length_without_terminator6,
        conversion_status_expected6,
        conversion_status_actual6,
        next_part_expected6, 
        next_part_actual6, 
        expected6, 
        actual6, 
        silent_on_success);

    
    const char *const case7 = "9096-501*(45";
    const int length_without_terminator7 = 12;
    const int expected7 = 9096;
    const char *const next_part_expected7 = case7 + 4;  //  pointer to '-' which goes right after "9096"
    const int conversion_status_expected7 = CS_SUCCESSFUL_CONVERSION;


    int actual7 = 0;
    int conversion_status_actual7 = -1; 
    const char *next_part_actual7 = string_to_int_function(case7, length_without_terminator7, &actual7, &conversion_status_actual7);
    
    __compare_and_print_input_output_and_resolution(
        7, 
        case7, 
        length_without_terminator7,
        conversion_status_expected7,
        conversion_status_actual7,
        next_part_expected7, 
        next_part_actual7, 
        expected7, 
        actual7, 
        silent_on_success);


    //  test case with shifting: considering not "9096-501*(45", but "501*(45"
    const char *const case8 = "9096-501*(45";
    const int shift8 = 5;
    const int length_without_terminator8 = 7;
    const int expected8 = 501;
    const char *const next_part_expected8 = case8 + shift8 + 3;  //  pointer to '*' which goes right after "9096-501"
    const int conversion_status_expected8 = CS_SUCCESSFUL_CONVERSION;


    int actual8 = 0;
    int conversion_status_actual8 = -1;                 //  note this shift below
    const char *next_part_actual8 = string_to_int_function(case8 + shift8, length_without_terminator8, &actual8, &conversion_status_actual8);
    
    __compare_and_print_input_output_and_resolution(
        8, 
        case8 + shift8,  //  note this shift
        length_without_terminator8,
        conversion_status_expected8,
        conversion_status_actual8,
        next_part_expected8, 
        next_part_actual8, 
        expected8, 
        actual8, 
        silent_on_success);


//  test case with shifting: considering not "9096-501*(45", but "45"
    const char *const case9 = "9096-501*(45";
    const int shift9 = 10;
    const int length_without_terminator9 = 2;
    const int expected9 = 45;
    const char *const next_part_expected9 = case9 + shift9 + 2;  //  pointer to '*' which goes right after "9096-501"
    const int conversion_status_expected9 = CS_SUCCESSFUL_CONVERSION;


    int actual9 = 0;
    int conversion_status_actual9 = -1;                 //  note this shift below
    const char *next_part_actual9 = string_to_int_function(case9 + shift9, length_without_terminator9, &actual9, &conversion_status_actual9);
    
    __compare_and_print_input_output_and_resolution(
        9, 
        case9 + shift9,  //  note this shift
        length_without_terminator9,
        conversion_status_expected9,
        conversion_status_actual9,
        next_part_expected9, 
        next_part_actual9, 
        expected9, 
        actual9, 
        silent_on_success);


    const char *const case10 = "9096-501*(45";
    const int shift10 = 4;
    const int length_without_terminator10 = 8;
    const int expected10 = -501;
    const char *const next_part_expected10 = case10 + shift10 + 4;  //  pointer to '*' which goes right after "9096-501"
    const int conversion_status_expected10 = CS_SUCCESSFUL_CONVERSION;


    int actual10 = 0;
    int conversion_status_actual10 = -1;                 //  note this shift below
    const char *next_part_actual10 = string_to_int_function(case10 + shift10, length_without_terminator10, &actual10, &conversion_status_actual10);
    
    __compare_and_print_input_output_and_resolution(
        10, 
        case10 + shift10,  //  note this shift
        length_without_terminator10,
        conversion_status_expected10,
        conversion_status_actual10,
        next_part_expected10, 
        next_part_actual10, 
        expected10, 
        actual10, 
        silent_on_success);
    
    
    // const char *case10 = "096-501*(45";
    // const int expected10 = 96;


    // TODO: test cases when conversion is failed

    const char *const case11 = "sin(9096)-501*(45";
    const int length_without_terminator11 = 17;
    const int expected11 = 0;
    const char *const next_part_expected11 = case11;  //  points to the beginning because conversion is failed
    const int conversion_status_expected11 = CS_FAILED_CONVERSION;


    int actual11 = 0;
    int conversion_status_actual11 = -1; 
    const char *next_part_actual11 = string_to_int_function(case11, length_without_terminator11, &actual11, &conversion_status_actual11);
    
    __compare_and_print_input_output_and_resolution(
        11, 
        case11, 
        length_without_terminator11,
        conversion_status_expected11,
        conversion_status_actual11,
        next_part_expected11, 
        next_part_actual11, 
        expected11, 
        actual11, 
        silent_on_success);

}

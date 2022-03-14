#include "check_expression_and_count_lexemes_test.h"

static void __compare_and_print_input_output_and_resolution(
    int case_number, 
    const char *input,
    int input_length,
    int expected_status,
    int expected_length,
    int actual_status,
    int actual_length,
    int silent_on_success 
) {
    printf("Test #%d:\t", case_number);
    if ((actual_status == expected_status) && (actual_length == expected_length)) {
        printf("ok\n");
        if (silent_on_success)
            return;
    } else {
        printf("FAILED\n");
    }

    printf("input:\n");
    printf("%s\n", input);
    printf("input length = %d\n", input_length);

    printf("expected status = %d\n", expected_status);
    printf("expected length = %d\n", expected_length);

    printf("actual status   = %d\n", actual_status);
    printf("actual length   = %d\n", actual_length);
    
    printf("\n");
}

// int check_input_string_and_count_lexemes(const char *infix_notation_row, int length_without_terminator, int *amount_of_lexemes_out)
void check_expression_and_count_lexemes_test(int (*check_expression_and_count_lexemes_function)(const char*, int, int *)) {
    printf("\ncheck_expression_and_count_lexemes_test():\n");
    int silent_on_success = 1;

    {
        const char *case1 = "2+1";
        const int length_without_terminator_1 = 3;
        const int expected_status1  = EC_EXPRESSION_IS_CORRECT;
        const int expected_length1  = 3;
     

        int actual_length1 = -1;


        const int actual_status1 = check_expression_and_count_lexemes_function(case1, length_without_terminator_1, &actual_length1);
        __compare_and_print_input_output_and_resolution(
            1, 
            case1, 
            length_without_terminator_1, 
            expected_status1, 
            expected_length1, 
            actual_status1, 
            actual_length1,
            silent_on_success); 
    }

    {
        const char *case2 = "59+7/2";
        const int length_without_terminator2 = 6;
   
        const int expected_status2  = EC_EXPRESSION_IS_CORRECT;
        const int expected_length2 = 5;
     
        int actual_length2 = -1;

        const int actual_status2 = check_expression_and_count_lexemes_function(case2, length_without_terminator2, &actual_length2);
        __compare_and_print_input_output_and_resolution(
            2, 
            case2, 
            length_without_terminator2, 
            expected_status2, 
            expected_length2, 
            actual_status2, 
            actual_length2,
            silent_on_success); 

    }

    {
        const char *case3 = "(5+7)/2";
        const int length_without_terminator3 = 7;
               
        const int expected_status3  = EC_EXPRESSION_IS_CORRECT;
        const int expected_length3 = 7;
     
        int actual_length3 = -1;

        const int actual_status3 = check_expression_and_count_lexemes_function(case3, length_without_terminator3, &actual_length3);
        __compare_and_print_input_output_and_resolution(
            3, 
            case3, 
            length_without_terminator3, 
            expected_status3, 
            expected_length3, 
            actual_status3, 
            actual_length3,
            silent_on_success); 
    }

    {
        const char *case4 = "(5+7)/2*4+88/14+9";
        const int length_without_terminator4 = 17;
               
        const int expected_status4 = EC_EXPRESSION_IS_CORRECT;
        const int expected_length4 = 15;
     
        int actual_length4 = -1;

        const int actual_status4 = check_expression_and_count_lexemes_function(case4, length_without_terminator4, &actual_length4);
        __compare_and_print_input_output_and_resolution(
            4, 
            case4, 
            length_without_terminator4, 
            expected_status4, 
            expected_length4, 
            actual_status4, 
            actual_length4,
            silent_on_success); 
    }

    {
        const char *case5 = "517*(20-39)";
        const int length_without_terminator5 = 11;
        
        const int expected_status5 = EC_EXPRESSION_IS_CORRECT;
        const int expected_length5 = 9;
     
        int actual_length5 = -1;

        const int actual_status5 = check_expression_and_count_lexemes_function(case5, length_without_terminator5, &actual_length5);
        __compare_and_print_input_output_and_resolution(
            5,
            case5,
            length_without_terminator5,
            expected_status5,
            expected_length5,
            actual_status5,
            actual_length5,
            silent_on_success); 
    }

    {
        const char *case6 = "sin(2)";
        const int length_without_terminator6 = 6;
        
        const int expected_status6 = EC_EXPRESSION_IS_CORRECT;
        const int expected_length6 = 4;
     
        int actual_length6 = -1;

        const int actual_status6 = check_expression_and_count_lexemes_function(case6, length_without_terminator6, &actual_length6);
        __compare_and_print_input_output_and_resolution(
            6,
            case6,
            length_without_terminator6,
            expected_status6,
            expected_length6,
            actual_status6,
            actual_length6,
            silent_on_success); 
    }

    {
        const char *case7 = "cos(14)/sqrt(88)";
        const int length_without_terminator7 = 16;
        
        const int expected_status7 = EC_EXPRESSION_IS_CORRECT;
        const int expected_length7 = 9;
     
        int actual_length7 = -1;

        const int actual_status7 = check_expression_and_count_lexemes_function(case7, length_without_terminator7, &actual_length7);
        __compare_and_print_input_output_and_resolution(
            7,
            case7,
            length_without_terminator7,
            expected_status7,
            expected_length7,
            actual_status7,
            actual_length7,
            silent_on_success);
    }

    {
        const char *case8 = "(sin(2+2^3)+tg(1))+ctg(0.5)+cos(14/88+sqrt(9)*ln(88))*69";
        const int length_without_terminator8 = 56;
        
        const int expected_status8 = EC_EXPRESSION_IS_CORRECT;
        const int expected_length8 = 39;
     
        int actual_length8 = -1;

        const int actual_status8 = check_expression_and_count_lexemes_function(case8, length_without_terminator8, &actual_length8);
        __compare_and_print_input_output_and_resolution(
            8,
            case8,
            length_without_terminator8,
            expected_status8,
            expected_length8,
            actual_status8,
            actual_length8,
            silent_on_success);
    }


    {
        const char *case9 = "cos(14)/sqrt(x)";
        const int length_without_terminator9 = 15;
        
        const int expected_status9 = EC_EXPRESSION_IS_CORRECT;
        const int expected_length9 = 9;
        
        int actual_length9 = -1;

        const int actual_status9 = check_expression_and_count_lexemes_function(case9, length_without_terminator9, &actual_length9);
        __compare_and_print_input_output_and_resolution(
            9,
            case9,
            length_without_terminator9,
            expected_status9,
            expected_length9,
            actual_status9,
            actual_length9,
            silent_on_success);
    }

    {
        const char *case10 = "(sin(2+2^3)+tg(1))+ctg(0.5)+cos(14/88-sqrt(9)*ln(88))*69";
        const int length_without_terminator10 = 56;
       
        const int expected_status10 = EC_EXPRESSION_IS_CORRECT;
        const int expected_length10 = 41;
        
        int actual_length10 = -1;

        const int actual_status10 = check_expression_and_count_lexemes_function(case10, length_without_terminator10, &actual_length10);
        __compare_and_print_input_output_and_resolution(
            10,
            case10,
            length_without_terminator10,
            expected_status10,
            expected_length10,
            actual_status10,
            actual_length10,
            silent_on_success);
    }

    {
        const char *case11 = "(sin(2+2^3)+tg(1))*+ctg(0.5)+cos(14/88-sqrt(9)*ln(88))*69";
        const int length_without_terminator11 = 56;
       
        const int expected_status11 = EC_EXPRESSION_IS_NOT_CORRECT;
        const int expected_length11 = -1;
        
        int actual_length11 = -1;

        const int actual_status11 = check_expression_and_count_lexemes_function(case11, length_without_terminator11, &actual_length11);
        __compare_and_print_input_output_and_resolution(
            11,
            case11,
            length_without_terminator11,
            expected_status11,
            expected_length11,
            actual_status11,
            actual_length11,
            silent_on_success);
    }

    {
        const char *case12 = "(sin2+2^3)+tg(1))+ctg(0.5)+cos(14/88-sqrt(9)*ln(88))*69";
        const int length_without_terminator12 = 55;
       
        const int expected_status12 = EC_EXPRESSION_IS_NOT_CORRECT;
        const int expected_length12 = -1;
        
        int actual_length12 = -1;

        const int actual_status12 = check_expression_and_count_lexemes_function(case12, length_without_terminator12, &actual_length12);
        __compare_and_print_input_output_and_resolution(
            12,
            case12,
            length_without_terminator12,
            expected_status12,
            expected_length12,
            actual_status12,
            actual_length12,
            silent_on_success);
    }

    {
        const char *case13 = "*(sin(2+2^3)+tg(1))+ctg(0.5)+cos(14/88-sqrt(9)*ln(88))*69";
        const int length_without_terminator13 = 57;
       
        const int expected_status13 = EC_EXPRESSION_IS_NOT_CORRECT;
        const int expected_length13 = -1;
        
        int actual_length13 = -1;

        const int actual_status13 = check_expression_and_count_lexemes_function(case13, length_without_terminator13, &actual_length13);
        __compare_and_print_input_output_and_resolution(
            13,
            case13,
            length_without_terminator13,
            expected_status13,
            expected_length13,
            actual_status13,
            actual_length13,
            silent_on_success);
    }

    {
        const char *case14 = "(sin(2+2^3)+tg(1))+ctg(0.5)+cos(14/88-sqrt(9)*ln(88))*69-";
        const int length_without_terminator14 = 58;
       
        const int expected_status14 = EC_EXPRESSION_IS_NOT_CORRECT;
        const int expected_length14 = -1;
        
        int actual_length14 = -1;

        const int actual_status14 = check_expression_and_count_lexemes_function(case14, length_without_terminator14, &actual_length14);
        __compare_and_print_input_output_and_resolution(
            14,
            case14,
            length_without_terminator14,
            expected_status14,
            expected_length14,
            actual_status14,
            actual_length14,
            silent_on_success);
    }

    {
        const char *case15 = "-(sin(2+2^3)+tg(1))+ctg(0.5)+cos(14/88-sqrt(9)*ln(88))*69";
        const int length_without_terminator15 = 57;
       
        const int expected_status15 = EC_EXPRESSION_IS_CORRECT;
        const int expected_length15 = 44;
        
        int actual_length15 = -1;

        const int actual_status15 = check_expression_and_count_lexemes_function(case15, length_without_terminator15, &actual_length15);
        __compare_and_print_input_output_and_resolution(
            15,
            case15,
            length_without_terminator15,
            expected_status15,
            expected_length15,
            actual_status15,
            actual_length15,
            silent_on_success);
    }

    {
        const char *case16 = "+(sin(2+2^3)+tg(1))+ctg(0.5)+cos(14/88-sqrt(9)*ln(88))*69";
        const int length_without_terminator16 = 57;
       
        const int expected_status16 = EC_EXPRESSION_IS_CORRECT;
        const int expected_length16 = 42;
        
        int actual_length16 = -1;

        const int actual_status16 = check_expression_and_count_lexemes_function(case16, length_without_terminator16, &actual_length16);
        __compare_and_print_input_output_and_resolution(
            16,
            case16,
            length_without_terminator16,
            expected_status16,
            expected_length16,
            actual_status16,
            actual_length16,
            silent_on_success);
    }

    {
        const char *case17 = "+)sin(2+2^3)+tg(1))+ctg(0.5)+cos(14/88-sqrt(9)*ln(88))*69";
        const int length_without_terminator17 = 57;
       
        const int expected_status17 = EC_EXPRESSION_IS_NOT_CORRECT;
        const int expected_length17 = -1;
        
        int actual_length17 = -1;

        const int actual_status17 = check_expression_and_count_lexemes_function(case17, length_without_terminator17, &actual_length17);
        __compare_and_print_input_output_and_resolution(
            17,
            case17,
            length_without_terminator17,
            expected_status17,
            expected_length17,
            actual_status17,
            actual_length17,
            silent_on_success);
    }
}
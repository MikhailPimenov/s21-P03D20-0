void test_string_to_int(const char*(string_to_int_function)(const char*, int*, int*)) {
    int is_successfully_converted = 0;
    
    const char *case1 = "123";
    const int expected1 = 123;
    
    
    int actual1 = 0;
    string_to_int_function(case1, &actual1, &is_successfully_converted);
    
    printf("test # 1:  ");
    (actual1 == expected1 && is_successfully_converted) ? printf("ok\n") : printf("FAILED\n");
    
    
    const char *case2 = "0";
    const int expected2 = 0;
    
    int actual2 = 0;
    string_to_int_function(case2, &actual2, &is_successfully_converted);
    
    printf("test # 2:  ");
    (actual2 == expected2 && is_successfully_converted) ? printf("ok\n") : printf("FAILED\n");
    
    
    
    const char *case3 = "9001";
    const int expected3 = 9001;
    
    int actual3 = 0;
    string_to_int_function(case3, &actual3, &is_successfully_converted);
    
    printf("test # 3:  ");
    (actual3 == expected3 && is_successfully_converted) ? printf("ok\n") : printf("FAILED\n");
    
    
    
    const char *case4 = "9096501";
    const int expected4 = 9096501;
    
    int actual4 = 0;
    string_to_int_function(case4, &actual4, &is_successfully_converted);
    
    printf("test # 4:  ");
    (actual4 == expected4 && is_successfully_converted) ? printf("ok\n") : printf("FAILED\n");
    
    
    
    const char *case5 = "9096501-99";
    const int expected5 = 9096501;
    
    int actual5 = 0;
    string_to_int_function(case5, &actual5, &is_successfully_converted);
    
    printf("test # 5:  ");
    (actual5 == expected5 && is_successfully_converted) ? printf("ok\n") : printf("FAILED\n");
    
    
    
    const char *case6 = "9096501*(45";
    const int expected6 = 9096501;
    
    int actual6 = 0;
    string_to_int_function(case6, &actual6, &is_successfully_converted);
    
    printf("test # 6:  ");
    (actual6 == expected6 && is_successfully_converted) ? printf("ok\n") : printf("FAILED\n");
    
   
    
    
    const char *case7 = "9096501*(45";
    const int expected7 = 9096501;
    
    int actual7 = 0;
    string_to_int_function(case7, &actual7, &is_successfully_converted);
    
    printf("test # 7:  ");
    (actual7 == expected7 && is_successfully_converted) ? printf("ok\n") : printf("FAILED\n");
    
    
    
    const char *case8 = "9096-501*(45";
    const int expected8 = 9096;
    
    int actual8 = 0;
    string_to_int_function(case8, &actual8, &is_successfully_converted);
    
    printf("test # 8:  ");
    (actual8 == expected8 && is_successfully_converted) ? printf("ok\n") : printf("FAILED\n");
    
    
    
    const char *case9 = "9096-501*(45";
    const int expected9 = 9096;
    
    int actual9 = 0;
    string_to_int_function(case9, &actual9, &is_successfully_converted);
    
    printf("test # 9:  ");
    (actual9 == expected9 && is_successfully_converted) ? printf("ok\n") : printf("FAILED\n");
    
    
    
    const char *case10 = "096-501*(45";
    const int expected10 = 96;
    
    int actual10 = 0;
    string_to_int_function(case10, &actual10, &is_successfully_converted);
    
    printf("test #10:  ");
    (actual10 == expected10 && is_successfully_converted) ? printf("ok\n") : printf("FAILED\n");
    
}

int is_symbol_numeric(char symbol) {
    static const int ascii_code_of_first_numeric = 48;
    static const int ascii_code_of_last_numeric = 57;
    
    return ascii_code_of_first_numeric <= symbol && symbol <= ascii_code_of_last_numeric;
}

int get_amount_of_digits_in_number(const char *input) {
    int length = 0;
    while(is_symbol_numeric(input[length])) 
        ++length;
        
    return length;
}

int get_int_from_numeric_char(char symbol) {
    static const int ascii_shift = 48;
    return (int)symbol - 48;
}

const char* string_to_int(const char* input, int *result, int *conversion_status) {
    
    static const int base = 10;
    
    const int length = get_amount_of_digits_in_number(input);
    if (length == 0) {
        *conversion_status = 0;
        *result = -1;
    }
    int index = length - 1;
    
    
    int sum = 0;
    int multiplier = 1;
    
    while (index > -1) {
        const int digit = get_int_from_numeric_char(input[index]);
        sum += (digit * multiplier);
        multiplier *= base;
        
        --index;
    }

    *result = sum;
    *conversion_status = 1;
    return NULL;
}
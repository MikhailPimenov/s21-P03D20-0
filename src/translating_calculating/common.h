#ifndef SRC_TRANSLATING_CALCULATING_COMMON_H_
#define SRC_TRANSLATING_CALCULATING_COMMON_H_

#include <stdio.h>

int compare_strings(const char *first, const char *second);
int get_test_resolution_and_print_output(const char *expected, const char *actual, int test_number);
int are_double_equal(double left, double right, double epsilon);

#endif //  SRC_TRANSLATING_CALCULATING_COMMON_H_
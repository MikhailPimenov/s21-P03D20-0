#include "common.h"

int compare_strings(const char *first, const char *second) {
    int index = 0;

    if ( !first && !second )
        return 0;
    if ( !first )
        return -1;
    if ( !second )
        return +1;

    while (first[index] && second[index]) {
        if (first[index] != second[index]) {
            return first[index] - second[index];
        }
        ++index;
    }

    return 0;
}

int are_double_equal(double left, double right, double epsilon) {
    return ((left > right) ? ((left - right) < epsilon) : ((right - left) < epsilon));  //  fabs(left - right) < epsilon
}
#include "allocate_deallocate_field.h"


int allocate_field(char ***field, int rows, int columns) {
    char **plain_array = malloc(rows * columns * sizeof(char) + rows * sizeof(char*));

    if (plain_array == NULL)
        return A_NOT_ALLOCATED;

    char *start = (char*)(plain_array + rows);

    for (int row = 0; row < rows; ++row)
        plain_array[row] = start + row * columns;

    *field = plain_array;
    return A_ALLOCATED_SUCCESSFULLY;
}

void free_field(char ***field) {
    if (*field) {
        free(*field);
        *field = NULL;
    }
}
#include "input.h"


// if typedef doesn't exist (msvc, blah)
// typedef intptr_t ssize_t;

int getline_allocate(char **line_pointer, size_t *allocated_length, FILE *stream) {

    if (line_pointer == NULL || stream == NULL || allocated_length == NULL) {
        return -1;
    }

    int symbol = '\0';
    symbol = getc(stream);
    if (symbol == EOF) {
        return -1;
    }

    const size_t initial_buffer_size = 128u;
    if (*line_pointer == NULL) {
        *line_pointer = malloc(initial_buffer_size);
        if (*line_pointer == NULL) {
            return -1;
        }
        *allocated_length = initial_buffer_size;
    }

    size_t position = 0;
    while(symbol != EOF) {
        if (position + 1 >= *allocated_length) {
            size_t new_size = *allocated_length + (*allocated_length >> 2);
            if (new_size < initial_buffer_size) {
                new_size = initial_buffer_size;
            }

            char *new_line_pointer = realloc(*line_pointer, new_size);
            if (new_line_pointer == NULL) {
                if (*line_pointer) {
                    free(*line_pointer);
                    *line_pointer = NULL;
                }

                return -1;
            }
            *allocated_length = new_size;
            *line_pointer = new_line_pointer;
        }

        ((unsigned char *)(*line_pointer))[position ++] = symbol;
        if (symbol == '\n') {
            break;
        }
        symbol = getc(stream);
    }

    (*line_pointer)[position] = '\0';
    return position;
}
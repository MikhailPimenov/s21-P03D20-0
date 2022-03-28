#ifndef SRC_INPUT_INPUT_H_
#define SRC_INPUT_INPUT_H_

#include <stdio.h>
#include <stdlib.h>

int getline_allocate(char **line_pointer, size_t *allocated_length, FILE *stream);

#endif  //  SRC_INPUT_INPUT_H_
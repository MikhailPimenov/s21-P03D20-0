#ifndef SRC_FIELD_ALLOCATE_DEALLOCATE_FIELD_H_
#define SRC_FIELD_ALLOCATE_DEALLOCATE_FIELD_H_


#include <stdlib.h>


enum allocation_error_codes {
    A_NOT_ALLOCATED = -1,
    A_ALLOCATED_SUCCESSFULLY = 0
};


int allocate_field(char ***field, int rows, int columns);
void free_field(char ***field);


#endif  //  SRC_FIELD_ALLOCATE_DEALLOCATE_FIELD_H_
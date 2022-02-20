#ifndef SRC_DATA_STRUCTURES_LEXEME_H_
#define SRC_DATA_STRUCTURES_LEXEME_H_

#include <stdlib.h>

enum Lexeme_types {
    LT_OPERAND = 0,
    LT_ACTION = 1
};

typedef struct Lexeme {
    int data;
    int actual_type;
} Lexeme;


void print_lexeme(const Lexeme* lexeme);




#endif //  SRC_DATA_STRUCTURES_LEXEME_H_
#ifndef SRC_DATA_STRUCTURES_LEXEME_H_
#define SRC_DATA_STRUCTURES_LEXEME_H_

enum Lexeme_types {
    LT_OPERAND = 0,
    LT_ACTION = 1
};

typedef struct Lexeme {
    int data;
    int actual_type;
} Lexeme;



#endif //  SRC_DATA_STRUCTURES_LEXEME_H_
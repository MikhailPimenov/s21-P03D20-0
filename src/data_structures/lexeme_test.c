#include "lexeme_test.h"

void get_lexeme_test_visual(void get_lexeme(const Lexeme *const, double *const, char *const)) {
    Lexeme lexemes[33];

    set_lexeme(lexemes + 0, LT_OPERAND,  56.0, '\0');
    set_lexeme(lexemes + 1,  LT_ACTION,   0.0,  '-'); 
    set_lexeme(lexemes + 2, LT_OPERAND, 14.88, '\0');
    set_lexeme(lexemes + 3,  LT_ACTION,   0.0,  '+');
    set_lexeme(lexemes + 4, LT_OPERAND,  22.8, '\0');
    set_lexeme(lexemes + 5,  LT_ACTION,   0.0,  '*');
    set_lexeme(lexemes + 6, LT_OPERAND,  14.0, '\0');
    set_lexeme(lexemes + 7, LT_OPERAND,  88.0, '\0');
    set_lexeme(lexemes + 8,  LT_ACTION,   0.0,  '-');

    set_lexeme(lexemes + 9,  LT_ACTION, 0.0 , '/');
    set_lexeme(lexemes + 10, LT_ACTION, 0.0 , '+');
    set_lexeme(lexemes + 11, LT_ACTION, 0.0 , '/');
    set_lexeme(lexemes + 12, LT_OPERAND, -1.0,  '\0');
    set_lexeme(lexemes + 13, LT_OPERAND, -0.0,  '\0');
    set_lexeme(lexemes + 14, LT_OPERAND, 10.0,  '\0');
    set_lexeme(lexemes + 15, LT_OPERAND, -0.0,  '\0');
    set_lexeme(lexemes + 16, LT_ACTION, 0.0 , 'm');
    set_lexeme(lexemes + 17, LT_ACTION, 0.0 , 's');
    set_lexeme(lexemes + 18, LT_ACTION, 0.0 , 't');
    set_lexeme(lexemes + 19, LT_ACTION, 0.0 , 'g');
    set_lexeme(lexemes + 20, LT_OPERAND, -5.0,  '\0');
    set_lexeme(lexemes + 21, LT_OPERAND, 25.0,  '\0');
    set_lexeme(lexemes + 22, LT_OPERAND, -0.0,  '\0');
    set_lexeme(lexemes + 23, LT_ACTION, 0.0 , 'm');
    set_lexeme(lexemes + 24, LT_ACTION, 0.0 , 's');
    set_lexeme(lexemes + 25, LT_ACTION, 0.0 , '(');
    set_lexeme(lexemes + 26, LT_OPERAND, -5.0, '\0');;
    set_lexeme(lexemes + 27, LT_OPERAND, 25.0, '\0');;
    set_lexeme(lexemes + 28, LT_OPERAND, -6.0, '\0');;
    set_lexeme(lexemes + 29, LT_ACTION, 0.0 , 'l');
    set_lexeme(lexemes + 30, LT_ACTION, 0.0 , 't');
    set_lexeme(lexemes + 31, LT_ACTION, 0.0 , ')');
    set_lexeme(lexemes + 32, LT_ACTION, 0.0 , 'g');

        const int length = 33;

    for (int index = 0; index < length; ++index) {
        // int actual_type = -1;
        double operand = -1;
        char action = '$';
        get_lexeme(lexemes + index, &operand, &action);
        if (lexemes[index].actual_type == LT_OPERAND) {
            printf("operand = %lf\n", operand);
        }
        if (lexemes[index].actual_type == LT_ACTION) {
            printf("action  = %c\n", action);
        }
    }
}
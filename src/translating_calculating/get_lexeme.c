#include <stdio.h>

// enum Lexeme_types {
//     LT_OPERAND = 0,
//     LT_ACTION = 1
// };

// typedef struct Lexeme {
//     int data;
//     int actual_type;
// } Lexeme;

// void get_lexeme(const Lexeme *const lexeme, double *const operand_out, char *const action_out) {
//     *operand_out = 0;
//     *action_out = '\0';

//     // expecting action (operator, action, symbol):
//     if (lexeme->actual_type == LT_ACTION) {
//         *action_out = lexeme->data[0];
//         return;
//     }

//     // expecting operand (number, double):
//     const double *const pointer_to_double = (const double *const)(lexeme->data);
//     *operand_out = *pointer_to_double;
// }

// void set_lexeme(Lexeme *const lexeme, double operand, char action) {
    
//     // expecting to set action (operator, action, symbol):
//     if (lexeme->actual_type == LT_ACTION) {
//         lexeme->data[0] = action;
//     }

//     // expecting to set operand (number, double):
//     data[0] = operand;
// }

/*
"+"
"-" (unary and binary) unary '-' -> m
"*"
"/"
"()"
sin(x) -> s
cos(x) -> c
tan(x) -> t
ctg(x) -> g
sqrt(x) -> r
ln(x) - l
*/


// Student s1;
// s1 = (Student){.id = id, .name = name, .score = score};

// void visual_test_get_lexeme(void get_lexeme(const Lexeme*, int *, int *, char *)){
//     Lexeme lexemes[33];
//     lexemes[0] = (Lexeme){.data = 56, .actual_type = LT_OPERAND};
//     lexemes[1] = (Lexeme){.data = '-', .actual_type = LT_ACTION};
//     lexemes[2] = (Lexeme){.data = 14, .actual_type = LT_OPERAND};
//     lexemes[3] = (Lexeme){.data = 88, .actual_type = LT_OPERAND};
//     lexemes[4] = (Lexeme){.data = '*', .actual_type = LT_ACTION};
//     lexemes[5] = (Lexeme){.data = 1488, .actual_type = LT_OPERAND};
//     lexemes[6] = (Lexeme){.data = '-', .actual_type = LT_ACTION};
//     lexemes[7] = (Lexeme){.data = 228, .actual_type = LT_OPERAND};
//     lexemes[8] = (Lexeme){.data = -99, .actual_type = LT_OPERAND};
//     lexemes[9] = (Lexeme){.data = '/', .actual_type = LT_ACTION};
//     lexemes[10] = (Lexeme){.data = '+', .actual_type = LT_ACTION};
//     lexemes[11] = (Lexeme){.data = '/', .actual_type = LT_ACTION};
//     lexemes[12] = (Lexeme){.data = -1, .actual_type = LT_OPERAND};
//     lexemes[13] = (Lexeme){.data = -0, .actual_type = LT_OPERAND};
//     lexemes[14] = (Lexeme){.data = 10, .actual_type = LT_OPERAND};
//     lexemes[15] = (Lexeme){.data = -0, .actual_type = LT_OPERAND};
//     lexemes[16] = (Lexeme){.data = 'm', .actual_type = LT_ACTION};
//     lexemes[17] = (Lexeme){.data = 's', .actual_type = LT_ACTION};
//     lexemes[18] = (Lexeme){.data = 't', .actual_type = LT_ACTION};
//     lexemes[19] = (Lexeme){.data = 'g', .actual_type = LT_ACTION};
//     lexemes[20] = (Lexeme){.data = -5, .actual_type = LT_OPERAND};
//     lexemes[21] = (Lexeme){.data = 25, .actual_type = LT_OPERAND};
//     lexemes[22] = (Lexeme){.data = -0, .actual_type = LT_OPERAND};
//     lexemes[23] = (Lexeme){.data = 'm', .actual_type = LT_ACTION};
//     lexemes[24] = (Lexeme){.data = 's', .actual_type = LT_ACTION};
//     lexemes[25] = (Lexeme){.data = '(', .actual_type = LT_ACTION};
//     lexemes[26] = (Lexeme){.data = -50, .actual_type = LT_OPERAND};
//     lexemes[27] = (Lexeme){.data = 250, .actual_type = LT_OPERAND};
//     lexemes[28] = (Lexeme){.data = -60, .actual_type = LT_OPERAND};
//     lexemes[29] = (Lexeme){.data = 'l', .actual_type = LT_ACTION};
//     lexemes[30] = (Lexeme){.data = 't', .actual_type = LT_ACTION};
//     lexemes[31] = (Lexeme){.data = ')', .actual_type = LT_ACTION};
//     lexemes[32] = (Lexeme){.data = 'g', .actual_type = LT_ACTION};
    
//     const int length = 33;
    
//     for (int index = 0; index < length; ++index) {
//         int actual_type = -1;
//         int operand = -1;
//         char action = '\0';
//         get_lexeme(lexemes + index, &actual_type, &operand, &action);
//         if (lexemes[index].actual_type == LT_OPERAND) {
//             printf("operand = %d\n", operand);
//         }
//         if (lexemes[index].actual_type == LT_ACTION) {
//             printf("action  = %c\n", action);
//         }
            
//     }
// }
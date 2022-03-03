#include "lexeme.h"

void get_lexeme(const Lexeme *const lexeme, double *const operand_out, char *const action_out) {
    *operand_out = 0;
    *action_out = '\0';

    // expecting action (operator, action, symbol):
    if (lexeme->actual_type == LT_ACTION) {
        *action_out = lexeme->data[0];
        return;
    }

    // expecting operand (number, double):
    const double *const pointer_to_double = (const double *const)(lexeme->data);
    *operand_out = *pointer_to_double;
}

void set_lexeme(Lexeme *lexeme, int actual_type, double operand, char action) {
    if (actual_type != LT_OPERAND && actual_type != LT_ACTION)
        return;


    lexeme->actual_type = actual_type;
    if (lexeme->actual_type == LT_ACTION) {
        (lexeme->data)[0] = action;
        return;
    }

    static const int data_array_length = 8;  //  same as sizeof(double) 
    const double *const pointer_to_double = &operand;
    char *pointer_to_char = (char*)pointer_to_double;

    for (int byte_index = 0; byte_index < data_array_length; ++byte_index)
        (lexeme->data)[byte_index] = *(pointer_to_char + byte_index);    
}

static void __print_lexeme_with_format(const Lexeme *const lexeme, int with_endline, int with_type) {

    if (lexeme->actual_type == LT_ACTION) {
        if (with_type)
            printf("action : ");

        printf("%c ", lexeme->data[0]);

        if (with_endline)
            printf("\n");
        return;
    }
    
    
    if (with_type)
        printf("operand : ");

    printf("%.2lf ", *(double *)(lexeme->data));

    if (with_endline)
        printf("\n");
}

void print_lexeme(const Lexeme *const lexeme) {
    static const int with_endline = 0;
    static const int with_type = 0;
    __print_lexeme_with_format(lexeme, with_endline, with_type);
}

void print_lexeme_with_endline_and_type(const Lexeme *const lexeme) {
    static const int with_endline = 1;
    static const int with_type = 1;
    __print_lexeme_with_format(lexeme, with_endline, with_type);
}

// void print_lexeme(const Lexeme *const lexeme) {
//     if (lexeme->actual_type == LT_ACTION) {
//         printf("action : %c\n", lexeme->data[0]);
//         return;
//     }

//     printf("operand: %lf\n", *(double *)(lexeme->data));
// }

void print_lexeme_array(const Lexeme *const array, int length) {
    for (int index = 0; index < length; ++index) {
        print_lexeme(array + index);
    }
    printf("\n");
}


int are_lexemes_equal(const Lexeme *const left, const Lexeme *const right) {
    if (left->actual_type != right->actual_type)
        return 0;

    char action_left = '\0';
    double operand_left = -1.0;
    get_lexeme(left, &operand_left, &action_left);

    char action_right = '\n';
    double operand_right = -10.0;
    get_lexeme(right, &operand_right, &action_right);


    if (left->actual_type == LT_ACTION) {  // right->actual_type is also LT_ACTION
        return action_left == action_right;
    }

    static const int epsilon = 1e-12;
    /*return*/ are_double_equal(operand_left, operand_right, epsilon);
    return 1;
}

int are_lexeme_arrays_equal(const Lexeme *const first, const Lexeme *const second, int length) {
    for (int index = 0; index < length; ++index) {
        if (!are_lexemes_equal(first + index, second + index)) {
            return 0;
        }
    }
    return 1;
}

int is_operand(const Lexeme *lexeme) {
    return lexeme->actual_type == LT_OPERAND;
}
int is_action(const Lexeme *lexeme) {
    return lexeme->actual_type == LT_ACTION;
}

int is_brace(const Lexeme *lexeme) {
    return lexeme->data[0] == ')' || lexeme->data[0] == '(';
}

int is_not_brace(const Lexeme *lexeme) {
    return !is_brace(lexeme);
}

int get_precenence(const Lexeme *lexeme) {
    double operand = -1;
    char action = '\0';
    get_lexeme(lexeme, &operand, &action);

    switch (action) {
        case '+':
            return OP_LOW;
        case '-':
            return OP_LOW;
        case '*':
            return OP_MEDIUM;
        case '/':
            return OP_MEDIUM;
        case 'p':  //  x^y
            return OP_HIGH;
        case 's':  //  sin(x)
            return OP_HIGH;
        case 'c':  //  cos(x)
            return OP_HIGH;
        case 't':  //  tg(x)
            return OP_HIGH;
        case 'g':  //  ctg(x)
            return OP_HIGH;
        case 'r':  //  sqrt(x)
            return OP_HIGH;
        case 'l':  //  ln(x)
            return OP_HIGH;
        case 'm':  //  -x
            return OP_HIGH;
    };
    return OP_LOWEST;
}

int has_lower_precedence(const Lexeme *left, const Lexeme *right) {
    const int left_precedence = get_precenence(left);
    const int right_precedence = get_precenence(right);

    return left_precedence < right_precedence;
}

int has_top_higher_precedence(Lexeme top, Lexeme current_lexeme) {
    return has_lower_precedence(&current_lexeme, &top);
}

int is_opening_brace(Lexeme lexeme) {
    return lexeme.data[0] == '('; 
}

int is_not_opening_brace(Lexeme lexeme) {
    return !is_opening_brace(lexeme); 
}

int is_closing_brace(Lexeme lexeme) {
    return lexeme.data[0] == ')';
}
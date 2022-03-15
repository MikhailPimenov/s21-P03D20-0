#include "shunting_yard.h"

static int get_length_of_postfix_notation(const Lexeme *infix_notation, int length) {
    int new_length = 0;
    for (int index = 0; index < length; ++index) {
        // if (is_operand(infix_notation + index) || (is_action(infix_notation + index) && !is_brace(infix_notation + index)))   //  TODO: simplify multiple condition if
        if (is_brace(infix_notation + index))
            continue;    
        ++new_length;

    }
    return new_length;
}

static void push_to_postfix_notation(const Lexeme *lexeme_to_push, Lexeme *postfix_notation, int *last_index_postfix_notation) {
    postfix_notation[*last_index_postfix_notation] = *lexeme_to_push;
    ++(*last_index_postfix_notation);
}

static void process_lexeme(const Lexeme *lexeme, Lexeme *postfix_notation, int *last_index_postfix_notation, Stack_node **stack_for_actions) {
    if (is_operand_or_placeholder(lexeme)) {
        push_to_postfix_notation(lexeme, postfix_notation, last_index_postfix_notation);
        return;
    }

    if (is_opening_brace(*lexeme)) {
        push(stack_for_actions, *lexeme);
        return;
    }

    if (is_closing_brace(*lexeme)) {
        while (is_not_opening_brace(top(*stack_for_actions))) {
            const Lexeme action_from_stack = pop(stack_for_actions);
            push_to_postfix_notation(&action_from_stack, postfix_notation, last_index_postfix_notation);
        }
        pop(stack_for_actions);
        return;
    }

    //  is action:
    while (!is_empty(*stack_for_actions) && has_top_higher_precedence(top(*stack_for_actions), *lexeme)) {
        const Lexeme action_from_stack = pop(stack_for_actions);
        push_to_postfix_notation(&action_from_stack, postfix_notation, last_index_postfix_notation);
    }
    push(stack_for_actions, *lexeme);
}

// TODO: remove int *length_out parameter. It is possible to find the length of the postfix_notation outside this function
void shunting_yard(const Lexeme *infix_notation, int length, Lexeme *postfix_notation, int *length_out) {
    *length_out = get_length_of_postfix_notation(infix_notation, length);
    int last_index_postfix_notation = 0;
    Stack_node *stack_for_actions = NULL;

    for (int index = 0; index < length; ++index) {
        const Lexeme current_lexeme = infix_notation[index];
        process_lexeme(&current_lexeme, postfix_notation, &last_index_postfix_notation, &stack_for_actions);
    }

    //  flushing what's left in stack into postfix_notation:
    while (!is_empty(stack_for_actions)) {
        const Lexeme action_from_stack = pop(&stack_for_actions);
        push_to_postfix_notation(&action_from_stack, postfix_notation, &last_index_postfix_notation);
    }
}



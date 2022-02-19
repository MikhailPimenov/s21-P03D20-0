#include <stdio.h>
#include "drawing/drawing.h"
#include "translating_calculating/calculating.h"
#include "translating_calculating/translating.h"
#include "translating_calculating/shunting_yard_test.h"
#include "translating_calculating/shunting_yard.h"

const char* shunting_yard_first_test_success(const char *infix_notation) {
    infix_notation = NULL;
    return "2 1 +";
}

int main() {
    // printf("Hello from main()\n");
    // print_from_translating();



    // const int rows = 25;
    // const int columns = 80;
 
    // char **example_field = NULL;
    // *example_field = NULL;
    // example_field = NULL;
    // printf("Before draw_print():\n");

    shunting_yard_test(shunting_yard, "Testing shunting_yard:");

    // draw_field(example_field, rows, columns);

    // printf("After draw_print():\n");
    
    

    return 0;
}

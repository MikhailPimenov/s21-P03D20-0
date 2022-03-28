#include "drawing.h"

int get_row_number_from_y(double y, int amount_of_rows) {
    if (amount_of_rows < 0) {
        printf("get_row_number_from_y(): amount_of_rows should not be negative!\n");
        return 0;
    }

    return (y + 1.0) * ((double)amount_of_rows) / 2.0;
}

void draw_line(char *line, int length) {
    for (int index = 0; index < length - 1; ++index)
        printf("%c ", line[index]);

    printf("%c", line[length - 1]);
}

int draw_field(char **field, int rows, int columns) {
    for (int row = 0; row < rows; ++row) {
        draw_line(field[row], columns);
        printf("\n");
    }
    return 0;
}
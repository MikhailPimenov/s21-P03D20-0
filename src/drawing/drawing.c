#include "drawing.h"

int get_row_number_from_y(double y, int amount_of_rows) {
    if (amount_of_rows < 0)
        printf("get_row_number_from_y(): amount_of_rows should not be negative!\n");
        return 0;

    return (y + 1.0) * ((double)amount_of_rows) / 2.0;
}

double compute(double x) {
    //  calculate reversed polish notation is here:
    // set_lexeme_placeholders_array
    return 2.0 * x;
}

double get_x_from_column_number(int column, int minimum_column, int maximum_column, double minimum_x, double maximum_x) {
    return (double)column / ((double)maximum_column - (double)minimum_column) * (maximum_x - minimum_x) + minimum_x;
}


// TODO: pass here precalculated array of row values which should be represented as filled symbols (where graph line is)
int set_field(char **field, int rows, int columns, double minimum_x, double maximum_x) {
    for (int column = 0; column < columns; ++column) {

        for (int row = 0; row < rows; ++row) {
            field[row][column] = '.';
        }

        double x = get_x_from_column_number(column, 0, columns, minimum_x, maximum_x);
        double y = compute(x);

        int filled_row = get_row_number_from_y(y, rows);

        if (0 < filled_row && filled_row < rows)
            field[filled_row][column] = '*';
    }
}

int draw_line(char *line, int length) {
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
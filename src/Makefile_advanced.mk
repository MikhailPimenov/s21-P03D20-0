CC=gcc
CFLAGS=-c -Wall -Werror -Wextra -std=c11

BUILDIR=../build


OBJECTS=$(BUILDIR)/lexeme.o $(BUILDIR)/stack_lexeme.o $(BUILDIR)/shunting_yard.o $(BUILDIR)/common.o $(BUILDIR)/calculate_reverse_polish_notation.o  $(BUILDIR)/parse_to_lexemes.o  $(BUILDIR)/string_to_int.o  $(BUILDIR)/string_to_double.o  $(BUILDIR)/recognize_lexemes.o $(BUILDIR)/create_lexemes.o  $(BUILDIR)/check_expression_and_count_lexemes.o $(BUILDIR)/drawing.o $(BUILDIR)/allocate_deallocate_field.o
OBJECTS_TESTS=$(BUILDIR)/graph_test.o $(BUILDIR)/lexeme_test.o $(BUILDIR)/stack_lexeme_test.o $(BUILDIR)/shunting_yard_test.o $(BUILDIR)/calculate_reverse_polish_notation_test.o $(BUILDIR)/parse_to_lexemes_test.o $(BUILDIR)/string_to_int_test.o $(BUILDIR)/string_to_double_test.o $(BUILDIR)/check_expression_and_count_lexemes_test.o
# all: $(BUILDIR)/graph.exe


# run: $(BUILDIR)/graph.exe
		# $(BUILDIR)/graph.exe	


test: $(BUILDIR)/graph_test.exe
		$(BUILDIR)/graph_test.exe	


# $(BUILDIR)/graph.exe: $(BUILDIR)/translating.o $(BUILDIR)/graph.o $(BUILDIR)/shunting_yard.o $(BUILDIR)/stack.o $(BUILDIR)/lexeme.o
		# $(CC) $(BUILDIR)/graph.o $(BUILDIR)/translating.o  $(BUILDIR)/shunting_yard.o $(BUILDIR)/stack.o $(BUILDIR)/lexeme.o -o $(BUILDIR)/graph.exe



# $(BUILDIR)/graph_test.exe: $(BUILDIR)/graph_test.o $(BUILDIR)/lexeme.o $(BUILDIR)/lexeme_test.o $(BUILDIR)/stack_lexeme.o $(BUILDIR)/stack_lexeme_test.o $(BUILDIR)/shunting_yard.o $(BUILDIR)/shunting_yard_test.o $(BUILDIR)/common.o $(BUILDIR)/calculate_reverse_polish_notation.o $(BUILDIR)/calculate_reverse_polish_notation_test.o $(BUILDIR)/parse_to_lexemes.o $(BUILDIR)/parse_to_lexemes_test.o $(BUILDIR)/string_to_int.o $(BUILDIR)/string_to_int_test.o $(BUILDIR)/string_to_double.o $(BUILDIR)/string_to_double_test.o $(BUILDIR)/recognize_lexemes.o $(BUILDIR)/create_lexemes.o $(BUILDIR)/check_expression_and_count_lexemes_test.o $(BUILDIR)/check_expression_and_count_lexemes.o $(BUILDIR)/drawing.o $(BUILDIR)/allocate_deallocate_field.o
		# $(CC) $(BUILDIR)/graph_test.o $(BUILDIR)/lexeme.o $(BUILDIR)/lexeme_test.o $(BUILDIR)/stack_lexeme.o $(BUILDIR)/stack_lexeme_test.o $(BUILDIR)/shunting_yard.o $(BUILDIR)/shunting_yard_test.o $(BUILDIR)/common.o $(BUILDIR)/calculate_reverse_polish_notation.o $(BUILDIR)/calculate_reverse_polish_notation_test.o $(BUILDIR)/parse_to_lexemes.o $(BUILDIR)/parse_to_lexemes_test.o $(BUILDIR)/string_to_int.o $(BUILDIR)/string_to_int_test.o $(BUILDIR)/string_to_double.o $(BUILDIR)/string_to_double_test.o $(BUILDIR)/recognize_lexemes.o $(BUILDIR)/create_lexemes.o $(BUILDIR)/check_expression_and_count_lexemes_test.o $(BUILDIR)/check_expression_and_count_lexemes.o $(BUILDIR)/drawing.o $(BUILDIR)/allocate_deallocate_field.o -o $(BUILDIR)/graph_test.exe

$(BUILDIR)/graph_test.exe: $(OBJECTS) $(OBJECTS_TESTS) $(BUILDIR)/graph_test.o
		$(CC) -o $@ $^


$(BUILDIR)/graph_test.o: graph.c
		$(CC) $(CFLAGS) $< -D TEST_GRAPH_ -o $@


# $(BUILDIR)/stack_lexeme.o: data_structures/stack.c data_structures/stack.h
		# $(CC) $(CFLAGS) -D LEXEME_T_ $< -o $@

$(BUILDIR)/stack_lexeme.o: */stack.c */stack.h
		$(CC) $(CFLAGS) -D LEXEME_T_ $< -o $@


$(BUILDIR)/%.o: %.c
		$(CC) $(CFLAGS) $< -o $@


# $(BUILDIR)/stack_lexeme.o: data_structures/stack.c data_structures/stack.h
		# $(CC) $(CFLAGS) data_structures/stack.c -D LEXEME_T_ -o $(BUILDIR)/stack_lexeme.o







$(BUILDIR)/stack_lexeme_test.o: data_structures/stack_test.c data_structures/stack_test.h
		$(CC) $(CFLAGS) data_structures/stack_test.c -D LEXEME_T_ -o $(BUILDIR)/stack_lexeme_test.o


# $(BUILDIR)/graph.o: graph.c
# 		$(CC) $(CFLAGS) graph.c -o $(BUILDIR)/graph.o


# $(BUILDIR)/shunting_yard_test.o: translating_calculating/shunting_yard_test.c translating_calculating/shunting_yard_test.h
# 		$(CC) $(CFLAGS) translating_calculating/shunting_yard_test.c -o $(BUILDIR)/shunting_yard_test.o


# $(BUILDIR)/shunting_yard.o: translating_calculating/shunting_yard.c translating_calculating/shunting_yard.h
# 		$(CC) $(CFLAGS) translating_calculating/shunting_yard.c -o $(BUILDIR)/shunting_yard.o


# $(BUILDIR)/lexeme.o: data_structures/lexeme.c data_structures/lexeme.h
		# $(CC) $(CFLAGS) data_structures/lexeme.c -o $(BUILDIR)/lexeme.o


# $(BUILDIR)/lexeme_test.o: data_structures/lexeme_test.c data_structures/lexeme_test.h
# 		$(CC) $(CFLAGS) data_structures/lexeme_test.c -o $(BUILDIR)/lexeme_test.o


# $(BUILDIR)/common.o: translating_calculating/common.c translating_calculating/common.h
# 		$(CC) $(CFLAGS) translating_calculating/common.c -o $(BUILDIR)/common.o


# $(BUILDIR)/calculate_reverse_polish_notation_test.o: translating_calculating/calculate_reverse_polish_notation_test.c translating_calculating/calculate_reverse_polish_notation_test.h translating_calculating/calculation_error_codes.h
# 		$(CC) $(CFLAGS) translating_calculating/calculate_reverse_polish_notation_test.c -o $(BUILDIR)/calculate_reverse_polish_notation_test.o 


# $(BUILDIR)/calculate_reverse_polish_notation.o: translating_calculating/calculate_reverse_polish_notation.c translating_calculating/calculate_reverse_polish_notation.h translating_calculating/calculation_error_codes.h
# 		$(CC) $(CFLAGS) translating_calculating/calculate_reverse_polish_notation.c -o $(BUILDIR)/calculate_reverse_polish_notation.o


# $(BUILDIR)/parse_to_lexemes.o: parsing_expression/parse_to_lexemes.c parsing_expression/parse_to_lexemes.h
# 		$(CC) $(CFLAGS) parsing_expression/parse_to_lexemes.c -o $(BUILDIR)/parse_to_lexemes.o


# $(BUILDIR)/parse_to_lexemes_test.o: parsing_expression/parse_to_lexemes_test.c parsing_expression/parse_to_lexemes_test.h
# 		$(CC) $(CFLAGS) parsing_expression/parse_to_lexemes_test.c -o $(BUILDIR)/parse_to_lexemes_test.o


# $(BUILDIR)/string_to_int_test.o: parsing_expression/string_to_int_test.c parsing_expression/string_to_int_test.h parsing_expression/string_to_number_error_codes.h
# 		$(CC) $(CFLAGS) parsing_expression/string_to_int_test.c -o $(BUILDIR)/string_to_int_test.o


# $(BUILDIR)/string_to_int.o: parsing_expression/string_to_int.c parsing_expression/string_to_int.h parsing_expression/string_to_number_error_codes.h
# 		$(CC) $(CFLAGS) parsing_expression/string_to_int.c -o $(BUILDIR)/string_to_int.o


# $(BUILDIR)/string_to_double_test.o: parsing_expression/string_to_double_test.c parsing_expression/string_to_double_test.h parsing_expression/string_to_number_error_codes.h
# 		$(CC) $(CFLAGS) parsing_expression/string_to_double_test.c -o $(BUILDIR)/string_to_double_test.o


# $(BUILDIR)/string_to_double.o: parsing_expression/string_to_double.c parsing_expression/string_to_double.h parsing_expression/string_to_number_error_codes.h
# 		$(CC) $(CFLAGS) parsing_expression/string_to_double.c -o $(BUILDIR)/string_to_double.o


# $(BUILDIR)/recognize_lexemes.o: parsing_expression/recognize_lexemes.c parsing_expression/recognize_lexemes.h
# 		$(CC) $(CFLAGS) parsing_expression/recognize_lexemes.c -o $(BUILDIR)/recognize_lexemes.o


# $(BUILDIR)/create_lexemes.o: parsing_expression/create_lexemes.c parsing_expression/create_lexemes.h
# 		$(CC) $(CFLAGS) parsing_expression/create_lexemes.c -o $(BUILDIR)/create_lexemes.o


# $(BUILDIR)/check_expression_and_count_lexemes.o: parsing_expression/check_expression_and_count_lexemes.c parsing_expression/check_expression_and_count_lexemes.h
# 		$(CC) $(CFLAGS) parsing_expression/check_expression_and_count_lexemes.c -o $(BUILDIR)/check_expression_and_count_lexemes.o


# $(BUILDIR)/check_expression_and_count_lexemes_test.o: parsing_expression/check_expression_and_count_lexemes_test.c parsing_expression/check_expression_and_count_lexemes_test.h
# 		$(CC) $(CFLAGS) parsing_expression/check_expression_and_count_lexemes_test.c -o $(BUILDIR)/check_expression_and_count_lexemes_test.o


# $(BUILDIR)/drawing.o: drawing/drawing.c drawing/drawing.h
# 		$(CC) $(CFLAGS) drawing/drawing.c -o $(BUILDIR)/drawing.o



# $(BUILDIR)/allocate_deallocate_field.o: field/allocate_deallocate_field.c field/allocate_deallocate_field.h
# 		$(CC) $(CFLAGS) field/allocate_deallocate_field.c -o $(BUILDIR)/allocate_deallocate_field.o


clean:
		rm -rf $(BUILDIR)/*.o $(BUILDIR)/*.exe


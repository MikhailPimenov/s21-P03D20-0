CC=gcc
CFLAGS=-c -Wall -Werror -Wextra -std=c11

BUILD=../build


# all: $(BUILD)/graph.exe


# run: $(BUILD)/graph.exe
		# $(BUILD)/graph.exe	


test: $(BUILD)/graph_test.exe
		$(BUILD)/graph_test.exe	


# $(BUILD)/graph.exe: $(BUILD)/translating.o $(BUILD)/graph.o $(BUILD)/shunting_yard.o $(BUILD)/stack.o $(BUILD)/lexeme.o
		# $(CC) $(BUILD)/graph.o $(BUILD)/translating.o  $(BUILD)/shunting_yard.o $(BUILD)/stack.o $(BUILD)/lexeme.o -o $(BUILD)/graph.exe


$(BUILD)/graph_test.exe: $(BUILD)/graph_test.o $(BUILD)/lexeme.o $(BUILD)/lexeme_test.o $(BUILD)/stack_lexeme.o $(BUILD)/stack_lexeme_test.o $(BUILD)/shunting_yard.o $(BUILD)/shunting_yard_test.o $(BUILD)/common.o $(BUILD)/calculate_reverse_polish_notation.o $(BUILD)/calculate_reverse_polish_notation_test.o $(BUILD)/parse_to_lexemes.o $(BUILD)/parse_to_lexemes_test.o $(BUILD)/string_to_int.o $(BUILD)/string_to_int_test.o $(BUILD)/string_to_double.o $(BUILD)/string_to_double_test.o $(BUILD)/recognize_lexemes.o
		$(CC) $(BUILD)/graph_test.o $(BUILD)/lexeme.o $(BUILD)/lexeme_test.o $(BUILD)/stack_lexeme.o $(BUILD)/stack_lexeme_test.o $(BUILD)/shunting_yard.o $(BUILD)/shunting_yard_test.o $(BUILD)/common.o $(BUILD)/calculate_reverse_polish_notation.o $(BUILD)/calculate_reverse_polish_notation_test.o $(BUILD)/parse_to_lexemes.o $(BUILD)/parse_to_lexemes_test.o $(BUILD)/string_to_int.o $(BUILD)/string_to_int_test.o $(BUILD)/string_to_double.o $(BUILD)/string_to_double_test.o $(BUILD)/recognize_lexemes.o -o $(BUILD)/graph_test.exe


$(BUILD)/graph_test.o: graph.c
		$(CC) $(CFLAGS) graph.c -D TEST_GRAPH_ -o $(BUILD)/graph_test.o


$(BUILD)/stack_lexeme.o: data_structures/stack.c data_structures/stack.h
		$(CC) $(CFLAGS) data_structures/stack.c -D LEXEME_T_ -o $(BUILD)/stack_lexeme.o


$(BUILD)/stack_lexeme_test.o: data_structures/stack_test.c data_structures/stack_test.h
		$(CC) $(CFLAGS) data_structures/stack_test.c -D LEXEME_T_ -o $(BUILD)/stack_lexeme_test.o


$(BUILD)/graph.o: graph.c
		$(CC) $(CFLAGS) graph.c -o $(BUILD)/graph.o


# $(BUILD)/translating.o: translating_calculating/translating.c
		# $(CC) $(CFLAGS) translating_calculating/translating.c -o $(BUILD)/translating.o


$(BUILD)/shunting_yard_test.o: translating_calculating/shunting_yard_test.c translating_calculating/shunting_yard_test.h
		$(CC) $(CFLAGS) translating_calculating/shunting_yard_test.c -o $(BUILD)/shunting_yard_test.o


$(BUILD)/shunting_yard.o: translating_calculating/shunting_yard.c translating_calculating/shunting_yard.h
		$(CC) $(CFLAGS) translating_calculating/shunting_yard.c -o $(BUILD)/shunting_yard.o


# $(BUILD)/stack.o: data_structures/stack.c
		# $(CC) $(CFLAGS) data_structures/stack.c -o $(BUILD)/stack.o


$(BUILD)/lexeme.o: data_structures/lexeme.c data_structures/lexeme.h
		$(CC) $(CFLAGS) data_structures/lexeme.c -o $(BUILD)/lexeme.o


$(BUILD)/lexeme_test.o: data_structures/lexeme_test.c data_structures/lexeme_test.h
		$(CC) $(CFLAGS) data_structures/lexeme_test.c -o $(BUILD)/lexeme_test.o


$(BUILD)/common.o: translating_calculating/common.c translating_calculating/common.h
		$(CC) $(CFLAGS) translating_calculating/common.c -o $(BUILD)/common.o


$(BUILD)/calculate_reverse_polish_notation_test.o: translating_calculating/calculate_reverse_polish_notation_test.c translating_calculating/calculate_reverse_polish_notation_test.h
		$(CC) $(CFLAGS) translating_calculating/calculate_reverse_polish_notation_test.c -o $(BUILD)/calculate_reverse_polish_notation_test.o 


$(BUILD)/calculate_reverse_polish_notation.o: translating_calculating/calculate_reverse_polish_notation.c translating_calculating/calculate_reverse_polish_notation.h
		$(CC) $(CFLAGS) translating_calculating/calculate_reverse_polish_notation.c -o $(BUILD)/calculate_reverse_polish_notation.o


$(BUILD)/parse_to_lexemes.o: parsing_expression/parse_to_lexemes.c parsing_expression/parse_to_lexemes.h
		$(CC) $(CFLAGS) parsing_expression/parse_to_lexemes.c -o $(BUILD)/parse_to_lexemes.o


$(BUILD)/parse_to_lexemes_test.o: parsing_expression/parse_to_lexemes_test.c parsing_expression/parse_to_lexemes_test.h
		$(CC) $(CFLAGS) parsing_expression/parse_to_lexemes_test.c -o $(BUILD)/parse_to_lexemes_test.o


$(BUILD)/string_to_int_test.o: parsing_expression/string_to_int_test.c parsing_expression/string_to_int_test.h parsing_expression/string_to_number_error_codes.h
		$(CC) $(CFLAGS) parsing_expression/string_to_int_test.c -o $(BUILD)/string_to_int_test.o


$(BUILD)/string_to_int.o: parsing_expression/string_to_int.c parsing_expression/string_to_int.h parsing_expression/string_to_number_error_codes.h
		$(CC) $(CFLAGS) parsing_expression/string_to_int.c -o $(BUILD)/string_to_int.o


$(BUILD)/string_to_double_test.o: parsing_expression/string_to_double_test.c parsing_expression/string_to_double_test.h parsing_expression/string_to_number_error_codes.h
		$(CC) $(CFLAGS) parsing_expression/string_to_double_test.c -o $(BUILD)/string_to_double_test.o


$(BUILD)/string_to_double.o: parsing_expression/string_to_double.c parsing_expression/string_to_double.h parsing_expression/string_to_number_error_codes.h
		$(CC) $(CFLAGS) parsing_expression/string_to_double.c -o $(BUILD)/string_to_double.o


$(BUILD)/recognize_lexemes.o: parsing_expression/recognize_lexemes.c parsing_expression/recognize_lexemes.h
		$(CC) $(CFLAGS) parsing_expression/recognize_lexemes.c -o $(BUILD)/recognize_lexemes.o




clean:
		rm -rf $(BUILD)/*.o $(BUILD)/*.exe


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


$(BUILD)/graph_test.exe: $(BUILD)/graph_test.o $(BUILD)/lexeme.o $(BUILD)/lexeme_test.o $(BUILD)/stack_lexeme.o $(BUILD)/stack_lexeme_test.o $(BUILD)/shunting_yard.o $(BUILD)/shunting_yard_test.o $(BUILD)/common.o $(BUILD)/calculate_reverse_polish_notation.o $(BUILD)/calculate_reverse_polish_notation_test.o
		$(CC) $(BUILD)/graph_test.o $(BUILD)/lexeme.o $(BUILD)/lexeme_test.o $(BUILD)/stack_lexeme.o $(BUILD)/stack_lexeme_test.o $(BUILD)/shunting_yard.o $(BUILD)/shunting_yard_test.o $(BUILD)/common.o $(BUILD)/calculate_reverse_polish_notation.o $(BUILD)/calculate_reverse_polish_notation_test.o -o $(BUILD)/graph_test.exe


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




clean:
		rm -rf $(BUILD)/*.o $(BUILD)/*.exe


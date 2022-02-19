CC=gcc
CFLAGS=-c -Wall -Werror -Wextra -std=c11

BUILD=../build

all: $(BUILD)/graph

run:
		$(BUILD)/graph	


$(BUILD)/graph: $(BUILD)/translating.o $(BUILD)/graph.o $(BUILD)/shunting_yard_test.o $(BUILD)/shunting_yard.o $(BUILD)/stack.o
		$(CC) $(BUILD)/graph.o $(BUILD)/translating.o $(BUILD)/shunting_yard_test.o $(BUILD)/shunting_yard.o $(BUILD)/stack.o -o $(BUILD)/graph


$(BUILD)/graph.o: graph.c
		$(CC) $(CFLAGS) graph.c -o $(BUILD)/graph.o


$(BUILD)/translating.o: translating_calculating/translating.c
		$(CC) $(CFLAGS) translating_calculating/translating.c -o $(BUILD)/translating.o


$(BUILD)/shunting_yard_test.o: translating_calculating/shunting_yard_test.c
		$(CC) $(CFLAGS) translating_calculating/shunting_yard_test.c -o $(BUILD)/shunting_yard_test.o


$(BUILD)/shunting_yard.o: translating_calculating/shunting_yard.c
		$(CC) $(CFLAGS) translating_calculating/shunting_yard.c -o $(BUILD)/shunting_yard.o


$(BUILD)/stack.o: data_structures/stack.c
		$(CC) $(CFLAGS) data_structures/stack.c -o $(BUILD)/stack.o


clean:
		rm -rf $(BUILD)/*.o $(BUILD)/graph


CC=gcc
CFLAGS=-c -Wall -Werror -Wextra -std=c11

BUILD=../build

all: $(BUILD)/graph



$(BUILD)/graph: $(BUILD)/translating.o $(BUILD)/graph.o
		$(CC) $(BUILD)/graph.o $(BUILD)/translating.o -o $(BUILD)/graph


$(BUILD)/graph.o: graph.c
		$(CC) $(CFLAGS) graph.c -o $(BUILD)/graph.o


$(BUILD)/translating.o:
		$(CC) $(CFLAGS) translating_calculating/translating.c -o $(BUILD)/translating.o
CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11 -c
# DEPFLAGS=-MT $@ -MMD -MP -MF $(DEPENDENCY_DIRECTORY)/$*.d



SOURCE_DIRECTORIES=. data_structures field translating_calculating drawing parsing_expression
BUILD_DIRECTORY=../build
TARGET=$(BUILD_DIRECTORY)/graph.exe
# DEPENDENCY_DIRECTORY=../dependencies
# DEPENDENCY_FILES=$(SOURCE_FILES_ALL:%.c=$(DEPENDENCY_DIRECTORY)/%.d)


SOURCE_FILES_ALL=$(foreach directory_as_variable, $(SOURCE_DIRECTORIES),$(wildcard $(directory_as_variable)/*.c))
# DEPENDENCY_FILES=$(patsubst %.o,%.d,$(SOURCE_FILES_ALL))




OBJECT_FILES_ALL_IN_SOURCE_DIRECTORIES=$(patsubst %.c,%.o,$(SOURCE_FILES_ALL))
OBJECT_FILES_ALL_IN_BUILD_DIRECTORIES=$(addprefix $(BUILD_DIRECTORY)/,$(OBJECT_FILES_ALL_IN_SOURCE_DIRECTORIES))


all: $(TARGET)


$(TARGET): $(OBJECT_FILES_ALL_IN_BUILD_DIRECTORIES)
		$(CC) -o $@ $^

compile: $(OBJECT_FILES_ALL_IN_BUILD_DIRECTORIES)


# dependency: $(SOURCE_FILES_ALL)

# $(SOURCE_FILES_ALL): 

# deps = $(patsubst %.o,%.d,$(OBJECT_FILES_ALL_IN_BUILD_DIRECTORIES))
# -include $(deps)

# DEPFLAGS = -MMD -MF $(@:.o=.d)


$(OBJECT_FILES_ALL_IN_BUILD_DIRECTORIES): $(BUILD_DIRECTORY)/%.o: %.c
		mkdir -p $(dir $@)
		$(CC) $(CFLAGS) $< -o $@  



# $(DEPENDENCY_DIRECTORY):
		# mkdir -p $@
	    # foreach dependency_directory_as_variable, $(dir $(DEPENDENCY_FILES)) mkdir -p dependency_directory_as_variable




print:
		echo $(OBJECT_FILES_ALL_IN_BUILD_DIRECTORIES)






clean: 
		rm -rf $(BUILD_DIRECTORY)/*


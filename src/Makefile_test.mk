SOURCE_FILES_ALL := $(wildcard */*.c)
SOURCE_FILES     := $(filter-out %_test.c, $(SOURCE_FILES_ALL))



print: 
		echo $(SOURCE_FILES)

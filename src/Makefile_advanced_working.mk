BINARY=bin 

CODEDIRS=. data_structures field translating_calculating drawing parsing_expression 
INCDIRS=. # can be list 

CC=gcc
OPT=-O0 

DEPFLAGS=-MP -MD 
CFLAGS=-Wall -Wextra -g $(foreach D,$(INCDIRS),-I$(D)) $(OPT) $(DEPFLAGS) 
  
CFILES=$(foreach D,$(CODEDIRS),$(wildcard $(D)/*.c)) 

OBJECTS=$(patsubst %.c,%.o,$(CFILES)) 
DEPFILES=$(patsubst %.c,%.d,$(CFILES)) 
  
all: $(BINARY) 
   
$(BINARY): $(OBJECTS) 
	$(CC) -o $@ $^ -lm
 
%.o:%.c 
	$(CC) $(CFLAGS) -c -o $@ $< 
   
clean: 
	rm -rf $(BINARY) $(OBJECTS) $(DEPFILES)

distribute: clean 
	 tar zcvf dist.tgz *

-include $(DEPFILES) 

BINARY=bin 

CODEDIRS=data_structures field translating_calculating drawing parsing_expression 
INCDIRS=. # can be list 

CC=gcc
OPT=-O0 

BUILDIR=../build

DEPFLAGS=-MP -MD 
CFLAGS=-Wall -Wextra -g $(foreach D,$(INCDIRS),-I$(D)) $(OPT) $(DEPFLAGS) 
  
CFILES=$(foreach D,$(CODEDIRS),$(wildcard $(D)/*.c)) 

OBJECTS1=$(patsubst %.c,%.o,$(CFILES))
OBJECTS=$(addprefix $(BUILDIR)/,$(CFILES)) 
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

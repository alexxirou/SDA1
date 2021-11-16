MODE=CONT
OBJECTS= parentheses.o test_pile.o xpile.o
SRC = parentheses.c test_pile.c xpile.c 
ifeq "$(MODE)" "CONT"
OBJECTS += pile_char.o 
else
OBJECTS +=pile_char2.o
endif

all: xpile
xpile : $(OBJECTS)
	gcc-9 -g -D$(MODE) $(OBJECTS) -o  xpile 

$(OBJECTS): %.o:  %.c
	gcc-9 -g -D$(MODE) $< -c -o $@  

clean : 
	rm *.o xpile 


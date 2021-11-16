MODE=CHAINE
OBJECTS= parentheses.o test_pile.o xpile.o
SRC = parentheses.c test_pile.c xpile.c 
ifeq "$(MODE)" "CHAINE"
OBJECTS += pile_char2.o 
SRC += pile_char2.c
else
OBJECTS +=pile_char.o
SRC += pile_char.c
endif

all: xpile
xpile : $(OBJECTS)
	gcc-9 -DMODE $(OBJECTS) -o  xpile 

$(OBJECTS): %.o:  %.c
	gcc-9 -DMODE $< -c -o $@  

clean : 
	rm *.o xpile 


MODE=CIC
OBJECTS= xliste.o test.o
SRC = xliste.c 
ifeq "$(MODE)" "CONT"
OBJECTS += liste.o 
else  
OBJECTS += listec.o 
endif

all: xliste
xliste : $(OBJECTS)
	gcc-9 -g -D$(MODE) $(OBJECTS)  liste.h -o  xliste

$(OBJECTS): %.o:  %.c
	gcc-9 -g -D$(MODE) $< -c -o $@  

clean : 
	rm *.o xliste
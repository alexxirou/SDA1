OBJECTS= xliste.o test.o listed.o
SRC = xliste.c test.c listed.c
MODE= DOU

all: xliste
xliste : $(OBJECTS) listed.h
	gcc-9 -g -D$(MODE) $(OBJECTS)  -o  xliste

$(OBJECTS): %.o:  %.c
	gcc-9 -g -D$(MODE) $< -c -o $@  

clean : 
	rm *.o xliste
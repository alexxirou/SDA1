OBJECTS= TD1.o test.o
SRC = TD1.c test.c 


all: xtest
xtest : $(OBJECTS) 
	gcc -g $(OBJECTS)  -o  xtest

$(OBJECTS): %.o:  %.c
	gcc -g  $< -c -o $@

clean : 
	rm *.o xtest
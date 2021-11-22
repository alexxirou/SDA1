MODE=CIC
OBJECTS= xfile.o test.o
SRC = xfile.c 
ifeq "$(MODE)" "CONT"
OBJECTS += file_int.o 
else
	ifeq "$(MODE)" "CIC"
OBJECTS += file_int3.o 
	else
OBJECTS +=file_int2.o
	endif
endif

all: xfile
xfile : $(OBJECTS)
	gcc-9 -g -D$(MODE) $(OBJECTS) -o  xfile 

$(OBJECTS): %.o:  %.c
	gcc-9 -g -D$(MODE) $< -c -o $@  

clean : 
	rm *.o xfile 
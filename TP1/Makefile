
xpile : pile_char.o testpile.o
	gcc pile_char.o testpile.o -g -o xpile

pile.o : pile_char.h base.h pile_char.c
	gcc -c pile_char.c

testpile.o : pile_char.c testpile.c
	gcc -c testpile.c

clean : 
	rm *.o xpile

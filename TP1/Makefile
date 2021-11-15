all: xpile_char_chaine


xpile_char_chaine : pile_char_chaine.o testpile.o #parentheses.o
	gcc pile_char_chaine.o testpile.o  -g -o xpile_char_chaine

pile_char_chaine.o : pile_char.h base.h pile_char_chaine.c
	gcc -c pile_char_chaine.c

	
# xpile_char_contigu : pile_char_contigu.o testpile.o parentheses.o
# 	gcc pile_char_contigu.o testpile.o parentheses.o -g -o xpile_char_contigu

# pile_char_contigu.o : pile_char.h base.h pile_char_contigu.c
# 	gcc -c pile_char_contigu.c

#parentheses.o: pile_char.h base.h parentheses.c
#gcc -c parentheses.c

testpile.o : pile_char.h base.h testpile.c
	gcc -c testpile.c

clean : 
	rm *.o xpile_char_chaine


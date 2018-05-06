CFLAGS = -Wall -fpic -coverage -lm

testme: testme.c
	gcc testme.c -o testme  $(CFLAGS)
	./testme

clean:
	rm -f *.gcno testme *.out  

CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

unittests.out: unittest1.c unittest2.c unittest3.c dominion.c rngs.c interface.c
	echo "Dominion Unit Test Results:" > unittestresults.out
	echo "Unit Test 1 isGameOver()(unittest1.c):" >> unittestresults.out
	gcc dominion.c rngs.c interface.c unittest1.c -o unittest1 $(CFLAGS)
	unittest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	echo "Unit Test 2 newGame() (unittest2.c):" >> unittestresults.out
	gcc dominion.c rngs.c interface.c unittest2.c -o unittest2 $(CFLAGS)
	unittest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	echo "Unit Test 3 compare() (unittest3.c):" >> unittestresults.out
	gcc dominion.c rngs.c interface.c unittest3.c -o unittest3 $(CFLAGS)
	unittest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out
	echo "Unit Test 4 getCost() (unittest4.c):" >> unittestresults.out
	gcc dominion.c rngs.c interface.c unittest4.c -o unittest4 $(CFLAGS)
	unittest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out


clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe

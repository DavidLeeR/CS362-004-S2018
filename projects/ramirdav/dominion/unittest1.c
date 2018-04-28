/***********************************************************
 * Class: CS 362
 * Assignment: 3 (unit tests)
 * Unit Test: isGameOver() function
 * Author: David Ramirez
 * Date: 4/19/18
 * *********************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

//Unit Test for isGameOver() function
//1. isGameOver() should return 0 (continue game) if called directly after initializing game (ie. when supply cards and province card are full)
//2. isGameOver() should return 1 (game over) if there are 0 province cards left
//3. isGameOver() should return 1 (game over) if there are 3 empty supply piles
//4. isGameOver() should return 1 (game over) if there are over 3 supply piles
//5. isGameOver() should return 0 (game continues) if there are 2 empty supply piles
int main() 
{
    int seed = 1000;
    int k[10] = {adventurer, baron, council_room, feast, gardens, great_hall, mine, remodel, smithy, village};
    int playerCount = 2;
    int initCheck;
    int tester;
    struct gameState G;

    initCheck = initializeGame(playerCount, k, seed, &G);

    //part 1.
    tester = isGameOver(&G);
    printf("Unit Test 1, part 1...  expected result: isGameOver() == 0 , actual result: isGameOver() == %d\n", tester);     
    assert(tester == 0);            //isGameOver() should return 0 to show that the game should continue


    //part 2.
    G->supplyCount[province] = 0;

    tester = isGameOver(&G);
    printf("Unit Test 1, part 2...  expected result: isGameOver() == 1 , actual result: isGameOver == %d\n", tester);  
    assert(tester == 1)             //isGameOver() should return 1 to show that the game should end

    //part 3.
    

    return 0;

}

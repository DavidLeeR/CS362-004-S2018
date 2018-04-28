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
//1. isGameOver() should return 1 (game over) if there are 0 province cards left
//2. isGameOver() should return 1 (game over) if there are 3 empty supply piles
//3. isGameOver() should return 1 (game over) if there are over 3 supply piles
//3. isGameOver() should return 0 (game continues) if there are 2 empty supply piles
int main() 
{
    int seed = 1000;
    int k[10] = {adventurer, baron, council_room, feast, gardens, great_hall, mine, remodel, smithy, village};
    int playerCount = 2;
    int initCheck;
    int tester;
    struct gamestate G;

    initCheck = initializeGame(playerCount, k, seed, &G);
    assert(initCheck == 0);

    tester = isGameOver(&G);     
    assert(tester == 0);            //isGameOver() should return 0 to show that the game should continue

   // G->supplyCount[province] = 0;

}
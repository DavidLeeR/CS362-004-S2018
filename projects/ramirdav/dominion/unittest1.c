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
    int tester;
    struct gameState G1, G2, G3, G4a, G4b, G5;
    int testSum = 0;
    int testTotal = 6;



    //part 1: check if 0 is returned after inititializing game
    initializeGame(playerCount, k, seed, &G1);

    tester = isGameOver(&G1);
    printf("Unit Test 1, part 1 (call function after initialization)... \n     expected result: isGameOver() == 0\n     actual result: isGameOver() == %d\n", tester);     
    if(tester == 0)
        testSum++;



    //part 2: check if 1 is returned when the number of province cards reaches 0
    initializeGame(playerCount, k, seed, &G2);

    G2.supplyCount[province] = 0;

    tester = isGameOver(&G2);
    printf("Unit Test 1, part 2 (call function after province cards = 0)... \n     expected result: isGameOver() == 1\n     actual result: isGameOver == %d\n", tester);  
    if(tester == 1)
        testSum++;



    //part 3: check if 1 is returned when the number of 3 types of supply cards reaches 0
    initializeGame(playerCount, k, seed, &G3);

    G3.supplyCount[1] = 0;
    G3.supplyCount[2] = 0;
    G3.supplyCount[3] = 0;

    tester = isGameOver(&G3);
    printf("Unit Test 1, part 3 (call function after 3 types of supply cards = 0)... \n     expected result: isGameOver() == 1\n     actual result: isGameOver == %d\n", tester);
    if(tester == 1)
        testSum++;



    //part 4.a: check if 1 is returned when the number of 4 types of supply cards reaches 0
    initializeGame(playerCount, k, seed, &G4a);

    G4a.supplyCount[1] = 0;
    G4a.supplyCount[2] = 0;
    G4a.supplyCount[3] = 0;
    G4a.supplyCount[4] = 0;

    tester = isGameOver(&G4a);
    printf("Unit Test 1, part 4.a (call function after 4 types of supply cards = 0)... \n     expected result: isGameOver() == 1\n     actual result: isGameOver == %d\n", tester);
    if(tester == 1)
        testSum++;



    //part 4.b: check if 1 is returned when the number of 5 types of supply cards reaches 0
    initializeGame(playerCount, k, seed, &G4b);
    
    G4b.supplyCount[1] = 0;
    G4b.supplyCount[2] = 0;
    G4b.supplyCount[3] = 0;
    G4b.supplyCount[4] = 0;
    G4b.supplyCount[5] = 0;

    tester = isGameOver(&G4b);
    printf("Unit Test 1, part 4.b (call function after 4 types of supply cards = 0)... \n     expected result: isGameOver() == 1\n     actual result: isGameOver == %d\n", tester);
    if(tester == 1)
    testSum++;


    
    //part 5: check if 0 is returned when the number of 2 types of supply cards reaches 0
    initializeGame(playerCount, k, seed, &G5);
    
    G5.supplyCount[1] = 0;
    G5.supplyCount[2] = 0;

    tester = isGameOver(&G5);
    printf("Unit Test 1, part 5 (call function after 2 types of supply cards = 0)... \n     expected result: isGameOver() == 0\n     actual result: isGameOver == %d\n", tester);
    if(tester == 0)
    testSum++;



    if (testSum < testTotal)
    {
        int testFails = testTotal - testSum;
        printf("Unit Test 1 failed %d test cases \n", testFails);
    }
    else if (testSum == testTotal)
        printf("Unit Test 1 passed all test cases \n");



    return 0;

}

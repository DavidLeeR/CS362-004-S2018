/***********************************************************
 * Class: CS 362
 * Assignment: 3 (card tests)
 * Card Test 1: Smithy card
 * Author: David Ramirez
 * Date: 4/29/18
 * *********************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

//Card Test 1: Smithy Card
//1. current player's hand should increase by exactly 3 cards
//2. The 3 in test case 1 should come from the same player's pile
//3. there should be no state change for other players
//4. there should be no state change for the victory card piles or the kingdom card piles
int main() 
{
    int seed = 1000;        //seed for random numbers
    int k[10] = {adventurer, baron, council_room, feast, gardens, great_hall, mine, remodel, smithy, village};      //kingdom cards
    int playerCount = 2;
    int result;     //tracks return value of isGameOver()
    struct gameState G;      //6 different gameStates for 6 test cases
    int testSum = 0;        //keeps track of passed test cases
    int testTotal = 6;      //number of total test cases

    printf("\n\n\n******************Starting Card Test 1: Smithy card******************\n");            
    /***************************************************************************************
     *PART 1: check if 0 is returned after inititializing game                             *
     ***************************************************************************************/
    initializeGame(playerCount, k, seed, &G);

    result = isGameOver(&G);

    if(result == 0)
    {
        printf("Unit Test 1, part 1 (isGameOver() should return 0 (continue) after game initialization)... \n     PASS\n     expected result: isGameOver() == 0\n     actual result: isGameOver() == %d\n", result);  
        testSum++;
    }
    else if(result != 0)
    {
        printf("Unit Test 1, part 1 (isGameOver() should return 0 (continue) after game initialization)... \n     FAIL\n     expected result: isGameOver() == 0\n     actual result: isGameOver() == %d\n", result);  
    }



    /***************************************************************************************
     *                         OUTPUT TOTAL UNIT TEST RESULTS                              *
     ***************************************************************************************/
    //if not all the test cases passed, output number of failed tests
    if (testSum < testTotal)
    {
        int testFails = testTotal - testSum;
        printf("Unit Test 1 failed %d out of 6 test cases \n", testFails);
    }
    //if all test cases passed, output success message
    else if (testSum == testTotal)
        printf("Unit Test 1 passed all 6 test cases \n");



    return 0;

}

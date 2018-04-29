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
    int playerCount = 3;
    int result;     //tracks return value of isGameOver()
    struct gameState G;      //6 different gameStates for 6 test cases
    int testSum = 0;        //keeps track of passed test cases
    int testTotal = 1;      //number of total test cases
    int cardIndex;
    int oldHandCount;
    int newHandCount;
    int cardsGained;

    printf("\n\n\n******************Starting Card Test 1: Smithy card******************\n");            
    /***************************************************************************************
     *PART 1: check if current player's hand increases by exactly 3 cards                  *
     ***************************************************************************************/
    initializeGame(playerCount, k, seed, &G);
    
    cardIndex = G.handCount[0];
    G.hand[0][cardIndex] = smithy;   //add smithy to hand
    G.handCount[0]++;
    oldHandCount = G.handCount[0];

    playCard(cardIndex,1, 1, 1, &G);

    newHandCount = G.handCount[0];
    cardsGained = newHandCount - oldHandCount;

    //if exactly 3 cards were drawn after the smithy card was played, test passes
    if(cardsGained == 3)
    {
        printf("Card Test 1, part 1 (player should gain 3 cards in their hand)... \n     PASS\n     expected result: cards gained == 3\n     actual result: cards gained == 3\n");  
        testSum++;
    }
    else if(cardsGained != 3)
    {
        printf("Cards Test 1, part 1 (player should gain 3 cards in their hand)... \n     FAIL\n     expected result: cards gained == 3\n     actual result: cards gained == %d\n", cardsGained);  
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

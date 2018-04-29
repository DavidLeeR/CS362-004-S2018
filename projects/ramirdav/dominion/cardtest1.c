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
    //variables for test part 1
    int oldHandCount;
    int newHandCount;
    int cardsGained;
    //variables for test part 2
    int oldDeckCount;
    int newDeckCount;
    int cardsRemoved;
    //variables for test part 3
    int oldHandCount3;
    int newHandCount3;
    //variables for test part 4
    int oldHandCount4;
    int newHandCount4;

    printf("\n\n\n******************Starting Card Test 1: Smithy card******************\n");   
    /*******************************************************************************************************************
     *SETUP: initalize game, give player 1 Smithy card, and record each player's hand size before using Smithy card    *
     *******************************************************************************************************************/     
    initializeGame(playerCount, k, seed, &G);    

    cardIndex = G.handCount[0];      //save size of hand as index of smithy card

    G.hand[0][cardIndex] = smithy;   //add smithy to hand of player 1
    G.handCount[0]++;

    oldHandCount = G.handCount[0];
    oldDeckCount = G.deckCount[0];

    /***************************************************************************************
     *PART 1: check if player 1's hand increases by exactly 3 cards after playing Smithy   *
     ***************************************************************************************/
    playCard(cardIndex,1, 1, 1, &G);

    newHandCount = G.handCount[0];
    cardsGained = newHandCount - oldHandCount;

    //if exactly 3 cards were drawn to player 1's hand after the smithy card was played, test passes
    if(cardsGained == 3)
    {
        printf("Card Test 1, part 1 (player 1 should gain 3 cards in their hand)... \n     PASS\n     expected result: cards gained == 3\n     actual result: cards gained == 3\n");  
        testSum++;
    }
    else if(cardsGained != 3)
    {
        printf("Cards Test 1, part 1 (player 1 should gain 3 cards in their hand)... \n     FAIL\n     expected result: cards gained == 3\n     actual result: cards gained == %d\n", cardsGained);  
    }


    /***************************************************************************************
     *PART 2: check if the 3 cards drawn in PART 1 were from player 1's deck               *
     ***************************************************************************************/
    newDeckCount = G.deckCount[0];
    cardsRemoved = newDeckCount - oldDeckCount;


    //if exactly 3 cards were removed from player 1's deck after the smithy card was played, test passes
    if(cardsRemoved == 3)
    {
        printf("Card Test 1, part 2 (player 1 should have 3 cards removed from deck)... \n     PASS\n     expected result: cards removed == 3\n     actual result: cards removed == 3\n");  
        testSum++;
    }
    else if(cardsGained != 3)
    {
        printf("Cards Test 1, part 2 (player 1 should have 3 cards removed from deck)... \n     FAIL\n     expected result: cards removed == 3\n     actual result: cards removed == %d\n", cardsRemoved);  
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

/***********************************************************
 * Class: CS 362
 * Assignment: 3 (card tests)
 * Card Test 2: Adventurer card
 * Author: David Ramirez
 * Date: 4/29/18
 * *********************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

//Card Test 2: Adventurer card
//1. exactly 2 treasure cards should be added to player 1's hand after playing Adventurer card
//2. the discarded cards and the 2 treasure cards should come from player 1's supply pile
//3. there should be no state change for other players
//4. there should be no state change for the victory card piles or the kingdom card piles
int main() 
{
    int seed = 1000;        //seed for random numbers
    int k[10] = {adventurer, baron, council_room, feast, gardens, great_hall, mine, remodel, smithy, village};      //kingdom cards
    int playerCount = 3;
    struct gameState G;      
    int testSum = 0;        //keeps track of passed test cases
    int testTotal = 4;      //number of total test cases
    int cardIndex;
    //variables for test part 1
    int oldTreasureCount = 0;
    int newTreasureCount = 0;
    int oldHandCount;
    int newHandCount;
    int cardsGained;
    int treasureGained;

    int oldDeckCount;
    int oldHandCount2;
    int oldDeckCount2;
    int oldHandCount3;
    int oldDeckCount3;
 


    printf("\n\n\n******************Starting Card Test 1: Smithy card******************\n");   
    /*******************************************************************************************************************
     *SETUP: initalize game, give player 1 Adventurer card, and record each player's hand size before using Adventurer card    *
     *******************************************************************************************************************/     
    initializeGame(playerCount, k, seed, &G);    

    cardIndex = G.handCount[0];      //save size of hand as index of adventurer card

    G.hand[0][cardIndex] = adventurer;   //add adventurer card to hand of player 1
    G.handCount[0]++;

    //record hand and deck counts for all players before player 1 plays Adventurer card
    oldHandCount = G.handCount[0];      
    oldDeckCount = G.deckCount[0];
    oldHandCount2 = G.handCount[1];
    oldDeckCount2 = G.deckCount[1];
    oldHandCount3 = G.handCount[2];
    oldDeckCount3 = G.deckCount[2];

    //record number of treasure cards for player 1 before playing adventurer card
    int j = 0;
    for(j; j < oldHandCount; j++)
    {
        if(G.hand[0][j] == copper || G.hand[0][j] == silver || G.hand[0][j] == gold) 
            oldTreasureCount++;
    }

    /****************************************************************************************************
     *PART 1: check if player 1's hand increases by exactly 2 treasure cards after playing Adventurer   *
     ****************************************************************************************************/
    playCard(cardIndex,1, 1, 1, &G);

    newHandCount = G.handCount[0];
    cardsGained = newHandCount - oldHandCount;

    int i = 0;
    for(i; i < newHandCount; i++)
    {
        if(G.hand[0][i] == copper || G.hand[0][i] == silver || G.hand[0][i] == gold) 
            newTreasureCount++;
    }

    treasureGained = newTreasureCount - oldTreasureCount;

    //if exactly 2 treasure cards were drawn to player 1's hand after playing Adventurer card, test passes
    //note*: cardsGained is set to 1 because we must take into account discarding the Adventurer card after playing it
    if(cardsGained == 1 && treasureGained == 2)
    {
        printf("Card Test 2, part 1 (player 1 should gain 2 treasure cards)... \n     PASS\n     expected result: treasure cards gained == 2\n     actual result: treasure cards gained == 2\n");  
        testSum++;
    }
    else if(cardsGained != 2)
    {
        printf("Cards Test 2, part 1 (player 1 should gain 2 treasure cards)... \n     FAIL\n     expected result: treasure cards gained == 2\n     actual result: cards gained == %d, treasure cards gained == %d\n", cardsGained, treasureGained);  
    }





    /***************************************************************************************
     *                         OUTPUT TOTAL UNIT TEST RESULTS                              *
     ***************************************************************************************/
    //if not all the test cases passed, output number of failed tests
    if (testSum < testTotal)
    {
        int testFails = testTotal - testSum;
        printf("Unit Test 1 failed %d out of 4 test cases \n", testFails);
    }
    //if all test cases passed, output success message
    else if (testSum == testTotal)
        printf("Unit Test 1 passed all 4 test cases \n");



    return 0;

}

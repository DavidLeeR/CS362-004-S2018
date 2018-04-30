/***********************************************************
 * Class: CS 362
 * Assignment: 3 (card tests)
 * Card Test 3: Great Hall card
 * Author: David Ramirez
 * Date: 4/29/18
 * *********************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

//Card Test 3: Great Hall card
//1. exactly 1 card should be drawn into player 1's hand after playing great_hall card
//2. player 1 should gain exactly 1 action point after playing great hall card
//3. the drawn card should come from player 1's supply pile
//4. there should be no state change for other players
//5. there should be no state change for victory/kingdom card piles
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
    int oldHandCount;
    int newHandCount;
    int cardsGained;
    //variables for test part 2
    int actionPoints;
    //variables for test part 3
    int oldDeckCount;
    int newDeckCount;
    int cardsRemoved;

    int oldDeckCount2;
    int newDeckCount2;
    int oldHandCount2;
    int newHandCount2;
    int oldDeckCount3;
    int newDeckCount3;
    int oldHandCount3;
    int newHandCount3;
    int cardsGained2;
    int cardsGained3;
    int cardsRemoved2;
    int cardsRemoved3;
    //variables for test part 4
    int oldVictoryCount = 36;
    int newVictoryCount = 0;
    int victoryChange;
    int oldKingdomCount = 104;
    int newKingdomCount = 0;
    int kingdomChange;


    printf("\n\n\n******************Starting Card Test 1: Smithy card******************\n");   
    /***************************************************************************************************************************
     *SETUP: initalize game, give player 1 great_hall card, and record each player's hand size before using great_hall card    *
     ***************************************************************************************************************************/     
    initializeGame(playerCount, k, seed, &G);    

    cardIndex = G.handCount[0];      //save size of hand as index of great_hall card

    G.hand[0][cardIndex] = great_hall;   //add great_hall to hand of player 1
    G.handCount[0]++;

    //record hand and deck counts for all players before player 1 plays great_hall card
    oldHandCount = G.handCount[0];      
    oldDeckCount = G.deckCount[0];
    oldHandCount2 = G.handCount[1];
    oldDeckCount2 = G.deckCount[1];
    oldHandCount3 = G.handCount[2];
    oldDeckCount3 = G.deckCount[2];

    /**************************************************************************************************************************************
     *PART 1: check if player 1's hand increases by exactly 1 cards after playing great_hall (accounting for great_hall being discarded)  *
     **************************************************************************************************************************************/
    playCard(cardIndex,-1, -1, -1, &G);

    newHandCount = G.handCount[0];
    cardsGained = newHandCount - oldHandCount;

    //if exactly 2 cards were drawn to player 1's hand after the smithy card was played, test passes
    //note*: this is 0 to account for discarding great_hall
    if(cardsGained == 0)
    {
        printf("Card Test 1, part 1 (player 1 should gain 1 cards in their hand)... \n     PASS\n     expected result: cards gained == 1\n     actual result: cards gained == 1\n");  
        testSum++;
    }
    else if(cardsGained != 0)
    {
        printf("Cards Test 1, part 1 (player 1 should gain 3 cards in their hand)... \n     FAIL\n     expected result: cards gained == 1\n     actual result: cards gained == %d\n", cardsGained+1);  
    }


     /**************************************************************************************
     *PART 2: check player 1 gained 1 action point after playing great_hall                *
     ***************************************************************************************/
    actionPoints = G.numActions;

    //if exactly 1 action point was added to player 1 after the great_hall card was played, test passes
    if(actionPoints == 1)
    {
        printf("Card Test 1, part 2 (player 1 should gain 1 action point)... \n     PASS\n     expected result: action points gained == 1\n     actual result: action points gained == 1\n");  
        testSum++;
    }
    else if(cardsGained != 0)
    {
        printf("Cards Test 1, part 2 (player 1 should gain 1 action point)... \n     FAIL\n     expected result: action points gained == 1\n     actual result: action points gained == %d\n", actionPoints);  
    }

    /***************************************************************************************
     *PART 3: check if the 1 card drawn in PART 1 was from player 1's pile                 *
     ***************************************************************************************/
    newDeckCount = G.deckCount[0];
    cardsRemoved = oldDeckCount - newDeckCount;     //number of cards removed from player 1's deck


    //if exactly 1 card was removed from player 1's deck after the great_hall card was played, test passes
    if(cardsRemoved == 3)
    {
        printf("Card Test 1, part 2 (player 1 should have 1 card removed from deck)... \n     PASS\n     expected result: cards removed == 1\n     actual result: cards removed == 1\n");  
        testSum++;
    }
    else if(cardsGained != 3)
    {
        printf("Cards Test 1, part 2 (player 1 should have 1 card removed from deck)... \n     FAIL\n     expected result: cards removed == 1\n     actual result: cards removed == %d\n", cardsRemoved);  
    }


    /***************************************************************************************
     *PART 4: check if there are no state changes to other players deck                    *
     ***************************************************************************************/
    newHandCount2 = G.handCount[1];
    newDeckCount2 = G.deckCount[1];
    newHandCount3 = G.handCount[2];
    newDeckCount3 = G.deckCount[2];

    cardsGained2 = newHandCount2 - oldHandCount2;     //number of cards gained to player 2's hand
    cardsRemoved2 = oldDeckCount2 - newDeckCount2;    //number of cards removed from player 2's deck
    cardsGained3 = newHandCount3 - oldHandCount3;     //number of cards gained to player 3's hand
    cardsRemoved3 = oldDeckCount3 - newDeckCount3;    //number of cards removed from player 3's deck
    


    //if there are no changes to player 2 or player 3's deck and hand then test passes
    if(cardsGained2 == 0 && cardsRemoved2 == 0 && cardsGained3 == 0 && cardsRemoved3 == 0)
    {
        printf("Card Test 3, part 4 (player 2 and 3 should have no deck/hand change)... \n     PASS\n     expected result: p1 gained/removed == 0, p2 gained/removed == 0\n     actual result: p2 gained/removed == 0, p3 gained/removed == 0\n");  
        testSum++;
    }
    else
    {
        printf("Cards Test 3, part 4 (player 2 and 3 should have no deck/hand change)... \n     FAIL\n     expected result: p1 gained/removed == 0, p2 gained/removed == 0\n     actual result: p2 gained == %d, p2 removed == %d, p3 gained == %d, p3 removed == %d\n", cardsGained2, cardsRemoved2, cardsGained3, cardsRemoved3);  
    }



    /***************************************************************************************
     *PART 5: check if there are no state changes to victory and kingdom cards             *
     ***************************************************************************************/
    //count all victory cards after player 1 plays Smithy card
    newVictoryCount += G.supplyCount[estate];
    newVictoryCount += G.supplyCount[duchy];
    newVictoryCount += G.supplyCount[province];

    //for each kingdom card, add the number in supply to the new kingdom card count (ie. after playing Smithy card)
    int i;
    for(i = adventurer; i <= great_hall; i++)
    {
        newKingdomCount += G.supplyCount[i];
    }

    victoryChange = newVictoryCount - oldVictoryCount;
    kingdomChange = newKingdomCount - oldKingdomCount;

    //if there are no changes to the victory card and kingdom card supply then test passes
    if(victoryChange == 0 && kingdomChange == 0)
    {
        printf("Card Test 3, part 5 (there should be no change in victory/kingdom card supply)... \n     PASS\n     expected result: victory/kingdom card supply change == 0\n     actual result: victory/kingdom card supply change == 0\n");  
        testSum++;
    }
    else
    {
        printf("Cards Test 3, part 5 (there should be no change in victory/kingdom card supply)... \n     FAIL\n     expected result: victory/kingdom card supply change == 0\n     actual result: victory card supply change == %d, kingdom card supply change == %d\n", victoryChange, kingdomChange);  
    }



    /***************************************************************************************
     *                         OUTPUT TOTAL UNIT TEST RESULTS                              *
     ***************************************************************************************/
    //if not all the test cases passed, output number of failed tests
    if (testSum < testTotal)
    {
        int testFails = testTotal - testSum;
        printf("Card Test 3 failed %d out of 5 test cases \n", testFails);
    }
    //if all test cases passed, output success message
    else if (testSum == testTotal)
        printf("Card Test 3 passed all 5 test cases \n");



    return 0;

}

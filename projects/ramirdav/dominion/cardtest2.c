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
//4. check if no state change to kingdom/victory card piles
//5. deck should be shuffled if is 0 when using Adventurer
int main() 
{
    
    int seed = 1000;        //seed for random numbers
    int k[10] = {adventurer, baron, council_room, feast, gardens, great_hall, mine, remodel, smithy, village};      //kingdom cards
    int playerCount = 3;
    struct gameState G, G2;      
    int testSum = 0;        //keeps track of passed test cases
    int testTotal = 5;      //number of total test cases
    int cardIndex;
    int cardIndex2;
    //variables for test part 1
    int oldTreasureCount = 0;
    int newTreasureCount = 0;
    int oldHandCount;
    int newHandCount;
    int cardsGained;
    int treasureGained;
    //variables for test part 2
    int numDiscarded;
    int oldDeckCount;
    int newDeckCount;
    int totalFromDeck;
    int deckDiff;
    //variables for test part 3
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
    //variables for test part 5
    int startingCount;
    int afterShuffleCount;
 


    printf("\n\n\n******************Starting Card Test 2: Adventurer card******************\n");   
    /***************************************************************************************************************************
     *SETUP: initalize game, give player 1 Adventurer card, and record each player's hand size before using Adventurer card    *
     ***************************************************************************************************************************/     
    initializeGame(playerCount, k, seed, &G);    
    initializeGame(playerCount, k, seed, &G2);  

    cardIndex = G.handCount[0];      //save size of hand as index of adventurer card
    cardIndex2 = G2.handCount[0];

    G.hand[0][cardIndex] = adventurer;   //add adventurer card to hand of player 1
    G.handCount[0]++;

    G2.hand[0][cardIndex] = adventurer;   //add adventurer card to hand of player 1
    G2.handCount[0]++;

    //record hand and deck counts for all players before player 1 plays Adventurer card
    oldHandCount = G.handCount[0];      
    oldDeckCount = G.deckCount[0];
    oldHandCount2 = G.handCount[1];
    oldDeckCount2 = G.deckCount[1];
    oldHandCount3 = G.handCount[2];
    oldDeckCount3 = G.deckCount[2];

    //record number of treasure cards for player 1 before playing adventurer card
    int j;
    for(j = 0; j < oldHandCount; j++)
    {
        if(G.hand[0][j] == copper || G.hand[0][j] == silver || G.hand[0][j] == gold) 
            oldTreasureCount++;
    }


    /****************************************************************************************************
     *PART 1: check if player 1's hand increases by exactly 2 treasure cards after playing Adventurer   *
     ****************************************************************************************************/
    playCard(cardIndex,-1, -1, -1, &G);

    newHandCount = G.handCount[0];
    cardsGained = newHandCount - oldHandCount;

    int i;
    for(i = 0; i < newHandCount; i++)
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
    else
    {
        printf("Cards Test 2, part 1 (player 1 should gain 2 treasure cards)... \n     FAIL\n     expected result: treasure cards gained == 2\n     actual result: cards gained == %d, treasure cards gained == %d\n", cardsGained, treasureGained);  
    }


    /****************************************************************************************************
     *PART 2: check if cards drawn in STEP 1 came from player 1's supply pile                           *
     ****************************************************************************************************/
    numDiscarded = G.discardCount[0];
    newDeckCount = G.deckCount[0];
    totalFromDeck = numDiscarded + 2;       //the total number of cards from the deck should equal all discarded cards and 2 treasure cards
    deckDiff = oldDeckCount - newDeckCount;

    if(totalFromDeck == deckDiff)
    {
        printf("Card Test 2, part 2 (cards drawn in PART 1 should be from player 1's pile)... \n     PASS\n     expected result: deck difference == # cards added and discarded\n     actual result: deck difference == # cards added and discarded\n");  
        testSum++;
    }
    else
    {
        printf("Cards Test 2, part 2 (cards drawn in PART 1 should be from player 1's pile)... \n     FAIL\n     expected result: deck difference == # cards added and discarded\n     actual result: deck difference == %d, cards added and discarded == %d\n", deckDiff, totalFromDeck);  
    }


    /***************************************************************************************
     *PART 3: check if there are no state changes to other players deck                    *
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
        printf("Card Test 1, part 3 (player 2 and 3 should have no deck/hand change)... \n     PASS\n     expected result: p2 gained/removed == 0, p3 gained/removed == 0\n     actual result: p2 gained/removed == 0, p3 gained/removed == 0\n");  
        testSum++;
    }
    else
    {
        printf("Cards Test 1, part 3 (player 2 and 3 should have no deck/hand change)... \n     FAIL\n     expected result: p2 gained/removed == 0, p3 gained/removed == 0\n     actual result: p2 gained == %d, p2 removed == %d, p3 gained == %d, p3 removed == %d\n", cardsGained2, cardsRemoved2, cardsGained3, cardsRemoved3);  
    }


    /***************************************************************************************
     *PART 4: check if there are no state changes to victory and kingdom cards             *
     ***************************************************************************************/
    //count all victory cards after player 1 plays great_hall card
    newVictoryCount += G.supplyCount[estate];
    newVictoryCount += G.supplyCount[duchy];
    newVictoryCount += G.supplyCount[province];

    //for each kingdom card, add the number in supply to the new kingdom card count (ie. after playing great_hall card)
    int m;
    for(m = adventurer; m <= great_hall; m++)
    {
        newKingdomCount += G.supplyCount[m];
    }

    victoryChange = newVictoryCount - oldVictoryCount;
    kingdomChange = newKingdomCount - oldKingdomCount;

    //if there are no changes to the victory card and kingdom card supply then test passes
    if(victoryChange == 0 && kingdomChange == 0)
    {
        printf("Card Test 3, part 4 (there should be no change in victory/kingdom card supply)... \n     PASS\n     expected result: victory/kingdom card supply change == 0\n     actual result: victory/kingdom card supply change == 0\n");  
        testSum++;
    }
    else
    {
        printf("Cards Test 3, part 4 (there should be no change in victory/kingdom card supply)... \n     FAIL\n     expected result: victory/kingdom card supply change == 0\n     actual result: victory card supply change == %d, kingdom card supply change == %d\n", victoryChange, kingdomChange);  
    }


    /***************************************************************************************
     *PART 5: check if cards shuffle back into deck if deck at 0 when adventurer card used                   *
     ***************************************************************************************/
    startingCount = G2.deckCount[0];

    //transfer all deck cards to discard pile
    int g = 0;
    for(g; g < G2.deckCount[0]; g++)
    {
        G2.discard[0][g] = G2.deck[0][g];
        G2.deck[0][g] = -1;
        G2.discardCount[0]++;
    }

    G2.deckCount[0] = 0;     //set deck to empty

    playCard(cardIndex2,-1, -1, -1, &G2);

    afterShuffleCount = G2.deckCount[0];

    //if there are no changes to the victory card and kingdom card supply then test passes
    if(startingCount == afterShuffleCount)
    {
        printf("Card Test 2, part 5 (deck count before shuffle should equal deck count after shuffle)... \n     PASS\n     expected result: deck count before shuffle == deck count after shuffle\n     actual result: deck count before shuffle == deck count after shuffle\n");  
        testSum++;
    }
    else
    {
        printf("Cards Test 2, part 5 (deck count before shuffle should equal deck count after shuffle)... \n     FAIL\n     expected result: deck count before shuffle == deck count after shuffle\n     actual result: deck count before shuffle == %d, deck count after shuffle == %d\n", startingCount, afterShuffleCount);  
    }


    /***************************************************************************************
     *                         OUTPUT TOTAL UNIT TEST RESULTS                              *
     ***************************************************************************************/
    //if not all the test cases passed, output number of failed tests
    if (testSum < testTotal)
    {
        int testFails = testTotal - testSum;
        printf("Card Test 2 failed %d out of 5 test cases \n", testFails);
    }
    //if all test cases passed, output success message
    else if (testSum == testTotal)
        printf("Card Test 2 passed all 5 test cases \n");



    return 0;

}

//CS 362 Assignment 4
//Author: David Ramirez
//Date: 5/13/18

#include <string.h>
#include <stdio.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "interface.h"



//Random Card Test 2: Village card
//1. player 1's deck should be missing exactly 1 cards after playing village card
//2. exactly 1 card should be drawn into player 1's hand after playing village card
//3. player 1 should gain exactly 2 action points after playing village card
//???????4. there should be no state change for other players
//4. there should be no state change for victory/kingdom card piles

//Global Variables
struct gameState G;
struct gameState G2;
int passes = 0;
int fails = 0;
int handP = 0;
int treas;
int oldDeckCount;
int oldVictoryCount = 36;
int oldKingdomCount = 104;
int oldDiscardCount;
int oldHandCount;



//test part 1: compares the number of cards in the deck before and after playing Village
void deckTesting(int count)
{

    int newDeckCount = G2.deckCount[0];
    int deckDiff = oldDeckCount - newDeckCount;

    if(deckDiff == 1)
    {
		passes++;
        printf("Deck Test # %d passed   \n     # players = %d, hand position = %d,  \n     # actions = %d, # buys = %d,  deck diff = %d\n     p1 deck: %d, p1 discard: %d, p1 handpos: %d\n",count,G2.numPlayers, handP, G2.numActions, G2.numBuys, deckDiff, oldDeckCount, oldDiscardCount, handP);  
    }
    else
    {
		fails++;
        printf("Deck Test # %d failed   \n     # players = %d, hand position = %d,  \n     # actions = %d, # buys = %d, deck diff = %d\n     p1 deck: %d, p1 discard: %d, p1 handpos: %d\n",count,G2.numPlayers, handP, G2.numActions, G2.numBuys, deckDiff,  oldDeckCount, oldDiscardCount, handP);  
    }
}

//test part 2: compares the number of cards in the hand before and after playing Village
void handTesting(int count)
{
    int newHandCount = G2.handCount[0];
    int handDiff = newHandCount - oldHandCount;

    if(handDiff == 1)
    {
		passes++;
        printf("Hand Test # %d passed   \n     # players = %d, hand position = %d,  \n     # actions = %d, # buys = %d,  hand diff = %d\n     p1 deck: %d, p1 discard: %d, p1 handpos: %d\n",count,G2.numPlayers, handP, G2.numActions, G2.numBuys, handDiff, oldDeckCount, oldDiscardCount, handP);  
    }
    else
    {
		fails++;
        printf("Hand Test # %d failed   \n     # players = %d, hand position = %d,  \n     # actions = %d, # buys = %d, hand diff = %d\n     p1 deck: %d, p1 discard: %d, p1 handpos: %d\n",count,G2.numPlayers, handP, G2.numActions, G2.numBuys, handDiff,  oldDeckCount, oldDiscardCount, handP);  
    }
}

//test part 3: calculates number of action points gained (considering 1 being used to play Village)
void actionTesting(int count)
{
	int actionPoints = G.numActions;
	
	//if exactly 2 action points was added to player 1 after the village card was played, test passes
	if(actionPoints == 2)
	{
		passes++;
        printf("Action Point Test # %d passed   \n     # players = %d, hand position = %d,  \n     # actions = %d, # buys = %d,  action points = %d\n     p1 deck: %d, p1 discard: %d, p1 handpos: %d\n",count,G2.numPlayers, handP, G2.numActions, G2.numBuys, actionPoints, oldDeckCount, oldDiscardCount, handP);  
		
	}
	else
	{
		fails++;
		printf("Action Point Test # %d failed   \n     # players = %d, hand position = %d,  \n     # actions = %d, # buys = %d, action points = %d\n     p1 deck: %d, p1 discard: %d, p1 handpos: %d\n",count,G2.numPlayers, handP, G2.numActions, G2.numBuys, actionPoints,  oldDeckCount, oldDiscardCount, handP);  		
	}
}


//test part 4: compares the number of victory and kingdom cards before and after playing Village
void victoryKingdomTesting(int count)
{
	int newKingdomCount = 0;
	int newVictoryCount = 0;
	int victoryChange;
	int kingdomChange;
	//count all victory cards after player 1 plays great_hall card
    newVictoryCount += G2.supplyCount[estate];
    newVictoryCount += G2.supplyCount[duchy];
    newVictoryCount += G2.supplyCount[province];

    //for each kingdom card, add the number in supply to the new kingdom card count (ie. after playing great_hall card)
    int m;
    for(m = adventurer; m <= great_hall; m++)
    {
        newKingdomCount += G2.supplyCount[m];
    }

    victoryChange = newVictoryCount - oldVictoryCount;
    kingdomChange = newKingdomCount - oldKingdomCount;

    //if there are no changes to the victory card and kingdom card supply then test passes
    if(victoryChange == 0 && kingdomChange == 0)
    {
		passes++;
		printf("Victory/Kingdom Card Test # %d passed   \n     # players = %d, hand position = %d, # actions = %d,\n     # buys = %d, victory change = %d, kingdom change: %d\n     p1 deck: %d, p1 discard: %d, p1 handpos: %d\n",count,G2.numPlayers, handP, G2.numActions, G2.numBuys,victoryChange,kingdomChange);  
    }
    else
    {
		fails++;
		printf("Victory/Kingdom Card Test # %d failed   \n     # players = %d, hand position = %d, # actions = %d,\n     # buys = %d, victory change = %d, kingdom change: %d\n     p1 deck: %d, p1 discard: %d, p1 handpos: %d\n",count,G2.numPlayers, handP, G2.numActions, G2.numBuys,victoryChange,kingdomChange);  
		
    }
}

//main test loop
int main() {
	int testNum = 50;
	int bonus = 0;
	int numPlayers = 2;
	int seed = 1000;
	int k[10] = {adventurer, great_hall, village, minion, mine, cutpurse,sea_hag, tribute, smithy, council_room};
	
	int i = 0;
	for (i; i < testNum; i++) {
		
		initializeGame(numPlayers, k, seed, &G);
		memcpy(&G2, &G, sizeof(struct gameState));


		/******************************************************************
		 *                          Randomization                         *
		 * ***************************************************************/

		//assign random number between 0 and 10 to number of players
		G2.numPlayers = rand() % 11;
		//assign random number between 0 and 2 to number of actions
		G2.numActions = rand() % 3;
		//assign random number between 0 and 2 to number of buys
		G2.numBuys = rand() % 3;
		//Assign random number between 0 and handCount to hand position
		handP = rand() % (G2.handCount[0] + 1);
		//randomize deck count for each player (500 is max deck size)
		int h = 0;
		for (h; h < numPlayers; h++)
			G2.deckCount[h] = rand() % 501;
		//randomize discard count for each player (500 is max deck size)
		int g = 0;
		for (g; g < numPlayers; g++)
			G2.discardCount[g] = rand() % 501;

		/******************************************************************
		 *                        Setup for Tests                         *
		 * ***************************************************************/
		//Assign adventurer card to current hand position
		G2.hand[0][handP] = village;
		//check deck count before playing Adventurer
		oldDeckCount = G2.deckCount[0];
		//check discard count before playing Adventurer
		oldDiscardCount = G2.discardCount[0];
		//check hand count before playing Adventurer
		oldHandCount = G2.handCount[0];
		
		/******************************************************************
		 *                          Play Card                             *
		 * ***************************************************************/
		//play Adventurer
		playCard(handP,-1, -1, -1, &G2);
	

		/******************************************************************
		 *                          Testing                               *
		 * ***************************************************************/
		//test for deck count
		deckTesting(i);

		//test for hand count
		handTesting(i);

		//test for victory/kingdom card number
		victoryKingdomTesting(i);

	}

	//output totals
	printf("Village card random test results:\n     Passing Tests:%d\n     Failing Tests:%d\n\n\n\n", passes, fails);
    return 0;
}
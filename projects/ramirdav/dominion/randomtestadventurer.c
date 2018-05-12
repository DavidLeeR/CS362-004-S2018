#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include "interface.h"

//Random Test 1: Adventurer card
//1. exactly 2 treasure cards should be added to player 1's hand after playing Adventurer card
//2. the discarded cards and the 2 treasure cards should come from player 1's supply pile
//3. there should be no state change for other players
//4. check if no state change to kingdom/victory card piles
//5. deck should be shuffled if is 0 when using Adventurer

struct gameState G;
struct gameState G2;
int passes = 0;
int fails = 0;
int handP = 0;
int treas;
int oldDeckCount;
int oldVictoryCount = 36;
int oldKingdomCount = 104;

void beforeTreasureCheck()
{
	treas = 0;
	int p = 0;
	for (p; p < G2.handCount[0]; p++) {
		
		if ((G2.hand[0][p] == gold) || (G2.hand[0][p] == silver) || (G2.hand[0][p] == copper)) {
			treas++;
		}
	}
	//printf("%d\n", treas);
}

void treasureTesting(int count)
{
	int treas2 = 0;
	//test that two treasures were drawn
	int k = 0;
	for (k; k < G2.handCount[0]; k++) {
		
		if ((G2.hand[0][k] == gold) || (G2.hand[0][k] == silver) || (G2.hand[0][k] == copper)) {
			treas2++;
		}
	}

	//printf("%d\n", treas2);
	//if there were 2 added treasure cards to the hand
	if (treas2 - treas == 2) {
		passes++;
		printf("Treasure Test # %d passed   \n     # players = %d, hand position = %d,  \n     # actions = %d, # buys = %d, # treasures = %d\n",count,G2.numPlayers, handP, G2.numActions, G2.numBuys, treas2-treas);
	}
	else {
		fails++;
		printf("Tresure Test # %d failed   \n     # players = %d, hand position = %d,  \n     # actions = %d, # buys = %d, # treasures = %d\n",count,G2.numPlayers, handP, G2.numActions, G2.numBuys, treas2-treas);
	}
}

void deckTesting(int count)
{
	int numDiscarded = G2.discardCount[0];
    int newDeckCount = G2.deckCount[0];
    int totalFromDeck = numDiscarded + 2;       //the total number of cards from the deck should equal all discarded cards and 2 treasure cards
    int deckDiff = oldDeckCount - newDeckCount;

    if(totalFromDeck == deckDiff)
    {
		passes++;
        printf("Deck Test # %d passed   \n     # players = %d, hand position = %d,  \n     # actions = %d, # buys = %d,  deck diff = %d\n",count,G2.numPlayers, handP, G2.numActions, G2.numBuys, deckDiff);  
    }
    else
    {
		fails++;
        printf("Deck Test # %d failed   \n     # players = %d, hand position = %d,  \n     # actions = %d, # buys = %d, deck diff = %d\n",count,G2.numPlayers, handP, G2.numActions, G2.numBuys, deckDiff);  
    }
}

void victoryKingdomTesting(int count)
{
	int newKingdomCount = 0;
	int victoryChange;
	int kingdomChange;
	//count all victory cards after player 1 plays great_hall card
    int newVictoryCount = G2.supplyCount[estate];
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
		printf("Victory/Kingdom Card Test # %d passed   \n     # players = %d, hand position = %d, # actions = %d,\n     # buys = %d, victory change = %d, kingdom change: %d\n",count,G2.numPlayers, handP, G2.numActions, G2.numBuys,victoryChange,kingdomChange);  
    }
    else
    {
		fails++;
		printf("Victory/Kingdom Card Test # %d failed   \n     # players = %d, hand position = %d, # actions = %d,\n     # buys = %d, victory change = %d, kingdom change: %d\n",count,G2.numPlayers, handP, G2.numActions, G2.numBuys,victoryChange,kingdomChange);  
		
    }
}

//testing adventurer card
int main() {
	int testNum = 99;
	int bonus = 0;
	int numPlayers = 2;
	int seed = 1000;
	int k[10] = {adventurer, great_hall, village, minion, mine, cutpurse,sea_hag, tribute, smithy, council_room};
	
	int i = 0;
	for (i; i < testNum; i++) {
		//start a new game
		initializeGame(numPlayers, k, seed, &G);
		
		//make a test game
		memcpy(&G2, &G, sizeof(struct gameState));

		//randomize number of players -- limit is from 0 to 10
		G2.numPlayers = rand() % 11;

		//change player's first card to adventurer
		G2.hand[0][0] = k[0];

		//randomize numActions -- range of 0 to 2
		G2.numActions = rand() % 3;
		//randomize numBuys -- range of 0 to 2
		G2.numBuys = rand() % 3;
		
		//randomize hand position -- limit it to player's hand count
		handP = rand() % (G2.handCount[0] + 1);
		
		beforeTreasureCheck();

		oldDeckCount = G2.deckCount[0];
		
		cardEffect(adventurer, -1, -1, -1, &G2, handP, &bonus);
		
		treasureTesting(i);
		deckTesting(i);
		victoryKingdomTesting(i);

	}
	printf("Adventurer card random test results:\n     Passing Tests:%d\n     Failing Tests:%d\n\n\n\n", passes, fails);
    return 0;
}
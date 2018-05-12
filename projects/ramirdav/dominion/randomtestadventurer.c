#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include "interface.h"

struct gameState G;
struct gameState G2;
int passes = 0;
int fails = 0;
int handP = 0;
int treas;

void beforeTreasureCheck()
{
	treas = 0;
	int p = 0;
	for (p; p < G2.handCount[G2.whoseTurn]; p++) {
		
		if ((G2.hand[G2.whoseTurn][p] == gold) || (G2.hand[G2.whoseTurn][p] == silver) || (G2.hand[G2.whoseTurn][p] == copper)) {
			treas++;
		}
	}
}

void treasureTesting(int count)
{
	int treas2 = 0;
	//test that two treasures were drawn
	int k = 0;
	for (k; k < G2.handCount[G2.whoseTurn]; k++) {
		
		if ((G2.hand[G2.whoseTurn][k] == gold) || (G2.hand[G2.whoseTurn][k] == silver) || (G2.hand[G2.whoseTurn][k] == copper)) {
			treas2++;
		}
	}
	//if there were 2 added treasure cards to the hand
	if (treas2 - treas == 2) {
		passes++;
		printf("Test # %d passed   \n     # players = %d, hand position = %d,  \n     # actions = %d, # buys = %d, # treasures = %d\n",count,G2.numPlayers, handP, G2.numActions, G2.numBuys, treas2-treas);
	}
	else {
		fails++;
		printf("Test # %d failed   \n     # players = %d, hand position = %d,  \n     # actions = %d, # buys = %d, # treasures = %d\n",count,G2.numPlayers, handP, G2.numActions, G2.numBuys, treas2-treas);
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
		G2.hand[G2.whoseTurn][0] = k[0];

		//randomize numActions -- range of 0 to 2
		G2.numActions = rand() % 3;
		//randomize numBuys -- range of 0 to 2
		G2.numBuys = rand() % 3;
		
		//randomize hand position -- limit it to player's hand count
		handP = rand() % (G2.handCount[G2.whoseTurn] + 1);
		
		beforeTreasureCheck();
		
		cardEffect(adventurer, 0, 0, 0, &G2, handP, &bonus);
		
		treasureTesting(i);

	}
	printf("Adventurer card random test results:\n     Passing Tests:%d\n     Failing Tests:%d\n\n\n\n", passes, fails);
    return 0;
}
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include "interface.h"

//testing adventurer card
int main() {
	int testNum = 99;
	int passes = 0;
	int fails = 0;
	int handP = 0;
	int bonus = 0;
	int numPlayers = 2;
	//int curPlayer = 0;   
	int seed = 1000;
	int k[10] = {adventurer, great_hall, village, minion, mine, cutpurse,sea_hag, tribute, smithy, council_room};
	int t;
	struct gameState G;
	struct gameState G2;
	
	int i = 0;
	for (i; i < testNum; i++) {
		t = 0;
		//start a new game
		initializeGame(numPlayers, k, seed, &G);
		
		//make a test game
		memcpy(&G2, &G, sizeof(struct gameState));

		//randomize number of players -- limit is from 0 to 10
		G2.numPlayers = rand() % 11;

		//change player's first card to adventurer
		G2.hand[G2.whoseTurn][0] = k[0];
		
		//randomize hand position -- limit it to player's hand count
		handP = rand() % (G2.handCount[G2.whoseTurn] + 1);
		//randomize numActions -- range of 0 to 2
		G2.numActions = rand() % 3;
		//randomize numBuys -- range of 0 to 2
		G2.numBuys = rand() % 3;
		
		cardEffect(adventurer, 0, 0, 0, &G2, handP, &bonus);
		
		//test that two treasures were drawn
		int k = 0;
		for (k; k < G2.handCount[G2.whoseTurn]; k++) {
			
			if ((G2.hand[G2.whoseTurn][k] == copper) || (G2.hand[G2.whoseTurn][k] == silver) || (G2.hand[G2.whoseTurn][k] == gold)) {
				t++;
			}
		}
		if (t == 2) {
			passes++;
			printf("Test # %d passed   \n     # players = %d, hand position = %d,  \n     # actions = %d, # buys = %d, # treasures = %d\n",i,G2.numPlayers, handP, G2.numActions, G2.numBuys, t);
		}
		else {
			fails++;
			printf("Test # %d failed   \n     # players = %d, hand position = %d,  \n     # actions = %d, # buys = %d, # treasures = %d\n",i,G2.numPlayers, handP, G2.numActions, G2.numBuys, t);
		}
		

	}
	printf("Adventurer card random test results:\n     Passing Tests:%d\n     Failing Tests:%d\n\n\n\n", passes, fails);
    return 0;
}
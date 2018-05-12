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
	struct gameState G;
	struct gameState G2;
	int handpos = 0;
	int bonus = 0;
	int pass = 0, fail = 0;
	int numPlayers = 2;
	int curPlayer = 0;   
	int seed = 1000;
	int k[10] = {adventurer, great_hall, village, minion, mine, cutpurse,sea_hag, tribute, smithy, council_room};
	int t = 0;
	
	int i = 0;
	for (i; i < testNum; i++) {
		//start a new game
		initializeGame(numPlayers, k, seed, &G);
		
		//make a test game
		memcpy(&G2, &G, sizeof(struct gameState));

		//change player's first card to adventurer
		G2.hand[curPlayer][0] = k[0];
		
		//randomize number of players -- limit is from 0 to 10
		G2.numPlayers = rand() % 11;
		//randomize hand position -- limit it to player's hand count
		handpos = rand() % (G2.handCount[curPlayer] + 1);
		//randomize numActions -- range of 0 to 2
		G2.numActions = rand() % 3;
		//randomize numBuys -- range of 0 to 2
		G2.numBuys = rand() % 3;
		
		cardEffect(adventurer, 0, 0, 0, &G2, handpos, &bonus);
		
		//test that two treasures were drawn
		int k = 0;
		for (k; k < G2.handCount[curPlayer]; k++) {
			if ((G2.hand[curPlayer][k] == copper) || (G2.hand[curPlayer][k] == silver) || (G2.hand[curPlayer][k] == gold)) {
				t++;
			}
		}
		if (t == 2) {
			pass++;
			printf("Test # %d passed   /n     # players = %d, hand position = %d,  /n     # actions = %d, # buys = %d",i,G2.numPlayers, handpos, G2.numActions, G2.numBuys);
		}
		else {
			fail++;
			printf("Test # %d failed   /n     # players = %d, hand position = %d,  /n     # actions = %d, # buys = %d",i,G2.numPlayers, handpos, G2.numActions, G2.numBuys);
		}
		

	}
	printf("TOTAL PASS: %d\nTOTAL FAIL: %d\n", pass, fail);
    return 0;
}
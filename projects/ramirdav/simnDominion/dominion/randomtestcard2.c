#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include "rngs.h"



#define DEBUG 0
#define NOISY_TEST 1

int refactorGreathall(int currentPlayer, struct gameState *state, int handPos);

/*
int refactorGreathall(int currentPlayer, struct gameState *state, int handPos){
  //+1 Card
      drawCard(currentPlayer, state);
      
      //+1 Actions
      state->numActions++;
      
      
      //discard card from hand
      discardCard(handPos, currentPlayer, state, 0);
      return 0;

}
*/
/*
struct gameState {
  int numPlayers; //number of players
  int supplyCount[treasure_map+1];  //this is the amount of a specific type of card given a specific number.
  int embargoTokens[treasure_map+1];
  int outpostPlayed;
  int outpostTurn;
  int whoseTurn;
  int phase;
  int numActions; //Starts at 1 each turn 
  int coins; // Use as you see fit! 
  int numBuys; // Starts at 1 each turn 
  int hand[MAX_PLAYERS][MAX_HAND];
  int handCount[MAX_PLAYERS];			   --use this
  int deck[MAX_PLAYERS][MAX_DECK];
  int deckCount[MAX_PLAYERS];              --use this
  int discard[MAX_PLAYERS][MAX_DECK];	   --use this
  int discardCount[MAX_PLAYERS];
  int playedCards[MAX_DECK];
  int playedCardCount;
};

****Also check 

*/

int main(){
	
	struct gameState *game;

	int i;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

	//greathall specific variables
	int player=0;
	int errors=0;


	printf("Testing great hall card. \n");
	printf("RANDOM TESTS. \n");
	int iterations = 100;
	//int treasures[] = {copper, silver, gold};



	srand(time(NULL));

	int cardCount1, cardCount2;
	int actions1, actions2;
	for (i=0; i < iterations; i++){
		game = malloc(sizeof(struct gameState));
		int players = rand() % 3 + 2;
		

		printf("Test %d Init\n", i+1);

		initializeGame(players, k, rand(), game);

		//initialized the player's handcount, deckcount, and discard count, and we want to keep track of it
		game->handCount[player] = rand() % MAX_DECK;
		game->deckCount[player] = rand() % MAX_DECK;
		game->discardCount[player] = rand() % MAX_DECK;

		//refactorAdventurer(int drawntreasure, struct gameState *state, int currentPlayer, int cardDrawn, int z, int *temphand)
		printf("Before Init\n");
		printf("handcount: %d\n", game->handCount[player]);
		printf("deckcount: %d\n", game->deckCount[player]);
		printf("discardcount: %d\n", game->deckCount[player]);
		cardCount1 = game->handCount[player];
		actions1 = game->numActions;
		printf("actions1: %d\n", actions1);

		//printf("cardCount: %d\n", cardCount1);

		cardEffect(great_hall, 1, 1, 1, game, 0, 0);
		//adventurer card goes into effect




		printf("After Init\n");
		printf("handcount: %d\n", game->handCount[player]);
		printf("deckcount: %d\n", game->deckCount[player]);
		printf("discardcount: %d\n", game->deckCount[player]);
		printf("actions2: %d\n", actions2);
		cardCount2 = game->handCount[player];
		actions2 = game->numActions;
		//printf("cardCount: %d\n", cardCount2);
		free(game);

		if (cardCount1 - cardCount2 != 1 && actions2 - actions1 == 2){//it adds 2 actions because of the bug introduced from assignment 2
			//int holder = cardCount2 - cardCount1;
			
			errors++;
			printf("***ERROR FOUND\n");
		}
	}
		

	

	printf("\n");
	printf("The number of errors was: %d\n", errors);

	if (errors > 0){
		printf("\n **Test completed with errors\n");
	}
	else{
		printf("\n **Test complete with no errors\n");
	}

	//use cardEffect to run the card and it's effect onto gamestate game


	return 0;

}



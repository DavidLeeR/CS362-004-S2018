#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "rngs.h"



#define DEBUG 0
#define NOISY_TEST 1

int refactorAdventurer(int drawntreasure, struct gameState *state, int currentPlayer, int cardDrawn, int z, int *temphand);

/*
Reveal cards from your deck until you reveal 2 treasure cards. put those treasure cards into your hand and discard other revealed cards
To random test:
	drawntreasure - not enough treasures in deck?
	gamestate struct
	current player int (compatible number)
	cardDrawn
	z
	*temphand

  while(drawntreasure<2){
  if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
    shuffle(currentPlayer, state);
  }
  drawCard(currentPlayer, state);
  cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
  if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
    drawntreasure++;
  else{
    temphand[z]=cardDrawn;
    state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
    z++;
  }
      }
      while(z-1>=0){
  state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
  z=z-1;
      }
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

	int i, j;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};
	//adventurecard specific variables
	//int drawntreasure=0; //can have this be > 1 for testing
	int player=0;
	int errors=0;


	printf("Testing adventurer card. \n");
	printf("RANDOM TESTS. \n");
	int iterations = 100;
	int treasures[] = {copper, silver, gold};



	srand(time(NULL));

	for (i=0; i < iterations; i++){
		game = malloc(sizeof(struct gameState));
		int players = rand() % 3 + 2;
		

		printf("Test %d Init\n", i+1);

		initializeGame(players, k, rand(), game);

		//initialized the player's handcount, deckcount, and discard count, and we want to keep track of it
		game->handCount[player] = rand() % MAX_DECK;
		game->deckCount[player] = rand() % MAX_DECK;
		game->discardCount[player] = rand() % MAX_DECK;
		int treasureCount = 0;

		//refactorAdventurer(int drawntreasure, struct gameState *state, int currentPlayer, int cardDrawn, int z, int *temphand)
		printf("Before Init\n");
		printf("handcount: %d\n", game->handCount[player]);
		printf("deckcount: %d\n", game->deckCount[player]);
		printf("discardcount: %d\n", game->deckCount[player]);

		for (j=0; j < game->handCount[player]; j++){
			if( (game->hand[player][j] == treasures[0]
				|| game->hand[player][j] == treasures[1]
				|| game->hand[player][j] == treasures[2]) ){
				treasureCount++;
			}
		}
		printf("treasureCOUNT: %d\n", treasureCount);

		cardEffect(adventurer, 1, 1, 1, game, 0, 0);
		//adventurer card goes into effect

		for (j=0; j < game->handCount[player]; j++){
			if( (game->hand[player][j] == treasures[0]
				|| game->hand[player][j] == treasures[1]
				|| game->hand[player][j] == treasures[2]) ){
				treasureCount = treasureCount - 1;
			}
		}

		if(treasureCount >= -1){ //after the adventurer card is used, in best case the first two cards will be a treasure card.
			errors++;
			printf("***ERROR FOUND");
		}


		printf("After Init\n");
		printf("handcount: %d\n", game->handCount[player]);
		printf("deckcount: %d\n", game->deckCount[player]);
		printf("discardcount: %d\n", game->deckCount[player]);
		printf("treasureCOUNT: %d\n", treasureCount);
		
		free(game);
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












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

int refactorSmithy(int i, int currentPlayer, struct gameState *state, int handPos);
/*
int refactorSmithy(int i, int currentPlayer, struct gameState *state, int handPos){
  //+3 Cards
      for (i = 0; i < 3; i++)
  {
    drawCard(currentPlayer, state);
  }
      
      //discard card from hand
      discardCard(handPos, currentPlayer, state, 0);
      state->numBuys++; // (**BUG)
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
  int discard[MAX_PLAYERS][MAX_DECK];	   
  int discardCount[MAX_PLAYERS];		   --use this
  int playedCards[MAX_DECK];
  int playedCardCount;
};

****Also check 

if we check smithy we check if the number of cards of the deck changes after the cardEffect takes place

*/


int main(){
	
	struct gameState *game;

	int i;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

	//smithycard specific variables
	int player=0;
	int errors=0;


	printf("Testing smithy card. \n");
	printf("RANDOM TESTS. \n");
	int iterations = 100;
	//int treasures[] = {copper, silver, gold};



	srand(time(NULL));

	int cardCount1, cardCount2;
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

		printf("cardCount: %d\n", cardCount1);

		cardEffect(smithy, 1, 1, 1, game, 0, 0);
		//adventurer card goes into effect




		printf("After Init\n");
		printf("handcount: %d\n", game->handCount[player]);
		printf("deckcount: %d\n", game->deckCount[player]);
		printf("discardcount: %d\n", game->deckCount[player]);
		
		int cardCount2 = game->handCount[player];
		printf("cardCount: %d\n", cardCount2);
		free(game);
		//you lose one you gain 3 so 2 difference
		if (cardCount2 - cardCount1 != 2){
		errors++;
		printf("***ERROR FOUND");
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



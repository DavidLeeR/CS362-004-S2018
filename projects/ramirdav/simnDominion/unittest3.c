#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

//supplyCount
int main(){

	int r;
	int count=0;
	struct gameState state;
	
	int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

	r = initializeGame(4, k, 1000, &state);//4 players, seed 1000

	//printf("initializeGame(4, k, 1000, &state) = %d\n", r);


	r = supplyCount(great_hall, &state); //should be 12

	if ( r == 12 ){
		printf("**Great Hall has correct # in supply\n");
	}
	else{
		count++;
	}

	r = supplyCount(gardens, &state);

	if ( r == 12){
		printf("**Gardens has correct # in supply\n");
	}
	else{
		count++;
	}

	r = supplyCount(feast, &state);

	if ( r == 10){
		printf("**Feast has correct # in supply\n");
	}
	else{
		count++;
	}

	if(count == 0){
		printf("Testing complete with NO errors\n");
	}

	else{
		printf("Testing failed, supply was incorrect\n");
	}

	return 0;


	//silver should be 40


	//curse should be 30
	


	
}
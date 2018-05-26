#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

//whoseTurn
int main(){


	int count = 0;
	struct gameState state;

	int player = 0;

	for (int i = 0; i < 4; i++){//4 players
		state.whoseTurn = i;
		if (whoseTurn(&state) == i){
			printf("**SUCCESS\n");
		}
		else{
			printf("##Test Fail player %d was incorrect", i);
			count++;
		}

	}

	if (count == 0){
		printf("Unittest2 - whoseTurn() completed with no errors\n");
	}
	
	return 0;
}
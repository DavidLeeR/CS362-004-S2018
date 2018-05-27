#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

//getCost
int main(){

	int count = 0; //counts failed test
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
			sea_hag, tribute, smithy, council_room};

	for (int i = 0; i < 10; i++){
		if (getCost(k[i]) <= 8)// province is highest at value 8
			printf("%d PASS", k[i]);
		else{
			printf("%d FAIL#####", k[i]);
			count++;
		}
	}

	if (count == 0){
		printf("Unittest1 - getCost() completed with no errors\n");
	}

	return 0;

}
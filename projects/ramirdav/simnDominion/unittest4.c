#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

//kingdomCards 
int main(){
	int count = 0;
	int k1=1;
	int k2=2;
	int k3=3;
	int k4=4;
	int k5=5;
	int k6=6;
	int k7=7;
	int k8=8;
	int k9=9;
	int k10=10;

	int* k = kingdomCards(k1,k2,k3,k4,k5,k6,k7,k8,k9,k10);
	//int* k = kingdomCards(k1,k2,k3,k4,k5,k6,k7,k8,k9,k9); //can check incorrectness with this init

	if (k[0] != k1){
		printf("Card Incorrect at index 0\n");
		count++;

	}
	if (k[1] != k2){
		printf("Card Incorrect at index 1\n");
		count++;

	}
	if (k[2] != k3){
		printf("Card Incorrect at index 2\n");
		count++;

	}
	if (k[3] != k4){
		printf("Card Incorrect at index 3\n");
		count++;

	}
	if (k[4] != k5){
		printf("Card Incorrect at index 4\n");
		count++;

	}
	if (k[5] != k6){
		printf("Card Incorrect at index 5\n");
		count++;

	}
	if (k[6] != k7){
		printf("Card Incorrect at index 6\n");
		count++;

	}
	if (k[7] != k8){
		printf("Card Incorrect at index 7\n");
		count++;

	}
	if (k[8] != k9){
		printf("Card Incorrect at index 8\n");
		count++;

	}
	if (k[9] != k10){
		printf("Card Incorrect at index 9\n");
		count++;

	}

	if (count == 0){
		printf("**Unittest4 -kingdomCards completed with no errors\n");
	}

	return 0;

}
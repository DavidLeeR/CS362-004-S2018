/***********************************************************
 * Class: CS 362
 * Assignment 3: unit tests
 * Unit Test 2: newGame() function
 * Author: David Ramirez
 * Date: 4/19/18
 * *********************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

//Unit Test for newGame() function
//1. G1 should not point to NULL after call to newGame(), signifying a new memory address for G1
//2. G1->numPlayers and G1->playedCardCount should both return 0, showing that memory has been corrctly allocated for the struct
//	-If test case 2 fails, a segmentation fault will result 
int main() 
{
    struct gameState *G1 = NULL;
    int testSum = 0;        //keeps track of passed test cases
    int testTotal = 1;      //number of total test cases


    /***************************************************************************************
     *PART 1: check if G1 points to different address than G1Copy                          *
     ***************************************************************************************/
    //call new game, returning a new memory address for G1
    G1 = newGame();

    if(G1 != NULL)
    {
        printf("Unit Test 2: part 1 (check if new memory address for G1 after call to newGame() is not NULL)... \n     PASS\n     expected result: G1 != NULL\n     actual result: G1 != NULL\n");
	testSum++;
    }
    else if(G1 == NULL)
    {
        printf("Unit Test 2: part 1(check if new memory address for G1 after call to newGame() is not NULL)... \n     FAIL\n     expected result: G1 != NULL\n     actual result: G1 == NULL\n");
    }

    /***************************************************************************************
    *                         OUTPUT TOTAL UNIT TEST RESULTS                              *
    ****************************************************************************************/
    //if not all the test cases passed, output number of failed tests
    if (testSum < testTotal)
    {
        int testFails = testTotal - testSum;
        printf("Unit Test 2 failed %d test cases \n", testFails);
    }
    //if all test cases passed, output success message
    else if (testSum == testTotal)
        printf("Unit Test 2 passed all test cases \n");
    
    printf("%d      %d", G1->numPlayers, G1->playedCardCount);

    return 0;
}

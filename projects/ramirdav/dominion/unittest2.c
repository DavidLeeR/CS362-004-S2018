/***********************************************************
 * Class: CS 362
 * Assignment 3: unit tests
 * Unit Test 2: newGame() function
 * Author: David Ramirez
 * Date: 4/29/18
 * *********************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

//Unit Test 2: newGame() function
//1. G1 should not point to NULL after call to newGame(), signifying a new memory address for G1
//2. G1->numPlayers and G1->playedCardCount should both return 0, showing that memory has been corrctly allocated for the struct
//	-If test case 2 fails, a segmentation fault will result 
int main() 
{
    struct gameState *G1 = NULL;
    int testSum = 0;        //keeps track of passed test cases
    int testTotal = 2;      //number of total test cases

    printf("\n\n\n******************Starting Unit Test 2: newGame() function******************\n");        
    /***************************************************************************************
     *PART 1: check if G1 points to NULL                                                   *
     ***************************************************************************************/
    //call new game, returning a new memory address for G1
    G1 = newGame();

    if(G1 != NULL)
    {
        printf("Unit Test 2: part 1 (G1 should not equal NULL after call to newGame())... \n     PASS\n     expected result: G1 != NULL\n     actual result: G1 != NULL\n");
	    testSum++;
    }
    else if(G1 == NULL)
    {
        printf("Unit Test 2: part 1(G1 should not equal NULL after call to newGame())... \n     FAIL\n     expected result: G1 != NULL\n     actual result: G1 == NULL\n");
    }


    /***************************************************************************************
     *PART 2: check if G1->playerNum == 0 and G1->playedCardCount == 0                     *
     ***************************************************************************************/
    printf("*NOTE*: Unit Test 2: part 1 has passed. If Unit Test 2: part 2 fails, a segmentation fault will occur and will \nresult in a missing \"Unit Test2:part 2\" line directly after this line as well \nas a missing unit test summary.");
    if(G1->numPlayers == 0 && G1->playedCardCount == 0)
    {
        printf("Unit Test 2: part 2 (G1->playerNum and G1->playerCardCount should both equal 0 after call to newGame())... \n     PASS\n     expected result: playerNum == 0 && playerCardCount == 0\n     actual result: playerNum == 0 && playerCardCount ==0\n");
        testSum++;
    }
    else
    {
        //there is nothing here because a seg fault will happen if this test case fails
    }


    /***************************************************************************************
    *                         OUTPUT TOTAL UNIT TEST RESULTS                              *
    ****************************************************************************************/
    //if not all the test cases passed, output number of failed tests
    if (testSum < testTotal)
    {
        int testFails = testTotal - testSum;
        printf("Unit Test 2 failed %d out of 2 test cases \n", testFails);
    }
    //if all test cases passed, output success message
    else if (testSum == testTotal)
        printf("Unit Test 2 passed all 2 test cases \n");

    return 0;
}

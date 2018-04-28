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
//1. G1 should be NULL before call to newGame()
//2. G1 should not be NULL after call to newGame()
int main() 
{
    struct gameState G1;      
    int testSum = 0;        //keeps track of passed test cases
    int testTotal = 2;      //number of total test cases


    /***************************************************************************************
     *PART 1: check if G1 == NULL before call to newGame()                                 *
     ***************************************************************************************/
    if(G1 == NULL)
    { 
        printf("Unit Test 2: part 1 (check if G1 == NULL before call to newGame())... \n     PASS\n     expected result: G1 == NULL\n     actual result: G1 == NULL\n");  
        testSum++;
    }
    else if(G1 != NULL)
    {
        printf("Unit Test 2: part 1(check if G1 == NULL before call to newGame())... \n     FAIL\n     expected result: G1 == NULL\n     actual result: G1 != NULL\n");
    }



    /***************************************************************************************
     *PART 2: check if size of G1 == size of gamState struct after call to newGame()       *
     ***************************************************************************************/
    G1 = newGame();

    if(G1 != NULL)
    {
        printf("Unit Test 2: part 2 (check if G1 == NULL after call to newGame())... \n     PASS\n     expected result: G1 != NULL\n     actual result: G1 != NULL\n");  
        testSum++;
    }
    else if(G1 == NULL)
    {
        printf("Unit Test 2: part 1(check if G1 == NULL after call to newGame())... \n     FAIL\n     expected result: G1 != NULL\n     actual result: G1 == NULL\n");
    }


    return 0;

}

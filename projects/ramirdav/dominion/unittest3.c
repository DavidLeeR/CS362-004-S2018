/***********************************************************
 * Class: CS 362
 * Assignment: 3 (unit tests)
 * Unit Test 3: compare() function
 * Author: David Ramirez
 * Date: 4/29/18
 * *********************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

//Unit Test 3: compare() function
//1. compare() function should return -1 (showing that a is less than b) when value of parameter a is less than value of parameter b
//2. compare() function should return 1 (showing that a is greater than b) when value of parameter a is greater than value of parameter b
//3. compare() function should return 0 (showing that a is equal to b) when value of parameter a is equal to value of parameter b
int main() 
{
    //test params 1
    int* a1 = malloc(sizeof(int));
    *a1 = 0;
    int* b1 = malloc(sizeof(int));
    *b1 = 100;
    //test params 2
    int* a2 = malloc(sizeof(int));
    *a2 = 100;
    int* b2 = malloc(sizeof(int));
    *b2 = 0;
    //test params 3
    int* a3 = malloc(sizeof(int));
    *a3 = 15;
    int* b3 = malloc(sizeof(int));
    *b3 = 15;


    int result;
    int testSum = 0;        //keeps track of passed test cases
    int testTotal = 3;      //number of total test cases

    printf("\n\n\n******************Starting Unit Test 3: compare() function******************\n");    
    /***************************************************************************************
     *PART 1: check if -1 is returned (signifying a is less than b) when a is less than b  *
     ***************************************************************************************/
    result = compare(a1, b1);

    if(result == -1)
    {
        printf("Unit Test 3, part 1 (compare() should return -1 for a < b)... \n     PASS\n     expected result: compare(0,100) == -1\n     actual result: compare(0,100) == -1\n");  
        testSum++;
    }
    else if(result != -1)
    {
        printf("Unit Test 3, part 1 (compare should return -1 for for a < b)... \n     FAIL\n     expected result: compare(0,100) == -1\n     actual result: compare(0,100) == %d\n",result);          
    }


    /******************************************************************************************
     *PART 2: check if 1 is returned (signifying a is greater than b) when a is greater than b*
     ******************************************************************************************/
    result = compare(a2, b2);
    
    if(result == 1)
    {
        printf("Unit Test 3, part 2 (compare should return 1 for a > b)... \n     PASS\n     expected result: compare(100,0) == 1\n     actual result: compare(100,0) == 1\n");          
        testSum++;
    }
    else if(result != 1)
    {
        printf("Unit Test 3, part 2 (compare should return 1 for a > b)... \n     FAIL\n     expected result: compare(100,0) == 1\n     actual result: compare(100,0) == %d\n", result); 
    }


    /******************************************************************************************
     *PART 3: check if 0 is returned (signifying a is equal to b) when a is equal to b        *
     ******************************************************************************************/
    result = compare(a3, b3);
    
    if(result == 0)
    {
        printf("Unit Test 3, part 2 (compare should return 0 for a == b)... \n     PASS\n     expected result: compare(15,15) == 0\n     actual result: compare(15,15) == 0\n");          
        testSum++;
    }
    else if(result != 0)
    {
        printf("Unit Test 3, part 2 (compare should return 0 for a == b)... \n     FAIL\n     expected result: compare(15,15) == 0\n     actual result: compare(15,15) == %d\n", result); 
    }
    

    /***************************************************************************************
    *                         OUTPUT TOTAL UNIT TEST RESULTS                              *
    ****************************************************************************************/
    //if not all the test cases passed, output number of failed tests
    if (testSum < testTotal)
    {
        int testFails = testTotal - testSum;
        printf("Unit Test 3 failed %d out of 3 test cases \n", testFails);
    }
    //if all test cases passed, output success message
    else if (testSum == testTotal)
        printf("Unit Test 3 passed all 3 test cases \n");

  
    return 0;
}

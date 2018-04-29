/***********************************************************
 * Class: CS 362
 * Assignment: 3 (unit tests)
 * Unit Test 3: getCost() function
 * Author: David Ramirez
 * Date: 4/29/18
 * *********************************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

//Unit Test 4: getCost() function
//1. getCost() function should return 0 when curse card (enum value 0) is passed
//2. getCost() function should return 2 when estate card (enum value 1) is passed
//3. getCost() function should return 5 when duchy card (enum value 2) is passed
//4. getCost() function should return 8 when province card (enum value 3) is passed
//5. getCost() function should return 0 when copper card (enum value 4) is passed
//6. getCost() function should return 3 when silver card (enum value 5) is passed
//7. getCost() function should return 6 when gold card (enum value 6) is passed
//8. getCost() function should return 6 when adventurer card (enum value 7) is passed
//9. getCost() function should return 5 when council_room card (enum value 8) is passed
//10. getCost() function should return 4 when feast card (enum value 9) is passed
//11. getCost() function should return 4 when gardens card (enum value 10) is passed
//12. getCost() function should return 5 when mine card (enum value 11) is passed
//13. getCost() function should return 4 when remodel card (enum value 12) is passed
//14. getCost() function should return 4 when smithy card (enum value 13) is passed
//15. getCost() function should return 3 when village card (enum value 14) is passed
//16. getCost() function should return 4 when baron card (enum value 15) is passed
//17. getCost() function should return 3 when great_hall card (enum value 16) is passed
//18. getCost() function should return 5 when minion card (enum value 17) is passed
//19. getCost() function should return 3 when steward card (enum value 18) is passed
//20. getCost() function should return 5 when tribute card (enum value 19) is passed
//21. getCost() function should return 3 when embassador card (enum value 20) is passed
//22. getCost() function should return 4 when cutpurse card (enum value 21) is passed
//23. getCost() function should return 2 when embargo card (enum value 22) is passed
//24. getCost() function should return 5 when outpost card (enum value 23) is passed
//25. getCost() function should return 4 when salvager card (enum value 24) is passed
//26. getCost() function should return 4 when sea_hag card (enum value 25) is passed
//27. getCost() function should return 4 when treasure_map card (enum value 26) is passed


int main() 
{
  


    int result;
    int testSum = 0;        //keeps track of passed test cases
    int testTotal = 27;      //number of total test cases


    /***************************************************************************************
     *PART 1: check if 0 is returned from getCost() when curse card value (0) is passed    *
     ***************************************************************************************/
    result = getCost(0);

    if(result == 0)
    {
        printf("Unit Test 4, part 1 (getCost() should return 0 when curse card value (0) passed)... \n     PASS\n     expected result: getCost(0) == 0\n     actual result: getCost(0) == 0\n");  
        testSum++;
    }
    else if(result != 0)
    {
        printf("Unit Test 4, part 1 (getCost() should return 0 when curse card value (0) passed)... \n     FAIL\n     expected result: getCost(0) == 0\n     actual result: getCost(0) == %d\n", result);  
    }



    /***************************************************************************************
     *PART 2: check if 2 is returned from getCost() when estate card value (1) is passed   *
     ***************************************************************************************/
    result = getCost(1);

    if(result == 2)
    {
        printf("Unit Test 4, part 2 (getCost() should return 2 when curse card value (1) passed)... \n     PASS\n     expected result: getCost(1) == 2\n     actual result: getCost(1) == 2\n");  
        testSum++;
    }
    else if(result != 2)
    {
        printf("Unit Test 4, part 2 (getCost() should return 2 when curse card value (1) passed)... \n     FAIL\n     expected result: getCost(1) == 2\n     actual result: getCost(1) == %d\n", result);  
    }



    /***************************************************************************************
     *PART 3: check if 5 is returned from getCost() when duchy card value (2) is passed    *
     ***************************************************************************************/
    result = getCost(2);

    if(result == 5)
    {
        printf("Unit Test 4, part 3 (getCost() should return 5 when curse card value (2) passed)... \n     PASS\n     expected result: getCost(2) == 5\n     actual result: getCost(2) == 5\n");  
        testSum++;
    }
    else if(result != 5)
    {
        printf("Unit Test 4, part 3 (getCost() should return 5 when curse card value (2) passed)... \n     FAIL\n     expected result: getCost(2) == 5\n     actual result: getCost(2) == %d\n", result);  
    }
    


    /***************************************************************************************
     *PART 4: check if 8 is returned from getCost() when province card value (3) is passed *
     ***************************************************************************************/
    result = getCost(3);

    if(result == 8)
    {
        printf("Unit Test 4, part 4 (getCost() should return 8 when curse card value (3) passed)... \n     PASS\n     expected result: getCost(3) == 8\n     actual result: getCost(1) == 8\n");  
        testSum++;
    }
    else if(result != 8)
    {
        printf("Unit Test 4, part 4 (getCost() should return 8 when curse card value (3) passed)... \n     FAIL\n     expected result: getCost(3) == 8\n     actual result: getCost(1) == %d\n", result);  
    }



    /***************************************************************************************
     *PART 5: check if 0 is returned from getCost() when copper card value (4) is passed   *
     ***************************************************************************************/
    result = getCost(4);

    if(result == 0)
    {
        printf("Unit Test 4, part 5 (getCost() should return 0 when copper card value (4) passed)... \n     PASS\n     expected result: getCost(4) == 0\n     actual result: getCost(4) == 0\n");  
        testSum++;
    }
    else if(result != 0)
    {
        printf("Unit Test 4, part 5 (getCost() should return 0 when copper card value (4) passed)... \n     FAIL\n     expected result: getCost(4) == 0\n     actual result: getCost(4) == %d\n", result);  
    }



    /***************************************************************************************
     *PART 6: check if 3 is returned from getCost() when silver card value (5) is passed   *
     ***************************************************************************************/
    result = getCost(5);

    if(result == 3)
    {
        printf("Unit Test 4, part 6 (getCost() should return 3 when silver card value (5) passed)... \n     PASS\n     expected result: getCost(5) == 3\n     actual result: getCost(5) == 3\n");  
        testSum++;
    }
    else if(result != 3)
    {
        printf("Unit Test 4, part 6 (getCost() should return 3 when silver card value (5) passed)... \n     FAIL\n     expected result: getCost(5) == 3\n     actual result: getCost(5) == %d\n", result);  
    }



    /***************************************************************************************
     *PART 7: check if 6 is returned from getCost() when gold card value (6) is passed     *
     ***************************************************************************************/
    result = getCost(6);

    if(result == 6)
    {
        printf("Unit Test 4, part 7 (getCost() should return 6 when gold card value (6) passed)... \n     PASS\n     expected result: getCost(6) == 6\n     actual result: getCost(6) == 6\n");  
        testSum++;
    }
    else if(result != 6)
    {
        printf("Unit Test 4, part 7 (getCost() should return 6 when gold card value (6) passed)... \n     FAIL\n     expected result: getCost(6) == 6\n     actual result: getCost(6) == %d\n", result);  
    }



    /****************************************************************************************
     *PART 8: check if 6 is returned from getCost() when adventurer card value (7) is passed*
     ****************************************************************************************/
    result = getCost(7);

    if(result == 6)
    {
        printf("Unit Test 4, part 8 (getCost() should return 0 when copper card value (4) passed)... \n     PASS\n     expected result: getCost(4) == 0\n     actual result: getCost(4) == 0\n");  
        testSum++;
    }
    else if(result != 6)
    {
        printf("Unit Test 4, part 8 (getCost() should return 0 when copper card value (4) passed)... \n     FAIL\n     expected result: getCost(4) == 0\n     actual result: getCost(4) == %d\n", result);  
    }


    /*********************************************************************************************
     *PART 9: check if 5 is returned from getCost() when council_room card value (8) is passed   *
     *********************************************************************************************/
    result = getCost(8);

    if(result == 5)
    {
        printf("Unit Test 4, part 9 (getCost() should return 5 when council_room card value (8) passed)... \n     PASS\n     expected result: getCost(8) == 5\n     actual result: getCost(8) == 5\n");  
        testSum++;
    }
    else if(result != 5)
    {
        printf("Unit Test 4, part 9 (getCost() should return 5 when council_room card value (8) passed)... \n     FAIL\n     expected result: getCost(8) == 5\n     actual result: getCost(8) == %d\n", result);  
    }


    /***************************************************************************************
     *PART 10: check if 4 is returned from getCost() when feast card value (9) is passed   *
     ***************************************************************************************/
    result = getCost(9);

    if(result == 4)
    {
        printf("Unit Test 4, part 10 (getCost() should return 4 when feast card value (9) passed)... \n     PASS\n     expected result: getCost(9) == 4\n     actual result: getCost(9) == 4\n");  
        testSum++;
    }
    else if(result != 4)
    {
        printf("Unit Test 4, part 10 (getCost() should return 4 when feast card value (9) passed)... \n     FAIL\n     expected result: getCost(9) == 4\n     actual result: getCost(9) == %d\n", result);  
    }


    /***************************************************************************************
     *PART 11: check if 4 is returned from getCost() when gardens card value (10) is passed   *
     ***************************************************************************************/
    result = getCost(10);

    if(result == 4)
    {
        printf("Unit Test 4, part 11 (getCost() should return 4 when gardens card value (10) passed)... \n     PASS\n     expected result: getCost(10) == 4\n     actual result: getCost(10) == 4\n");  
        testSum++;
    }
    else if(result != 4)
    {
        printf("Unit Test 4, part 11 (getCost() should return 4 when gardens card value (10) passed)... \n     FAIL\n     expected result: getCost(10) == 4\n     actual result: getCost(10) == %d\n", result);  
    }


    /***************************************************************************************
     *PART 12: check if 5 is returned from getCost() when mine card value (11) is passed   *
     ***************************************************************************************/
    result = getCost(11);

    if(result == 5)
    {
        printf("Unit Test 4, part 12 (getCost() should return 5 when copper card value (11) passed)... \n     PASS\n     expected result: getCost(11) == 5\n     actual result: getCost(11) == 5\n");  
        testSum++;
    }
    else if(result != 5)
    {
        printf("Unit Test 4, part 12 (getCost() should return 5 when copper card value (11) passed)... \n     FAIL\n     expected result: getCost(11) == 5\n     actual result: getCost(11) == %d\n", result);  
    }


    /***************************************************************************************
     *PART 13: check if 4 is returned from getCost() when remodel card value (12) is passed*
     ***************************************************************************************/
    result = getCost(12);

    if(result == 4)
    {
        printf("Unit Test 4, part 13 (getCost() should return 4 when remodel card value (12) passed)... \n     PASS\n     expected result: getCost(12) == 4\n     actual result: getCost(12) == 4\n");  
        testSum++;
    }
    else if(result != 4)
    {
        printf("Unit Test 4, part 13 (getCost() should return 4 when remodel card value (12) passed)... \n     FAIL\n     expected result: getCost(12) == 4\n     actual result: getCost(12) == %d\n", result);  
    }


    /***************************************************************************************
     *PART 14: check if 4 is returned from getCost() when smithy card value (13) is passed *
     ***************************************************************************************/
    result = getCost(13);

    if(result == 4)
    {
        printf("Unit Test 4, part 14 (getCost() should return 4 when smithy card value (13) passed)... \n     PASS\n     expected result: getCost(13) == 4\n     actual result: getCost(13) == 4\n");  
        testSum++;
    }
    else if(result != 4)
    {
        printf("Unit Test 4, part 14 (getCost() should return 4 when smithy card value (13) passed)... \n     FAIL\n     expected result: getCost(13) == 4\n     actual result: getCost(13) == %d\n", result);  
    }


    /***************************************************************************************
     *PART 15: check if 3 is returned from getCost() when village card value (14) is passed*
     ***************************************************************************************/
    result = getCost(14);

    if(result == 3)
    {
        printf("Unit Test 4, part 15 (getCost() should return 3 when village card value (14) passed)... \n     PASS\n     expected result: getCost(14) == 3\n     actual result: getCost(14) == 3\n");  
        testSum++;
    }
    else if(result != 3)
    {
        printf("Unit Test 4, part 15 (getCost() should return 3 when village card value (14) passed)... \n     FAIL\n     expected result: getCost(14) == 3\n     actual result: getCost(14) == %d\n", result);  
    }


    /***************************************************************************************
     *PART 16: check if 4 is returned from getCost() when baron card value (15) is passed   *
     ***************************************************************************************/
    result = getCost(15);

    if(result == 4)
    {
        printf("Unit Test 4, part 16 (getCost() should return 4 when baron card value (15) passed)... \n     PASS\n     expected result: getCost(15) == 4\n     actual result: getCost(4) == 4\n");  
        testSum++;
    }
    else if(result != 4)
    {
        printf("Unit Test 4, part 16 (getCost() should return 4 when baron card value (15) passed)... \n     FAIL\n     expected result: getCost(15) == 4\n     actual result: getCost(4) == %d\n", result);  
    }


    /*********************************************************************************************
     *PART 17: check if 3 is returned from getCost() when great_hall card value (16) is passed   *
     *********************************************************************************************/
    result = getCost(16);

    if(result == 3)
    {
        printf("Unit Test 4, part 17 (getCost() should return 3 when great_hall card value (16) passed)... \n     PASS\n     expected result: getCost(16) == 3\n     actual result: getCost(16) == 3\n");  
        testSum++;
    }
    else if(result != 3)
    {
        printf("Unit Test 4, part 17 (getCost() should return 3 when great_hall card value (16) passed)... \n     FAIL\n     expected result: getCost(16) == 3\n     actual result: getCost(16) == %d\n", result);  
    }


    /***************************************************************************************
     *PART 18: check if 5 is returned from getCost() when minion card value (17) is passed *
     ***************************************************************************************/
    result = getCost(17);

    if(result == 5)
    {
        printf("Unit Test 4, part 18 (getCost() should return 5 when great_hall card value (17) passed)... \n     PASS\n     expected result: getCost(17) == 5\n     actual result: getCost(17) == 5\n");  
        testSum++;
    }
    else if(result != 5)
    {
        printf("Unit Test 4, part 18 (getCost() should return 5 when great_hall card value (17) passed)... \n     FAIL\n     expected result: getCost(17) == 5\n     actual result: getCost(17) == %d\n", result);  
    }


    /***************************************************************************************
     *PART 19: check if 3 is returned from getCost() when steward card value (18) is passed*
     ***************************************************************************************/
    result = getCost(18);

    if(result == 3)
    {
        printf("Unit Test 4, part 19 (getCost() should return 3 when steward card value (18) passed)... \n     PASS\n     expected result: getCost(18) == 3\n     actual result: getCost(18) == 3\n");  
        testSum++;
    }
    else if(result != 3)
    {
        printf("Unit Test 4, part 19 (getCost() should return 3 when steward card value (18) passed)... \n     FAIL\n     expected result: getCost(18) == 3\n     actual result: getCost(18) == %d\n", result);  
    }


    /*******************************************************************************************
     *PART 20: check if 5 is returned from getCost() when tribute card value (19) is passed   *
     *******************************************************************************************/
    result = getCost(19);

    if(result == 5)
    {
        printf("Unit Test 4, part 20 (getCost() should return 5 when tribute card value (19) passed)... \n     PASS\n     expected result: getCost(19) == 5\n     actual result: getCost(19) == 5\n");  
        testSum++;
    }
    else if(result != 5)
    {
        printf("Unit Test 4, part 20 (getCost() should return 5 when tribute card value (19) passed)... \n     FAIL\n     expected result: getCost(19) == 5\n     actual result: getCost(19) == %d\n", result);  
    }


    /*********************************************************************************************
     *PART 21: check if 3 is returned from getCost() when embassador card value (20) is passed   *
     *********************************************************************************************/
    result = getCost(20);

    if(result == 3)
    {
        printf("Unit Test 4, part 21 (getCost() should return 3 when ambassador card value (20) passed)... \n     PASS\n     expected result: getCost(20) == 3\n     actual result: getCost(20) == 3\n");  
        testSum++;
    }
    else if(result != 3)
    {
        printf("Unit Test 4, part 21 (getCost() should return 3 when ambassador card value (20) passed)... \n     FAIL\n     expected result: getCost(20) == 3\n     actual result: getCost(20) == %d\n", result);  
    }


    /*********************************************************************************************
     *PART 22: check if 4 is returned from getCost() when cutpurse card value (21) is passed     *
     *********************************************************************************************/
    result = getCost(21);

    if(result == 4)
    {
        printf("Unit Test 4, part 22 (getCost() should return 4 when cutpurse card value (21) passed)... \n     PASS\n     expected result: getCost(21) == 4\n     actual result: getCost(21) == 4\n");  
        testSum++;
    }
    else if(result != 4)
    {
        printf("Unit Test 4, part 22 (getCost() should return 4 when cutpurse card value (21) passed)... \n     FAIL\n     expected result: getCost(21) == 4\n     actual result: getCost(21) == %d\n", result);  
    }


    /*********************************************************************************************
     *PART 23: check if 2 is returned from getCost() when embargo card value (22) is passed      *
     *********************************************************************************************/
    result = getCost(22);

    if(result == 2)
    {
        printf("Unit Test 4, part 23 (getCost() should return 2 when embargo card value (22) passed)... \n     PASS\n     expected result: getCost(22) == 2\n     actual result: getCost(22) == 2\n");  
        testSum++;
    }
    else if(result != 2)
    {
        printf("Unit Test 4, part 23 (getCost() should return 2 when embargo card value (22) passed)... \n     FAIL\n     expected result: getCost(22) == 2\n     actual result: getCost(22) == %d\n", result);  
    }


    /*********************************************************************************************
     *PART 24: check if 5 is returned from getCost() when outpost card value (23) is passed      *
     *********************************************************************************************/
    result = getCost(23);

    if(result == 5)
    {
        printf("Unit Test 4, part 24 (getCost() should return 5 when outpost card value (23) passed)... \n     PASS\n     expected result: getCost(23) == 5\n     actual result: getCost(23) == 5\n");  
        testSum++;
    }
    else if(result != 5)
    {
        printf("Unit Test 4, part 24 (getCost() should return 5 when outpost card value (23) passed)... \n     FAIL\n     expected result: getCost(23) == 5\n     actual result: getCost(23) == %d\n", result);  
    }


    /*********************************************************************************************
     *PART 25: check if 4 is returned from getCost() when salvager card value (24) is passed     *
     *********************************************************************************************/
    result = getCost(24);

    if(result == 4)
    {
        printf("Unit Test 4, part 25 (getCost() should return 4 when salvager card value (23) passed)... \n     PASS\n     expected result: getCost(23) == 4\n     actual result: getCost(23) == 4\n");  
        testSum++;
    }
    else if(result != 4)
    {
        printf("Unit Test 4, part 25 (getCost() should return 4 when salvager card value (23) passed)... \n     FAIL\n     expected result: getCost(23) == 4\n     actual result: getCost(23) == %d\n", result);  
    }


    /*********************************************************************************************
     *PART 26: check if 4 is returned from getCost() when sea_hag card value (25) is passed      *
     *********************************************************************************************/
    result = getCost(25);

    if(result == 4)
    {
        printf("Unit Test 4, part 26 (getCost() should return 4 when sea_hag card value (25) passed)... \n     PASS\n     expected result: getCost(25) == 4\n     actual result: getCost(25) == 4\n");  
        testSum++;
    }
    else if(result != 4)
    {
        printf("Unit Test 4, part 26 (getCost() should return 4 when sea_hag card value (25) passed)... \n     FAIL\n     expected result: getCost(25) == 4\n     actual result: getCost(25) == %d\n", result);  
    }


    /***********************************************************************************************
     *PART 27: check if 4 is returned from getCost() when treasure_map card value (26) is passed   *
     ***********************************************************************************************/
    result = getCost(26);

    if(result == 4)
    {
        printf("Unit Test 4, part 27 (getCost() should return 4 when treasure_map card value (26) passed)... \n     PASS\n     expected result: getCost(26) == 4\n     actual result: getCost(26) == 4\n");  
        testSum++;
    }
    else if(result != 4)
    {
        printf("Unit Test 4, part 27 (getCost() should return 4 when treasure_map card value (26) passed)... \n     FAIL\n     expected result: getCost(26) == 4\n     actual result: getCost(26) == %d\n", result);  
    }



    /***************************************************************************************
    *                         OUTPUT TOTAL UNIT TEST RESULTS                              *
    ****************************************************************************************/
    //if not all the test cases passed, output number of failed tests
    if (testSum < testTotal)
    {
        int testFails = testTotal - testSum;
        printf("Unit Test 3 failed %d test cases \n", testFails);
    }
    //if all test cases passed, output success message
    else if (testSum == testTotal)
        printf("Unit Test 3 passed all test cases \n");

  
    return 0;
}
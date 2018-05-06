//Title: CSc62 Random Testing Quiz
//Author: David Ramirez
//Date: 5/6/18

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    //assign any valid code in the ascii table to charNum
    int charNum = rand() % 128;
    //assign a char corresponding to the above ascii code
    char retChar = charNum;
    //return the random char
    return retChar;
}

char *inputString()
{
  
    //create string to return
    char* retString = malloc(sizeof(char) * (6));
    //lowChar = lowest bound of ascii code to randomize (e)
    int lowChar = 101;
    //highChar = upper bound of ascii code to randomize (t) 
    int highChar = 116;
  
    //for each of the 5 elements in retString, pick a random number
    //in the range between lowChar and highChar and assign to retString
    int i;
    for (i = 0; i < 5; i++) 
    {
        int pickRandom = (rand() % (highChar-lowChar + 1)) + lowChar;
        retString[i] = pickRandom;;
    }
          
  //put null terminator at end of string
    retString[5] = '\0';
          
    return retString;
          
}

void testme()
{
    int tcCount = 0;
    char *s;
    char c;
    int state = 0;

    clock_t start = clock();
    clock_t elapsed;
    int elapsedTime;

    //ensure program runs no longer than 250 seconds
    while (elapsedTime < 250)
    {
        elapsed = clock() - start;
        elapsedTime = elapsed/CLOCKS_PER_SEC;
        tcCount++;
        c = inputChar();
        s = inputString();
        printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

        if (c == '[' && state == 0) state = 1;
        if (c == '(' && state == 1) state = 2;
        if (c == '{' && state == 2) state = 3;
        if (c == ' '&& state == 3) state = 4;
        if (c == 'a' && state == 4) state = 5;
        if (c == 'x' && state == 5) state = 6;
        if (c == '}' && state == 6) state = 7;
        if (c == ')' && state == 7) state = 8;
        if (c == ']' && state == 8) state = 9;
        if (s[0] == 'r' && s[1] == 'e'
           && s[2] == 's' && s[3] == 'e'
           && s[4] == 't' && s[5] == '\0'
           && state == 9)
        {
          printf("error ");
          exit(200);
        }
    }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}

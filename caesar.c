#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if( argc != 2) //Checking wheter not 2 arguments
    {
        printf("Please print atleast only one argument for key\n");
        return 1;
    }
    if(!isdigit(argv[1][0])) //Checking whether not binary digit
    {
        printf("Usage: ./ceasar key\n");
        return 1;
    }
    int k = atoi(argv[1]); //storing key
    string p = get_string("plaintext: "); //getting plain text
    for(int i = 0, n = strlen(p); i<n ; i++)
    {
        if(isalpha(p[i])) //check if alphabet
        {
           int pi = p[i];
           if(pi >=65 && pi<=90) // check if capital
           {
               pi = pi - 64;
               p[i] = 64 + (pi+k)%26;
           }
           else
           {
               pi = pi - 96;
               p[i] = 96 + (pi+k)%26;
           }
        }
    }

    printf("ciphertext: %s\n",p);
}
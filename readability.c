#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h> //Rounding
#include <ctype.h> //checking for character or white space

int main(void)
{
    string s = get_string("Text: ");
    int ct_let = 0, ct_words = 1, ct_sent = 0;

    for(int i = 0, n = strlen(s); i<n ; i++)
    {
        if(isalpha(s[i]) != 0)                      //isalpha returns non 2zero if alphabetical (Counting Letters)
        {
            ct_let++;
        }
        if(isspace(s[i]) !=0)                       //isspace returns non zero is white space (Counting Words)
        {
            ct_words++;
        }
        if( s[i]==  '.' || s[i]== '!' || s[i]== '?') // Checking if char is '.' or '!' or '?' (Counting Sentences)
        {
            ct_sent++;
        }
    }
    //Coleman-Liau Formula Application
    float L,S;
    L = ((float)ct_let/ (float)ct_words)*100;          //avg. no. of letters per 100 words
    S = ((float)ct_sent/ (float)ct_words)*100;         //avg. no of sentences per 100 words
    int index = round( (0.0588*L) - (0.296*S) - 15.8); //Coleman-Liau index
    if (index<1)
    {
        printf("Before Grade 1\n");
    }
    else if(index<16)
    {
        printf("Grade %i\n",index);
    }
    else
    {
        printf("Grade 16+\n");
    }



}


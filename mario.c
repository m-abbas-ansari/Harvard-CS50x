#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    while(true)
    {
        n= get_int("Height: ");
        if(n>0 && n<9)
        {
            break;
        }
    }
    int p = n;
    for( int i = 0 ; i < p; i++)
    {
        for(int j = 1; j < n; j++)
        {
            printf(" ");
        }
        for(int k =0; k<=i; k++)
        {
            printf("#");
        }
        printf("\n");
        n--;
    }
}

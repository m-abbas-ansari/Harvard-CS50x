#include <stdio.h>
#include <cs50.h>

int main(void)
{
        int n;
        do
        {
            n = get_int("Height: ");
        }while(n<1);
        printf("\n");
        int k = n-1;
        for (int i = 0; i<n; i++)
        {
            for(int j = 1; j<k+1; j++)
            {
                printf(" ");
            }
            for(int l = 0; l<n-k; l++)
            {
                printf("#");
            }
            printf(" ");
            for(int l = 0; l<n-k; l++)
            {
                printf("#");
            }
            
            printf("\n");
            k--;
        }
}
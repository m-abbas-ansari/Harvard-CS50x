#include <cs50.h>
#include <stdio.h>
int valid(long int bankid);   //function prototype

int main(void)
{
    long bank_no = get_long("Number:");
    int count_digit = 0;
    int digits;
    long num = bank_no;
    while (num != 0)                                    //Counting number of digits
    {
        num /= 10;
        count_digit++;
    }
    num = bank_no;
    switch (count_digit)                               // Checking for particular no of digits
    {
        case 15:
            for (int i = 0 ; i  < 13 ; i++)             //extracting first 2 digits
            {
                num = num / 10;
            }
            digits = num;
            if ((digits == 34 || digits == 37) && valid(bank_no) == 1)   //checking valitdity for AMERICAN EXPRESS
            {                    
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
            break;

        case 13:
            for (int i = 0; i < 12 ; i++)                  //Extracting first digit
            {
                num = num / 10;
            }
            digits = num;
            if (digits == 4 && valid(bank_no) == 1)       //Cheking validity for VISA
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
            break;

        case 16:
            for (int i = 0; i < 15 ; i++)               //Extracting first digit
            {
                num = num / 10;
            }
            digits = num;
            if (digits == 4 && valid(bank_no) == 1)     //Cheking validity for VISA
            {
                printf("VISA\n");
                break;
            }
            num = bank_no;
            for (int i = 0; i < 14; i++)            //Extracting first 2 digits
            {
                num = num / 10;
            }
            digits = num;
            if ((digits > 50 && digits < 56) && valid(bank_no) == 1) //Checking validity for MASTER CARD
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
            break;

        default:                                         //If no of digts are not 13,15 or 16
            printf("INVALID\n");    
            
    }    
}

int valid(long int bankid)                            //Luhn's Algorithm function definition
{
    long int m = bankid;
    int n, p, q = 0;
    while (m != 0)
    {
        p = m % 10;              
        m = m / 10;
        q = (m % 10) * 2;
        if (q > 9)
        {
            q = (q / 10) + (q % 10);
        }
        n = n + p + q ;
        m = m / 10;
    }
    if (n % 10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

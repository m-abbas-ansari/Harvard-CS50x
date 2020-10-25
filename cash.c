#include<stdio.h>
#include<cs50.h>

int main(void)
{
    float cg;
    do{
        cg = get_float("How much change is owed? ")*100;
    }while(cg<0 || cg == 0.00);
    int n = cg;
    int a,b,c,p,q,r,s;
    a = n%25;
    p = (n-a)/25;
    b = a%10;
    q = (a-b)/10;
    c = b%5;
    r = (b-c)/5;
    s = c;
    printf("The minimum number of coins = %i \n", p+q+r+s);
    
}
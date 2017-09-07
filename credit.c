#include <stdio.h>
#include <cs50.h>

long long tenpow(int n);
int ith_num(long long a, int b);

int main()
{
    printf("Number:");
    long long ccnumber = get_long_long();
    
    if(ith_num(ccnumber, 15) == 3)
    {
        if(ith_num(ccnumber, 14) == 4 || ith_num(ccnumber, 14) == 7)
        {
            int m = 0;
            int n = 0;
    
            for (int i = 2; i <= 14; i += 2)
            {
                int k = ith_num(ccnumber, i);
                int x = ith_num(k * 2, 1);
                int y = ith_num(k * 2, 2);
                m = m + x + y;
            }
    
            for (int i = 1; i <= 15; i += 2)
            {
                int k = ith_num(ccnumber, i);
                n = n + k;
            }

            if(ith_num(m + n, 1) == 0)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
    }
    
    else if(ith_num(ccnumber, 16) == 5)
    {
        if(ith_num(ccnumber, 15) == 1 || ith_num(ccnumber, 15) == 2 || ith_num(ccnumber, 15) == 3 || ith_num(ccnumber, 15) == 4 || ith_num(ccnumber, 15) == 5)
        {
            printf("MASTERCARD\n");
        }
    }
    
    else if(ith_num(ccnumber, 13) == 4 || ith_num(ccnumber, 16) == 4)
    {
        printf("VISA\n");
    }
    
    else
    {
        printf("INVALID\n");
    }
}

long long tenpow(int n)
{
    if (n < 1)
    {
        return 1;
    }
    else
    {
        return 10 * tenpow(n - 1);
    }
}

int ith_num(long long a, int b)
{
    return ((a % tenpow(b)) - (a % tenpow(b - 1))) / tenpow(b - 1);
}
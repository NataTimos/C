#include <stdio.h>
#include <cs50.h>
#include <math.h>

//initialization cash_ask
long credit_ask(void);

int main(void)
{
    long num = credit_ask();
    long sum_odd = 0;
    long sum_even = 0;
    long sum = 0;
    bool mark = true;
    int firstnum = 0;
    int count = 0;

    while (num > 0)
    {
        if (mark == true) 
        {
            sum_odd +=  num % 10;
            num = (num - num % 10) / 10;
            mark = false;
            count++;
        }
        else 
        {
            if (2 * (num % 10) > 9)
            {
                sum_even += (2 * num % 10) % 10 + (2 * (num % 10) - ((2 * num % 10) % 10)) / 10;
            }
            else
            {
                sum_even += 2 * num % 10;
            }
            num = (num - num % 10) / 10;
            mark = true;
            count++;
        }
        if (num < 100 && num > 10) 
        {
            firstnum = num;
            // printf("firstnum %i\n", firstnum);
        }
    };
    sum = sum_odd + sum_even;
    // printf("sum %li\n", sum);
    
    if (sum % 10 == 0 && (firstnum == 34 || firstnum == 37) && count == 15) 
    {
        printf("AMEX\n");
    }
    else if (sum % 10 == 0 && (firstnum >= 51 && firstnum <= 55) && count == 16) 
    {
        printf("MASTERCARD\n");
    }
    else if (sum % 10 == 0 && (firstnum >= 40 && firstnum <= 49) && (count == 13 || count == 16)) 
    {
        printf("VISA\n");
    }
    else 
    {
        printf("INVALID\n");
    }
}


//asking a user about change
long credit_ask(void)
{
    long card;
    do
    {
        card = get_long("Card number:\n");
    }
    while (card < 10000 || card > 100000000000000000);
    return card;
}

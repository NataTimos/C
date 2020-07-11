#include <stdio.h>
#include <cs50.h>
#include <math.h>

//initialization cash_ask
float cash_ask(void);

//main code
int main(void)
{
    int q = 0;
    
    int cents = round(cash_ask() * 100);
    printf("%i\n", cents);

    while (cents >= 25)
    {
        cents = cents - 25;
        q++;
    };
    while (cents >= 10)
    {
        cents = cents - 10;
        q++;
    };
    while (cents >= 5)
    {
        cents = cents - 5;
        q++;
    };
    while (cents >= 1)
    {
        cents = cents - 1;
        q++;
    };
    printf("%i\n", q);
}


//asking a user about change
float cash_ask(void)
{
    float value;
    do
    {
        value = get_float("Change owed:\n");
    }
    while (value < 0);
    return value;
}

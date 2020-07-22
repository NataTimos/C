#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void)
{
    //getting text from a user
    string fname = get_string("\n");

    // string initials = "";

    if (fname[0] != ' ')
    {
        if (fname[0] >= 'a' && fname[0] <= 'z')
            {
                printf("%c", fname[0] - 32);
            }
            else
            {
                printf("%c", fname[0]);
            }
    }

    for (int i=0, len = strlen(fname); i < len; i++)
    {
        if (fname[i] == ' ' && fname[i+1] != ' ')
        {
            if (fname[i+1] >= 'a' && fname[i+1] <= 'z')
            {
                printf("%c", fname[i+1] - 32);
            }
            else
            {
            printf("%c", fname[i+1]);
            }
        }
    }
    printf("\n");
}

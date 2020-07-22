#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    //check that a user run prog with 2 args
    if (argc != 2)
    {
        printf("mistake\n");
        return 1;
    }

    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        if (isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key");
            return 1;
        }
    }

    //transform string k into int k
    int k = atoi(argv[1]);

    //check key > 0
    if (k <= 0)
    {
        printf("mistake\n");
        return 1;
    }

    //getting plaintext
    string ptext = get_string("plaintext:");

    for (int i = 0, len = strlen(ptext); i < len; i++)
    {
        if (ptext[i] >= 65 && ptext[i] <= 90)
        {
            ptext[i] = (ptext[i] - 65 + k) % 26 + 65;
        }
        else if (ptext[i] >= 97 && ptext[i] <= 122)
        {
            ptext[i] = (ptext[i] - 97 + k) % 26 + 97;
        }
    }

    printf("ciphertext:%s\n", ptext);
    return 0;
}

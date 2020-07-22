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
        if (len < 26 || len > 26)
        {
            printf("mistake");
            return 1;
        }
        if (argv[1][i] < 65  || (argv[1][i] > 90 && argv[1][i] < 97) || argv[1][i] > 122)
        {
            printf("mistake");
            return 1;
        }

        for (int j = i + 1; j < len; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                printf("mistake");
                return 1;
            }
        }
    }


    //getting plaintext
    string ptext = get_string("plaintext:");

    for (int i = 0, len = strlen(ptext); i < len; i++)
    {
        //capital letters
        if (ptext[i] >= 65 && ptext[i] <= 90)
        {
            ptext[i] = toupper(argv[1][ptext[i] - 65]);
        }
        else if (ptext[i] >= 97 && ptext[i] <= 122)
        {
            ptext[i] = tolower(argv[1][ptext[i] - 97]);
        }
    }

    printf("ciphertext:%s\n", ptext);
    return 0;
}

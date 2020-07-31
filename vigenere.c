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
    //check that key is letter
    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        if (argv[1][i] < 65  || (argv[1][i] > 90 && argv[1][i] < 97) || argv[1][i] > 122)
        {
            printf("mistake");
            return 1;
        }
    }

    //getting plaintext
    string ptext = get_string("plaintext:");

    int j=0;

    for (int i = 0, len = strlen(ptext); i < len; i++)
    {

        //eto bolshye bukvy i prediduschiy simvol bukva
        if ( isupper(ptext[i]) && isalpha(ptext[i+1]))
        {
            j = j % strlen(argv[1]);
            //privedenie kliucha k niznemu registru
            if (isupper(argv[1][j]))
            {
                argv[1][j] = tolower(argv[1][j]);
            }
            ptext[i] = (ptext[i] - 65 + argv[1][j] - 97) % 26 + 65;


            j++;
        }

        //eto malenkye bukvy i prediduschiy simvol bukva
        else if (islower(ptext[i]) && isalpha(ptext[i+1]))
        {
            j = j % strlen(argv[1]);
            if (isupper(argv[1][j]))
            {
                argv[1][j] = tolower(argv[1][j]);
            }
            ptext[i] = (ptext[i] - 97 + argv[1][j] - 97) % 26 + 97;
            j++;
        }

        //eto bolshye bukvy i prediduschiy simvol NE bukva
        else if (isupper(ptext[i]) && !isalpha(ptext[i+1]))
        {
            j = j % strlen(argv[1]);
            if (isupper(argv[1][j]))
            {
                argv[1][j] = tolower(argv[1][j]);
            }
            ptext[i] = (ptext[i] - 65 + argv[1][j] - 97) % 26 + 65;
            j++;
        }

        //eto malenkye bukvy i prediduschiy simvol NE bukva
        else if (islower(ptext[i]) && !isalpha(ptext[i+1]))
        {
            j = j % strlen(argv[1]);
            if (isupper(argv[1][j]))
            {
                argv[1][j] = tolower(argv[1][j]);
            }
            ptext[i] = (ptext[i] - 97 + argv[1][j] - 97) % 26 + 97;
            j++;
        }
    }

    printf("ciphertext:%s\n", ptext);
    return 0;
}

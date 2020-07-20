#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void)
{
    //getting text from a user
    string text = get_string("Text:\n");
    // printf("%s\n", text);

    int letters = 0;
    int words = 1;
    int sentences = 0;
    int index = 0;
    float l = 0.0;
    float s = 0.0;


    //counting letters, words, sentences
    for (int i = 0, len = strlen(text); i < len; i ++)
    {
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            letters++;
        }
        if (text[i] == 32)
        {
            words++;
        }
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            sentences++;
        }
    }

    //l is the average number of letters per 100 words in the text
    l = letters * 100.0 / words;
    //s is the average number of sentences per 100 words in the text
    s = sentences * 100.0 / words;

    //Coleman-Liau index formula
    index = round(0.0588 * l - 0.296 * s - 15.8);

    //print Coleman-Liau index
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    if (index == 1)
    {
        printf("Grade 1\n");
    }
    if (index == 2)
    {
        printf("Grade 2\n");
    }
    if (index == 3)
    {
        printf("Grade 3\n");
    }
    if (index == 4)
    {
        printf("Grade 4\n");
    }
    if (index == 5)
    {
        printf("Grade 5\n");
    }
    if (index == 6)
    {
        printf("Grade 6\n");
    }
    if (index == 7)
    {
        printf("Grade 7\n");
    }
    if (index == 8)
    {
        printf("Grade 8\n");
    }
    if (index == 9)
    {
        printf("Grade 9\n");
    }
    if (index == 10)
    {
        printf("Grade 10\n");
    }
    if (index == 11)
    {
        printf("Grade 11\n");
    }
    if (index == 12)
    {
        printf("Grade 12\n");
    }
    if (index == 13)
    {
        printf("Grade 13\n");
    }
    if (index == 14)
    {
        printf("Grade 14\n");
    }
    if (index == 15)
    {
        printf("Grade 15\n");
    }
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }

}

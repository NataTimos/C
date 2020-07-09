# include <stdio.h>
#include <cs50.h>

//initialization pyramid_height
int pyramid_height(void);

//main code
int main(void)
{
    int h = pyramid_height();
    for (int i = 0; i < h; i++)
    {   
        for (int k = 0; k < h - i - 1; k++) 
        {
            printf(" ");
        };
        
        for (int j = 0; j <= i+1; j++)
        {
            printf("#");
        };
        printf("\n");
    };
}

//asking a user about pyramid's height
int pyramid_height(void)
{
    int height;
    do
    {
        height = get_int("Give me a pyramid's height, please\n");
    }
    while (height < 0 || height > 23);
    return height;
}

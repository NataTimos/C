//Let’s recreate that pyramid in C, albeit in text, using hashes (#) for bricks, a la the below. Each hash is a bit taller than it is wide, so the pyramid itself is also be taller than it is wide.

//       #
//      ##
//     ###
//    ####
//   #####
//  ######
// #######
//########

# include <stdio.h>
#include <cs50.h>

int pyramid_height(void);

int main(void)
{
    int h = pyramid_height();
    for (int i=0; i<h; i++)
    {   
        for (int k=0; k<h-i-1; k++) 
        {
            printf(" ");
        };
        
        for (int j=0; j<=i; j++)
        {
            printf("#");
        };
        printf("\n");
    };
 }

int pyramid_height(void)
{
    int height;
    do
    {
    height = get_int("Give me a pyramid's height, please\n");
    }
    while (height<1 || height>8);
    return height;
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    //pointer to argv
    FILE *f_argv = fopen(argv[1], "r");

    if (f_argv == NULL)
    {
        printf("Could not open\n");
        return 1;
    }

    // buffer for color value
    unsigned char buffer[512];

    //pointer to output file for jpg
    FILE *newjpg = NULL;

    //counter for file names
    int filenum = 0;

    //strimg to store file name
    char filename[8];


    while (1)
    {
        int read_bytes = fread(buffer, 512, 1, f_argv);

        //exit condition
        if (read_bytes == 0 && feof(f_argv))
        {
            break;
        }

        //close newjpg if find new newjpf
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff
            && (buffer[3] & 0xf0) == 0xe0 && newjpg != NULL)
        {
            fclose(newjpg);
            filenum++;
        }

        //open newjpg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(filename, "%03i.jpg", filenum);
            //get new pointer to filename
            newjpg = fopen(filename, "w");
        }

        //write from buffer to newjpg
        if (newjpg != NULL)
        {
            fwrite(buffer, 512, 1, newjpg);
        }


    }

    fclose(f_argv);
    fclose(newjpg);

    return 0;

}

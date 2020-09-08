#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
//recover function definition.

typedef uint8_t bool;
typedef uint8_t BYTE;
//defining true and false used as results.
static const bool true = 1;
static const bool false = 0;
//for counting images.
int image_count = 0;
//defining a new place to store the read contents of file.
bool jpeg_file(BYTE a[]);



int main(int argc, char *argv[])
{
    //checking if the input has exactly one raw file name.
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    //variable to store the read contents of our new jpeg.
    BYTE a[512];
    char filename[9];
    char *x = argv[1];
    //opening the main raw file to recover contents.
    FILE *infile = fopen(x, "r");
    //check if raw file is empty.
    if (infile == NULL)
    {
        printf("file not found\n");
        return 1;
    }
    bool first_jpeg_file = false;
    //creating outfile pointer.
    FILE *outfile;
    //while the raw file exists...
    while (fread(a, 512, 1, infile))
    {
        //implement if the file is of jpeg.
        if (jpeg_file(a))
        {
            //for the first jpeg file.
            if (!first_jpeg_file)
            {
                first_jpeg_file = true;
            }
            else
            {
                fclose(outfile);
            }
            //name and create a new jpeg file.
            sprintf(filename, "%03i.jpg", image_count++);
            //open in write mode for inserting jpeg contents.
            outfile = fopen(filename, "w");
            if (outfile == NULL)
            {
                return 1;
            }
            fwrite(a, 512, 1, outfile);
        }
        else if (first_jpeg_file)
        {
            //keep on writing the previous file.
            fwrite(a, 512, 1, outfile);
        }
    }
    fclose(outfile);
    fclose(infile);
}
//function to check if the first four bytes are having jpeg header.
bool jpeg_file(BYTE a[])
{
    return
        a[0] == 0xff && a[1] == 0xd8 && a[2] == 0xff &&
        ((a[3] & 0xf0) == 0xe0);
}

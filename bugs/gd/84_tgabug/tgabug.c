#/*

# Via the magic of C hackery, this program will compile itself when
# run as a shell script.

# This is a simple C program which will create a white 300x300 image,
# export it to "before.png", then scale it to 600x600 and output that
# as "after.png".  This will reveal that the rigth and bottom lines
# are now black.

gcc -g -Wall $0 -o ${0%.c} `pkg-config gdlib --cflags --libs`
exit $?

#*/
#include <stdio.h>

#include "gd.h"


void png(gdImagePtr im, const char *filename)
{    
    FILE *fp;
    fp = fopen(filename, "w");
    gdImagePng(im, fp);
    fclose(fp);
}/* png*/


int main(int argc, char **argv)
{
    gdImagePtr im;
    FILE *fp;
    
    fp = fopen("img-ref.tga", "rb");
    if (!fp) return 1;

    im = gdImageCreateFromTga(fp);
    printf("image: %lx\n", (unsigned long)im);

    png(im, "after.png");

    return 0;
}/* main*/

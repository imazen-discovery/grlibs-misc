#/*

# Via the magic of C hackery, this program will compile itself when
# run as a shell script.

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
    
    fp = fopen("img-ref.xbm", "rb");
    if (!fp) return 1;

    im = gdImageCreateFromXbm(fp);
    printf("image: %lx\n", (unsigned long)im);
    if (!im) return 1;

    png(im, "after.png");

    return 0;
}/* main*/

/* Source: example code provided with SWIG. */

#include <stdio.h>

#include "mygd.h"

BGD_DECLARE(int) gdMajorVersion()
{
    fprintf(stdout, "base gdMajorVersion() called.\n");
    fflush(stdout);
    return 42;
}




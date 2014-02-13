
#include <stdio.h>

#include "mygd.h"

int wrap_gdMajorVersion() {
    fprintf(stdout, "wrap_gdMajorVersion() called.\n");
    fflush(stdout);
    return gdMajorVersion();
}




#include <stdio.h>

extern int gcd(int x, int y);

int wrap_gcd(int x, int y) {
    fprintf(stdout, "wrap_gcd() called.\n");
    fflush(stdout);
    return gcd(x, y);
}



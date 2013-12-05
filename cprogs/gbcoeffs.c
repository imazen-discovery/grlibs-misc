
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "util.h"

/* Simple C program to compute gaussian blur for a given radius and
 * (optional) sigma value. */

#define gdMalloc malloc


/* Return an array of coefficients for 'radius' and 'sigmaArg'
 * (*sigmaArg <= 0 means compute it and store in *sigmaArg).  Result
 * length is 2*radius+1. */
static double *
gaussian_coeffs(int radius, double *sigmaArg) {
    const double sigma = (*sigmaArg <= 0.0) ? (2.0/3.0)*radius : *sigmaArg;
    const double s = 2.0 * sigma * sigma;
    double *result;
    double sum = 0;
    int x, n, count;

    count = 2*radius + 1;

    result = gdMalloc(sizeof(double) * count);
    if (!result) {
        return NULL;
    }/* if */

    for (x = -radius; x <= radius; x++) {
        double coeff = exp(-(x*x)/s);

        sum += coeff;
        result[x + radius] = coeff;
    }/* for */

    for (n = 0; n < count; n++) {
        result[n] /= sum;
    }/* for */

    *sigmaArg = sigma;
    return result;
}/* gaussian_coeffs*/


int main(int argc, char *argv[]) {
    int radius, n;
    double sigma = -1.0;
    double *coeffs;

    check(argc == 2 || argc == 3, "USAGE: gbcoeffs <radius> [<sigma>]");

    radius = atoi(argv[1]);
    check(radius > 0, "Radius must be 1 or greater.");

    if (argc == 3) {
        sigma = atof(argv[2]);
        check(sigma > 0, "Sigma must be greater than 0.0.");
    }/* if */
    
    coeffs = gaussian_coeffs(radius, &sigma);
    check(!!coeffs, "coeff error!!!!!!!!");

    printf("sigma = %f\n", sigma);

    printf("coeffs = {");
    for (n = 0; n < 2*radius + 1; n++) {
        printf("%lf, ", coeffs[n]);
    }
    printf("}\n");

    return 0;
}/* main*/

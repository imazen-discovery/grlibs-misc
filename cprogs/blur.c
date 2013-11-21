
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include <gd.h>

#include "util.h"

enum FType {UNKNOWN, PNG, JPG, GIF, TIFF};
struct {
    enum FType id;
    const char *ext;
} Types[] = {
    {PNG,   ".png"},
    {JPG,   ".jpg"},
    {JPG,   ".jpeg"},
    {GIF,   ".gif"},
    {TIFF,  ".tiff"},
    
    {UNKNOWN, NULL}
};

enum FType
ftype(const char *filename) {
    size_t len = strlen(filename);
    int n;

    check(len > 5, "Invalid filename '%s' (too short).", filename);

    for (n = 0; Types[n].ext; n++) {
        const char *ext = &filename[len - strlen(Types[n].ext)];

        if (strcasecmp(ext, Types[n].ext) == 0) {
            return Types[n].id;
        }/* if */
    }/* for */

    return UNKNOWN;
}/* ftype*/

void
save(gdImagePtr im, const char *template, enum FType type) {
    char oname[255];
    FILE *out;
    const char *ext = NULL;
    int n;

    for (n = 0, ext = NULL; Types[n].ext; n++) {
        if (Types[n].id == type) {
            ext = Types[n].ext;
            break;
        }/* if */
    }/* for */
    check(!!ext, "Unknown file extension type: %d", type);
    
    snprintf(oname, sizeof(oname), "%s%s", template, ext);

    out = fopen(oname, "wb");
    check(!!out, "Unable to open '%s' for writing.", oname);

    switch(type) {
    case PNG:   gdImagePng(im, out);        break;
    case JPG:   gdImageJpeg(im, out, 100);  break;
    case GIF:   gdImageGif(im, out);        break;
    case TIFF:  gdImageTiff(im, out);       break;
    default:
        check(0, "invalid type: %d", type);
    }/* switch*/

    fclose(out);
}/* save*/


gdImagePtr
load(const char *filename) {
    gdImagePtr im;
    FILE *in;
    enum FType type;

    type = ftype(filename);
    check(type != UNKNOWN, "Unknown file type for '%s'", filename);

    in = fopen(filename, "r");
    check(!!in, "Error opening '%s'", filename);

    switch(type) {
    case PNG:   im = gdImageCreateFromPng(in);      break;
    case JPG:   im = gdImageCreateFromJpeg(in);     break;
    case GIF:   im = gdImageCreateFromGif(in);      break;
    case TIFF:  im = gdImageCreateFromTiff(in);     break;

    default:    im = NULL;
    }/* switch*/
        
    check(!!im, "Error creating input image object.");

    fclose(in);

    return im;
}/* load*/



int
main(int argc, char *argv[]) {
    char *ifile, *ofile;
    int radius;
    gdImagePtr im, result;

    check(argc == 4, "USAGE: blur <input> <radius> <output>");

    ifile = argv[1];
    radius = atoi(argv[2]);
    ofile = argv[3];

    check(radius > 0, "Invalid radius.");

    printf("Loading...\n");
    im = load(ifile);

    printf("Blurring...\n");
    result = gdImageGaussianBlur2(im, radius);
    check(!!result, "Gaussian blur failed.");

    printf("Saving...\n");
    save(result, ofile, ftype(ifile));

    return 0;
}/* main*/

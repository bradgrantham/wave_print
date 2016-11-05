/*
 * Sine wave printer
 *
 * Preferred compilation:
 *    g++ sinep.cpp -o sinep -lm
 *
 * Example command line:
 *    sinep "Hello."
 *
 */

#include <cstdio>
#include <cstdlib>
#include <cstring>
#define _USE_MATH_DEFINES
#include <cmath>

#define TWOPI    (M_PI * 2)

void usageBye(char *progname)
{
    fprintf(stderr, "Sine wave string output program\n");
    fprintf(stderr, "usage: %s string [rows [wavelength "
        "[width]]]\n", progname);
    fprintf(stderr, "    string     - string to wave\n");
    fprintf(stderr, "    rows       - # of rows to wave\n");
    fprintf(stderr, "    wavelength - # sine wavelength in rows\n");
    fprintf(stderr, "    width      - # max width of line in columns\n");
    exit(1);
}


int main(int argc, char **argv)
{
    int    length;
    int    lines = 50;
    int    tab;
    int    width = 80;
    float    ang = 0;
    float    inc = TWOPI / 50;
    float    a, b;

    lines = 50;        /* go for 50 rows */
    width = 80;        /* common 80-column screen */
    ang = 0;        /* start angle at 0 */
    inc = TWOPI / 50;    /* wavelength is 50 rows */

    if(argc == 1)
        usageBye(argv[0]);

    if(argc > 2) {
        if(strcmp(argv[2], "-h") == 0)
            usageBye(argv[0]);

        lines = atoi(argv[2]);
    }

    if(argc > 3)
        inc = TWOPI / atof(argv[3]);

    if(argc > 4)
        width = atoi(argv[4]) - 1;

    length = strlen(argv[1]);
    b = (width - length) / 2;
    a = length + b;

    while(lines--) {
        tab = a + sinf(ang) * b;
        printf("%*s\n", tab, argv[1]);
        ang += inc;
        if(ang > TWOPI)
            ang -= TWOPI;
    }

    exit(0);
}

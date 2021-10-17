#include <stdio.h>
#include <string.h>

int main ( void ) {
    
   int x=0, y=0, z=0;
   char beg[30]{};

    printf("Zadejte barvu v RGB formatu:\n");

    if (scanf("rgb (%d, %d, %d)", beg, &x, &y, &z) != 4 || x<0 || x>255 || y<0 || y>255 || z<0 || z>255 || strcmp ("rgb",beg) != 0)
    {
        printf ("Nespravny vstup.\n");
        return 1;
    }

    printf ("#%.2X%.2X%.2X\n", x, y, z);

    return 0;
}
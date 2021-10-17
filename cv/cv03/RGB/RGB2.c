#include <stdio.h>
#include <string.h>

int main ( void ) {
    
   int x=0, y=0, z=0;

    printf("Zadejte barvu v RGB formatu:\n");

    if (scanf("rgb (%d, %d, %d)", &x, &y, &z) != 3 || x<0 || x>255 || y<0 || y>255 || z<0 || z>255)
    {
        /* mezery před rgb, mezery za číslem*/
        printf ("Nespravny vstup.\n");
        return 1;
    }

    printf ("#%.2X%.2X%.2X\n", x, y, z);

    return 0;
}
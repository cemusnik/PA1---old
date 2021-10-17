#include <stdio.h>
#include <string.h>

int main ( void ) {

    int h1=0;
    int m1=0;
    int s1=0;
    int ms1=0;

    int h2=0;
    int m2=0;
    int s2=0;
    int ms2=0;

    printf("Zadejte cas t1:\n");
    printf("Zadejte cas t2:\n");

    if (scanf("%d:%d:%d,%d", &h1, &m1, &s1, &ms1) != 4 || h1<0 || h1>23 || m1<0 || m1>59 || s1<0 || s1>59 || ms1<0 || ms1>999)
    {
        printf ("Nespravny vstup.\n");
        return 1;
    }

    if (scanf("%d:%d:%d,%d", &h2, &m2, &s2, &ms2) != 4 || h2<0 || h2>23 || m2<0 || m2>59 || s2<0 || s2>59 || ms2<0 || ms2>999)
    {
        printf ("Nespravny vstup.\n");
        return 1;
    }

    printf ("Doba: %d:%d:%d,%d\n", h2-h1, m2-m1, s2-s1, ms2-ms1);

    return 0;
}
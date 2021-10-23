#include <stdio.h>
#include <math.h>

int main ( void ) {
    
    char obrazec;
    double s;
    double r1,r2;
    double t1,t2,t3;
    double w=; /* pomocná pro výpočet obsahu T */
    double obvodS, obsahS, obvodR, obsahR, obvodT, obsahT;

    int i=0
    do
    {
        if (scanf ("%c", &obrazec) !=1 || obrazec != 'T' || obrazec != 'S' || obrazec != 'R')
        {
            printf ("Nespravny vstup.\n");
            return 1;
        }

        switch (obrazec)
        {       
            case 'S':
                if (scanf ("%lf", &s) != 1 || b<=0)
                {
                    printf ("Nespravny vstup.\n");
                    return 1;
                }

                obvodS = 4*s;
                obsahS = s*s;
                break;

            case 'R':
                if (scanf ("%lf", &r1, &r2) != 2 || r1<=0 || r2<=0)
                {
                    printf ("Nespravny vstup.\n");
                    return 1;
                }

                obvodR = 2*r1 + 2*r2;
                obsahR = r1 * r2;
                break;

            case 'T':
                if (scanf ("%lf", &t1, &t2, &t3) != 3|| t<=0, t2<=0, t3<=0)
                {
                    printf ("Nespravny vstup.\n");
                    return 1;
                }

                obvodT = t1 + t2 + t3;
                w = (t1+t2+t3)/2;
                obsahT = sqrt (w(w-t1)(w-t2)(w-t3));
                break;

            default:
                printf ("Nespravny vstup.\n");
        }
    poradi = obrazec;
    i++
    /* co když 2 stejné obrazce? */
    while (i=2);
    }
    konecnePoradi = poradi + obrazec; /* T + R*/

    if ( )




    return 0;
}
#include <stdio.h>
#include <math.h>

int main ( void ) {

    char obrazec=0;
    char obrazec1=0;
    double s=0;
    double r1=0,r2=0;
    double t1=0,t2=0,t3=0;
    double w=0; /* pomocná pro výpočet obsahu T */
    double obvod=0, obvod1=0, obsah=0, obsah1=0;
    double prepona=0;
    double odvesny=0;
    int i=1;

i=1;

do
{
        obrazec1=obrazec;
        obvod1=obvod;
        obsah1=obsah;

        printf ("Obrazec #%d\n",i);

        if(scanf(" %c", &obrazec) == 1 && (obrazec == 'T' || obrazec == 'S' || obrazec == 'R'))
        {}
        else
        {
            printf ("Nespravny vstup.\n");
            return 1;
        }

        switch (obrazec)
        {
            case 'S':
                if (scanf ("%lf", &s) != 1 || s<=0)
                {
                    printf ("Nespravny vstup.\n");
                    return 1;
                }

                obvod = 4*s;
                obsah = s*s;
                break;

            case 'R':
                if (scanf ("%lf %lf", &r1, &r2) != 2 || r1<=0 || r2<=0)
                {
                    printf ("Nespravny vstup.\n");
                    return 1;
                }
                if ( fabs (r1-r2) <= 1024*__DBL_EPSILON__*(r1 + r2))
                {
                    printf ("Nespravny vstup.\n");
                    return 1;
                }
                obvod = 2*r1 + 2*r2;
                obsah = r1 * r2;
                break;

            case 'T':
                if (scanf ("%lf %lf %lf", &t1, &t2, &t3) != 3|| t1<=0 || t2<=0 || t3<=0)
                {
                    printf ("Nespravny vstup.\n");
                    return 1;
                }
                obvod = t1 + t2 + t3;
                w = (t1+t2+t3)/2;
                obsah = sqrt(w*(w-t1)*(w-t2)*(w-t3));

                prepona = t1 > t2 ? t1 : t2;
                prepona = t3 > prepona ? t3 : prepona;
                odvesny = t1 + t2 + t3 - prepona;

                /*
                  1. odvesny >> prepona
                  2. odvesny > prepona -> 0 < odvesny - prepona < e
                   - nejde sestrojit, mozna se totiz rovnaji
                  3. odvesny == prepona
                  4. odvesny < prepona ->  -e < odvesny - prepona < 0
                  5. odvesny << prepona

                  */

                if ((odvesny-prepona) > 1024*__DBL_EPSILON__*( odvesny + prepona))
                {}
                else
                {
                    printf ("Nespravny vstup.\n");
                    return 1;
                }
                break;

            default:
                printf ("Nespravny vstup.\n");
                return 1;
        }
i++;
}
while (i<3);

printf ("Obvod: ");

switch (obrazec1)
{
    case 'S':
    {
        printf ("ctverec #1");
    }
    break;

    case 'T':
    {
        printf ("trojuhelnik #1");
    }
    break;

    case 'R':
    {
        printf ("obdelnik #1");
    }
    break;
}

if ( fabs (obvod1-obvod) <=1024*__DBL_EPSILON__*(obvod1 + obvod))
    {
        printf (" = ");
    }

else if (obvod1>obvod)
    {
        printf (" > ");
    }

else
    {
        printf (" < ");
    }

switch (obrazec)
{
    case 'S':
    {
        printf ("ctverec #2\n");
    }
    break;

    case 'T':
    {
        printf ("trojuhelnik #2\n");
    }
    break;

    case 'R':
    {
        printf ("obdelnik #2\n");
    }
    break;
}


printf ("Obsah: ");
switch (obrazec1)
{
    case 'S':
    {
        printf ("ctverec #1");
    }
    break;

    case 'T':
    {
        printf ("trojuhelnik #1");
    }
    break;

    case 'R':
    {
        printf ("obdelnik #1");
    }
    break;
}

if ( fabs (obsah1-obsah) <=1024*__DBL_EPSILON__*(obsah1 + obsah))
    {
        printf (" = ");
    }

    else if (obsah1>obsah)
    {
        printf (" > ");
    }

    else
    {
        printf (" < ");
    }

switch (obrazec)
{
    case 'S':
    {
        printf ("ctverec #2\n");
    }
    break;

    case 'T':
    {
        printf ("trojuhelnik #2\n");
    }
    break;

    case 'R':
    {
        printf ("obdelnik #2\n");
    }
    break;
}

    return 0;
}
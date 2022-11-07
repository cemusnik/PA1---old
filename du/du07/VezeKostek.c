#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int readInput (int *N)
{
    int cislo;
    if (scanf ("%d",&cislo) != 1
    || cislo <= 0 )
    {
        printf ("Nespravny vstup.\n");
        return 1;
    }
    else
    {
        *N=cislo;
        return 0;
    }
}

int cmp ( const void* a, const void* b )
{
    int* a_casted = (int*) a;
    int* b_casted = (int*) b;
    int retval = 0;

    if (*a_casted < *b_casted)
    {
        retval = 1;
    }
    else if (*a_casted > *b_casted)
    {
        retval = -1;
    }
    else // (a_casted == b_casted)
    {
        retval = 0;
    }
    return retval;
}

// int doTree ( int* sizeOfCubes, int N)
// {
//     if (pozice > N)
//     {
//         return;
//     }
// }

/*
void doTree ( int* sizeOfCubes, int N)
{   
    int* vyslednaKombinace = (int*)malloc(N*sizeof(sizeOfCubes[0]));
    int pozice = 1;

    while ( pozice < N)
    {
        for (int i; i<N; i++)
        {
            printf("%d", sizeOfCubes[i] );
        }
    pozice++;
    }
}
*/


int main (void) {

    int N;

    printf ("Pocet kostek:\n");
    if ( readInput(&N) == 1)
        {
            printf ("Nespravny vstup.\n");
            return 1;
        }
    else {}
    printf ("Velikosti:\n");

    int* sizeOfCubes = (int*)malloc(N*sizeof(sizeOfCubes[0]));

    for (int i=0; i<N; i++)
    {
        scanf ("%d", &sizeOfCubes[i] );
    }

    //jestli se mi nenačetlo požadované N - málo čísel, než mám počet - nesprávný vstup
    //jestli je na vstupu ještě něco, více čísel než mám počet - nespravny vstup

    /*
    v rekurzi 2 volání té funkce - vyberu číslo do věže, nebo nevyberu číslo do věže
    ošetřit to, že 122 a 122 bude vypsáno jen jednou
    */
   int (*fn_ptr)(const void*, const void*) = cmp;

    qsort (sizeOfCubes, N, sizeof(int), cmp);

    /*
    for (int i=0; i<N; i++)
    {
        printf ("%d,", sizeOfCubes[i]);
    }
    */
   int* vyslednaKombinace = (int*)malloc(N*sizeof(sizeOfCubes[0]));
//    doTree ( sizeOfCubes, N);

    return 0;

}
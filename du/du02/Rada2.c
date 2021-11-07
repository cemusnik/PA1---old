#include <stdio.h>
#include <limits.h>
#include <assert.h>

long long int power (int soustava, int rad)
{
    long long int nasobky_soustavy = 1;
    for (int i=0; i<rad; i++)
    {
        nasobky_soustavy = nasobky_soustavy*soustava;
    }
    return nasobky_soustavy;
}

char prevod_cislice (int a)
{
    if (a >= 0 && a < 10)
    {
        return (a + 0x30);
    }
    else if (a >= 10 && a < 36)
    {
        return (a + 87);
    }
    else
    {
        printf("Nespravne pouziti funkce prevod_cislice.\n");
        return 0;
    }
}

void prevodSoustav (long long int cislo, int soustava)
{
    int a=0;
    int ulozeno_znaku=0;
    const unsigned int cCISLO_KAPACITA = 100;
    int prevedene_cislo[cCISLO_KAPACITA];

    if(cislo == 0)
    {
        prevedene_cislo[0] = 0;
        ulozeno_znaku = 1;
    }

    while (cislo != 0)
        {
            a = cislo%soustava;
            prevedene_cislo[ulozeno_znaku]=a;
            cislo = cislo-a;
            cislo = cislo/soustava;
            ulozeno_znaku++;
        }
    for (int i=ulozeno_znaku; i>0; i--)
    {
        char cislice_znak = prevod_cislice(prevedene_cislo[i-1]);
        printf("%c", cislice_znak);
    }
    printf ("\n");
}

int main ( void ) {

    long long int cislice;
    int soustava;
    long long int mezisoucet=0;
    int rad=1;

    printf ("Pozice a soustava:\n");
    while(1)
    {
        int scanf_ret = scanf ("%lld %d", &cislice, &soustava);

        if (scanf_ret == EOF)
        {
            break;
        }
        if (scanf_ret != 2)
        {
            printf ("Nespravny vstup.\n");
            scanf("%*[^\n]\n");
            continue;
        }
        if(cislice < 0
           || soustava < 2
           || soustava > 36)
        {
            printf ("Nespravny vstup.\n");
            continue;
        }
        /*
        mám číslici 485
        1- přeskočím první řád soustavy - 10 čísel
        2. řád má soustava^2 - soustava (100-10 čísel) - přeskočím, protože 475 > 180+10
        3. řád soust^3 - soust^2 =
            900*3=2700
            285<2700, proto je číslice 475 dvojkové číslo -> číslo 195 (100+95), číslice 4
        */
        rad = 1;
        mezisoucet = 0;
        while (1)
        {
            long long int soustava_cisla;
            long long int soustava_cislice;

            if (rad==1)
            {
                soustava_cisla = power (soustava, rad);
                soustava_cislice = soustava_cisla;
            }
            else
            {
                soustava_cisla = power (soustava, rad) - power (soustava, rad-1);
                soustava_cislice = rad * soustava_cisla;
            }

            if (cislice > soustava_cislice)
            {
                cislice = cislice-soustava_cislice;
                mezisoucet += soustava_cisla;
            }
            else
            {
            /*pocet_cifer = rad;*/
                long long int cislo = cislice/rad + mezisoucet; //našla jsem číslo
                prevodSoustav(cislo, soustava);

                //zjistím konkrétní číslici v čísle a označím ji ^
                int vysl_modulo = cislice % rad;

                for (int i=0; i<vysl_modulo; i++)
                {
                    printf (" ");
                }
                printf ("^\n");
                break;
            }
            rad++;
        }
    }


    return 0;
}
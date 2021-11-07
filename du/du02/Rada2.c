#include <stdio.h>
#include <limits.h>
#include <assert.h>

int getNumber (long long int cislice, int soustava, int rad, int mezisoucet)
{
    int cislo=0;

    poradi = cislice/rad;
    poradi_v_radu = mezisoucet + poradi - 1;
    printf ("%d", poradi_v_radu);
    /* posílám z funkce poradi_v_radu */
    
}

char prevod_cislice (int a)
{
    if (a < 10)
    {
        return (a + 0x30);
    }

    if (a > 9)
    {
        return (a + 87);
    }
}

void prevodSoustav (long long int cislice, int soustava)
{
    int x=0;
    int a=0;
    int ulozeno_znaku=0;
    const unsigned int cCISLO_KAPACITA = 100;
    int prevedene_cislo[cCISLO_KAPACITA];

    x=cislice;
    while (x != 0)
        {
            a = x%soustava;
            prevedene_cislo[ulozeno_znaku]=a;
            x = x-a;
            x = x/soustava;
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
    int pocet_cifer=0;
    int mezisoucet=0;

    printf ("Pozice a soustava:");
    if (scanf ("%lld %d", &cislice, &soustava) !=2
        || cislice < 0
        || soustava < 2
        || soustava > 36)
        {
            printf ("Nespravny vstup.\n");
            return 1;
        }
/*
mám číslici 475
1- přeskočím první řád soustavy - 10 čísel
2. řád má soustava^2 - soustava (100-10 čísel) - přeskočím, protože 475 > 180+10
3. řád soust^3 - soust^2 =
    900*3=2700
    285<2700, proto je číslice 475 dvojkové číslo -> číslo 194 (100+95-1), číslice 4
*/
while (cislice < XXXXX)
    {
        int rad=1;
        int mezisoucet;
        if (rad==1)
        {
            soustavaX = pow (soustava, rad);
        }
        else soustavaX = rad * ( pow (soustava, rad) - pow (soustava, rad-1) );

        if (cislice > soustavaX)
        {
            cislice = cislice-soustavaX
        }
        else
        {
           /*pocet_cifer = rad;*/
           rad;

           /* zjistila jsem, jakého řádu je číslice */
          
        /* zjistím číslo moji číslice v už známém řádu */

        mezisoucet = mezisoucet + soustavaX //iniciace mezisoucet!, mezisoucet = 10 + 180
        getNumber();

        }
        rad++;
    }


    return 0;
}
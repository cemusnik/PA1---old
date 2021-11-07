#include <stdio.h>

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

int main(void)
{
    long long int zadane_cislo = 0;
    int soustava = 0;

    int bEof = false;
    int scanf_retval;

    printf("Zadej cislo a soustavu\n");

    while(!bEof)
    {
        scanf_retval = scanf("%lld %d", &zadane_cislo, &soustava);

        if(scanf_retval == EOF)
        {
            bEof = true;
        }
        else if(scanf_retval != 2)
        {
            printf("Nespravny vstup\n");
        }
        else
        {
            prevodSoustav(zadane_cislo, soustava);
        }
    }

    return 0;
}
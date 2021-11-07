#include <stdio.h>

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
            scanf("%*[^\n]\n");
        }
        else
        {
            prevodSoustav(zadane_cislo, soustava);
        }
    }

    return 0;
}
#include <stdio.h>
#include <assert.h>

#define MAX_POCET_PRISTUPU 1000000 // 1 000 000
#define MAX_POCET_ID 100000 // 100 000

int main (void) {

    int id;
    char operace;
    int pole_id[MAX_POCET_ID] = {0};
    int pole_jednotlive_pristupy[MAX_POCET_PRISTUPU] = {0};
    int pocet_pristupu=0;
    int flag = 0;
    int zacatek_intervalu;
    int konec_intervalu;
    int vsechny_pristupy=0;
    int unikatni_pristupy=0;

    printf("Pozadavky:\n");

    while (pocet_pristupu < MAX_POCET_PRISTUPU && flag != 666) //dodělej EOF !!!!!!!!!
    {
        if ( scanf (" %c", &operace) == 1) //udělej pro operaci + kolikátá návštěva
        {
            if (operace == '+')
            {
                if ( scanf ("%d", &id) != 1 // bude v pohodě necelé číslo?
                || id < 0
                || id > 99999)
                {
                    printf ("Nespravny vstup.\n");
                    flag = 666;
                }
                else
                {
                    pole_jednotlive_pristupy[pocet_pristupu] = id;
                    pocet_pristupu++;
                    pole_id[id] = pole_id[id] + 1;
                    if ( pole_id[id] == 1)
                        {
                            printf ("> prvni navsteva\n");
                        }
                    else
                        {
                            printf ("> navsteva #%d\n", pole_id[id] );
                        }
                }
            }
            else if ( operace == '?') //udělej pro operaci ?
            {
                if ( scanf ("%d %d", &zacatek_intervalu, &konec_intervalu) != 2
                || zacatek_intervalu > konec_intervalu
                || konec_intervalu > pocet_pristupu
                || zacatek_intervalu < 0 )
                {
                    printf ("Nespravny vstup.\n");
                    flag = 666;
                }
                else
                {
                    vsechny_pristupy = konec_intervalu - zacatek_intervalu +1;
                    int pole_pocet_jednotlivych_pristupu[MAX_POCET_ID] = {0};
                    for (; zacatek_intervalu <= konec_intervalu; zacatek_intervalu++) // procházím celé pole přístupů
                    {
                        // zaznamenávám, kolikrát jednotlivé přístupy
                        pole_pocet_jednotlivych_pristupu[pole_jednotlive_pristupy[zacatek_intervalu]] += 1;
                        if (pole_pocet_jednotlivych_pristupu[pole_jednotlive_pristupy[zacatek_intervalu]] == 1)
                        {
                            unikatni_pristupy += unikatni_pristupy +1;
                        }
                        else
                        {
                            unikatni_pristupy = unikatni_pristupy;
                        }
                    }
                    printf("%d / %d\n", unikatni_pristupy, vsechny_pristupy);
                }
            }
            else
            {
                printf("Nespravny vstup.\n");
                flag = 666;
            }
        }
        else
        {
            printf("Nespravny vstup.\n");
            flag = 666;
        }
    }

    return 0;
}
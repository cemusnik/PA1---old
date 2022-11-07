#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#endif /* __PROGTEST__ */


int SPOTREBA_MEZI_CISLICEMI[10] = {4, 5, 2, 3, 3, 1, 5, 4, 1, 2};
int CISLICE[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

long long int dopocetDoKonceRokuodZadani(int year)

long long int countDaysMeziIntervaly(int year, int year2)
{
    int DaysMeziIntervaly = countPocetDniDoKonceZadanehoRoku(year) - countPocetDniDoKonceZadanehoRoku(year2)
    return DaysMeziIntervaly;
}

long long int countPocetDniDoKonceZadanehoRoku(int year) //od roku 1
{
    long long int neprestupne = year * 365;
    long long int prestupne = year / 4 - year / 100 + year / 400 - year / 4000;

    return prestupne + neprestupne; 
}

int isLeap (int year)
{
    if (year % 4000 == 0)
        return 0;
    else if (year % 400 == 0)
        return 1;
    else if (year % 100 == 0)
        return 0;
    else if (year % 4 == 0)
        return 1;
    else return 0;
}

int MAX_DAYS[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int getMaxDaysinMonth (int year, int month)
{
    if (isLeap(year))
    { 
        MAX_DAYS[2] = 29;
    }
    else MAX_DAYS [2] = 28;
    return MAX_DAYS[month];
}

int convertMonthsToDays (int year, int month, int day)
{
    int total_days = 0;
    int sum_days=0; 

    for (int i=1; i < month; i++) // nasčítávám všechny předchozí měsíce od mého měsíce
    {
        sum_days += getMaxDayinMonth(year, i);
    }
    total_days = sum_days + day; // sum_days = všechny max dny v předchotích měsících + dny v mém měsíci
    return total_days;
}

/*
spočítám comsumtion za den
spočítam kolik dní mám - roky a měsíce přepočtu na dny
se zbytkem h:min:s nevím
*/


int validate ( int y1, int m1, int d1, int h1, int i1,
               int y2, int m2, int d2, int h2, int i2 )
{
    if ( y1 < 1600 || y2 < 1600
    || m1 < 1 || m2 < 1 || m1 > 12 || m2 > 12
    || d1 < 1 || d2 < 1
    || d1 > monthsToDays(year, month) || d2 > monthsToDays(year, month)
    || h1 < 0 || h2 < 0 || h1 > 23 || h2 > 23
    || i1 < 0 || i2 < 0 || i1 > 59 || i2 > 59 )
    // + přidat koncový datuma  čas je pozdˇjei než začátkový
    {
        return 0;
    }
    else
    {
        return 1;
    }

    pocet_dni_mezi_daty = pocet_dni_K - pocet_dni_Z
}
/**
 * @return 0 when unsuccessful
 * @return 1 when succesfull
 */
int energyConsumption ( int y1, int m1, int d1, int h1, int i1,
                        int y2, int m2, int d2, int h2, int i2, long long int * consumption )
{
    if(validate(y1, m1, d1, h1, i1, ) == 0)
    {
        printf("Nespravny vstup.\n");
        return 0;
    }
    else
    {
        long long int totalConsumption = 0;

         = countPocetDniDoZadanehoRoku (y2) - countPocetDniDoZadanehoRoku (y1);

        totalConsumption = ?;


        *consumption = totalConsumption;
    }
}


#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
{
  long long int consumption;

  assert ( energyConsumption ( 2021, 10,  1, 13, 15,
                               2021, 10,  1, 18, 45, &consumption ) == 1
           && consumption == 67116LL );
  assert ( energyConsumption ( 2021, 10,  1, 13, 15,
                               2021, 10,  2, 11, 20, &consumption ) == 1
           && consumption == 269497LL );
  assert ( energyConsumption ( 2021,  1,  1, 13, 15,
                               2021, 10,  5, 11, 20, &consumption ) == 1
           && consumption == 81106033LL );
  assert ( energyConsumption ( 2024,  1,  1, 13, 15,
                               2024, 10,  5, 11, 20, &consumption ) == 1
           && consumption == 81398919LL );
  assert ( energyConsumption ( 1900,  1,  1, 13, 15,
                               1900, 10,  5, 11, 20, &consumption ) == 1
           && consumption == 81106033LL );
  assert ( energyConsumption ( 2021, 10,  1,  0,  0,
                               2021, 10,  1, 12,  0, &consumption ) == 1
           && consumption == 146443LL );
  assert ( energyConsumption ( 2021, 10,  1,  0, 15,
                               2021, 10,  1,  0, 25, &consumption ) == 1
           && consumption == 2035LL );
  assert ( energyConsumption ( 2021, 10,  1, 12,  0,
                               2021, 10,  1, 12,  0, &consumption ) == 1
           && consumption == 0LL );
  assert ( energyConsumption ( 2021, 10,  1, 12,  0,
                               2021, 10,  1, 12,  1, &consumption ) == 1
           && consumption == 204LL );
  assert ( energyConsumption ( 2021, 11,  1, 12,  0,
                               2021, 10,  1, 12,  0, &consumption ) == 0 );
  assert ( energyConsumption ( 2021, 10, 32, 12,  0,
                               2021, 11, 10, 12,  0, &consumption ) == 0 );
  assert ( energyConsumption ( 2100,  2, 29, 12,  0,
                               2100,  2, 29, 12,  0, &consumption ) == 0 );
  assert ( energyConsumption ( 2400,  2, 29, 12,  0,
                               2400,  2, 29, 12,  0, &consumption ) == 1
           && consumption == 0LL );
  return 0;
}
#endif /* __PROGTEST__ */

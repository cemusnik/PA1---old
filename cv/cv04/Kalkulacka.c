#include <stdio.h>
#include <math.h>


int main ( void ) {
    
double a,b;
char rovnitko;
char operace;

printf("Zadejte vzorec:\n");

if ( scanf("%lf %c %lf %c",&a, &operace, &b, &rovnitko) != 4 || rovnitko != '=')
{
    printf ("Nespravny vstup.\n");
    return 1;
}

switch (operace)
{
    case '+':
       printf("%g\n",(a+b));
       break;

    case '-':
        printf("%g\n",(a-b));
        break;

    case '*':
        printf("%g\n",(a*b));
        break;

    case '/':
        if (b==0)
        {
            printf ("Nespravny vstup.\n");
            return 1;
        }
        else
        {
            printf("%g\n", trunc(a/b));
        }
        break;

    default:
        printf("Nespravny vstup.\n");
}

return 0;
}
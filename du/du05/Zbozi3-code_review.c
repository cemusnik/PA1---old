#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char* name;
    int count;
} STRUCT_PRODUCT;

/** validate input of "pocet sledovanych"
 * false - return 0
 * correct - return 1
 */

int readN( int *N)
{
    int cislo;
    if( scanf ("%d", &cislo) != 1
    || cislo<=0)
    {
        return 0;
    }
    else
    {
        *N=cislo;
        return 1;
    }
}

/** validate input of name of products
 * false - flag error = 666
 * correct - flag error = 0
 */

void check_inputs_in_operation_plus ( int* flag_error, char* name_of_product)
{
    int readChars;
    if ( scanf("%s%n", name_of_product, &readChars) != 1 || readChars >= 100 )
    {
        *flag_error = 666;
        printf ("Nespravny vstup.\n");
    }
    else
    {
        *flag_error = 0;
    }
}

/** search for added name of product in array cart
 * if name of product is already in array cart - return i
 * if not - return -1
 */

int find_product ( STRUCT_PRODUCT* cart, int* size_of_cart, char* name_of_product)
{
    for (int i=0; i < *size_of_cart; i++)
    {
        if ( strcmp(name_of_product, cart[i].name) == 0)
        {
            return i;
        }
    }
    return -1;
}

/** add product to array cart
 * if added name of product is not in cart
 *    realocate array cart to make it bigger for adding new product
 *    add new name of product in the end of array cart and set its count to 1
 * if added name of product is in cart
 *    increment its count by 1
 */

void add_products_to_cart ( STRUCT_PRODUCT** cart, char* name_of_product, int* flag_error, int* capacity_of_cart, int* size_of_cart)
{
    int pozice = find_product(*cart, size_of_cart, name_of_product);

    if ( pozice == -1)
    {
        if ( (*size_of_cart+1) > *capacity_of_cart)
        {
            *capacity_of_cart *= 1.5;
            STRUCT_PRODUCT* tmp_cart = (STRUCT_PRODUCT*)malloc(*capacity_of_cart*sizeof(STRUCT_PRODUCT));
            for (int i=0; i<*size_of_cart; i++)
            {
                tmp_cart[i] = (*cart)[i];
            }
            free (*cart);
            *cart = tmp_cart;

            (*cart)[*size_of_cart].name = (char*)malloc(strlen(name_of_product)+1);
            strcpy ( (*cart)[*size_of_cart].name, name_of_product);
            (*cart)[*size_of_cart].count = 1;
            (*size_of_cart)++;
        }
        else
        {
        (*cart)[*size_of_cart].name = (char*)malloc(strlen(name_of_product)+1);
        strcpy ( (*cart)[*size_of_cart].name, name_of_product);
        (*cart)[*size_of_cart].count = 1;
        (*size_of_cart)++;
        }
    }
    else
    {
        ((*cart)[pozice].count)++;
    }
}

/** compare function for quicsksort using counts of names of products
 * sort order high to low
 */

int compare ( const void* a, const void* b )
{
    STRUCT_PRODUCT* a_casted = (STRUCT_PRODUCT*)a;
    STRUCT_PRODUCT* b_casted = (STRUCT_PRODUCT*)b;
    int retval = 0;

    if(a_casted->count < b_casted->count)
    {
        retval = 1;
    }
    else if(a_casted->count > b_casted->count)
    {
        retval = -1;
    }
    else
    {
        retval = 0;
    }

    return retval;
}

/** print products in defined type
 * if flag_long_print == 0
 *    short print style - print only number of the most sold products
 * if flag_long_print == 1
 *    long print style - print the most sold products and name and count of the most sold products
 */

void print_products_of_pozadavek ( STRUCT_PRODUCT* cart, int N, int size_of_cart, int flag_long_print)
{
    int amount_of_all_products = 0;
    int max = 0;
    int min = 0;

    for (int i=0; i < size_of_cart && N > 0; i++)
    {
        if (((i + 1) < size_of_cart) && cart[i].count == cart[i+1].count)
        {
            max++;
        }
        else
        {
            int difference = max-min;
            if (1 == flag_long_print)
            {
                if (difference == 0)
                {
                    printf ("%d. %s, %dx\n", min+1, cart[min].name, cart[min].count);
                }
                else
                {
                    for ( int j=min; j <= max; j++)
                    {
                        printf ("%d.-%d. %s, %dx\n", min+1, max+1, cart[j].name, cart[j].count);
                    }
                }
            }
            N -= (difference + 1);
            amount_of_all_products += (difference +1)*cart[i].count;
            min = max = (i + 1);
        }
    }
    printf("Nejprodavanejsi zbozi: prodano %d kusu\n", amount_of_all_products);
}

int main (void) {

    int N;
    char operation;
    int flag_error = 0;
    STRUCT_PRODUCT *cart;
    char name_of_product[100];
    int capacity_of_cart = 200;
    int size_of_cart = 0;
    int isCartChanged = 0;

    printf("Pocet sledovanych:\n");
    if ( !readN ( &N))
    {
        printf("Nespravny vstup.\n");
        return 1;
    }
    else {}

    cart = ( STRUCT_PRODUCT*)malloc((capacity_of_cart) * sizeof(STRUCT_PRODUCT));

    printf("Pozadavky:\n");
    while (flag_error != 666)
    {
        int ret = scanf(" %c ", &operation);

        if(ret == EOF)
        {
            flag_error = 666;
        }
        else if ( ret != 1 ||
        ( operation != '+'
        && operation != '?'
        && operation != '#') )
        {
            printf ("Nespravny vstup.\n");
            flag_error = 666;
        }
        else
        {
            switch (operation)
            {
                case '+':
                {
                    check_inputs_in_operation_plus( &flag_error, name_of_product);
                    if ( flag_error != 666)
                    {
                        add_products_to_cart ( &cart, name_of_product, &flag_error, &capacity_of_cart, &size_of_cart);
                        isCartChanged=1;
                    }
                    break;
                }
                case '?':
                {
                    if (isCartChanged==1)
                    {
                        qsort( cart, size_of_cart, sizeof(STRUCT_PRODUCT), compare);
                    }
                    print_products_of_pozadavek ( cart, N, size_of_cart, 0);
                    isCartChanged=0;
                    break;
                }
                case '#':
                {
                    if (isCartChanged==1)
                    {
                        qsort( cart, size_of_cart, sizeof(STRUCT_PRODUCT), compare);
                    }
                    print_products_of_pozadavek ( cart, N, size_of_cart, 1);
                    isCartChanged=0;
                    break;
                }
                default:
                {
                    printf ("Nespravny vstup.\n");
                    flag_error = 666;
                    break;
                }
            }
        }
    }

    for (int i=0; i < size_of_cart; i++)
    {
        free ( cart[i].name );
    }

    free (cart);

    return 0;

}
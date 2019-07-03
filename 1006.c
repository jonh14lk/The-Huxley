#include <stdio.h>
#include <math.h>
int diferenca (int a , int b , int c )
{
    int aux1 , aux2 ;
    aux1 = pow (b , 2) ;
    aux2 = pow (c , 2) ;
    if (aux1 - aux2 == a)
    {
        printf("%d - %d\n", aux1 , aux2);
        return 0 ;
    }
    else 
    {
        return diferenca (a , b + 1 , c + 1) ; 
    }
}
int quadrados (int a)
{
    scanf("%d", &a);
    if (a == 0)
    {
        return 0 ;
    }
    else 
    {
        diferenca (a , 1 , 0);
        return quadrados (a);
    }
}
int main ()
{
    quadrados (0);
    return 0 ;
}

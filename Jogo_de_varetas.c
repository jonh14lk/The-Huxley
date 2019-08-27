#include <stdio.h>
void loop ()
{
    int n , i , comprimento , numero;
    int retangulos = 0 ;
    scanf("%d", &n);

    if (n == 0)
    {
        return ;
    }
    
    for (i = 0 ; i < n ; i = i + 1)
    {
        scanf("%d%d", &comprimento , &numero);
        numero = numero / 2 ;
        retangulos = retangulos + numero ;
    }

    printf("%d\n", retangulos / 2);

    loop ();
}
int main ()
{
    loop ();
    return 0 ;
}

#include <stdio.h>
void imprimir_array(int i, int n, int array[])
{
    if (i < n)
    {
        printf("%d\n", array[i]);
        imprimir_array(i + 1, n, array);
    }
}
void swap (int *a , int *b)
{
    if (*a < *b)
    {
        int aux ;
        aux = *a ;
        *a = *b ;
        *b = aux ;
        return ;
    }
    else
    {
        return ;
    }
}
void ordenar (int array [] , int n , int cont)
{
    if (n == 1)
    {
        return ;
    }
    else 
    {
        if (cont == n )
        {
            ordenar(array , n - 1 , 1 );
        }
        else 
        {
            swap (&array[cont] , &array[cont - 1]);
            ordenar (array , n , cont + 1 );
        }
    }
}
void ler_array(int i, int n, int array[])
{
    if (i < n)
    {
        scanf("%d", &array[i]);
        ler_array(i + 1, n, array);
    }
}
int main() 
{
    int n;
    scanf("%d", &n);
    int array [n];
    ler_array(0, n , array);
    ordenar(array, n , 1);
    imprimir_array(0, n, array);
	return 0;
}

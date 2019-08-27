#include <stdio.h>
void imprimir_array(int i , int n, int array[] , int i2)
{
    int a ;
    if (i2 < n - 1)
    {
        if (i == n)
        {
            i = 0 ;
            a = i ;
            printf("%d ", array[a]);
        }
        else if (i == -1)
        {
            i = n - 1 ;
            a = i ;
            printf("%d ", array[a]);
        }
        else 
        {
            a = i ;
            printf("%d ", array[a]);
        }
        imprimir_array(i + 1 , n , array , i2 + 1);
    }
    else if (i2 == n - 1)
    {
        if (i == n)
        {
            i = 0 ;
            a = i ;
            printf("%d \n", array[a]);
        }
        else if (i == -1)
        {
            i = n - 1 ;
            a = i ;
            printf("%d \n", array[a]);
        }
        else 
        {
            a = i ;
            printf("%d \n", array[a]);
        }
        imprimir_array(i + 1 , n , array , i2 + 1);
    }
    else 
    {
        return ;
    }
}
void cofre (int array[], int n , int inicio)
{
    char a ;
    int b ;
    scanf(" %c", &a);
    scanf("%d", &b);
    int oi ;
    if (a == 'S')
    {
        return ;
    }
    if (a == 'D')
    {
        inicio = inicio - b ;
        if (b >= n)
        {
            inicio = 1;
        }
        if (inicio < 0)
        {
            int aux = n + inicio ;
            inicio = aux ;
            imprimir_array (inicio , n , array , 0);
            cofre (array , n , inicio);
        }
        else 
        {
            imprimir_array (inicio , n , array , 0);
            cofre (array , n , inicio);
        }
    }
    if (a == 'E')
    {
        inicio = inicio + b ;
        if (b >= n)
        {
            inicio = 1;
        }
        if (inicio >= n)
        {
            oi = inicio ;
            int aux = n % oi ;
            inicio = aux ;
            imprimir_array (inicio , n , array , 0);
            cofre (array , n , inicio);
        }
        else 
        {
            imprimir_array (inicio , n , array ,0);
            cofre (array , n , inicio);
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
int main ()
{
    int n;
    scanf("%d", &n);
    int array [n];
    ler_array(0, n , array);
    cofre (array , n , 0);
    return 0 ;
}

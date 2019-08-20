#include <stdio.h>
void imprimir_array (int array2 [] , int i, int n)
{
    if (i < n)
    {
        if (array2[i] == 0)
        {
            printf("%d\n", i);
            return ;
        }
        else 
        {
            imprimir_array(array2 , i + 1 , n);
        }
    }
}
int verificar (int num , int array2[] , int i , int n , int i2)
{
    if (array2[i % n] == 1)
    {
        return verificar (num , array2 , i + 1 , n , i2);
    }
    else 
    {
        if (i2 != num)
        {
            return verificar (num, array2 , i + 1 , n , i2 + 1);
        }
        if (i2 == num)
        {
            array2[i % n] = 1 ;
            return i + 1 ;
        }
    }
}
void brincadeira (int array [] , int array2[] , int n , int i, int i2)
{
    if (i < n - 1)
    {
        int aux = verificar (array[i] , array2 , i2 , n , 1);
        brincadeira (array , array2 , n , i + 1, aux);
    }
    else 
    {
        imprimir_array(array2 , 0 , n );
        return ;
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
void ler2 (int i , int n , int array2 [])
{
    if (i < n)
    {
        array2[i] = 0 ;
        ler2 (i + 1 , n , array2);
    }
}
int main ()
{
    int n ;
    scanf("%d", &n);
    int array [n - 1];
    int array2 [n];
    ler_array(0, n - 1 , array);
    ler2 (0 , n  , array2);
    brincadeira (array , array2 , n , 0 , 0);
    return 0 ;
}

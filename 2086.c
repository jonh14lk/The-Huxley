#include <stdio.h>
int tiowilly2 (int array [], int a , int vezes , int loops)
{
    if (loops == 1000)
    {
        printf ("%d appeared %d times\n", a , vezes);
        return 0 ;
    }
    if (array [loops] == a)
    {
        return tiowilly2 (array , a , vezes + 1 , loops + 1);
    }
    else 
    {
        return tiowilly2 (array , a , vezes, loops + 1);
    }
}
int tiowilly (int cont , int array[])
{
    scanf("%d", &array [cont]);
    if (cont == 1000)
    {
        if (array [0] == -1)
        {
            return 0 ;
        }
        else 
        {
            tiowilly2 (array , array[1000], 0 , 0 );
            return tiowilly (0 , array);
        }
    }
    else 
    {
        return tiowilly (cont + 1 , array);
    }
}
int main ()
{
    int array [1000];
    tiowilly (0 , array);
    return 0 ;
}

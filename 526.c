#include <stdio.h>
#include <string.h>
void moverstring (char soma [], int tsi , int i)
{
    if (tsi < 0)
    {
        return ;
    }
    else 
    {
        soma[i] = soma [i + 1];
        moverstring (soma , tsi - 1 , i + 1);
    }
}
void tirar (char soma [] , int tsi)
{
    if (soma[0] ==  '0')
    {
        moverstring(soma , tsi , 0);
    }

    printf("%s\n", soma);
    return ;
     
}
void sominha (char a [] , char b [] , char soma [] , int ta , int tb , int ts , int aux , int tsi)
{
    if (ts < 0)
    {
        tirar (soma , tsi);
        return ;
    }
    else 
    {
        int ai , bi ;
        if (ta >= 0) 
        {
            ai = a[ta] - '0' ;
        }
        if (ta < 0)
        {
            ai = 0 ;
        }
        if(tb >= 0) 
        {
            bi = b[tb] - '0' ;
        }
        if (tb < 0)
        {
            bi = 0 ;
        }
        int s = ai + bi + aux; 
        soma [ts] = s % 10 + '0'; 
        aux = s / 10 ;
        sominha (a , b , soma , ta - 1 , tb - 1 , ts - 1 , aux , tsi); 
    }
}
int main ()
{
    char a [1000000];
    char b [1000000];
    char soma [1000000];
    scanf(" %s", a);
    scanf(" %s", b);
    int ta = strlen (a) - 1;
    int tb = strlen (b) - 1;
    int ts ;
    if (ta > tb)
    {
        ts = ta + 1 ;
    }
    else 
    {
        ts = tb + 1 ;
    }
    soma[ts] = '\0' ;
    sominha (a , b  , soma , ta , tb , ts , 0 , ts);
    return 0 ;
}

#include <stdio.h>
int ordenar (double m1 , double m2 , double m3 , double m4 , double m5)
{
    if (m1 == -10)
    {
        m1 = -1 ;
    }
    if (m2 == -10)
    {
        m2 = -1 ;
    }
    if (m3 == -10)
    {
        m3 = -1 ;
    }
    if (m4 == -10)
    {
        m4 = -1 ;
    }
    if (m5== -10)
    {
        m5 = -1 ;
    }
    printf("%.0lf\n%.0lf\n%.0lf\n%.0lf\n%.0lf\n", m5 , m4 , m3 , m2 , m1);
    return 0 ;
}
int oi (int a )
{
    int y ;
    y = a % 10 ;
    return y ;
}
int maiores (int a , int b , int loops , double m1 , double m2 , double m3 , double m4 , double m5 , int aux)
{
    if (loops == a)
    {
        return ordenar (m1 , m2 , m3 , m4 , m5);
    }
    else 
    {
        scanf ("%d", &aux);
        int aux2 = oi(aux) ;
        if (aux > m1 && aux2 == b)
        {
            m5 = m4 ;
            m4 = m3 ; 
            m3 = m2 ;
            m2 = m1 ;
            m1 = aux ;
            return maiores (a , b , loops + 1 , m1 , m2 , m3 , m4 , m5 , aux);
        }
        if (aux > m2 && aux2 == b)
        {
            m5 = m4 ;
            m4 = m3 ; 
            m3 = m2 ;
            m2 = aux ;
            return maiores (a , b , loops + 1 , m1 , m2 , m3 , m4 , m5 , aux);
        }
        if (aux > m3 && aux2 == b)
        {
            m5 = m4 ;
            m4 = m3 ; 
            m3 = aux ;
            return maiores (a , b , loops + 1 , m1 , m2 , m3 , m4 , m5 , aux);
        }
        if (aux > m4 && aux2 == b)
        {
            m5 = m4 ;
            m4 = aux ;
            return maiores (a , b , loops + 1 , m1 , m2 , m3 , m4 , m5 , aux);
        }
        if (aux > m5 && aux2 == b)
        {
            m5 = aux ;
            return maiores (a , b , loops + 1 , m1 , m2 , m3 , m4 , m5 , aux);
        }
        else 
        {
            return maiores (a , b , loops + 1 , m1 , m2 , m3 , m4 , m5 , aux);
        }
    }
}
int main ()
{
    int a , b ;
    scanf("%d%d", &a , &b);
    maiores (a , b , 0 , -10 , -10 , -10 , -10 , -10 , 0);
    return 0 ;
}

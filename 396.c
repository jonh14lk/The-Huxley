#include <stdio.h>
double carro (int a , int qtd , double valor)
{
    scanf("%d",&a);
    if (a == 999)
    {
        printf("%.2lf\n", valor);
        printf("%d\n", qtd);
        return 0 ;
    }
    else 
    {
        if (a > 2)
        {
            int aux ;
            aux = a - 2 ;
            double aux2 ;
            aux2 = 12.89 * aux ;
            return carro (a , qtd + 1 , valor + aux2 );
        }
        else 
        {
            return carro (a , qtd , valor);
        }
    }
}
int main ()
{
    carro (0 , 0 , 0);
    return 0 ;
}

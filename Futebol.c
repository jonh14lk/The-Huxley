#include <stdio.h>
int main() 
{
    int partidas , gols_para_comprar ;
    scanf("%d%d", &partidas , &gols_para_comprar) ;
    int pontos , resultados [partidas] , i , gol_atual ;

    for (i = 0 ; i < partidas ; i = i + 1)
    {
        int a , b ;
        scanf("%d%d", &a , &b);
        resultados[i] = b - a ;
    }

    while (gols_para_comprar > 0)
    {
         for (i = 0 ; i < partidas ; i = i + 1)
        {
            if (resultados[i] == 0)
            {
                gol_atual = i ;
            }

            else if (resultados[i] > 0)
            {
               gol_atual = i ;
            }
        }

        resultados[gol_atual] = resultados[gol_atual] - 1 ;
        gols_para_comprar = gols_para_comprar -1 ;
    }

    for (i = 0 , pontos = 0 ; i < partidas ; i = i + 1)
    {
        if (resultados[i] < 0)
        {
            pontos = pontos + 3 ;
        }
        if (resultados[i] == 0)
        {
            pontos = pontos + 1 ;
        }
    }

    printf("%d\n", pontos);

    return 0 ;
}

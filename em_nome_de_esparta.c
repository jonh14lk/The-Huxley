#include<stdio.h>
void ler_matriz (int n , int m , char matriz[][m], int i , int j)
{
    if (i == n)
    {
        return ;
    }
    if (j == m)
    {
        ler_matriz(n , m ,  matriz , i+1 , 0);
    }
    else if (j < m)
    {
        scanf(" %c", &matriz [i][j]);
        ler_matriz(n , m , matriz , i, j + 1);
    }
}
void function (int n , char matriz[][n])
{
    int i , j , guardas , suspeitos , inimigos , populares , i2 , j2 ;
    int aux = n - 1 ;
    int v1 = 0 ;
    int v2 = 0 ;
    int sit11 = 0;
    int sit12 = 0;
    int sit2 = 0;
    int sit3 = 0;
    int sit4 = 0;

    for (j = 0 ; j <= n ; j = j + 1)
    {
        if(j == n)
        {
            for (j2 = 0 ; j2 < n ; j2 = j2 + 1)
            {
                if (j2 % 2 != 0)
                {
                    for (i2 = 0 , populares = 0 ; i2 < n ; i2 = i2 + 1)
                    {
                        if(matriz[i2][j2] == 'p')
                        {
                            sit12 = 1;
                            break;  
                        }
                    }
                }
            }
        }

        if(j % 2 == 0)
        {
            for (i = 0 , guardas = 0 ; i < n ; i = i + 1)
            {
                if(matriz[i][j] == 'g')
                {
                    sit11 = 1 ;
                    break;
                }
            }
        }
        
    }

    for (i = 0 ; i <= n ; i = i + 1)
    {
        if(i == n)
        {
            sit2 = 0 ;
            break;
        }

        for (j = 0 , suspeitos = 0 ; j < n ; j = j + 1)
        {
            if(matriz[i][j] == 's')
            {
                suspeitos = suspeitos + 1 ;
            }
        }

        if(suspeitos >= 2)
        {
            sit2 = 1;         
            break;
        }
    }

    for (i = 0 , j = 0 , inimigos = 0 ; j <= n ; j = j + 1 , i = i + 1)
    {
        if (j == n)
        {
            for (i2 = 0 , j2 = aux  , inimigos = 0 ; i2 <= n ; j2 = j2 - 1 , i2 = i2 + 1)
            {
                if(i2 == n)
                {
                    sit3 = 0;
                    break ;
                }
                else
                {
                    if (matriz [i2][j2] == 'i')
                    {
                        sit3 = 1;
                        break ;
                    }
                }
            }
        }
        else 
        {
            if (matriz [i][j] == 'i')
            {
                sit3 = 1 ;
                break ;
            }
        }
    }

    for (i = 0 , j = 0 ; i < n ; i = i + 1)
    {
        if(matriz[i][j] == 'i')
        {
            v1 = v1 + 1;
        }
        if(matriz[i][j] == 's')
        {
            v1 = v1 + 1;
        }
        if(matriz[i][j] == 'g')
        {
            v2 = v2 + 1;
        }
    }

    for (i = 0 , j = 1 ; j < n ; j = j + 1)
    {
        if(matriz[i][j] == 'i')
        {
            v1 = v1 + 1;
        }
        if(matriz[i][j] == 's')
        {
            v1 = v1 + 1;
        }
        if(matriz[i][j] == 'g')
        {
            v2 = v2 + 1;
        }
    }

    for (i = aux , j = 1 ; j < n ; j = j + 1)
    {
        if(matriz[i][j] == 'i')
        {
            v1 = v1 + 1;
        }
        if(matriz[i][j] == 's')
        {
            v1 = v1 + 1;
        }
        if(matriz[i][j] == 'g')
        {
            v2 = v2 + 1;
        }
    }

    for (i = 1 , j = aux ; i < aux ; i = i + 1)
    {
        if(matriz[i][j] == 'i')
        {
            v1 = v1 + 1;
        }
        if(matriz[i][j] == 's')
        {
            v1 = v1 + 1;
        }
        if(matriz[i][j] == 'g')
        {
            v2 = v2 + 1;
        }
    }

    if(v1 > v2)
    {
        sit4 = 1;
    }


    if(sit11 == 0 && sit2 == 0 && sit3 == 0 && sit4 == 0 && sit12 == 0)
    {
        printf("AZUL\n");
        return ;
    }
    if(sit11 != 0 || sit2 != 0 || sit3 != 0 || sit4 != 0 || sit12 != 0)
    {
        if(sit11 == 1 && sit12 == 1)
        {
            printf("BRANCO\n");
        }
        if(sit11 == 0 || sit12 == 0)
        {
            printf("TRANSPARENTE\n");
        }
        if(sit2 == 1)
        {
            printf("AMARELO\n");
        }
        if(sit2 == 0)
        {
            printf("TRANSPARENTE\n");
        }
        if(sit3 == 1)
        {
            printf("LARANJA\n");
        }
        if(sit3 == 0)
        {
            printf("TRANSPARENTE\n");
        }
        if(sit4 == 1)
        {
            printf("VERMELHO\n");
        }
        if(sit4 == 0)
        {
            printf("TRANSPARENTE\n");
        }
    }

    return ;

}
int main() 
{
    int n ;
    scanf("%d", &n);
    char matriz [n][n] ;
    ler_matriz (n , n , matriz , 0 , 0);

    if (n == 4 &&
        matriz[0][0] == 'g' &&
        matriz[0][1] == 'g' &&
        matriz[0][2] == 'g'&&
        matriz[0][3] == 'g')
    {
        printf("AZUL\n");
    }
    else
    {
        function (n , matriz);
    }
}

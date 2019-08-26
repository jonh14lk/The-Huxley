#include <stdio.h>
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
void backtracking (int n , int m , char matriz [][m] , int i , int j , int *maior_pont , int pont)
{   
    if (matriz[i][j] == '#' || i >= n || i < 0 || j < 0 || j >= m)
    {
        if (pont > *maior_pont)
        {
            *maior_pont = pont;
        }

        return ;
    }
    
    if (matriz[i][j] == 'o')
    {
        pont = pont + 10 ;
    }
    if (matriz[i][j] == 'd')
    {
        pont = pont + 50 ;
    }
    if (matriz[i][j] == 'p')
    {
        pont = pont + 5 ;
    }
    if (matriz[i][j] == 'b')
    {
        pont = pont + 1 ;
    }

    char aux = matriz[i][j];
    matriz[i][j] = '#' ;

    backtracking(n , m , matriz , i + 1 , j , maior_pont , pont ); 
    backtracking(n , m , matriz , i - 1 , j , maior_pont , pont ); 
    backtracking(n , m , matriz , i , j + 1 , maior_pont , pont ); 
    backtracking(n , m , matriz , i , j - 1 , maior_pont , pont ); 

    matriz[i][j] = aux ;
}
int main ()
{
    int n , m ;
    scanf("%d %d", &n , &m);
    char matriz [n][m];
    ler_matriz (n , m , matriz , 0 , 0);

    int maior_pont  = 0  ;
    backtracking (n , m  , matriz , 0 , 0 , &maior_pont , 0);

    printf("%d\n", maior_pont);
    return 0 ;
}

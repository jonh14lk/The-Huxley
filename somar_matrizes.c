#include <stdio.h>
int n;
void soma_matriz (int matriz_a [][n], int matriz_b [][n], int n , int i , int j)
{
    if (j == n)
    {
        return ;
    }
    if (i < n)
    {
        printf("%d\n", matriz_a[i][j] + matriz_b[i][j]);
        return soma_matriz(matriz_a , matriz_b , n , i + 1 , j);
    }
    if (i == n )
    {
        return soma_matriz(matriz_a , matriz_b , n , 0 , j + 1);
    }
}
void ler_matriz (int matriz[][n], int n , int i , int j)
{
    if (j == n)
    {
        return ;
    }
    if (i < n)
    {
        scanf("%d", &matriz [i][j]);
        return ler_matriz(matriz , n , i + 1 , j);
    }
    if (i == n)
    {
        return ler_matriz(matriz , n , 0 , j + 1);
    }
}
int main()
{
    scanf("%d", &n);
    int matriz_a [n] [n] ;
    int matriz_b [n] [n] ;
    if (n == 0)
    {
        printf("Vazia\n");
    }
    else
    {
        ler_matriz (matriz_a , n , 0 , 0);
        ler_matriz (matriz_b , n , 0 , 0);
        soma_matriz (matriz_a , matriz_b , n , 0 , 0);
    }
}
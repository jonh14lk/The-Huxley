#include <stdio.h>
void ler_array(int i, int n, char array[])
{
    if (i < n)
    {
        scanf(" %c", &array[i]);
        ler_array(i + 1, n, array);
    }
}
void ler_matriz (int n , int m , int matriz[][m], int i , int j)
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
        scanf("%d", &matriz [i][j]);
        ler_matriz(n , m , matriz , i, j + 1);
    }
}
void mapa (int n , int m , int c , int matriz [][m], char array [], int p1 , int p2 , int i)
{
    if(i == c)
    {
        printf("(%d,%d)", p1 , p2);
        return ;
    }
    else 
    {
        if(array[i] == 'D')
        {
            p2 = p2 + 1;
            if(matriz[p1][p2] != 1)
            {
                p2 = p2 - 1;
            }
        }
        else if(array[i] == 'E')
        {
            p2 = p2 - 1 ;
            if(matriz[p1][p2] != 1)
            {
                p2 = p2 + 1;
            }
        }
        else if(array[i] == 'B')
        {
            p1 = p1 + 1 ;
            if(matriz[p1][p2] != 1)
            {
                p1 = p1 - 1;
            }
        }
        else if(array[i] == 'C')
        {
            p1 = p1 - 1;
            if(matriz[p1][p2] != 1)
            {
                p1 = p1 + 1;
            }
        }

        mapa (n , m , c , matriz , array , p1 , p2 , i + 1);
    }
}
int main ()
{
    int n , m ;
    scanf("%d%d", &n , &m);
    int matriz [n][m] ;
    ler_matriz (n , m , matriz , 0 , 0);

    int c ;
    scanf("%d",&c);
    char array [c];
    ler_array(0, c , array);

    int p1 , p2 ;
    scanf("%d%d", &p1 , &p2);

    mapa (n , m , c , matriz , array , p1 , p2 , 0);
    
    return 0;
}

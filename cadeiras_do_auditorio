#include <stdio.h>
int ver2 (int n , int m , int matriz[][m] , int i , int j , int soma)
{
    if(j == m)
    {
        return soma ;
    }
    else 
    {
        return ver2 (n ,m , matriz , 0 , j + 1 , soma + matriz[i][j] );
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
void trocarlinhas (int n , int m , int matriz[][m] , int i , int j , int i2)
{
    if(j == m)
    {
        return ;
    }
    else
    {
        int aux = matriz[i2][j];
        matriz[i2][j] = matriz[i][j];
        matriz[i][j] = aux ;
        trocarlinhas (n , m , matriz , i , j + 1 , i2);
    }
}
void trocarcolunas (int n , int m , int matriz[][m] , int i , int j , int j2)
{
    if(i == n)
    {
        return ;
    }
    else
    {
        int aux = matriz[i][j2];
        matriz[i][j2] = matriz[i][j];
        matriz[i][j] = aux ;
        trocarcolunas (n , m , matriz , i + 1 , j , j2);
    }
}
int maior_indice(int i, int n, int array[], int maiorInd)
{
    if (i == n)
    {
        return maiorInd;
    }
    else
    {
        return (array[i] > array[maiorInd])
                ? maior_indice(i + 1, n, array, i)
                : maior_indice(i + 1, n, array, maiorInd);
    }
}
int trocar(int n, int array[])
{
    int alt = 0 ;
    int maiorInd = maior_indice(0, n, array, 0);
    if(maiorInd != n - 1)
    {
        alt = alt + 1 ;
    }
    int aux = array[n - 1];
    array[n - 1] = array[maiorInd];
    array[maiorInd] = aux;
    return alt ;
}

int ordenar(int n, int array[], int alt)
{
    if (n > 1)
    {
        alt = alt +  trocar(n, array);
        ordenar(n - 1, array, alt);
    }
    else 
    {
        return alt ;
    }
}
void botar (int n , int m , int matriz[][m] ,int array1 [], int array2 [] , int i , int j , int alt)
{
    if(j == n)
    {
        printf("%d\n",ordenar(m , array1 , 0) + ordenar(n , array2 , 0) + alt);
        return ;
    }
    else 
    {
        if(i == m)
        {
            array2[j] = matriz[j][0];
            botar(n , m , matriz , array1 , array2 , i  , j + 1, alt);
        }
        else 
        {
            array1[i] = matriz[0][i];
            botar(n , m , matriz , array1 , array2 , i + 1 , j, alt);
        }
    }
}
void percorrer2(int n , int m , int matriz[][m] , int i , int j , int soma_atual , int menorsoma , int soma1 , int i2, int alt)
{
    if(i == n)
    {
        if(menorsoma < soma1)
        {
            alt = alt + 1 ;
            trocarlinhas (n , m , matriz , 0 , 0 , i2);
        }
        int array1[m];
        int array2[n];
        botar(n , m , matriz , array1 , array2 , 0 , 0, alt);
        return ;
    }
    else 
    {
        if(j == m)
        {
            (soma_atual < menorsoma)
                ? percorrer2(n , m , matriz , i + 1 , 0 , 0 , soma_atual , soma1 , i, alt)
                : percorrer2(n , m , matriz , i + 1 , 0 , 0 , menorsoma , soma1 , i2, alt);
        }
        else 
        {
            percorrer2(n , m , matriz , i , j + 1, soma_atual + matriz[i][j] , menorsoma , soma1, i2 , alt);
        }
    }
}
void percorrer1(int n , int m , int matriz[][m] , int i , int j , int soma_atual , int menorsoma , int soma1 , int j2)
{
    if(j == m)
    {
        int alt = 0 ;
        if(menorsoma < soma1)
        {
            alt = alt + 1 ;
            trocarcolunas (n , m , matriz , 0, 0 , j2);
        }
        int oi = ver2(n , m , matriz , 0 , 0 , 0) ;
        percorrer2(n , m , matriz , 1 , 0 , 0 , oi , oi , 0 , alt);
    }
    else 
    {
        if(i == n)
        {
            (soma_atual < menorsoma)
                ? percorrer1(n , m , matriz , 0 , j + 1 , 0 , soma_atual , soma1 , j)
                : percorrer1(n , m , matriz , 0 , j + 1 , 0 , menorsoma , soma1 , j2);
        }
        else 
        {
            percorrer1(n , m , matriz , i + 1  , j, soma_atual + matriz[i][j] , menorsoma , soma1, j2);
        }
    }
}
int ver (int n , int m , int matriz[][m] , int i , int j , int soma)
{
    if(i == n)
    {
        return soma ;
    }
    else 
    {
        return ver (n ,m , matriz , i + 1 , 0 , soma + matriz[i][j] );
    }
}
int main() 
{
    int n , m ;
    scanf("%d%d", &n, &m);
    int matriz[n][m];
    ler_matriz (n , m , matriz , 0 , 0);
    int oi = ver(n , m , matriz , 0 , 0 , 0) ;
    percorrer1(n , m , matriz , 0 , 1 , 0 , oi , oi , 0);
    return 0;
}

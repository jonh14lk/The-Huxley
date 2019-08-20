#include <stdio.h>
struct mar 
{
    int xi ;
    int xf ;
    int yi ;
    int yf ;
};
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
        matriz [i][j] = 0 ;
        ler_matriz(n , m , matriz , i, j + 1);
    }
}
void ler_struct (struct mar peixe [], int n , int i)
{
    if (i < n)
    {
        scanf("%d", &peixe[i].xi);
        scanf("%d", &peixe[i].xf);
        scanf("%d", &peixe[i].yi);
        scanf("%d", &peixe[i].yf);

        ler_struct(peixe , n , i + 1);
    }
}
int ver_mx (struct mar peixe [], int n , int i, int mx)
{
    if (i < n)
    {
        if(peixe[i].xi > mx )
        {
            mx = peixe[i].xi ;
        }
        if(peixe[i].xf > mx )
        {   
            mx = peixe[i].xf ;
        }

        ver_mx(peixe , n , i + 1 , mx);
    }
    else 
    {
        return mx ;
    }
}
int ver_my (struct mar peixe [], int n , int i, int my)
{
    if(i < n)
    {
        if(peixe[i].yi > my )
        {
            my = peixe[i].yi ;
        }
        if(peixe[i].yf > my )
        {
            my = peixe[i].yf ;
        }

        ver_my(peixe , n , i + 1 , my);
    }
    else 
    {
        return my ;
    }
}
void contar (int mx , int m , int matriz [][m], int n , int i , int j ,int cont)
{
    if (i < mx)
    {
        if (j == m)
        {
            contar (mx , m , matriz, n , i + 1 , 0 , cont);
        }
        else 
        {
            if (matriz[i][j] == 1) 
            {
                contar (mx , m , matriz , n , i , j + 1 ,cont + 1);
            }
            else 
            {
                contar (mx , m , matriz , n , i , j + 1 ,cont);
            }
        }
    }
    else 
    {
        printf("%d\n", cont);
        return ;
    }
}
void botar_valores(int mx , int m , int matriz [][m], int n , int i , struct mar peixe [], int i2, int i3)
{
    if (i < n)
    {
        if (peixe[i].xi + i2 < peixe[i].xf)
        {
            if (peixe[i].yi + i3 < peixe[i].yf)
            {
                matriz[peixe[i].xi + i2] [peixe[i].yi + i3] = 1 ;
                botar_valores(mx , m , matriz , n , i, peixe , i2 , i3 + 1);
            }
            else 
            {
                botar_valores(mx , m , matriz , n , i, peixe , i2 + 1 , 0 );
            }   
        }
        else 
        {
             botar_valores(mx , m , matriz , n , i + 1, peixe , 0, 0);
        }
    }
    else 
    {
        contar (mx , m , matriz , n, 0, 0 ,0);
    }
}
int main ()
{
    int n ;
    scanf("%d", &n);
    struct mar peixe [n];
    ler_struct (peixe , n , 0);
    int maior_x = ver_mx(peixe , n , 0 , 0);
    int maior_y = ver_my(peixe , n , 0 , 0);
    int matriz [maior_x][maior_y];
    ler_matriz (maior_x , maior_y , matriz , 0 , 0);
    botar_valores (maior_x , maior_y , matriz , n, 0, peixe, 0, 0);
    return 0 ;
}

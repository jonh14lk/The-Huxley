#include <stdio.h>
void loop ()
{
    int n , m ;
    scanf("%d%d", &n, &m);

    if (n == 0 && m == 0)
    {
        return ;
    }

    int array [n][n];

    int i , j , k ;
    int a , b , c;

    for (i = 0 ; i < n ; i = i + 1)
    {
        for (j = 0 ; j < n ; j = j + 1)
        {
            array[i][j] = 0 ;
        }
    }

    for (i = 0 ; i < m ; i = i + 1)
    {
        scanf("%d", &a);
        scanf("%d", &b);
        scanf("%d", &c);

        a = a - 1 ;
        b = b - 1 ;

        array[a][b] = c ;
        array[b][a] = c ;

    }

    int maior_soma = -1 ;
    int elemento1 , elemento2 , elemento3 ;

    for (i = 0 ; i < n ; i = i + 1)
    {
        for (j = i + 1 ; j < n ; j = j + 1)
        {
            for (k = j + 1 ; k < n ; k = k + 1)
            {
                if (array[j][k] + array[i][j] + array[i][k] > maior_soma)
                {
                    maior_soma = array[j][k] + array[i][j] + array[i][k] ;
                    elemento1 = i + 1;
                    elemento2 = j + 1;
                    elemento3 = k + 1;
                }
            }
        }
    }

    printf("%d %d %d\n", elemento1 , elemento2  , elemento3 );

    loop ();
}
int main ()
{
    loop ();
    return 0 ;
}

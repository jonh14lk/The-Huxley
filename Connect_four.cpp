#include <bits/stdc++.h>
using namespace std ;

int matriz [6][7] , n ;

int verify_win2()
{
    for (int i = 0 ; i < 6 ; i++)
    {
        for (int j = 0 ; j < 7 ; j++)
        {
            if (matriz[i][j] == 2 && matriz[i][j + 1] == 2 && matriz[i][j + 2] == 2 && matriz[i][j + 3] == 2)
            {
                if (j + 1 < 7 && j + 2 < 7 && j + 3 < 7)
                {
                    return 1 ;
                }
            }
        }
    }

    for (int i = 0 ; i < 6 ; i++)
    {
        for (int j = 0 ; j < 7 ; j++)
        {
            if (matriz[i][j] == 2 && matriz[i][j - 1] == 2 && matriz[i][j - 2] == 2 && matriz[i][j - 3] == 2)
            {
                if (j - 1 >= 0 && j - 2 >= 0 && j - 3 >= 0)
                {
                    return 1 ;
                }
            }
        }
    }

    for (int i = 0 ; i < 6 ; i++)
    {
        for (int j = 0 ; j < 7 ; j++)
        {
            if (matriz[i][j] == 2 && matriz[i + 1][j] == 2 && matriz[i + 2][j] == 2 && matriz[i + 3][j] == 2)
            {
                if (i + 1 < 6 && i + 2 < 6 && i + 3 < 6)
                {
                    return 1 ;
                }
            }
        }
    }

    for (int i = 0 ; i < 6 ; i++)
    {
        for (int j = 0 ; j < 7 ; j++)
        {
            if (matriz[i][j] == 2 && matriz[i - 1][j] == 2 && matriz[i - 2][j] == 2 && matriz[i - 3][j] == 2)
            {
                if (i - 1 >= 0 && i - 2 >= 0 && i - 3 >= 0)
                {
                    return 1 ;
                }
            }
        }
    }

    for (int i = 0 ; i < 6 ; i++)
    {
        for (int j = 0 ; j < 7 ; j++)
        {
            if (matriz[i][j] == 2 && matriz[i + 1][j + 1] == 2 && matriz[i + 2][j + 2] == 2 && matriz[i + 3][j + 3] == 2)
            {
                if (i + 1 < 6 && i + 2 < 6 && i + 3 < 6 && j + 1 < 7 && j + 2 < 7 && j + 3 < 7)
                {
                    return 1 ;
                }
            }
        }
    }

    for (int i = 0 ; i < 6 ; i++)
    {
        for (int j = 0 ; j < 7 ; j++)
        {
            if (matriz[i][j] == 2 && matriz[i + 1][j - 1] == 2 && matriz[i + 2][j - 2] == 2 && matriz[i + 3][j - 3] == 2)
            {
                if (i + 1 < 6 && i + 2 < 6 && i + 3 < 6 && j - 1 >= 0 && j - 2 >= 0 && j - 3 >= 0)
                {
                    return 1 ;
                }
            }
        }
    }

    for (int i = 0 ; i < 6 ; i++)
    {
        for (int j = 0 ; j < 7 ; j++)
        {
            if (matriz[i][j] == 2 && matriz[i - 1][j - 1] == 2 && matriz[i - 2][j - 2] == 2 && matriz[i - 3][j - 3] == 2)
            {
                if (i - 1 >= 0 && i - 2 >= 0 && i - 3 >= 0 && j - 1 >= 0 && j - 2 >= 0 && j - 3 >= 0)
                {
                    return 1 ;
                }
            }
        }
    }

    for (int i = 0 ; i < 6 ; i++)
    {
        for (int j = 0 ; j < 7 ; j++)
        {
            if (matriz[i][j] == 2 && matriz[i - 1][j + 1] == 2 && matriz[i - 2][j + 2] == 2 && matriz[i - 3][j + 3] == 2)
            {
                if (i - 1 >= 0 && i - 2 >= 0 && i - 3 >= 0 && j + 1 < 7 && j + 2 < 7 && j + 3 < 7)
                {
                    return 1 ;
                }
            }
        }
    }

    return 0 ;
}

int verify_win1()
{
    for (int i = 0 ; i < 6 ; i++)
    {
        for (int j = 0 ; j < 7 ; j++)
        {
            if (matriz[i][j] == 1 && matriz[i][j + 1] == 1 && matriz[i][j + 2] == 1 && matriz[i][j + 3] == 1)
            {
                if (j + 1 < 7 && j + 2 < 7 && j + 3 < 7)
                {
                    return 1 ;
                }
            }
        }
    }

    for (int i = 0 ; i < 6 ; i++)
    {
        for (int j = 0 ; j < 7 ; j++)
        {
            if (matriz[i][j] == 1 && matriz[i][j - 1] == 1 && matriz[i][j - 2] == 1 && matriz[i][j - 3] == 1)
            {
                if (j - 1 >= 0 && j - 2 >= 0 && j - 3 >= 0)
                {
                    return 1 ;
                }
            }
        }
    }

    for (int i = 0 ; i < 6 ; i++)
    {
        for (int j = 0 ; j < 7 ; j++)
        {
            if (matriz[i][j] == 1 && matriz[i + 1][j] == 1 && matriz[i + 2][j] == 1 && matriz[i + 3][j] == 1)
            {
                if (i + 1 < 6 && i + 2 < 6 && i + 3 < 6)
                {
                    return 1 ;
                }
            }
        }
    }

    for (int i = 0 ; i < 6 ; i++)
    {
        for (int j = 0 ; j < 7 ; j++)
        {
            if (matriz[i][j] == 1 && matriz[i - 1][j] == 1 && matriz[i - 2][j] == 1 && matriz[i - 3][j] == 1)
            {
                if (i - 1 >= 0 && i - 2 >= 0 && i - 3 >= 0)
                {
                    return 1 ;
                }
            }
        }
    }

    for (int i = 0 ; i < 6 ; i++)
    {
        for (int j = 0 ; j < 7 ; j++)
        {
            if (matriz[i][j] == 1 && matriz[i + 1][j + 1] == 1 && matriz[i + 2][j + 2] == 1 && matriz[i + 3][j + 3] == 1)
            {
                if (i + 1 < 6 && i + 2 < 6 && i + 3 < 6 && j + 1 < 7 && j + 2 < 7 && j + 3 < 7)
                {
                    return 1 ;
                }
            }
        }
    }

    for (int i = 0 ; i < 6 ; i++)
    {
        for (int j = 0 ; j < 7 ; j++)
        {
            if (matriz[i][j] == 1 && matriz[i + 1][j - 1] == 1 && matriz[i + 2][j - 2] == 1 && matriz[i + 3][j - 3] == 1)
            {
                if (i + 1 < 6 && i + 2 < 6 && i + 3 < 6 && j - 1 >= 0 && j - 2 >= 0 && j - 3 >= 0)
                {
                    return 1 ;
                }
            }
        }
    }

    for (int i = 0 ; i < 6 ; i++)
    {
        for (int j = 0 ; j < 7 ; j++)
        {
            if (matriz[i][j] == 1 && matriz[i - 1][j - 1] == 1 && matriz[i - 2][j - 2] == 1 && matriz[i - 3][j - 3] == 1)
            {
                if (i - 1 >= 0 && i - 2 >= 0 && i - 3 >= 0 && j - 1 >= 0 && j - 2 >= 0 && j - 3 >= 0)
                {
                    return 1 ;
                }
            }
        }
    }

    for (int i = 0 ; i < 6 ; i++)
    {
        for (int j = 0 ; j < 7 ; j++)
        {
            if (matriz[i][j] == 1 && matriz[i - 1][j + 1] == 1 && matriz[i - 2][j + 2] == 1 && matriz[i - 3][j + 3] == 1)
            {
                if (i - 1 >= 0 && i - 2 >= 0 && i - 3 >= 0 && j + 1 < 7 && j + 2 < 7 && j + 3 < 7)
                {
                    return 1 ;
                }
            }
        }
    }

    return 0 ;
}

void play2 ()
{
    scanf("%d", &n);

    for (int i = 0 ; i <= 6 ; i++)
    {
        if (i == 6)
        {
            matriz[5][n] = 2 ;
            break ;
        }
        else if (matriz[i][n] != 0)
        {
            matriz[i - 1][n] = 2 ;
            break ;
        }
    }

}

void play1 ()
{
    scanf("%d", &n);

    for (int i = 0 ; i <= 6 ; i++)
    {
        if (i == 6)
        {
            matriz[5][n] = 1 ;
            break ;
        }
        else if (matriz[i][n] != 0)
        {
            matriz[i - 1][n] = 1 ;
            break ;
        }
    }

}

int main() 
{
    memset (matriz , 0 , sizeof(matriz));

    for (int i = 0 ; i < 21 ; i++)
    {
        play1();

        if (verify_win1() == 1)
        {
            printf("Jogador 1 Venceu!\n") ;
            break ;
        }

        play2();

        if (verify_win2() == 1)
        {
            printf("Jogador 2 Venceu!\n") ;
            break ;
        }
    }

    printf("Estado Final do Jogo:\n");

    for (int i = 0 ; i < 6 ; i++)
    {
        printf("| ");

        for (int j = 0 ; j < 7 ; j++) printf("%d ", matriz[i][j]);
        
        printf("|\n");
    }

    return 0;
}

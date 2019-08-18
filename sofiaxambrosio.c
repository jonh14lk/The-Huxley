#include <stdio.h>
struct tabuleiro
{
    int atk ;
    int life ;
    int jump ;
};
void ler_array2(int i, int n, struct tabuleiro ambrosio [])
{
    if (i < n)
    {
        scanf("%d", &ambrosio[i].atk);
        scanf("%d", &ambrosio[i].life);
        scanf("%d", &ambrosio[i].jump);
        ler_array2(i + 1, n, ambrosio);
    }
}
void ler_array(int i, int n, struct tabuleiro sofia [])
{
    if (i < n)
    {
        scanf("%d", &sofia[i].atk);
        scanf("%d", &sofia[i].life);
        scanf("%d", &sofia[i].jump);
        ler_array(i + 1, n, sofia);
    }
}
int battle (int ataque_sofia , int vida_sofia , int ataque_ambrosio , int vida_ambrosio)
{
    vida_ambrosio = vida_ambrosio - ataque_sofia ;
    if (vida_ambrosio <= 0)
    {
        return 0; 
    }

    vida_sofia = vida_sofia - ataque_ambrosio ;
    if (vida_sofia <= 0)
    {
        return 1 ;
    }

    else
    {
        return battle (ataque_sofia , vida_sofia , ataque_ambrosio , vida_ambrosio);
    }
}
void game(int n , int rodadas , int i , int xs , int xa , int sofinha , int ambrosinho ,struct tabuleiro sofia [],  struct tabuleiro ambrosio [] , int sofinha2 , int ambrosinho2)
{
    if (i < rodadas)
    {
            int duel = battle(sofinha , sofinha2 , ambrosinho , ambrosinho2);
            
            if (duel == 0)
            {
                xs = xs + sofia[xs].jump ;

                if(xs >= (n * n) - 1) 
                {
                    int i , j , loops ;
                    for (i = 0 , j = 0 , loops = 0 ; loops <= xa ; loops = loops + 1)
                    {
                        if(loops == xa)
                        {
                            printf("Sofia: (%d, %d)\n" , n - 1 , n - 1);
                            printf("Ambrosio: (%d, %d)\n", i , j );
                            printf("Sofia venceu\n");
                            break ;
                        }
                        else
                        {
                            if (j != n)
                            {
                                j = j + 1 ;
                            }
                            if(j == n)
                            {
                                j = 0 ;
                                i = i + 1;
                            }
                        }
                    }
                    return ;
                }
                
                sofinha = sofia[xs].atk ;
                sofinha2 = sofia[xs].life ;
            }

            if (duel == 1)
            {
                xa = xa + ambrosio[xa].jump ;
                
                if(xa >= (n * n) - 1) 
                {
                    int i , j , loops ;
                    for (i = 0 , j = 0 , loops = 0; loops <= xs; loops = loops + 1)
                    {
                        if(loops == xs)
                        {
                            printf("Sofia: (%d, %d)\n" , i , j);
                            printf("Ambrosio: (%d, %d)\n", n-1 , n-1);
                            printf("Ambrosio venceu\n");
                            break ;
                        }
                        else
                        {
                            if (j != n)
                            {
                                j = j + 1 ;
                            }
                            if (j == n)
                            {
                                j = 0 ;
                                i = i + 1;
                            }
                        }
                    }
                    return ;
                }

                ambrosinho = ambrosio[xa].atk ;
                ambrosinho2 = ambrosio[xa].life;
            }

            game (n , rodadas , i + 1 , xs  , xa , sofinha , ambrosinho , sofia , ambrosio , sofinha2 , ambrosinho2);
    }
    else
    {
        int i , j , loops ;
        for (i = 0 , j = 0 , loops = 0; loops <= xs ; loops = loops + 1)
        {
            if(loops == xs)
            {
                printf("Sofia: (%d, %d)\n" , i , j) ;
                break ;
            }
            else
            {
                if (j != n)
                {
                    j = j + 1 ;
                }
                if (j == n)
                {
                    j = 0 ;
                    i = i + 1;
                }
            }
        }

        for (i = 0 , j = 0 , loops = 0 ; loops <= xa; loops = loops + 1)
        {
            if(loops == xa)
            {
                printf("Ambrosio: (%d, %d)\n", i , j );
                printf("Ninguem venceu\n");
                break ;
            }
            else
            {
                if (j != n)
                {
                    j = j + 1 ;
                }
                if (j == n)
                {
                    j = 0 ;
                    i = i + 1;
                }
            }
        }
        return ;
    }
}
int main() 
{
    int n ;
    scanf("%d", &n);
    int tam = n * n ;
    struct tabuleiro sofia [tam];
    struct tabuleiro ambrosio [tam] ;
    ler_array(0, tam , sofia);
    ler_array2(0, tam , ambrosio);
    int rodadas ;
    scanf("%d", &rodadas);
    game (n , rodadas , 0 , 0 , 0, sofia[0].atk , ambrosio[0].atk , sofia, ambrosio , sofia[0].life , ambrosio[0].life);
    return 0;
}

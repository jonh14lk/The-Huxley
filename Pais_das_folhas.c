#include <stdio.h>
struct arvore 
{
    int esquerda ;
    int direita ;
};
void imprimir_array(int i, int n, int array[])
{
    if (i < n)
    {
        if (array[i] != -1)
        {
            printf("%d\n", array[i]);
        }

        imprimir_array(i + 1, n, array);
    }
}
void swap (int *a , int *b)
{
    if (*a < *b)
    {
        int aux ;
        aux = *a ;
        *a = *b ;
        *b = aux ;
        return ;
    }
    else
    {
        return ;
    }
}
void bubblesort (int array [] , int n , int cont)
{
    if (n == 1)
    {
        return ;
    }
    else 
    {
        if (cont == n )
        {
            bubblesort (array , n - 1 , 1 );
        }
        else 
        {
            swap (&array[cont] , &array[cont - 1]);
            bubblesort (array , n , cont + 1 );
        }
    }
}
void run (struct arvore percorrer [] , int no_atual , int tam , int print [])
{
    if (no_atual == -1)
    {
        return ;
    }

    int aux1 = percorrer[no_atual].esquerda ;
    int aux2 = percorrer[no_atual].direita ;
        
    if (percorrer[aux1].esquerda == -1 || percorrer[aux2].direita == -1)
    {
        int t ;
        for (t = 0 ; t < tam * 2 ; t = t + 1)
        {
            if (print[t] == -1)
            {
                print[t] = no_atual;
                break ;
            }
        }
    }

    run (percorrer , percorrer[no_atual].esquerda , tam , print);
    run (percorrer , percorrer[no_atual].direita, tam , print);
}
int main ()
{
    int tam ;
    scanf("%d", &tam);
    struct arvore percorrer [tam] ;
    int i ;
    for (i = 0 ; i < tam ; i = i + 1)
    {
        scanf("%d", &percorrer[i].esquerda);
        scanf("%d", &percorrer[i].direita);
    }

    int print [tam * 2];
    for (i = 0 ; i < tam * 2 ; i = i + 1)
    {
        print[i] = -1 ;
    }

    run (percorrer , 0 , tam , print);

    bubblesort(print, tam * 2 , 1);
    imprimir_array(0, tam * 2, print);

    return 0 ;
}

#include <stdio.h>
struct arvore 
{
    int esquerda ;
    int direita ;
    int valor ;
};
void verificar_niveis (struct arvore percorrer [] , int *niveis, int no_atual, int nivel_atual)
{
    if (no_atual == -1)
    {
        if (nivel_atual > *niveis)
        {
            *niveis = nivel_atual ;
        }

        return ;
    }

    verificar_niveis(percorrer , niveis , percorrer[no_atual].esquerda, nivel_atual + 1);
    verificar_niveis(percorrer , niveis , percorrer[no_atual].direita, nivel_atual + 1);

}
void backtracking (struct arvore percorrer [], int no_atual , int *maior_valor , int *menor_valor , int i , int j)
{
    if (no_atual == -1)
    {
        return ;
    }
    
    if (i == j)
    {
        if (percorrer[no_atual].valor > *maior_valor)
        {
            *maior_valor = percorrer[no_atual].valor ;
        }
        if (percorrer[no_atual].valor < *menor_valor)
        {
            *menor_valor = percorrer[no_atual].valor ;
        }

        return ;
    }

    backtracking(percorrer,percorrer[no_atual].esquerda , maior_valor , menor_valor , i , j + 1);
    backtracking(percorrer,percorrer[no_atual].direita , maior_valor , menor_valor , i , j + 1);
}
int main ()
{
    int n , i ;
    scanf("%d", &n);
    struct arvore percorrer [n];

    for (i = 0 ; i < n ; i = i + 1)
    {
        percorrer[i].esquerda = -1 ;
        percorrer[i].direita = -1 ;
    }

    for (i = 0 ; i < n ; i = i + 1)
    {
        scanf("%d", &percorrer[i].valor);
        scanf("%d", &percorrer[i].esquerda);
        scanf("%d", &percorrer[i].direita);
    }

    int niveis = 0 ;
    verificar_niveis (percorrer , &niveis , 0 , 0);

    for (i = 1 ; i <= niveis ; i = i + 1)
    {
        int maior_valor = 0 ;
        int menor_valor = 100000 ;
        backtracking (percorrer , 0 , &maior_valor, &menor_valor , i , 1);
        printf("Nivel %d: Maior = %d, Menor = %d\n", i , maior_valor , menor_valor);
    }

    return 0 ;
}

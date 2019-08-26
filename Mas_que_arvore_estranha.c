#include <stdio.h>
struct arvore 
{
    int esquerda ;
    int direita ;
};
void backtracking (struct arvore percorrer [] , int altura_atual , int *altura , int no_atual)
{
    if(no_atual == -1) 
    {
        if (altura_atual > *altura)
        {
            *altura = altura_atual ;
        }

        return;
    }

    backtracking(percorrer , altura_atual + 1 , altura , percorrer[no_atual].esquerda);
    backtracking(percorrer , altura_atual + 1 , altura , percorrer[no_atual].direita);
}
int main ()
{
    int num_nos , num_pais , raiz ;
    scanf("%d%d%d", &num_nos , &num_pais , &raiz);

    struct arvore percorrer [num_nos];
    int i , origem ;

    for (i = 0 ; i < num_nos ; i = i + 1)
    {
        percorrer[i].esquerda = -1 ;
        percorrer[i].direita = -1 ;
    }
    
    for (i = 0 ; i < num_pais ; i = i + 1)
    {
        int array [3];
        scanf("%d", &array[0]);
        scanf("%d", &array[1]);
        scanf("%d", &array[2]);
        
        
        origem = array[0];
        percorrer[origem].esquerda = array[1];
        percorrer[origem].direita = array[2];
    }

    int altura = 0;
    backtracking (percorrer , 0 , &altura , raiz);

    printf("%d\n", altura);

    return 0 ;
}

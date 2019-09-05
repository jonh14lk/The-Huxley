#include <stdio.h>
struct buracos  // arvore (struct com nos para esquerda , direita e quantidade de queijo)
{
    int quant_quejo ;
    int esquerda ;
    int direita ;
};
void run (struct buracos rato [] , int b , int q , int *condition , int no_atual , int quantia) // funçao que percorre a arvore
{
    if (no_atual == -1) // se o meu nó atual for -1 (ele nao existe)
    {
        if (quantia == q) // verifico se a quantidade de queijos atuais foi a que ele pediu na entrada
        {
            *condition = 1 ; // mudo a minha condição para q ele printe sim 
        }

        return ; // retorno essa função(cheguei no final), e agora ele vai executar a proxima que tá na fila se tiver
    }

    quantia = quantia + rato[no_atual].quant_quejo ; // somo a quantidade de queijos que tem nesse nó da arvore

    if (quantia == q) // verifico se a quantidade de queijos atuais foi a que ele pediu na entrada
    {
        *condition = 1 ; // mudo a minha condição para q ele printe sim 
        return ;
    }

    run (rato , b , q , condition , rato[no_atual].esquerda , quantia); // chamada para ir pro nó da direita agora
    run (rato , b , q , condition , rato[no_atual].direita , quantia); // chamada para ir pro nó da esquerda agora
}
int main ()
{
    int b , i , q , l ; // criação das variaveis, sendo b a quantidade de buracos , i o tunel de inicio(nó inicial) , q a
    // quantidade de queijos que ele deseja comer e l uma variavel pra auxiliar nos for.
    scanf("%d%d%d", &b, &i , &q); // lendo b , i , q (primeira linha da entrada)
    
    struct buracos rato [b]; // criando a arvore (struct com nos para esquerda , direita e quantidade de queijo)

    for (l = 0 ; l < b ; l++) // for para ler a arvore
    {
        scanf("%d", &rato[l].quant_quejo); // le a quantidade de queijos pra cada nó da arvore
        scanf("%d", &rato[l].esquerda); // le o no da direita
        scanf("%d", &rato[l].direita); // le o no da esquerda
    }
    
    int condition = 0 ; // variavel para armazenar a condiçao de que se deve printar sim ou nao no final 

    run (rato , b , q , &condition , i , 0); // chamada da funçao que percorre a arvore , passando condition por ponteiro

    if (condition == 1) // se ele conseguiu comer exatamente a quantidade de queijos em algum momento
    {
        printf("SIM\n");
    }
    if (condition == 0) // se ele  não conseguiu comer exatamente a quantidade de queijos em algum momento
    {
        printf("NAO\n");
    }

    return 0 ;
}

#include <stdio.h>
int pegar_proximo(int visitados [] , int i , int n)
{
    if (i < n)
    {
        return (visitados [i] == 0)
            ? i 
            : pegar_proximo(visitados , i + 1 , n);
    }
    else 
    {
        return -2 ;
    }
}
void tocas (int array [] , int visitados [] , int n , int i , int cont , int atual , int aux)
{
    if (i < n) 
    {
        aux = array[aux];
        visitados [aux] = 1 ;
        if (aux == atual)
        {
            cont = cont + 1  ;
            atual = pegar_proximo(visitados , 0 , n);
            
            (atual == -2)
                ? printf("%d\n", cont)
                : tocas (array , visitados , n , i + 1 , cont , atual , atual);
        }
        else 
        {
            tocas (array , visitados , n , i + 1 , cont , atual , aux);
        }
    }
    else 
    {
        printf("%d\n", cont);
    }
}
int main ()
{
	int n , i;
    scanf("%d", &n);
    int array [n] , visitados [n] ;

    for (i = 0 ; i < n ; i = i + 1)
    {
    	scanf("%d", &array[i]);
    }

    for (i = 0 ; i < n ; i = i + 1)
    {
    	visitados[i] = 0 ;
    }

    tocas (array , visitados , n , 0 , 0 , 0 , 0);

	return 0 ;
}
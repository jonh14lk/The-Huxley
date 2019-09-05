#include <stdio.h>
void imprimir_matriz(int n , int m , char matriz [][m] , int i , int j) // funçao para imprimir a matriz no final da execução 
{
    if (i == n)
    {
        return ;
    }
    if (j == m - 1 )
    {
        printf("%c\n", matriz[i][j]);
        imprimir_matriz(n , m , matriz , i + 1 , 0);
    }
    else if (j < m)
    {
        printf("%c", matriz[i][j]);
        imprimir_matriz(n , m , matriz , i, j + 1);
    }
}
void ler_matriz2 (int n , int m , char matriz[][m], int i , int j) // função para ler a matriz do mapa (matriz de char)
{
    if (i == n)
    {
        return ;
    }
    if (j == m)
    {
        ler_matriz2(n , m ,  matriz , i+1 , 0);
    }
    else if (j < m)
    {
        scanf(" %c", &matriz [i][j]);
        ler_matriz2(n , m , matriz , i, j + 1);
    }
}
void ler_matriz (int n , int m , int matriz[][m], int i , int j) // função para ler a matriz das jogadas que irao ser feitas
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
        scanf(" %d", &matriz [i][j]);
        ler_matriz(n , m , matriz , i, j + 1);
    }
}
void game (int n , int m , char mapa [][n] , int jogadas [][2] , int i) // funçao que vai executar cada bomba jogada
{
	if (i < m) // enquanto ainda tiver bombas pra ser jogadas
	{
		int p1 = jogadas [i][0]; // variavel pra armazenar a linha da posição bomba jogada
		int p2 = jogadas [i][1]; // variavel pra armazenar a coluna da posiçao da bomba jogada
		int j1 = p1 + 1 ; // variavel pra armazenar a jogada da exploxão da bomba para baixo
		int j2 = p1 - 1 ; // variavel pra armazenar a jogada da exploxão da bomba para cima
		int j3 = p2 + 1 ; // variavel pra armazenar a jogada da exploxão da bomba para direita
		int j4 = p2 - 1 ; // variavel pra armazenar a jogada da exploxão da bomba para esquerda

		if (j1 >= n) // verificar se j1 passou dos limites da matriz
		{
			j1 = j1 % n ; 
		}
		if (j1 < 0)
		{
			j1 = n + j1 ;
		}

		if (j2 >= n) // verificar se j2 passou dos limites da matriz
		{
			j2 = j2 % n ;
		}
		if (j2 < 0)
		{
			j2 = n + j2 ;
		}

		if (j3 >= n) // verificar se j3 passou dos limites da matriz
		{
			j3 = j3 % n ;
		}
		if (j3 < 0)
		{
			j3 = n + j3 ;
		}

		if (j4 >= n) // verificar se j4 passou dos limites da matriz
		{
			j4 = j4 % n ;
		}
		if (j4 < 0)
		{
			j4 = n + j4 ;
		}

		if (mapa[p1][p2] == '_') // a bomba ira estourar apenas se for jogada numa casa que estiver vazia
		{
			if (mapa[j1] [p2] == '&')  // explode em baixo
			{
				mapa[j1] [p2] = '_' ;
			}

			if (mapa[j2] [p2] == '&') // explode em cima
			{
				mapa[j2] [p2] = '_' ;
			}

			if (mapa[p1] [j3] == '&') // explode na direita
			{
				mapa[p1] [j3] = '_' ;
			}

			if (mapa[p1] [j4] == '&') // explode na esquerda
			{
				mapa[p1] [j4] = '_' ;
			}
		}

		game (n , m , mapa , jogadas , i + 1); // chamada da funçao para jogar a proxima bomba, se existir


	}
	else // quando nao tiver mais bombas pra ser jogadas
	{
		imprimir_matriz (n , n , mapa , 0 , 0); //  chamada da funçao para imprimir a matriz no final da execução 
		return ; // fim da questão 
	}
}
int main ()
{
	int n ;  // variavel que armazena o tamanho do mapa
	scanf(" %d", &n); // lendo a variavel que armazena o tamanho do mapa
	char mapa [n][n]; // criando a matriz do mapa
	ler_matriz2 (n , n , mapa , 0 , 0); // chamada da função para ler a matriz do mapa (matriz de char)

	int m ;  // variavel que armazena a quantidade de bombas que irao ser jogadas
	scanf(" %d", &m); // lendo a variavel que armazena a quantidade de bombas que irao ser jogadas
	int jogadas [m][2] ; // criando a matriz que armazena as jogadas
	ler_matriz (m , 2 , jogadas , 0 , 0); // chamada da função para ler a matriz das jogadas que irao ser feitas

	game (n , m , mapa , jogadas , 0); // chamada da funçao que vai executar cada bomba jogada
	return 0 ;
}
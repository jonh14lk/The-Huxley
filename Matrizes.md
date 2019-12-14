# Matrizes na linguagem C

Definição: Matriz é a uma estrutura de dados do tipo vetor com duas ou mais dimensões, cujo os itens de uma matriz tem que ser todos do mesmo tipo de dado.

Sempre que declaramos uma matriz, declaramos ela assim:

```c
Tipo_de_dado Nome_da_matriz [Quantidade de linhas][Quantidade de colunas] ;
```

Exemplos:

```c
int matriz[10][10] ; // crio uma matriz que armazena inteiros que possui 10 linhas e 10 colunas
double matriz2 [200][10] ; // crio a matriz2 que armazena valores de ponto flutuante (double) e que possui 200 linhas e 10 colunas 
```

Assim como nos arrays, as matrizes também possui suas linhas e colunas numeradas de 0 até n - 1.

Para acessar cada uma das posições da matriz, podemos fazer assim:

```c
int m[10][10] // declarando a minha matriz 10 por 10

m[0][1] = 1 ; // a minha matriz na posição 0,1 recebe 1 
scanf("%d", &m[4][2]); // lendo a matriz na posição 4,2
printf("%d\n", m[1][5]); // printando o valor da matriz na posição 1,5
```
Exemplo de uma matriz 3 por 5:

![GitHub Logo](https://cdn.discordapp.com/attachments/630216934192840723/655459226382106635/cpp_Multidimensional_Array.png)

fonte da imagem: https://beginnersbook.com/2017/08/cpp-multidimensional-arrays/

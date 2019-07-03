#include <stdio.h>
int main()
{
	int a, b, aux ;
	scanf("%d %d", &a ,&b);
	if (a > b)
	{
      aux= a;
      a= b;
      b= aux;
       
    }
	printf(" %d %d\n", a, b);
	return(0);
}

#include <stdio.h>

void swap (int *a , int *b)
{
    if (*a > *b)
    {
        int aux ;
        aux = *a ;
        *a = *b ;
        *b = aux ;
    }
}

int main() 
{
    int a , b , c ;
    scanf("%d%d%d", &a , &b , &c);
    swap (&a , &b);
    swap (&b , &c);
    
    swap(&a , &b);
    
    printf("%d\n%d\n%d\n", a , b , c);
	return 0;
}

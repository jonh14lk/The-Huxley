#include <stdio.h>
int naturais (int loops)
{
    if (loops == 100)
    {
        return 0 ;
    }
    else 
    {
        printf("%d\n", loops);
        return naturais (loops + 1);
    }
}
int main ()
{
    naturais (0);
    return 0 ;
}

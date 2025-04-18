#include <stdio.h>

void ft_swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;

}

/*void ft_swap(int *a, int *b);

int main(void)
{
    int x = 5;
    int y = 10;
    
    printf("x = %d, y = %d\n", x, y);
    ft_swap(&x, &y);
    printf("x = %d, y = %d\n", x, y);
    
    return 0;
}*/
#include <stdio.h>

int ft_strlen(char *str)
{
    int len = 0;
    while(str[len])
    {
        len++;
    }
    return len;
}

// int main(void)
// {
//     printf("%d\n", ft_strlen("Teste"));
//     printf("%d\n", ft_strlen("Michele"));
//     return 0;
// }
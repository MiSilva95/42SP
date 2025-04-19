#include <unistd.h>

void ft_putstr(char *str)
{
    int i = 0;
    while(str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

// int main(void)
// {
//     char *c = "Cuscuz\n";
//     ft_putstr(c);
//     return 0;
// }

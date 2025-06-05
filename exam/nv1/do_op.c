#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    int num1;
    int num2;
    int result;
    if(ac == 4)
    {
        num1 = atoi(av[1]);
        num2 = atoi(av[3]);
        if(av[2][0] == '+')
            result = num1 + num2;
        if(av[2][0] == '-')
            result = num1 - num2;
        if(av[2][0] == '*')
            result = num1 * num2;
        if(num2 == 0)
        {   
            printf("\n");
            return 0;
        }
        if(av[2][0] == '/')
            result = num1 / num2;
        if(av[2][0] == '%')
            result = num1 % num2;
        printf("%i", result);
    }
    printf("\n");
}
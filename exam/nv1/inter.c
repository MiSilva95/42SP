#include <unistd.h>

int is_repeat(char *av, char c, int i)
{
    int j = 0;
    while (av[j] && j < i)
    {
        if(av[j] == c)
        {
            return 1;
        }
        j++;
    }
    return 0;    
}

int main(int ac, char **av)
{
   int i = 0;
   int j;
   if(ac == 3)
    {
        while(av[1][i])
        {  
            j = 0;
            if(!is_repeat(av[1], av[1][i], i))
            {
                while(av[2][j])
                {
                    if(av[1][i] == av[2][j])
                    {
                        write(1, &av[1][i], 1);
                        break;
                    }
                    j++;
                }
            }
            i++;
        }
    }
    write(1, "\n", 1);
}
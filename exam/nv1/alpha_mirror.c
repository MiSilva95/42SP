#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;
    char c;
    if(ac == 2)
    {
        while(av[1][i])
        {
            c = av[1][i];
            if (c >= 'a' && c <= 'z')
                c = 'z' - (c - 'a');
            else if (c >= 'A' && c <= 'Z')
                c = 'Z' - (c - 'A');
        write(1, &c, 1);
        i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}
#include <unistd.h>

void	ft_putnbr(int nb)
{
	long n;

    n = nb;
	if (n < 0)
	{
		write(1, "-", 1);
		n = n * (-1);
	}
	if (n > 9)
	ft_putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

int main()
{
    ft_putnbr(10);
    write(1, "\n", 1);
    return 0;
}
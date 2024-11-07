/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgomes-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 11:48:06 by vgomes-p          #+#    #+#             */
/*   Updated: 2024/07/14 17:04:33 by mida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y);

void	validation(int x, int y)
{
	if (x <= 0 || y <= 0)
		return ;
}

void	rush(int x, int y)
{
	int	line;
	int	column;

	validation(x, y);
	line = 0;
	while (line < y)
	{
		column = 0;
		while (column < x)
		{
			if ((line == 0 && column == 0) || (line == 0 && column == x - 1))
				ft_putchar('A');
			else if ((line == y - 1 && column == 0)
				|| (line == y - 1 && column == x - 1))
				ft_putchar('C');
			else if (line == 0 || line == y - 1
				|| column == 0 || column == x - 1)
				ft_putchar('B');
			else
				ft_putchar(' ');
			column++;
		}
		ft_putchar('\n');
	line++;
	}
}

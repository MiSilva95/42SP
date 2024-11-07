/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida-sil <mida-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:56:53 by mida-sil          #+#    #+#             */
/*   Updated: 2024/10/03 14:40:41 by mida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	num;

	num = 2;
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (nb);
	while (num * num != nb)
	{
		if (num * num > nb)
			return (0);
		num++;
	}
	return (num);
}

/*int main()
{
    printf("%d", ft_sqrt(25));
    return 0;
}*/

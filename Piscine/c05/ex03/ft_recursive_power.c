/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida-sil <mida-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:27:02 by mida-sil          #+#    #+#             */
/*   Updated: 2024/08/01 17:44:45 by mida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power > 1)
	{
		return (nb = nb * ft_recursive_power(nb, power - 1));
	}
	return (nb);
}

/*int main()
{
    printf("%d\n", ft_recursive_power(4, 3));
    return 0;
}*/

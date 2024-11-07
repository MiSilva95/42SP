/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida-sil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:42:15 by mida-sil          #+#    #+#             */
/*   Updated: 2024/07/11 14:43:51 by mida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)

{
	char	indicator;

	if (n < 0)
	{
		indicator = 'N';
	}
	else
	{
		indicator = 'P';
	}
	write (1, &indicator, 1);
}

/*int main ()
{
	ft_is_negative(0);
	return ('0');
}*/

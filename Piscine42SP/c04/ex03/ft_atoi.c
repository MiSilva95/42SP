/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida-sil <mida-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 11:20:47 by mida-sil          #+#    #+#             */
/*   Updated: 2024/08/01 17:03:44 by mida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	isminus;
	int	isdigit;	

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	isminus = 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			isminus *= -1;
		i++;
	}
	isdigit = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		isdigit = isdigit * 10 + (str[i] - 48);
		i++;
	}
	return (isdigit * isminus);
}

/*int main() {
    printf("%d\n", ft_atoi("---+--+1234ab567"));
    return 0;
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida-sil <mida-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 14:54:01 by mida-sil          #+#    #+#             */
/*   Updated: 2024/07/25 10:43:52 by mida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= 'A' && str[i] <= 'Z') || \
	(str[i] >= 'a' && str[i] <= 'z')))
		{
			return (0);
		}
	i++;
	}
	return (1);
}

/*int main()
{
    char str[] = "55";
    printf("%d\n", ft_str_is_alpha(str));
    return 0;
}*/

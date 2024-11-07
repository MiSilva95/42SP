/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida-sil <mida-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 16:04:12 by mida-sil          #+#    #+#             */
/*   Updated: 2024/07/19 16:35:40 by mida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < ' ' || str[i] > '~'))
		{
			return (0);
		}
	i++;
	}
	return (1);
}

/*int main()
{
    char str[] = "©";
    printf("%d\n", ft_str_is_printable(str));
    return 0;
}*/
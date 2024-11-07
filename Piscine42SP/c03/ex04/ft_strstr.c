/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida-sil <mida-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:18:29 by mida-sil          #+#    #+#             */
/*   Updated: 2024/07/24 11:14:22 by mida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (to_find[b] == '\0')
	{
		return (str);
	}
	while (str[a])
	{
		while (str[a + b] == to_find[b] && str[a + b])
		{
			b++;
		}
		if (to_find[b] == '\0')
		{
			return (str + a);
		}
		a++;
		b = 0;
	}
	return (0);
}

/*int	main()
{
    char str[] = "I love cuscuz";
	char to_find[] = "love";
	printf("%s\n", ft_strstr(str, to_find));
    return (0);
}*/
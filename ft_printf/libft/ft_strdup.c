/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida-sil <mida-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 14:15:08 by mida-sil          #+#    #+#             */
/*   Updated: 2024/10/21 11:20:23 by mida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*cpy;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (src[len])
	{
		len++;
	}
	cpy = (char *)malloc((len + 1) * sizeof(char));
	if (cpy == NULL)
	{
		return (NULL);
	}
	while (i < len)
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[len] = '\0';
	return (cpy);
}

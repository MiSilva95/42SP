/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida-sil <mida-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:06:32 by mida-sil          #+#    #+#             */
/*   Updated: 2024/10/25 16:12:37 by mida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*str;

	start = 0;
	end = ft_strlen(s1);
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	if (start < end)
	{
		while (start < end && is_in_set(s1[end - 1], set))
			end--;
	}
	len = end - start;
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, &s1[start], len);
	str[len] = '\0';
	return (str);
}

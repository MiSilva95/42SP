/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:09:30 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/11 19:04:38 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	last_index(char const *s1, char const *set)
{
	size_t		b;
	int			index;
	int			a;

	a = ft_strlen(s1);
	b = 0;
	index = 0;
	while (a >= 0)
	{
		while (b <= ft_strlen(set))
		{
			if (s1[a] == set[b])
			{
				index = a - 1;
				break ;
			}
			b++;
		}
		if (b == ft_strlen(set) + 1)
			break ;
		b = 0;
		a--;
	}
	return (index);
}

static int	first_index(char const *s1, char const *set)
{
	size_t		a;
	size_t		b;
	int			index;

	a = 0;
	b = 0;
	index = 0;
	while (a <= ft_strlen(s1))
	{
		while (b <= ft_strlen(set))
		{
			if (s1[a] == set[b])
			{
				index = a + 1;
				break ;
			}
			b++;
		}
		if (b == ft_strlen(set) + 1)
			break ;
		b = 0;
		a++;
	}
	return (index);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*result;
	int			last;
	int			first;

	first = first_index(s1, set);
	last = last_index(s1, set);
	if (last < 0)
		return (ft_strdup(""));
	result = ft_substr(s1, first, (last - first + 1));
	if (result == NULL)
		return (NULL);
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:48:23 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/06 19:16:41 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	c_counter(char const *s, char c)
{
	unsigned int		counter;
	size_t				i;

	i = 0;
	counter = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] == c && s[i - 1] != c)
			counter++;
		i++;
	}
	return (counter);
}

static char const	*char_const_maker(char c)
{
	char	*result;

	result = (char *)malloc(2 * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[0] = c;
	result[1] = '\0';
	return ((char const *)(result));
}

static char	**result_is(char *str, int n)
{
	char	**result;

	if (n == 0)
	{
		result = (char **)malloc(sizeof(char *));
		if (result == NULL)
			return (NULL);
		result[0] = NULL;
	}
	if (n == 1)
	{
		result = (char **)malloc(2 * sizeof(char *));
		if (result == NULL)
			return (NULL);
		result[0] = ft_strdup(str);
		if (result[0] == NULL)
			return (NULL);
		result[1] = NULL;
	}
	free(str);
	return (result);
}

static char	**return_is_subs(char **result, char *str, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	first;

	i = 0;
	j = 0;
	first = 0;
	while (i <= ft_strlen(str))
	{
		if (str[i] == c || i == ft_strlen(str))
		{
			result[j] = ft_substr(str, first, i - first);
			if (result == NULL)
				return (NULL);
			while (str[i] == c)
				i++;
			first = i;
			j++;
		}
		i++;
	}
	result[j] = NULL;
	free(str);
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char		*str;
	char		*c_const;
	char		**result;

	c_const = (char *) char_const_maker(c);
	if (c_const == NULL)
		return (NULL);
	str = ft_strtrim(s, (const char *)c_const);
	free(c_const);
	if (str == NULL)
		return (NULL);
	if (s[0] == '\0' || str[0] == '\0')
		return (result_is(str, 0));
	if (c_counter(str, c) == 0)
		return (result_is(str, 1));
	result = (char **)malloc((c_counter(str, c) + 2) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	return (return_is_subs(result, str, c));
}

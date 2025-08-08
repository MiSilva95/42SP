/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 08:39:03 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/05 18:21:47 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*make_subs(unsigned int start, unsigned int final_index, \
				char const *s, char *str)
{
	unsigned int	i;

	i = 0;
	while (start <= final_index)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		final_index;
	char				*str;
	unsigned int		s_len;

	s_len = ft_strlen(s);
	if (len > s_len)
		len = s_len;
	if (len >= (s_len - start))
		len = s_len - start;
	final_index = start + (len - 1);
	if (final_index > s_len)
		final_index = s_len - 1;
	if (start >= s_len || (start == 0 && len == 0))
		return (ft_strdup(""));
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	make_subs(start, final_index, s, str);
	return (str);
}

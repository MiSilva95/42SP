/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:34:39 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/13 19:31:52 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i_big;
	char			*big_loop;

	i_big = 0;
	if (!(*little))
		return ((char *)(big));
	if (len > ft_strlen(big) || (int)(len) < 0)
		len = ft_strlen(big);
	if (len == 0)
		return (NULL);
	while (i_big <= len)
	{
		big_loop = ft_strchr(big + i_big, little[0]);
		if (big_loop != NULL && (big_loop + ft_strlen(little)) <= &big[len] && \
			ft_strncmp(little, big_loop, ft_strlen(little)) == 0)
			return (big_loop);
		i_big++;
	}
	return (NULL);
}

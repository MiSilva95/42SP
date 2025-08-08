/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:40:19 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/02 17:59:03 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	temp_c;

	i = 0;
	ptr = (unsigned char *)(s);
	temp_c = (unsigned char)(c);
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		if (ptr[i] == temp_c)
			return (&ptr[i]);
		i++;
	}
	return (NULL);
}

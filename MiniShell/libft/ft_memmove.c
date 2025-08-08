/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:18:29 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/07 10:15:53 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned char	*copy(unsigned char *s1, unsigned char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (s1);
}

static unsigned char	*r_copy(unsigned char *s1, unsigned char *s2, size_t n)
{
	size_t	i;

	i = n;
	while (i > 0)
	{
		s1[i - 1] = s2[i -1];
		i--;
	}
	return (s1);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;

	ptr_dest = (unsigned char *)(dest);
	ptr_src = (unsigned char *)(src);
	if (dest == NULL && src == NULL)
		return (NULL);
	if (n == 0)
		return (dest);
	if (ptr_dest < ptr_src)
	{
		copy(ptr_dest, ptr_src, n);
	}
	else if (ptr_dest > ptr_src)
	{
		r_copy(ptr_dest, ptr_src, n);
	}
	return (dest);
}

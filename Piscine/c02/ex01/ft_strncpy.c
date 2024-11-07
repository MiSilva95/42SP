/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida-sil <mida-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:59:16 by mida-sil          #+#    #+#             */
/*   Updated: 2024/07/25 11:40:19 by mida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		(dest[i]) = (src[i]);
		i++;
	}
	while (i < n)
	{
		(dest[i]) = '\0';
		i++;
	}
	return (dest);
}

/*int main ()
{
    char dest[25];
    ft_strncpy(dest, "Good Morning!", 7);
    printf("%s", dest);
    return 0;
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida-sil <mida-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:33:54 by mida-sil          #+#    #+#             */
/*   Updated: 2024/10/08 12:56:59 by mida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

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

/*int main() {
    const char *original = "Ola";
    char *copia;
    copia = ft_strdup(original);
    printf("%s\n", copia);
    free(copia);
    return 0;
}*/

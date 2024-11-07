/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida-sil <mida-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:58:16 by mida-sil          #+#    #+#             */
/*   Updated: 2024/10/08 15:24:23 by mida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*ptr;
	int	i;

	i = 0;
	if (min >= max)
	{
		ptr = NULL;
		return (ptr);
	}
	ptr = malloc((max - min) * sizeof(int));
	while (min < max)
	{
		ptr[i] = min;
		i++;
		min++;
	}
	return (ptr);
}

/*int main()
{
	int min = 1;
	int max = 11;
	int i = 0;
	int *range = ft_range(min, max);
	while (i < max - min)
	{
		printf("%d", range[i]);
		i++;
	}
	free(range);
	return 0;
}*/

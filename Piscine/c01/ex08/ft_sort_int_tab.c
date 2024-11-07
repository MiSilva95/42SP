/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida-sil <mida-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:52:56 by mida-sil          #+#    #+#             */
/*   Updated: 2024/07/16 18:02:36 by mida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	temp;
	int	first;
	int	last;

	first = 0;
	while (first < size - 1)
	{
		last = 0;
		while (last < size - first - 1)
		{
			if (tab[last] > tab[last + 1])
			{
			temp = tab[last];
			tab[last] = tab[last + 1];
			tab[last + 1] = temp;
			}
		last++;
		}
	first++;
	}
}

/*int main()
{
    int tab[] = {4, 3, 5, 2, 1};
    int size = sizeof(tab) / sizeof(tab[0]);
    ft_sort_int_tab(tab, size);
    int i = 0;
    while (i < size)
    {
        printf("%d ", tab[i]);
        i++;
    }
    return 0;
}*/

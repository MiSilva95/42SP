/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida-sil <mida-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:08:50 by mida-sil          #+#    #+#             */
/*   Updated: 2024/10/02 13:14:10 by mida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

/*int main(void)
{
    int a = 2;
    int b = 3;
    ft_swap(&a, &b);
    printf ("%d\n", a);
    printf ("%d\n", b);
    return 0;
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida-sil <mida-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:09:43 by mida-sil          #+#    #+#             */
/*   Updated: 2024/07/16 14:34:10 by mida-sil         ###   ########.fr       */
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

/* int main ()
{
    int a = 50;
    int b = 101;
    ft_swap(&a, &b);
    printf("%d\n", a);
    printf("%d\n", b);
    return 0;
}*/
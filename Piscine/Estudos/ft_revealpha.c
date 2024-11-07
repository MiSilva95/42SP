/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revealpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida-sil <mida-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:56:39 by mida-sil          #+#    #+#             */
/*   Updated: 2024/07/25 14:59:47 by mida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_revealpha(void)
{
    char z = 'z';
    char y = 'Y';

    while (y >= 'A')
    {
        write (1, &z, 1);
        write (1, &y, 1);
        z -= 2;
        y -= 2;
    }
    write (1, "\n", 1);
}

int main ()
{
    ft_revealpha();
    return 0;
}
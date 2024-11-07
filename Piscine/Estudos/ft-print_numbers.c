/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft-print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida-sil <mida-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:55:08 by mida-sil          #+#    #+#             */
/*   Updated: 2024/07/25 11:57:08 by mida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void numbers(void)
{
    char number = '0';
    while (number <= '9')
    {
        write(1, &number, 1);
        number++;
    }
}

int main ()
{
    numbers();
    return 0;
}
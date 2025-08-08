/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:53:12 by vimafra-          #+#    #+#             */
/*   Updated: 2025/07/30 13:55:01 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void   *ft_atoi(char *str, long long *result)
{
        long long    i;
        long long  sign;

        i = 0;
        sign = 1;
        while (str[i] != '\0' && ((str[i] >= 9 && str[i] <= 13) \
                        || str[i] == 32))
                i++;
        if (str[i] == '-' || str[i] == '+')
        {
                if (str[i] == '-')
                        sign = sign * (-1);
                i++;
        }
        while (str[i] >= '0' && str[i] <= '9')
        {
                *result = *result * 10 + (str[i] - '0');
                i++;
        }
        if (str[i] != '\0' && (str[i] < '0' || str[i] > '9'))
                return (NULL);
        *result = (*result) * sign;
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida-sil <mida-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:43:24 by mida-sil          #+#    #+#             */
/*   Updated: 2024/11/22 09:49:05 by mida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, const char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_printchar(va_arg(args, int));
	else if (format == 's')
		count += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		count += ft_printptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		count += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		count += ft_printunsigned(va_arg(args, unsigned int));
	else if (format == 'x')
		count += ft_printhex_lower(va_arg(args, unsigned int));
	else if (format == 'X')
		count += ft_printhex_upper(va_arg(args, unsigned int));
	else if (format == '%')
		count += ft_printpercent();
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	va_start(args, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i])
				count += ft_formats(args, str[i]);
			else
				break ;
		}
		else
		{
			count += ft_printchar(str[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}

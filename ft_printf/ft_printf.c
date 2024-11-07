/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida-sil <mida-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:43:24 by mida-sil          #+#    #+#             */
/*   Updated: 2024/11/07 14:13:01 by mida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list args, const char format)
{
	int	i;

	i = 0;
	if (format == 'c')
		i += ft_printchar(va_arg(args, int));
	else if (format == 's')
		i += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		i += ft_printptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		i += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		i += ft_printunsigned(va_arg(args, unsigned int));
	else if (format == 'x')
		i += ft_printhex_lower(va_arg(args, unsigned int));
	else if (format == 'X')
		i += ft_printhex_upper(va_arg(args, unsigned int));
	else if (format == '%')
		i += ft_printpercent();
	return (i);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida-sil <mida-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 14:20:16 by mida-sil          #+#    #+#             */
/*   Updated: 2024/11/21 10:31:26 by mida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_utoa(unsigned int n)
{
	char			*str;
	unsigned int	tmp;
	int				len;

	tmp = n;
	len = 1;
	while (tmp > 9)
	{
		tmp /= 10;
		len++;
	}
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

int	ft_printunsigned(int n)
{
	unsigned int	num;
	char			*str;
	int				len;

	num = (unsigned int)n;
	str = ft_utoa(num);
	if (str == NULL)
		return (0);
	len = ft_printstr(str);
	free(str);
	return (len);
}

int	ft_printhex_upper(unsigned long n)
{
	if (n >= 16)
		return (ft_printhex_upper(n / 16) \
		+ ft_printchar("0123456789ABCDEF"[n % 16]));
	return (ft_printchar("0123456789ABCDEF"[n]));
}

int	ft_printhex_lower(unsigned long n)
{
	if (n >= 16)
		return (ft_printhex_lower(n / 16) \
		+ ft_printchar("0123456789abcdef"[n % 16]));
	return (ft_printchar("0123456789abcdef"[n]));
}

int	ft_printptr(void *p)
{
	unsigned long	add;
	int				len;

	if (p == NULL)
	{
		ft_printstr("(nil)");
		return (5);
	}
	add = (unsigned long)p;
	ft_printstr("0x");
	len = ft_printhex_lower(add);
	return (len + 2);
}

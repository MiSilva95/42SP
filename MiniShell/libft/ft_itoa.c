/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimafra- <vimafra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:20:41 by vimafra-          #+#    #+#             */
/*   Updated: 2024/11/06 18:25:33 by vimafra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*write_number(int n, char *s)
{
	char	*numbers;

	numbers = "0123456789";
	if (n < 0)
	{
		*s = '-';
		s++;
		if (n == -2147483648)
		{
			*s = '8';
			n = n / 10;
			s++;
		}
		n *= -1;
	}
	while (n > 9)
	{
		*s = numbers[n % 10];
		n = n / 10;
		s++;
	}
	*s = numbers[n % 10];
	s++;
	*s = '\0';
	return (s);
}

static int	digit_counter(int n)
{
	int	counter;

	counter = 1;
	if (n < 0)
		n = n * (-1);
	while (n > 9)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

static char	*ft_swap(char *s, int n)
{
	size_t	init;
	size_t	end;
	char	temp;

	init = 0;
	if (n < 0)
		init = 1;
	end = ft_strlen(s) - 1;
	while (init < end)
	{
		temp = s[init];
		s[init] = s[end];
		s[end] = temp;
		init++;
		end--;
	}
	return (s);
}

static char	*is_int_min(int n)
{
	char	*result;

	result = (char *)malloc(12 * sizeof(char));
	if (result == NULL)
		return (NULL);
	write_number(n, result);
	ft_swap(result, n);
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;

	if (n == -2147483648)
		return (is_int_min(n));
	if (n < 0)
	{
		result = malloc((digit_counter(n) + 2) * sizeof(char));
		if (result == NULL)
			return (NULL);
	}
	else
	{
		result = malloc((digit_counter(n) + 1) * sizeof(char));
		if (result == NULL)
			return (NULL);
	}
	write_number(n, result);
	ft_swap(result, n);
	return (result);
}

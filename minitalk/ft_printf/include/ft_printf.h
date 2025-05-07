/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida-sil <mida-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:09:30 by mida-sil          #+#    #+#             */
/*   Updated: 2024/11/07 11:47:18 by mida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

int		ft_printnbr(int n);
int		ft_printchar(char c);
int		ft_printptr(void *p);
int		ft_printpercent(void);
int		ft_printstr(char *str);
int		ft_printptr(void *ptr);
int		ft_printunsigned(int n);
char	*ft_utoa(unsigned int n);
int		ft_printf(const char *str, ...);
int		ft_printhex_upper(unsigned long n);
int		ft_printhex_lower(unsigned long n);
int		ft_formats(va_list args, const char format);

#endif
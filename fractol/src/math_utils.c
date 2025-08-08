/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida-sil <mida-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 09:17:34 by mida-sil          #+#    #+#             */
/*   Updated: 2025/07/09 11:19:35 by mida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double unscaled, t_range old, t_range new)
{
	return ((new.max - new.min) * (unscaled - old.min)
		/ (old.max - old.min) + new.min);
}

t_complex	sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex	square_complex(t_complex z)
{
	t_complex	result;

	result.x = z.x * z.x - z.y * z.y;
	result.y = 2 * z.x * z.y;
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida-sil <mida-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 09:17:34 by mida-sil          #+#    #+#             */
/*   Updated: 2025/07/05 14:42:57 by mida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_put_pixel(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	select_fractal(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static int	iterate_point(t_complex z, t_complex c, t_fractal *fractal)
{
	int	i;

	i = 0;
	while (i < fractal->max_iter)
	{
		if (!ft_strncmp(fractal->name, "burning", 7))
		{
			z.x = fabs(z.x);
			z.y = fabs(z.y);
		}
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
			return (i);
		i++;
	}
	return (-1);
}

static void	process_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			iter;
	int			color;

	z.x = (map(x, (t_range){0, WIDTH}, (t_range){-2, +2}) * fractal->zoom)
		+ fractal->shift_x;
	z.y = (map(y, (t_range){0, HEIGHT}, (t_range){+2, -2}) * fractal->zoom)
		+ fractal->shift_y;
	select_fractal(&z, &c, fractal);
	iter = iterate_point(z, c, fractal);
	if (iter != -1)
	{
		color = map(iter, (t_range){0, fractal->max_iter}, \
		(t_range){BLACK, WHITE});
		fractal_put_pixel(x, y, &fractal->img, color);
	}
	else
		fractal_put_pixel(x, y, &fractal->img, WHITE);
}

void fractal_render(t_fractal *fractal)
{
	int y, x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			process_pixel(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connection,
		fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}

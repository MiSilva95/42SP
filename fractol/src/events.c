/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mida-sil <mida-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 09:17:34 by mida-sil          #+#    #+#             */
/*   Updated: 2025/07/05 13:38:01 by mida-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	else if (keysym == XK_plus)
		fractal->max_iter += 10;
	else if (keysym == XK_minus)
		fractal->max_iter -= 10;
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	double	new_zoom;

	if (button == Button4)
		new_zoom = fractal->zoom * 0.95;
	else if (button == Button5)
		new_zoom = fractal->zoom * 1.05;
	else
		return (0);
	fractal->shift_x += (map(x, (t_range){0, WIDTH}, \
	(t_range){-2, +2}) * (fractal->zoom - new_zoom));
	fractal->shift_y += (map(y, (t_range){0, HEIGHT}, \
	(t_range){+2, -2}) * (fractal->zoom - new_zoom));
	fractal->zoom = new_zoom;
	fractal_render(fractal);
	return (0);
}

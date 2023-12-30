/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 21:18:16 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/30 23:55:07 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	handle_close(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->image.image_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	exit(0);
}

void	reset(t_fractal *fractal)
{
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
	fractal->min_x = -2;
	fractal->max_x = 2;
	fractal->min_y = -2;
	fractal->max_y = 2;
}

int	handle_key(int keysym, t_fractal *fractal)
{
	if (keysym == 53)
		handle_close(fractal);
	else if (keysym == 123)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == 124)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == 125)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == 126)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == 69)
		fractal->iterations += 10;
	else if (keysym == 78)
		fractal->iterations -= 10;
	else if (keysym == 15)
		reset(fractal);
	else if (keysym == 8)
		fractal->color += 10;
	else
		return (0);
	fractal_render(fractal);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_fractal *fractal)
{
	double	scaled_x;
	double	scaled_y;

	scaled_x = map(x, fractal->min_x, fractal->max_x, WIDTH);
	scaled_y = map(y, fractal->min_y, fractal->max_y, HEIGHT);
	if (button == 4)
	{
		fractal->zoom *= 0.9;
		fractal->min_x = scaled_x + (fractal->min_x - scaled_x) * 0.9;
		fractal->max_x = scaled_x + (fractal->max_x - scaled_x) * 0.9;
		fractal->min_y = scaled_y + (fractal->min_y - scaled_y) * 0.9;
		fractal->max_y = scaled_y + (fractal->max_y - scaled_y) * 0.9;
	}
	else if (button == 5)
	{
		fractal->zoom *= 1.1;
		fractal->min_x = scaled_x + (fractal->min_x - scaled_x) * 1.1;
		fractal->max_x = scaled_x + (fractal->max_x - scaled_x) * 1.1;
		fractal->min_y = scaled_y + (fractal->min_y - scaled_y) * 1.1;
		fractal->max_y = scaled_y + (fractal->max_y - scaled_y) * 1.1;
	}
	else
		return (0);
	fractal_render(fractal);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 21:18:16 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/31 13:36:35 by yzaazaa          ###   ########.fr       */
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

static void	change_color(t_fractal *fractal)
{
	if (fractal->color >= 400000)
		fractal->color = fractal->iterations;
	fractal->color += 10;
}

int	handle_key(int keysym, t_fractal *fractal)
{
	if (keysym == ESC)
		handle_close(fractal);
	else if (keysym == ARR_LEFT)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == ARR_RIGHT)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == ARR_UP)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == ARR_DOWN)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == PLUS)
		fractal->iterations += 10;
	else if (keysym == MINUS)
		fractal->iterations -= 10;
	else if (keysym == R)
		reset(fractal);
	else if (keysym == C)
		change_color(fractal);
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
	if (button == MOUSE_WHEEL_UP)
	{
		fractal->zoom *= 0.9;
		fractal->min_x = scaled_x + (fractal->min_x - scaled_x) * 0.9;
		fractal->max_x = scaled_x + (fractal->max_x - scaled_x) * 0.9;
		fractal->min_y = scaled_y + (fractal->min_y - scaled_y) * 0.9;
		fractal->max_y = scaled_y + (fractal->max_y - scaled_y) * 0.9;
	}
	else if (button == MOUSE_WHEEL_DOWN)
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

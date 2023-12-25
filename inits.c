/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:21:30 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/25 22:13:21 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iterations = 42;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, 2, (1L<<0), handle_key, fractal);
	mlx_hook(fractal->mlx_window, 4, (1L<<2), handle_mouse, fractal);
	mlx_hook(fractal->mlx_window, 17, (1L<<17), handle_close, fractal);
}

void    fractal_init(t_fractal *fractal)
{
    fractal->mlx_connection = mlx_init();
	if (!fractal->mlx_connection)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
										WIDTH, HEIGHT, fractal->name);
	if (!fractal->mlx_window)
	{
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->image.image_ptr = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
	if (!fractal->image.image_ptr)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		free(fractal->mlx_connection);
		malloc_error();
	}
	fractal->image.pixels = mlx_get_data_addr(fractal->image.image_ptr,
											&fractal->image.bpp,
											&fractal->image.line_len,
											&fractal->image.endian);
	events_init(fractal);
	data_init(fractal);
}

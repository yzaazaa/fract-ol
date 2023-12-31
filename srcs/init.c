/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:21:30 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/31 01:06:46 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	init_data(t_fractal *fractal, char **av)
{
	fractal->escape_value = 4;
	fractal->iterations = 20;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
	fractal->min_x = -2;
	fractal->max_x = 2;
	fractal->min_y = -2;
	fractal->max_y = 2;
	fractal->color = fractal->iterations;
	if (!ft_strcmp(fractal->name, "julia"))
	{
		fractal->julia.x = ft_atod(av[2]);
		fractal->julia.y = ft_atod(av[3]);
	}
}

static void	init_events(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, KEY_PRESS, KEYPRESS_MASK, handle_key, fractal);
	mlx_hook(fractal->mlx_window, BUTTON_PRESS, BUTTONPRESS_MASK, handle_mouse, fractal);
	mlx_hook(fractal->mlx_window, DESTROY_NOTIFY, STRUCTURENOTIFY_MASK, handle_close, fractal);
}

void	fractal_init(t_fractal *fractal, char **av)
{
	fractal->mlx_connection = mlx_init();
	if (!fractal->mlx_connection)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
			WIDTH, HEIGHT, fractal->name);
	if (!fractal->mlx_window)
		malloc_error();
	fractal->image.image_ptr = mlx_new_image(fractal->mlx_connection,
			WIDTH, HEIGHT);
	if (!fractal->image.image_ptr)
	{
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
		malloc_error();
	}
	fractal->image.pixels = mlx_get_data_addr(fractal->image.image_ptr,
			&fractal->image.bpp,
			&fractal->image.line_len,
			&fractal->image.endian);
	init_data(fractal, av);
	init_events(fractal);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:30:29 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/30 23:55:07 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fractal_render(t_fractal *fractal)
{
	int		x;
	int		y;
	double	julia_x;
	double	julia_y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (!ft_strcmp(fractal->name, "mandelbrot"))
				handle_pixel_mandelbrot(x, y, fractal);
			else if (!ft_strcmp(fractal->name, "julia"))
				handle_pixel_julia(x, y, fractal);
			else if (!ft_strcmp(fractal->name, "burning ship")
				|| !ft_strcmp(fractal->name, "burning"))
				handle_pixel_burningship(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connection,
		fractal->mlx_window, fractal->image.image_ptr, 0, 0);
}

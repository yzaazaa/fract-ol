/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:30:29 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/26 16:37:51 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, t_image *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels + offset) = color;
}

static void	handle_pixel_julia(int x, int y, t_fractal *fractal, double julia_x, double julia_y)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.real = (map(x, -2, 2, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.imaginary = (map(y, 2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	c.real = julia_x;
	c.imaginary = julia_y;
	i = 0;
	while (i++ < fractal->iterations)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.real * z.real) + (z.imaginary * z.imaginary) > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, fractal->iterations);
			my_pixel_put(x, y, &fractal->image, color);
			return ;
		}
	}
	my_pixel_put(x, y, &fractal->image, PSYCHEDELIC_PURPLE);
}

static void	handle_pixel_mandelbrot(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.real = 0.0;
	z.imaginary = 0.0;
	c.real = (map(x, -2, 2, WIDTH) * fractal->zoom) + fractal->shift_x;
	c.imaginary = (map(y, 2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	i = 0;
	while (i++ < fractal->iterations)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.real * z.real) + (z.imaginary * z.imaginary) > fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, fractal->iterations);
			my_pixel_put(x, y, &fractal->image, color);
			return ;
		}
	}
	my_pixel_put(x, y, &fractal->image, PSYCHEDELIC_PURPLE);
}

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
			if (!ft_strcmp(fractal->name,"mandelbrot"))
				handle_pixel_mandelbrot(x, y, fractal);
			if (!ft_strcmp(fractal->name, "julia"))
				handle_pixel_julia(x, y, fractal, fractal->julia.x, fractal->julia.y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->image.image_ptr, 0, 0);
}
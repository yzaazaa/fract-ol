/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 22:54:42 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/30 23:55:07 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	handle_pixel_julia(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.real = map(x, fractal->min_x, fractal->max_x, WIDTH)
		+ fractal->shift_x;
	z.imaginary = map(y, fractal->min_y, fractal->max_y, HEIGHT)
		+ fractal->shift_y;
	c.real = fractal->julia.x;
	c.imaginary = fractal->julia.y;
	i = 0;
	while (i++ < fractal->iterations)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.real * z.real) + (z.imaginary * z.imaginary)
			> fractal->escape_value)
		{
			color = map(i, BLACK, WHITE, fractal->color);
			my_pixel_put(x, y, &fractal->image, color);
			return ;
		}
	}
	my_pixel_put(x, y, &fractal->image, BLACK);
}

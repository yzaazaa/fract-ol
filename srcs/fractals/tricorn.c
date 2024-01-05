/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 00:57:11 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/01/05 04:37:16 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static t_complex	calculate_tricorn(t_complex z, t_complex c)
{
	double	tmp;

	tmp = -2 * z.real * z.imaginary + c.imaginary;
	z.real = z.real * z.real - z.imaginary * z.imaginary + c.real;
	z.imaginary = tmp;
	return (z);
}

void	handle_pixel_tricorn(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.real = map(x, fractal->min_x, fractal->max_x, WIDTH)
		+ fractal->shift_x;
	z.imaginary = map(y, fractal->min_y, fractal->max_y, HEIGHT)
		+ fractal->shift_y;
	c.real = z.real;
	c.imaginary = z.imaginary;
	i = 0;
	while (i++ < fractal->iterations)
	{
		z = calculate_tricorn(z, c);
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

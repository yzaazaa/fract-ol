/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 21:18:16 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/26 16:52:04 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_close(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->image.image_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	exit(EXIT_SUCCESS);
}

int	handle_key(int keysym, t_fractal *fractal)
{
	if (keysym == 53)
		handle_close(fractal);
	else if (keysym == 123)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == 124)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == 126)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == 125)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == 69)
		fractal->iterations += 10;
	else if (keysym == 78)
		fractal->iterations -= 10;
	fractal_render(fractal);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_fractal *fractal)
{
	if (button == 5)
		fractal->zoom *= 0.9;
	else if (button == 4)
		fractal->zoom *= 1.1;
	fractal_render(fractal);
	return (0);
}

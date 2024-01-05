/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:21:28 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/01/05 01:15:59 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	print_instructions(void)
{
	ft_putendl_fd("Usage: ./fractol [FRACTAL]", 2);
	ft_putendl_fd("For mandelbrot: ./fractol mandelbrot", 2);
	ft_putendl_fd("For julia: ./fractol julia [REAL] [IMAGINARY]", 2);
	ft_putendl_fd("For tricorn (mandelbar): ./fractol tricorn", 2);
	ft_putendl_fd("                      or ./fractol mandelbar", 2);
	ft_putendl_fd("Commands:", 2);
	ft_putendl_fd("Mouse wheel to zoom", 2);
	ft_putendl_fd("Arrow keys to move.", 2);
	ft_putendl_fd("R: reset view.", 2);
	ft_putendl_fd("C: change color.", 2);
	ft_putendl_fd("V: change color backwards.", 2);
	ft_putendl_fd("+: increase iterations.", 2);
	ft_putendl_fd("-: decrease iterations.", 2);
	ft_putendl_fd("ESC: close window.", 2);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((ac == 2 && !ft_strcmp(av[1], "mandelbrot"))
		|| (ac == 4 && !ft_strcmp(av[1], "julia")
			&& is_double(av[2]) && is_double(av[3]))
		|| (ac == 2 && !ft_strcmp(av[1], "tricorn"))
		|| (ac == 2 && !ft_strcmp(av[1], "mandelbar")))
	{
		fractal.name = av[1];
		fractal_init(&fractal, av);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		print_instructions();
		exit(1);
	}
}

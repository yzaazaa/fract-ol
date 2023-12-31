/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:21:28 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/31 13:15:45 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	print_message(void)
{
	ft_putendl_fd("Usage: ./fractol [FRACTAL]", 2);
	ft_putendl_fd("For mandelbrot: ./fractol mandelbrot", 2);
	ft_putendl_fd("For julia: ./fractol julia [REAL] [IMAGINARY]", 2);
	ft_putendl_fd("For burning ship: ./fractol \"burning ship\"", 2);
	ft_putendl_fd("               or ./fractol burning ship", 2);
	ft_putendl_fd("Commands:", 2);
	ft_putendl_fd("Arrow keys to move.", 2);
	ft_putendl_fd("R: reset view.", 2);
	ft_putendl_fd("C: change color.", 2);
	ft_putendl_fd("+: increase iterations.", 2);
	ft_putendl_fd("-: decrease iterations.", 2);
	ft_putendl_fd("ESC: close window.", 2);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((ac == 2 && !ft_strcmp(av[1], "mandelbrot"))
		|| (ac == 2 && !ft_strcmp(av[1], "burning ship"))
		|| (ac == 3 && !ft_strcmp(av[1], "burning")
			&& !ft_strcmp(av[2], "ship"))
		|| (ac == 4 && !ft_strcmp(av[1], "julia")
			&& is_double(av[2]) && is_double(av[3])))
	{
		fractal.name = av[1];
		fractal_init(&fractal, av);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		print_message();
		exit(1);
	}
}

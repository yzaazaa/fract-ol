/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:21:28 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/28 23:16:36 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
// void f(void){system("leaks fractol");}
int main(int ac, char **av)
{
    // atexit(f);
    t_fractal   fractal;

    if ((ac == 2 && !ft_strcmp(av[1], "mandelbrot"))
        || (ac == 2 && !ft_strcmp(av[1], "burning ship"))
        || (ac == 3 && !ft_strcmp(av[1], "burning") && !ft_strcmp(av[2], "ship"))
        || (ac == 4 && !ft_strcmp(av[1], "julia") && is_double(av[2]) && is_double(av[3])))
    {
        fractal.name = av[1];
        fractal_init(&fractal, av);
        fractal_render(&fractal);
        mlx_loop(fractal.mlx_connection);
    }
    else
    {
        ft_putendl_fd("Usage: ./fractol [FRACTAL] (if julia) [REAL] [IMAGINARY]", 2);
        ft_putendl_fd("For mandelbrot: ./fractol mandelbrot" , 2);
        ft_putendl_fd("For julia: ./fractol julia [REAL] [IMAGINARY]" , 2);
        ft_putendl_fd("For burning ship: ./fractol \"burning ship\" or ./fractol burning ship" , 2);
        exit(EXIT_FAILURE);
    }
}

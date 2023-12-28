/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:21:32 by yzaazaa           #+#    #+#             */
/*   Updated: 2023/12/28 23:12:12 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>

# define ERROR_MESSAGE "\"./fractol mandelbrot\"or \n\t\"./fractol julia [real] [imaginary]\""

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define PSYCHEDELIC_PURPLE 0x660066
# define WIDTH 800
# define HEIGHT 800

typedef struct  s_image
{
    void    *image_ptr;
    char    *pixels;
    int     bpp;
    int     endian;
    int     line_len;
}               t_image;

typedef struct  s_julia
{
    double  x;
    double  y;
}               t_julia;

typedef struct  s_fractal
{
    char    *name;
    void    *mlx_connection;
    void    *mlx_window;
    t_image image;
    double  escape_value;
    int     iterations;
    double  shift_x;
    double  shift_y;
    double  min_x;
    double  min_y;
    double  max_x;
    double  max_y;
    double  zoom;
    int     color;
    t_julia julia;
}               t_fractal;

typedef struct  s_complex
{
    double  real;
    double  imaginary;
}               t_complex;

int         ft_strcmp(char *s1, char *s2);
void        ft_putendl_fd(char *str, int fd);
void        malloc_error(void);
double      ft_atod(char *s);
void        fractal_init(t_fractal *fractal, char **av);
double      map(double unscaled_num, double new_min, double new_max, double old_max);
t_complex	square_complex(t_complex z);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	abs_complex(t_complex z);
double	abs_double(double c);
int         is_double(char *s);
int         check_sign(char **s);
void        fractal_render(t_fractal *fractal);
int         handle_key(int keysym, t_fractal *fractal);
int         handle_mouse(int button, int x, int y, t_fractal *fractal);
int         handle_julia(int x, int y, t_fractal *fractal);
int         handle_close(t_fractal *fractal);
int	color_to_int(int t, int r, int g, int b);

#endif

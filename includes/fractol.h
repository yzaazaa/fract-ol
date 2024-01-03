/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaazaa <yzaazaa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:21:32 by yzaazaa           #+#    #+#             */
/*   Updated: 2024/01/03 21:27:46 by yzaazaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "string.h"
# include "keys.h"
# include <mlx.h>

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define BLUE 0x061A80
# define WIDTH 800
# define HEIGHT 800

typedef struct s_image
{
	void	*image_ptr;
	char	*pixels;
	int		bpp;
	int		endian;
	int		line_len;
}				t_image;

typedef struct s_julia
{
	double	x;
	double	y;
}			t_julia;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_image	image;
	double	escape_value;
	int		iterations;
	double	shift_x;
	double	shift_y;
	double	min_x;
	double	min_y;
	double	max_x;
	double	max_y;
	double	zoom;
	int		color;
	t_julia	julia;
}				t_fractal;

void		fractal_init(t_fractal *fractal, char **av);
void		my_pixel_put(int x, int y, t_image *img, int color);
void		handle_pixel_mandelbrot(int x, int y, t_fractal *fractal);
void		handle_pixel_burningship(int x, int y, t_fractal *fractal);
void		handle_pixel_julia(int x, int y, t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
int			handle_key(int keysym, t_fractal *fractal);
int			handle_mouse(int button, int x, int y, t_fractal *fractal);
int			handle_close(t_fractal *fractal);

#endif

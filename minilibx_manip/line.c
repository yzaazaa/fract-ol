#include "mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>

int	main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	int	width;
	int	height;
	int	x1;
	int	y1;
	int	x2;
	int	y2;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	e;
	int	e2;

	if(ac != 5)
	{
		write(1, "The program takes 4 arguments: x1 y1 x2 y2\n", 44);
		return (-1);
	}
	width = 800;
	height = 600;
	mlx = mlx_init();
	win = mlx_new_window(mlx, width, height, "line");
	x1 = atoi(av[1]);
	y1 = atoi(av[2]);
	x2 = atoi(av[3]);
	y2 = atoi(av[4]);
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	sx = x1 < x2 ? 1 : -1;
	sy = y1 < y2 ? 1 : -1;
	e = dx - dy;
	while(1)
	{
		mlx_pixel_put(mlx, win, x1, y1, 0xFFFFFF);
		if(x1 == x2 && y1 == y2)
			break;
		e2 = 2 * e;
		if(e2 > -dy)
		{
			e -= dy;
			x1 += sx;
		}
		if(e2 < dx)
		{
			e += dx;
			y1 += sy;
		}		
	}
	mlx_loop(mlx);
	return (0);
}

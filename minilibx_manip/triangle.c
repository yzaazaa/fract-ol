#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void	draw_line(void *mlx, void *win, int x1, int y1, int x2, int y2)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	e;
	int	e2;

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
}
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
	int	x3;
	int	y3;

	if(ac != 7)
	{
		printf("The program takes 6 arguments (3 points) : x1 y1 x2 y2 x3 y3");
		return (-1);
	}
	width = 800;
	height = 600;
	mlx = mlx_init();
	win = mlx_new_window(mlx, width, height, "Triangle");

	x1 = atoi(av[1]);
	y1 = atoi(av[2]);
	x2 = atoi(av[3]);
	y2 = atoi(av[4]);
	x3 = atoi(av[5]);
	y3 = atoi(av[6]);
	draw_line(mlx, win, x1, y1, x2, y2);
	draw_line(mlx, win, x1, y1, x3, y3);
	draw_line(mlx, win, x2, y2, x3, y3);
	mlx_loop(mlx);
}

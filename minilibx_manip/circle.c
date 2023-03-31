#include "mlx.h"
#include "stdlib.h"

void	eightsymplot(void *mlx, void *win, int xc, int yc, int x, int y)
{

	mlx_pixel_put(mlx, win, x + xc, y + yc, 0xFFFFFF);
	mlx_pixel_put(mlx, win, x + xc, -y + yc, 0xFFFFFF);
	mlx_pixel_put(mlx, win, -x + xc, -y + yc, 0xFFFFFF);
	mlx_pixel_put(mlx, win, -x + xc, y + yc, 0xFFFFFF);
	mlx_pixel_put(mlx, win, y + xc, x + yc, 0xFFFFFF);
	mlx_pixel_put(mlx, win, y + xc, -x + yc, 0xFFFFFF);
	mlx_pixel_put(mlx, win, -y + xc, -x + yc, 0xFFFFFF);
	mlx_pixel_put(mlx, win, -y + xc, x + yc, 0xFFFFFF);
}

int	main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	int	x_win;
	int	y_win;
	int	xo;
	int	yo;
	int	x;
	int	y;
	int	r;
	int	d;

	if(ac != 2)
		return (-1);
	x_win = 800;
	y_win = 600;
	xo = x_win / 2;
	yo = y_win / 2;
	x = 0;
	r = atoi(av[1]);
	y = r;
	d = 3 - (2 * r);
	mlx = mlx_init();
	win = mlx_new_window(mlx, x_win, y_win, "Circle");
	mlx_pixel_put(mlx, win, xo, yo, 0xFF0000);
	while(x < y)
	{
		eightsymplot(mlx, win, xo, yo, x, y);
		if(d < 0)
		{
			d = d + (4 * x) + 6;
			x++;
		}
		else
		{
			d = d + (4 * (x - y)) + 10;
			x++;
			y--;
		}
	}
	mlx_loop(mlx);
}

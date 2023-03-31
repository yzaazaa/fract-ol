#include "mlx.h"
#include "stdlib.h"

int	main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	int	x;
	int	y;
	int	n;	
	int 	i;

	if(ac != 2)
		return (-1);
	x = 800;
	y = 600;
	n = atoi(av[1]);
	mlx = mlx_init();
	win = mlx_new_window(mlx, x, y, "Square");
	mlx_pixel_put(mlx, win, (x / 2), (y / 2), 0xFF0000);
	i = 0;
	while(i < n)
	{
		mlx_pixel_put(mlx, win, (x / 2) - (n / 2) + i, (y / 2) - (n / 2), 0xFFFFFF); 
		mlx_pixel_put(mlx, win, (x / 2) - (n / 2), (y / 2) - (n / 2) + i, 0xFFFFFF);
		mlx_pixel_put(mlx, win, (x / 2) - (n / 2) + i, (y / 2) + (n / 2), 0xFFFFFF);
		mlx_pixel_put(mlx, win, (x / 2) + (n / 2), (y / 2) - (n / 2) + i, 0xFFFFFF);
		i++;
	}
	mlx_loop(mlx);
}

#include "mlx.h"
#include <stdio.h>

int	mousein(int button, int x, int y, void *params)
{
	printf("Hello!\n");		
	return (0);
}

int	mouseout(int button, int x, int y, void *params)
{
	printf("Bye!\n");
	return (0);
}

int	main()
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "Focus");
	mlx_hook(win, 7, 0, mousein, 0);
	mlx_hook(win, 8, 0, mouseout, 0);
	mlx_loop(mlx);
	return (0);
}

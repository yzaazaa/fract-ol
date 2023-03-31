#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

struct	s_vars
{
	void	*mlx;
	void	*win;
};
typedef struct s_vars	t_vars;

int	deal_key(int keycode, t_vars *params)
{
	if(keycode == 65307)
	{	
		mlx_destroy_window(params->mlx, params->win);
		exit(0);
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello World");
	mlx_key_hook(vars.win, deal_key, &vars);
	mlx_loop(vars.mlx);
}

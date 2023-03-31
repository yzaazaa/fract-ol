#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}		t_vars;

int	deal_key(int keycode, t_vars *params)
{
	mlx_destroy_window(params->mlx, params->win);
	return (0);
}

int	main()
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 600, "mouse_hook");
	mlx_hook(vars.win, 17, 0L, deal_key, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

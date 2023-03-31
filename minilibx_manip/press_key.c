#include "mlx.h"
#include <stdio.h>
#include <time.h>

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}		t_vars;

typedef struct	s_elapsed
{
	time_t	start_time;
	time_t	end_time;
}		t_elapsed;

int	key_press(int key, t_elapsed *elapsed)
{
	elapsed->start_time = time(NULL);
	if(difftime(elapsed->end_time, elapsed->start_time) >= 3.0)
	{
		printf("Long press detected\n");
		return (0);
	}
	return (0);
}


int	main()
{
	t_elapsed	elapsed;
	t_vars		vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 600, "press_key");
	
	mlx_hook(vars.win, 2, 1L<<0, key_press, &elapsed);
	mlx_loop(vars.mlx);
	
	return (0);
}

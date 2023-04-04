#include <SDL2/SDL.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 1080
#define WIDTH 1920
#define MAX_ITER 1000

typedef struct s_complex{
	double x;
	double y;
}	t_complex;

void	SDL_ExitWithError()
{
	SDL_Log("Error: %s.\n", SDL_GetError());
	SDL_Quit();
	exit(-1);
}

int	main()
{
	SDL_Window	*win;
	SDL_Renderer	*render;
	SDL_bool	program_launched;
	SDL_Event 	event;
	int		x;
	int		y;

	if(SDL_Init(SDL_INIT_VIDEO) != 0)
		SDL_ExitWithError();
	if(SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &win, &render) != 0)
		SDL_ExitWithError();
	
	program_launched = SDL_TRUE;
	while(program_launched)
	{
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
				program_launched = SDL_FALSE;
		}
		for(int x = 0; x < WIDTH; x++)
		{
			for(int y = 0; y < HEIGHT; y++)
			{
				t_complex c = {
					(double)x / WIDTH * 3.5 - 2.5,
					(double)y / HEIGHT * 2 - 1
				};
				t_complex z = {0,0};
				int iterations = 0;
				while(iterations < MAX_ITER)
				{
					if(z.x * z.x + z.y * z.y > 4)
						break;
					t_complex tmp = {
						z.x * z.x - z.y * z.y + c.x,
						2 * z.x *z.y + c.y
					};
					z = tmp;
					iterations++;
				}
				int color = iterations % 8 * 35;
				SDL_SetRenderDrawColor(render, color, color, color, 255);
				SDL_RenderDrawPoint(render, x, y);
			}
		}
		SDL_RenderPresent(render);
	}

	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return (0);
}

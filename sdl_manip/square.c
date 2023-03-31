#include <SDL.h>
#include <stdlib.h>

#define WIN_HEIGHT 600
#define WIN_WIDTH 800

void	SDL_ExitWithError()
{
	SDL_Log("Error: %s.\n", SDL_GetError());
	SDL_Quit();
	exit(-1);
}

int	main(int ac, char **av)
{
	SDL_Window	*win;
	SDL_Renderer	*render;
	SDL_bool	program_launched;
	SDL_Event 	event;
	int		x;
	int		y;
	int		n;
	int		i;

	if(ac != 2)
		return (-1);
	if(SDL_Init(SDL_INIT_VIDEO) != 0)
		SDL_ExitWithError();
	if(SDL_CreateWindowAndRenderer(WIN_WIDTH, WIN_HEIGHT, 0, &win, &render) != 0)
		SDL_ExitWithError();


	n = atoi(av[1]);
	SDL_SetRenderDrawColor(render, 255, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawPoint(render, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	SDL_SetRenderDrawColor(render, 255, 255, 255, SDL_ALPHA_OPAQUE);
	i = 0;
	while(i < n)
	{
		SDL_RenderDrawPoint(render, (WIN_WIDTH / 2) - (n / 2) + i, (WIN_HEIGHT / 2) - (n / 2));
		SDL_RenderDrawPoint(render, (WIN_WIDTH / 2) - (n / 2), (WIN_HEIGHT / 2) - (n / 2) + i);
		SDL_RenderDrawPoint(render, (WIN_WIDTH / 2) - (n / 2) + i, (WIN_HEIGHT / 2) + (n / 2));
		SDL_RenderDrawPoint(render, (WIN_WIDTH / 2) + (n / 2), (WIN_HEIGHT / 2) - (n / 2) + i);
		i++;
	}
	SDL_RenderPresent(render);

	program_launched = SDL_TRUE;
	while(program_launched)
	{
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT:
					program_launched = SDL_FALSE;
					break;
				default:
					break;
			}
		}
	}

	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return (0);
}

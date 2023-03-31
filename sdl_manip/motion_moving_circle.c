#include <SDL.h>

#define WIN_HEIGHT 600
#define WIN_WIDTH 800

void	SDL_ExitWithError()
{
	SDL_Log("Error: %s.\n", SDL_GetError());
	SDL_Quit();
	exit(-1);
}

void	eightsymplot(SDL_Renderer *render, int xc, int yc, int x, int y)
{

	SDL_RenderDrawPoint(render, x + xc, y + yc);
	SDL_RenderDrawPoint(render, x + xc, -y + yc);
	SDL_RenderDrawPoint(render, -x + xc, -y + yc);
	SDL_RenderDrawPoint(render, -x + xc, y + yc);
	SDL_RenderDrawPoint(render, y + xc, x + yc);
	SDL_RenderDrawPoint(render, y + xc, -x + yc);
	SDL_RenderDrawPoint(render, -y + xc, -x + yc);
	SDL_RenderDrawPoint(render, -y + xc, x + yc);
}

void	draw_circle(SDL_Renderer *render, int r, int xo, int yo)
{
	int	x;
	int	y;
	int	d;

	x = 0;
	y = r;
	d = 3 - (2 * r);
	while(x < y)
	{
		eightsymplot(render, xo, yo, x, y);
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
}

int	main()
{
	SDL_Window	*win;
	SDL_Renderer	*render;
	SDL_bool	program_launched;
	SDL_Event 	event;
	int		r;
	int		xo;
	int		yo;
	int		speed;

	if(SDL_Init(SDL_INIT_VIDEO) != 0)
		SDL_ExitWithError();
	if(SDL_CreateWindowAndRenderer(WIN_WIDTH, WIN_HEIGHT, 0, &win, &render) != 0)
		SDL_ExitWithError();

	program_launched = SDL_TRUE;
	r = 50;
	xo = WIN_WIDTH/2;
	yo = WIN_HEIGHT/2;
	while(program_launched)
	{
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_MOUSEMOTION:
					xo = event.motion.x;
					yo = event.motion.y;
					break;
				case SDL_QUIT:
					program_launched = SDL_FALSE;
					break;
				default:
					break;
			}
		}

		SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
		SDL_RenderClear(render);
		SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
		draw_circle(render, r, xo, yo);
		SDL_RenderPresent(render);
	}
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return (0);
}

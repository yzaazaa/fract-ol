#include "SDL.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define WIN_HEIGHT 600
#define WIN_WIDTH 800

void	SDL_ExitWithError()
{
	SDL_Log("Error: %s.\n", SDL_GetError());
	SDL_Quit();
	exit(-1);
}

void	draw_line(SDL_Renderer *render, int x1, int y1, int x2, int y2)
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
		SDL_RenderDrawPoint(render, x1, y1);
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
	SDL_Window	*win;
	SDL_Renderer	*render;
	SDL_bool	program_launched;
	SDL_Event 	event;
	int	x1;
	int	y1;
	int	x2;
	int	y2;
	int	x3;
	int	y3;

	if(SDL_Init(SDL_INIT_VIDEO) != 0)
		SDL_ExitWithError();
	if(SDL_CreateWindowAndRenderer(WIN_WIDTH, WIN_HEIGHT, 0, &win, &render) != 0)
		SDL_ExitWithError();

	if(ac != 7)
	{
		printf("The program takes 6 arguments (3 points) : x1 y1 x2 y2 x3 y3");
		return (-1);
	}
	x1 = atoi(av[1]);
	y1 = atoi(av[2]);
	x2 = atoi(av[3]);
	y2 = atoi(av[4]);
	x3 = atoi(av[5]);
	y3 = atoi(av[6]);
	SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
	draw_line(render, x1, y1, x2, y2);
	draw_line(render, x1, y1, x3, y3);
	draw_line(render, x2, y2, x3, y3);
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

#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>

int	main()
{
	SDL_Window *win;
	SDL_Renderer *rend;


	if(SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		SDL_Log("Couldnt initialize SDL: %s \n", SDL_GetError());
		exit(-1);
	}
	if(SDL_CreateWindowAndRenderer(800, 600, 0, &win, &rend) != 0)
	{
		SDL_Log("Couldnt create and render: %s \n", SDL_GetError());
		exit(-1);
	}
	if(SDL_SetRenderDrawColor(rend, 255, 0, 0, SDL_ALPHA_OPAQUE) != 0)
	{
		SDL_Log("Couldnt initialize SDL: %s \n", SDL_GetError());
		exit(-1);
	}
	SDL_RenderDrawPoint(rend, 400, 300);
	SDL_RenderPresent(rend);
	SDL_Delay(3000);
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return (0);
}
